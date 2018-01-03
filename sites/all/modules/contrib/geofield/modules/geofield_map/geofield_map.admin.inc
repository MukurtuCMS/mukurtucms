<?php

/**
 * @file
 * Code for managing the Geofield Map settings page.
 */

/**
 * API Key settings form callback.
 */
function geofield_map_admin_settings($form, &$form_state) {
  $form['geofield_map_google_auth_method'] = array(
    '#type' => 'select',
    '#title' => t('Google API Authentication Method'),
    '#description' => t(''),
    '#default_value' => variable_get('geofield_map_google_auth_method', 1),
    '#options' => array(
      1 => t('API Key'),
      2 => t('Google Maps API for Work'),
    ),
  );

  $form['geofield_map_google_apikey'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps API Key'),
    '#description' => t('Obtain a Google Maps Javascript API key at <a href="@link">@link</a>', array(
      '@link' => 'https://developers.google.com/maps/documentation/javascript/get-api-key',
    )),
    '#default_value' => variable_get('geofield_map_google_apikey', ''),
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="geofield_map_google_auth_method"]' => array('value' => 1),
      ),
    ),
  );

  $form['geofield_map_google_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps API for Work: Client ID'),
    '#description' => t('For more information, visit: <a href="@link">@link</a>', array(
      '@link' => 'https://developers.google.com/maps/documentation/javascript/get-api-key#client-id',
    )),
    '#default_value' => variable_get('geofield_map_google_client_id', ''),
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="geofield_map_google_auth_method"]' => array('value' => 2),
      ),
    ),
  );

  $form['geofield_map_google_private_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps API for Work: Private/Signing Key '),
    '#description' => t('For more information, visit: <a href="@link">@link</a>', array(
      '@link' => 'https://developers.google.com/maps/documentation/business/webservices/auth#how_do_i_get_my_signing_key',
    )),
    '#default_value' => variable_get('geofield_map_google_private_key', ''),
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="geofield_map_google_auth_method"]' => array('value' => 2),
      ),
    ),
  );

  return system_settings_form($form);
}
