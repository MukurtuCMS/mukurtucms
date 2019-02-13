<?php

/**
 * Page callback. 
 */
function node_view_permissions_settings_page_form($form, &$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#markup' => t('Select content types configurable by extra permissions "View own content" and "View any content".'),
  );
  foreach (node_type_get_types() as $type => $info) {
    $form['node_view_permissions_' . $type] = array(
      '#type' => 'checkbox',
      '#title' => $info->name,
      '#default_value' => node_view_permissions_check_node_type_activation($type),
    );
  }
  $form = system_settings_form($form);
  $form['#submit'][] = 'node_view_permissions_settings_page_form_submit';
  return $form;
}

/**
 * Submit handler. 
 */
function node_view_permissions_settings_page_form_submit($form, &$form_state) {
  if (count(module_implements('node_grants'))) {
    node_access_needs_rebuild(TRUE);
  }
}
