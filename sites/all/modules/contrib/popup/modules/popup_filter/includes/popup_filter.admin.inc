<?php



function popup_filter_insert_form(){

  drupal_add_css(drupal_get_path('module', 'popup_filter').'/popup-filter-admin.css');
  drupal_add_js(drupal_get_path('module', 'popup_filter').'/popup-filter-admin.js');

  module_load_include('inc', 'popup', 'includes/popup.util');

  $default = t('Format');

  $position = _popup_filter_position_options($default);
  $modules = module_implements('block_info', TRUE);
  $activate = _popup_filter_activate_options($default);
  $views_options = _popup_filter_views_options();
  $display_format_options = _popup_filter_format_options();

	$invoke = module_invoke_all('popup_effects');
	$pop = array_pop($invoke);
  $effects = array_keys($pop);

  $widths = range(100, 500, 50);
  $popup_widths_formats = array($default) + array_combine($widths, $widths);

  $node_title_form = array(
    '#title' => t('Node title'),
    '#type' => 'textfield',
    '#autocomplete_path' => 'ajax/popup-filter/getnode',
    '#id' => 'popup-content-node-title',
  );

  $variables = array(
    'text' => _popup_filter_text(),
    'position_options' => _popup_filter_options($position),
    'module_options' => _popup_filter_options(array_combine($modules, $modules)),
    'format_options' => _popup_filter_options($display_format_options),
    'width_options' => _popup_filter_options($popup_widths_formats),
    'activate_options' => _popup_filter_options($activate),
    'type_options' => _popup_filter_options(_popup_filter_type_options()),
    'view_options' => (
      $views_options
        ? _popup_filter_options(array_filter($views_options))
        : FALSE
    ),
    'effect_options' => (
      count($effects)
        ? _popup_filter_options(array($default) + array_combine($effects, array_map('_popup_key_to_title', $effects)))
        : FALSE
    ),
    'node_title' => drupal_render($node_title_form),
    'menu_options' => _popup_filter_options(menu_get_menus()),
  );

  extract($variables, EXTR_SKIP);
  ob_start();
  include('popup_filter_form.php');
  $form_html = ob_get_contents();
  ob_end_clean();

  return $form_html;
}



/* ---- Options ---- */



function _popup_filter_position_options($default){
  return array(
    0 => $default,
    'top-left' => 'Top left',
    'top-right' => 'Top right',
    'bottom-left' => 'Bottom left',
    'bottom-right' => 'Bottom right',
  );
}



function _popup_filter_activate_options($default){
  return array(
    $default,
    'hover' => t('Hover'),
    'click' => t('Click'),
  );
}



function _popup_filter_views_options(){

  if (module_exists('views')){

    $views = views_get_all_views();
    $views_options = array();
    foreach($views as $view){
      $views_options[$view->name] = $view->name;
    }
    return $views_options;

  }

  return FALSE;
}



function _popup_filter_format_options(){

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.admin');
  $formats = array_keys(_popup_ui_formatter_settings());
  $display_format_options = array_combine($formats, $formats);
  array_unshift($display_format_options, 'None');

  return $display_format_options;
}



function _popup_filter_type_options(){

  return array(
    'block' => t('Block'),
    'form' => t('Form'),
    'menu' => t('Menu'),
    'node' => t('Node'),
    'php' => t('PHP'),
    'text' => t('Text'),
    'view' => t('View'),
  );

}



function _popup_filter_options($options){
  $rendered = '';

  foreach($options as $value => $label){
    $rendered .= '<option value="' . $value . '">' . $label . '</option>';
  }

  return $rendered;
}



/* ---- Text ---- */



function _popup_filter_text(){
  return array(
    'title' => t('Title'),
    'image' => t('Image'),
    'image description' => t('Path to an image to use as the popup title. This path must be relative to the drupal root.'),
    'link' => t('Link'),
    'css id' => t('CSS ID'),
    'css class' => t('CSS class'),
    'format' => t('Format'),
    'format description' => t('Select the default display format of the popup. The options below will override this formats\' settings. Popup formats may be managed !here.', array('!here' => l(t('here'), 'admin/config/user-interface/popup/formats'))),
    'origin' => t('Origin'),
    'expand' => t('Expand'),
    'effect' => t('Effect'),
    'width' => t('Width'),
    'activate' => t('Activate'),
    'close button' => t('Close button'),
    'ajax' => t('Use AJAX to load content on demand'),
    'type' => t('Type'),
    'module' => t('Module'),
    'delta' => t('Delta'),
    'form' => t('Form function'),
    'form description' => t('The PHP function that generates the form. This is usually the same as the form ID.'),
    'menu' => t('Menu'),
    'flat' => t('Flat'),
    'flat description' => t('Select this option if you want the top level menu items to show rather than the menu root.'),
    'inline' => t('Inline'),
    'inline description' => t('Select this option if you want the top level menu items to be displayed next to each other.'),
    'node id' => t('Node ID'),
    'or' => t('OR'),
    'teaser' => t('Display teaser'),
    'page' => t('Use the page display'),
    'default' => t('Default'),
    'links' => t('Show links'),
    'panel' => t('Use panel display'),
    'php' => t('PHP'),
    'php description' => t('PHP that returns text to popup eg.<br />return my_text_function();'),
    'text' => t('Text'),
    'view' => t('View'),
    'display' => t('Display'),
    'arguments' => t('Arguments'),
    'argument description' => t('Comma seperated list of arguments to pass to the view, eg.<br />1, 3'),
    'views disabled' => t('To embed views, the views module must be enabled on the') . ' ' . l(t('Modules administration page'), 'admin/build/modules'),
    'filter reminder' => t('Please ensure that the input format below is set to "Popup tags", or that the selected input format includes a popup tags filter.'),
    'insert' => t('Insert'),
  );
}



/* ---- Callbacks ---- */



function popup_filter_ajax_getnode($part){

  // Not sure why, but replacement of args don't work if they're in single quotes
  $result = db_query("SELECT title, nid FROM {node} where title like('%" . check_plain($part) . "%');");
  $nodes = array();

  foreach($result as $row){
    $nodes[$row->title . ' [' . $row->nid . ']'] = check_plain($row->title);
  }

  drupal_json_output(
    $nodes
  );

}



function popup_filter_ajax_getdeltas($module){

  $options = '';
  $blocks = module_invoke($module, 'block_info');
  if (is_array($blocks)){
    foreach($blocks as $delta=>$data){
      $options .= '<option value="' . $delta . '">' . $data['info'] . '</option>';
    }
  }

  print $options;

  exit;
}



function popup_filter_ajax_getdisplays($view_name){

  if (module_exists('views')){
    $view = views_get_view($view_name);
    if (is_array($view->display)){
      foreach($view->display as $id=>$display){
        $options .= '<option value="' . $id . '">' . $display->display_title . '</option>';
      }
    }
  }

  print $options;

  exit;
}


