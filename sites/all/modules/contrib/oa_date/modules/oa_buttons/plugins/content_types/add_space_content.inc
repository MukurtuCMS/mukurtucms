<?php
/**
 * @file oa_notifications_pane.inc
 */

$plugin = array(
  'title' => t('Add Space Content'),
  'description' => t('Provides a dropdown menu for adding content within a space'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_buttons_add_space_content_settings_form',
  'render callback' => 'oa_buttons_add_space_content_render',
);

/**
 * Renders the widget.
 */
function oa_buttons_add_space_content_render($subtype, $conf, $args, $context) {
  global $user;
  $context = og_context();
  $section = oa_core_get_section_context();
  $content = '';
  if (isset($context['gid'])) {
    $node = node_load($context['gid']);
  }
  else {
    return;
  }
  $cache_key = 'oa_section_buttons:' . $context['gid'] . ':' . $section . ':' . $user->uid;
  // Lets cache this, since it can be expensive.
  if ($cache = cache_get($cache_key, 'cache_oa_section_buttons')) {
    $content = $cache->data;
  }
  else {
    $caption = isset($conf['caption']) ? $conf['caption'] : t('Create Content');
    $btn_title = isset($conf['btn_title']) ? $conf['btn_title'] : t('Create Content');
    $buttons = oa_buttons_get_command_buttons($node);
    if (count($buttons)) {
      drupal_alter('oa_space_buttons', $buttons);
      $command_buttons = array();
      $node_types = array_flip(node_type_get_names());
      // Iterate over each of the buttons.
      foreach ($buttons as $button) {
        $entity_type = $button['value'];
        $command_buttons[$entity_type] = $entity_type;
      }
      $entities = command_buttons_machine_name_load(array_keys($command_buttons));
      $btn_class = !empty($conf['btn_class']) ? check_plain($conf['btn_class']) : 'btn btn-inverse';
      $classes = array(
        'use_dropdowns' => TRUE,
        'dropdown_label' => $caption,
        'btn_title' => !empty($btn_title) ? $btn_title : $caption,
        'direction' => !empty($conf['direction']) ? check_plain($conf['direction']) : '',
        'icon_class' => !empty($conf['icon']) ? check_plain($conf['icon']) : '',
        'show_caret' => isset($conf['caret']) ? $conf['caret'] : TRUE,
        'item_class' => array(
          'oa-button',
        ),
        'wrapper_class' => array(
          'oa-buttons',
          $btn_class,
        ),
      );

      if (!empty($entities) && !empty($buttons)) {
        $content = command_buttons_render_buttons($entities, $classes, $buttons);
      }

      // Cache for 1 hour.
      cache_set($cache_key, $content, 'cache_oa_section_buttons', time() + 6000);
    }
  }

  if (empty($content)) {
    return;
  }

  $block = new stdClass();
  $block->content = $content;
  return $block;
}

/**
 * Provides the form for the widget.
 */
function oa_buttons_add_space_content_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['caption'] = array(
    '#title' => t('Button caption'),
    '#type' => 'textfield',
    '#default_value' => (isset($conf['caption'])) ? $conf['caption'] : t('Create Content'),
  );
  $form['btn_title'] = array(
    '#title' => t('Button title '),
    '#type' => 'textfield',
    '#default_value' => (isset($conf['btn_title'])) ? $conf['btn_title'] : t('Create Content'),
  );
  $form['icon'] = array(
    '#title' => t('Icon class'),
    '#type' => 'textfield',
    '#default_value' => (!empty($conf['icon'])) ? $conf['icon'] : '',
  );
  $form['btn_class'] = array(
    '#title' => t('Button class'),
    '#type' => 'textfield',
    '#default_value' => (!empty($conf['btn_class'])) ? $conf['btn_class'] : 'btn btn-inverse',
  );
  $form['direction'] = array(
    '#type' => 'select',
    '#title' => t('Direction'),
    '#options' => array(
      '' => t('Drop down'),
      'dropup' => t('Drop up'),
    ),
    '#default_value' => (isset($conf['direction'])) ? $conf['direction'] : '',
    '#description' => t('Controls whether menu expands downwards or upwards.  Default is drop down.'),
  );
  $form['caret'] = array(
    '#title' => t('Show caret'),
    '#type' => 'checkbox',
    '#default_value' => (isset($conf['caret'])) ? $conf['caret'] : TRUE,
  );

  return $form;
}

/**
 * Saves changes to the widget.
 */
function oa_buttons_add_space_content_settings_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  cache_clear_all('oa_section_buttons', 'cache_oa_section_buttons', TRUE);
}
