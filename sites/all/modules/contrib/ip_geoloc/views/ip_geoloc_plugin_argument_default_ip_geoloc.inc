<?php

/**
 * @file
 * views/ip_geoloc_plugin_argument_default_ip_geoloc.inc
 */

/**
 * Default argument plugin to inject attributes from the visitor's location.
 */
class ip_geoloc_plugin_argument_default_ip_geoloc extends views_plugin_argument_default {

  public function option_definition() {
    $options = parent::option_definition();
    $options['type'] = array('default' => 'postal');
    return $options;
  }

  public function options_form(&$form, &$form_state) {
    $form['type'] = array(
      '#type' => 'select',
      '#title' => t('Location attribute to use'),
      '#options' => array(
        'postal_code' => t('Postal code'),
        'city_state' => t('City and State/Province'),
        'country' => t('Country'),
        'lat_long' => t('Latitude, longitude'),
        'formatted_address' => t('Formatted address'),
      ),
      '#default_value' => $this->options['type'],
    );
  }

  public function get_argument() {
    $location = ip_geoloc_get_visitor_location();
    if (!empty($location)) {
      switch ($this->options['type']) {
        case 'postal_code':
          return isset($location['postal_code']) ? $location['postal_code'] : '';

        case 'city_state':
          return isset($location['city']) && isset($location['region']) ? $location['city'] . ', ' . $location['region'] : '';

        case 'country':
          return isset($location['country']) ? $location['country'] : '';

        case 'lat_long':
          return isset($location['latitude']) && isset($location['longitude']) ? $location['latitude'] . ',' . $location['longitude'] : '';

        case 'formatted_address':
          return isset($location['formatted_address']) ? $location['formatted_address'] : '';
      }
    }
    return NULL;
  }

}
