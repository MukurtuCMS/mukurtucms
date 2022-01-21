<?php

/**
 * Implements hook_i18n_string_info().
 */
function file_entity_i18n_string_info() {
  $groups['file_entity'] = array(
    'title' => t('File Entity'),
    'format' => FALSE,
  );
  return $groups;
}

/**
 * Implements hook_i18n_string_list().
 */
function file_entity_i18n_string_list($group) {
  if ($group == 'file_entity') {
    $fields = field_info_instances();

    $strings = array();
    foreach ($fields as $entity_type => $bundles) {
      foreach ($bundles as $bundle => $fields) {
        foreach ($fields as $field_key => $field_settings) {
          foreach ($field_settings['display'] as $view_mode => $view_mode_settings) {
            if (!empty($view_mode_settings['type']) && $view_mode_settings['type'] == 'file_download_link') {
              $text = $view_mode_settings['settings']['text'];

              $key = $entity_type . ':' . $bundle . ':' . 'link_text';

              $strings['file_entity']['file_download_link'][$key][$text] = $text;
            }
          }
        }
      }
    }

    return $strings;
  }
}
