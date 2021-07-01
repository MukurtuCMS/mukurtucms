<?php
/**
 * @file
 * Field handler to present a link to editt the entity content.
 */
// @codingStandardsIgnoreStart
class eck_views_handler_field_link_edit extends eck_views_handler_field_link {

  function render_link($entity, $values) {
    $entity_type = $entity->entityType();
    $bundle = $entity->bundle();
    // Return early if the user doesn't have access.
    if (entity_access('update', $entity_type, $entity)) {
      $crud_info = get_bundle_crud_info($entity_type, $bundle);
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = str_replace('%eckentity', $entity->id, $crud_info['edit']['path']);
      $this->options['alter']['query'] = drupal_get_destination();
      $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

      return $text;
    }
  }
}
// @codingStandardsIgnoreEnd