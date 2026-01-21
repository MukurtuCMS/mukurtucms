<?php

/**
 * @file
 * cdn.inc
 *
 * Provides necessary CDN integration.
 */

define('BOOTSTRAP_CDN_PROVIDER_PATH', 'public://bootstrap/cdn_providers');

/**
 * Retrieves JSON from a URI.
 *
 * @param string $url
 *   The URI to retrieve JSON from.
 * @param array $options
 *   The options to pass to the HTTP client.
 * @param \Exception|null $exception
 *   The exception thrown if there was an error, passed by reference.
 *
 * @return array
 *   The requested JSON array.
 */
function _bootstrap_cdn_provider_request_json($url, array $options = array(), &$exception = NULL) {
  $json = array();

  $options += array(
    'method' => 'GET',
    'headers' => array(
      'User-Agent' => 'Drupal Bootstrap 7.x-3.x (https://www.drupal.org/project/bootstrap)',
    ),
  );

  try {
    $response = drupal_http_request($url, $options);
    if (!empty($response->error)) {
      throw new \Exception($response->error, $response->code);
    }
    if ($response->code == 200) {
      $json = drupal_json_decode($response->data) ?: array();
    }
  }
  catch (\Exception $e) {
    $exception = $e;
  }

  return $json;
}

/**
 * Retrieves the Drupal Bootstrap Styles to use with CDN assets.
 *
 * @param string $version
 *   A specific version to use. If not set, the currently set CDN Provider
 *   version will be used.
 * @param string $theme
 *   A specific theme to use. If not set, the currently set CDN Provider
 *   theme will be used.
 *
 * @return string|false
 *   The URL to the styles or FALSE if it doesn't exist.
 */
function _bootstrap_cdn_get_drupal_bootstrap_styles_url($version = NULL, $theme = NULL) {
  global $theme_key;
  static $styles;

  if (!isset($provider)) {
    $provider = bootstrap_setting('cdn_provider', NULL, 'bootstrap', 'jsdelivr');
  }

  if (!isset($version)) {
    $version = bootstrap_setting('cdn_' . $provider . '_version') ?: BOOTSTRAP_VERSION;
  }

  if (!isset($theme)) {
    $theme = bootstrap_setting('cdn_' . $provider . '_theme') ?: 'bootstrap';
  }


  $cid = "theme_registry:$theme_key:drupal_bootstrap_styles";
  $min = variable_get('preprocess_css', FALSE) ? '.min' : '';
  $key = "$provider:$version:$theme$min";

  if (!isset($styles)) {
    // Allow sites to manually specify a custom path or URL.
    if ($data = variable_get('drupal_bootstrap_styles')) {
      $styles = array($key => $data);
    }
    // Otherwise, attempt to load cached database data.
    else {
      $styles = ($cache = cache_get($cid)) && !empty($cache->data) ? $cache->data : array();
    }
  }

  if (!isset($styles[$key])) {
    // Determine the latest @unicorn-fail/drupal-bootstrap-styles version.
    if (!isset($styles['versions'])) {
      $json = _bootstrap_cdn_provider_request_json('https://data.jsdelivr.com/v1/package/npm/@unicorn-fail/drupal-bootstrap-styles');
      $json += array('versions' => array());
      natsort($json['versions']);
      $styles['versions'] = $json['versions'];
    }

    // Latest version should be the last entry.
    $pkg_version = end($styles['versions']);

    // Retrieve the list of files from the actual distributed API JSON file in
    // @unicorn-fail/drupal-bootstrap-styles (note the sub-domain difference).
    if (!isset($styles["$pkg_version:files"])) {
      $json = _bootstrap_cdn_provider_request_json("https://cdn.jsdelivr.net/npm/@unicorn-fail/drupal-bootstrap-styles@$pkg_version/dist/api.json");
      $json += array('files' => array());
      $styles["$pkg_version:files"] = array_filter($json['files'], function ($file) {
        return !!preg_match('`^/?dist/(\d+\.\d+\.\d+)/7.x-3.x`', $file['name']);
      });
    }

    $styles[$key] = FALSE;
    $theme = $theme === 'bootstrap' || $theme === 'bootstrap_theme' ? '' : "-$theme";
    foreach ($styles["$pkg_version:files"] as $file) {
      if (!empty($file['name']) && $file['name'] === "/dist/$version/7.x-3.x/drupal-bootstrap$theme$min.css") {
        $filename = !empty($file['symlink']) ? $file['symlink'] : $file['name'];
        $styles[$key] = "https://cdn.jsdelivr.net/npm/@unicorn-fail/drupal-bootstrap-styles@$pkg_version$filename";
        break;
      }
    }

    // Now cache the styles.
    cache_set($cid, $styles);
  }

  return $styles[$key];
}

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
          'title' => t('jsDelivr'),
          'description' => t('<p><a href="!jsdelivr" target="_blank">jsDelivr</a> is a free multi-CDN infrastructure that uses <a href="!maxcdn" target="_blank">MaxCDN</a>, <a href="!cloudflare" target="_blank">Cloudflare</a> and many others to combine their powers for the good of the open source community... <a href="!jsdelivr_about" target="_blank">read more</a></p>', array(
            '!jsdelivr' => 'https://www.jsdelivr.com',
            '!jsdelivr_about' => 'https://www.jsdelivr.com/about',
            '!maxcdn' => 'https://www.maxcdn.com',
            '!cloudflare' => 'https://www.cloudflare.com',
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

        // Skip alter (processing) if using backported CDN Provider logic.
        if ($instance = _bootstrap_backport_cdn_provider(NULL, $name)) {
          // Go ahead and use its description and label though.
          $data['description'] = $instance->getDescription();
          $data['title'] = $instance->getLabel();
          continue;
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
  $provider['versions'] = array();
  $provider['themes'] = array();

  $json = array();
  foreach (array('bootstrap', 'bootswatch') as $package) {
    $data = array('name' => $package, 'assets' => array());
    $latest = '0.0.0';
    $versions = array();
    $packageJson = _bootstrap_cdn_provider_request_json("https://data.jsdelivr.com/v1/package/npm/$package") + array('versions' => array());
    foreach ($packageJson['versions'] as $key => $version) {
      // Skip irrelevant versions.
      if (!preg_match('/^' . substr(BOOTSTRAP_VERSION, 0, 1) . '\.\d+\.\d+$/', $version)) {
        continue;
      }
      $versionJson = _bootstrap_cdn_provider_request_json("https://data.jsdelivr.com/v1/package/npm/$package@$version/flat");

      // Skip empty files.
      if (empty($versionJson['files'])) {
        continue;
      }

      $versions[] = $version;
      if (version_compare($latest, $version) === -1) {
        $latest = $version;
      }

      $asset = array('files' => array(), 'version' => $version);
      foreach ($versionJson['files'] as $file) {
        // Skip old bootswatch file structure.
        if ($package === 'bootswatch' && preg_match('`^/2|/bower_components`', $file['name'], $matches)) {
          continue;
        }
        preg_match('`([^/]*)/bootstrap(-theme)?(\.min)?\.(js|css)$`', $file['name'], $matches);
        if (!empty($matches[1]) && !empty($matches[4])) {
          $asset['files'][] = $file['name'];
        }
      }
      $data['assets'][] = $asset;
    }
    $data['lastversion'] = $latest;
    $data['versions'] = $versions;
    $json[] = $data;
  }

  // Extract the raw asset files from the JSON data for each framework.
  $libraries = array();
  if ($json) {
    foreach ($json as $data) {
      if ($data['name'] === 'bootstrap' || $data['name'] === 'bootswatch') {
        foreach ($data['assets'] as $asset) {
          if (preg_match('/^' . BOOTSTRAP_VERSION_MAJOR . '\.\d\.\d$/', $asset['version'])) {
            $libraries[$data['name']][$asset['version']] = $asset['files'];
          }
        }
      }
    }
  }

  // If the main bootstrap library could not be found, then provide defaults.
  if (!isset($libraries['bootstrap'])) {
    $provider['error'] = TRUE;
    $provider['versions'][BOOTSTRAP_VERSION] = BOOTSTRAP_VERSION;
    $provider['themes'][BOOTSTRAP_VERSION] = array(
      'bootstrap' => array(
        'title' => t('Bootstrap'),
        'css' => array('https://cdn.jsdelivr.net/npm/bootstrap@' . BOOTSTRAP_VERSION . '/dist/css/bootstrap.css'),
        'js' => array('https://cdn.jsdelivr.net/npm/bootstrap@' . BOOTSTRAP_VERSION . '/dist/js/bootstrap.js'),
        'min' => array(
          'css' => array('https://cdn.jsdelivr.net/npm/bootstrap@' . BOOTSTRAP_VERSION . '/dist/css/bootstrap.min.css'),
          'js' => array('https://cdn.jsdelivr.net/npm/bootstrap@' . BOOTSTRAP_VERSION . '/dist/js/bootstrap.min.js'),
        ),
      ),
    );
    return;
  }

  // Populate the provider array with the versions and themes available.
  foreach (array_keys($libraries['bootstrap']) as $version) {
    $provider['versions'][$version] = $version;

    if (!isset($provider['themes'][$version])) {
      $provider['themes'][$version] = array();
    }

    // Extract Bootstrap themes.
    $provider['themes'][$version] = drupal_array_merge_deep($provider['themes'][$version], _bootstrap_cdn_provider_jsdelivr_extract_themes($libraries['bootstrap'][$version], "https://cdn.jsdelivr.net/npm/bootstrap@$version"));

    // Extract Bootswatch themes.
    if (isset($libraries['bootswatch'][$version])) {
      $provider['themes'][$version] = drupal_array_merge_deep($provider['themes'][$version], _bootstrap_cdn_provider_jsdelivr_extract_themes($libraries['bootswatch'][$version], "https://cdn.jsdelivr.net/npm/bootswatch@$version"));
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
        $themes[$theme]['min'][$filetype][] = "$base_url/" . ltrim($file, '/');
      }
      else {
        $themes[$theme][$filetype][] = "$base_url/" . ltrim($file, '/');
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

  // Use backported CDN Provider logic from 8.x-3.x.
  if ($instance = _bootstrap_backport_cdn_provider($theme, $provider['name'])) {
    $versions = $instance->getCdnVersions();
    $themes = array();
    foreach ($instance->getCdnThemes($version) as $name => $data) {
      $themes[$name] = $data['title'];
    }
  }
  else {
    $versions = isset($provider['versions']) ? $provider['versions'] : array();
    $themes = array();
    if (isset($provider['themes'][$version])) {
      foreach ($provider['themes'][$version] as $_theme => $data) {
        $themes[$_theme] = $data['title'];
      }
    }
  }

  $element['bootstrap_cdn_jsdelivr_version'] = array(
    '#type' => 'select',
    '#title' => t('Version'),
    '#options' => $versions,
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

  // Themes.
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
