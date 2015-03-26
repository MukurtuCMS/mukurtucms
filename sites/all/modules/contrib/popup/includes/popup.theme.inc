<?php



/* ---- hook_theme helper ---- */



/**
 *  generate a theme array for a specific style
 */
function _popup_theme_array($style = FALSE, $path = FALSE){

  $suffix = $style ? '-' . $style : '';
  $theme = array(

    'popup-element' . $suffix => array(
      'arguments' => array(
        'title' => '',
        'body' => '',
        'css_id' => '',
        'class' => '',
        'style' => '',
      ),
      'template' => 'popup-element',
      'preprocess functions' => array(
        'popup_preprocess_popup_element',
      ),
    ),

    'popup-element-body' . $suffix => array(
      'arguments' => array(
        'body' => '',
        'class' => '',
        'close' => '',
      ),
      'template' => 'popup-element-body',
    ),

    'popup-element-title' . $suffix => array(
      'arguments' => array(
        'title' => '',
        'class' => '',
        'href' => '',
      ),
      'template' => 'popup-element-title',
    ),

  );

  if ($path){
    foreach($theme as &$element){
      $element['path'] = $path;
    }
  }

  return $theme;
}



/* ---- Theme implementation ---- */



function theme_popup_ahah_placeholder($variables){

  $hash = popup_cache_attributes($variables['attributes']);
  $type = $variables['type'];
  $extra = isset($variables['attributes']['ajax_extra'])
    ? '/' . $variables['attributes']['ajax_extra']
    : '';

  $url = (
    variable_get('clean_url')
      ? '/ahah/popup/'
      : '?q=/ahah/popup/'
    ) . $type . '/' . $hash . $extra;

  return
    '<div class="popup-ahah-placeholder">' .
      t('Loading') .
      '<a class="ahah-path" href="' . $url . '"></a>' .
    '</div><noscript><p class="error">' . t('Please enable Javascript to be able to view this content.') . '</p></noscript>';
}


