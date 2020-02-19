<?php

/**
 * @file
 * Search API data alteration callback.
 */

/**
 * {@inheritdoc}
 */
class SearchApiAttachmentsUserContentAlterSettings extends SearchApiAttachmentsAlterSettings {

  /**
   * {@inheritdoc}
   */
  public function supportsIndex(SearchApiIndex $index) {
    return $index->getEntityType() === 'user';
  }

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    // Get the file fields.
    $file_fields = $this->getFileFields();
    if (empty($file_fields)) {
      return;
    }

    // Get all nodes authored by the indexed users.
    $uids = array();
    foreach ($items as $item) {
      $uids[] = $item->uid;
    }

    $sql = 'SELECT nid FROM {node} WHERE uid IN (:uids)';
    $nids = db_query($sql, array(':uids' => $uids));
    $user_nodes = array();
    foreach (node_load_multiple($nids->fetchCol()) as $node) {
      $user_nodes[$node->uid][] = $node;
    }

    foreach ($items as $item) {
      // Index the files content.
      if (!empty($user_nodes[$item->uid])) {
        foreach ($user_nodes[$item->uid] as $node) {
          foreach ($file_fields as $file_field) {
            // The node has the file field.
            if (!empty($node->{$file_field['field_name']})) {
              // Get the files.
              $files = field_get_items('node', $node, $file_field['field_name']);
              if (!empty($files)) {
                // Limit to the max number of value per field.
                if (!empty($this->options['number_indexed']) && count($files) > $this->options['number_indexed']) {
                  $files = array_slice($files, 0, $this->options['number_indexed']);
                }
                foreach ($files as $file) {
                  if ($this->isFileIndexable($file, $item, $file_field['field_name'])) {
                    $attachments = 'attachments_' . $file_field['field_name'];
                    if (isset($item->{$attachments})) {
                      $item->{$attachments} .= ' ' . $this->getFileContent($file);
                    }
                    else {
                      $item->{$attachments} = $this->getFileContent($file);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    $ret = array();
    $fields = $this->getFileFields();
    foreach ($fields as $name => $field) {
      $ret['attachments_' . $name] = array(
        'label' => 'Attachment content: ' . $name,
        'description' => $name,
        'type' => 'text',
      );
    }
    return $ret;
  }

  /**
   * {@inheritdoc}
   */
  protected function getFileFields() {
    $ret = array();
    foreach (field_info_fields() as $name => $field) {
      if ($field['type'] == 'file' && array_key_exists('node', $field['bundles'])) {
        $ret[$name] = $field;
      }
    }
    return $ret;
  }

}
