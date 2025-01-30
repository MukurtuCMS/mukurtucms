<?php

/**
 * @file
 * Defines the space summary panels pane.
 */

$plugin = array(
  'title' => t('Space summary'),
  'description' => t('Provides a summary of a space, including the picture, description, and useful links.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_core_summary_edit_form',
  'render callback' => 'oa_core_summary_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'show_description' => TRUE,
    'show_favorite' => TRUE,
    'show_links' => TRUE,
    'image_size' => 'quarter',
  ),
);


/**
 * Render callback for the content visibility panel.
 */
function oa_core_summary_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data->nid)
    || !(($space_nid = oa_core_get_group_from_node($context->data, array(OA_SPACE_TYPE)))
      && ($space = node_load($space_nid)))
    || !node_access('view', $space)) {
    return;
  }

  global $user;
  $vars = array();

  $vars['title'] = check_plain($space->title);
  $vars['description'] = '';
  $vars['picture'] = '';
  $vars['links']['favorite'] = '';
  $vars['links']['edit'] = '';

  if (!empty($conf['show_description'])) {
    $field = field_view_field('node', $space, 'body', array('label' => 'hidden'));
    if (!empty($field)) {
      $vars['description'] = drupal_render($field);
    }

    $picture = field_get_items('node', $space, 'field_featured_image');
    if (!empty($picture)) {
      $picture = array_shift($picture);
      $vars['picture'] = theme('image_style', array(
        'style_name' => 'panopoly_image_' . $conf['image_size'],
        'path' => $picture['uri'],
        'width' => $picture['width'],
        'height' => $picture['height'],
        'alt' => $picture['alt'],
      ));
    }

    if (isset($space->field_oa_related)) {
      $paragraphs = field_view_field('node', $space, 'field_oa_related');
      $paragraphs['#label_display'] = 'hidden';
      $vars['related'] = drupal_render($paragraphs);
    }
  }

  $vars['links'] = array();
  if (!empty($conf['show_favorite']) && $user->uid && module_exists('oa_favorites')) {
    $favorite = oa_favorites_is_favorite_space($user->uid, $space->nid);
    $vars['links']['favorite'] = theme('flag', array(
      'flag' => flag_get_flag(FAVORITE_SPACE),
      'action' => $favorite ? 'unflag' : 'flag',
      'content_id' => $space->nid,
    ));
  }
  if (!empty($conf['show_links']) && node_access('update', $space)) {
    $vars['links']['edit'] = l(t('Edit'), 'node/' . $space->nid . '/edit');
  }

  $block = new stdClass();
  $block->title = check_plain($space->title);
  $block->content = theme('oa_core_summary', $vars);

  return $block;
}


/**
 * Edit form for the panel.
 */
function oa_core_summary_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['show_description'] = array(
    '#title' => t('Show description'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_description'],
  );
  $form['show_favorite'] = array(
    '#title' => t('Show favorite button'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_favorite'],
  );
  $form['show_links'] = array(
    '#title' => t('Show links'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_links'],
  );
  $form['image_size'] = array(
    '#type' => 'radios',
    '#title' => t('Image size'),
    '#options' => array(
      'quarter' => t('Quarter'),
      'half' => t('Half'),
      'full' => t('Full'),
    ),
    '#default' => $conf['image_size'],
  );

  return $form;
}

/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_core_summary_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

