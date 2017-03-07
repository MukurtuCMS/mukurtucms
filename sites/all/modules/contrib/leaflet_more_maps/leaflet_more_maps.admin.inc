<?php

/**
 * @file
 * Menu callback for Leaflet More Maps admin configuration.
 */

/**
 * Configure leaflet more maps.
 */
function leaflet_more_maps_admin_configure() {

  // First a global setting to enter the Google sat map version number
  $form['global_settings'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Global settings'),
  );

  // An arbitrary map tile.
  $google_sat_test_url = 'http://khms2.googleapis.com/kh?x=428&y=242&z=9&v=';
  for ($v = 713; $v < 1000; $v++) {
    if (leaflet_more_maps_check_url($google_sat_test_url . $v)) {
      break;
    }
  }
  if ($v < 1000) {
    // Found! Now find the first that does NOT work, return version before it.
    while (leaflet_more_maps_check_url($google_sat_test_url . ++$v)) { }
    $v--;
  }

  $form['global_settings']['google_satellite_version'] = array(
    '#type' => 'textfield',
    '#title' => t('Google satellite map version'),
    '#default_value' => variable_get('google_satellite_version', 713),
    '#description' => t('Latest working version: %version', array('%version' => ($v < 1000) ? $v : '?')),
  );

  $map_info = array();
  foreach (module_implements('leaflet_map_info') as $module) {
    if ($module !== 'leaflet_more_maps') {
      $function = $module . '_leaflet_map_info';
      if (function_exists($function)) {
        $result = call_user_func_array($function, array());
        $map_info = array_merge_recursive($map_info, $result);
      }
    }
  }
  _leaflet_more_maps_assemble_default_map_info($map_info);

  $all_layer_keys = array();
  foreach ($map_info as $map_key => $map) {
    foreach ($map['layers'] as $layer_key => $layer) {
      // Unique.
      $all_layer_keys["$map_key $layer_key"] = "$map_key $layer_key";
    }
  }
  $custom_map_layers = variable_get('leaflet_more_maps_custom_maps', array());

  if (empty($custom_map_layers)) {
    for ($i = 1; $i <= LEAFLET_MORE_MAPS_NO_CUSTOM_MAPS; $i++) {
      $custom_map_layers[$i] = array(
        'map-key' => '',
        'layer-keys' => array(),
        'reverse-order' => FALSE,
      );
    }
  }
  for ($i = 1; $i <= LEAFLET_MORE_MAPS_NO_CUSTOM_MAPS; $i++) {
    $form['map'][$i] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => $i > 1,
      '#title' => t('Custom map #@number layer selection', array('@number' => $i)),
    );
    $form['map'][$i]['map-key'] = array(
      '#type' => 'textfield',
      '#title' => t('Name of custom map #@number in the administrative UI', array('@number' => $i)),
      '#default_value' => $custom_map_layers[$i]['map-key'],
      '#description' => t('Use a blank field to remove this layer configuration from the set of selectable maps.'),
    );
    $form['map'][$i]['layer-keys'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Select one or more layers to be included in this map.'),
      '#options' => $all_layer_keys,
      '#default_value' => $custom_map_layers[$i]['layer-keys'],
      '#description' => t('If you select two or more layers, these will be selectable via radio buttons in the layer switcher on your map.'),
    );
    $form['map'][$i]['reverse-order'] = array(
      '#type' => 'checkbox',
      '#title' => t('Reverse order in layer switcher'),
      '#default_value' => $custom_map_layers[$i]['reverse-order'],
      '#description' => t('The first layer in the switcher will be the default.'),
    );
    // Organise the $form_state['values'] structure available after submission.
    $form['map'][$i]['map-key']['#parents'] = array(
      'map', $i, 'map-key');
    $form['map'][$i]['layer-keys']['#parents'] = array(
      'map', $i, 'layer-keys');
    $form['map'][$i]['reverse-order']['#parents'] = array(
      'map', $i, 'reverse-order');
  }

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save map configurations'),
  );
  $form['#submit'][] = 'leaflet_more_maps_admin_configure_form_submit';

  $form['#theme'] = 'system_settings_form';
  return $form;
}

/**
 * Execute leaflet_admin_configure_form.
 */
function leaflet_more_maps_admin_configure_form_submit($form, &$form_state) {

  // form_state_values_clean($form_state);

  variable_set('google_satellite_version', $form_state['values']['google_satellite_version']);

  $custom_maps = $form_state['values']['map'];

  // Clear out the unticked boxes.
  foreach ($custom_maps as &$custom_map) {
    $custom_map['layer-keys'] = array_filter($custom_map['layer-keys']);
  }
  variable_set('leaflet_more_maps_custom_maps', $custom_maps);

  drupal_set_message(t('The map configurations have been saved.'));

  // Refresh the cache table or hook_leaflet_more_maps() won't be called.
  cache_clear_all('*', 'cache', TRUE);
}

/**
 * A way to test if a URL returns an OK (200) response. 
 *
 * Thanks www.drupal.org/u/n20
 *
 * @param string $test_url
 * @return boolean
 */
function leaflet_more_maps_check_url($test_url) {
  $agent= 'Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.0.3705; .NET CLR 1.1.4322)';

  $ch = curl_init();
  curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
  curl_setopt($ch, CURLOPT_VERBOSE, true);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_USERAGENT, $agent);
  curl_setopt($ch, CURLOPT_URL, $test_url);
  $result = curl_exec($ch);

  $info = curl_getinfo($ch);
  return ($info['http_code'] == 200);
}
