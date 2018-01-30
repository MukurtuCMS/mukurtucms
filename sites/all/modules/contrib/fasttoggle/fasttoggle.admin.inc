<?php

/**
 * @file
 * Contains the administration forms for fasttoggle.module.
 */

module_load_include('inc', 'fasttoggle');

function fasttoggle_get_settings_form_items($config = array())
{
  $form = array();
  $setting_key = NULL;

  if (empty($config)) {
    $object_type_filter = NULL;
    $object_subtype_filter = NULL;
    $dummy_obj = NULL;
    $desc_key = "global_settings_desc";
  } else {
    $object_type_filter = $config['type'];
    $object_subtype_filter = $config['subtype'];
    $dummy_obj = new stdClass();
    $dummy_obj->type = $object_subtype_filter;
    $desc_key = "nodetype_settings_desc";
  }

  $config_data = module_invoke_all('fasttoggle_available_links', $object_type_filter, $dummy_obj);
  foreach($config_data as $object_type => $object_data) {
    if (isset($object_type_filter) && $object_type != $object_type_filter)
      continue;

    // Label settings
    $defaults = fasttoggle_defaults_from_config_data($object_data);
    unset($setting_key);

    $form["fasttoggle_{$object_type}"] = array(
        '#type' => 'fieldset',
        '#title' => isset($config['#title']) ? $config['#title'] : t(ucfirst($object_type)),
        '#description' => t('Select what options for fast toggling of this object\'s settings are available.'),
        );

    $subform = &$form["fasttoggle_{$object_type}"];

    foreach ($object_data['fields'] as $group_name => $group_data) {
      // Start a new subgroup of settings?
      if (!isset($setting_key) || isset($group_data['#title'])) {
        // For nodes, the setter adds the node type so we need to do so too when getting only.
        $setting_key = isset($config['setting']) ? "{$config['setting']}_{$object_type}_{$config['subtype']}" : "fasttoggle_{$object_type}_{$group_name}_settings";
        $current_values = array_filter(variable_get($setting_key, $defaults));

        // Some forms (node_type_admin...) do array_keys on the values saved.
        $temp = array_reverse(array_keys($current_values), TRUE);
        if (array_pop($temp) === 0) {
          $current_values = array_flip($current_values);
        }

        if (isset($config['write_key'])) {
          $setting_key = $config['write_key'];
        }
      }

      // Create the subgroup if it doesn't already exist
      if (!isset($subform[$setting_key])) {
        $subform[$setting_key] = array(
            '#type' => 'checkboxes',
            '#title' => t(ucfirst("Togglable {$object_type} {$group_name} fields and settings.")),
            '#description' => isset($object_data[$desc_key]) ? $object_data[$desc_key] : '',
            '#options' => array(),
            '#default_value' => array(),
            );
      }

      foreach ($group_data['instances'] as $field_name => $field_data) {
        $value_key = "{$group_name}_{$field_name}";
        $subform[$setting_key]['#options'][$value_key] = $field_data['description'];
        if (isset($current_values[$value_key])) {
          $subform[$setting_key]['#default_value'][] = $value_key;
        }
      }
    }

    // Extra settings
    if (empty($config) && isset($object_data['extra_settings'])) {
      $subform['extra_settings'] = array(
          '#type' => 'item',
          '#title' => t("Additional {$object_type} settings."),
          );
      foreach ($object_data['extra_settings'] as $key => $data) {
        $subform['extra_settings'][$key] = $data;
      }
    }
  }

  if (!empty($config)) {
    $temp = $form;
    $form = array_pop($temp);
  }

  return $form;
}

/**
 * (Menu callback) Configures what fast toggling options are available.
 */
function fasttoggle_settings_form() {
  $form = array();

  $form['fasttoggle_label_style'] = array(
      '#type' => 'radios',
      '#title' => t('Label style'),
      '#description' => t('Select what kind of labels you want for fasttoggle links. See the README.txt for information about providing your own labels.'),
      '#options' => array(
        FASTTOGGLE_LABEL_STATUS => t('Status (reflects the current state, e.g. "published", "active")'),
        FASTTOGGLE_LABEL_ACTION => t('Action (shows what happens upon a click, e.g. "unpublish", "block")'),
        ),
      '#default_value' => variable_get('fasttoggle_label_style', FASTTOGGLE_LABEL_STATUS),
      );

  $custom_labels = variable_get('fasttoggle_labels', array());
  if (!empty($custom_labels)) {
    $form['fasttoggle_label_style']['#options'][FASTTOGGLE_LABEL_CUSTOM] = t('Custom (configure in your settings.php)');
  }

  return system_settings_form(array_merge_recursive($form, fasttoggle_get_settings_form_items()));
}
