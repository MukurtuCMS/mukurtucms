<?php

/**
 * Implements hook_entity_property_info_alter().
 *
 * Give Users a virtual property that contains all relevant address information from multiple sources.
 */
function YOURMOD_entity_property_info_alter(&$info) {
  $info['user']['bundles']['user']['properties']['full_address'] = array(
    'type' => 'text',
    'label' => 'Full adress (from other fields)',
    'getter callback' => 'YOURMOD_user_full_address',
  );
}

/**
 * Entity property callback for user.full_address.
 *
 * field_address is a text field, and when combined with a variable makes the full address.
 */
function YOURMOD_user_full_address($entity, $options, $field, $entity_type, $property) {
  return $entity->field_address[LANGUAGE_NONE][0]['value'] . ', ' . variable_get('YOURMOD_global_country', 'Zimbabwe');
}

/**
 * Implements hook_geocoder_geocode_values_alter().
 *
 * Alter the source values before geocode them.
 */
function YOURMOD_geocoder_geocode_values_alter(&$source_field_values, $field_info, $handler_settings, $field_instance) {
  foreach($source_field_values as $key => $value) {
    $source_field_values[$key]['administrative_area'] = 'Ciudad de Buenos Aires';
  }
}
