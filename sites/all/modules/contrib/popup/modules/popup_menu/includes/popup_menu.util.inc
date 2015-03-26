<?php



/* ---- Forms ---- */



function popup_menu_block_form($delta){

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.admin');

  $settings = _popup_menu_settings();

  $settings = isset($settings[$delta])
    ? $settings[$delta]
    : _popup_menu_default_settings();

  $format_options = array_keys(_popup_ui_formatter_settings());
  array_unshift($format_options, 'Default');
  $display_format_options = array_combine($format_options, $format_options);

  $format = isset($settings['format'])
    ? $settings['format']
    : 'Default';
  $title_override = isset($settings['override-title'])
    ? $settings['override-title']
    : '';

  return array(

    'popup-format' => array(
      '#default_value' => $format,
      '#title' => 'Display format',
      '#type' => 'select',
      '#options' => $display_format_options,
      '#description' => t('Select the format in which to display popups. You may manage popup formats !here.', array('!here' => l('here', 'admin/config/user-interface/popup/formats'))),
      '#weight' => -2,
    ),

    'popup-override-title' => array(
      '#default_value' => $title_override,
      '#title' => 'Override menu title',
      '#type' => 'textfield',
      '#description' => t('Enter a title to use for the popup instead of the menu title.'),
      '#weight' => -2,
    ),

  );

}



function popup_menu_block_form_save($delta, $edit){

  $settings = _popup_menu_settings();

  $settings[$delta] = array(
    'format' => $edit['popup-format'],
    'override-title' => $edit['popup-override-title'],
  );

  _popup_menu_settings($settings);

}



/* ---- Settings ---- */



function _popup_menu_settings($new_settings = FALSE){

  static $settings = FALSE;
  if ($new_settings){
    $settings = $new_settings;
    variable_set('popup-menu-settings', $settings);
  }

  if (!$settings){
    $settings =  variable_get('popup-menu-settings', array());
  }

  return $settings;
}



function _popup_menu_default_settings(){

	module_load_include('inc', 'popup_ui', 'includes/popup_ui.admin');

  $format_options = _popup_ui_formatter_settings();

  return array(
    'format' => isset($format_options['Popup menu']) ? 'Popup menu' : 'Default',
  );

}



