<?php

/**
 * @file
 * Search API data alteration callback.
 */

/**
 * {@inheritdoc}
 */
class SearchApiAttachmentsFieldCollectionsAlterSettings extends SearchApiAttachmentsAlterSettings {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    // Get the field collection bundles.
    $field_collections_instances = field_info_instances('field_collection_item');
    $field_collections = array_keys($field_collections_instances);
    if (!empty($field_collections_instances)) {
      foreach ($items as &$item) {
        // Case of field collection fields.
        foreach ($field_collections as $field_collection) {
          if (isset($item->{$field_collection})) {
            // Get the file fields of the field collection item.
            $file_fields = array();
            foreach (array_keys($field_collections_instances[$field_collection]) as $field_name) {
              $field_info = field_info_field($field_name);
              if ($field_info['type'] == 'file') {
                $file_fields[] = $field_name;
              }
            }
            if (empty($file_fields)) {
              return;
            }
            $collections = field_get_items($this->index->getEntityType(), $item, $field_collection);
            if ($collections) {
              $collection_item_ids = array();
              foreach ($collections as $field_collection_id) {
                $collection_item_ids[] = $field_collection_id['value'];
              }
              $collection_items = entity_load_multiple_by_name('field_collection_item', $collection_item_ids);

              // Index the files content.
              foreach ($file_fields as $file_field) {
                foreach ($collection_items as $collection_item) {
                  $field_collection_name = $collection_item->field_name;
                  if (isset($item->{$field_collection_name}) && !empty($item->{$field_collection_name})) {
                    $files = field_get_items('field_collection_item', $collection_item, $file_field);
                    if (!empty($files)) {
                      // Limit to the max number of value per field.
                      if (isset($this->options['number_indexed']) && $this->options['number_indexed'] != '0' && count($files) > $this->options['number_indexed']) {
                        $files = array_slice($files, 0, $this->options['number_indexed']);
                      }
                      foreach ($files as $file) {
                        if ($this->isFileIndexable($file, $item, $field_collection_name)) {
                          $attachments = 'attachments_' . $file_field;
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
    }
  }

  /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    $ret = array();
    if ($this->index->getEntityType() == 'file') {
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
