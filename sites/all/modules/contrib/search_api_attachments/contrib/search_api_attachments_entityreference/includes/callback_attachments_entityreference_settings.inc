<?php

/**
 * @file
 * Search API data alteration callback.
 */

/**
 * {@inheritdoc}
 */
class SearchApiAttachmentsEntityreferenceAlterSettings extends SearchApiAttachmentsAlterSettings {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    // Get the entity reference fields.
    $entityreference_fields = $this->getEntityReferenceFields();

    // Get the file fields.
    $file_fields = $this->getFileFields();

    foreach ($items as &$item) {
      // Support the search_api_et module. It adds its prefix to entity types.
      $entity_type = (strpos($this->index->item_type, 'search_api_et_') === 0) ?
        substr($this->index->item_type, 14) : //14 = strlen('search_api_et_').
        $this->index->item_type;
      $item_wrapper = entity_metadata_wrapper($entity_type, $item);

      // Case of entity reference fields.
      foreach ($entityreference_fields as $entityreference_field) {
        if (isset($item->{$entityreference_field['field_name']})) {
          $referenced_entities = $item_wrapper->{$entityreference_field['field_name']}->value();
          // Manage case of single value fields by reproducing the structure of
          // multiple values fields.
          if (is_object($referenced_entities)) {
            $referenced_entities = array($referenced_entities);
          }
          // Index the files content.
          if (!empty($referenced_entities) && $entityreference_field['settings']['target_type'] == 'file') {
            if ($content = $this->getFilesContent($referenced_entities, $exclude, $max_file_size)) {
              $item->{'attachments_' . $entityreference_field['field_name']} = $content;
            }
          }
          elseif (!empty($file_fields) && !empty($referenced_entities)) {
            foreach ($file_fields as $file_field) {
              foreach ($referenced_entities as $referenced_entity) {
                // The referenced entity has the file field.
                if (isset($referenced_entity->{$file_field['field_name']}) && !empty($referenced_entity->{$file_field['field_name']})) {
                  // Get the files.
                  $files = field_get_items($entityreference_field['settings']['target_type'], $referenced_entity, $file_field['field_name']);
                  if (!empty($files)) {
                    if ($content = $this->getFilesContent($files, $exclude, $max_file_size)) {
                      $item->{'attachments_' . $file_field['field_name']} = $content;
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
      $fields = $this->getFileFields() + $this->getEntityReferenceFields();
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

  /**
   * {@inheritdoc}
   */
  protected function getEntityReferenceFields() {
    $ret = array();
    foreach (field_info_fields() as $name => $field) {
      if ($field['type'] == 'entityreference') {
        $ret[$name] = $field;
      }
    }
    return $ret;
  }

  /**
   * Extracts and returns contents of files.
   *
   * @param array $files
   *   The array of file objects/arrays.
   * @param array $exclude
   *   The array of file extensions to exclude.
   * @param int $max_file_size
   *   The maximum file size.
   *
   * @return string
   *   Extracted contents of files imploded by the space character.
   */
  protected function getFilesContent($files, $exclude, $max_file_size) {
    $ret = '';
    // Limit to the max number of value per field.
    if (isset($this->options['number_indexed']) && $this->options['number_indexed'] != '0' && count($files) > $this->options['number_indexed']) {
      $files = array_slice($files, 0, $this->options['number_indexed']);
    }
    foreach ($files as $file) {
      $file = (array) $file;
      // Private file restriction.
      if (!$this->isTemporary($file) && !($this->options['excluded_private'] && $this->isPrivate($file))) {
        // Extension restriction.
        if (!in_array($file['filemime'], $exclude)) {
          // File size restriction.
          $file_size_errors = file_validate_size((object) $file, $max_file_size);
          if (empty($file_size_errors)) {
            $ret .= ' ' . $this->getFileContent($file);
          }
        }
      }
    }
    return trim($ret);
  }
}
