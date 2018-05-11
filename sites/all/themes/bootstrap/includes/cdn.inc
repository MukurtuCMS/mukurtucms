<?php

/**
 * @file
 * cdn.inc
 *
 * Provides necessary CDN integration.
 */

define('BOOTSTRAP_CDN_PROVIDER_PATH', 'public://bootstrap/cdn_providers');

/**
 * Retrieves a list of available CDN providers for the Bootstrap framework.
 *
 * @param string $provider
 *   A specific provider data to return.
 * @param bool $reset
 *   Toggle determining whether or not to reset the database cache.
 *
 * @return array|false
 *   An associative array of CDN providers, keyed by their machine name if
 *   $provider is not set. If $provider is set and exists, its individual
 *   data array will be returned. If $provider is set and the data does not
 *   exist then FALSE will be returned.
 */
function bootstrap_cdn_provider($provider = NULL, $reset = FALSE) {
  $original_provider = $provider;

  // Use the advanced drupal_static() pattern, since this is called very often.
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['providers'] = &drupal_static(__FUNCTION__);
  }
  $providers = &$drupal_static_fast['providers'];
  if ($reset || !isset($providers)) {
    $provider_path = BOOTSTRAP_CDN_PROVIDER_PATH;
    file_prepare_directory($provider_path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

    $cid = 'theme_registry:bootstrap:cdn_providers';
    if (($cached = cache_get($cid)) && !empty($cached->data)) {
      $providers = $cached->data;
    }
    if ($reset || !isset($providers)) {
      $providers = array(
        'custom' => array(
          'title' => t('Custom'),
        ),
        'jsdelivr' => array(
          'api' => 'https://api.jsdelivr.com/v1/bootstrap/libraries',
          'title' => t('jsDelivr'),
          'description' => t('<p style="background:#EB4C36"><a href="!jsdelivr" target="_blank"><img src="//www.jsdelivr.com/img/logo.png" alt="jsDelivr Logo"/></a></p><p><a href="!jsdelivr" target="_blank">jsDelivr</a> is a free multi-CDN infrastructure that uses <a href="!maxcdn" target="_blank">MaxCDN</a>, <a href="!cloudflare" target="_blank">Cloudflare</a> and many others to combine their powers for the good of the open source community... <a href="!jsdelivr_about" target="_blank">read more</a></p>', array(
            '!jsdelivr' => 'https://www.jsdelivr.com',
            '!jsdelivr_about' => 'https://www.jsdelivr.com/about',
            '!maxcdn' => 'http://www.maxcdn.com',
            '!cloudflare' => 'http://www.cloudflare.com',
          )),
        ),
      );

      // Defaults properties each provider must have.
      $defaults = array(
        'api' => NULL,
        'css' => array(),
        'description' => NULL,
        'error' => FALSE,
        'js' => array(),
        'imported' => FALSE,
        'min' => array(
          'css' => array(),
          'js' => array(),
        ),
        'title' => NULL,
      );

      // Process the providers.
      foreach ($providers as $name => &$data) {
        $data += $defaults;
        $data['name'] = $name;
        if (empty($name)) {
          continue;
        }

        // Use manually imported API data, if it exists.
        $request = NULL;
        if (!empty($data['api']) && file_exists("$provider_path/$name.json") && ($imported_data = file_get_contents("$provider_path/$name.json"))) {
          $data['imported'] = TRUE;
          $request = new stdClass();
          $request->code = '200';
          $request->data = $imported_data;
        }
        // Otherwise, attempt to request API data if the provider has specified
        // an "api" URL to use.
        elseif (!empty($data['api'])) {
          $request = drupal_http_request($data['api']);
        }

        // Alter the specific provider.
        $function = 'bootstrap_bootstrap_cdn_provider_' . $name . '_alter';
        if (function_exists($function)) {
          $function($data, $request);
        }
      }
      cache_set($cid, $providers);
    }
  }
  if (isset($original_provider)) {
    if (!isset($providers[$original_provider])) {
      return FALSE;
    }
    return $providers[$original_provider];
  }
  return $providers;
}

/**
 * Callback for jsDelivr CDN.
 *
 * @param array $provider
 *   The provider data array, passed by reference.
 * @param \stdClass $request
 *   The raw request object, if the provider specified an "api" URL to retrieve
 *   data prior to this alter hook being called. It is up to whatever
 *   implements these hooks to parse the requested data.
 */
function bootstrap_bootstrap_cdn_provider_jsdelivr_alter(array &$provider, \stdClass $request = NULL) {
  $json = array();
  $provider['versions'] = array();
  $provider['themes'] = array();

  if ($request->code === '200' && !empty($request->data)) {
    $json = drupal_json_decode($request->data);
  }

  // Expected library names from jsDelivr API v1. Must use "twitter-bootstrap"
  // instead of "bootstrap" (which is just a folder alias).
  // @see https://www.drupal.org/node/2504343
  // @see https://github.com/jsdelivr/api/issues/94
  $bootstrap = 'twitter-bootstrap';
  $bootswatch = 'bootswatch';

  // Extract the raw asset files from the JSON data for each framework.
  $libraries = array();
  if ($json) {
    foreach ($json as $data) {
      if ($data['name'] === $bootstrap || $data['name'] === $bootswatch) {
        foreach ($data['assets'] as $asset) {
          if (preg_match('/^' . BOOTSTRAP_VERSION_MAJOR . '\.\d\.\d$/', $asset['version'])) {
            $libraries[$data['name']][$asset['version']] = $asset['files'];
          }
        }
      }
    }
  }

  // If the main bootstrap library could not be found, then provide defaults.
  if (!isset($libraries[$bootstrap])) {
    $provider['error'] = TRUE;
    $provider['versions'][BOOTSTRAP_VERSION] = BOOTSTRAP_VERSION;
    $provider['themes'][BOOTSTRAP_VERSION] = array(
      'bootstrap' => array(
        'title' => t('Bootstrap'),
        'css' => array('//cdn.jsdelivr.net/bootstrap/' . BOOTSTRAP_VERSION . '/css/bootstrap.css'),
        'js' => array('//cdn.jsdelivr.net/bootstrap/' . BOOTSTRAP_VERSION . '/js/bootstrap.js'),
        'min' => array(
          'css' => array('//cdn.jsdelivr.net/bootstrap/' . BOOTSTRAP_VERSION . '/css/bootstrap.min.css'),
          'js' => array('//cdn.jsdelivr.net/bootstrap/' . BOOTSTRAP_VERSION . '/js/bootstrap.min.js'),
        ),
      ),
    );
    return;
  }

  // Populate the provider array with the versions and themes available.
  foreach (array_keys($libraries[$bootstrap]) as $version) {
    $provider['versions'][$version] = $version;

    if (!isset($provider['themes'][$version])) {
      $provider['themes'][$version] = array();
    }

    // Extract Bootstrap themes.
    $provider['themes'][$version] = drupal_array_merge_deep($provider['themes'][$version], _bootstrap_cdn_provider_jsdelivr_extract_themes($libraries[$bootstrap][$version], "//cdn.jsdelivr.net/bootstrap/$version"));

    // Extract Bootswatch themes.
    if (isset($libraries[$bootswatch][$version])) {
      $provider['themes'][$version] = drupal_array_merge_deep($provider['themes'][$version], _bootstrap_cdn_provider_jsdelivr_extract_themes($libraries[$bootswatch][$version], "//cdn.jsdelivr.net/bootswatch/$version"));
    }
  }

  // Post process the themes to fill in any missing assets.
  foreach (array_keys($provider['themes']) as $version) {
    foreach (array_keys($provider['themes'][$version]) as $theme) {
      // Some themes actually require Bootstrap framework assets to still
      // function properly.
      if ($theme !== 'bootstrap') {
        foreach (array('css', 'js') as $type) {
          // Bootswatch themes include the Bootstrap framework in their CSS.
          // Skip the CSS portions.
          if ($theme !== 'bootstrap_theme' && $type === 'css') {
            continue;
          }
          if (!isset($provider['themes'][$version][$theme][$type]) && !empty($provider['themes'][$version]['bootstrap'][$type])) {
            $provider['themes'][$version][$theme][$type] = array();
          }
          $provider['themes'][$version][$theme][$type] = drupal_array_merge_deep($provider['themes'][$version]['bootstrap'][$type], $provider['themes'][$version][$theme][$type]);
          if (!isset($provider['themes'][$version][$theme]['min'][$type]) && !empty($provider['themes'][$version]['bootstrap']['min'][$type])) {
            $provider['themes'][$version][$theme]['min'][$type] = array();
          }
          $provider['themes'][$version][$theme]['min'][$type] = drupal_array_merge_deep($provider['themes'][$version]['bootstrap']['min'][$type], $provider['themes'][$version][$theme]['min'][$type]);
        }
      }
      // Some themes do not have a non-minified version, clone them to the
      // "normal" css/js arrays to ensure that the theme still loads if
      // aggregation (minification) is disabled.
      foreach (array('css', 'js') as $type) {
        if (!isset($provider['themes'][$version][$theme][$type]) && isset($provider['themes'][$version][$theme]['min'][$type])) {
          $provider['themes'][$version][$theme][$type] = $provider['themes'][$version][$theme]['min'][$type];
        }
      }
    }
  }
}

/**
 * Extracts theme information from files provided by the jsDelivr API.
 *
 * This will place the raw files into proper "css", "js" and "min" arrays
 * (if they exist) and prepends them with a base URL provided.
 *
 * @param array $files
 *   An array of files to process.
 * @param string $base_url
 *   The base URL each one of the $files are relative to, this usually
 *   should also include the version path prefix as well.
 *
 * @return array
 *   An associative array containing the following keys, if there were
 *   matching files found:
 *   - css
 *   - js
 *   - min:
 *     - css
 *     - js
 */
function _bootstrap_cdn_provider_jsdelivr_extract_themes(array $files, $base_url = '') {
  $themes = array();
  foreach ($files as $file) {
    preg_match('`([^/]*)/bootstrap(-theme)?(\.min)?\.(js|css)$`', $file, $matches);
    if (!empty($matches[1]) && !empty($matches[4])) {
      $path = $matches[1];
      $min = $matches[3];
      $filetype = $matches[4];

      // Determine the "theme" name.
      if ($path === 'css' || $path === 'js') {
        $theme = 'bootstrap';
        $title = t('Bootstrap');
      }
      else {
        $theme = $path;
        $title = ucfirst($path);
      }
      if ($matches[2]) {
        $theme = 'bootstrap_theme';
        $title = t('Bootstrap Theme');
      }

      $themes[$theme]['title'] = $title;
      if ($min) {
        $themes[$theme]['min'][$filetype][] = "$base_url/$path/bootstrap{$matches[2]}$min.$filetype";
      }
      else {
        $themes[$theme][$filetype][] = "$base_url/$path/bootstrap{$matches[2]}$min.$filetype";
      }
    }
  }
  return $themes;
}

/**
 * Callback for Custom CDN assets.
 */
function bootstrap_bootstrap_cdn_provider_custom_assets_alter(&$provider, $theme = NULL) {
  foreach (array('css', 'js') as $type) {
    if ($setting = bootstrap_setting('cdn_custom_' . $type, $theme)) {
      $provider[$type][] = $setting;
    }
    if ($setting = bootstrap_setting('cdn_custom_' . $type . '_min', $theme)) {
      $provider['min'][$type][] = $setting;
    }
  }
}

/**
 * Callback for jsDelivr CDN assets.
 */
function bootstrap_bootstrap_cdn_provider_jsdelivr_assets_alter(&$provider, $theme = NULL) {
  $error = !empty($provider['error']);
  $version = $error ? BOOTSTRAP_VERSION : bootstrap_setting('cdn_jsdelivr_version', $theme);
  $theme = $error ? 'bootstrap' : bootstrap_setting('cdn_jsdelivr_theme', $theme);
  if (isset($provider['themes'][$version][$theme])) {
    $provider = drupal_array_merge_deep($provider, $provider['themes'][$version][$theme]);
  }
}

/**
 * Custom callback for CDN provider settings.
 *
 * @see bootstrap_form_system_theme_settings_alter()
 */
function bootstrap_cdn_provider_settings_form(&$form, &$form_state, $theme) {
  // Retrieve the provider from form values or the setting.
  $provider = isset($form_state['values']['bootstrap_cdn_provider']) ? $form_state['values']['bootstrap_cdn_provider'] : bootstrap_setting('cdn_provider', $theme);

  // Intercept possible manual import of API data via AJAX callback.
  if (isset($form_state['clicked_button']['#value']) && $form_state['clicked_button']['#value'] === t('Save provider data')) {
    $provider_path = BOOTSTRAP_CDN_PROVIDER_PATH;
    file_prepare_directory($provider_path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    $provider_data = isset($form_state['values']['bootstrap_cdn_provider_import_data']) ? $form_state['values']['bootstrap_cdn_provider_import_data'] : FALSE;
    $provider_file = "$provider_path/$provider.json";
    if ($provider_data) {
      file_unmanaged_save_data($provider_data, $provider_file, FILE_EXISTS_REPLACE);
    }
    elseif ($provider_file && file_exists($provider_file)) {
      file_unmanaged_delete($provider_file);
    }
    bootstrap_cdn_provider(NULL, TRUE);
  }

  $description_label = t('NOTE');
  $description = t('Using one of the "CDN Provider" options below is the preferred method for loading Bootstrap CSS and JS on simpler sites that do not use a site-wide CDN. Using a "CDN Provider" for loading Bootstrap, however, does mean that it depends on a third-party service. There is no obligation or commitment by these third-parties that guarantees any up-time or service quality. If you need to customize Bootstrap and have chosen to compile the source code locally (served from this site), you must disable the "CDN Provider" option below by choosing "- None -" and alternatively enable a site-wide CDN implementation. All local (served from this site) versions of Bootstrap will be superseded by any enabled "CDN Provider" below. <strong>Do not do both</strong>.');
  $form['advanced']['cdn'] = array(
    '#type' => 'fieldset',
    '#title' => t('CDN (Content Delivery Network)'),
    '#description' => '<div class="alert alert-info messages warning"><strong>' . $description_label . ':</strong> ' . $description . '</div>',
    '#collapsible' => TRUE,
    '#collapsed' => !$provider,
  );

  $providers = bootstrap_cdn_provider();
  $options = array();
  foreach ($providers as $key => $data) {
    $options[$key] = $data['title'];
  }
  $form['advanced']['cdn']['bootstrap_cdn_provider'] = array(
    '#type' => 'select',
    '#title' => t('CDN Provider'),
    '#default_value' => $provider,
    '#empty_value' => '',
    '#options' => $options,
  );

  // Render each provider.
  foreach ($providers as $name => $data) {
    $form['advanced']['cdn']['provider'][$name] = array(
      '#type' => 'container',
      '#prefix' => '<div id="bootstrap-cdn-provider-' . $name . '">',
      '#suffix' => '</div>',
      '#states' => array(
        'visible' => array(
          ':input[name="bootstrap_cdn_provider"]' => array('value' => $name),
        ),
      ),
    );
    $element = &$form['advanced']['cdn']['provider'][$name];

    $element['description']['#markup'] = '<div class="lead">' . $data['description'] . '</div>';

    // Indicate there was an error retrieving the provider's API data.
    if (!empty($data['error']) || !empty($data['imported'])) {
      if (!empty($data['error'])) {
        $description_label = t('ERROR');
        $description = t('Unable to reach or parse the data provided by the @title API. Ensure the server this website is hosted on is able to initiate HTTP requests via <a href="!drupal_http_request" target="_blank">drupal_http_request()</a>. If the request consistently fails, it is likely that there are certain PHP functions that have been disabled by the hosting provider for security reasons. It is possible to manually copy and paste the contents of the following URL into the "Imported @title data" section below.<br /><br /><a href="!provider_api" target="_blank">!provider_api</a>.', array(
          '@title' => $data['title'],
          '!provider_api' => $data['api'],
          '!drupal_http_request' => 'https://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_http_request/7',
        ));
        $element['#prefix'] .= '<div class="alert alert-danger messages error"><strong>' . $description_label . ':</strong> ' . $description . '</div>';
      }
      $element['import'] = array(
        '#type' => 'fieldset',
        '#title' => t('Imported @title data', array(
          '@title' => $data['title'],
        )),
        '#description' => t('The provider will attempt to parse the data entered here each time it is saved. If no data has been entered, any saved files associated with this provider will be removed and the provider will again attempt to request the API data normally through the following URL: <a href="!provider_api" target="_blank">!provider_api</a>.', array(
          '!provider_api' => $data['api'],
        )),
        '#weight' => 10,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $element['import']['bootstrap_cdn_provider_import_data'] = array(
        '#type' => 'textarea',
        '#default_value' => file_exists(BOOTSTRAP_CDN_PROVIDER_PATH . '/' . $name . '.json') ? file_get_contents(BOOTSTRAP_CDN_PROVIDER_PATH . '/' . $name . '.json') : NULL,
      );
      $element['import']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save provider data'),
        '#executes_submit_callback' => FALSE,
        '#ajax' => array(
          'callback' => 'bootstrap_cdn_provider_settings_form_ajax_reload_provider',
          'wrapper' => 'bootstrap-cdn-provider-' . $name,
        ),
      );
    }

    // Alter the specific provider.
    $function = 'bootstrap_bootstrap_cdn_provider_' . $name . '_settings_form_alter';
    if (function_exists($function)) {
      $function($element, $form_state, $data, $theme);
    }
  }
}

/**
 * AJAX callback for reloading CDN provider elements.
 */
function bootstrap_cdn_provider_settings_form_ajax_reload_provider($form, $form_state) {
  return $form['advanced']['cdn']['provider'][$form_state['values']['bootstrap_cdn_provider']];
}

/**
 * Implements hook_bootstrap_cdn_provider_PROVIDER_settings_form_alter().
 */
function bootstrap_bootstrap_cdn_provider_custom_settings_form_alter(&$element, &$form_state, $provider = array(), $theme = NULL) {
  foreach (array('css', 'js') as $type) {
    $setting = bootstrap_setting('cdn_custom_' . $type, $theme);
    $setting_min = bootstrap_setting('cdn_custom_' . $type . '_min', $theme);
    $element['bootstrap_cdn_custom_' . $type] = array(
      '#type' => 'textfield',
      '#title' => t('Bootstrap @type URL', array(
        '@type' => drupal_strtoupper($type),
      )),
      '#description' => t('It is best to use protocol relative URLs (i.e. without http: or https:) here as it will allow more flexibility if the need ever arises.'),
      '#default_value' => $setting,
    );
    $element['bootstrap_cdn_custom_' . $type . '_min'] = array(
      '#type' => 'textfield',
      '#title' => t('Minified Bootstrap @type URL', array(
        '@type' => drupal_strtoupper($type),
      )),
      '#description' => t('Additionally, you can provide the minimized version of the file. It will be used instead if site aggregation is enabled.'),
      '#default_value' => $setting_min,
    );
  }
}

/**
 * Implements hook_bootstrap_cdn_provider_PROVIDER_settings_form_alter().
 */
function bootstrap_bootstrap_cdn_provider_jsdelivr_settings_form_alter(&$element, &$form_state, $provider = array(), $theme = NULL) {
  $version = isset($form_state['values']['bootstrap_cdn_jsdelivr_version']) ? $form_state['values']['bootstrap_cdn_jsdelivr_version'] : bootstrap_setting('cdn_jsdelivr_version', $theme);
  $element['bootstrap_cdn_jsdelivr_version'] = array(
    '#type' => 'select',
    '#title' => t('Version'),
    '#options' => isset($provider['versions']) ? $provider['versions'] : array(),
    '#default_value' => $version,
    '#ajax' => array(
      'callback' => 'bootstrap_cdn_provider_settings_form_ajax_reload_provider',
      'wrapper' => 'bootstrap-cdn-provider-jsdelivr',
    ),
  );
  if (empty($provider['error']) && empty($provider['imported'])) {
    $element['bootstrap_cdn_jsdelivr_version']['#description'] = t('These versions are automatically populated by the @provider API upon cache clear and newer versions may appear over time. It is highly recommended the version that the site was built with stays at that version. Until a newer version has been properly tested for updatability by the site maintainer, you should not arbitrarily "update" just because there is a newer version. This can cause many inconsistencies and undesired effects with an existing site.', array(
      '@provider' => $provider['title'],
    ));
  }

  // Bootswatch.
  $themes = array();
  if (isset($provider['themes'][$version])) {
    foreach ($provider['themes'][$version] as $_theme => $data) {
      $themes[$_theme] = $data['title'];
    }
  }
  $element['bootstrap_cdn_jsdelivr_theme'] = array(
    '#type' => 'select',
    '#title' => t('Theme'),
    '#description' => t('Choose the example <a href="!bootstrap_theme" target="_blank">Bootstrap Theme</a> provided by Bootstrap or one of the many, many <a href="!bootswatch" target="_blank">Bootswatch</a> themes!', array(
      '!bootswatch' => 'https://bootswatch.com',
      '!bootstrap_theme' => 'https://getbootstrap.com/docs/3.3/examples/theme/',
    )),
    '#default_value' => bootstrap_setting('cdn_jsdelivr_theme', $theme),
    '#options' => $themes,
    '#empty_option' => t('Bootstrap (default)'),
    '#empty_value' => 'bootstrap',
    '#suffix' => '<div id="bootstrap-theme-preview"></div>',
  );
}
