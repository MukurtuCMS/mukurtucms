<?php



/**
 *  Implementation of [component]_features_export()
 */
function popupmenu_features_export_options() {

  $blocks = popup_menu_block_info();

  $options = array();

  foreach ($blocks as $id=>$block) {
    $options[$id] = $block['info'];
  }

  return $options;
}



/**
 *  Implementation of [component]_features_export()
 */
function popupmenu_features_export($data, &$export, $module_name = '') {

  module_load_include('inc', 'popup_menu', 'includes/popup_menu.util');

  $pipe = array();
  $settings = _popup_menu_settings();
  $export['dependencies']['popup_menu'] = 'popup_menu';

  foreach($data as $instance){

    $pipe['menu_custom'][] = $instance;

    if (isset($settings[$instance]['format'])){
      $pipe['popupformat'][] = $settings[$instance]['format'];
    }

    $export['features']['popupmenu'][$instance] = $instance;
  }

  return $pipe;
}



/**
 *  Implementation of [component]_features_export_render()
 */
function popupmenu_features_export_render($module_name, $data, $export = NULL) {

  module_load_include('inc', 'popup_menu', 'includes/popup_menu.util');

  $settings = _popup_menu_settings();
  $code[] = '  return array(';

  foreach($data as $block){
    $format_export = features_var_export($settings[$block], '    ');
    $format_identifier = features_var_export($block);
    $code[] = "    {$format_identifier} => {$format_export},";
  }

  $code[] = '  );';
  $code = implode("\n", $code);

  return array('popupmenu_defaults' => $code);
}



/**
 * Implementation of hook_features_revert().
 */
function popupmenu_features_revert($module) {
  popupmenu_features_rebuild($module);
}



/**
 * Implementation of hook_features_rebuild().
 */
function popupmenu_features_rebuild($module) {

  module_load_include('inc', 'popup_menu', 'includes/popup_menu.util');

  $settings = _popup_menu_settings();
  $rebuild_menus = module_invoke_all('popupmenu_defaults');

  if (!empty($rebuild_menus)) {
    foreach ($rebuild_menus as $name => $rebuild_menu) {
      $settings[$name] = $rebuild_menu;
    }
  }

  _popup_menu_settings($settings);
}