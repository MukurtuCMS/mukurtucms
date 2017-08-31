<?php
/**
 * @file
 * alter.inc
 *
 * Contains various implementations of hook_*_alter().
 */

/**
 * Include #pre_render callbacks for elements.
 */
bootstrap_include('bootstrap', 'includes/pre-render.inc');

/**
 * Include #process callbacks for elements.
 */
bootstrap_include('bootstrap', 'includes/process.inc');

/**
 * Implements hook_css_alter().
 */
function bootstrap_css_alter(&$css) {
  $theme_path = drupal_get_path('theme', 'bootstrap');

  // Exclude specified CSS files from theme.
  $excludes = bootstrap_get_theme_info(NULL, 'exclude][css');

  // Add CDN assets, if any.
  $provider = bootstrap_setting('cdn_provider');
  if ($cdn_assets = bootstrap_get_cdn_assets('css', $provider)) {
    $cdn_weight = -2.99;
    foreach ($cdn_assets as $cdn_asset) {
      $cdn_weight += .01;
      $css[$cdn_asset] = array(
        'data' => $cdn_asset,
        'type' => 'external',
        'every_page' => TRUE,
        'media' => 'all',
        'preprocess' => FALSE,
        'group' => CSS_THEME,
        'browsers' => array('IE' => TRUE, '!IE' => TRUE),
        'weight' => $cdn_weight,
      );
    }

    // Add a specific version and theme CSS overrides file.
    $version = bootstrap_setting('cdn_' . $provider . '_version');
    if (!$version) {
      $version = BOOTSTRAP_VERSION;
    }
    $theme = bootstrap_setting('cdn_' . $provider . '_theme');
    if (!$theme) {
      $theme = 'bootstrap';
    }
    $theme = $theme === 'bootstrap' || $theme === 'bootstrap_theme' ? '' : "-$theme";
    $overrides = "$theme_path/css/$version/overrides$theme.min.css";
    if (file_exists($overrides)) {
      $css[$overrides] = array(
        'data' => $overrides,
        'type' => 'file',
        'every_page' => TRUE,
        'media' => 'all',
        'preprocess' => TRUE,
        'group' => CSS_THEME,
        'browsers' => array('IE' => TRUE, '!IE' => TRUE),
        'weight' => -1,
      );
    }
  }
  if (!empty($excludes)) {
    $excludes = array_merge($excludes, str_replace('.css', '-rtl.css', $excludes));
    $css = array_diff_key($css, drupal_map_assoc($excludes));
  }
}

/**
 * Implements hook_element_info_alter().
 */
function bootstrap_element_info_alter(&$info) {
  global $theme_key;

  $cid = "theme_registry:bootstrap:element_info";
  $cached = array();
  if (($cache = cache_get($cid)) && !empty($cache->data)) {
    $cached = $cache->data;
  }

  $themes = _bootstrap_get_base_themes($theme_key, TRUE);
  foreach ($themes as $theme) {
    if (!isset($cached[$theme])) {
      $cached[$theme] = array();
      foreach (array_keys($info) as $type) {
        $element = array();

        // Replace fieldset theme implementations with bootstrap_panel.
        if (!empty($info[$type]['#theme']) && $info[$type]['#theme'] === 'fieldset') {
          $element['#bootstrap_replace']['#theme'] = 'bootstrap_panel';
        }
        if (!empty($info[$type]['#theme_wrappers']) && array_search('fieldset', $info[$type]['#theme_wrappers']) !== FALSE) {
          $element['#bootstrap_replace']['#theme_wrappers']['fieldset'] = 'bootstrap_panel';
        }

        // Setup a default "icon" variable. This allows #icon to be passed
        // to every template and theme function.
        // @see https://drupal.org/node/2219965
        $element['#icon'] = NULL;
        $element['#icon_position'] = 'before';

        $properties = array(
          '#process' => array(
            'form_process',
            'form_process_' . $type,
          ),
          '#pre_render' => array(
            'pre_render',
            'pre_render_' . $type,
          ),
        );
        foreach ($properties as $property => $callbacks) {
          foreach ($callbacks as $callback) {
            $function = $theme . '_' . $callback;
            if (function_exists($function)) {
              // Replace direct core function correlation.
              if (!empty($info[$type][$property]) && array_search($callback, $info[$type][$property]) !== FALSE) {
                $element['#bootstrap_replace'][$property][$callback] = $function;
              }
              // Check for a "form_" prefix instead (for #pre_render).
              elseif (!empty($info[$type][$property]) && array_search('form_' . $callback, $info[$type][$property]) !== FALSE) {
                $element['#bootstrap_replace'][$property]['form_' . $callback] = $function;
              }
              // Otherwise, append the function.
              else {
                $element[$property][] = $function;
              }
            }
          }
        }
        $cached[$theme][$type] = $element;
      }

      // Cache the element information.
      cache_set($cid, $cached);
    }

    // Merge in each theme's cached element info.
    $info = _bootstrap_element_info_array_merge($info, $cached[$theme]);
  }
}

/**
 * Merges the cached element information into the runtime array.
 *
 * @param array $info
 *   The element info array to merge data into.
 * @param array $cached
 *   The cached element info data array to merge from.
 *
 * @return array
 *   The altered element info array.
 */
function _bootstrap_element_info_array_merge($info, $cached) {
  foreach ($cached as $type => $element) {
    $replacement_data = isset($element['#bootstrap_replace']) ? $element['#bootstrap_replace'] : array();
    unset($element['#bootstrap_replace']);
    foreach ($element as $property => $data) {
      if (is_array($data)) {
        if (!isset($info[$type][$property])) {
          $info[$type][$property] = array();
        }
        // Append the values if not already in the array.
        foreach ($data as $key => $value) {
          if (!in_array($value, $info[$type][$property])) {
            $info[$type][$property][] = $value;
          }
        }
      }
      // Create the property, if not already set.
      elseif (!isset($info[$type][$property])) {
        $info[$type][$property] = $data;
      }
    }
    // Replace data, if necessary.
    foreach ($replacement_data as $property => $data) {
      if (is_array($data)) {
        foreach ($data as $needle => $replacement) {
          if (!empty($info[$type][$property]) && ($key = array_search($needle, $info[$type][$property])) !== FALSE) {
            $info[$type][$property][$key] = $replacement;
          }
        }
      }
      // Replace the property with the new data.
      else {
        $info[$type][$property] = $data;
      }
    }
  }

  // Return the altered element info array.
  return $info;
}

/**
 * Implements hook_field_widget_form_alter().
 */
function bootstrap_field_widget_form_alter(&$element, &$form_state, $context) {
  $widget_type = isset($context['instance']['widget']['type']) ? $context['instance']['widget']['type'] : NULL;
  if ($widget_type === 'image_image') {
    foreach (element_children($element) as $child) {
      $element[$child]['#process'][] = '_bootstrap_image_field_widget_process';
    }
  }
}

/**
 * Implements above #process callback.
 */
function _bootstrap_image_field_widget_process($element, &$form_state, $form) {
  // Core explicitly sets #theme_wrappers to an empty array for the upload
  // element (perhaps for styling reasons?). Thus, bootstrap_form_element() is
  // invoked, preventing any necessary logic from executing. To achieve the
  // same goal and keep backwards compatibility, reset the theme wrapper back
  // and indicating that the wrapper shouldn't be printed.
  $element['upload']['#theme_wrappers'][] = 'form_element__image_widget';
  $element['upload']['#form_element_wrapper'] = FALSE;

  // Unfortunately, core also doesn't set #access on the appropriate elements
  // until way too late (ironically, because of #ajax). Instead of calling
  // file_managed_file_pre_render(), just mimic the same #access logic, but
  // using #default_value instead of #value since the ajax request populates
  // #value.
  $value = empty($element['#default_value']['fid']);
  if (!$value) {
    $element['upload']['#access'] = FALSE;
    $element['upload_button']['#access'] = FALSE;
  }
  // If we don't already have a file, there is nothing to remove.
  else {
    $element['remove_button']['#access'] = FALSE;
  }

  // Make the upload file element an input group with a button.
  $element['upload']['#input_group_button'] = $value;

  return $element;
}

/**
 * Implements hook_form_alter().
 */
function bootstrap_form_alter(array &$form, array &$form_state = array(), $form_id = NULL) {
  if ($form_id) {
    switch ($form_id) {
      case 'system_theme_settings':
        // Create vertical tabs for global settings (provided by core or other
        // contrib modules).
        if (!isset($form['global'])) {
          $form['global'] = array(
            '#type' => 'vertical_tabs',
            '#weight' => -9,
          );
          if (!empty($form_state['build_info']['args'][0])) {
            $form['global']['#prefix'] = '<h2><small>' . t('Override Global Settings') . '</small></h2>';
          }
        }

        // Iterate over all child elements and check to see if they should be
        // moved in the global vertical tabs.
        $global_children = element_children($form);
        foreach ($global_children as $child) {
          if (isset($form[$child]['#type']) && $form[$child]['#type'] === 'fieldset' && !isset($form[$child]['#group'])) {
            $form[$child]['#group'] = 'global';
          }
        }
        break;

      case 'search_form':
        // Add a clearfix class so the results don't overflow onto the form.
        $form['#attributes']['class'][] = 'clearfix';

        // Remove container-inline from the container classes.
        $form['basic']['#attributes']['class'] = array();

        // Hide the default button from display.
        $form['basic']['submit']['#attributes']['class'][] = 'element-invisible';

        // Implement a theme wrapper to add a submit button containing a search
        // icon directly after the input element.
        $form['basic']['keys']['#theme_wrappers'] = array('bootstrap_search_form_wrapper');
        $form['basic']['keys']['#title'] = '';
        $form['basic']['keys']['#attributes']['placeholder'] = t('Search');
        break;

      case 'search_block_form':
        $form['#attributes']['class'][] = 'form-search';

        $form['search_block_form']['#title'] = '';
        $form['search_block_form']['#attributes']['placeholder'] = t('Search');

        // Hide the default button from display and implement a theme wrapper
        // to add a submit button containing a search icon directly after the
        // input element.
        $form['actions']['submit']['#attributes']['class'][] = 'element-invisible';
        $form['search_block_form']['#theme_wrappers'] = array('bootstrap_search_form_wrapper');

        // Apply a clearfix so the results don't overflow onto the form.
        $form['#attributes']['class'][] = 'content-search';
        break;

      case 'image_style_form':
        $form['effects']['new']['new']['#input_group_button'] = TRUE;
        break;

      case 'path_admin_filter_form':
        $form['basic']['filter']['#input_group_button'] = TRUE;
        break;
    }

  }
}

/**
 * Implements hook_js_alter().
 */
function bootstrap_js_alter(&$js) {
  // Exclude specified JavaScript files from theme.
  $excludes = bootstrap_get_theme_info(NULL, 'exclude][js');

  $theme_path = drupal_get_path('theme', 'bootstrap');

  // Add or replace JavaScript files when matching paths are detected.
  // Replacement files must begin with '_', like '_node.js'.
  $files = _bootstrap_file_scan_directory($theme_path . '/js', '/\.js$/');
  foreach ($files as $file) {
    $path = str_replace($theme_path . '/js/', '', $file->uri);
    // Detect if this is a replacement file.
    $replace = FALSE;
    if (preg_match('/^[_]/', $file->filename)) {
      $replace = TRUE;
      $path = dirname($path) . '/' . preg_replace('/^[_]/', '', $file->filename);
    }
    $matches = array();
    if (preg_match('/^modules\/([^\/]*)/', $path, $matches)) {
      if (!module_exists($matches[1])) {
        continue;
      }
      else {
        $path = str_replace('modules/' . $matches[1], drupal_get_path('module', $matches[1]), $path);
      }
    }
    // Path should always exist to either add or replace JavaScript file.
    if (!empty($js[$path])) {
      // Replace file.
      if ($replace) {
        $js[$file->uri] = $js[$path];
        $js[$file->uri]['data'] = $file->uri;
        unset($js[$path]);
      }
      // Add file.
      else {
        $js[$file->uri] = drupal_js_defaults($file->uri);
        $js[$file->uri]['group'] = JS_THEME;
      }
    }
  }

  // Ensure jQuery Once is always loaded.
  // @see https://drupal.org/node/2149561
  if (empty($js['misc/jquery.once.js'])) {
    $jquery_once = drupal_get_library('system', 'jquery.once');
    $js['misc/jquery.once.js'] = $jquery_once['js']['misc/jquery.once.js'];
    $js['misc/jquery.once.js'] += drupal_js_defaults('misc/jquery.once.js');
  }

  // Always add bootstrap.js last.
  $bootstrap = $theme_path . '/js/bootstrap.js';
  $js[$bootstrap] = drupal_js_defaults($bootstrap);
  $js[$bootstrap]['group'] = JS_THEME;
  $js[$bootstrap]['scope'] = 'footer';

  if (!empty($excludes)) {
    $js = array_diff_key($js, drupal_map_assoc($excludes));
  }

  // Add Bootstrap settings.
  $js['settings']['data'][]['bootstrap'] = array(
    'anchorsFix' => bootstrap_setting('anchors_fix'),
    'anchorsSmoothScrolling' => bootstrap_setting('anchors_smooth_scrolling'),
    'formHasError' => (int) bootstrap_setting('forms_has_error_value_toggle'),
    'popoverEnabled' => bootstrap_setting('popover_enabled'),
    'popoverOptions' => array(
      'animation' => (int) bootstrap_setting('popover_animation'),
      'html' => (int) bootstrap_setting('popover_html'),
      'placement' => bootstrap_setting('popover_placement'),
      'selector' => bootstrap_setting('popover_selector'),
      'trigger' => implode(' ', array_filter(array_values((array) bootstrap_setting('popover_trigger')))),
      'triggerAutoclose' => (int) bootstrap_setting('popover_trigger_autoclose'),
      'title' => bootstrap_setting('popover_title'),
      'content' => bootstrap_setting('popover_content'),
      'delay' => (int) bootstrap_setting('popover_delay'),
      'container' => bootstrap_setting('popover_container'),
    ),
    'tooltipEnabled' => bootstrap_setting('tooltip_enabled'),
    'tooltipOptions' => array(
      'animation' => (int) bootstrap_setting('tooltip_animation'),
      'html' => (int) bootstrap_setting('tooltip_html'),
      'placement' => bootstrap_setting('tooltip_placement'),
      'selector' => bootstrap_setting('tooltip_selector'),
      'trigger' => implode(' ', array_filter(array_values((array) bootstrap_setting('tooltip_trigger')))),
      'delay' => (int) bootstrap_setting('tooltip_delay'),
      'container' => bootstrap_setting('tooltip_container'),
    ),
  );

  // Add CDN assets, if any.
  if ($cdn_assets = bootstrap_get_cdn_assets('js')) {
    $cdn_weight = -99.99;
    foreach ($cdn_assets as $cdn_asset) {
      $cdn_weight += .01;
      $js[$cdn_asset] = drupal_js_defaults($cdn_asset);
      $js[$cdn_asset]['type'] = 'external';
      $js[$cdn_asset]['every_page'] = TRUE;
      $js[$cdn_asset]['weight'] = $cdn_weight;
    }
  }
}

/**
 * Implements hook_icon_bundle_list_alter().
 */
function bootstrap_icon_bundle_list_alter(&$build, $bundle) {
  if (bootstrap_setting('tooltip_enabled')) {
    foreach ($build as &$icon) {
      $icon['#attributes']['data-toggle'] = 'tooltip';
      $icon['#attributes']['data-placement'] = 'bottom';
    }
  }
}

/**
 * Implements hook_menu_local_tasks_alter().
 */
function bootstrap_menu_local_tasks_alter(&$data, &$router_item, $root_path) {
  if (!empty($data['actions']['output'])) {
    $items = array();
    foreach ($data['actions']['output'] as $item) {
      $items[] = array(
        'data' => $item,
      );
    }
    $data['actions']['output'] = array(
      '#theme' => 'item_list__action_links',
      '#items' => $items,
      '#attributes' => array(
        'class' => array('action-links'),
      ),
    );
  }
}

/**
 * Implements hook_js_callback_filter_xss_alter().
 */
function bootstrap_js_callback_filter_xss_alter(array &$allowed_tags = array()) {
  $allowed_tags[] = 'button';
}
