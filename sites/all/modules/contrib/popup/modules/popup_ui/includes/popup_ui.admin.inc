<?php



/* ---- Forms ---- */



function popup_ui_form_formatters($form, &$form_state){

  drupal_add_css(drupal_get_path('module', 'popup_ui').'/style/popup-ui.css');
  drupal_add_css(drupal_get_path('module', 'popup_ui').'/style/popup-ui.css');

	$options = _popup_ui_form_options();
  $formatters = _popup_ui_formatter_settings();

  $form = array(
	  'popup_formats' => array('#type' => 'vertical_tabs'),
    '#tree' => TRUE,
    'format_forms' => array(),
  );

  foreach ($formatters as $label => $formatter){
    $form['format_forms'][$label] = _popup_ui_form_formatters_form(
      $label,
      $formatter,
      $options
    );
  }

  $form['format_forms']['new'] = _popup_ui_form_formatters_form(
    'new',
    array(
      'origin' => 'bottom-left',
      'expand' => 'bottom-right',
      'effect' => 'none',
      'style' => 0,
      'activate' => 'hover',
    ),
    $options
  );

  $form['buttons'] = _popup_ui_form_buttons();

  return $form;
}



function _popup_ui_form_options(){

  module_load_include('inc', 'popup', 'includes/popup.util');

	$effects = _popup_effects();
	$pop = array_pop($effects);
	$effect_names = array_keys($pop);
  $effect_options = array_combine(
    $effect_names,
    array_map('_popup_key_to_title', $effect_names)
  );

  $style_names = array_keys(_popup_styles());
  $style_options = array_combine(
    $style_names,
    array_map('_popup_key_to_title', $style_names)
  );
  array_unshift($style_options, t('Default'));

  $widths = range(100, 500, 50);

  return array(
    'position' => array('top-left' => t('Top left'), 'top-right' => t('Top right'), 'bottom-right' => t('Bottom right'), 'bottom-left' => t('Bottom left'),),
    'effect' => $effect_options,
    'style' => $style_options,
    'opacity' => array('1.0' => '1.0', '0.9' => 0.9, '0.8' => 0.8, '0.7' => 0.7, '0.6' => 0.6, '0.5' => 0.5, '0.4' => 0.4, '0.3' => 0.3, '0.2' => 0.2, '0.1' => 0.1,),
    'width' => array_combine($widths, $widths),
  );

}



function _popup_ui_form_buttons(){

	return array(

    array('#markup' => '<div class="form-item form-buttons">'),

    'submit' => array(
      '#type'=>'submit',
      '#value'=>t('Save formats'),
    ),

    array(
    	'#markup' => popup_ui_confirm(
    		'Reset to defaults',
    		'Are you sure you want to reset to defaults?<br /> This action cannot be undone!',
    		'admin/config/user-interface/popup/formats/reset',
				array(
					'origin' => 'top-left',
					'expand' => 'top-right',
				)
    	)
    ),

    array(
    	'#markup' => popup_ui_confirm(
    		'Delete all',
    		'Are you sure you want to delete all the formats?<br /> This action cannot be undone!',
    		'admin/config/user-interface/popup/formats/whipe',
				array(
					'origin' => 'top-left',
					'expand' => 'top-right',
				)
    	)
    ),

    array('#markup' => '</div>'),

    '#weight' => 20,
  );

}



function _popup_ui_form_formatters_form($key, $values, $options){

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.api');
  module_load_include('inc', 'popup', 'includes/popup.util');

  static $weight = 0;

  $values += _popup_defaults();

  $form = $key == 'new'
  	? array(
  			'fieldset' => array(
		      '#group' => 'popup_formats',
  				'#title' => 'Add a new new format',
  				'#type' => 'fieldset',
  				'#weight' => -1,
  			),
  		)
  	: array(
  			'fieldset' => array(
		      '#group' => 'popup_formats',
  				'#title' => $values['label'],
  				'#type' => 'fieldset',
  				'#weight' => $weight ++,
  			),
  		);


  $form['fieldset']['fields'] = array(

    'ops' => array(
      '#markup' => (
        $key == 'new'
          ? '&nbsp;'
          : popup_ui_confirm(
          		'Delete',
          		'Are you sure you want to delete this popup format? It cannot be undone!',
          		'admin/config/user-interface/popup/formats/delete/'.$key,
          		array(
								'origin' => 'bottom-right',
								'expand' => 'bottom-left',
          		)
          	)
      ),
    ),

    'label' => array(
      '#default_value' => $values['label'],
      '#size' => 20,
      '#title' => 'Administrative label',
      '#type' => 'textfield',
      '#description' => 'To be used on administrative pages. End users will not see this label.',
    ),


  	array(
  		'#markup' => '<div class="column meta-column">',
  	),


  	array(
  		'#markup' => '<div class="section section-display"><div class="section-inner"><h4>' . t('Display') . '</h4>',
  	),

    'origin' => array(
      '#default_value' => isset($values['origin']) ? $values['origin'] : FALSE,
      '#title' => 'Origin',
      '#type' => 'select',
      '#options' => $options['position'],
      '#description' => 'Corner from where the popup should originate.',
    ),

    'expand' => array(
      '#default_value' => $values['expand'],
      '#title' => 'Expand',
      '#type' => 'select',
      '#options' => $options['position'],
      '#description' => 'Direction in which the popup should expand.',
    ),

    'effect' => array(
      '#default_value' => $values['effect'],
      '#title' => 'Effect',
      '#type' => 'select',
      '#options' => $options['effect'],
      '#description' => 'Effect used to display the popup.',
    ),

    'style' => array(
      '#default_value' => $values['style'],
      '#title' => 'Style',
      '#type' => 'select',
      '#options' => $options['style'],
      '#description' => 'Visual style with which to display the popup.',
    ),

    'opacity' => array(
      '#default_value' => $values['opacity'],
      '#title' => 'Opacity',
      '#type' => 'select',
      '#options' => $options['opacity'],
    ),

    'width' => array(
      '#default_value' => $values['width'],
      '#title' => 'Width',
      '#type' => 'select',
      '#options' => $options['width'],
    ),

  	array(
  		'#markup' => '</div></div><div class="section section-behavior"><div class="section-inner"><h4>' . t('Behavior') . '</h4>',
  	),

    'activate' => array(
      '#default_value' => $values['activate'],
      '#title' => 'Activation',
      '#type' => 'select',
      '#options' => array('hover' => t('Hover'), 'click' => t('Click')),
    ),

    'close' => array(
      '#default_value' => $values['close'],
      '#title' => 'Display a close button',
      '#type' => 'checkbox',
    ),

    'ajax' => array(
      '#default_value' => $values['ajax'],
      '#title' => 'Use AJAX to retrieve popup content',
      '#type' => 'checkbox',
    ),

  	array(
  		'#markup' => '</div></div></div><div class="column content-column">',
  	),

  	array(
  		'#markup' => '<div class="section section-node"><div class="section-inner"><h4>' . t('Nodes') . '</h4>',
  	),

    'teaser' => array(
      '#default_value' => $values['teaser'],
      '#title' => 'Display nodes as teasers',
      '#type' => 'checkbox',
    ),

  	array(
  		'#markup' => '</div></div><div class="section section-menu"><div class="section-inner"><h4>' . t('Menus') . '</h4>',
  	),

    'inline' => array(
      '#default_value' => $values['inline'],
      '#title' => 'Render the popup menu element inline within the box model',
      '#type' => 'checkbox',
    ),

    'flat' => array(
      '#default_value' => $values['flat'],
      '#title' => 'Render the top level menu items as a list of popups',
      '#type' => 'checkbox',
    ),

  	array(
  		'#markup' => '<h4>' . t('Submenus') . '</h4>',
  	),

    'submenu-origin' => array(
      '#default_value' => $values['submenu-origin'],
      '#title' => 'Origin',
      '#type' => 'select',
      '#options' => $options['position'],
    ),

    'submenu-expand' => array(
      '#default_value' => $values['submenu-expand'],
      '#title' => 'Expand',
      '#type' => 'select',
      '#options' => $options['position'],
    ),

  	array(
  		'#markup' => '</div></div></div>',
  	),

  );

  return $form;
}



function popup_ui_form_formatters_validate(&$form, &$form_state){

  $values = $form_state['values'];
  $formatters = _popup_ui_formatter_settings();

  unset($values['popup_formats']['popup_formats__active_tab']);

  foreach($values['format_forms'] as $label=>$fieldset){

  	$row = $fieldset['fieldset']['fields'];

    if (!preg_match('/^[A-Za-z0-9\ ]*$/', $row['label'])){
      form_set_error('popup_formats]['.$label.'][label', t('Labels may only contain letters, numbers and spaces.'));
    }

    if (!$row['label'] && $label!='new'){
      form_set_error('popup_formats]['.$label.'][label', t('Please provide a label.'));
    }

  }
}


function popup_ui_form_formatters_submit(&$form, &$form_state){

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.util');

  $values = $form_state['values'];
  $formatters = array();

  foreach($form_state['values']['format_forms'] as $label=>$fieldset){

  	$row = $fieldset['fieldset']['fields'];

    if ($row['label']){
      $formatters[$row['label']] = $row;
    }
  }

  _popup_ui_formatter_settings($formatters);
  _popup_ui_flush_all();

  drupal_set_message(t('The popup filters have been saved.'));

  $form['#redirect'] = array('admin/config/user-interface/popup/formats');
}



/* ---- Actions ---- */



function popup_ui_delete_format($format){

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.util');

  $settings = _popup_ui_formatter_settings();

  unset($settings[$format]);

  _popup_ui_formatter_settings($settings);
  _popup_ui_flush_all();

  drupal_set_message(t('The "%format" filter format has been deleted.', array('%format' => $format)));
  drupal_goto('admin/config/user-interface/popup/formats');
}



function popup_ui_whipe_formats(){

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.util');

  _popup_ui_formatter_settings(array());
  _popup_ui_flush_all();

  drupal_set_message(t('All filter formats have been deleted.'));
  drupal_goto('admin/config/user-interface/popup/formats');
}



function popup_ui_reset(){

  module_load_include('inc', 'popup_ui', 'includes/popup_ui.util');

  _popup_ui_formatter_settings(_popup_ui_formatter_defaults());
  _popup_ui_flush_all();

  drupal_set_message(t('Default settings have been restored.'));
  drupal_goto('admin/config/user-interface/popup/formats');
}



/* ---- Settings ---- */



function _popup_ui_formatter_defaults(){

  return array (

    'Default hover' => array (
      'label' => 'Default hover',
      'origin' => 'bottom-left',
      'expand' => 'bottom-right',
      'effect' => 'default',
      'opacity' => '1.0',
      'width' => '150',
      'activate' => 'hover',
    ),

    'Default click' => array (
      'label' => 'Default click',
      'origin' => 'bottom-left',
      'expand' => 'bottom-right',
      'effect' => 'default',
      'opacity' => '1.0',
      'width' => '150',
      'activate' => 'click',
      'close' => 1,
    ),

    'Default node' => array (
      'label' => 'Default node',
      'origin' => 'bottom-left',
      'expand' => 'bottom-right',
      'effect' => 'default',
      'opacity' => '1.0',
      'width' => '150',
      'activate' => 'hover',
      'teaser' => 1,
      'links' => 1,
    ),

    'Left block' => array (
      'label' => 'Left block',
      'origin' => 'top-right',
      'expand' => 'bottom-right',
      'effect' => 'default',
      'opacity' => '1.0',
      'width' => '150',
      'activate' => 'hover',
    ),

    'Right block' => array (
      'label' => 'Right block',
      'origin' => 'top-left',
      'expand' => 'bottom-left',
      'effect' => 'default',
      'opacity' => '1.0',
      'width' => '150',
      'activate' => 'hover',
    ),

    'Popup menu' => array (
      'label' => 'Popup menu',
      'origin' => 'top-right',
      'expand' => 'bottom-right',
      'effect' => 'default',
      'opacity' => '1.0',
      'submenu-origin' => 'top-right',
      'submenu-expand' => 'bottom-right',
      'width' => '200',
      'activate' => 'hover',
    ),

    'Flat popup menu' => array (
      'label' => 'Flat popup menu',
      'origin' => 'top-right',
      'expand' => 'bottom-right',
      'effect' => 'default',
      'opacity' => '1.0',
      'width' => '200',
      'activate' => 'hover',
      'flat' => 1,
    ),
  );
}



function _popup_ui_formatter_settings($new_formatters = FALSE){

  static $formatters = FALSE;

  if (is_array($new_formatters)){
    $formatters = $new_formatters;
    variable_set('popup-formatters', $formatters);
  }

  if (!$formatters){
    $formatters = variable_get('popup-formatters', _popup_ui_formatter_defaults());
  }

  return $formatters;
}


