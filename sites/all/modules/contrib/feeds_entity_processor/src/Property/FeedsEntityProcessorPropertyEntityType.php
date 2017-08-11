<?php

/**
 * @file
 * Contains FeedsEntityProcessorPropertyEntityType.
 */

/**
 * Handler for specified entity type property.
 */
class FeedsEntityProcessorPropertyEntityType extends FeedsEntityProcessorPropertyDefault {

  /**
   * Implements FeedsEntityProcessorPropertyInterface::validate().
   */
  public function validate(&$value) {
    $info = $this->getPropertyInfo();
    $entity_type = $info['type'];

    if ($value) {
      $entity = entity_load_single($entity_type, $value);
      if (!$entity) {
        $entity_info = entity_get_info();
        $entity_type_label = $entity_info[$entity_type]['label'];
        return array(
          t('@entity_type with ID "@entity_id" does not exist.', array(
            '@entity_type' => $entity_type_label,
            '@entity_id' => $value,
          )),
        );
      }

      $wrapper = entity_metadata_wrapper($entity_type, $value);
      return parent::validate($wrapper);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function setValue($value, array $mapping) {
    $info = $this->getPropertyInfo();

    if (is_scalar($value)) {
      $wrapper = entity_metadata_wrapper($info['type'], $value);
    }

    parent::setValue($wrapper, $mapping);
  }

  /**
   * {@inheritdoc}
   */
  protected function getDataType() {
    $type = parent::getDataType();
    $info = entity_get_info($type);

    if (isset($info['entity keys']['id'])) {
      $id_key = $info['entity keys']['id'];
      if (isset($info['base table field types'][$id_key])) {
        $type .= ' (' . $info['base table field types'][$id_key] . ')';
      }
    }

    return $type;
  }

}
