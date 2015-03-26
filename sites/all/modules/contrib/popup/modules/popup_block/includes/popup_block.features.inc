<?php



/**
 *  Implementation of [component]_features_export()
 */
function popupblock_features_export_options() {

  $settings = _popup_block_settings();
  $options = array();

  foreach ($settings as $id=>$block_setting) {
    if ($block_setting['active']){
      $meta = explode(':', $id);
      $blocks = module_invoke($meta[0], 'block');

      $options[$id] = $blocks[$meta[1]]['info'];
    }
  }

  return $options;
}



/**
 *  Implementation of [component]_features_export()
 */
function popupblock_features_export($data, &$export, $module_name = '') {

  $pipe = array();
  $settings = _popup_block_settings();
  $export['dependencies']['popup_block'] = 'popup_block';

  foreach($data as $instance){

    if (isset($settings[$instance]['format'])){
      $pipe['popupformat'][] = $settings[$instance]['format'];
    }

    $export['features']['popupblock'][$instance] = $instance;
  }

  return $pipe;
}



/**
 *  Implementation of [component]_features_export_render()
 */
function popupblock_features_export_render($module_name, $data, $export = NULL) {

  $settings = _popup_block_settings();
  $code[] = '  return array(';

  foreach($data as $block){
    $format_export = features_var_export($settings[$block], '    ');
    $format_identifier = features_var_export($block);
    $code[] = "    {$format_identifier} => {$format_export},";
  }

  $code[] = '  );';
  $code = implode("\n", $code);

  return array('popupblock_defaults' => $code);
}



/**
 * Implementation of hook_features_revert().
 */
function popupblock_features_revert($module) {
  popupblock_features_rebuild($module);
}



/**
 * Implementation of hook_features_rebuild().
 */
function popupblock_features_rebuild($module) {

  $settings = _popup_block_settings();
  $rebuild_blocks = module_invoke_all('popupblock_defaults');

  if (!empty($rebuild_blocks)) {
    foreach ($rebuild_blocks as $name => $rebuild_block) {
      $settings[$name] = $rebuild_block;
    }
  }

  _popup_block_settings($settings);
}
