<?php

/**
 * @file
 * Plugin to provide a Mapzen geocoder.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Mapzen"),
  'description' => t('Geocodes via Mapzen search'),
  'callback' => 'geocoder_mapzen',
  'field_types' => array('text', 'text_long', 'file', 'computed'),
  'field_callback' => 'geocoder_mapzen_field',
);


/**
 * Process Markup
 */
function geocoder_mapzen($address, $options = array()) {
  geophp_load();
  $api_url = "https://search.mapzen.com/v1/search";
  $geocoder_settings = variable_get('geocoder_settings', array());

  if (!empty($geocoder_settings['geocoder_apikey_mapzen'])) {
    $api_key = $geocoder_settings['geocoder_apikey_mapzen'];
  }
  else {
    throw new Exception('You must specify an API key for Mapzen.');
  }

  $params = array(
    'api_key' => $api_key,
    'size' => 1,
  );
  $request = drupal_http_request($api_url . '?text=' . str_replace(' ', '+', $address) . '&' . drupal_http_build_query($params));
  $data = $request->data;
  return geoPHP::load($data, 'json');
}

function geocoder_mapzen_field($field, $field_item) {
  if ($field['type'] == 'text' || $field['type'] == 'text_long' || $field['type'] == 'text_with_summary' || $field['type'] == 'computed') {
    return geocoder_mapzen($field_item['value']);
  }
  if ($field['type'] == 'addressfield') {
    $address = geocoder_widget_parse_addressfield($field_item);
    return geocoder_mapzen($address);
  }
  if ($field['type'] == 'location') {
    $address = geocoder_widget_parse_locationfield($field_item);
    return geocoder_mapzen($address);
  }
  if ($field['type'] == 'taxonomy_term_reference') {
    $term = taxonomy_term_load($field_item['tid']);
    return geocoder_mapzen($term->name);
  }
}

