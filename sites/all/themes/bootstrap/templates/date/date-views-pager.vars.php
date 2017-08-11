<?php
/**
 * @file
 * Stub file for "date_views_pager" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "date_views_pager" theme hook.
 *
 * See template for list of available variables.
 *
 * @see date-views-pager.tpl.php
 *
 * @ingroup theme_preprocess
 */
function bootstrap_preprocess_date_views_pager(&$variables) {
  $mini = !empty($variables['mini']);

  // Link types.
  $types = array(
    // Because this is using the "date_nav" context, this must use "Prev"
    // instead of the full English word "Previous".
    // @todo Should this be fixed upstream in the date/date_views module?
    'prev' => t('Prev', array(), array('context' => 'date_nav')),
    'next' => t('Next', array(), array('context' => 'date_nav')),
  );

  // Icon map.
  $icons = array(
    'prev' => array(
      'name' => 'menu-left',
      'default' => '&laquo;&nbsp;',
      'position' => 'before',
    ),
    'next' => array(
      'name' => 'menu-right',
      'default' => '&nbsp;&raquo;',
      'position' => 'after',
    ),
  );

  // Create necessary links.
  $items = array();
  foreach ($types as $type => $text) {
    $item_classes = array($type);

    $options = isset($variables[$type . '_options']) ? $variables[$type . '_options']: array();
    $options += array('attributes' => array());

    $url = $variables[$type . '_url'];
    // Make the item disabled if there is no URL.
    if (!$url) {
      $url = '#';
      $item_classes[] = 'disabled';
      $options['absolute'] = TRUE;
      $options['external'] = TRUE;
    }
    // Convert titles into tooltips, if enabled.
    elseif (!empty($options['attributes']['title']) && bootstrap_setting('tooltip_enabled')) {
      $options['attributes']['data-toggle'] = 'tooltip';
      $options['attributes']['data-placement'] = 'bottom';
    }

    // Create a link.
    $link = array(
      '#theme' => 'link__date_views__pager__' . $type,
      '#text' => $text,
      '#path' => $url,
      '#options' => $options,
    );

    // Add relevant icon.
    if (isset($icons[$type])) {
      $icon = $icons[$type];
      $link['#icon'] = _bootstrap_icon($icon['name'], $icon['default']);
      $link['#icon_position'] = $mini ? 'icon_only' : $icon['position'];
    }

    $items[$type] = array(
      'class' => $item_classes,
      'data' => $link,
    );
  }

  // Add items render array.
  $variables['items'] = array(
    '#theme' => 'item_list__date_views__pager',
    '#attributes' => array('class' => array('pagination', 'pull-right')),
    '#items' => $items,
  );

  // Add default classes for the <nav> wrapper.
  $variables['attributes_array']['class'][] = 'clearfix';
  $variables['attributes_array']['class'][] = 'date-nav-wrapper';

  // This is not mentioned anywhere other than in the original module's
  // template file. However, to keep BC, these need to be merged just in case.
  if (!empty($variables['extra_classes'])) {
    if (is_string($variables['extra_classes'])) {
      $variables['extra_classes'] = explode(' ', $variables['extra_classes']);
    }
    $variables['attributes_array']['class'] = array_merge(isset($variables['attributes']['class']) ? $variables['attributes']['class'] : array(), $variables['extra_classes']);
  }
}
