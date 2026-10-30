<?php

/**
 * @file
 * Plugin to provide a Mapbox geocoder.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Mapbox"),
  'description' => t('Geocodes via Mapbox'),
  'callback' => 'geocoder_mapbox',
  'field_types' => array('text', 'text_long', 'addressfield', 'location', 'text_with_summary', 'computed', 'taxonomy_term_reference'),
  'field_callback' => 'geocoder_mapbox_field',
  'terms_of_service' => 'https://www.mapbox.com/tos/#geocoding',
);

/**
 * Process Markup
 */
function geocoder_mapbox($address, $options = array()) {
  global $base_path;
  $geocoder_settings = variable_get("geocoder_settings", array());

  if (!empty($geocoder_settings["geocoder_apikey_mapbox"])) {
    $access_token = $geocoder_settings["geocoder_apikey_mapbox"];
  }
  else {
    drupal_set_message(t('You must set up your Mapbox access token. Click !config', array('!config' => l(t('here'), $base_path .'admin/config/content/geocoder'))),'error');
    return;
  }

  $request = drupal_http_request("https://api.mapbox.com/geocoding/v5/mapbox.places/" . urlencode($address) . ".json?access_token=$access_token");
  $data = json_decode($request->data);

  geophp_load();
  return _geocoder_mapbox_geometry($data);
}

function geocoder_mapbox_field($field, $field_item) {
  if ($field['type'] == 'text' || $field['type'] == 'text_long' || $field['type'] == 'text_with_summary' || $field['type'] == 'computed') {
    return geocoder_mapbox($field_item['value']);
  }
  if ($field['type'] == 'addressfield' && module_exists('addressfield') && !addressfield_field_is_empty($field_item, $field)) {
    $address = geocoder_widget_parse_addressfield($field_item);
    return geocoder_mapbox($address);
  }
  if ($field['type'] == 'location') {
    $address = geocoder_widget_parse_locationfield($field_item);
    return geocoder_mapbox($address);
  }
  if ($field['type'] == 'taxonomy_term_reference') {
    $term = taxonomy_term_load($field_item['tid']);
    return geocoder_mapbox($term->name);
  }
}

function _geocoder_mapbox_geometry(&$data) {
  if (!isset($data->features)) {
    return NULL;
  }
  elseif (isset($data->features[0]->geometry->type) && $data->features[0]->geometry->type=='Point') {
    return new Point($data->features[0]->geometry->coordinates[0], $data->features[0]->geometry->coordinates[1]);
  }
}

