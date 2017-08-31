<?php
/**
 * @file
 * List of functions used to alter the theme registry in Bootstrap based themes.
 */

/**
 * @addtogroup registry
 * @{
 */

// Define additional sub-groups for creating lists for all the theme files.
/**
 * @defgroup theme_functions Theme Functions (.func.php)
 *
 * List of theme functions used in the Drupal Bootstrap base theme.
 *
 * View the parent topic for additional documentation.
 */
/**
 * @defgroup theme_preprocess Theme Preprocess Functions (.vars.php)
 *
 * List of theme preprocess functions used in the Drupal Bootstrap base theme.
 *
 * View the parent topic for additional documentation.
 */
/**
 * @defgroup theme_process Theme Process Functions (.vars.php)
 *
 * List of theme process functions used in the Drupal Bootstrap base theme.
 *
 * View the parent topic for additional documentation.
 */
/**
 * @defgroup templates Theme Templates (.tpl.php)
 *
 * List of theme templates used in the Drupal Bootstrap base theme.
 *
 * View the parent topic for additional documentation.
 */

/**
 * Stub implementation for bootstrap_theme().
 *
 * This base-theme's custom theme hook implementations. Never define "path"
 * or "template" as these are detected and automatically added.
 *
 * @see bootstrap_theme_registry_alter()
 * @see bootstrap_theme()
 * @see hook_theme()
 */
function _bootstrap_theme(&$existing, $type, $theme, $path) {
  // Bootstrap Carousels.
  $hooks['bootstrap_carousel'] = array(
    'variables' => array(
      'attributes' => array(),
      'items' => array(),
      'start_index' => 0,
      'controls' => TRUE,
      'indicators' => TRUE,
      'interval' => 5000,
      'pause' => 'hover',
      'wrap' => TRUE,
    ),
  );

  // Bootstrap Dropdowns.
  $hooks['bootstrap_dropdown'] = array(
    'render element' => 'element',
  );

  // Bootstrap Modals.
  $hooks['bootstrap_modal'] = array(
    'variables' => array(
      'heading' => '',
      'body' => '',
      'footer' => '',
      'dialog_attributes' => array(),
      'attributes' => array(),
      'size' => '',
      'html_heading' => FALSE,
    ),
  );

  // Bootstrap Panels.
  $hooks['bootstrap_panel'] = array(
    'render element' => 'element',
  );

  // Bootstrap search form wrapper.
  // @todo Remove this as it's not really needed and should use suggestions.
  $hooks['bootstrap_search_form_wrapper'] = array(
    'render element' => 'element',
  );
  return $hooks;
}

/**
 * Implements hook_theme_registry_alter().
 */
function bootstrap_theme_registry_alter(&$registry) {
  // Retrieve the active theme names.
  $themes = _bootstrap_get_base_themes(NULL, TRUE);

  // Return the theme registry unaltered if it is not Bootstrap based.
  if (!in_array('bootstrap', $themes)) {
    return;
  }

  // Inject the "footer" variable default in the existing "table" hook.
  // @see https://drupal.org/node/806982
  // @todo Make this discoverable in some way instead of a manual injection.
  $registry['table']['variables']['footer'] = NULL;

  // Process registered hooks in the theme registry.
  _bootstrap_process_theme_registry($registry, $themes);

  // Process registered hooks in the theme registry to add necessary theme hook
  // suggestion phased function invocations. This must be run after separately
  // and after all includes have been loaded.
  _bootstrap_process_theme_registry_suggestions($registry, $themes);

  // Post-process theme registry. This happens after all altering has occurred.
  foreach ($registry as $hook => $info) {
    // Ensure uniqueness.
    if (!empty($registry[$hook]['includes'])) {
      $registry[$hook]['includes'] = array_unique($info['includes']);
    }
    if (!empty($registry[$hook]['preprocess functions'])) {
      $registry[$hook]['preprocess functions'] = array_unique($info['preprocess functions']);
    }
    if (!empty($registry[$hook]['process functions'])) {
      $registry[$hook]['process functions'] = array_unique($info['process functions']);
    }

    // Ensure "theme path" is set.
    if (!isset($registry[$hook]['theme path'])) {
      $registry[$hook]['theme path'] = $GLOBALS['theme_path'];
    }
  }
}

/**
 * Processes registered hooks in the theme registry against list of themes.
 *
 * Discovers and fills missing elements in the theme registry. This is similar
 * to _theme_process_registry(), however severely modified for Bootstrap based
 * themes.
 *
 * All additions or modifications must live in `./templates`, relative to the
 * base theme or sub-theme's base folder. These files can be organized in any
 * order using sub-folders as it searches recursively.
 *
 * Adds or modifies the following theme hook keys:
 *  - `includes`: When a variables file `*.vars.php` is found.
 *  - `includes`: When a function file `*.func.php` is found.
 *  - `function`: When a specific theme hook function override is found.
 *  - `template`: When a template file `*.tpl.php` is found in. Note, if both
 *    a function and a template are defined, a template implementation will
 *    always be used and the `function` will be unset.
 *  - `path`: When a template file `*.tpl.php` is found.
 *  - `preprocess functions`: When a specific theme hook suggestion function
 *    `hook_preprocess_HOOK__SUGGESTION` is found.
 *  - `process functions` When a specific theme hook suggestion function
 *    `hook_process_HOOK__SUGGESTION` is found.
 *
 * @param array $registry
 *   The theme registry array, passed by reference.
 * @param string|array $themes
 *   The name of the theme or list of theme names to process.
 *
 * @see bootstrap_theme_registry_alter()
 * @see _theme_process_registry()
 * @see _theme_build_registry()
 */
function _bootstrap_process_theme_registry(&$registry, $themes) {
  // Convert to an array if needed.
  if (is_string($themes)) {
    $themes = array();
  }

  // Processor functions work in two distinct phases with the process
  // functions always being executed after the preprocess functions.
  $variable_process_phases = array(
    'preprocess functions' => 'preprocess',
    'process functions'    => 'process',
  );

  // Iterate over each theme passed.
  // Iterate over the [pre]process phases.
  foreach ($variable_process_phases as $phase_key => $phase) {
    foreach ($themes as $theme) {
      // Get the theme's base path.
      $path = drupal_get_path('theme', $theme);

      // Find theme function overrides.
      foreach (drupal_system_listing('/\.(func|vars)\.php$/', $path, 'name', 0) as $name => $file) {
        // Strip off the extension.
        if (($pos = strpos($name, '.')) !== FALSE) {
          $name = substr($name, 0, $pos);
        }

        // Transform "-" in file names to "_" to match theme hook naming scheme.
        $hook = strtr($name, '-', '_');

        // File to be included by core's theme function when a theme hook is
        // invoked.
        if (isset($registry[$hook])) {
          if (!isset($registry[$hook][$phase_key])) {
            $registry[$hook][$phase_key] = array();
          }
          if (!isset($registry[$hook]['includes'])) {
            $registry[$hook]['includes'] = array();
          }

          // Include the file now so functions can be discovered below.
          include_once DRUPAL_ROOT . '/' . $file->uri;
          if (!in_array($file->uri, $registry[$hook]['includes'])) {
            $registry[$hook]['includes'][] = $file->uri;
          }
        }
      }

      // Process core's normal functionality.
      _theme_process_registry($registry, $theme, $GLOBALS['theme_key'] === $theme ? 'theme' : 'base_theme', $theme, $path);

      // Find necessary templates in the theme.
      $registry = drupal_array_merge_deep($registry, drupal_find_theme_templates($registry, '.tpl.php', $path));

      // Iterate over each registered hook.
      foreach ($registry as $hook => $info) {
        // Remove function callbacks if a template was found.
        if (isset($info['function']) && isset($info['template'])) {
          unset($registry[$hook]['function']);
        }

        // Correct template theme paths.
        if (!isset($info['theme path'])) {
          $registry[$hook]['theme path'] = $path;
        }

        // Correct the type that is implementing this override.
        $registry[$hook]['type'] = $GLOBALS['theme_path'] === $registry[$hook]['theme path'] ? 'theme' : 'base_theme';

        // Sort the phase functions.
        // @see https://www.drupal.org/node/2098551
        _bootstrap_registry_sort_phase_functions($registry[$hook][$phase_key], $hook, $phase, $themes);

        // Setup a default "context" variable. This allows #context to be passed
        // to every template and theme function.
        // @see https://drupal.org/node/2035055
        if (isset($info['variables']) && !isset($info['variables']['context'])) {
          $registry[$hook]['variables']['context'] = array();
        }

        // Setup a default "icon" variable. This allows #icon to be passed
        // to every template and theme function.
        // @see https://drupal.org/node/2219965
        if (isset($info['variables']) && !isset($info['variables']['icon'])) {
          $registry[$hook]['variables']['icon'] = NULL;
        }
        if (isset($info['variables']) && !isset($info['variables']['icon_position'])) {
          $registry[$hook]['variables']['icon_position'] = 'before';
        }
      }
    }
  }
}

/**
 * Ensures the phase functions are invoked in the correct order.
 *
 * @param array $functions
 *   The phase functions to iterate over.
 * @param string $hook
 *   The current hook being processed.
 * @param string $phase
 *   The current phase being processed.
 * @param array $themes
 *   An indexed array of current themes.
 *
 * @see https://www.drupal.org/node/2098551
 */
function _bootstrap_registry_sort_phase_functions(&$functions, $hook, $phase, $themes) {
  // Immediately return if there is nothing to sort.
  if (count($functions) < 2) {
    return;
  }

  // Create an associative array of theme functions to ensure sort order.
  $theme_functions = array_fill_keys($themes, array());

  // Iterate over all the themes.
  foreach ($themes as $theme) {
    // Only add the function to the array of theme functions if it currently
    // exists in the $functions array.
    $function = $theme . '_' . $phase . '_' . $hook;
    $key = array_search($function, $functions);
    if ($key !== FALSE) {
      // Save the theme function to be added later, but sorted.
      $theme_functions[$theme][] = $function;

      // Remove it from the current $functions array.
      unset($functions[$key]);
    }
  }

  // Iterate over all the captured theme functions and place them back into
  // the phase functions array.
  foreach ($theme_functions as $array) {
    $functions = array_merge($functions, $array);
  }
}

/**
 * Processes registered hooks in the theme registry against list of themes.
 *
 * This is used to add the necessary phased functions to theme hook suggestions.
 * Because it uses get_defined_functions(), it must be invoked after all
 * includes have been detected and loaded. This is similar to
 * drupal_find_theme_functions(), however severely modified for Bootstrap based
 * themes.
 *
 * @param array $registry
 *   The theme registry array, passed by reference.
 * @param string|array $themes
 *   The name of the theme or list of theme names to process.
 *
 * @return array
 *   The functions found, suitable for returning from hook_theme;
 *
 * @see https://drupal.org/node/939462
 * @see drupal_find_theme_functions()
 */
function _bootstrap_process_theme_registry_suggestions(&$registry, $themes) {
  // Convert to an array if needed.
  if (is_string($themes)) {
    $themes = array();
  }

  // Merge in normal core detections first.
  $registry = drupal_array_merge_deep($registry, drupal_find_theme_functions($registry, $themes));

  // Processor functions work in two distinct phases with the process
  // functions always being executed after the preprocess functions.
  $variable_process_phases = array(
    'preprocess functions' => 'preprocess',
    'process functions'    => 'process',
  );

  $grouped_functions = drupal_group_functions_by_prefix();

  // Iterate over each theme passed.
  foreach ($themes as $theme) {
    // Iterate over each registered hook.
    foreach ($registry as $hook => $info) {
      // The pattern to match.
      $pattern = isset($info['pattern']) ? $info['pattern'] : ($hook . '__');

      // Only process hooks that have not explicitly "turned off" patterns.
      if (empty($pattern)) {
        continue;
      }

      // Iterate over the [pre]process phases.
      foreach ($variable_process_phases as $phase_key => $phase) {
        // Find functions matching the specific theme and phase prefix.
        $prefix = $theme . '_' . $phase;

        // Grep only the functions which are within the prefix group.
        list($first_prefix,) = explode('_', $prefix, 2);
        if (isset($grouped_functions[$first_prefix]) && ($matches = preg_grep('/^' . $prefix . '_' . $pattern . '/', $grouped_functions[$first_prefix]))) {
          foreach ($matches as $match) {
            // Determine the current theme implementation.
            $hook = substr($match, strlen($prefix) + 1);
            $base_hook = $hook;

            // If there's no current theme implementation, keep checking for
            // more generic base hooks. If there's still no implementation,
            // one must be created using the last found implementation
            // information.
            if (!isset($registry[$base_hook]) || isset($registry[$base_hook]['base hook'])) {
              // Iteratively strip everything after the last '__' delimiter,
              // until an implementation is found.
              while ($pos = strrpos($base_hook, '__')) {
                $base_hook = substr($base_hook, 0, $pos);
                if (isset($registry[$base_hook])) {
                  break;
                }
              }

              // No base hook was found, this allows the implementation to be
              // ignored in the next steps.
              if (!isset($registry[$base_hook])) {
                $base_hook = FALSE;
              }
            }

            // Process specific base hook implementations if necessary.
            if ($base_hook) {
              // The matched theme implementation does not exist in the
              // registry, one must be created if base hook information was
              // found, otherwise it will be ignored.
              if (!isset($registry[$hook])) {
                $registry[$base_hook] += array(
                  'type' => 'theme',
                  'preprocess functions' => array(),
                  'process functions' => array(),
                );
                $hook_type = isset($registry[$base_hook]['function']) ? 'function' : 'template';
                $arg_name = isset($registry[$base_hook]['variables']) ? 'variables' : 'render element';
                $registry[$hook] = array(
                  $hook_type => $registry[$base_hook][$hook_type],
                  $arg_name => $registry[$base_hook][$arg_name],
                  'base hook' => $base_hook,
                  'type' => $registry[$base_hook]['type'],
                  'preprocess functions' => array(),
                  'process functions' => array(),
                );
                if (isset($registry[$base_hook]['path'])) {
                  $registry[$hook]['path'] = $registry[$base_hook]['path'];
                }
                if (isset($registry[$base_hook]['theme path'])) {
                  $registry[$hook]['theme path'] = $registry[$base_hook]['theme path'];
                }
              }
            }

            // If the hook exists, merge in the functions. Otherwise ignore it
            // since there was no base hook found and a new implementation
            // could not be created.
            if (isset($registry[$hook])) {
              $registry[$hook] = drupal_array_merge_deep($registry[$hook], array(
                $phase_key => array($match),
              ));

              // Due to how theme() functions, if a base hook implements
              // preprocess or process functions, then the base hook info is
              // used to invoke the necessary phase functions instead of the
              // suggestion hook info. To get around this, a helper function
              // must be appended to the base hook info so it can call the
              // theme suggestion implementation's phase function.
              $function = '_bootstrap_' . $phase . '_theme_suggestion';
              if (!in_array($function, $registry[$base_hook][$phase_key])) {
                $registry[$base_hook][$phase_key][] = $function;
              }
            }
          }
        }
      }
    }
  }
}

/**
 * Performance gain.
 *
 * Do not remove from 7.x. This function is not available in every core version.
 *
 * @see https://www.drupal.org/node/2339447
 */
if (!function_exists('drupal_group_functions_by_prefix')) {
  /**
   * Group all user functions by word before first underscore.
   *
   * @return array
   *   Functions grouped by the first prefix.
   */
  function drupal_group_functions_by_prefix() {
    $functions = get_defined_functions();
    $grouped_functions = array();

    // Splitting user defined functions into groups by the first prefix.
    foreach ($functions['user'] as $function) {
      list($first_prefix,) = explode('_', $function, 2);
      $grouped_functions[$first_prefix][] = $function;
    }

    return $grouped_functions;
  }
}

/**
 * @} End of "addtogroup registry".
 */
