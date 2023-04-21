<?php

/**
 * Entity metadata implementation for the paragraphs entity.
 */
class ParagraphsItemMetadataController extends EntityDefaultMetadataController {

  /**
   * Generate basic metadata for a paragraphs item.
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info['paragraphs_item']['properties'];

    $properties['field_name']['label'] = t('Field name');
    $properties['field_name']['description'] = t('The machine-readable name of the paragraphs field containing this item.');
    $properties['field_name']['required'] = TRUE;

    $properties['host_entity'] = array(
      'label' => t('Host entity'),
      'type' => 'entity',
      'description' => t('The entity containing the paragraphs field.'),
      'getter callback' => 'paragraphs_item_get_host_entity',
      'setter callback' => 'paragraphs_item_set_host_entity',
      'required' => TRUE,
    );

    return $info;
  }

}
