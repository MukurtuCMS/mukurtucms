<?php
/**
 * @file
 * Search API data alteration callback.
 */

class SearchApiAttachmentsMultipleEntitiesAlterSettings extends SearchApiAttachmentsAlterSettings {

  // Cache table name.
  const CACHE_TABLE = 'cache_search_api_attachments';

  public function alterItems(array &$items) {

    // Extension restriction.
    $exclude = array();
    foreach (explode(' ', $this->options['excluded_extensions']) as $ext) {
      $exclude[$ext] = file_get_mimetype('dummy.' . $ext);
    }

    // File size restriction.
    $max_file_size = parse_size($this->options['max_file_size']);

    $fields = $this->getFileFields();

    foreach ($items as $id => &$item) {
      foreach ($fields as $name => $field) {
        foreach ($item as &$single_item) {

          if (is_object($single_item) && isset($single_item->$name)) {
            foreach ($single_item->$name as $value) {
              // Limit to the max number of value per field.
              if (isset($this->options['number_indexed']) && $this->options['number_indexed'] != '0' && count($value) > $this->options['number_indexed']) {
                $value = array_slice($value, 0, $this->options['number_indexed']);
              }
              foreach ($value as $file) {
                // Private file restriction.
                if (!$this->isTemporary($file) && !($this->options['excluded_private'] && $this->isPrivate($file))) {
                  // Extension restriction.
                  if (!in_array($file['filemime'], $exclude)) {
                    // File size restriction.
                    $file_size_errors = file_validate_size((object) $file, $max_file_size);
                    if (empty($file_size_errors)) {
                      $attachments = 'attachments_' . $name;
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

  protected function getFileFields() {
    $ret = array();
    foreach (field_info_fields() as $name => $field) {
      if ($field['type'] == 'file') {
        if ($this->index->item_type == 'multiple') {
          $bundles = $this->index->options['datasource']['types'];

          foreach ($bundles as $bundle) {
            if (array_key_exists($bundle, $field['bundles'])) {
              $ret[$name] = $field;
            }
          }
        }

        if (array_key_exists($this->index->getEntityType(), $field['bundles'])) {
          $ret[$name] = $field;
        }
      }
    }
    return $ret;
  }

}
