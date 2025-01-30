<?php

/**
 * @file
 * List of common helper functions for use in Drupal Bootstrap based themes.
 */

/**
 * @defgroup utility Utilities
 *
 * List of common helper functions for use in Drupal Bootstrap based themes.
 *
 * @{
 */

define('BOOTSTRAP_VERSION_MAJOR', 3);
define('BOOTSTRAP_VERSION_MINOR', 4);
define('BOOTSTRAP_VERSION_PATCH', 1);
define('BOOTSTRAP_VERSION', BOOTSTRAP_VERSION_MAJOR . '.' . BOOTSTRAP_VERSION_MINOR . '.' . BOOTSTRAP_VERSION_PATCH);

/**
 * Converts an element description into a tooltip based on certain criteria.
 *
 * @param array $element
 *   An element render array, passed by reference.
 * @param array $target
 *   The target element render array the tooltip is to be attached to, passed
 *   by reference. If not set, it will default to the $element passed.
 * @param bool $input_only
 *   Toggle determining whether or not to only convert input elements.
 * @param int $length
 *   The length of characters to determine if description is "simple".
 */
function bootstrap_element_smart_description(array &$element, array &$target = NULL, $input_only = TRUE, $length = NULL) {
  // Determine if tooltips are enabled.
  static $enabled;
  if (!isset($enabled)) {
    $enabled = bootstrap_setting('tooltip_enabled') && bootstrap_setting('forms_smart_descriptions');
  }

  // Immediately return if "simple" tooltip descriptions are not enabled.
  if (!$enabled) {
    return;
  }

  // Allow a different element to attach the tooltip.
  if (!isset($target)) {
    $target = &$element;
  }

  // Retrieve the length limit for smart descriptions.
  if (!isset($length)) {
    $length = (int) bootstrap_setting('forms_smart_descriptions_limit');
    // Disable length checking by setting it to FALSE if empty.
    if (empty($length)) {
      $length = FALSE;
    }
  }

  // Retrieve the allowed tags for smart descriptions. This is primarily used
  // for display purposes only (i.e. non-UI/UX related elements that wouldn't
  // require a user to "click", like a link).
  $allowed_tags = array_filter(array_unique(array_map('trim', explode(',', bootstrap_setting('forms_smart_descriptions_allowed_tags') . ''))));

  // Disable length checking by setting it to FALSE if empty.
  if (empty($allowed_tags)) {
    $allowed_tags = FALSE;
  }

  $html = FALSE;
  $type = !empty($element['#type']) ? $element['#type'] : FALSE;

  // Return if element or target shouldn't have "simple" tooltip descriptions.
  if (($input_only && !isset($target['#input']))
    // Ignore text_format elements.
    // @see https://www.drupal.org/node/2478339
    //    || $type === 'text_format'

    // Ignore if the actual element has no #description set.
    || empty($element['#description'])

    // Ignore if the target element already has a "data-toggle" attribute set.
    || !empty($target['#attributes']['data-toggle'])

    // Ignore if the target element is #disabled.
    || isset($target['#disabled'])

    // Ignore if either the actual element or target element has an explicit
    // #smart_description property set to FALSE.
    || (isset($element['#smart_description']) && !$element['#smart_description'])
    || (isset($target['#smart_description']) && !$target['#smart_description'])

    // Ignore if the description is not "simple".
    || !_bootstrap_is_simple_string($element['#description'], $length, $allowed_tags, $html)
  ) {
    // Set the both the actual element and the target element
    // #smart_description property to FALSE.
    $element['#smart_description'] = FALSE;
    $target['#smart_description'] = FALSE;
    return;
  }

  // Default property (on the element itself).
  $property = 'attributes';

  // Add the tooltip to the #label_attributes property for 'checkbox'
  // and 'radio' elements.
  if ($type === 'checkbox' || $type === 'radio') {
    $property = 'label_attributes';
  }
  // Add the tooltip to the #wrapper_attributes property for 'checkboxes'
  // and 'radios' elements.
  elseif ($type === 'checkboxes' || $type === 'radios') {
    $property = 'wrapper_attributes';
  }
  // Add the tooltip to the #input_group_attributes property for elements
  // that have valid input groups set.
  elseif ((!empty($element['#field_prefix']) || !empty($element['#field_suffix'])) && (!empty($element['#input_group']) || !empty($element['#input_group_button']))) {
    $property = 'input_group_attributes';
  }

  // Retrieve the proper attributes array.
  $attributes = &_bootstrap_get_attributes($target, $property);

  // Set the tooltip attributes.
  $attributes['title'] = $allowed_tags !== FALSE ? filter_xss($element['#description'], $allowed_tags) : $element['#description'];
  $attributes['data-toggle'] = 'tooltip';
  if ($html || $allowed_tags === FALSE) {
    $attributes['data-html'] = 'true';
  }

  // Remove the element description so it isn't (re-)rendered later.
  unset($element['#description']);
}

/**
 * Retrieves a plugin that uses backported CDN Provider logic from 8.x-3.x.
 *
 * @param string $theme
 *   The name of a given theme; defaults to the currently active theme.
 *
 * @return \Drupal\bootstrap\Backport\Plugin\Provider\ProviderBase|false
 *   A CDN Provider instance or FALSE if provider cannot use backported code.
 */
function _bootstrap_backport_cdn_provider($theme = NULL, $provider = NULL) {
  /** @var \Drupal\bootstrap\Backport\Plugin\Provider\ProviderBase[] $providers */
  static $providers = array();

  // If no key is given, use the current theme if we can determine it.
  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  if (!isset($provider)) {
    $provider = bootstrap_setting('cdn_provider', $theme);
  }

  if (!isset($providers[$theme][$provider])) {
    $providers[$theme][$provider]  = FALSE;
    if (bootstrap_setting('cdn_use_backported_code', $theme, 'bootstrap', TRUE)) {
      if ($provider === 'jsdelivr') {
        require_once __DIR__ . '/cdn/ProviderBase.php';
        require_once __DIR__ . '/cdn/JsDelivr.php';
        $providers[$theme][$provider] = new \Drupal\bootstrap\Backport\Plugin\Provider\JsDelivr();
      }
      elseif ($provider === 'custom') {
        require_once __DIR__ . '/cdn/ProviderBase.php';
        require_once __DIR__ . '/cdn/Custom.php';
        $providers[$theme][$provider] = new \Drupal\bootstrap\Backport\Plugin\Provider\Custom();
      }
    }
  }

  return $providers[$theme][$provider];
}

/**
 * Retrieves CDN assets for the active provider, if any.
 *
 * @param string|array $type
 *   The type of asset to retrieve: "css" or "js", defaults to an array
 *   array containing both if not set.
 * @param string $provider
 *   The name of a specific CDN provider to use, defaults to the active provider
 *   set in the theme settings.
 * @param string $theme
 *   The name of a specific theme the settings should be retrieved from,
 *   defaults to the active theme.
 *
 * @return array
 *   If $type is a string or an array with only one (1) item in it, the assets
 *   are returned as an indexed array of files. Otherwise, an associative array
 *   is returned keyed by the type.
 */
function bootstrap_get_cdn_assets($type = NULL, $provider = NULL, $theme = NULL) {
  bootstrap_include('bootstrap', 'includes/cdn.inc');

  $original_type = $type;
  $assets = array();
  $types = array();

  // If no type is set, return all CSS and JS.
  if (!isset($type)) {
    $types = array('css', 'js');
  }
  elseif (isset($type)) {
    if (!is_array($type)) {
      $type = array($type);
    }
    $types = $type;
  }

  // Ensure default arrays exist for the requested types.
  foreach ($types as $type) {
    $assets[$type] = array();
  }

  // Retrieve the CDN provider from the theme.
  if (!isset($provider)) {
    $provider = bootstrap_setting('cdn_provider', $theme);
  }

  // Immediately return if there's no provider set.
  if (empty($provider)) {
    return array();
  }

  // Check if the backported 8.x-3.x jsDelivr code should be used.
  if ($provider = _bootstrap_backport_cdn_provider($theme, $provider)) {
    $framework = array();
    $provider->alterFrameworkLibrary($framework);
    $assets = array_map(function ($data) {
      $assets = array();
      foreach ($data as $info) {
        if (isset($info['data'])) {
          $assets[] = $info['data'];
        }
      }
      return $assets;
    }, array_intersect_key($framework, array_flip($types)));
  }
  // Otherwise, use the legacy CDN provider code.
  else {
    if (!empty($provider) && ($data = bootstrap_cdn_provider($provider))) {
      // Alter the assets based on provider.
      $function = 'bootstrap_bootstrap_cdn_provider_' . $provider . '_assets_alter';
      if (function_exists($function)) {
        $function($data, $theme);
      }
      // Iterate over each type.
      foreach ($types as $type) {
        if (variable_get("preprocess_$type", FALSE) && !empty($data['min'][$type])) {
          $assets[$type] = $data['min'][$type];
        }
        elseif (!empty($data[$type])) {
          $assets[$type] = $data[$type];
        }
      }
    }  }

  return is_string($original_type) ? $assets[$original_type] : $assets;
}

/**
 * Return information from the .info file of a theme (and possible base themes).
 *
 * @param string $theme_key
 *   The machine name of the theme.
 * @param string $key
 *   The key name of the item to return from the .info file. This value can
 *   include "][" to automatically attempt to traverse any arrays.
 * @param bool $base_themes
 *   Recursively search base themes, defaults to TRUE.
 *
 * @return string|array|false
 *   A string or array depending on the type of value and if a base theme also
 *   contains the same $key, FALSE if no $key is found.
 */
function bootstrap_get_theme_info($theme_key = NULL, $key = NULL, $base_themes = TRUE) {
  // If no $theme_key is given, use the current theme if we can determine it.
  if (!isset($theme_key)) {
    $theme_key = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : FALSE;
  }
  if ($theme_key) {
    $themes = list_themes();
    if (!empty($themes[$theme_key])) {
      $theme = $themes[$theme_key];
      // If a key name was specified, return just that array.
      if ($key) {
        $value = FALSE;
        // Recursively add base theme values.
        if ($base_themes && isset($theme->base_themes)) {
          foreach (array_keys($theme->base_themes) as $base_theme) {
            $value = bootstrap_get_theme_info($base_theme, $key);
          }
        }
        if (!empty($themes[$theme_key])) {
          $info = $themes[$theme_key]->info;
          // Allow array traversal.
          $keys = explode('][', $key);
          foreach ($keys as $parent) {
            if (isset($info[$parent])) {
              $info = $info[$parent];
            }
            else {
              $info = FALSE;
            }
          }
          if (is_array($value)) {
            if (!empty($info)) {
              if (!is_array($info)) {
                $info = array($info);
              }
              $value = drupal_array_merge_deep($value, $info);
            }
          }
          else {
            if (!empty($info)) {
              if (empty($value)) {
                $value = $info;
              }
              else {
                if (!is_array($value)) {
                  $value = array($value);
                }
                if (!is_array($info)) {
                  $info = array($info);
                }
                $value = drupal_array_merge_deep($value, $info);
              }
            }
          }
        }
        return $value;
      }
      // If no info $key was specified, just return the entire info array.
      return $theme->info;
    }
  }
  return FALSE;
}

/**
 * Includes a theme file.
 *
 * @param string $theme
 *   Name of the theme to use for base path.
 * @param string $path
 *   Path relative to $theme.
 *
 * @return string|false
 *   The absolute path to the include file or FALSE if it doesn't exist.
 */
function bootstrap_include($theme, $path) {
  static $included = array();
  static $themes = array();

  if (!isset($themes[$theme])) {
    $themes[$theme] = drupal_get_path('theme', $theme);
  }

  if (!isset($included["$theme:$path"])) {
    $file = DRUPAL_ROOT . '/' . $themes[$theme] . '/' . $path;
    if (file_exists($file)) {
      include_once $file;
    }
    else {
      $file = FALSE;
    }
    $included["$theme:$path"] = $file;
  }

  return $included["$theme:$path"];
}

/**
 * Retrieves a setting for the current theme or for a given theme.
 *
 * This is a wrapper for theme_get_setting(), ensuring to use deprecated
 * setting values instead.
 *
 * @param string $name
 *   The name of the setting to be retrieved.
 * @param string $theme
 *   The name of a given theme; defaults to the currently active theme.
 * @param string $prefix
 *   The prefix used on the $name of the setting, this will be appended with
 *   "_" automatically if set.
 * @param mixed $default
 *   The default value to return if setting doesn't exist or is not set.
 *
 * @return mixed
 *   The value of the requested setting, NULL if the setting does not exist.
 *
 * @see theme_get_setting()
 *
 * @todo Refactor in 7.x-4.x and get rid of the deprecated settings.
 */
function bootstrap_setting($name, $theme = NULL, $prefix = 'bootstrap', $default = NULL) {
  $prefix = !empty($prefix) ? $prefix . '_' : '';
  $setting = theme_get_setting($prefix . $name, $theme);
  switch ($prefix . $name) {
    case 'bootstrap_cdn_provider':
      $deprecated = theme_get_setting('bootstrap_cdn', $theme);
      if (isset($deprecated)) {
        $setting = empty($deprecated) ? '' : 'jsdelivr';
      }
      break;

    case 'bootstrap_cdn_jsdelivr_version':
      $deprecated = theme_get_setting('bootstrap_cdn', $theme);
      if (isset($deprecated)) {
        $setting = empty($deprecated) ? BOOTSTRAP_VERSION : $deprecated;
      }
      break;

    case 'bootstrap_cdn_jsdelivr_theme':
      $deprecated = theme_get_setting('bootstrap_bootswatch', $theme);
      if (isset($deprecated)) {
        $setting = empty($deprecated) ? 'bootstrap' : $deprecated;
      }
      break;

    case 'bootstrap_forms_smart_descriptions':
      $deprecated = theme_get_setting('bootstrap_tooltip_descriptions', $theme);
      if (isset($deprecated)) {
        $setting = (int) !empty($deprecated);
      }
      break;

    case 'bootstrap_forms_smart_descriptions_limit':
      $deprecated = theme_get_setting('bootstrap_tooltip_descriptions_length', $theme);
      if (isset($deprecated)) {
        $setting = (int) !empty($deprecated);
      }
      break;

  }
  return isset($setting) ? $setting : $default;
}

/**
 * Sets a theme setting.
 *
 * @param string $name
 *   The name of the setting to set.
 * @param mixed $value
 *   The value of the setting to set.
 * @param string $prefix
 *   The prefix used on the $name of the setting, this will be appended with
 *   "_" automatically if set.
 * @param string $theme
 *   The name of a given theme; defaults to the currently active theme.
 */
function _bootstrap_set_setting($name, $value, $prefix = 'bootstrap', $theme = NULL) {
  // If no key is given, use the current theme if we can determine it.
  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  // Trigger at least once so it can populate defaults.
  theme_get_setting('', $theme);

  // Retrieve the cached settings.
  $cache = &drupal_static('theme_get_setting', array());
  $settings = $cache[$theme];

  // Set the value.
  $prefix = !empty($prefix) ? $prefix . '_' : '';
  $settings["$prefix$name"] = $value;

  // Set the settings.
  variable_set('theme_' . $theme . '_settings', $settings);
}

/**
 * Retrieves an element's "attributes" array.
 *
 * @param array $element
 *   The individual renderable array element. It is possible to also pass the
 *   $variables parameter in [pre]process functions and it will logically
 *   determine the correct path to that particular theme hook's attribute array.
 *   Passed by reference.
 * @param string $property
 *   Determines which attributes array to retrieve. By default, this is the
 *   normal attributes, but can be "wrapper_attributes" or
 *   "input_group_attributes".
 *
 * @return array
 *   The attributes array. Passed by reference.
 */
function &_bootstrap_get_attributes(array &$element, $property = 'attributes') {
  // Attempt to retrieve a renderable element attributes first.
  if (
    isset($element['#type']) ||
    isset($element['#theme']) ||
    isset($element['#pre_render']) ||
    isset($element['#markup']) ||
    isset($element['#theme_wrappers']) ||
    isset($element["#$property"])
  ) {
    if (!isset($element["#$property"])) {
      $element["#$property"] = array();
    }
    return $element["#$property"];
  }
  // Treat $element as if it were a [pre]process function $variables parameter
  // and look for a renderable "element".
  elseif (isset($element['element'])) {
    if (!isset($element['element']["#$property"])) {
      $element['element']["#$property"] = array();
    }
    return $element['element']["#$property"];
  }

  // If all else fails, create (if needed) a default "attributes" array. This
  // will, at the very least, either work or cause an error that can be tracked.
  if (!isset($element[$property])) {
    $element[$property] = array();
  }

  return $element[$property];
}

/**
 * Retrieves an element's "class" array.
 *
 * @param array $element
 *   The individual renderable array element. It is possible to also pass the
 *   $variables parameter in [pre]process functions and it will logically
 *   determine the correct path to that particular theme hook's classes array.
 *   Passed by reference.
 * @param string $property
 *   Determines which attributes array to retrieve. By default, this is the
 *   normal attributes, but can be "wrapper_attributes" or
 *   "input_group_attributes".
 *
 * @return array
 *   The classes array. Passed by reference.
 */
function &_bootstrap_get_classes(array &$element, $property = 'attributes') {
  $attributes = &_bootstrap_get_attributes($element, $property);

  if (!isset($attributes['class'])) {
    $attributes['class'] = array();
  }
  // Contrib modules have a very bad habit of frequently adding classes as
  // strings, convert them to a proper array.
  // @see https://www.drupal.org/node/2269653
  elseif (!is_array($attributes['class'])) {
    $attributes['class'] = explode(' ', $attributes['class']);
  }

  // Ensure classes are not duplicated.
  $attributes['class'] = array_unique($attributes['class']);
  return $attributes['class'];
}

/**
 * Adds a class to an element's render array.
 *
 * @param string|array $class
 *   An individual class or an array of classes to add.
 * @param array $element
 *   The individual renderable array element. It is possible to also pass the
 *   $variables parameter in [pre]process functions and it will logically
 *   determine the correct path to that particular theme hook's classes array.
 *   Passed by reference.
 * @param string $property
 *   Determines which attributes array to retrieve. By default, this is the
 *   normal attributes, but can be "wrapper_attributes" or
 *   "input_group_attributes".
 */
function _bootstrap_add_class($class, array &$element, $property = 'attributes') {
  // Retrieve the element's classes.
  $classes = &_bootstrap_get_classes($element, $property);

  // Convert the class to an array.
  if (!is_array($class)) {
    $class = array($class);
  }

  // Iterate over all classes to add.
  foreach ($class as $_class) {
    // Ensure the class to add does not yet already exist.
    if (!in_array($_class, $classes)) {
      $classes[] = $_class;
    }
  }
}

/**
 * Removes a class from an element's render array.
 *
 * @param string|array $class
 *   An individual class or an array of classes to remove.
 * @param array $element
 *   The individual renderable array element. It is possible to also pass the
 *   $variables parameter in [pre]process functions and it will logically
 *   determine the correct path to that particular theme hook's classes array.
 *   Passed by reference.
 * @param string $property
 *   Determines which attributes array to retrieve. By default, this is the
 *   normal attributes, but can be "wrapper_attributes" or
 *   "input_group_attributes".
 */
function _bootstrap_remove_class($class, array &$element, $property = 'attributes') {
  // Retrieve the element's classes.
  $classes = &_bootstrap_get_classes($element, $property);

  // Convert the class to an array.
  if (!is_array($class)) {
    $class = array($class);
  }

  // Iterate over all classes to add.
  foreach ($class as $_class) {
    $key = array_search($_class, $classes);
    if ($key !== FALSE) {
      unset($classes[$key]);
    }
  }
}

/**
 * Returns a list of base themes for active or provided theme.
 *
 * @param string $theme_key
 *   The machine name of the theme to check, if not set the active theme name
 *   will be used.
 * @param bool $include_theme_key
 *   Whether to append the returned list with $theme_key.
 *
 * @return array
 *   An indexed array of base themes.
 */
function _bootstrap_get_base_themes($theme_key = NULL, $include_theme_key = FALSE) {
  static $themes;
  if (!isset($theme_key)) {
    $theme_key = $GLOBALS['theme_key'];
  }
  if (!isset($themes[$theme_key])) {
    $themes[$theme_key] = array_unique(array_filter((array) bootstrap_get_theme_info($theme_key, 'base theme')));
  }
  if ($include_theme_key) {
    $themes[$theme_key][] = $theme_key;
  }
  return $themes[$theme_key];
}

/**
 * Retrieves the full base/sub-theme ancestry of a theme.
 *
 * @param string $theme_key
 *   The machine name of the theme to check, if not set the active theme name
 *   will be used.
 * @param bool $reverse
 *   Whether or not to return the array of themes in reverse order, where the
 *   active theme is the first entry.
 *
 * @return string[]
 *   An array of theme names.
 */
function _bootstrap_get_ancestry($theme_key = NULL, $reverse = FALSE) {
  $ancestry = _bootstrap_get_base_themes($theme_key, TRUE);
  return $reverse ? array_reverse($ancestry) : $ancestry;
}

/**
 * Wrapper for the core file_scan_directory() function.
 *
 * Finds all files that match a given mask in a given directory and then caches
 * the results. A general site cache clear will force new scans to be initiated
 * for already cached directories.
 *
 * @param string $dir
 *   The base directory or URI to scan, without trailing slash.
 * @param string $mask
 *   The preg_match() regular expression of the files to find.
 * @param array $options
 *   Additional options to pass to file_scan_directory().
 *
 * @return array
 *   An associative array (keyed on the chosen key) of objects with 'uri',
 *   'filename', and 'name' members corresponding to the matching files.
 *
 * @see file_scan_directory()
 */
function _bootstrap_file_scan_directory($dir, $mask, array $options = array()) {
  $files = &drupal_static(__FUNCTION__, array());

  // Generate a unique cache identifier for all parameters passed as a change
  // in any of them would return different results.
  $cid = 'theme_registry:bootstrap:files:' . drupal_hash_base64(serialize(func_get_args()));

  // Load from DB cache or scan filesystem if files are not statically cached.
  if (!isset($files[$cid])) {
    if (($cache = cache_get($cid)) && isset($cache->data)) {
      $files[$cid] = $cache->data;
    }
    else {
      $files[$cid] = file_scan_directory($dir, $mask, $options);
      cache_set($cid, $files[$cid]);
    }
  }

  return $files[$cid];
}

/**
 * Filters HTML to prevent cross-site-scripting (XSS) vulnerabilities.
 *
 * Very similar to core's filter_xss(). It does, however, include the addition
 * of the "span", "div" and "i" elements which are commonly used in Bootstrap.
 *
 * @param string $string
 *   The string with raw HTML in it. It will be stripped of everything that can
 *   cause an XSS attack.
 * @param array $allowed_tags
 *   An array of allowed tags.
 *
 * @return string
 *   An XSS safe version of $string, or an empty string if $string is not
 *   valid UTF-8.
 *
 * @see filter_xss()
 * @see filter_xss_admin()
 *
 * @deprecated Use filter_xss() or filter_xss_admin() instead.
 * Will be removed in a future release.
 */
function _bootstrap_filter_xss($string, array $allowed_tags = NULL) {
  if (is_null($allowed_tags)) {
    $allowed_tags = array(
      // Inline elements.
      'a',
      'cite',
      'em',
      'i',
      'span',
      'strong',

      // Block elements.
      'blockquote',
      'code',
      'div',
      'ul',
      'ol',
      'li',
      'dl',
      'dt',
      'dd',
    );
  }
  return filter_xss($string, $allowed_tags);
}

/**
 * Returns a list of available Bootstrap Glyphicons.
 *
 * @param string $version
 *   The specific version of glyphicons to return. If not set, the latest
 *   BOOTSTRAP_VERSION will be used.
 *
 * @return array
 *   An associative array of icons keyed by their classes.
 */
function _bootstrap_glyphicons($version = NULL) {
  static $versions;
  if (!isset($versions)) {
    $versions = array();
    $versions['3.0.0'] = array(
      // Class => Name.
      'glyphicon-adjust' => 'adjust',
      'glyphicon-align-center' => 'align-center',
      'glyphicon-align-justify' => 'align-justify',
      'glyphicon-align-left' => 'align-left',
      'glyphicon-align-right' => 'align-right',
      'glyphicon-arrow-down' => 'arrow-down',
      'glyphicon-arrow-left' => 'arrow-left',
      'glyphicon-arrow-right' => 'arrow-right',
      'glyphicon-arrow-up' => 'arrow-up',
      'glyphicon-asterisk' => 'asterisk',
      'glyphicon-backward' => 'backward',
      'glyphicon-ban-circle' => 'ban-circle',
      'glyphicon-barcode' => 'barcode',
      'glyphicon-bell' => 'bell',
      'glyphicon-bold' => 'bold',
      'glyphicon-book' => 'book',
      'glyphicon-bookmark' => 'bookmark',
      'glyphicon-briefcase' => 'briefcase',
      'glyphicon-bullhorn' => 'bullhorn',
      'glyphicon-calendar' => 'calendar',
      'glyphicon-camera' => 'camera',
      'glyphicon-certificate' => 'certificate',
      'glyphicon-check' => 'check',
      'glyphicon-chevron-down' => 'chevron-down',
      'glyphicon-chevron-left' => 'chevron-left',
      'glyphicon-chevron-right' => 'chevron-right',
      'glyphicon-chevron-up' => 'chevron-up',
      'glyphicon-circle-arrow-down' => 'circle-arrow-down',
      'glyphicon-circle-arrow-left' => 'circle-arrow-left',
      'glyphicon-circle-arrow-right' => 'circle-arrow-right',
      'glyphicon-circle-arrow-up' => 'circle-arrow-up',
      'glyphicon-cloud' => 'cloud',
      'glyphicon-cloud-download' => 'cloud-download',
      'glyphicon-cloud-upload' => 'cloud-upload',
      'glyphicon-cog' => 'cog',
      'glyphicon-collapse-down' => 'collapse-down',
      'glyphicon-collapse-up' => 'collapse-up',
      'glyphicon-comment' => 'comment',
      'glyphicon-compressed' => 'compressed',
      'glyphicon-copyright-mark' => 'copyright-mark',
      'glyphicon-credit-card' => 'credit-card',
      'glyphicon-cutlery' => 'cutlery',
      'glyphicon-dashboard' => 'dashboard',
      'glyphicon-download' => 'download',
      'glyphicon-download-alt' => 'download-alt',
      'glyphicon-earphone' => 'earphone',
      'glyphicon-edit' => 'edit',
      'glyphicon-eject' => 'eject',
      'glyphicon-envelope' => 'envelope',
      'glyphicon-euro' => 'euro',
      'glyphicon-exclamation-sign' => 'exclamation-sign',
      'glyphicon-expand' => 'expand',
      'glyphicon-export' => 'export',
      'glyphicon-eye-close' => 'eye-close',
      'glyphicon-eye-open' => 'eye-open',
      'glyphicon-facetime-video' => 'facetime-video',
      'glyphicon-fast-backward' => 'fast-backward',
      'glyphicon-fast-forward' => 'fast-forward',
      'glyphicon-file' => 'file',
      'glyphicon-film' => 'film',
      'glyphicon-filter' => 'filter',
      'glyphicon-fire' => 'fire',
      'glyphicon-flag' => 'flag',
      'glyphicon-flash' => 'flash',
      'glyphicon-floppy-disk' => 'floppy-disk',
      'glyphicon-floppy-open' => 'floppy-open',
      'glyphicon-floppy-remove' => 'floppy-remove',
      'glyphicon-floppy-save' => 'floppy-save',
      'glyphicon-floppy-saved' => 'floppy-saved',
      'glyphicon-folder-close' => 'folder-close',
      'glyphicon-folder-open' => 'folder-open',
      'glyphicon-font' => 'font',
      'glyphicon-forward' => 'forward',
      'glyphicon-fullscreen' => 'fullscreen',
      'glyphicon-gbp' => 'gbp',
      'glyphicon-gift' => 'gift',
      'glyphicon-glass' => 'glass',
      'glyphicon-globe' => 'globe',
      'glyphicon-hand-down' => 'hand-down',
      'glyphicon-hand-left' => 'hand-left',
      'glyphicon-hand-right' => 'hand-right',
      'glyphicon-hand-up' => 'hand-up',
      'glyphicon-hd-video' => 'hd-video',
      'glyphicon-hdd' => 'hdd',
      'glyphicon-header' => 'header',
      'glyphicon-headphones' => 'headphones',
      'glyphicon-heart' => 'heart',
      'glyphicon-heart-empty' => 'heart-empty',
      'glyphicon-home' => 'home',
      'glyphicon-import' => 'import',
      'glyphicon-inbox' => 'inbox',
      'glyphicon-indent-left' => 'indent-left',
      'glyphicon-indent-right' => 'indent-right',
      'glyphicon-info-sign' => 'info-sign',
      'glyphicon-italic' => 'italic',
      'glyphicon-leaf' => 'leaf',
      'glyphicon-link' => 'link',
      'glyphicon-list' => 'list',
      'glyphicon-list-alt' => 'list-alt',
      'glyphicon-lock' => 'lock',
      'glyphicon-log-in' => 'log-in',
      'glyphicon-log-out' => 'log-out',
      'glyphicon-magnet' => 'magnet',
      'glyphicon-map-marker' => 'map-marker',
      'glyphicon-minus' => 'minus',
      'glyphicon-minus-sign' => 'minus-sign',
      'glyphicon-move' => 'move',
      'glyphicon-music' => 'music',
      'glyphicon-new-window' => 'new-window',
      'glyphicon-off' => 'off',
      'glyphicon-ok' => 'ok',
      'glyphicon-ok-circle' => 'ok-circle',
      'glyphicon-ok-sign' => 'ok-sign',
      'glyphicon-open' => 'open',
      'glyphicon-paperclip' => 'paperclip',
      'glyphicon-pause' => 'pause',
      'glyphicon-pencil' => 'pencil',
      'glyphicon-phone' => 'phone',
      'glyphicon-phone-alt' => 'phone-alt',
      'glyphicon-picture' => 'picture',
      'glyphicon-plane' => 'plane',
      'glyphicon-play' => 'play',
      'glyphicon-play-circle' => 'play-circle',
      'glyphicon-plus' => 'plus',
      'glyphicon-plus-sign' => 'plus-sign',
      'glyphicon-print' => 'print',
      'glyphicon-pushpin' => 'pushpin',
      'glyphicon-qrcode' => 'qrcode',
      'glyphicon-question-sign' => 'question-sign',
      'glyphicon-random' => 'random',
      'glyphicon-record' => 'record',
      'glyphicon-refresh' => 'refresh',
      'glyphicon-registration-mark' => 'registration-mark',
      'glyphicon-remove' => 'remove',
      'glyphicon-remove-circle' => 'remove-circle',
      'glyphicon-remove-sign' => 'remove-sign',
      'glyphicon-repeat' => 'repeat',
      'glyphicon-resize-full' => 'resize-full',
      'glyphicon-resize-horizontal' => 'resize-horizontal',
      'glyphicon-resize-small' => 'resize-small',
      'glyphicon-resize-vertical' => 'resize-vertical',
      'glyphicon-retweet' => 'retweet',
      'glyphicon-road' => 'road',
      'glyphicon-save' => 'save',
      'glyphicon-saved' => 'saved',
      'glyphicon-screenshot' => 'screenshot',
      'glyphicon-sd-video' => 'sd-video',
      'glyphicon-search' => 'search',
      'glyphicon-send' => 'send',
      'glyphicon-share' => 'share',
      'glyphicon-share-alt' => 'share-alt',
      'glyphicon-shopping-cart' => 'shopping-cart',
      'glyphicon-signal' => 'signal',
      'glyphicon-sort' => 'sort',
      'glyphicon-sort-by-alphabet' => 'sort-by-alphabet',
      'glyphicon-sort-by-alphabet-alt' => 'sort-by-alphabet-alt',
      'glyphicon-sort-by-attributes' => 'sort-by-attributes',
      'glyphicon-sort-by-attributes-alt' => 'sort-by-attributes-alt',
      'glyphicon-sort-by-order' => 'sort-by-order',
      'glyphicon-sort-by-order-alt' => 'sort-by-order-alt',
      'glyphicon-sound-5-1' => 'sound-5-1',
      'glyphicon-sound-6-1' => 'sound-6-1',
      'glyphicon-sound-7-1' => 'sound-7-1',
      'glyphicon-sound-dolby' => 'sound-dolby',
      'glyphicon-sound-stereo' => 'sound-stereo',
      'glyphicon-star' => 'star',
      'glyphicon-star-empty' => 'star-empty',
      'glyphicon-stats' => 'stats',
      'glyphicon-step-backward' => 'step-backward',
      'glyphicon-step-forward' => 'step-forward',
      'glyphicon-stop' => 'stop',
      'glyphicon-subtitles' => 'subtitles',
      'glyphicon-tag' => 'tag',
      'glyphicon-tags' => 'tags',
      'glyphicon-tasks' => 'tasks',
      'glyphicon-text-height' => 'text-height',
      'glyphicon-text-width' => 'text-width',
      'glyphicon-th' => 'th',
      'glyphicon-th-large' => 'th-large',
      'glyphicon-th-list' => 'th-list',
      'glyphicon-thumbs-down' => 'thumbs-down',
      'glyphicon-thumbs-up' => 'thumbs-up',
      'glyphicon-time' => 'time',
      'glyphicon-tint' => 'tint',
      'glyphicon-tower' => 'tower',
      'glyphicon-transfer' => 'transfer',
      'glyphicon-trash' => 'trash',
      'glyphicon-tree-conifer' => 'tree-conifer',
      'glyphicon-tree-deciduous' => 'tree-deciduous',
      'glyphicon-unchecked' => 'unchecked',
      'glyphicon-upload' => 'upload',
      'glyphicon-usd' => 'usd',
      'glyphicon-user' => 'user',
      'glyphicon-volume-down' => 'volume-down',
      'glyphicon-volume-off' => 'volume-off',
      'glyphicon-volume-up' => 'volume-up',
      'glyphicon-warning-sign' => 'warning-sign',
      'glyphicon-wrench' => 'wrench',
      'glyphicon-zoom-in' => 'zoom-in',
      'glyphicon-zoom-out' => 'zoom-out',
    );
    $versions['3.0.1'] = $versions['3.0.0'];
    $versions['3.0.2'] = $versions['3.0.1'];
    $versions['3.0.3'] = $versions['3.0.2'];
    $versions['3.1.0'] = $versions['3.0.3'];
    $versions['3.1.1'] = $versions['3.1.0'];
    $versions['3.2.0'] = $versions['3.1.1'];
    $versions['3.3.0'] = array_merge($versions['3.2.0'], array(
      'glyphicon-eur' => 'eur',
    ));
    $versions['3.3.1'] = $versions['3.3.0'];
    $versions['3.3.2'] = array_merge($versions['3.3.1'], array(
      'glyphicon-alert' => 'alert',
      'glyphicon-apple' => 'apple',
      'glyphicon-baby-formula' => 'baby-formula',
      'glyphicon-bed' => 'bed',
      'glyphicon-bishop' => 'bishop',
      'glyphicon-bitcoin' => 'bitcoin',
      'glyphicon-blackboard' => 'blackboard',
      'glyphicon-cd' => 'cd',
      'glyphicon-console' => 'console',
      'glyphicon-copy' => 'copy',
      'glyphicon-duplicate' => 'duplicate',
      'glyphicon-education' => 'education',
      'glyphicon-equalizer' => 'equalizer',
      'glyphicon-erase' => 'erase',
      'glyphicon-grain' => 'grain',
      'glyphicon-hourglass' => 'hourglass',
      'glyphicon-ice-lolly' => 'ice-lolly',
      'glyphicon-ice-lolly-tasted' => 'ice-lolly-tasted',
      'glyphicon-king' => 'king',
      'glyphicon-knight' => 'knight',
      'glyphicon-lamp' => 'lamp',
      'glyphicon-level-up' => 'level-up',
      'glyphicon-menu-down' => 'menu-down',
      'glyphicon-menu-hamburger' => 'menu-hamburger',
      'glyphicon-menu-left' => 'menu-left',
      'glyphicon-menu-right' => 'menu-right',
      'glyphicon-menu-up' => 'menu-up',
      'glyphicon-modal-window' => 'modal-window',
      'glyphicon-object-align-bottom' => 'object-align-bottom',
      'glyphicon-object-align-horizontal' => 'object-align-horizontal',
      'glyphicon-object-align-left' => 'object-align-left',
      'glyphicon-object-align-right' => 'object-align-right',
      'glyphicon-object-align-top' => 'object-align-top',
      'glyphicon-object-align-vertical' => 'object-align-vertical',
      'glyphicon-oil' => 'oil',
      'glyphicon-open-file' => 'open-file',
      'glyphicon-option-horizontal' => 'option-horizontal',
      'glyphicon-option-vertical' => 'option-vertical',
      'glyphicon-paste' => 'paste',
      'glyphicon-pawn' => 'pawn',
      'glyphicon-piggy-bank' => 'piggy-bank',
      'glyphicon-queen' => 'queen',
      'glyphicon-ruble' => 'ruble',
      'glyphicon-save-file' => 'save-file',
      'glyphicon-scale' => 'scale',
      'glyphicon-scissors' => 'scissors',
      'glyphicon-subscript' => 'subscript',
      'glyphicon-sunglasses' => 'sunglasses',
      'glyphicon-superscript' => 'superscript',
      'glyphicon-tent' => 'tent',
      'glyphicon-text-background' => 'text-background',
      'glyphicon-text-color' => 'text-color',
      'glyphicon-text-size' => 'text-size',
      'glyphicon-triangle-bottom' => 'triangle-bottom',
      'glyphicon-triangle-left' => 'triangle-left',
      'glyphicon-triangle-right' => 'triangle-right',
      'glyphicon-triangle-top' => 'triangle-top',
      'glyphicon-yen' => 'yen',
    ));
    $versions['3.3.4'] = array_merge($versions['3.3.2'], array(
      'glyphicon-btc' => 'btc',
      'glyphicon-jpy' => 'jpy',
      'glyphicon-rub' => 'rub',
      'glyphicon-xbt' => 'xbt',
    ));
    $versions['3.3.5'] = $versions['3.3.4'];
    $versions['3.3.6'] = $versions['3.3.5'];
    $versions['3.3.7'] = $versions['3.3.6'];
    $versions['3.4.0'] = $versions['3.3.7'];
    $versions['3.4.1'] = $versions['3.4.0'];
  }

  // Return a specific versions icon set.
  if (isset($version) && isset($versions[$version])) {
    return $versions[$version];
  }

  // Return the latest version.
  return $versions[BOOTSTRAP_VERSION];
}

/**
 * Returns a specific Bootstrap Glyphicon as rendered HTML markup.
 *
 * @param string $name
 *   The icon name, minus the "glyphicon-" prefix.
 * @param string $default
 *   (Optional) The default value to return.
 * @param array $attributes
 *   (Optional) Additional attributes to merge onto the icon.
 *
 * @return string
 *   The HTML markup containing the icon defined by $name, $default value if
 *   icon does not exist or returns empty output for whatever reason.
 */
function _bootstrap_icon($name, $default = NULL, array $attributes = array()) {
  $icon = _bootstrap_glyphicon($name, $default, $attributes);
  return render($icon);
}

/**
 * Returns a specific Bootstrap Glyphicon as a render array.
 *
 * Note: This function was added to keep BC with the former _bootstrap_icon()
 * implementation since it didn't return a render array. It is basically a
 * backport of 8.x-3.x code so the added $attributes parameter can be more
 * easily dealt with.
 *
 * @param string $name
 *   The icon name, minus the "glyphicon-" prefix.
 * @param array|string $default
 *   (Optional) The default render array to use if $name is not available.
 * @param array $attributes
 *   (Optional) Additional attributes to merge onto the icon.
 *
 * @see https://www.drupal.org/project/bootstrap/issues/2844885
 *
 * @return array
 *   The render containing the icon defined by $name, $default value if
 *   icon does not exist or returns NULL if no icon could be rendered.
 */
function _bootstrap_glyphicon($name, $default = array(), array $attributes = array()) {
  $icon = array();

  // Ensure the icon specified is a valid Bootstrap Glyphicon.
  if (_bootstrap_glyphicons_supported() && in_array($name, _bootstrap_glyphicons())) {
    // Attempt to use the Icon API module, if enabled and it generates output.
    if (module_exists('icon')) {
      $icon = array(
        '#theme' => 'icon',
        '#bundle' => 'bootstrap',
        '#icon' => 'glyphicon-' . $name,
        '#attributes' => $attributes,
      );
    }
    else {
      $icon = array(
        '#theme' => 'html_tag',
        '#tag' => 'span',
        '#value' => '',
        '#attributes' => $attributes,
      );

      // Unlike 8.x-3.x, it will be easier to add the classes and aria-hidden
      // attribute afterwards since there is a passed default $attributes
      // parameter and drupal_array_merge_deep() is notorious for not properly
      // merging attributes, especially when dealing with classes.
      _bootstrap_add_class(array('icon', 'glyphicon', 'glyphicon-' . $name), $icon);
      $icon['#attributes']['aria-hidden'] = 'true';
    }
  }

  // Return the icon.
  if (!empty($icon)) {
    return $icon;
  }

  // _bootstrap_icon() may pass NULL as $default. If so, return an empty array.
  return isset($default) ? $default : array();
}

/**
 * Determine whether or not Bootstrap Glyphicons can be used.
 */
function _bootstrap_glyphicons_supported() {
  global $theme;

  // Use the advanced drupal_static() pattern, since this has the potential to
  // be called very often by _bootstrap_icon().
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['supported'] = &drupal_static(__FUNCTION__);
  }

  // Get static data.
  $supported = &$drupal_static_fast['supported'];

  // Retrieve supported themes.
  if (!isset($supported)) {
    $supported = array();

    // Retrieve cached data.
    $cid = 'theme_registry:bootstrap:icon_support';
    if (($cache = cache_get($cid)) && !empty($cache->data)) {
      $supported = $cache->data;
    }
  }

  // Determine active theme support if not yet set.
  if (!isset($supported[$theme])) {
    // Bootstrap based themes are enabled by default to use CDN. Check if
    // that is the case here so no file discovery is necessary. If the active
    // theme does not have this setting, it falls back to the base theme that
    // does.
    $supported[$theme] = !!bootstrap_get_cdn_assets('css', NULL, $theme);

    // CDN not used, iterate over all of the active (base) themes to determine
    // if they contain glyphicon font files.
    if (!$supported[$theme]) {
      foreach (_bootstrap_get_base_themes($theme, TRUE) as $_theme) {
        // Scan the theme for files.
        $fonts = _bootstrap_file_scan_directory(drupal_get_path('theme', $_theme), '/glyphicons-halflings-regular\.(eot|svg|ttf|woff)$/');

        // Fonts found, stop the search.
        if (!empty($fonts)) {
          $supported[$theme] = TRUE;
          break;
        }
      }
    }

    // Cache all supported themes now that this theme is added to the array.
    cache_set($cid, $supported);
  }

  return $supported[$theme];
}

/**
 * Determine whether a specific element is a button.
 *
 * @param array $element
 *   A renderable element.
 *
 * @return bool
 *   TRUE or FALSE.
 */
function _bootstrap_is_button(array $element) {
  return
    !empty($element['#type']) &&
    !empty($element['#value']) && (
      $element['#type'] === 'button' ||
      $element['#type'] === 'submit' ||
      $element['#type'] === 'image_button'
    );
}

/**
 * Adds a specific Bootstrap class to color a button based on its text value.
 *
 * @param array $element
 *   The form element, passed by reference.
 */
function _bootstrap_colorize_button(array &$element) {
  if (_bootstrap_is_button($element)) {
    // Do not add the class if one is already present in the array.
    $button_classes = array(
      'btn-default',
      'btn-primary',
      'btn-success',
      'btn-info',
      'btn-warning',
      'btn-danger',
      'btn-link',
    );
    $class_intersection = array_intersect($button_classes, $element['#attributes']['class']);
    if (empty($class_intersection)) {
      // Get the matched class.
      $class = bootstrap_setting('button_colorize') ? _bootstrap_colorize_text($element['#value']) : FALSE;
      // If no particular class matched, use the default style.
      if (!$class) {
        $class = 'default';
      }
      $element['#attributes']['class'][] = 'btn-' . $class;
    }
  }
}

/**
 * Matches a Bootstrap class based on a string value.
 *
 * @param string $string
 *   The string to match classes against.
 * @param string $default
 *   The default class to return if no match is found.
 *
 * @return string
 *   The Bootstrap class matched against the value of $haystack or $default if
 *   no match could be made.
 */
function _bootstrap_colorize_text($string, $default = '') {
  static $texts;
  if (!isset($texts)) {
    $texts = array(
      // Text that match these specific strings are checked first.
      'matches' => array(
        // Primary class.
        t('Download feature')   => 'primary',

        // Success class.
        t('Add effect')         => 'success',
        t('Add and configure')  => 'success',

        // Info class.
        t('Save and add')       => 'info',
        t('Add another item')   => 'info',
        t('Update style')       => 'info',
      ),

      // Text that contain these words anywhere in the string are checked last.
      'contains' => array(
        // Primary class.
        t('Confirm')            => 'primary',
        t('Filter')             => 'primary',
        t('Log in')             => 'primary',
        t('Submit')             => 'primary',
        t('Search')             => 'primary',
        t('Upload')             => 'primary',

        // Success class.
        t('Add')                => 'success',
        t('Create')             => 'success',
        t('Save')               => 'success',
        t('Write')              => 'success',

        // Warning class.
        t('Export')             => 'warning',
        t('Import')             => 'warning',
        t('Restore')            => 'warning',
        t('Rebuild')            => 'warning',

        // Info class.
        t('Apply')              => 'info',
        t('Update')             => 'info',

        // Danger class.
        t('Delete')             => 'danger',
        t('Remove')             => 'danger',
      ),
    );

    // Allow sub-themes to alter this array of patterns.
    drupal_alter('bootstrap_colorize_text', $texts);
  }

  // Iterate over the array.
  foreach ($texts as $pattern => $strings) {
    foreach ($strings as $value => $class) {
      switch ($pattern) {
        case 'matches':
          if ($string === $value) {
            return $class;
          }
          break;

        case 'contains':
          if (strpos(drupal_strtolower($string), drupal_strtolower($value)) !== FALSE) {
            return $class;
          }
          break;
      }
    }
  }

  // Return the default if nothing was matched.
  return $default;
}

/**
 * Adds an icon to button element based on its text value.
 *
 * @param array $element
 *   The form element, passed by reference.
 */
function _bootstrap_iconize_button(array &$element) {
  if (bootstrap_setting('button_iconize') && _bootstrap_is_button($element) && ($icon = _bootstrap_iconize_text($element['#value']))) {
    $element['#icon'] = $icon;
  }
}

/**
 * Matches a Bootstrap Glyphicon based on a string value.
 *
 * @param string $string
 *   The string to match classes against.
 * @param string $default
 *   The default icon to return if no match is found.
 *
 * @return string
 *   The Bootstrap icon matched against the value of $haystack or $default if
 *   no match could be made.
 */
function _bootstrap_iconize_text($string, $default = '') {
  static $texts;
  if (!isset($texts)) {
    $texts = array(
      // Text that match these specific strings are checked first.
      'matches' => array(),

      // Text that contain these words anywhere in the string are checked last.
      'contains' => array(
        t('Manage')     => 'cog',
        t('Configure')  => 'cog',
        t('Download')   => 'download',
        t('Export')     => 'export',
        t('Filter')     => 'filter',
        t('Import')     => 'import',
        t('Save')       => 'ok',
        t('Update')     => 'ok',
        t('Edit')       => 'pencil',
        t('Add')        => 'plus',
        t('Write')      => 'plus',
        t('Cancel')     => 'remove',
        t('Delete')     => 'trash',
        t('Remove')     => 'trash',
        t('Upload')     => 'upload',
        t('Log In')     => 'log-in',
      ),
    );

    // Allow sub-themes to alter this array of patterns.
    drupal_alter('bootstrap_iconize_text', $texts);
  }

  // Iterate over the array.
  foreach ($texts as $pattern => $strings) {
    foreach ($strings as $value => $icon) {
      switch ($pattern) {
        case 'matches':
          if ($string === $value) {
            return _bootstrap_icon($icon, $default);
          }
          break;

        case 'contains':
          if (strpos(drupal_strtolower($string), drupal_strtolower($value)) !== FALSE) {
            return _bootstrap_icon($icon, $default);
          }
          break;
      }
    }
  }

  // Return a default icon if nothing was matched.
  return _bootstrap_icon($default);
}

/**
 * Invokes a specific suggestion's preprocess functions.
 *
 * @param array $variables
 *   The theme implementation variables array.
 */
function _bootstrap_preprocess_theme_suggestion(array &$variables) {
  $registry = theme_get_registry();
  if (!empty($variables['theme_hook_suggestion']) && !empty($registry[$variables['theme_hook_suggestion']]['preprocess functions'])) {
    // Save the suggestion as the hook to pass to the function.
    $hook = $variables['theme_hook_suggestion'];

    // Iterate over the preprocess functions.
    foreach ($registry[$hook]['preprocess functions'] as $function) {
      // Ensure that the function is not this one (recursive) and exists.
      if ($function !== __FUNCTION__ && function_exists($function)) {
        // Invoke theme hook suggestion preprocess function.
        $function($variables, $hook);

        // Unset the theme_hook_suggestion so the suggestion's preprocess
        // functions can provide theme_hook_suggestions if needed.
        if (!empty($variables['theme_hook_suggestions'])) {
          unset($variables['theme_hook_suggestion']);
        }
      }
    }
  }
}

/**
 * Invokes a specific suggestion's process functions.
 *
 * @param array $variables
 *   The theme implementation variables array.
 */
function _bootstrap_process_theme_suggestion(array &$variables) {
  $registry = theme_get_registry();
  if (!empty($variables['theme_hook_suggestion']) && !empty($registry[$variables['theme_hook_suggestion']]['process functions'])) {
    // Save the suggestion as the hook to pass to the function.
    $hook = $variables['theme_hook_suggestion'];

    // Iterate over the process functions.
    foreach ($registry[$hook]['process functions'] as $function) {
      if (function_exists($function)) {
        // Invoke theme hook suggestion process function.
        $function($variables, $hook);

        // Unset the theme_hook_suggestion so the suggestion's preprocess
        // functions can provide theme_hook_suggestions if needed.
        if (!empty($variables['theme_hook_suggestions'])) {
          unset($variables['theme_hook_suggestion']);
        }
      }
    }
  }
}

/**
 * Determines if a string of text is considered "simple".
 *
 * @param string $string
 *   The string of text to check "simple" criteria on.
 * @param int|false $length
 *   The length of characters used to determine whether or not $string is
 *   considered "simple". Set explicitly to FALSE to disable this criteria.
 * @param array|false $allowed_tags
 *   An array of allowed tag elements. Set explicitly to FALSE to disable this
 *   criteria.
 * @param bool $html
 *   A variable, passed by reference, that indicates whether or not the
 *   string contains HTML.
 *
 * @return bool
 *   Returns TRUE if the $string is considered "simple", FALSE otherwise.
 */
function _bootstrap_is_simple_string($string, $length = 250, $allowed_tags = NULL, &$html = FALSE) {
  // Use the advanced drupal_static() pattern, since this is called very often.
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['strings'] = &drupal_static(__FUNCTION__);
  }
  $strings = &$drupal_static_fast['strings'];
  if (!isset($strings[$string])) {
    $plain_string = strip_tags($string);
    $simple = TRUE;
    if ($allowed_tags !== FALSE) {
      $filtered_string = filter_xss($string, $allowed_tags);
      $html = $filtered_string !== $plain_string;
      $simple = $simple && $string === $filtered_string;
    }
    if ($length !== FALSE) {
      $simple = $simple && strlen($plain_string) <= intval($length);
    }
    $strings[$string] = $simple;
  }
  return $strings[$string];
}

/**
 * Determines if the Path Breadcrumbs module theme function should be used.
 *
 * @param string $theme
 *   The machine name of a specific theme to determine status if the Path
 *   Breadcrumbs module has been configured to only use its internal function
 *   on a specific list of themes.
 *
 * @return bool
 *   TRUE or FALSE
 */
function _bootstrap_use_path_breadcrumbs($theme = NULL) {
  static $path_breadcrumbs;

  if (!isset($path_breadcrumbs)) {
    $path_breadcrumbs = FALSE;

    // Use active theme as the theme key if not explicitly set.
    if (!isset($theme)) {
      $theme = $GLOBALS['theme_key'];
    }

    // Determine whether or not the internal Path Breadcrumbs theme function
    // should be used or not.
    if (function_exists('path_breadcrumbs_breadcrumb') && module_exists('path_breadcrumbs')) {
      $internal_render = variable_get('path_breadcrumbs_internal_render', 1);
      $themes = variable_get('path_breadcrumbs_internal_render_themes', array());
      $path_breadcrumbs = ($internal_render && (empty($themes) || in_array($theme, $themes)));
    }
  }

  return $path_breadcrumbs;
}

/**
 * @} End of "ingroup utility".
 */
