<?php

/**
 * @file
 * Provides entity property info for field collection items.
 */

class FieldCollectionItemMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info['field_collection_item']['properties'];

    $properties['field_name']['label'] = t('Field name');
    $properties['field_name']['description'] = t('The machine-readable name of the field collection field containing this item.');
    $properties['field_name']['required'] = TRUE;

    $properties['host_entity'] = array(
      'label' => t('Host entity'),
      'type' => 'entity',
      'description' => t('The entity containing the field collection field.'),
      'getter callback' => 'field_collection_item_get_host_entity',
      'setter callback' => 'field_collection_item_set_host_entity',
      'required' => TRUE,
    );

    // Also add type-specific host entity references for all entity types that
    // have at least one field collection field.
    $field_collection_fields = field_read_fields(array('type' => 'field_collection'));
    $entity_types = entity_get_info();
    foreach (field_info_instances() as $entity_type => $bundles) {
      foreach ($bundles as $bundle => $fields) {
        if (array_intersect_key($fields, $field_collection_fields)) {
          $args = array('@type' => $entity_types[$entity_type]['label']);
          $properties["host_entity_$entity_type"] = array(
            'label' => t('Host entity (@type)', $args),
            'type' => $entity_type,
            'description' => t('The @type containing the field collection field (empty if this field collection is attached to an item of a different type).', $args),
            'getter callback' => 'field_collection_item_get_specific_type_host_entity',
            'computed' => TRUE,
          );
          break;
        }
      }
    }

    return $info;
  }

}
