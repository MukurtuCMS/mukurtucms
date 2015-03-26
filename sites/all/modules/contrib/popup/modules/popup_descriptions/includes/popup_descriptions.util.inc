<?php



/* ---- Rendering of descriptions and popups ---- */



/**
 *  Applies popup behaviour to the description of a form element
 */
function _popup_descriptions_apply_popup_description(&$element){

  if (_popup_descriptions_enabled($element)){

    $position = variable_get('description-popup-position');

    $element_title = isset($element['#title']) && trim($element['#title']) != ''
      ? $element['#title']
      : variable_get('description-popup-title', '?');

    $title = $position == 'label'
      ? $element_title
      : variable_get('description-popup-title', '?');

    $popup = popup_element(
      $title,
      $element['#description'],
      array(
        'format' => variable_get('description-popup-format'),
        'element-class' => 'popup-description',
        'empty-title',
      )
    );

    switch(variable_get('description-popup-position', 0)){

      case 'label':
        $element['#title'] = $popup;
        unset($element['#description']);
      break;

      case 'prefix':
        isset($element['#field_prefix'])
          ? $element['#field_prefix'] .= $popup
          : $element['#field_prefix'] = $popup;
        unset($element['#description']);
      break;

      case 'suffix':
        isset($element['#field_suffix'])
          ? $element['#field_suffix'] .= $popup
          : $element['#field_suffix'] = $popup;
        unset($element['#description']);
      break;

      default:
        $element['#description'] = $popup;
      break;

    }
  }
}



/**
 * Adds description popup admin links to the form element
 */
function _popup_descriptions_apply_popup_admin(&$element){

  $access = user_access('administer popup elements');
  $admin_links = variable_get('description-popup-admin', FALSE);

  if ($access && $admin_links){

    $popup = '';
    $link = array();

    $link[] = _popup_descriptions_enabled_id($element)
      ? l(
          'Display this description inline',
          'admin/config/user-interface/popup/descriptions/rule/remove/id/' .
          $element['#id'],
          array(
            'query' => array(
              'destination' => $_GET['q'],
            ),
          )
        )
      : l(
          'Display this description as a popup',
          'admin/config/user-interface/popup/descriptions/rule/add/id/' .
          $element['#id'],
          array(
            'query' => array(
              'destination' => $_GET['q'],
            ),
          )
        );

    $link[] = _popup_descriptions_enabled_path()
      ? l(
          'Do not display all descriptions on this page as popups',
          'admin/config/user-interface/popup/descriptions/rule/remove/page',
          array(
            'query' => array(
              'destination' => $_GET['q'],
            ),
          )
        )
      : l(
          'Display all descriptions on this page as popups',
          'admin/config/user-interface/popup/descriptions/rule/add/page',
          array(
            'query' => array(
              'destination' => $_GET['q'],
            ),
          )
        );

    $popup =
      popup_element(
        t('Configure description popup behaviour'),
        '<ul><li>' . implode('</li><li>', $link) . '</ul>',
        array(
          'activate' => 'hover',
          'element-class' => 'popup-description popup-description-admin',
	        'origin' => 'bottom-right',
	        'expand' => 'bottom-left',
	        'width' => 400,
        )
      );

    $element['#description'] = isset($element['#description'])
      ? $element['#description'] . $popup
      : $popup;

  }
}



/* ---- Popup description status testers ---- */



/**
 *  Tests whether an element's description should pop up
 */
function _popup_descriptions_enabled($element){

  $mode = variable_get('description-popup-mode', 'specific');

  switch($mode){

    case 'specific':
      return
        _popup_descriptions_enabled_id($element) ||
        _popup_descriptions_enabled_path();

    case 'all':
      return TRUE;

  }

  return FALSE;
}



/**
 *  Tests whether an element's description should pop up based on its id
 */
function _popup_descriptions_enabled_id($element){

  if (!variable_get('description-popup-id')){
    return FALSE;
  }

  static $ids = FALSE;
  if (!$ids) {
    $ids = preg_split('/[\n\r]+/', variable_get('description-popup-ids'));
  }

  return in_array($element['#id'], $ids);
}



/**
 *  Tests whether an element's description should pop up based on its path
 */
function _popup_descriptions_enabled_path($path = FALSE){

  if (!variable_get('description-popup-path')){
    return FALSE;
  }

  $path = $path ? $path : $_GET['q'];

  static $paths = FALSE;
  if (!$paths) {
    $paths = preg_split('/[\n\r]+/', variable_get('description-popup-paths'));
  }

  return in_array($path, $paths);
}


