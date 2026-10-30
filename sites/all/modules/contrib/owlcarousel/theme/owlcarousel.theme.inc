<?php

/**
 * @file
 * owlcarousel.theme.inc
 */

/**
 * Template process owlcarousel.
 */
function template_process_owlcarousel(&$variables) {
  $instance = $variables['settings']['attributes']['id']['default'];
  $variables['settings']['attributes']['id'] = $instance;
  $variables['settings']['attributes']['class'][] = 'owl-carousel owl-theme';
}

/**
 * Template preprocess carousel wrapper.
 */
function template_preprocess_owlcarousel_wrapper(&$variables) {
  if (count($variables['output']['#items']) < 2) {
    $variables['output']['#settings']['attributes']['class'][] = 'disabled';
  }
  $variables['output']['#settings']['attributes']['class'][] = drupal_clean_css_identifier($variables['output']['#settings']['instance']);
}

/**
 * Theme declaration for Owl Carousel wrapper.
 */
function theme_owlcarousel_wrapper($variables) {
  $attributes = $variables['output']['#settings']['attributes'];

  return '<div' . drupal_attributes($attributes) . '>' . drupal_render($variables['output']) . '</div>';
}

/**
 * Theme declaration for Owl Carousel.
 */
function theme_owlcarousel($variables) {
  $instance = $variables['settings']['attributes']['id'];
  $settings = $variables['settings'];
  $items = $variables['items'];

  $output = array(
    '#output' => array(
      'settings' => $settings,
      'items' => $items,
    ),
    '#pre_render' => array('owlcarousel_pre_render_cache'),
  );

  $debug = variable_get('owlcarousel_debug_mode', TRUE);
  // Views (and other callers) can disable caching if it's unwanted:
  $cache_disable = !empty($variables['settings']['cache_disable']);
  if (!$debug && !$cache_disable) {
    $output += array(
      '#cache' => array(
        'keys' => array('owlcarousel', $instance),
        'bin' => 'cache',
        'expire' => time() + variable_get('owlcarousel_cache_interval', 3600),
        'granularity' => DRUPAL_CACHE_GLOBAL,
      ),
    );
  }

  return drupal_render($output);
}

/**
 * Construct element for render.
 */
function owlcarousel_pre_render_cache($element) {
  $settings = $element['#output']['settings']['instance'];
  $instance = $element['#output']['settings']['attributes']['id'];

  $output = array(
    '#theme' => 'owlcarousel_list',
    '#items' => $element['#output']['items'],
    '#settings' => $element['#output']['settings'],
  );

  // Element output /w attached.
  $element['#markup'] = owlcarousel_build($output);

  // Provide alter before carousel is rendered.
  drupal_alter('owlcarousel_pre_render', $element);

  $element['#children'] = drupal_render($element['#markup']);
  $element['#attached'] = array(
    'js' => array(
      array(
        'data' => drupal_get_path('module', 'owlcarousel') . '/includes/js/owlcarousel.settings.js',
        'type' => 'file',
        'scope' => 'footer',
      ),
      array(
        'data' => array(
          'owlcarousel' => array(
            $instance => owlcarousel_settings($instance, $settings),
          ),
        ),
        'type' => 'setting',
      ),
    ),
    'library' => array(
      array(
        'owlcarousel',
        'owlcarousel',
      ),
    ),
  );

  return $element;
}

/**
 * Build final output array.
 */
function owlcarousel_build($output) {
  return array(
    '#output' => $output,
    '#theme_wrappers' => array('owlcarousel_wrapper'),
  );
}

/**
 * Theme declaration for carousel lists.
 */
function theme_owlcarousel_list(&$variables) {
  $items = &$variables['items'];
  $output = '';

  if (!empty($items)) {
    foreach ($items as $i => $item) {
      if ($item['row']) {
        $striping = $i % 2 == 0 ? 'item-odd' : 'item-even';
        $output .= theme('owlcarousel_list_item', array(
          'item' => $item['row'],
          'class' => drupal_html_class('item-' . $i) . ' ' . drupal_html_class($striping),
        ));
      }
    }
  }

  return $output;
}

/**
 * Theme declaration for carousel items.
 */
function theme_owlcarousel_list_item(&$variables) {
  return '<div class="' . $variables['class'] . '">' . $variables['item'] . '</div>';
}
