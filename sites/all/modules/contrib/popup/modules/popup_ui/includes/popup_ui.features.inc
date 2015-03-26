<?php



/**
 *  Implementation of [component]_features_export()
 */
function popupformat_features_export_options() {

	module_load_include('inc', 'popup_ui', 'includes/popup_ui.admin');
	module_load_include('inc', 'popup', 'includes/popup.util');

  $options = array();

  foreach (_popup_ui_formatter_settings() as $title=>$formatter) {
    $options[$title] = $formatter['label'];
  }

  return $options;
}



/**
 *  Implementation of [component]_features_export()
 */
function popupformat_features_export($data, &$export, $module_name = '') {

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.admin');
  module_load_include('inc', 'popup', 'includes/popup.util');

  $formats = _popup_ui_formatter_settings();
  $styles = _popup_styles();
  $effects = _popup_effects();
  $export['dependencies']['popup_ui'] = 'popup_ui';

  foreach($data as $instance){

    if ($formats[$instance]['style']){
      $matches = array();
      preg_match('/\/modules\/([^\/]+)/', $styles[$formats[$instance]['style']], $matches);
      $module = $matches[1];
      $export['dependencies'][$module] = $module;
    }


    if ($formats[$instance]['effect']){
      foreach(module_implements('popup_effects') as $module){
        $provided = module_invoke($module, 'popup_effects');
        $module_effects = array_shift($provided);
        if (isset($module_effects[$formats[$instance]['effect']])){
          $export['dependencies'][$module] = $module;
          break;
        }
      }
    }

    $export['features']['popupformat'][$instance] = $instance;
  }

  return array();
}



/**
 *  Implementation of [component]_features_export_render()
 */
function popupformat_features_export_render($module_name, $data, $export = NULL) {

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.admin');

  $formats = _popup_ui_formatter_settings();
  $code[] = '  return array(';

  foreach($data as $format){
    $format_export = features_var_export($formats[$format], '    ');
    $format_identifier = features_var_export($format);
    $code[] = "    {$format_identifier} => {$format_export},";
  }

  $code[] = '  );';
  $code = implode("\n", $code);

  return array('popupformat_defaults' => $code);
}



/**
 * Implementation of hook_features_revert().
 */
function popupformat_features_revert($module) {
  popupformat_features_rebuild($module);
}



/**
 * Implementation of hook_features_rebuild().
 */
function popupformat_features_rebuild($module) {

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.admin');

  $formats = _popup_ui_formatter_settings();
  $rebuild_formats = module_invoke_all('popupformat_defaults');

  if (!empty($rebuild_formats)) {
    foreach ($rebuild_formats as $name => $rebuild_format) {
      $formats[$name] = $rebuild_format;
    }
  }

  _popup_ui_formatter_settings($formats);
}


