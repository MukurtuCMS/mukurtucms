<?php

/**
 * @file
 * Blocks available in IP Geolocation Views & Maps.
 */

define('IP_GEOLOC_VISITOR_DEFAULT_FIND_LABEL', t('Find me'));
define('IP_GEOLOC_VISITOR_DEFAULT_ADDRESS_LABEL', t('Move to'));
define('IP_GEOLOC_VISITOR_DEFAULT_REGION_LABEL', t('Region'));

/**
 * Implements hook_block_info().
 */
function ip_geoloc_block_info() {
  $blocks['geocode_address'] = array(
    'info' => t('IPGV&M: Set my location'),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['current_visitor_map'] = array(
    'info' => t("IPGV&M: Map (Google) centered on visitor's location"),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['recent_visitors_map'] = array(
    'info' => t('IPGV&M: Map (Google) of @n most recent visitors', array('@n' => variable_get('ip_geoloc_recent_visitors_map_number_of_visitors', 20))),
    'cache' => DRUPAL_NO_CACHE,
  );
  $blocks['address_lookup'] = array(
    'info' => t('IPGV&M: Address lookup based on IP'),
    'cache' => DRUPAL_NO_CACHE,
  );
  return $blocks;
}

/**
 * Implements hook_block_configure().
 *
 * @todo refactor, it's too long.
 */
function ip_geoloc_block_configure($delta = '') {
  $form = array();
  if ($delta == 'address_lookup') {
    return $form;
  }
  if ($delta == 'geocode_address') {
    ip_geoloc_block_set_my_location($form);
    return $form;
  }
  if ($delta == 'recent_visitors_map') {
    $form['ip_geoloc_recent_visitors_map_number_of_visitors'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of recent visitor locations to show on the map.'),
      '#default_value' => variable_get('ip_geoloc_recent_visitors_map_number_of_visitors', 20),
      '#description' => t('Must be greater than 0. Clustering is not supported, all markers are shown individually.'),
    );
  }
  $form['ip_geoloc_' . $delta . '_div_style'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS style attribute(s) applied to the HTML DIV element that is placeholding the map'),
    '#default_value' => variable_get('ip_geoloc_' . $delta . '_div_style', IP_GEOLOC_MAP_DIV_DEFAULT_STYLE),
    '#description' => t('The default %default_style results in a map of 300 pixels high, with a width bounded by the element that contains it. Do not enter quotes or equal signs.',
      array('%default_style' => IP_GEOLOC_MAP_DIV_DEFAULT_STYLE)),
  );

  switch ($delta) {

    case 'current_visitor_map':
      $form['ip_geoloc_current_visitor_map_options'] = array(
        '#type' => 'textfield',
        '#size' => 120,
        '#title' => t('Map options'),
        '#default_value' => variable_get('ip_geoloc_current_visitor_map_options', IP_GEOLOC_CURRENT_VISITOR_MAP_OPTIONS),
        '#description' => t("The default %default_options produces a street map zoomed in to level 15. A list of map options can be found <a href='!google_map_docs'>here</a>. Remember to separate options with comma's, not semi-colons, and make sure your quotes match.",
          array(
            '%default_options' => IP_GEOLOC_CURRENT_VISITOR_MAP_OPTIONS,
            '!google_map_docs' => IP_GEOLOC_DOC_GOOGLE_MAP_OPTIONS,
          )),
      );
      break;

    case 'recent_visitors_map':
      $form['ip_geoloc_recent_visitors_map_options'] = array(
        '#type' => 'textfield',
        '#size' => 120,
        '#title' => t('Map options'),
        '#default_value' => variable_get('ip_geoloc_recent_visitors_map_options', IP_GEOLOC_RECENT_VISITORS_MAP_OPTIONS),
        '#description' => t("The default %default_options produces a world map zoomed in to level 2. A list of map options can be found <a href='!google_map_docs'>here</a>. Remember to separate options with comma's, not semi-colons, and make sure your quotes match.",
          array(
            '%default_options' => IP_GEOLOC_RECENT_VISITORS_MAP_OPTIONS,
            '!google_map_docs' => IP_GEOLOC_DOC_GOOGLE_MAP_OPTIONS,
          )),
      );
      break;
  }
  return $form;
}

function ip_geoloc_block_set_my_location(&$form) {
  $form['address'] = array(
    '#type' => 'fieldset',
    '#title' => t('Visitor location'),
    '#description' => t('This panel offers various ways for the visitor to set the focus of maps created through this module.'),
  );
  $note = t('As soon as the newly updated visitor location comes in, this is reflected on the page through an automatic refresh, unless the auto-refresh has been switched off under <a href="!url">Advanced options</a>.',
    array('!url' => url('admin/config/system/ip_geoloc'))
  );
  $form['address']['find_visitor'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('"Find me" button'),
    '#description' => t("Displays a button for the visitor to put themselves on the map. If they confirm the browser prompt, this locates the visitor via their device's WiFi and GPS capabilities. This typcially takes 3 seconds.")
      . ' ' . $note,
  );
  $form['address']['find_visitor']['ip_geoloc_visitor_find'] = array(
    '#type' => 'checkbox',
    '#title' => t('Find visitor using Wifi/GPS location detection'),
    '#default_value' => variable_get('ip_geoloc_visitor_find', TRUE),
  );
  $form['address']['find_visitor']['ip_geoloc_visitor_reverse_geocode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reverse-geocode visitor location to a street address'),
    '#default_value' => variable_get('ip_geoloc_visitor_reverse_geocode', TRUE),
    '#description' => t('If ticked, reverse-geocoding is executed immeditaley after the visitor position is detected, as part of the same request. It typically adds another 0.3 seconds of waiting time.'),
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_visitor_find"]' => array('checked' => TRUE),
    )),
  );
  $form['address']['find_visitor']['ip_geoloc_visitor_find_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label for "Find me" button'),
    '#size' => 30,
    '#default_value' => filter_xss_admin(variable_get('ip_geoloc_visitor_find_label', '')),
    '#description' => t('Defaults to %default <br/>You may use most HTML tags.', array(
      '%default' => IP_GEOLOC_VISITOR_DEFAULT_FIND_LABEL,
    )),
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_visitor_find"]' => array('checked' => TRUE),
    )),
  );
  $form['address']['find_visitor']['ip_geoloc_visitor_find_position'] = array(
    '#type' => 'select',
    '#title' => t('Position of "Find me" button'),
    // Keys represent form element weights.
    '#options' => array(
      0 => t('First'),
      7 => t('Second'),
     12 => t('2nd Last'),
     17 => t('Last'),
    ),
    '#default_value' => variable_get('ip_geoloc_visitor_find_position', 0),
    '#description' => t('Relative to the other buttons on the "Set my location" form, if present. These buttons can be configured below.'),
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_visitor_find"]' => array('checked' => TRUE),
    )),
  );
  $throbber_text = variable_get('ip_geoloc_throbber_text', '');
  $form['address']['find_visitor']['ip_geoloc_throbber_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Text displayed while visitor is being geolocated'),
    '#size' => 30,
    '#default_value' => $throbber_text == '<none>' ? $throbber_text : filter_xss_admin($throbber_text),
    '#description' => t('A text shown together with an animated image, aka throbber, to show the visitor that geolocation is in progress. </br/>Defaults to %default <br/>You may use most HTML tags. Use <em>&lt;none&gt;</em> to have no throbber and no text.', array(
      '%default' => IP_GEOLOC_THROBBER_DEFAULT_TEXT,
    )),
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_visitor_find"]' => array('checked' => TRUE),
    )),
  );

  $form['address']['edit'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('"Move to" option with editable location'),
  );
  $form['address']['edit']['ip_geoloc_visitor_address_editable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Make address editable'),
    '#default_value' => variable_get('ip_geoloc_visitor_address_editable', TRUE),
    '#description' => t('If ticked, the visitor may enter a new address or tweak their reverse-geocoded address. It will be geocoded to latitude & longitude to become their new location.<br/>If not ticked, then this field simply displays the current reverse-geocoded address, without a submit button.'),
  );
  $label = variable_get('ip_geoloc_visitor_address_label', '');
  $form['address']['edit']['ip_geoloc_visitor_address_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label for editable address'),
    '#size' => 30,
    '#default_value' => $label == '<none>' ? $label : filter_xss_admin($label),
    '#description' => t('Defaults to %default. You may use most HTML tags. Use <em>&lt;none&gt;</em> for no label.', array(
      '%default' => IP_GEOLOC_VISITOR_DEFAULT_ADDRESS_LABEL,
    )),
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_visitor_address_editable"]' => array('checked' => TRUE),
    )),
  );

  $form['address']['display'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Form element to enter and display address'),
  );
  $form['address']['display']['ip_geoloc_address_element'] = array(
    '#type' => 'radios',
    '#options' => array(
      0 => t('text field'),
      1 => t('text area, 1 line'),
      2 => t('text area, 2 lines'),
      3 => t('text area, 3 lines'),
    ),
    '#default_value' => variable_get('ip_geoloc_address_element', 2),
    '#description' => t('Text areas may be resized by the visitor, text fields cannot.')
  );
  $form['address']['display']['ip_geoloc_visitor_address_default'] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t('Default partial address'),
    '#default_value' => check_plain(variable_get('ip_geoloc_visitor_address_default', '')),
    '#description' => t("You may use this to pre-populate the visitor address box with, say, a country, so that the visitor and the geocoding service have a context to the partial address entered. You may use comma's, newlines and blank lines if you wish."),
  );

  $vocabularies = array();
  foreach (taxonomy_get_vocabularies() as $vid => $vocabulary) {
    foreach (field_info_instances('taxonomy_term', $vocabulary->machine_name) as $field_name => $field) {
      $field_info = field_info_field($field_name);
      if ($field_info['type'] == 'geofield') {
        $vocabularies[$vid] = $vocabulary->name;
        break;
      }
    }
  }
  $description = t('The region selector allows the visitor to zoom in on a geographical area, such as a province or wine region, picked from a taxonomy vocabulary. The vocabulary must have a <a target="geofield" href="@url">Geofield</a> attached, providing the latitude & longitude of the centre of the region.', array(
    '@url' => url('http://drupal.org/project/geofield'),
  ));
  $form['address']['region'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Geographical region selector'),
    '#description' => $description,
  );
  $form['address']['region']['ip_geoloc_geo_vocabulary_id'] = array(
    '#type' => 'select',
    '#options' => array(0 => '--' . t('None') . '--') + $vocabularies,
    '#default_value' => variable_get('ip_geoloc_geo_vocabulary_id', 0),
  );
  if (empty($vocabularies)) {
    $form['address']['region']['ip_geoloc_geo_vocabulary_id']['#description'] = t('You do not appear to have any vocabularies on which a Geofield is defined. You cannot enable this feature until you do.');
  }
  $form['address']['region']['ip_geoloc_region_autocomplete'] = array(
    '#type' => 'select',
    '#title' => t('Widget to select geographical region'),
    '#options' => array(
      '0' => t('Select (drop-down)'),
      '1' => t('Autocomplete textfield'),
    ),
    '#default_value' => variable_get('ip_geoloc_region_autocomplete', '0'),
    '#states' => array(
      'invisible' => array('select[name="ip_geoloc_geo_vocabulary_id"]' => array('value' => '0'),
    )),
  );
  $label = variable_get('ip_geoloc_visitor_region_label', '');
  $form['address']['region']['ip_geoloc_visitor_region_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label for region selector'),
    '#size' => 30,
    '#default_value' => $label == '<none>' ? $label : filter_xss_admin($label),
    '#description' => t('Defaults to %default. You may use most HTML tags. Use <em>&lt;none&gt;</em> for no label.', array(
      '%default' => IP_GEOLOC_VISITOR_DEFAULT_REGION_LABEL,
    )),
    '#states' => array(
      'invisible' => array('select[name="ip_geoloc_geo_vocabulary_id"]' => array('value' => 0),
    )),
  );

  $form['address']['region']['ip_geoloc_region_parent'] = array(
    '#type' => 'select',
    '#title' => t('Center to use'),
    '#options' => array(
      '0' => t('Selected region'),
      '1' => t('Parent of selected region'),
      '2' => t('Grandparent of selected region'),
      '3' => t('Great-grandparent of selected region'),
    ),
    '#default_value' => variable_get('ip_geoloc_region_parent', 0),
    '#description' => t('If the selected parent does not exist the next parent up will be used instead.'),
    '#states' => array(
      'invisible' => array('select[name="ip_geoloc_geo_vocabulary_id"]' => array('value' => '0'),
    )),
  );

  $form['redirection'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Redirection'),
    '#description' => t('')
  );
  global $base_url;
  $form['redirection']['ip_geoloc_address_redirect'] = array(
    '#type' => 'textfield',
    '#field_prefix' => "$base_url/",
    '#title' => t('Redirect upon submit'),
    '#default_value' => variable_get('ip_geoloc_address_redirect', ''),
    '#description' => t('The page to redirect to after the user has pressed "Go". Use <em>&lt;front&gt;</em> for the front page.'),
  );
}

/**
 * Implements hook_block_save().
 */
function ip_geoloc_block_save($delta = '', $edit = array()) {
  if ($delta == 'address_lookup') {
    return;
  }
  if ($delta == 'geocode_address') {
    foreach ($edit as $variable => $value) {
      if (strpos($variable, 'ip_geoloc') === 0) {
        variable_set($variable, $value);
      }
    }
    return;
  }
  // Save options common to all maps.
  variable_set('ip_geoloc_' . $delta . '_div_style', $edit['ip_geoloc_' . $delta . '_div_style']);
  ip_geoloc_save_map_options('ip_geoloc_' . $delta . '_options', $edit['ip_geoloc_' . $delta . '_options']);

  switch ($delta) {
    case 'recent_visitors_map':
      variable_set('ip_geoloc_recent_visitors_map_number_of_visitors', $edit['ip_geoloc_recent_visitors_map_number_of_visitors']);
      break;
  }
}

/**
 * Implements hook_block_view().
 */
function ip_geoloc_block_view($delta = '') {
  $block = array();
  $map_style = variable_get('ip_geoloc_' . $delta . '_div_style', IP_GEOLOC_MAP_DIV_DEFAULT_STYLE);

  switch ($delta) {

    case 'geocode_address':
      $block['subject'] = t('Set my location');
      $block['content'] = drupal_get_form('ip_geoloc_set_location_form');
      break;

    case 'current_visitor_map':
      $block['subject'] = t('Your location');
      $map_options = variable_get('ip_geoloc_current_visitor_map_options', IP_GEOLOC_CURRENT_VISITOR_MAP_OPTIONS);
      $location = ip_geoloc_get_visitor_location();
      $block['content'] = theme(array('ip_geoloc_map_current_visitor'), array(
        'div_id' => 'ip-geoloc-block-current-visitor-map',
        'map_options' => $map_options,
        'map_style' => $map_style,
        // Lat,Lon NULL values will instigate HTML5 position retrieval. The
        // user will be prompted by the browser to give permission.
        'latitude'  => isset($location['latitude']) ? (float) $location['latitude'] : (empty($location['fixed_address']) ? NULL : 0.0),
        'longitude' => isset($location['longitude']) ? (float) $location['longitude'] : (empty($location['fixed_address']) ? NULL : 0.0),
        'info_text' => isset($location['formatted_address']) ? $location['formatted_address'] : NULL,
      ));
      break;

    case 'recent_visitors_map':
      $block['subject'] = t('Recent visitors');
      $how_many = variable_get('ip_geoloc_recent_visitors_map_number_of_visitors', 20);
      if ($how_many > 0) {
        $locations = ip_geoloc_get_recent_visitor_locations($how_many);
        $map_options = variable_get('ip_geoloc_recent_visitors_map_options', IP_GEOLOC_RECENT_VISITORS_MAP_OPTIONS);
        $block['content'] = theme(array('ip_geoloc_visitor_map'), array(
          'locations' => $locations,
          'div_id' => 'ip-geoloc-block-recent-visitors-map',
          'map_options' => $map_options,
          'map_style' => $map_style,
        ));
      }
      break;

    case 'address_lookup':
      $block['subject'] = t('Global IP address lookup');
      $block['content'] = drupal_get_form('ip_geoloc_ip_lookup_form');
      break;
  }
  return $block;
}

/**
 * Save map options to a Drupal variable.
 *
 * @param string $var_name
 *   The variable name to save
 *
 * @param string $map_options
 *   The map options to save
 */
function ip_geoloc_save_map_options($var_name, $map_options) {
  $map_options_decoded = drupal_json_decode($map_options);
  if ($map_options_decoded == NULL) {
    drupal_set_message(t("Sytax error in map options. These map options may not work: '%map_options'", array('%map_options' => $map_options)), 'warning');
  }
  variable_set($var_name, $map_options);
}

/**
 * Get recent visitor locations.
 *
 * @param int $how_many
 *   how many locations to retrieve
 *
 * @return object
 *   object of locations found
 */
function ip_geoloc_get_recent_visitor_locations($how_many) {
  $locations = array();
  if (db_table_exists('accesslog')) {
    // A LEFT JOIN would also pick up new IP addresses that are about to be
    // inserted into the {accesslog}.
    // However a LEFT JOIN in this query can easily make it 100 times slower
    // than the INNER JOIN used below and would only be relevant for the very
    // first click from a new IP address or in the case where the IP address was
    // removed from the {accesslog}.
    $result = db_query_range('SELECT DISTINCT ip_address, latitude, longitude, formatted_address, COUNT(a.timestamp) AS visit_count, MAX(a.timestamp) AS last_visit FROM {ip_geoloc} i INNER JOIN {accesslog} a ON i.ip_address = a.hostname GROUP BY i.ip_address ORDER BY last_visit DESC', 0, $how_many);
    $separator = '<br/>';
    foreach ($result as $location) {
      // Prevent older IP address locations overwriting the latest location.
      if (!isset($locations[$location->ip_address])) {
        $loc_rendered = new stdClass();
        $loc_rendered->latitude = $location->latitude;
        $loc_rendered->longitude = $location->longitude;
        $loc_rendered->balloon_text = t('IP address') . ' ' . $location->ip_address . '<br/>'
         . $location->formatted_address . $separator
         . t('#visits') . ' ' . (empty($location->visit_count) ? '?' : $location->visit_count)
         . ', ' . t('last visit') . ' ' . (empty($location->last_visit) ? '?' : format_date($location->last_visit, 'short'));
        $locations[$location->ip_address] = $loc_rendered;
      }
    }
  }
  return $locations;
}

/**
 * Form for finding the visitor or going to a region or street address.
 *
 * @ingroup forms
 */
function ip_geoloc_set_location_form($form, &$form_state) {

  $has_find_visitor = variable_get('ip_geoloc_visitor_find', TRUE);
  $is_address_editable = variable_get('ip_geoloc_visitor_address_editable', TRUE);
  $geo_vocabulary_id = variable_get('ip_geoloc_geo_vocabulary_id', 0);

  if (!$has_find_visitor && !$is_address_editable && !$geo_vocabulary_id) {
    drupal_set_message(t('You should select at least one of the three widgets available for the "Set my location" block.'), 'error');
    return $form;
  }

  $location = ip_geoloc_get_visitor_location();

  $form['#attributes']['id'] = $ajax_wrapper_id = drupal_html_id('set-location-form');

  if ($has_find_visitor) {
    _ip_geoloc_set_my_location_add_find_me($form, $ajax_wrapper_id);
  }

  $options = _ip_geoloc_set_my_location_add_selector($form, $location, $is_address_editable, $geo_vocabulary_id);

  $is_reverse_geocode = $has_find_visitor && variable_get('ip_geoloc_visitor_reverse_geocode', TRUE);

  if ($is_reverse_geocode || $is_address_editable) {
    _ip_geoloc_set_my_location_add_address($form, $location);
  }

  if ($geo_vocabulary_id) {
    _ip_geoloc_set_my_location_add_region($form, $location, $geo_vocabulary_id);
  }

  _ip_geoloc_set_my_location_add_logic($form, $location, $options, $is_address_editable, $geo_vocabulary_id);

  if ($is_address_editable || $geo_vocabulary_id) {
    $form['submit_address'] = array(
      '#type' => 'submit',
      '#value' => t('Go'),
      '#submit' => array('_ip_geoloc_process_go_to_submit'),
      '#weight' => 15,
    );
  }

  $form['#attributes']['class'][] = 'ip-geoloc-address';
  $form['#attached']['css'][] = drupal_get_path('module', 'ip_geoloc') . '/css/ip_geoloc_all.css';
  return $form;
}

function _ip_geoloc_set_my_location_add_find_me(&$form, $ajax_wrapper_id) {
  $find_visitor_label = variable_get('ip_geoloc_visitor_find_label', '');
  $find_visitor_label = empty($find_visitor_label) ? IP_GEOLOC_VISITOR_DEFAULT_FIND_LABEL : filter_xss_admin($find_visitor_label);

  // See _ip_geoloc_process_find_me_ajax() for why this is done here.
  if (variable_get('ip_geoloc_visitor_reverse_geocode')) {
    $form['#attached']['js'][] = IP_GEOLOC_GOOGLE_MAPS;
  }
  $form['find'] = array(
    // Use 'submit' to go with '#submit'. For #ajax 'button' may be used too.
    '#type' => 'submit',
    '#value' => $find_visitor_label,
    '#submit' => array('_ip_geoloc_process_find_me_submit'),
    '#ajax' => array(
      'callback' => '_ip_geoloc_process_find_me_ajax',
      'wrapper' => $ajax_wrapper_id,
      'progress' => FALSE,
    ),
    '#weight' => variable_get('ip_geoloc_visitor_find_position', 0),
  );
  $throbber_text = variable_get('ip_geoloc_throbber_text', '');
  if (empty($throbber_text)) {
    $throbber_text = IP_GEOLOC_THROBBER_DEFAULT_TEXT;
  }
  if ($throbber_text != '<none>') {
    $form['find']['#ajax']['progress'] = array(
      'type' => 'throbber',
      'message' => filter_xss_admin($throbber_text),
    );
  }
}

function _ip_geoloc_set_my_location_add_selector(&$form, &$location, $is_address_editable, $geo_vocabulary_id) {
  $options = array();
  $editable_address_label = variable_get('ip_geoloc_visitor_address_label', '');
  $editable_region_label = variable_get('ip_geoloc_visitor_region_label', '');

  if ($is_address_editable && $editable_address_label != '<none>') {
    $options['1'] = $editable_address_label ? filter_xss_admin($editable_address_label) : IP_GEOLOC_VISITOR_DEFAULT_ADDRESS_LABEL;
  }
  if ($geo_vocabulary_id && $editable_region_label != '<none>') {
    $options['2'] = $editable_region_label ? filter_xss_admin($editable_region_label) : IP_GEOLOC_VISITOR_DEFAULT_REGION_LABEL;
  }
  if (!empty($options)) {
    $form['fixed_address'] = array(
      '#type' => count($options) <= 1 ? 'markup' : 'select',
      '#options' => $options,
      '#default_value' => isset($options['2']) ? '2' : '1',
      '#markup' => isset($options['1']) ? $options['1'] : $options['2'],
      '#weight' => 5,
    );
  }
  return $options;
}

function _ip_geoloc_set_my_location_add_address(&$form, $location) {
  $textarea = variable_get('ip_geoloc_address_element', 2);
  $default_address = check_plain(variable_get('ip_geoloc_visitor_address_default', ''));
  $form['street_address'] = array(
    '#type' => $textarea ? 'textarea' : 'textfield',
    '#rows' => $textarea,
    '#default_value' => empty($location['formatted_address']) ? $default_address : $location['formatted_address'],
    '#weight' => 10,
  );
}

function _ip_geoloc_set_my_location_add_region(&$form, $location, $geo_vocabulary_id) {
    $regions = array(0 => '--' . t('none') . '--');
    foreach (taxonomy_get_tree($geo_vocabulary_id) as $term) {
      $regions[$term->tid] = str_repeat('-', $term->depth) . $term->name;
      if (isset($location['region']) && $location['region'] == $term->tid) {
        $current_region_name = $term->name;
      }
    }
    if (variable_get('ip_geoloc_region_autocomplete')) {
      // Use an autocomplete textfield, instead of a drop-down selector.
      $form['region'] = array(
        '#type' => 'textfield',
        '#size' => 29,
        '#default_value' => isset($current_region_name) ? $current_region_name : '',
        '#description' => t('Type the first letters of a region.'),
        // Refer to hook_menu().
        '#autocomplete_path' => 'ip_geoloc/region_autocomplete',
        '#executes_submit_callback' => TRUE,
        '#weight' => 10,
      );
    }
    else {
      $form['region'] = array(
        '#type' => 'select',
        '#options' => $regions,
        '#default_value' => isset($location['region']) ? $location['region'] : 0,
        '#weight' => 10,
      );
    }
    $form['region']['#states'] = array(
      'visible' => array('select[name="fixed_address"]' => array('value' => '2')),
    );
}

/*
 * The value of the 'fixed_address' selector is stored on the location, as
 * stored on the session. Its value is coded as follows:
 *   0: "Find me" button pressed
 *   1: "Move to" selected and "Go" pressed
 *   2: "Region" selected and "Go" pressed
 */
function _ip_geoloc_set_my_location_add_logic(&$form, $location, $options, $is_address_editable, $geo_vocabulary_id) {

  $fixed_address = empty($location['fixed_address']) ? 0 : (int)$location['fixed_address'];

  // Check if we have a "Region/Move to" drop-down ...
  if (isset($form['fixed_address'])) {
    // Default to "Move to", unless we do not have a location at all, or when
    // "Region" was selected and "Go" pressed.
   $selected = '1';
   if (isset($options['2']) && !isset($location['fixed_address']) || $fixed_address == 2) {
     $selected = '2';
   }
   $form['fixed_address']['#default_value'] = $selected;
  }

  // Disable the address box when it isn't editable.
  $form['street_address']['#disabled'] = !$is_address_editable;

  // Special logic for when there's a Region selector
  if ($geo_vocabulary_id) {

    // If "Move to" is NOT there, remove Address box when Go was pressed.
    if (!isset($options['1']) && $fixed_address == 2) {
      unset($form['street_address']);
    }
    elseif (count($options) > 1) {
      // If 2 or more options, then hide Address box when Region pressed.
      $form['street_address']['#states'] = array(
        'invisible' => array('select[name="fixed_address"]' => array('value' => '2')),
      );
    }
  }
}

/**
 * Submit handler for "Find me" button on the "Set my location block".
 *
 * This does little. See _ip_geoloc_process_find_me_ajax() for the hard work.
 *
 * @param array $form
 * @param array $form_state
 */
function _ip_geoloc_process_find_me_submit($form, &$form_state) {

  // Clear any pending location retrieval process that may be in process.
  _ip_geoloc_set_session_value('last_position_check', time());
  _ip_geoloc_set_session_value('position_pending_since', microtime(TRUE));

  // Note: cannot redirect when also using AJAX.

  // TRUE would give access to $form_state['clicked_button'], but is not needed.
  $form_state['rebuild'] = FALSE;
}

/**
 * AJAX form submit handler for the "Set my location" block.
 *
 * When this gets called the $form has already been rebuilt. What we do
 * here is return to core some JS and the part of the form that needs to be
 * updated.
 *
 * @global string $base_url
 * @param array $form
 * @param array $form_state
 * @return array, the updated $form
 */
function _ip_geoloc_process_find_me_ajax($form, &$form_state) {
  global $base_url;

  _ip_geoloc_set_session_value('position_pending_since', microtime(TRUE));

  // Cannot load Google JS here. Will result in error relating to Google code:
  // "Failed to execute 'write' on 'Document': It isn't possible to write into
  // a document from an asynchronously-loaded external script unless it is
  // explicitly opened."
  // So the Google JS lib is loaded in _ip_geoloc_set_my_location_add_find_me().
  $path = drupal_get_path('module', 'ip_geoloc');
  $form['#attached']['js'][] =  "$path/js/ip_geoloc_current_location.js";

  $menu_callback = variable_get('clean_url', 0) ? 'js/ip_geoloc/current_location' : '?q=js/ip_geoloc/current_location';
  $reverse_geocode = variable_get('ip_geoloc_visitor_reverse_geocode', TRUE);
  $refresh_page = variable_get('ip_geoloc_page_refresh', TRUE);
  $settings = array(
    'ip_geoloc_menu_callback' => "$base_url/$menu_callback",
    'ip_geoloc_reverse_geocode' => $reverse_geocode,
    'ip_geoloc_refresh_page' => $refresh_page,
  );
  drupal_add_js($settings, 'setting');

  $throbber_text = variable_get('ip_geoloc_throbber_text', '');
  if (empty($throbber_text)) {
    $throbber_text = IP_GEOLOC_THROBBER_DEFAULT_TEXT;
  }
  if ($throbber_text != '<none>') {
    $form['find-me-throbber'] = array(
      '#prefix' => IP_GEOLOC_THROBBER_PREFIX,
      '#markup' => ' ',
      '#suffix' => '</div>',
      '#weight' => $form['find']['#weight'] + 1,
    );
    $form['find-me-alert'] = array(
      '#prefix' => '<div class="message">',
      '#markup' => filter_xss_admin($throbber_text),
      '#suffix' => '</div></div>',
      '#weight' => $form['find']['#weight'] + 2,
    );
  }
  return $form;
}

/**
 * Submit handler to either go to a Region or "Move to" a street address.
 *
 * Stores the geocoded lat/long and address info on the session.
 *
 * @param array $form
 *   A form array
 * @param array $form_state
 *   The form's current state
 */
function _ip_geoloc_process_go_to_submit($form, &$form_state) {

  // Clear any pending location retrieval process that may be in process.
  _ip_geoloc_set_session_value('last_position_check', time());
  _ip_geoloc_set_session_value('position_pending_since', NULL);

  $geo_vocabulary_id = variable_get('ip_geoloc_geo_vocabulary_id', 0);

  if (empty($form_state['values']['fixed_address'])) {
    // Nothing slected. As 'Go' was pressed we need to choose 1 or 2.
    $form_state['values']['fixed_address'] = $geo_vocabulary_id ? '2' : '1';
  }

  if ($form_state['values']['fixed_address'] == '1') {
    // Using new 'input' rather than current 'values'.
    $entered_address = isset($form_state['input']['street_address']) ? check_plain($form_state['input']['street_address']) : NULL;
    $location = ip_geoloc_set_location_from_address($entered_address);
  }
  elseif ($geo_vocabulary_id) {
    // "Region" selected.
    $location = ip_geoloc_set_location_from_region($form_state['values']['region']);
  }
  // Wipe old location before setting the new one (to avoid merging).
  _ip_geoloc_set_session_value('location', NULL);
  _ip_geoloc_set_session_value('location', $location);

  $redirect = variable_get('ip_geoloc_address_redirect');
  if (!empty($redirect)) {
    $form_state['redirect'] = $redirect;
  }
  // No need to remember the form state. It's all kept on the session.
  // Also, if set to TRUE, content is rendered before new location is set
  // and Region selector will be one step behind.
  $form_state['rebuild'] = FALSE;
}

function ip_geoloc_set_location_from_region($region_name_or_tid) {
  if (!is_numeric($region_name_or_tid)) {
    $geo_vocabulary_id = variable_get('ip_geoloc_geo_vocabulary_id', 0);
    foreach (taxonomy_get_tree($geo_vocabulary_id) as $term) {
      if (strcasecmp($term->name, $region_name_or_tid) === 0) {
        $region_name_or_tid = $term->tid;
        break;
      }
    }
  }
  $parent = variable_get('ip_geoloc_region_parent', 0);
  $location = ip_geoloc_get_location_from_term($region_name_or_tid, $parent);
  $location['fixed_address'] = 2;
  return $location;
}
/**
 * Returns the location object belonging to supplied region taxonomy term id.
 *
 * @param int $tid
 *   Taxonomy term identifier
 * @param int $return_parent
 *   To return location of the parent (1) or grand-parent (2) rather than the
 *   supplied region term.
 *
 * @return array, location info
 */
function ip_geoloc_get_location_from_term($tid, $parent = 0) {

  $parents = taxonomy_get_parents_all($tid);
  if (empty($parents)) {
    return array('provider' => 'taxonomy', 'ip_address' => ip_address());
  }
  $term = $parents[min($parent, count($parents) - 1)];

  // Get lat,lng from the Geofield on this term
  $geo_vocabulary_id = variable_get('ip_geoloc_geo_vocabulary_id', 0);
  $vocabulary = taxonomy_vocabulary_load($geo_vocabulary_id);
  foreach (field_info_instances('taxonomy_term', $vocabulary->machine_name) as $field_name => $field_instance) {
    $field = field_info_field($field_name);
    if ($field['type'] == 'geofield') {
      $value = reset($term->{$field_name});
      $value = is_array($value) ? reset($value) : array();
      if (empty($value['lat'])) {
        drupal_set_message(t('The latitude and longitude of the term %name are not known.', array('%name' => $field_name)), 'warning');
        $value = array('lat' => NULL, 'lon' => NULL);
      }
      return array(
        'provider' => 'taxonomy',
        'is_updated' => TRUE,
        'ip_address' => ip_address(),
        'region' => $term->tid,
        'latitude' => $value['lat'],
        'longitude' => $value['lon'],
      //'formatted_address' => $term->name,
      );
    }
  }
}

/**
 * Returns the supplied string into an array with various address components.
 *
 * @param string $partial_address_or_landmark
 * @return array, a location holding, latitude, longitude and address fields
 */
function ip_geoloc_set_location_from_address($partial_address_or_landmark) {

  if (empty($partial_address_or_landmark)) {
    $location = array(
      'provider' => 'user',
      'ip_address' => ip_address(),
    );
  }
  else {
    if (module_exists('geocoder')) {
      // Use Google server-side API to retrieve lat/long from entered text, as
      // well as all components of the full address.
      $point = geocoder('google', $partial_address_or_landmark);
    }
    else {
      drupal_set_message(t('<a target="project_page" href="!geocoder">Geocoder</a> module must be enabled to geocode an address.', array(
        '!geocoder' => url('http://drupal.org/project/geocoder'))), 'warning');
    }
    if (empty($point)) {
      drupal_set_message(t('The address %address could not be geocoded to a location.', array(
        '%address' => $partial_address_or_landmark)), 'warning');
    }
    else {
      $location = array(
        'provider' => 'user+google',
        'is_updated' => TRUE,
        'ip_address' => ip_address(),
        'latitude' => $point->coords[1],
        'longitude' => $point->coords[0],
        'formatted_address' => $point->data['geocoder_formatted_address'],
        'accuracy' => $point->data['geocoder_accuracy'],
      );
      // Flatten the point object into a straight location array.
      foreach ($point->data['geocoder_address_components'] as $component) {
        if (!empty($component->long_name)) {
          $type = $component->types[0];
          $location[$type] = $component->long_name;
          if ($type == 'country' && !empty($component->short_name)) {
            $location['country_code'] = $component->short_name;
          }
        }
      }
    }
  }
  $location['fixed_address'] = 1;
  return $location;
}

/**
 * Generates a simple form for collecting the IP address to be reverse-geocoded.
 *
 * @ingroup forms
 */
function ip_geoloc_ip_lookup_form($form, &$form_state) {
  $last_visit = isset($form_state['storage']['last_visit']) ? $form_state['storage']['last_visit'] : '';
  $formatted_address = isset($form_state['storage']['formatted_address']) ? $form_state['storage']['formatted_address'] : '';
  if (!empty($last_visit) || !empty($formatted_address)) {
    $prefix = '<div class="ip_geoloc_address_lookup">' . $formatted_address . (empty($last_visit) ? '' : "<br/>$last_visit") . '</div>';
  }
  $form['ip_address'] = array(
    '#type' => 'textfield',
    '#title' => t('IP address'),
    '#default_value' => '',
    '#size' => 16,
    '#required' => FALSE,
    '#prefix' => isset($prefix) ? $prefix : NULL,
  );
  if (user_access('administer site configuration') && variable_get('ip_geoloc_store_addresses', TRUE)) {
    $form['store'] = array(
      '#type' => 'checkbox',
      '#title' => t('If found, store on IP geolocation database for future reference.'),
      '#default_value' => FALSE,
    );
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Lookup'),
    '#submit' => array('ip_geoloc_ip_lookup_submit'),
  );
  return $form;
}

/**
 * Lookup geoloc data.
 */
function ip_geoloc_ip_lookup_submit($form, &$form_state) {
  $store = !empty($form_state['values']['store']);
  $location = ip_geoloc_get_location_by_ip(trim($form_state['values']['ip_address']), TRUE, $store);
  if (db_table_exists('accesslog')) {
    $last_visit = db_query('SELECT MAX(timestamp) FROM {accesslog} WHERE hostname = :ip_address', array(':ip_address' => $location['ip_address']))->fetchField();
    if ($last_visit) {
      $last_visit = format_date($last_visit, 'short');
      $form_state['storage']['last_visit'] = t('<strong>Last visit:</strong> %date', array('%date' => $last_visit));
    }
  }
  $form_state['storage']['formatted_address']
    = isset($location['formatted_address']) ? t('%ip: <strong>%address</strong>', array('%ip' => $location['ip_address'], '%address' => $location['formatted_address'])) : '';
  // To preserve entered values and storage array.
  $form_state['rebuild'] = TRUE;
}
