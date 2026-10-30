<?php



/* ---- API ---- */



/**
 * Renders a popup element using specified attributes. This method should be
 * used to create popups programmatically.
 *
 * @param array $attributes
 *
 *
 * Attributes is a keyed array where the key is the attribute name. Acceptible
 * content related attributes are:
 *
 * text   - Actual text to display within the popup body.
 *
 * node   - Nid of the node to be displayed within the popup body. Additional
 *          options for the node display are:
 *
 *            teaser-display - set to TRUE the node will be rendered as a
 *                             teaser.
 *
 * form   - form id of the form to be displayed within the popup block.
 *
 *            args    - a comma separated list of arguments to be passed to the
 *                      form.
 *
 * block  - Id of the block to be popped up OR a value of TRUE, indicating that
 *          a block provided by a module should be displayed. In the latter
 *          case, the following attributes should also be provided:
 *
 *            module - the name of the module that provides the block.
 *            delta  - the delta of the module block.
 *
 * menu   - Machine name of the menu to be popped up. Note that the menu module
 *          prefixes some menu ids with "menu-". Additional attributes for menus
 *          are:
 *
 *            flat   - set to TRUE exposes the top level children of the menu,
 *                     while its root is not rendered.
 *            inline - causes the top level children to be displayed next to
 *                     eachother, rather than below.
 *
 * view   - Machine name of the view to be popped up. The following attributes
 *          may be provided for views:
 *
 *            display - the menu display to be rendered. Defaults to the Default
 *                      display.
 *            args    - a comma separated list of arguments to be passed to the
 *                      view.
 *
 * php    - A string of php that returns rendered text to be displayed within
 *          the popup body.
 *
 * image  - A path relative to the drupal root to an image to be used as the
 *          popup title.
 *
 * title  - The title that should be used for the popup. This will override any
 *          of the automatically generated titles provided by each of the above
 *          popup types. If an image is provided, this will be used as the alt
 *          attribute.
 *
 * link   - The URL to assign to the anchor of the popup. Note that this
 *          attribute will have no effect if activate is set to click, and
 *          Javascript is enabled within the client browser. It is still
 *          recommended to provide one to degrade semi-gracefully.
 *
 *
 * Display related attributes:
 *
 * id     - The CSS id, prefixed with "popup-element-id-", that will be assigned
 *          to the wrapper of the entire popup element. Note that the body will
 *          be wrapped within an element with "-active" appended to the id, and
 *          class "popup-element-wrapper", before being appended to the
 *          "popup-active-overlay" at the end of the HTML body.
 *
 * class  - The CSS class, prefixed with "class-" that will be
 *          assigned to the wrapper of the entire popup element, as well as the
 *          wrapper of the body. See above.
 *
 * origin - The corner of the title that the popup will originate at. Acceptable
 *          values:
 *
 *          top-left, top-right, bottom-left and bottom-right
 *
 * expand - The direction in which the popup should expand. Acceptible values:
 *
 *          top-left, top-right, bottom-left and bottom-right
 *
 * effect - The name of the showing/hiding animation effect to use. Modules may
 *          provide their own effects by implementing hook_popup_effects.
 *          The popup suite provides these effects:
 *
 *            default         - show or hide the popup with no animation.
 *            fade            - fades the popup in or out.
 *            slide-down      - slides the popup up/down.
 *            slide-down-fade - a combination of both of the above.
 *
 * style  - The visual style to be used to display this popup item.
 *
 * format - Predefined popup format as managed by the popup_ui module.
 *
 * width  - Displayed width of the popup body inner in pixels.
 *
 *
 * Behaviour related attributes:
 *
 * activate     - How the popup should be activated. Accepted values:
 *
 *                  click - users must click on the popup title to reveal the
 *                          body.
 *                  hover - (Default) users activate popups by hovering over the
 *                          popup title.
 *
 * ajax         - Causes the body of the popup to be retrieved with an AJAX call
 *                only when the body is to be shown to the user.
 *                This attribute applies to nodes, blocks, forms, views and php
 *                only.
 *
 * ajax_extra   - a string tag that will be appended as a last argument of the
 *                ajax request url.
 *
 * close        - Provides a close button within the popup body. Only applies to
 *                click activated popups.
 *
 * empty-body	  - How an empty body should be handled. Accepted values:
 *
 *									all 	- show the popup with an empty body.
 *									title - just show the popup title, default.
 * 									none	- show nothing.
 *
 */
function popup($attributes){

  module_load_include('inc', 'popup', 'includes/popup.util');

  drupal_alter('popup_attributes', $attributes);
  $attributes['altered'] = TRUE;

  $type = @array_shift(
    array_intersect(
      array('text', 'node', 'block', 'form', 'php', 'menu', 'view'),
      array_keys($attributes)
    )
  );

  $function = '_popup_' . $type;

	$keys = array_keys($attributes);
	$intersect = array_intersect(
		array('node', 'block', 'form', 'view', 'php'),
		$keys
	);
  $ajax_type = @array_shift($intersect);

  // If AJAX is to be used to populate the body, don't generate it now
  if (isset($attributes['ajax']) && $attributes['ajax'] && $ajax_type && function_exists($function)){
    return popup_element(
      $function($attributes, 'title'),
      'none',
      $attributes
    );
  }

  if (function_exists($function)){
    return $function($attributes);
  }

}



/**
 * Renders a popup elements' HTML
 *
 * @param string $title
 * @param string $body
 * @param array $attributes
 *
 * This method should be used to create popups programmatically where the title
 * and body of the popup element is known. It will automatically assign classes
 * and default behaviors. Any additional information should be passed in
 * attributes, eg. array('activate' => 'click')
 *
 */
function popup_element($title, $body, $attributes = array()){

  module_load_include('inc', 'popup', 'includes/popup.util');

  if (!isset($attributes['altered'])){
    drupal_alter('popup_attributes', $attributes);
  }

	$style = $attributes['style']
    ? $attributes['style']
    : variable_get('popup-style', 'White');
  $attributes['style-class'] = _popup_title_to_key($style);
  $style_suffix = $style
      ? '-' . $attributes['style-class']
      : '';

  $id = _popup_id($attributes['id']);
  $classes = _popup_classes($attributes);
  $close = ($attributes['close'] && ($attributes['activate'] == 'click'))
    ? '<a class="popup-close popup-close-button"><span>[X]</span></a>'
    : '';

  $href = isset($attributes['link']) ? 'href="' . url($attributes['link']) . '"' : '';

	$keys = array_keys($attributes);
	$intersect = array_intersect(
		array('node', 'block', 'form', 'view', 'php'),
		$keys
	);
  $ajax_type = @array_shift($intersect);

  $popup_title = theme(
    'popup-element-title' . $style_suffix,
    array(
      'title' => _popup_title($title, $attributes['image']),
      'class' => $classes['title'],
      'href' => $href,
    )
  );

  if ($attributes['ajax'] && $ajax_type){
    $body = theme(
      'popup_ahah_placeholder',
      array(
        'type' => $ajax_type,
        'attributes' => $attributes,
      )
    );
  } else {
    unset($attributes['ajax']);
  }

  $popup_body = (strlen(trim($body)) || $attributes['empty-body'] == 'all')
    ? theme(
        'popup-element-body' . $style_suffix,
        array(
          'body' => $body,
          'class' => $classes['body'],
          'close' => $close,
        )
      )
    : '';

  return (trim($body) || $attributes['empty-body'] != 'none')
  	? theme(
				'popup-element' . $style_suffix,
				array(
          'title' => $popup_title,
          'body' => $popup_body,
          'css_id' => $id,
          'class' => $classes['element'],
          'style' => $style,
        )
	  	)
	  : '';
}




/* ---- Content generators ---- */



function _popup_text($attributes, $return = FALSE){

  $title = $attributes['title'] ? $attributes['title'] : 'Text';
  if ($return == 'title'){
    return $title;
  }

  $body = $attributes['text'];
  if ($return == 'body'){
    return $body;
  }

  return
    popup_element(
      $title,
      $body,
      $attributes
    );

}



function _popup_node($attributes, $return = FALSE){

  $node = node_load($attributes['node']);

  if ($node) {

	  $title = isset($attributes['title']) && $attributes['title'] ? $attributes['title'] : $node->title;
	  if ($return == 'title'){
	    return $title;
	  }

		$mode = isset($attributes['teaser']) && $attributes['teaser'] ? 'teaser' : 'full';

		$node_view = node_view(
			$node,
			$mode
		);
    $body = drupal_render($node_view);

	  if ($return == 'body'){
	    return $body;
	  }

	  return
	    popup_element(
	      $title,
	      $body,
	      $attributes
	    );
	}

}



function _popup_block($attributes, $return = FALSE){

  $module = isset($attributes['module']) ? $attributes['module'] : 'block';
  $delta = isset($attributes['delta']) ? $attributes['delta'] : $attributes['block'];

  $block = module_invoke(
    $module,
    'block_info'
  );
	$title = $attributes['title'] ?  $attributes['title'] : $block[$delta]['info'];

  $block = module_invoke(
    $module,
    'block_view',
    $delta
  );

  $body =
    '<div class="block">' .
      (is_array($block['content']) ? drupal_render($block['content']) : $block['content']) .
    '</div>';

  if ($return == 'title'){
    return $title;
  }

  if ($return == 'body'){
    return $body;
  }

  return
    popup_element(
      $title,
      $body,
      $attributes
    );

}



function _popup_form($attributes, $return = FALSE){

  $title = $attributes['title'] ?  $attributes['title'] : 'form';
  if ($return == 'title'){
    return $title;
  }

  // Initialize args attribute.
  $attributes += array('args' => array());

  // Add form_id at the beginning of the args array.
  array_unshift($attributes['args'], $attributes['form']);

  // Render form.
  $form = call_user_func_array('drupal_get_form', $attributes['args']);
  $body = drupal_render($form);

  if ($attributes['ajax']){
    $body = '<div class="ajax-form-wrapper">' . $body . '</div>';
  }

  if ($return == 'body'){
    return $body;
  }

  return
    popup_element(
      $title,
      $body,
      $attributes
    );

}



function _popup_view($attributes, $return = FALSE){

  $title = FALSE;
  $body = FALSE;

  if (module_exists('views')){

    $view = views_get_view($attributes['view']);

    $display = $attributes['display'] ? $attributes['display'] : 'default';
    $args = isset($attributes['args'])
      ? explode(',', $attributes['args'])
      : array();

    if ($view){
      $view->set_arguments($args);
      $view->set_display($display);
      $body = $view->preview();

      $computed_title = $view->get_title();
      $title = $attributes['title']
        ? $attributes['title']
        : ($computed_title
            ? $computed_title
            : @$view->display[$display]->display_options['title']
          );

    }

  } else {
    $body = false;
  }

  $title = $title ? $title : 'View';
  if ($return == 'title'){
    return $title;
  }

  if ($return == 'body'){
    return $body;
  }

  return
    popup_element(
      $title,
      $body,
      $attributes
    );

}



function _popup_php($attributes, $return = FALSE){

  $title = $attributes['title'] ? $attributes['title'] : 'PHP';
  if ($return == 'title'){
    return $title;
  }
  $body = eval($attributes['php']);
  if ($return == 'body'){
    return $body;
  }

  return
    popup_element(
      $title,
      $body,
      $attributes
    );

}



function _popup_menu($attributes){

  module_load_include('inc', 'popup', 'includes/popup.util');

  if (!isset($attributes['empty-body'])) {
    $attributes['empty-body'] = 'none';
  }

	$tree = menu_build_tree($attributes['menu']);
  $menu = array_pop($tree);

  $children = menu_tree_all_data($attributes['menu']);

  $menu['below'] = $children ? array_filter(
      menu_tree_all_data(
        $attributes['menu']),
        '_popup_menu_visible'
      )
    : FALSE;
  $menu['link']['has_children'] = isset($children);

  $menu['link']['title'] = isset($attributes['title']) && strlen($attributes['title'])
    ? $attributes['title']
    : (isset($menu['title']) ? $menu['title'] : 'Menu');

  return _popup_menuelement($menu, $attributes);

}


