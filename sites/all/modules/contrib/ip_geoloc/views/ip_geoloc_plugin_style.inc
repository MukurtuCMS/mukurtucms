<?php

/**
 * @file
 * ip_geoloc_plugin_style.inc
 *
 * Helper functions for Views style plugins, in particular to extract location
 * data (lat/long columns) from the associated view.
 *
 * @todo turn this into a common base clase for ip_geoloc_style_*.inc.
 */

// Leaflet only.
define('IP_GEOLOC_MAP_AUTOBOX_IGNORE_VISITOR', -1);

define('IP_GEOLOC_MAP_CENTER_FIXED', 0);
define('IP_GEOLOC_MAP_CENTER_ON_FIRST_LOCATION', 1);
define('IP_GEOLOC_MAP_CENTER_ON_VISITOR', 2);
define('IP_GEOLOC_MAP_CENTER_OF_LOCATIONS', 3);
define('IP_GEOLOC_MAP_CENTER_ON_VISITOR_AND_LOCATIONS', 6);
define('IP_GEOLOC_MAP_CENTER_OF_LOCATIONS_WEIGHTED', 4);
define('IP_GEOLOC_MAP_CENTER_ON_LOCATION_FROM_ARGUMENT', 5);

/**
 * The bulk of the plugin style form.
 */
function ip_geoloc_plugin_style_bulk_of_form($views_plugin_style, &$weight, &$form, &$form_state) {

  // We only ever want to offer at most 1 grouping field.
  if (!empty($form['grouping']) && count($form['grouping']) > 1) {
    $form['grouping'] = array_slice($form['grouping'], 0, 1);
  }

  $fields = ip_geoloc_get_display_fields($views_plugin_style->display->handler, TRUE);

  $field_options = $fields;
  $type_field_name = t('Type a field name below');
  $field_options['---'] = '[' . $type_field_name . ']';
  $selected_options = $views_plugin_style->options['ip_geoloc_views_plugin_latitude'];
  if (!is_array($selected_options)) {
    $selected_options = array($selected_options);
  }
  $default_text = '';
  if (!empty($views_plugin_style->options['ip_geoloc_views_plugin_latitude_text'])) {
    $default_text = $views_plugin_style->options['ip_geoloc_views_plugin_latitude_text'];
    $selected_options['---'] = '---';
  }
  $form['ip_geoloc_views_plugin_latitude'] = array(
    '#title' => t('Name of latitude field in Views query'),
    '#type' => 'select',
    '#multiple' => TRUE,
    '#options' => $field_options,
    '#default_value' => $selected_options,
    '#weight' => $weight++,
  );
  $form['ip_geoloc_views_plugin_latitude_text'] = array(
    '#type' => 'textfield',
    '#default_value' => $default_text,
    '#states' => array(
      // Doesn't work on multi-selects, unless with patch from http://drupal.org/node/1149078
      //'visible' => array(
      // ':input[name="style_options[ip_geoloc_views_plugin_latitude][]"]' => array(
      //   'value' => array('---')),
      //),
    ),
    '#description' => t("If you have multiple fields to enter, separate these by comma's."),
    '#weight' => $weight++,
  );
  $explanation1 = t("Select the field(s) holding latitude from the select-box above. Make sure you have added it to the Fields list of this View or it won't show up above. Fields from the <strong>Geofield, Get Locations</strong> and <strong>Geolocation</strong> modules can all be selected this way.");
  $explanation2 = t('Your latitude may reside in a field with a special name. This is the case when using the <strong>Location</strong> module or when you have used <strong>relationships</strong> to pull in lat & lon. To input special names, select <em>[Type a field name below]</em> and enter the field\'s machine name. This <a target="_field_names" href="!url">list of all field names</a> may help in figuring out the correct name.', array(
    '!url' => url('admin/reports/fields')));
  $explanation3 = t('If you use a view based on the <strong>Location</strong> module, the special name is <strong>location_latitude</strong>.');

  $form['ip_geoloc_views_plugin_latitude_desc'] = array(
    '#type' => 'item',
    '#markup' => $explanation1 . '<br/><strong>' . t('Special names') . ': </strong>' . "$explanation2<br/>$explanation3",
    '#weight' => $weight++,
  );
  $default_text = '';
  $selected_option = $views_plugin_style->options['ip_geoloc_views_plugin_longitude'];
  if (!empty($views_plugin_style->options['ip_geoloc_views_plugin_longitude_text'])) {
    $default_text = $views_plugin_style->options['ip_geoloc_views_plugin_longitude_text'];
    $selected_option = '---';
  }
  $form['ip_geoloc_views_plugin_longitude'] = array(
    '#title' => t('Name of longitude field in Views query'),
    '#type' => 'select',
    '#options' => $field_options,
    '#default_value' => $selected_option,
    '#weight' => $weight++,
  );
  $form['ip_geoloc_views_plugin_longitude_text'] = array(
    '#type' => 'textfield',
    '#default_value' => $default_text,
    '#states' => array(
      'visible' => array(
        ':input[name="style_options[ip_geoloc_views_plugin_longitude]"]' => array('value' => '---'),
      ),
    ),
    '#weight' => $weight++,
  );
  $form['ip_geoloc_views_plugin_longitude_desc'] = array(
    '#type' => 'item',
    '#markup' => t('Select <em>&lt;none&gt;</em>, except when latitude and longitude are separate fields, as in the <strong>Location</strong> module. In these cases, select <em>[Type a field name below]</em> and enter the field name. For the Location module, enter <strong>location_longitude</strong>.'),
    '#weight' => $weight++,
  );

  $differentiator = isset($form_state['differentiator']) ? $form_state['differentiator'] : $views_plugin_style->options['differentiator']['differentiator_field'];

  if (isset($form_state['triggering_element'])) {
    // Get here when any form element with #ajax was changed/clicked causing
    // an auto-rebuild of the form. Can't put this in an ajax handler, as these
    // are called AFTER the form rebuild, so too late.
    if (strpos($form_state['triggering_element']['#id'], 'differentiator-differentiator-field') > 0) {
      // Get here when it was the differentiator drop-down that was changed.
      $differentiator = $form_state['triggering_element']['#value'];
      unset($form_state['num_associations']);
    }
  }
  $form_state['differentiator'] = $differentiator;
  // Or AJAX won't work!
  $form_state['no_cache'] = FALSE;

  $is_openlayers = $form_state['renderer'] == 'openlayers';
  $is_google = $form_state['renderer'] == 'google';

  if ($is_openlayers || $is_google) {
    $form['default_marker_color'] = array(
      '#title' => t('Default location marker'),
      '#type' => 'select',
      '#default_value' => $views_plugin_style->options['default_marker_color'],
      '#options' => $is_openlayers ? ip_geoloc_openlayers_marker_layers() : ip_geoloc_marker_colors(),
      '#description' => t('Select an image to use for all location markers whose images are not overridden by the <strong>location differentiator</strong> below.'),
      '#attributes' => array(
        'class' => $is_openlayers ? array('marker-color-ol') : array('marker-color')),
      '#weight' => $weight++,
    );
  }
  if (!$is_openlayers) {
    $path = drupal_get_path('module', 'ip_geoloc');
    $css_file = strpos(ip_geoloc_marker_directory(), 'amarkers') ? 'ip_geoloc_admin_select_amarkers.css' : 'ip_geoloc_admin_select_markers.css';
    $form['default_marker_color']['#attached']['css'] = array("$path/css/$css_file");
  }

  $descr = t('You may designate <em>any</em> field from your view as a <strong>location differentiator</strong>. Locations that match the same corresponding differentiator value will have the same marker image on the map. Examples of location differentiators are content type and taxonomy term. You can enter numeric and alphabetic <em>ranges</em> too, e.g. price ranges, like 100--125.');
  // Add wrapper for differentiator drop-down, association table and buttons.
  // The id in the prefix must match the AJAX submit handlers below.
  $form['differentiator'] = array(
    '#type' => 'fieldset',
    '#title' => t('Location differentiator and associated markers'),
    '#description' => $descr,
    '#prefix' => '<div id="differentiator-wrapper">',
    '#suffix' => '</div>',
    '#weight' => $weight++,
  );

  $instances = ip_geoloc_get_field_instances($differentiator);
  $instance = reset($instances);

  if (empty($differentiator)) {
    $description = t('Optionally select a location differentiator.');
  }
  else {
    $description = t('Below associate %differentiator values with marker images.', array(
      '%differentiator' => empty($instance) ? $fields[$differentiator] : $instance['label'],
    )) . '<br/>';
    $field = field_info_field($differentiator);
    if (!$field || $field['module'] == 'text') {
      $description .= t('You may enter a range of values by separating "from" and "to" by a <strong>double hyphen</strong>.<br/>Example: <strong>A--ZZ</strong><br/>You may omit "from" or "to" to create open-ended ranges.');
    }
    elseif ($field['module'] == 'number') {
      $description .= t('You may enter a numeric range of by separating "from" and "to" by a <strong>double hyphen</strong>.<br/>Example: <strong>2.5--7.95</strong><br/>You may omit "from" or "to" to create open-ended ranges.');
    }
    $description .= '<br/>' . t('You can refer to View URL arguments via !1, !2 etc.')
      . '<br/>' . t('To use components of complex field types like Date or AddressField use replacement tokens in the <em>Global: Custom text</em> field.');
    $description .='<br/>' . t('Font icon character and class columns apply to Leaflet only.');
  }
  $form['differentiator']['differentiator_field'] = array(
    '#title' => t('Location differentiator'),
    '#type' => 'select',
    '#default_value' => $differentiator,
    '#options' => $fields,
    '#description' => $description,
    '#ajax' => array(
      'callback' => '_ip_geoloc_plugin_style_refresh_color_table_js',
      'wrapper' => 'differentiator-wrapper',
    ),
  );
  if (!empty($differentiator)) {
    // Container for the differentiator color associations table.
    $form['differentiator']['color_table'] = array(
      '#theme' => 'ip_geoloc_plugin_style_differentiator_color_table',
    // '#prefix' => '<div id="differentiator-color-table-wrapper">',
    // '#suffix' => '</div>'
    );

    _ip_geoloc_plugin_style_differentiator_color_table_form($form, $form_state);

    $form['differentiator']['add-another'] = array(
      '#type' => 'submit',
      '#value' => empty($form_state['num_associations']) ? t('Add an association') : t('Add another association'),
      '#weight' => 1,
      '#submit' => array('_ip_geoloc_plugin_style_add_association_submit'),
      '#ajax' => array(
        'callback' => '_ip_geoloc_plugin_style_refresh_color_table_js',
        'wrapper' => 'differentiator-wrapper',
        // Or 'none' or 'slide'.
        'effect' => 'fade',
        // Or 'slow' or number of millisec.
        'speed' => 'fast',
      ),
    );
    if (!empty($form_state['num_associations'])) {
      $form['differentiator']['remove'] = array(
        '#type' => 'submit',
        '#value' => t('Remove bottom association'),
        '#weight' => 2,
        '#submit' => array('_ip_geoloc_plugin_style_remove_association_submit'),
        '#ajax' => array(
          'callback' => '_ip_geoloc_plugin_style_refresh_color_table_js',
          'wrapper' => 'differentiator-wrapper',
          // Or 'fade' or 'slide'.
          'effect' => 'none',
          // Or 'slow' or number of millisec.
          'speed' => 'fast',
        ),
      );
    }
  }
  $desc = '';
  if ($is_openlayers) {
    $desc = t('*) If you want a fixed center, visit the "Center & Bounds" vertical tab on the <a target="_ol_map_edit" href="@url">map edit page</a>. This is also where you set the initial zoom level.', array(
      '@url' => url('admin/structure/openlayers/maps/' . $views_plugin_style->options['map'] . '/edit'),
    ));
  }
  elseif ($is_google) {
    $desc = t('*) If you choose the first option you may center the map via the special <strong>Map options</strong> <em>"centerLat"</em> and <em>"centerLng"</em>.<br/>Example: %center_example', array(
      '%center_example' => '{ "mapTypeId":"terrain", "centerLat":-37.8, "centerLng":145 }',
    ));
  }
  $form['center_option'] = array(
    '#title' => t('Map centering options'),
    '#type' => 'radios',
    '#default_value' => $views_plugin_style->options['center_option'],
    '#options' => array(
      IP_GEOLOC_MAP_CENTER_FIXED => t('Fixed center; see note below *)'),
      IP_GEOLOC_MAP_CENTER_ON_FIRST_LOCATION => t('Use the first location returned by the view as the center of the map.'),
      IP_GEOLOC_MAP_CENTER_ON_VISITOR => t("Center the map on the visitor's current location, at the specified zoom level."),
      IP_GEOLOC_MAP_CENTER_OF_LOCATIONS => t('Use the center of the rectangle whose sides are defined by the left-most, right-most, top and bottom locations (this option is insensitive to location clusters).'),
      IP_GEOLOC_MAP_CENTER_OF_LOCATIONS_WEIGHTED => t('Use the center of gravity based on all locations, except the visitor location (this option is sensitive to location clusters)'),
    ),
    '#description' => $desc,
    '#weight' => $weight++,
  );
  $form['empty_map_center'] = array(
    '#title' => t('No locations behaviour'),
    '#type' => 'textfield',
    '#size' => 30,
    '#default_value' => $views_plugin_style->options['empty_map_center'],
    '#description' => t('a) Show empty map: enter <em>latitude, longitude</em> of the map center.<br/>b) Show empty map centered on visitor location: enter the word %visitor.<br/>c) Show nothing: if this field is left blank, the map canvas will be suppressed when there are no locations to show. If you wish, you may use the <strong>No results behavior</strong> panel in the Advanced section of the Views UI to show an alternative text or content.', array(
      '%visitor' => t('visitor'))),
    '#weight' => $weight++,
  );
  return $form;
}

/**
 * Validation for ip_geoloc_plugin_style_bulk_of_form().
 */
function ip_geoloc_plugin_style_bulk_of_form_validate(&$form, &$form_state) {
  $options = &$form_state['values']['style_options'];
  if (in_array('---', $options['ip_geoloc_views_plugin_latitude'])) {
    $names = explode(',', $options['ip_geoloc_views_plugin_latitude_text']);
    foreach ($names as $name) {
      $name = trim($name);
      $options['ip_geoloc_views_plugin_latitude'][$name] = $name;
    }
    unset($options['ip_geoloc_views_plugin_latitude']['---']);
  }
  else {
    $options['ip_geoloc_views_plugin_latitude_text'] = '';
  }
  if ($options['ip_geoloc_views_plugin_longitude'] == '---') {
    $options['ip_geoloc_views_plugin_longitude'] = trim($options['ip_geoloc_views_plugin_longitude_text']);
  }
  else {
    $options['ip_geoloc_views_plugin_longitude_text'] = '';
  }
}

/**
 * Submit handler for the "Add another association" button.
 *
 * Increments the counter and forces a form rebuild.
 */
function _ip_geoloc_plugin_style_add_association_submit($form, &$form_state) {
  $form_state['num_associations']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the "Remove" button.
 *
 * Decrements the counter and forces a form rebuild.
 */
function _ip_geoloc_plugin_style_remove_association_submit($form, &$form_state) {
  $form_state['num_associations']--;
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback in response to new rows or the diff. drop-down being changed.
 *
 * At this point the $form has already been rebuilt. All we have to do here is
 * tell AJAX what part of the browser form needs to be updated.
 */
function _ip_geoloc_plugin_style_refresh_color_table_js($form, &$form_state) {
  // Return the updated table, so that ajax.inc can issue commands to the
  // browser to update only the targeted sections of the page.
  return $form['options']['style_options']['differentiator'];
}

/**
 * Submit handler as declared in
 * ip_geoloc_form_views_ui_edit_display_form_alter().
 */
function ip_geoloc_plugin_style_diff_color_ass_submit($form, &$form_state) {
  if (empty($form_state['view']) || empty($form_state['display_id']) || empty($form_state['differentiator'])) {
    return;
  }
  $view_id = $form_state['view']->name;
  $display_id = $form_state['display_id'];
  $differentiator = $form_state['differentiator'];

  // Erase differentiator values for this display, then rebuild based on form.
  $diff_color_ass = variable_get('ip_geoloc_' . $view_id . '_color_mappings', array());
  unset($diff_color_ass[$display_id][$differentiator]);

  if (!empty($form_state['values']['color_table'])) {
    $i = 0;
    foreach ($form_state['values']['color_table'] as $association) {

      if (is_array($association[$differentiator])) {
        // E.g association['field_address']['und'][0]['postal_code']
        foreach ($association[$differentiator][LANGUAGE_NONE] as $values) {
          $differentiator_value = array();
          if (is_array($values)) {
            foreach ($values as $name => $value) {
              if (isset($value) && strpos($value, '|') === FALSE) {
                $differentiator_value[$name] = $value;
              }
            }
          }
          else {
            $differentiator_value[] = $values;
          }
          if (!empty($differentiator_value)) {
            $diff_color_ass[$display_id][$differentiator][$i]['differentiator_value'] = $differentiator_value;
            $diff_color_ass[$display_id][$differentiator][$i]['color'] = $association['color'];
            $diff_color_ass[$display_id][$differentiator][$i]['special char'] = $association['special char'];
            $diff_color_ass[$display_id][$differentiator][$i]['special char class'] = $association['special char class'];
            $i++;
          }
        }
      }
      else {
        // Plain text field or plain taxonomy select.
        $differentiator_value = trim($association[$differentiator]);
        if (!empty($differentiator_value) || $differentiator_value == 0) {
          $diff_color_ass[$display_id][$differentiator][$i]['differentiator_value'] = array($differentiator_value);
          $diff_color_ass[$display_id][$differentiator][$i]['color'] = $association['color'];
          $diff_color_ass[$display_id][$differentiator][$i]['special char'] = $association['special char'];
          $diff_color_ass[$display_id][$differentiator][$i]['special char class'] = $association['special char class'];
          $i++;
        }
      }
    }
  }
  variable_set('ip_geoloc_' . $view_id . '_color_mappings', $diff_color_ass);
}

/**
 * Plugin style color differ.
 */
function _ip_geoloc_plugin_style_differentiator_color_table_form(&$form, &$form_state) {

  $is_openlayers = $form_state['renderer'] == 'openlayers';

  // First the saved rows...
  // @todo: if $field['cardinality'] > 1, compress multiple diff. values
  // for the same color together in a single row.
  $view_id = $form_state['view']->name;
  $display_id = $form_state['display_id'];
  $differentiator = $form_state['differentiator'];

  $diff_color_ass = variable_get('ip_geoloc_' . $view_id . '_color_mappings', array());
  if (empty($diff_color_ass[$display_id][$differentiator])) {
    $diff_color_ass[$display_id] = array($differentiator => array());
  }
  $row = 0;
  foreach ($diff_color_ass[$display_id][$differentiator] as $association) {
    if (!is_array($association)) {
      // Data corrupt.
      break;
    }
    if (isset($form_state['num_associations']) && $row >= $form_state['num_associations']) {
      break;
    }
    $form['differentiator']['color_table'][$row] = _ip_geoloc_plugin_style_diff_color_table_row_form($is_openlayers, $row, $differentiator, $association);
    $row++;
  }
  // ... then the empty rows.
  if (!isset($form_state['num_associations'])) {
    $form_state['num_associations'] = count($diff_color_ass[$display_id][$differentiator]);
  }
  while ($row < $form_state['num_associations']) {
    $form['differentiator']['color_table'][$row] = _ip_geoloc_plugin_style_diff_color_table_row_form($is_openlayers, $row, $differentiator);
    $row++;
  }
}

/**
 * Diffs the color table plugin style row.
 */
function _ip_geoloc_plugin_style_diff_color_table_row_form($is_openlayers, $row, $differentiator, $association = NULL) {

  $differentiator_value = empty($association) ? NULL : $association['differentiator_value'];
  $attr_class = $is_openlayers ? array('differentiator ol') : array('differentiator');

  if (strpos($differentiator, 'field_') === 0) {
    $field = field_info_field($differentiator);
    $instances = ip_geoloc_get_field_instances($differentiator);
    $instance = reset($instances);
    $widget = $instance['widget']['type'];

    if (strpos($widget, 'taxonomy') !== FALSE) {
      // Covers core and Autocomplete Deluxe.
      $vid = 0;
      $vocabulary_name = $field['settings']['allowed_values'][0]['vocabulary'];
      foreach (taxonomy_get_vocabularies() as $vid => $vocabulary) {
        if ($vocabulary->machine_name == $vocabulary_name) {
          break;
        }
      }
      $options = array();
      foreach (taxonomy_get_tree($vid) as $term) {
        $options[$term->tid] = str_repeat('-', $term->depth) . $term->name;
      }
      $form[$differentiator] = array(
        '#type' => empty($options) ? 'textfield' : 'select',
        '#options' => $options,
        '#default_value' => $differentiator_value,
        '#attributes' => array('class' => $attr_class),
      );
    }
    else {
      // No label, unless other modules override this.
      $instance['label'] = '';
      // Don't want asterisk to appear.
      $instance['required'] = FALSE;
      // Make sure the text field is wide enough, especially for the case of a
      // range, which needs to receive two values and a separator.
      if (isset($instance['widget']['settings']['size']) && $instance['widget']['settings']['size'] < 15) {
        $instance['widget']['settings']['size'] = 15;
      }
      $items[0] = empty($differentiator_value) ? array() : is_array($differentiator_value) ? $differentiator_value : array($differentiator_value);
      if (isset($instance['default_value'])) {
        $items[0] += is_array($instance['default_value']) && !empty($instance['default_value']) ? reset($instance['default_value']) : $instance['default_value'];
      }
      $form['#parents'] = array();
      $form_state = array();

      $form = field_default_form($instance['entity_type'], NULL, $field, $instance, LANGUAGE_NONE, $items, $form, $form_state);

      if ($field['module'] == 'number' || $field['module'] == 'text') {
        $form[$differentiator][LANGUAGE_NONE][0][key($field['columns'])]['#element_validate'] = array('ip_geoloc_range_widget_validate');
      }
      $form[$differentiator]['#attributes']['class'][] = $attr_class;
    }
  }
  else {
    // Not a field, maybe an expression. Or a taxonomy term NOT wrapped in a
    // field, e.g., 'taxonomy_term_data_name'.
    if (ip_geoloc_is_taxonomy_term($differentiator)) {
      // The problem is that we don't know for sure the vocabulary...
      // So we cannot produce a drop-down select with all terms...
      // Fall back on textfield.
    }
    $form[$differentiator] = array(
      '#type' => 'textfield',
      '#size' => 40,
      '#default_value' => $differentiator_value,
      '#element_validate' => array('ip_geoloc_range_widget_validate'),
      '#attributes' => array('class' => $attr_class),
    );
  }
  $form['color'] = array(
    '#type' => 'select',
    '#default_value' => empty($association) ? NULL : $association['color'],
    '#options' => $is_openlayers ? ip_geoloc_openlayers_marker_layers() : ip_geoloc_marker_colors(),
    '#attributes' => array(
      'class' => $is_openlayers ? array('marker-color-ol') : array('marker-color'),
    ),
  );
  $form['special char'] = array(
    '#type' => 'textfield',
    '#size' => 8,
    '#default_value' => empty($association) ? NULL : $association['special char'],
  );
  $form['special char class'] = array(
    '#type' => 'textfield',
    '#size' => 25,
    '#default_value' => empty($association) ? NULL : $association['special char class'],
  );
  // We'll manually set the #parents property of these fields so that their
  // values appear in the $form_state['values']['color_table'] array.
  $form[$differentiator]['#parents'] = array(
    'color_table', $row, $differentiator);
  $form['color']['#parents'] = array(
    'color_table', $row, 'color');
  $form['special char']['#parents'] = array(
    'color_table', $row, 'special char');
  $form['special char class']['#parents'] = array(
    'color_table', $row, 'special char class');

  return $form;
}

/**
 * Return HTML for differentiator to color associations table.
 *
 * @param array $variables
 *   An associative array containing $variables['form']: a render element
 *   representing the form.
 *
 * @ingroup themeable
 */
function theme_ip_geoloc_plugin_style_differentiator_color_table($variables) {
  // Use the first form child to find out the name of the differentiator.
  $form = $variables['form'];
  $form_children = element_children($form);
  if (empty($form_children)) {
    return '';
  }
  $key = reset($form_children);
  foreach ($form[$key] as $attribute_name => $element) {
    if (drupal_substr($attribute_name, 0, 1) != '#' && $attribute_name != 'color') {
      $differentiator = $attribute_name;
      break;
    }
  }
  if (empty($differentiator)) {
    return '';
  }
  $instances = ip_geoloc_get_field_instances($differentiator);
  $instance = reset($instances);
  $differentiator_label = isset($instance) ? $instance['label'] : $differentiator;

  $headers = array(
    t('%differentiator value', array('%differentiator' => $differentiator_label)),
    t('Associated style/color'),
    t('Font icon character'),
    t('Font icon class'),
  );
  $rows = array();
  foreach ($form_children as $key) {
    $row = array('data' => array(), 'class' => array());
    $row['data'][] = drupal_render($form[$key][$differentiator]);
    $row['data'][] = drupal_render($form[$key]['color']);
    $row['data'][] = drupal_render($form[$key]['special char']);
    $row['data'][] = drupal_render($form[$key]['special char class']);
    $rows[] = $row;
  }

  $output = theme('table', array(
    'header' => $headers,
    'rows' => $rows,
    'attributes' => array('id' => 'differentiator-color-table'),
  ));
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Extract an array of locations from the supplied views_plugin_style.
 *
 * @param string $views_plugin_style
 *   the style of views plugin
 * @param bool $enable_balloons
 *
 * @return array
 *   array of location objects, each containing lat/long and balloon_text
 */
function ip_geoloc_plugin_style_extract_locations($views_plugin_style, $enable_balloons = TRUE) {

  $latitudes = $views_plugin_style->options['ip_geoloc_views_plugin_latitude'];
  if (!is_array($latitudes)) {
    $latitudes = array($latitudes);
  }
  $longitude = trim($views_plugin_style->options['ip_geoloc_views_plugin_longitude']);

  $view = &$views_plugin_style->view;
  $view_id = $view->name;
  $display_id = $views_plugin_style->display->id;

  if ($views_plugin_style->display->handler->is_defaulted('style_options')) {
    //$display_id = 'default';
  }

  $differentiator = FALSE;
  if (!empty($views_plugin_style->options['differentiator']['differentiator_field'])) {
    $differentiator = $views_plugin_style->options['differentiator']['differentiator_field'];
    $is_tax_term = ip_geoloc_is_taxonomy_term($differentiator);
    $diff_color_ass = variable_get('ip_geoloc_' . $view_id . '_color_mappings', array());
    if (empty($diff_color_ass[$display_id])) {
      $diff_color_ass[$display_id] = array($differentiator => array());
    }
  }
  if (!empty($views_plugin_style->options['cluster_aggregation']['aggregation_field'])) {
    $aggregation_field = $views_plugin_style->options['cluster_aggregation']['aggregation_field'];
    if (isset($view->field[$aggregation_field]->definition['type'])) {
      $is_count = (substr($view->field[$aggregation_field]->definition['type'], 0, 4) == 'list');
    }
  }
  $tooltip_field = FALSE;
  if (isset($views_plugin_style->options['tooltips']['marker_tooltip'])) {
    $marker_tooltip = $views_plugin_style->options['tooltips']['marker_tooltip'];
    if (isset($view->field[$marker_tooltip])) {
      $tooltip_field = $view->field[$marker_tooltip];
    }
  }
  $tag_field = FALSE;
  if (isset($views_plugin_style->options['tags']['marker_tag'])) {
    $marker_tag = $views_plugin_style->options['tags']['marker_tag'];
    if (isset($view->field[$marker_tag])) {
      $tag_field = $view->field[$marker_tag];
    }
  }
  $locations = array();
  $error_count = $first_error = 0;
  $loc_field_names = $loc_field_aliases = array();

  foreach ($latitudes as $latitude) {
    if (isset($view->field[$latitude])) {
    //$loc_field_names[] = $view->field[$latitude]->definition['field_name'];
      // Search API [#2603450]
      $loc_field_names[] = $view->field[$latitude]->field;
      $loc_field_aliases[] = $view->field[$latitude]->field_alias;
      // Example: $loc_field_name == 'field_geo'; $loc_field_alias == 'nid';
    }
  }

  // Group the rows according to the grouping instructions, if specified.
  $sets = $views_plugin_style->render_grouping(
    $views_plugin_style->view->result,
    $views_plugin_style->options['grouping'],
    TRUE
  );
  if (!empty($views_plugin_style->options['grouping'])) {
    // @todo - Add support for multiple grouping fields?
    $group_field = $views_plugin_style->options['grouping'][0]['field'];
  }

  $separator = '<br/>';
  if (is_a($views_plugin_style, 'ip_geoloc_plugin_style_map')) {
    // Google Map options come as a JSON string.
    if ($map_options = json_decode($views_plugin_style->options['map_options'])) {
      if (isset($map_options->separator)) {
        $separator = filter_xss_admin($map_options->separator);
      }
    }
  }
  elseif (isset($views_plugin_style->options['map_options']['separator'])) {
    $separator = filter_xss_admin($views_plugin_style->options['map_options']['separator']);
  }
  
  foreach ($sets as $set) {
    // Render as a grouping set.
    if (!empty($set['group'])) {
      // This is required for some Views functions.
      $view->row_index = $i = key($set['rows']);

      $loc_field_name = reset($loc_field_names);
      $loc_field_alias = reset($loc_field_aliases);
      $j = 0;
      $row = reset($set['rows']);
      foreach ($latitudes as $latitude) {

        $base = _ip_geoloc_plugin_style_get_base1($row, $loc_field_name, $loc_field_alias);
        $location = new stdClass();
        $is_location = FALSE;
        if (_ip_geoloc_plugin_style_extract_lat_lng($location, $row, $latitude, $longitude, $base)) {
          $is_location = TRUE;
        }
        // Search API support [#2603450]
        else if (isset($row->_entity_properties)) {
          $longitude_alias = $view->field[$longitude]->field_alias;
          if (isset($row->_entity_properties[$loc_field_alias])) {
            $location->latitude = $row->_entity_properties[$loc_field_alias];
          }
          if (isset($row->_entity_properties[$longitude_alias])) {
            $location->longitude = $row->_entity_properties[$longitude_alias];
          }
          if (isset($location->latitude) && isset($location->longitude)) {
            $is_location = TRUE;
          }
        }
        if ($is_location) {
          // Remaining row values go into the balloon.
          if ($enable_balloons && !empty($views_plugin_style->rendered_fields[$i])) {
            $location->balloon_text = $views_plugin_style->rendered_fields[$i][$group_field];
            foreach ($set['rows'] as $i => $row) {
              $rendered_fields = $views_plugin_style->rendered_fields[$i];
              unset($rendered_fields[$group_field]);
              $location->balloon_text .= $separator . implode($separator, $rendered_fields);
            }
          }
          if (!empty($diff_color_ass[$display_id][$differentiator])) {
            _ip_geoloc_plugin_style_set_marker_color($location, $row, $differentiator, $is_tax_term, $view->args, $diff_color_ass[$display_id][$differentiator]);
          }
          _ip_geoloc_plugin_style_decorate($location, $row, $tooltip_field, $tag_field);

          if (isset($aggregation_field)) {
            $value = ip_geoloc_get_view_result($views_plugin_style, $aggregation_field, $i);
            $location->aggregation_value = empty($is_count) ? reset($value) : count($value);
          }
          $locations[$j ? "$i.$j" : $i] = $location;
          $j++;
        }

        $loc_field_name = next($loc_field_names);
        $loc_field_alias = next($loc_field_aliases);
      }
      if ($j === 0 && $error_count++ === 0) {
        $first_error = $i;
      }
    }
    // Render as a record set.
    else {
      foreach ($view->result as $i => $row) {
        // This is required for some Views functions.
        $view->row_index = $i;

        $loc_field_name = reset($loc_field_names);
        $loc_field_alias = reset($loc_field_aliases);
        $j = 0;
        foreach ($latitudes as $latitude) {

          $base = _ip_geoloc_plugin_style_get_base1($row, $loc_field_name, $loc_field_alias);
          $location = new stdClass();
          $is_location = FALSE;

          if (_ip_geoloc_plugin_style_extract_lat_lng($location, $row, $latitude, $longitude, $base)) {
            $is_location = TRUE;
          }
          // Search API support [#2603450]
          else if (isset($row->_entity_properties)) {
            $longitude_alias = $view->field[$longitude]->field_alias;
            if (isset($row->_entity_properties[$loc_field_alias])) {
              $location->latitude  = $row->_entity_properties[$loc_field_alias];
            }
            if (isset($row->_entity_properties[$longitude_alias])) {
              $location->longitude  = $row->_entity_properties[$longitude_alias];
            }
            if (isset($location->latitude) && isset($location->longitude)) {
              $is_location = TRUE;
            }
          }
          if ($is_location) {
            // Remaining row values go into the balloon.
            if ($enable_balloons && !empty($views_plugin_style->rendered_fields[$i])) {
              $location->balloon_text = implode($separator, $views_plugin_style->rendered_fields[$i]);
            }
            if (!empty($diff_color_ass[$display_id][$differentiator])) {
              _ip_geoloc_plugin_style_set_marker_color($location, $row, $differentiator, $is_tax_term, $view->args, $diff_color_ass[$display_id][$differentiator]);
            }
            _ip_geoloc_plugin_style_decorate($location, $row, $tooltip_field, $tag_field);
            if (isset($aggregation_field)) {
              $value = ip_geoloc_get_view_result($views_plugin_style, $aggregation_field, $i);
              $location->aggregation_value = empty($is_count) ? reset($value) : count($value);
            }
            $locations[$j ? "$i.$j" : $i] = $location;
            $j++;
          }
          $loc_field_name = next($loc_field_names);
          $loc_field_alias = next($loc_field_aliases);
        }
        if ($j === 0 && $error_count++ === 0) {
          $first_error = $i;
          if (isset($row->nid)) {
            $id = 'nid #' . $row->nid;
          }
          if (isset($row->node_title)) {
            $id .= ': ' . $row->node_title;
          }
        }
      }
    }
  }
  global $user;
  if ($error_count > 0 && (($is_debug = ip_geoloc_debug_flag()) || $user->uid == 1)) {
    $row_count = count($view->result);
    $title = empty($views_plugin_style->display->display_options['title']) ? $view->get_human_name() . ' (' . $views_plugin_style->display->display_title . ')' : $views_plugin_style->display->display_options['title'];
    $t_args = array(
      '%view_title' => $title,
      '@total' => $row_count,
      '@error_count' => $error_count,
      '@first' => $first_error + 1,
      '%id' => isset($id) ? " ($id)" : '',
      '%latitudes' => implode(' ' . t('or') . ' ', $latitudes),
    );
    $msg = ($error_count >= $row_count) 
      ? t('None of the @total result rows in view %view_title had their %latitudes set. Therefore those rows could not be displayed as locations on the map. Are you using the correct field names?', $t_args)
      : t('Out of a total of @total result rows in view %view_title, @error_count rows did not have their %latitudes set and therefore could not be shown on the map. The first row that could not be located was row #@first%id. You can improve execution efficiency by using the Views UI to add an "is not empty" filter for %latitudes.', $t_args);
    drupal_set_message($msg);

    if ($is_debug) {
      $row_contents = t('First error row:') . '<br/>';
      foreach ((array) $view->result[$first_error] as $field_name => $value) {
        if ($field_name != '_field_data') {
          $output = filter_xss_admin(print_r($value, TRUE));
          $output = drupal_substr($output, 0, 255) . (strlen($output) > 255 ? '...' : '');
          $row_contents .= "<strong>$field_name</strong> = $output<br/>";
        }
      }
      drupal_set_message($row_contents);
    }
  }
  // Allow other modules to implement
  // hook_ip_geoloc_marker_locations_alter(&$locations, &$view)
  drupal_alter('ip_geoloc_marker_locations', $locations, $view);

  return $locations;
}

function _ip_geoloc_plugin_style_get_base1($row, $location_field_name, $location_field_alias) {
  $base = NULL;
  if (isset($row->_field_data[$location_field_alias]['entity'])) {
    // The lines below are stripped back fast versions of this call:
    // $loc_field_value = $loc_field->get_value($row);
    $entity = $row->_field_data[$location_field_alias]['entity'];
    // The field value may not be there, i.e. no coordinates entered.
    if (isset($entity->{$location_field_name})) {
      $location_field_value = reset($entity->{$location_field_name});
      $base = is_array($location_field_value) ? reset($location_field_value) : $location_field_value;
    }
  }
  return $base;
}

/**
 * Plugin style base.
 */
function _ip_geoloc_plugin_style_get_base2($row, $field_name, $delta) {
  if (!isset($row) || !isset($field_name) || !isset($delta)) {
    return NULL;
  }
  if (isset($row->{$field_name}) && is_array($row->{$field_name})) {
    if (!empty($row->{$field_name}[$delta]['raw'])) {
      return $row->{$field_name}[$delta]['raw'];
      // Geofield     : field_<field_name>[0]['raw']['geom']
      // Geolocation  : field_<field_name>[0]['raw']['lat'] and ...]['lng']
      // Get Locations: field_<field_name>[0]['raw']['latitude']
    }
    $lang = LANGUAGE_NONE;
    if (!empty($row->{$field_name}[$lang][$delta])) {
      // EntityFieldQuery Views Backend.
      // For Geofield module lat/long are as follows (note: no extra
      // 'field_' prefix):
      // <field_name>['und]['0']['wkt'], for example:
      // POINT (144.976 -37.813) or MULTIPOINT ( (),(),() )
      return $row->{$field_name}[$lang][$delta];
    }
    // Last resort, retrieve from rendered, as opposed to raw, result.
    if (!empty($row->{$field_name}[$delta]['rendered'])) {
      $base = $row->{$field_name}[$delta]['rendered'];
      // See [#2287187]
      return is_string($base) ? $base : $base['#markup'];
    }
  }
  return NULL;
}


/**
 * Extract coordinates from the View result row.
 *
 * @todo This function is in flux and a bit messy at the moment....
 *
 * @param array $location
 *   The object to receive the extracted lat and lng
 * @param array $row
 *   View result row
 * @param string $latitude
 *   name of the row field that holds latitude
 * @param string $longitude
 *   name of the row field that holds longitude
 *
 * @return object|NULL
 *   location -- @todo return array for consistency with Leaflet?
 */
function _ip_geoloc_plugin_style_extract_lat_lng(&$location, $row, $latitude, $longitude, $loc_field_value = NULL) {

  $delta = &drupal_static(__FUNCTION__);
  if (isset($delta)) {
    $delta++;
  }
  // Hack for http://drupal.org/node/1824538
  // In the View, AddressField must have "Display all values in the same row"
  // UNTICKED, while Geofield (and all other fields) must have it TICKED.
  foreach ((array) $row as $key => $value) {
    if (drupal_substr($key, -6) == '_delta' && strpos($key, 'field_data_field_') === 0) {
      $delta = $value;
      break;
    }
  }
  $field_name = 'field_' . $latitude;
  if (!isset($delta) || !isset($row->{$field_name}) || $delta >= count($row->{$field_name})) {
    $delta = 0;
  }

  $base = _ip_geoloc_plugin_style_get_base2($row, $field_name, $delta);
  if (empty($base)) {
    // Drop the "field_" prefix and try again.
    $base = _ip_geoloc_plugin_style_get_base2($row, $latitude, $delta);
  }
  if (empty($base)) {
    $base = $loc_field_value;
  }
  if (empty($base)) {
    // Empty $base, e.g. Location module or Views PHP or other db fields.
    if (isset($row->{$latitude}) && isset($row->{$longitude})) {
      $location->latitude  = is_array($row->{$latitude})  ? reset($row->{$latitude}) : $row->{$latitude};
      $location->longitude = is_array($row->{$longitude}) ? reset($row->{$longitude}) : $row->{$longitude};
    }
  }
  else {
    if (is_string($base)) {
      // Expect a rendered result like "Latitude: -37.8<br/>Longitude: 144.96"
      $parts = explode(':', $base);
      if (isset($parts[2])) {
        $location->latitude = (float) $parts[1];
        $location->longitude = (float) $parts[2];
      }
    }
    elseif (isset($base['geo_type'])) {
      // Geofield.
      // Quick fix: take advantage of Leaflet module, if enabled.
      // @todo generalise Leaflet code and incorporate here.
      if (function_exists('leaflet_process_geofield')) {
        // Support WKT lines and polygons in Leaflet. Call requires:
        // $base['geo_type'] eg 'point' or 'linestring'
        // $base['geom'] eg. 'POINT(145 -37)' or 'LINESTRING(145 -37, 146, -38)'
        $loc = leaflet_process_geofield(array($base));
        $location = (object) reset($loc);

        // @todo get rid of this duality, use lat/lon throughout
        if (isset($location->lat)) {
          $location->latitude = $location->lat;
          unset($location->lat);
        }
        if (isset($location->lon)) {
          $location->longitude = $location->lon;
          unset($location->lon);
        }
      }
      else {
        $is_point = ($base['geo_type'] == 'point');
        if ($is_point) {
          // Wkt more accurate than lat,lon in Geofield 7.x-1.x.
          $point = empty($base['geom']) ? $base['wkt'] : $base['geom'];
          // @todo Consider using the following:
          // $geometry = geoPHP::load($base['geom']);
          // $location = json_decode($geometry->out('json'));
          $is_point = (drupal_substr(trim($point), 0, 7) == 'POINT (');
          if ($is_point) {
            $parts = explode(' ', drupal_substr($point, 7));
            $is_point = count($parts) > 1;
          }
        }
        // $is_point==FALSE may indicate a MULTIPOINT cluster, which has its
        // averaged center on 'lat' and 'lon' indices.
        $location->longitude = $is_point ? (float) $parts[0] : $base['lon'];
        $location->latitude  = $is_point ? (float) $parts[1] : $base['lat'];
      }
    }
    elseif (isset($base['lng'])) {
      // GeoLocation.
      $location->latitude  = $base['lat'];
      $location->longitude = $base['lng'];
    }
    elseif (isset($base['longitude'])) {
      // Get Locations.
      $location->latitude  = $base['latitude'];
      $location->longitude = $base['longitude'];
    }
    elseif (isset($row->{'field_' . $latitude}[$delta]['raw']['value'])) {
      // Other module.
      // Field values tend to be inside ...[0]['raw']['value']:
      $location->latitude  = $row->{'field_' . $latitude}[$delta]['raw']['value'];
      $location->longitude = $row->{'field_' . $longitude}[$delta]['raw']['value'];
    }
  }
  return isset($location->type) || (isset($location->latitude) && $location->latitude != '');
}

/**
 * Set the marker color based on the differentiator, if any.
 */
function _ip_geoloc_plugin_style_set_marker_color(&$location, $row, $differentiator, $is_tax_term, $view_args, $diff_color_ass) {

  if (!empty($differentiator)) {

    $differentiator_value = _ip_geoloc_plugin_style_get_differentiator_value($row, $differentiator, $view_args);

    if (!empty($differentiator_value) || $differentiator_value === 0) {

      foreach ($diff_color_ass as $key => $association) {

        if ($is_tax_term) {
          $association = _ip_geoloc_plugin_style_match_on_taxonomy_term_or_parent($differentiator_value, $diff_color_ass);
          $is_match = !empty($association);
        }
        elseif (is_array($differentiator_value)) {
          // Eg AddressField, has multiple subvalues. All must match the
          // corresponding differentiator subvalues.
          $is_match = TRUE;
          foreach ($association['differentiator_value'] as $name => $subvalue) {
            if (!isset($differentiator_value[$name]) || !ip_geoloc_is_in_range($differentiator_value[$name], $subvalue, $view_args)) {
              $is_match = FALSE;
              break;
            }
          }
        }
        else {
          // Single value, either as a simple value or an array of length 1.
          $range = $association['differentiator_value'];
          $is_match = ip_geoloc_is_in_range($differentiator_value, $range, $view_args);
        }
        if ($is_match) {
          break;
        }
      }
      if ($is_match) {
        $location->marker_color = $association['color'];
        if (!empty($association['special char'])) {
          $location->marker_special_char = $association['special char'];
        }
        if (!empty($association['special char class'])) {
          $location->marker_special_char_class = $association['special char class'];
        }
      }
    }
  }
  if (isset($location->marker_color) && is_array($location->marker_color)) {
    $location->marker_color = reset($location->marker_color);
  }
}

/**
 * Find a color association record for the suppplied taxonomy term id or name.
 *
 * @param string|array $differentiator_value, term id or term name
 * @param array $diff_color_associations
 *
 * @return mixed, the matching association or FALSE, if none was found
 *
 * This function does not support taxonomy tid RANGES, only single values.
 */
function _ip_geoloc_plugin_style_match_on_taxonomy_term_or_parent($differentiator_value, $diff_color_associations) {
  // $differentiator_value may be tid (numeric) or term name (string).
  if (isset($differentiator_value['tid'])) {
    $tid = $differentiator_value['tid'];
  }
  elseif (is_numeric($differentiator_value)) {
    $tid = $differentiator_value;
  }
  else {
    $is_name = TRUE;
    $tid = ip_geoloc_get_tid_from_name($differentiator_value);
  }
  // Starting with the current child find the first ancestor in the
  // taxonomy hierarchy that matches.
  foreach (taxonomy_get_parents_all($tid) as $term) {
    $value = empty($is_name) ? $term->tid : $term->name;
    $association = _ip_geoloc_plugin_style_find_association_by_differentiator_value($value, $diff_color_associations);
    if (!empty($association)) {
      return $association;
    }
  }
  return FALSE;
}

function _ip_geoloc_plugin_style_find_association_by_differentiator_value($differentiator_value, $diff_color_ass) {
  foreach ($diff_color_ass as $association) {
    if (ip_geoloc_is_in_range($differentiator_value, $association['differentiator_value'])) {
      return $association;
    }
  }
  return FALSE;
}

function _ip_geoloc_plugin_style_get_differentiator_value($row, $differentiator, $view_args) {

  if (preg_match('/^!([0-9])/', $differentiator, $matches)) {
    // Check if an argument was appended to the URL. Internal count is from 0.
    $position = $matches[1] - 1;
    if (isset($view_args[$position])) {
      $differentiator_value = $view_args[$position];
    }
  }
  elseif (isset($row->{$differentiator})) {
    $differentiator_value = $row->{$differentiator};
  }
  elseif (!empty($row->{'field_' . $differentiator})) {
    $differentiator_values = $row->{'field_' . $differentiator};
    if (is_array($differentiator_values)) {
      // Count > 1 for taxonomy term with lineage.
      $num_values = count($differentiator_values);
      if (isset($differentiator_values[0]['raw'])) {
        $differentiator_value = $differentiator_values[$num_values - 1]['raw'];
      }
      elseif (isset($differentiator_values[0]['rendered']['#markup'])) {
        $differentiator_value = $differentiator_values[$num_values - 1]['rendered']['#markup'];
      }
    }
  }
  elseif (!empty($row->_field_data[$differentiator]['entity'])) {
    $differentiator_value = '';
    // Retrieve first value, regardless of language.
    $v = reset($row->_field_data[$differentiator]['entity']->{$differentiator});
    if (is_array($v)) {
       $v = reset($v);
       if (is_array($v)) {
         $differentiator_value = isset($v['value']) ? $v['value'] : reset($v);
       }
    }
  }
  elseif (!empty($row->_entity_properties)) {
    // Search API
    $differentiator_value = _ip_geoloc_plugin_style_get_search_api_value($row, $differentiator);
  }
  else {
    $differentiator_value = '';
    if (!isset($row->{'field_' . $differentiator})) {
      drupal_set_message(t('IPGV&M: no differentiator values found for %diff. Cannot assign marker images.', array(
        '%diff' => $differentiator)), 'warning', FALSE);
    }
  }
  return $differentiator_value;
}

function _ip_geoloc_plugin_style_get_search_api_value($row, $field_name) {
    $field_value = null;
    if (isset($row->_entity_properties[$field_name])) {
      //drupal_set_message(t('IPGV&M (1): Search API checking value for %name', array('%name' => $field_name)), 'warning', FALSE);
      $field_value = $row->_entity_properties[$field_name];
    }
    elseif ($last_ = strrpos($field_name, '_')) {
      $alt_field_name = drupal_substr($field_name, $last_ + 1);
      //drupal_set_message(t('IPGV&M (2): Search API checking value for %name', array('%name' => $alt_field_name)), 'warning', FALSE);
      if (isset($row->_entity_properties[$alt_field_name])) {
        $field_value = $row->_entity_properties[$alt_field_name];
      }
    }
    else {
      $alt_field_name = 'field_' . $field_name;
      //drupal_set_message(t('IPGV&M (3): Search API checking value for %name', array('%name' => $alt_field_name)), 'warning', FALSE);
      if (isset($row->_entity_properties[$alt_field_name])) {
        $field_value = $row->_entity_properties[$alt_field_name];
      }
    }
    if (isset($field_value)) {
      //drupal_set_message(t('IPGV&M (success!): Search API %name=%value', array('%name' => $field_name, '%value' => $field_value)), 'warning', FALSE);
    }
    else {
      drupal_set_message(t('IPGV&M: Could not retrieve value of field %name, as its name does not appear among these Search API keys: %keys', array(
        '%name' => $field_name,
        '%keys' => implode(', ', array_keys($row->_entity_properties)),
      )), 'warning', FALSE);
    }
    return isset($field_value) ? $field_value : '';
}

function _ip_geoloc_plugin_style_decorate(&$location, $row, $tooltip_field, $tag_field) {
  if ($tooltip_field) {
    $tooltip = $tooltip_field->theme($row);
    $location->marker_tooltip = strip_tags(_ip_geoloc_plugin_style_add_label($tooltip_field, $tooltip));
  }
  if ($tag_field) {
    $tag = $tag_field->theme($row);
    $location->marker_tag = _ip_geoloc_plugin_style_add_label_and_styling($tag_field, $tag);
  }
  if (isset($row->id)) {
    // CiviCRM [#2549825]
    $location->id = $row->id;
  }
  elseif (isset($row->nid)) {
    $location->id = $row->nid;
  }
  elseif (isset($row->tid)) {
    $location->id = $row->tid;
  }
  elseif (isset($row->uid)) {
    $location->id = $row->uid;
  }
  elseif (isset($row->entity) && is_numeric($row->entity)) {
    $location->id = $row->entity;
  }
}

/**
 * Perform token replacement, convert timestamps to date strings etc.
 *
 * Store the rendered rows on the object passed in, which will typically be an
 * instance of class views_plugin_style or subclass.
 * Note that fields that have their Exclude box ticked, won't be rendered,
 * Typical candidates for exclusion are the latitude and longitude fields.
 *
 * @param string $views_plugin_style
 *   The views plugin style.
 */
function ip_geoloc_plugin_style_render_fields($views_plugin_style) {
  if (!$views_plugin_style->uses_fields() || isset($views_plugin_style->rendered_fields)) {
    return;
  }
  $views_plugin_style->rendered_fields = array();
  $differentiator = $views_plugin_style->options['differentiator']['differentiator_field'];
  $aggregation_field = isset($views_plugin_style->options['cluster_aggregation']['aggregation_field'])
    ? $views_plugin_style->options['cluster_aggregation']['aggregation_field']
    : NULL;
  $latitudes = $views_plugin_style->options['ip_geoloc_views_plugin_latitude'];
  if (!is_array($latitudes)) {
    $latitudes = array($latitudes);
  }
  $longitude = trim($views_plugin_style->options['ip_geoloc_views_plugin_longitude']);

  foreach ($views_plugin_style->view->result as $i => &$row) {
    // God knows why we need this...
    $views_plugin_style->view->row_index = $i;
    foreach ($views_plugin_style->view->field as $field_id => $field) {
      // theme() also renders the replacement tokens that may be used in the
      // balloons of OTHER fields when "Rewrite the output of this field" is
      // ticked on those fields. So even if Excluded is ticked for this field,
      // we need to theme() it for the potential sake of those other fields.
      $field_value = $field->theme($row);
      
      // Add the special 'views_' fields that normally aren't in the results
      // set to the row, if required for the $differentiator or lat/lon that
      // have math expressions applied through the Views UI.
      // Examples:
      //  "User: Roles" used as differentiator becomes 'views_rid'
      //  "Global: View result counter" as differentiator becomes 'views_counter'
      $special_field_id = 'views_' . $field_id;
      if (($special_field_id == $differentiator || $special_field_id == $aggregation_field ||
        in_array($special_field_id, $latitudes) || $special_field_id == $longitude) && empty($row->{$special_field_id})) {
        $row->{$special_field_id}[] = $field_value;
      }
      // If Excluded is ticked, we don't style and don't add the field to the
      // rendered_fields.
      if (!$field->options['exclude']) {
        $styled_field_value = _ip_geoloc_plugin_style_add_label_and_styling($field, $field_value);
        $views_plugin_style->rendered_fields[$i][$field_id] = $styled_field_value;
      }
    }
  }
  unset($views_plugin_style->view->row_index);
  return $views_plugin_style->rendered_fields;
}

/**
 * Returns as an array the raw value(s) of a field in the results set.
 *
 * @param object $views_plugin_style
 *   The Views plugin.
 * @param mixed, field array or field name (string)
 *   The field or name of the field in the View.
 * @param int index
 *   The row index into the Views result set.
 *
 * @return array
 *   The raw value(s) of the field in the specified row of the results set.
 */
function ip_geoloc_get_view_result($views_plugin_style, $field, $index) {
  $field_name = is_array($field) ? $field['field_name'] : $field;
  if (!isset($views_plugin_style->view->result[$index])) {
    drupal_set_message(t("Field %name: no value found amongst view results.", array('%name' => $field_name)), 'warning', FALSE);
    return NULL;
  }
  $row = $views_plugin_style->view->result[$index];
  if (isset($row->{"field_$field_name"}) && $row->{"field_$field_name"} != array()) {
    $values = $row->{"field_$field_name"};
  }
  elseif (isset($row->{"views_$field_name"})) {
    $values = $row->{"views_$field_name"};
  }
  elseif (isset($row->{$field_name})) {
    $values = $row->{$field_name};
  }
  elseif (isset($views_plugin_style->view->field[$field_name])) {
    $values = $views_plugin_style->get_field_value($index, $field_name);
  }
  elseif (!empty($row->_entity_properties)) {
    // Search API emergency fallback
    $values = _ip_geoloc_plugin_style_get_search_api_value($row, $field_name);
  }
  else {
    return array('');
  }
  if (!is_array($values)) {
    return array($values);
  }
  $single_values = array();
  foreach ($values as $value) {
    if (isset($value['raw'])) {
      $value = $value['raw'];
    }
    if (isset($field['type'])) {
      if ($field['type'] == 'addressfield') {
        return $value;
      }
      if (is_array($value)) {
        $value = ($field['type'] == 'taxonomy_term_reference') ? $value['tid'] : reset($value);
      }
    }
    elseif (is_array($value)) {
      $value = reset($value);
    }
    $single_values[] = $value;
  }
  return $single_values;
}

/**
 * Prefix the field value with its label, where requested. No styling.
 *
 * @param string $field
 *   The field.
 * @param string $field_content
 *   The content of the field.
 *
 * @return string
 *   $field_content prefixed with the label defined for the field
 */
function _ip_geoloc_plugin_style_add_label($field, $field_content) {
  $label = $field->label();
  if ($label && $field->options['element_label_colon']) {
    $label .= ': ';
  }
  return $label . $field_content;
}

/**
 * Style field value, label and wrapper around both, where requested.
 *
 * Note: the "Add default classes" tickbox, options['element_default_classes'],
 * is NOT supported to avoid the balloons having excessive bulky markup.
 *
 * @param string $field
 *   The field.
 * @param string $field_content
 *   The content of the field.
 *
 * @return string
 *   $field_content wrapped in HTML with CSS classes
 */
function _ip_geoloc_plugin_style_add_label_and_styling($field, $field_content) {

  if ($field_content_type = $field->element_type(TRUE, TRUE)) {
    $element = '<' . $field_content_type;
    if ($field_content_class = $field->element_classes(NULL)) {
      $element .= ' class="' . $field_content_class . '"';
    }
    $element .= '>';
    $close_element = '</' . $field_content_type . '>';
    $field_content = $element . $field_content . $close_element;
  }

  $label = $field->label();
  if ($label && $field->options['element_label_colon']) {
    $label .= ': ';
  }
  $label_and_field_content = $label . $field_content;

  if ($label_type = $field->element_label_type(TRUE, TRUE)) {
    $element = '<' . $label_type;
    if ($label_class = $field->element_label_classes(NULL)) {
      $element .= ' class="' . $label_class . '"';
    }
    $element .= '>';
    $close_element = '</' . $label_type . '>';
    $label_and_field_content = $element . $label . $close_element . $field_content;
  }

  if ($wrapper_type = $field->element_wrapper_type(TRUE, TRUE)) {
    $element = '<' . $wrapper_type;
    if ($wrapper_class = $field->element_wrapper_classes(NULL)) {
      $element .= ' class="' . $wrapper_class . '"';
    }
    $element .= '>';
    $close_element = '</' . $wrapper_type . '>';
    return $element . $label_and_field_content . $close_element;
  }
  return $label_and_field_content;
}

/**
 * Implements hook_get_display_fields().
 */
function ip_geoloc_get_display_fields($view_display, $with_table_prefixes = TRUE, $include_view_args = TRUE) {
  $fields = array('' => '<' . t('none') . '>');
  $field_handlers = $view_display->get_handlers('field');
  $exceptions = array('nid', 'tid', 'uid');
  foreach ($field_handlers as $field_id => $field_handler) {
    if ($with_table_prefixes) {
      if ($field_id == 'rid') {
        // See ip_geoloc_plugin_style_render_fields().
        $field_id = 'views_rid';
      }
      elseif (!in_array($field_id, $exceptions)
        && strpos($field_id, 'field_') === FALSE
        /*&& strpos($field_handler->table, 'search_api_index' !== 0)
        && strpos($field_handler->table, 'entity' !== 0)*/) {
        // Example: 'title' becomes 'node_title'.
        $field_id = $field_handler->table . "_$field_id";
      }
    }
    $fields[$field_id] = $field_handler->ui_name();
  }
  if ($include_view_args) {
    // Add special differentiators: up to 4 View arguments appended to the URL
    for ($i = 1; $i <= 4; $i++) {
      $fields["!$i"] = t('View URL argument #@num', array('@num' => $i));
    }
  }
  return $fields;
}

/**
 * Implements hook_get_field_instances().
 */
function ip_geoloc_get_field_instances($field_name) {
  $instances = array();
  foreach (field_info_instances() as $type_bundles) {
    foreach ($type_bundles as $bundle_instances) {
      foreach ($bundle_instances as $fld_name => $instance) {
        if ($fld_name == $field_name) {
          $instances[] = $instance;
        }
      }
    }
  }
  return $instances;
}

/**
 * Returns whether the supplied Views field name refers to a taxonomy term.
 *
 * @param string $views_field_name
 *
 * @return boolean
 */
function ip_geoloc_is_taxonomy_term($views_field_name) {
  if (!module_exists('taxonomy')) {
    return FALSE;
  }
  if ($field = field_info_field($views_field_name)) {
    return ($field['type'] == 'taxonomy_term_reference');
  }
  // Could be a vocabulary. Crude as it is, this will do for now.
  return ($views_field_name == 'tid' || strpos($views_field_name, 'taxonomy_term_') === 0);
}

/**
 * Utility function to convert a term name to its associated taxonomy term id.
 *
 * @param string $term_name
 *   e.g., 'Amsterdam'
 * @param string $vocabulary_machine_name
 *   (optional) e.g., 'city' or simply omit, if known to be unique
 *
 * @return int|string
 *   The term id if found, FALSE otherwise.
 */
function ip_geoloc_get_tid_from_name($term_name, $vocabulary_machine_name = NULL) {
  foreach (taxonomy_get_vocabularies() as $vid => $vocabulary) {
    if (empty($vocabulary_machine_name) || $vocabulary_machine_name == $vocabulary->machine_name) {
      foreach (taxonomy_get_tree($vid) as $term) {
        if ($term_name == $term->name) {
          return $term->tid;
        }
      }
    }
  }
  return FALSE;
}
