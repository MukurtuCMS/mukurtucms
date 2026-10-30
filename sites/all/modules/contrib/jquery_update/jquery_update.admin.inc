<?php

/**
 * @file
 * Provides the administration settings for jQuery Update.
 */

// These are just for the examples in the admin UI, there's no urgent need to
// keep them up-to-date, especially as they'll be replaced by the latest
// versions if that info is available.
define('JQUERY_UPDATE_EXAMPLE_JQUERY_VERSION', '3.6.1');
define('JQUERY_UPDATE_EXAMPLE_JQUERYUI_VERSION', '1.13.2');
define('JQUERY_UPDATE_EXAMPLE_JQUERY_MIGRATE_VERSION', '3.4.0');
define('JQUERY_UPDATE_EXAMPLE_JQUERY_COOKIE_VERSION', '1.4.1');
define('JQUERY_UPDATE_EXAMPLE_JQUERY_FORM_VERSION', '4.3.0');

/**
 * Admin settings menu callback.
 *
 * @see jquery_update_menu()
 */
function jquery_update_settings_form() {
  // Vertical Tabs.
  $form['jquery_update'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 99,
  );

  // Provide the form item to choose which jQuery version to use.
  $default_version = variable_get('jquery_update_jquery_version', JQUERY_UPDATE_DEFAULT_JQUERY_VERSION);
  $custom_jquery = variable_get('jquery_update_custom_version_jquery', FALSE);
  if (!empty($custom_jquery)) {
    $default_version = $custom_jquery;
  }
  $version_options = jquery_update_get_version_options(FALSE);
  $form['jquery_update_jquery_version'] = array(
    '#type' => 'select',
    '#title' => t('Default jQuery version'),
    '#options' => $version_options,
    '#default_value' => $default_version,
    '#description' => t('Select which version of jQuery to use on the site.'),
  );

  // Theme-specific override version.
  $themes = list_themes();
  $theme_default = variable_get('theme_default', FALSE);
  $admin_theme = variable_get('admin_theme', FALSE);
  $header = array(t('Theme'), t('jQuery version'), t('Operations'));
  $rows = array();
  // Go through all themes.
  foreach ($themes as $theme_key => $theme) {
    // Skip disabled themes, but only if they are not configured as admin
    // theme. This is an inconsistency in drupal core, that you can select a
    // disabled theme as admin theme.
    if (!$theme->status && $theme_key !== $admin_theme) {
      continue;
    }

    // Retrieve the version jQuery for this theme.
    $theme_version = theme_get_setting('jquery_update_jquery_version', $theme_key);

    // Replace or modify the version name to be displayed.
    if (empty($theme_version)) {
      $theme_version = t('Site Default');
    }
    elseif (in_array($theme_version, array_keys($version_options))) {
      $theme_version = $version_options[$theme_version];
    }
    else {
      $theme_version .= ' (' . t('unknown version') . ')';
    }

    // Provide additional information for default and admin themes.
    $theme_name = $theme->info['name'];
    if ($theme_key === $theme_default && ($theme_key === $admin_theme || empty($admin_theme))) {
      $theme_name .= ' (' . t('default/admin theme') . ')';
    }
    elseif ($theme_key === $theme_default) {
      $theme_name .= ' (' . t('default theme') . ')';
    }
    elseif ($theme_key === $admin_theme) {
      $theme_name .= ' (' . t('admin theme') . ')';
    }

    // Construct the table row.
    $rows[] = array(
      $theme_name,
      $theme_version,
      l(t('Configure'), 'admin/appearance/settings/' . $theme_key, array(
        'attributes' => array(
          'class' => array(
            'module-link',
            'module-link-configure',
          ),
        ),
        'query' => drupal_get_destination(),
        'fragment' => 'edit-jquery-update',
      )),
    );
  }

  $form['themes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Theme Overrides'),
    '#description' => t('You can override the default jQuery version above on each themes settings page. This is useful for administrative based themes.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => FALSE,
    '#weight' => -2,
    '#group' => 'jquery_update',
  );
  $form['themes']['overrides'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  $form['performance'] = array(
    '#type' => 'fieldset',
    '#title' => t('Performance'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => FALSE,
    '#weight' => -1,
    '#group' => 'jquery_update',
    '#description' => t('Modify how jQuery is loaded to increase download and render performance.'),
  );

  $form['performance']['jquery_update_compression_type'] = array(
    '#type' => 'radios',
    '#title' => t('jQuery compression level'),
    '#options' => array(
      'min' => t('Production (minified)'),
      'none' => t('Development (uncompressed)'),
    ),
    // Do not show this field if jQuery version is default.
    '#states' => array(
      'invisible' => array(
        ':input[name=jquery_update_jquery_version]' => array('value' => "default"),
      ),
    ),
    '#default_value' => variable_get('jquery_update_compression_type', 'min'),
  );
  $form['performance']['jquery_update_jquery_cdn'] = array(
    '#type' => 'select',
    '#title' => t('jQuery and jQuery UI CDN'),
    '#options' => array(
      'none' => t('None'),
      'google' => t('Google'),
      'microsoft' => t('Microsoft'),
      'jquery' => t('jQuery'),
    ),
    // Do not show this field if jQuery version is default.
    '#states' => array(
      'invisible' => array(
        ':input[name=jquery_update_jquery_version]' => array('value' => "default"),
      ),
    ),
    '#default_value' => variable_get('jquery_update_jquery_cdn', 'none'),
    '#description' => t('Use jQuery and jQuery UI from a CDN. If the CDN is not available the local version of jQuery and jQuery UI will be used.'),
  );

  $form['jquery_migrate'] = array(
    '#type' => 'fieldset',
    '#title' => t('jQuery Migrate'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => FALSE,
    '#group' => 'jquery_update',
    '#description' => t('<a href="!url">jQuery Migrate</a> can be used to detect and restore APIs or features that have been deprecated in jQuery and removed as of version 1.9 or higher.', array(
      '!url' => 'http://github.com/jquery/jquery-migrate/#readme',
    )),
  );
  if (!empty($custom_jquery) && version_compare($custom_jquery, 3, '>=')) {
    $form['jquery_migrate']['#description'] .= '<br /><strong>' . t('Note that the jQuery Update module only provides jQuery Migrate for jQuery versions before 3.x. A newer version of jQuery Migrate for the current version of jQuery can be configured via a Custom path.') . '</strong>';
  }

  $form['jquery_migrate']['jquery_update_jquery_migrate_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable jQuery Migrate Plugin'),
    '#default_value' => variable_get('jquery_update_jquery_migrate_enable', FALSE),
    '#description' => t("Even if jQuery Migrate is enabled, it will not be loaded if the current page's jQuery version is lower than 1.9."),
  );

  $jquery_migrate_states = array(
    'visible' => array(
      ':input[name="jquery_migrate[jquery_update_jquery_migrate_enable]"]' => array('checked' => TRUE),
    ),
  );
  $form['jquery_migrate']['jquery_update_jquery_migrate_cdn'] = array(
    '#type' => 'select',
    '#title' => t('jQuery Migrate CDN'),
    '#options' => array(
      'none' => t('None'),
      'jquery' => t('jQuery'),
    ),
    '#default_value' => variable_get('jquery_update_jquery_migrate_cdn', 'none'),
    '#description' => t('Load the jQuery Migrate plugin using a CDN. If the CDN is not available the local module version of the plugin will be used instead.'),
    '#states' => $jquery_migrate_states,
  );

  $jquery_migrate_api_url = 'https://github.com/jquery/jquery-migrate/#migrate-plugin-api';
  $form['jquery_migrate']['jquery_update_jquery_migrate_warnings'] = array(
    '#type' => 'checkbox',
    '#title' => t('Console warnings'),
    '#default_value' => variable_get('jquery_update_jquery_migrate_warnings', FALSE),
    '#description' => t('Toggle the <a href="!url">generation of console warnings</a> when using the debug version of jQuery Migrate.', array(
      '!url' => $jquery_migrate_api_url,
    )),
    '#states' => $jquery_migrate_states,
  );

  $form['jquery_migrate']['jquery_update_jquery_migrate_trace'] = array(
    '#type' => 'checkbox',
    '#title' => t('Console trace'),
    '#default_value' => variable_get('jquery_update_jquery_migrate_trace', FALSE),
    '#description' => t('Toggle the <a href="!url">generation of console trace messages</a> when using the debug version of jQuery Migrate.', array(
      '!url' => $jquery_migrate_api_url,
    )),
    '#states' => $jquery_migrate_states,
  );

  $form['jquery_custom'] = array(
    '#type' => 'fieldset',
    '#title' => t('Custom paths'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => FALSE,
    '#group' => 'jquery_update',
    '#description' => t('Custom paths for jQuery libraries (e.g. CDN URLs or paths to local files).'),
  );

  $latest_version = jquery_update_latest_version('jquery');
  $example_version = $latest_version ? $latest_version : JQUERY_UPDATE_EXAMPLE_JQUERY_VERSION;
  $form['jquery_custom']['jquery_update_custom_path_jquery'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom jQuery path'),
    '#default_value' => variable_get('jquery_update_custom_path_jquery', ''),
    '#description' => t('Example: %url or %path', array(
      '%url' => 'https://code.jquery.com/jquery-' . $example_version . '.js',
      '%path' => '/sites/default/files/jquery_update/jquery.js',
    )),
  );
  $form['jquery_custom']['jquery_update_custom_version_jquery'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom jQuery version'),
    '#default_value' => variable_get('jquery_update_custom_version_jquery', ''),
    '#description' => t('Example: %version', array('%version' => $example_version)),
  );

  $latest_version = jquery_update_latest_version('jqueryui');
  $example_version = $latest_version ? $latest_version : JQUERY_UPDATE_EXAMPLE_JQUERYUI_VERSION;
  $form['jquery_custom']['jquery_update_custom_path_jqueryui'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom jQuery UI path'),
    '#default_value' => variable_get('jquery_update_custom_path_jqueryui', ''),
    '#description' => t('Example: %url or %path', array(
      '%url' => 'https://cdnjs.cloudflare.com/ajax/libs/jqueryui/' . $example_version . '/jquery-ui.min.js',
      '%path' => '/sites/default/files/jquery_update/jquery-ui.min.js',
    )),
  );
  $form['jquery_custom']['jquery_update_custom_version_jqueryui'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom jQuery UI version'),
    '#default_value' => variable_get('jquery_update_custom_version_jqueryui', ''),
    '#description' => t('Example: %version', array('%version' => $example_version)),
  );

  $latest_version = jquery_update_latest_version('jquery-migrate');
  $example_version = $latest_version ? $latest_version : JQUERY_UPDATE_EXAMPLE_JQUERY_MIGRATE_VERSION;
  $form['jquery_custom']['jquery_update_custom_path_migrate'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom jQuery Migrate path'),
    '#default_value' => variable_get('jquery_update_custom_path_migrate', ''),
    '#description' => t('Example: %url or %path', array(
      '%url' => 'https://cdn.jsdelivr.net/npm/jquery-migrate@' . $example_version . '/dist/jquery-migrate.min.js',
      '%path' => '/sites/default/files/jquery_update/jquery-migrate.js',
    )),
  );
  $form['jquery_custom']['jquery_update_custom_version_jquery_migrate'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom jQuery Migrate version'),
    '#default_value' => variable_get('jquery_update_custom_version_jquery_migrate', ''),
    '#description' => t('Example: %version', array('%version' => $example_version)),
  );

  $latest_version = jquery_update_latest_version('jquery-cookie');
  $example_version = $latest_version ? $latest_version : JQUERY_UPDATE_EXAMPLE_JQUERY_COOKIE_VERSION;
  $form['jquery_custom']['jquery_update_custom_path_cookie'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom jQuery Cookie path'),
    '#default_value' => variable_get('jquery_update_custom_path_cookie', ''),
    '#description' => t('Example: %url or %path', array(
      '%url' => 'https://cdn.jsdelivr.net/gh/carhartl/jquery-cookie@' . $example_version . '/jquery.cookie.js',
      '%path' => '/sites/default/files/jquery_update/jquery.cookie.js',
    )),
  );
  $form['jquery_custom']['jquery_update_custom_version_jquery_cookie'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom jQuery Cookie version'),
    '#default_value' => variable_get('jquery_update_custom_version_jquery_cookie', ''),
    '#description' => t('Example: %version', array('%version' => $example_version)),
  );

  $latest_version = jquery_update_latest_version('jquery.form');
  $example_version = $latest_version ? $latest_version : JQUERY_UPDATE_EXAMPLE_JQUERY_FORM_VERSION;
  $form['jquery_custom']['jquery_update_custom_path_form'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom jQuery Form path'),
    '#default_value' => variable_get('jquery_update_custom_path_form', ''),
    '#description' => t('Example: %url or %path', array(
      '%url' => 'https://cdn.jsdelivr.net/gh/jquery-form/form@' . $example_version . '/dist/jquery.form.min.js',
      '%path' => '/sites/default/files/jquery_update/jquery.form.js',
    )),
  );
  $form['jquery_custom']['jquery_update_custom_version_jquery_form'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom jQuery Form version'),
    '#default_value' => variable_get('jquery_update_custom_version_jquery_form', ''),
    '#description' => t('Example: %version', array('%version' => $example_version)),
  );

  jquery_update_add_latest_version_info($form);

  return system_settings_form($form);
}

/**
 * Validate handler for settings form.
 */
function jquery_update_settings_form_validate($form, &$form_state) {
  // Handle empty custom paths / versions.
  if (!empty($form_state['values']['jquery_update_custom_path_jquery'])) {
    if (empty($form_state['values']['jquery_update_custom_version_jquery'])) {
      form_set_error('jquery_update_custom_version_jquery', 'Please provide a version for the custom jQuery path');
    }
  }
  if (!empty($form_state['values']['jquery_update_custom_path_jqueryui'])) {
    if (empty($form_state['values']['jquery_update_custom_version_jqueryui'])) {
      form_set_error('jquery_update_custom_version_jqueryui', 'Please provide a version for the custom jQuery UI path');
    }
  }
  if (!empty($form_state['values']['jquery_update_custom_path_cookie'])) {
    if (empty($form_state['values']['jquery_update_custom_version_jquery_cookie'])) {
      form_set_error('jquery_update_custom_version_jquery_cookie', 'Please provide a version for the custom jQuery Cookie path');
    }
  }
  if (!empty($form_state['values']['jquery_update_custom_path_form'])) {
    if (empty($form_state['values']['jquery_update_custom_version_jquery_form'])) {
      form_set_error('jquery_update_custom_version_jquery_form', 'Please provide a version for the custom jQuery Form path');
    }
  }
  if (!empty($form_state['values']['jquery_update_custom_path_migrate'])) {
    if (empty($form_state['values']['jquery_update_custom_version_jquery_migrate'])) {
      form_set_error('jquery_update_custom_version_jquery_migrate', 'Please provide a version for the custom jQuery Migrate path');
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function jquery_update_form_jquery_update_settings_form_alter(&$form, &$form_state, $form_id) {
  array_unshift($form['#submit'], 'jquery_update_settings_form_submit_early');
  $form['#submit'][] = 'jquery_update_settings_form_submit_late';
}

/**
 * Early submit handler for settings form.
 */
function jquery_update_settings_form_submit_early($form, &$form_state) {
  // Handle empty custom paths / versions.
  $variables = array(
    'jquery_update_custom_path_cookie',
    'jquery_update_custom_path_form',
    'jquery_update_custom_path_jquery',
    'jquery_update_custom_path_jqueryui',
    'jquery_update_custom_path_migrate',
    'jquery_update_custom_version_jquery',
    'jquery_update_custom_version_jquery_cookie',
    'jquery_update_custom_version_jquery_form',
    'jquery_update_custom_version_jquery_migrate',
    'jquery_update_custom_version_jqueryui',
  );
  foreach ($variables as $variable) {
    if (empty($form_state['values'][$variable])) {
      unset($form_state['values'][$variable]);
      variable_del($variable);
    }
  }
}

/**
 * Late submit handler for settings form.
 */
function jquery_update_settings_form_submit_late($form, &$form_state) {
  // Special handling for the first time a custom jQuery version is configured.
  if (isset($form_state['values']['jquery_update_custom_version_jquery'])) {
    $custom_version = $form_state['values']['jquery_update_custom_version_jquery'];
    // If the custom version is not yet available as an option in the form, set
    // it as the default anyway. This avoids new custom versions requiring two
    // submissions of the admin form.
    if (!in_array($custom_version, array_keys($form['jquery_update_jquery_version']['#options']))) {
      variable_set('jquery_update_jquery_version', $custom_version);
    }
  }
}

/**
 * The Latest versions fieldset.
 */
function jquery_update_add_latest_version_info(&$form) {

  $form['jquery_latest_versions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Latest versions'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => FALSE,
    '#group' => 'jquery_update',
    '#description' => t('Information about the latest available versions of the jQuery libraries the jQuery Update module integrates.'),
  );

  $last_update = variable_get('jquery_update_latest_versions_checked', FALSE);
  if ($last_update) {
    $message = t('Version info last updated %datetime', array('%datetime' => format_date($last_update)));
    $form['jquery_latest_versions']['#description'] .= '<br />' . $message;
  }

  $refresh_url = url('admin/config/development/jquery_update/refresh-version-info',
    array(
      'query' => array(
        'token' => drupal_get_token('refresh-version-info'),
      ),
    )
  );
  $form['jquery_latest_versions']['refresh_version_info'] = array(
    '#type' => 'item',
    '#markup' => '<a href="' . $refresh_url . '">' . t('Refresh version info manually') . '</a>',
  );

  $updates_available = _jquery_update_check_available_updates();
  $libraries = array(
    'jquery',
    'jqueryui',
    'jquery-migrate',
    'jquery.form',
    'jquery-cookie',
  );
  foreach ($libraries as $library) {
    $version = jquery_update_latest_version($library);
    $form['jquery_latest_versions']['latest_version_' . $library] = array(
      '#type' => 'item',
      '#title' => t('Library: %library', array('%library' => $library)),
      '#markup' => t('Latest version: %version', array('%version' => $version)),
    );
    if (in_array($library, $updates_available)) {
      $custom_version = variable_get('jquery_update_custom_version_' . _jquery_update_clean_library_name($library), 'error');
      $message = t('An update (%update) is available for the current custom version (%current) of the %library library.',
        array(
          '%update' => $version,
          '%current' => $custom_version,
          '%library' => $library,
        )
      );
      $form['jquery_latest_versions']['latest_version_' . $library]['#description'] = '<strong>' . $message . '</strong>';
      if (variable_get('jquery_update_warning_available_update', TRUE)) {
        drupal_set_message($message, 'warning', FALSE);
      }
    }
  }

  $form['jquery_latest_versions']['jquery_update_check_latest_versions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Check latest version info?'),
    '#default_value' => variable_get('jquery_update_check_latest_versions', TRUE),
    '#description' => t('If enabled, jQuery Update checks %cdnjs for latest version info no more than once a day via cron.', array(
      '%cdnjs' => 'api.cdnjs.com',
    )),
  );
  $form['jquery_latest_versions']['jquery_update_warning_available_update'] = array(
    '#type' => 'checkbox',
    '#title' => t('Warn about available updates?'),
    '#default_value' => variable_get('jquery_update_warning_available_update', TRUE),
    '#description' => t("If enabled, jQuery Update will warn about available updates via messages in its admin UI and the main Status report."),
  );
}

/**
 * Menu callback to refresh jQuery libraries latest version info.
 *
 * @see system_run_cron()
 */
function jquery_update_refresh_version_info() {
  if (!isset($_GET['token']) || !drupal_valid_token($_GET['token'], 'refresh-version-info')) {
    return MENU_ACCESS_DENIED;
  }

  _jquery_update_refresh_version_info(TRUE);
  drupal_set_message(t('Attempted to refresh latest version info.'));

  drupal_goto('admin/config/development/jquery_update', array('fragment' => 'edit-jquery-latest-versions'));
}
