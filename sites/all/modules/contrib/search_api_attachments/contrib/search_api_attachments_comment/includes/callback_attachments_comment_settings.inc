<?php

/**
 * @file
 * Search API data alteration callback.
 */

/**
 * {@inheritdoc}
 */
class SearchApiAttachmentsCommentAlterSettings extends SearchApiAttachmentsAlterSettings {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    // Ensure we are on a node index.
    if ($this->index->item_type != 'node') {
      return;
    }

    // Extension restriction.
    $exclude = array();
    foreach (explode(' ', $this->options['excluded_extensions']) as $ext) {
      $exclude[$ext] = file_get_mimetype('dummy.' . $ext);
    }

    // File size restriction.
    $max_file_size = parse_size($this->options['max_file_size']);

    // Get the file fields.
    $file_fields = $this->getFileFields();

    foreach ($items as $id => &$item) {
      // Load the comments.
      $comments = comment_load_multiple(array(), array('nid' => $id));

      // Loop in the comments.
      foreach ($comments as $comment) {
        $comment_wrapper = entity_metadata_wrapper('comment', $comment->cid);
        foreach ($file_fields as $file_field) {
          if (isset($comment->{$file_field['field_name']})) {
            $files = $comment_wrapper->{$file_field['field_name']}->value();
            // Manage case of single value fields by reproducing the structure
            // of multiple values fields.
            if ($file_field['cardinality'] == 1) {
              $files = array($files);
            }
            // Index the files content.
            if (!empty($files)) {
              // Limit to the max number of value per field.
              if (isset($this->options['number_indexed']) && $this->options['number_indexed'] != '0' && count($files) > $this->options['number_indexed']) {
                $files = array_slice($files, 0, $this->options['number_indexed']);
              }
              foreach ($files as $file) {
                // Private file restriction.
                if (!$this->isTemporary($file) && !($this->options['excluded_private'] && $this->isPrivate($file))) {
                  // Extension restriction.
                  if (!in_array($file['filemime'], $exclude)) {
                    // File size restriction.
                    $file_size_errors = file_validate_size((object) $file, $max_file_size);
                    if (empty($file_size_errors)) {
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
  }

  /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    $ret = array();
    if ($this->index->item_type == 'file') {
      $ret['attachments_content'] = array(
        'label' => 'File content',
        'description' => 'File content',
        'type' => 'text',
      );
    }
    else {
      $fields = $this->getFileFields();
      foreach ($fields as $name => $field) {
        $ret['attachments_' . $name] = array(
          'label' => 'Attachment content: ' . $name,
          'description' => $name,
          'type' => 'text',
        );
      }
    }
    return $ret;
  }

  /**
   * {@inheritdoc}
   */
  protected function getFileFields() {
    $ret = array();
    foreach (field_info_fields() as $name => $field) {
      if ($field['type'] == 'file') {
        $ret[$name] = $field;
      }
    }
    return $ret;
  }

}
