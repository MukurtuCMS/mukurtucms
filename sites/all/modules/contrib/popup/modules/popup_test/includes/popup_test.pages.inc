<?php



/**
 * Popup test position page
 */
function popup_test_position(){

  module_load_include('inc', 'popup', 'includes/popup.api');

  $rendered = '';

  $corner = array(
    'top left' => 'top-left',
    'top right' => 'top-right',
    'bottom left' => 'bottom-left',
    'bottom right' => 'bottom-right',
  );

  foreach ($corner as $origin_label => $origin_setting){
    foreach($corner as $expand_label => $expand_setting){
      $rendered .=
        'This is the <strong>' . $origin_label . '</strong> origin test: ' .
        popup_element('popup title', 'Expanding to the ' . $expand_label, array('origin' => $origin_setting, 'expand' => $expand_setting)) .
        ' and some suffix text.<br />';
      ;
    }
  }

  return $rendered;

}



/**
 * Popup test effects page
 */
function popup_test_effects(){

  module_load_include('inc', 'popup', 'includes/popup.api');

  $rendered = '';

  $effects = module_invoke_all('popup_effects');

  foreach($effects['show'] as $name=>$effect){
    $rendered .= popup_element('Effect: ' . $name, 'Test popup text', array('effect' => $name, 'id' => 'class-effect-'.$name, 'class' => 'class-effect-'.$name));
  }

  return $rendered;

}



/**
 * Popup test nesting page
 */
function popup_test_nesting(){

  module_load_include('inc', 'popup', 'includes/popup.api');

  $rendered = '';

  foreach(array('top-right', 'bottom-right') as $expand){
    $popup = 'LAST!';
    for($i = 5; $i>0; $i--){
      $popup = popup_element('Level ' . $i, $popup, array('expand' => $expand));
    }
    $rendered .= $popup;
  }

  return $rendered;

}



/**
 * Popup test activation page
 */
function popup_test_activation(){

  module_load_include('inc', 'popup', 'includes/popup.api');

  $rendered =
    popup_element('Hover', 'This is a popup that activates on hover', array('activate' => 'hover')) .
    popup_element('Click', 'This is a popup that must be clicked to activate', array('activate' => 'click')) .
    popup_element('Click and Close', 'This is a popup that must be clicked to activate, and can be closed with a button', array('activate' => 'click', 'close' => TRUE));

  return $rendered;

}



/**
 * Popup test activation page
 */
function popup_test_styles(){

  module_load_include('inc', 'popup', 'includes/popup.util');
  module_load_include('inc', 'popup', 'includes/popup.api');

  $styles = _popup_styles();
  $rendered = '';

  foreach($styles as $style=>$path){
    $rendered .= popup_element($style, 'This is a test of the ' . $style . ' popup style', array('style' => $style, 'activate' => 'hover'));
  }

  return $rendered;

}



/**
 * Popup test content page
 */
function popup_test_content(){

  module_load_include('inc', 'popup', 'includes/popup.api');
  $firstnode = db_query("SELECT nid FROM {node} LIMIT 1")->fetchField();
  $firstblock = db_query("SELECT bid FROM {block_custom} LIMIT 1")->fetchField();

  $content = array(

    'Text: Some text ' . popup(array('text' => 'This is popup text', 'activate' => 'click')) . ' and some more text.',

    $firstnode > 0
      ? 'Node: Some text ' . popup(array('node' => $firstnode, 'activate' => 'click', 'width' => 450)) . ' and some more text.'
      : '[No nodes have been loaded, skipping node test]',

    'Module block: Some text ' . popup(array('block' => TRUE, 'module' => 'user', 'delta' => 'online', 'activate' => 'click')) . ' and some more text.',

    $firstblock > 0
      ? 'Custom block: Some text ' . popup(array('block' => 1, 'activate' => 'click')) . ' and some more text.'
      : '[No custom blocks loaded, skipping custom block test]',

    module_exists('search')
      ? 'Form: Some text ' . popup(array('form' => 'search_form', 'activate' => 'click', 'width' => 350)) . ' and some more text.'
      : '[Search module not enabled, skipping form test.]',

    module_exists('views')
      ? 'View: Some text ' . popup(array('view' => 'frontpage', 'activate' => 'click', 'width' => 500)) . ' and some more text.'
      : '[Views module not enabled, skipping view test.]',

    'PHP: Some text ' . popup(array('php' => 'return "Some php generated text: ' . date('d-M-Y', time()) . ' ";', 'activate' => 'click')) . ' and some more text.',

    'Menu: Some text ' . popup(array('menu' => 'management', 'origin' => 'top-right',  'expand' => 'bottom-right')) . ' and some more text.',

  );

  return implode('<br />', $content);
}



/**
 * Popup test AJAX content page
 */
function popup_test_ajax(){

  module_load_include('inc', 'popup', 'includes/popup.api');

  $firstnode = db_query("SELECT nid FROM {node} LIMIT 1")->fetchField();
  $firstblock = db_query("SELECT bid FROM {block_custom} LIMIT 1")->fetchField();

  $content = array(

    $firstnode > 0
      ? 'Node: Some text ' . popup(array('node' => $firstnode, 'activate' => 'click', 'ajax' => 1, 'width' => 450)) . ' and some more text.'
      : '[No nodes have been loaded, skipping node test]',

    'Module block: Some text ' . popup(array('block' => TRUE, 'module' => 'user', 'delta' => 'online', 'activate' => 'click', 'ajax' => 1)) . ' and some more text.',

    $firstblock > 0
      ? 'Custom block: Some text ' . popup(array('block' => 1, 'activate' => 'click', 'ajax' => 1)) . ' and some more text.'
      : '[No custom blocks loaded, skipping custom block test]',

    module_exists('search')
      ? 'Form: Some text ' . popup(array('form' => 'search_form', 'activate' => 'click', 'ajax' => 1, 'width' => 350)) . ' and some more text.'
      : '[Search module not enabled, skipping form test.]',

    module_exists('views')
      ? 'View: Some text ' . popup(array('view' => 'frontpage', 'activate' => 'click', 'ajax' => 1, 'width' => 500)) . ' and some more text.'
      : '[Views module not enabled, skipping view test.]',

    'PHP: Some text ' . popup(array('php' => 'return "Some php generated text: ' . date('d-M-Y', time()) . ' ";', 'activate' => 'click', 'ajax' => 1)) . ' and some more text.',

  );

  return implode('<br />', $content);
}
