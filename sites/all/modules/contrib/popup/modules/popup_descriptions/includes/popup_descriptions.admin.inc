<?php



/**
 *  Administration settings form
 */
function popup_description_admin_settings(){

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.admin');

  $format_options = array_keys(_popup_ui_formatter_settings());
  array_unshift($format_options, 'Default');
  $display_format_options = array_combine($format_options, $format_options);

  $form = array(

    'description-popup-admin' => array(
      '#default_value' => variable_get('description-popup-admin', TRUE),
      '#title' => t('Enable administration links in form element descriptions'),
      '#type' => 'checkbox',
    ),

    'display' => array(
      '#type' => 'fieldset',
      '#title' => t('Display'),

      'description-popup-title' => array(
        '#default_value' => variable_get('description-popup-title', '?'),
        '#description' => t('The title that will be displayed in stead of the description. eg. "?"'),
        '#title' => t('Popup title'),
        '#type' => 'textfield',
      ),

      'description-popup-format' => array(
        '#default_value' => variable_get('description-popup-format'),
        '#description' => t('Select the format in which to display popups. You may manage popup formats !here.', array('!here' => l('here', 'admin/config/user-interface/popup/formats'))),
        '#title' => t('Display format'),
        '#type' => 'select',
        '#options' => $display_format_options,
      ),

      'description-popup-position' => array(
        '#default_value' => variable_get('description-popup-position'),
        '#description' => t('Select where the popup icon should be displayed.'),
        '#title' => t('Position'),
        '#type' => 'select',
        '#options' => array(
          t('Default (In the discription area)'),
          'label' => t('Label'),
          'prefix' => t('Prefix'),
          'suffix' => t('Suffix'),
        ),
      ),

    ),

    'selection' => array(
      '#type' => 'fieldset',
      '#title' => t('Selection'),

      'description-popup-mode' => array(
        '#default_value' => variable_get('description-popup-mode', 'specific'),
        '#options' => array(
          t('No fields'),
          'all' => t('All fields'),
          'specific' => t('Specific fields'),
        ),
        '#title' => t('Popup the descriptions of:'),
        '#type' => 'radios',
      ),

      'description-popup-id' => array(
        '#default_value' => variable_get('description-popup-id'),
        '#title' => t('Popup descriptions of fields with the following IDs:'),
        '#type' => 'checkbox',
      ),

      'description-popup-ids' => array(
        '#default_value' => variable_get('description-popup-ids'),
        '#description' => t('Enter one element id per line.<br /><em>These values will only have an effect if the "Specific fields" option is selected above.</em>'),
        '#type' => 'textarea',
        '#rows' => 10,
      ),

      'description-popup-path' => array(
        '#default_value' => variable_get('description-popup-path'),
        '#title' => t('Popup all field descriptions on the following pages:'),
        '#type' => 'checkbox',
      ),

      'description-popup-paths' => array(
        '#default_value' => variable_get('description-popup-paths'),
        '#description' => t('Enter one internal drupal path per line.<br /><em>These values will only take effect if the "Specific fields" option is selected above.</em>'),
        '#type' => 'textarea',
        '#rows' => 10,
      ),

    ),

  );

  return system_settings_form($form);
}



/* ---- Callbacks ---- */



function popup_descriptions_rule($op, $type, $id = FALSE){

  if (variable_get('description-popup-mode', 0) == 0){
    variable_set('description-popup-mode', 'specific');
  }

  if ($type == 'id'){

    variable_set('description-popup-id', 1);

    if ($op == 'add'){
      variable_set(
        'description-popup-ids',
        variable_get('description-popup-ids') . "\n" . $id
      );
    } else {
      $ids = preg_split('/[\n\r]+/', variable_get('description-popup-ids'));
      if (($key = array_search($id, $ids)) !== FALSE){
        unset($ids[$key]);
      }
      variable_set('description-popup-ids', implode("\n", $ids));
    }
  } else {

    variable_set('description-popup-path', 1);

    $path = $_GET['destination'];

    if ($op == 'add'){
      variable_set(
        'description-popup-paths',
        variable_get('description-popup-paths') . "\n" . $path
      );
    } else {
      $paths = preg_split('/[\n\r]+/', variable_get('description-popup-paths'));
      if (($key = array_search($path, $paths)) !== FALSE){
        unset($paths[$key]);
      }
      variable_set('description-popup-paths', implode("\n", $paths));
    }
  }

  drupal_goto();

}
