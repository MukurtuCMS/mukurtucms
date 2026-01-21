<?php

/**
 * @file
 * Contains FeedsEntityProcessorTestMetadataController.
 */

/**
 * Extend the default Test entity metadata properties.
 */
class FeedsEntityProcessorTestMetadataController extends EntityDefaultMetadataController {

  /**
   * Overrides EntityDefaultMetadataController::entityPropertyInfo().
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    // Text.
    $properties['title'] += array(
      'setter callback' => 'entity_property_verbatim_set',
    );

    // Boolean.
    $properties['status']['type'] = 'boolean';
    $properties['status']['label'] = t('Published');
    $properties['status'] += array(
      'setter callback' => 'entity_property_verbatim_set',
    );

    // Date.
    $properties['created']['type'] = 'date';
    $properties['created'] += array(
      'setter callback' => 'entity_property_verbatim_set',
    );
    $properties['changed']['type'] = 'date';
    $properties['changed'] += array(
      'setter callback' => 'entity_property_verbatim_set',
    );

    // Entity id is provided via the "entity" property.
    unset($properties['etid']);

    // Entity.
    $properties['entity'] = array(
      'label' => t('Entity'),
      'type' => 'entity',
      'description' => t('The linked entity.'),
      'getter callback' => 'feeds_entity_processor_test_entity_getter',
      'setter callback' => 'feeds_entity_processor_test_entity_setter',
      'required' => variable_get('feeds_entity_processor_test_required', TRUE),
    );

    // Author.
    unset($properties['uid']);
    $properties['user'] = array(
      'label' => t('Author'),
      'type' => 'user',
      'description' => t('The author of the item.'),
      'getter callback' => 'feeds_entity_processor_test_entity_getter',
      'setter callback' => 'feeds_entity_processor_test_entity_setter',
      'required' => variable_get('feeds_entity_processor_test_required', TRUE),
    );

    return $info;
  }

}
