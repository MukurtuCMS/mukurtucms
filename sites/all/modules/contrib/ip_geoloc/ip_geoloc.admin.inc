<?php

/**
 * @file
 * Admin configuration settings for IPGV&M.
 */

/**
 * Menu callback for admin settings.
 */
function ip_geoloc_admin_configure() {

  global $base_url;

  $form['ip_geoloc_google_auth'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authentication of maps and geolocation services'),
    '#description' => t('The <a target="_blank" href="!url1">Google Maps API</a>, which include geolocation services, requires either a Google API Key or a Google Client ID. <br/>If you are using <a target="_blank" href="!url2">Leaflet maps</a> you may still need a Google API Key or Client ID when you use this module\'s geolocation services also.', array(
      '!url1' => url('https://developers.google.com/maps/documentation/javascript/get-api-key'),
      '!url2' => url('http://leafletjs.com'),
    )),
  );

  $form['ip_geoloc_google_auth']['ip_geoloc_auth_method'] = array(
    '#type' => 'select',
    '#title' => t('Select Google API Authentication Method'),
    '#description' => t('Google API Authentication Method'),
    '#default_value' => variable_get('ip_geoloc_auth_method', 1),
    '#options' => array(
      1 => t('API Key'),
      2 => t('Client ID'),
    ),
  );

  $form['ip_geoloc_google_auth']['ip_geoloc_apikey'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps API Key'),
    '#description' => t('Obtain a Google Maps Javascript API key <a href="!url">here</a>.', array(
      '!url' => url('https://developers.google.com/maps/documentation/javascript/get-api-key'),
    )),
    '#default_value' => variable_get('ip_geoloc_apikey', ''),
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="ip_geoloc_auth_method"]' => array('value' => 1),
      ),
    ),
  );

  $form['ip_geoloc_google_auth']['ip_geoloc_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Client ID'),
    '#description' => t('For more information, visit <a href="!url">this page</a>.', array(
      '!url' => url('https://developers.google.com/maps/documentation/javascript/get-api-key#client-id'),
     )),
    '#default_value' => variable_get('ip_geoloc_client_id', ''),
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
         ':input[name="ip_geoloc_auth_method"]' => array('value' => 2),
      ),
    ),
  );

  $form['ip_geoloc_google_auth']['ip_geoloc_signature'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Signature'),
    '#description' => t('May not be required. Check the Google documentation.'),
    '#default_value' => variable_get('ip_geoloc_signature', ''),
    '#required' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="ip_geoloc_auth_method"]' => array('value' => 2),
      ),
    ),
  );

  $form['markers'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Alternative markers'),
  );
  $markers_path = drupal_get_path('module', 'ip_geoloc');
  $form['markers']['ip_geoloc_marker_directory'] = array(
    '#type' => 'textfield',
    '#title' => t('<strong>Google Maps, Leaflet</strong>: path to marker images'),
    '#field_prefix' => "$base_url/",
    '#default_value' => ip_geoloc_marker_directory(),
    '#description' => t('Marker sets included with the module reside in %set1 and %set2. All marker images must be .png files.', array(
      '%set1' => "$markers_path/markers",
      '%set2' => "$markers_path/amarkers",
    )),
  );
  $form['markers']['ip_geoloc_marker_dimensions'] = array(
    '#type' => 'textfield',
    '#title' => t('<strong>Google Maps, Leaflet</strong>: marker image width and height'),
    '#default_value' => ip_geoloc_marker_dimensions(),
    '#field_suffix' => t('px'),
    '#description' => t('These dimensions apply to all markers in the set. The default marker size is 21 x 34 for the <em>/markers</em> directory and 32 x 42 for the <em>/amarkers</em> directory.'),
  );
  $form['markers']['ip_geoloc_marker_anchor_pos'] = array(
    '#title' => t('<strong>Google Maps, Leaflet</strong>: marker image anchor position'),
    '#type' => 'select',
    '#default_value' => variable_get('ip_geoloc_marker_anchor_pos', 'bottom'),
    '#options' => array(
      'top' => t('Center of topline'),
      'middle' => t('Center of image'),
      'bottom' => t('Center of baseline'),
    ),
    '#description' => t('This anchor position is applied to all markers in the set.'),
  );
  $form['markers']['ip_geoloc_num_location_marker_layers'] = array(
    '#type' => 'textfield',
    '#title' => t('<strong>OpenLayers only</strong>: maximum number of marker layers you may need'),
    '#default_value' => variable_get('ip_geoloc_num_location_marker_layers', IP_GEOLOC_DEF_NUM_MARKER_LAYERS),
    '#description' => t('Only relevant when you have selected "differentiator" fields in your view.'),
  );
  $benefits = t('Some of the benefits of font icons are explained <a target="flink" href="!url_flink">here</a>.', array(
    '!url_flink' => url('http://flink.com.au/ramblings/spruce-your-map-markers-font-icons')
  ));
  $form['font_icons'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Font icons (Leaflet only)'),
    '#description' => $benefits . '<br/>' .
      t('If you decide to use them, a good spot to put the font icon libraries you choose to download is in subdirectories of %url_libs.<br/>Each font icon library normally contains a CSS file through which other files in the library are found. Type the filespec of those CSS files below, one per library. After you have saved the configuration, check the <a target="status" href="!url_status">status report</a> page for errors.<br/><strong>Example 1</strong>, <a target="fontawesome" href="!url_fontawesome">Font Awesome</a>: %css_file1 <br/><strong>Example 2</strong>, <a target="flaticon" href="!url_flaticon">flaticon</a>: %css_file2', array(
      '%url_libs' => '/sites/all/libraries',
      '!url_fontawesome' => url('http://fortawesome.github.io/Font-Awesome'),
      '%css_file1' => 'sites/all/libraries/font-awesome/css/font-awesome.min.css',
      '!url_flaticon' => url('http://flaticon.com'),
      '%css_file2' => 'sites/all/libraries/flaticon/food-icons/flaticon.css',
      '!url_status' => url('admin/reports/status'),
    )),
  );
  $libs = ip_geoloc_get_font_icon_libs();
  $count = max(2, min(count($libs) + 1, IP_GEOLOC_MAX_NUM_FONT_ICON_LIBS));
  for ($i = 1; $i <= $count; $i++) {
    $form['font_icons']["ip_geoloc_font_icon_lib$i"] = array(
      '#type' => 'textfield',
      '#field_prefix' => "$base_url/",
      '#title' => t('Main CSS file belonging to font icon library #@i', array('@i' => $i)),
      '#default_value' => empty($libs[$i]) ? '' : $libs[$i],
    );
  }
  $form['font_icons']["ip_geoloc_font_icon_lib$count"]['#description'] =
    t('<strong>Note:</strong> as explained in this <a target="issue" href="!url_issue">issue</a>, you cannot have identical leaf names amongst the CSS filespecs. Rename .css files if there are clashes.', array(
      '!url_issue' => url('https://www.drupal.org/node/1885838#comment-8996119'),
    ));

  if (ip_geoloc_diagnose() > 0) {
    // Form for sync-ing the geolocation table with the system accesslog.
    $form['ip_geoloc_db_options'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#title' => t('Update IP geolocation database using past visitor IP addresses from the system access log'),
      '#description'  => t('You can update the IP geolocation database in batches by pressing the button below. As a rough guide, count on a 1 minute wait for every 100 IP addresses, when executing a web service like IPInfoDB, as employed by Smart IP. Add another 2 minutes per 100 IP addresses if you ticked the option to employ the Google Maps API to reverse-geocode to street addresses. If your server interrupts the process you can continue from where it stopped by refreshing this page and pressing the button again. You will not lose any data.'),
    );
    $form['ip_geoloc_db_options']['ip_geoloc_sync_with_accesslog'] = array(
      '#type' => 'submit',
      '#value' => t('Update now'),
      '#submit' => array('ip_geoloc_sync_with_accesslog'),
    );
    $form['ip_geoloc_db_options']['ip_geoloc_sync_batch_size'] = array(
      '#type' => 'textfield',
      '#size' => 4,
      '#title' => t('Batch size'),
      '#default_value'  => variable_get('ip_geoloc_sync_batch_size', 500),
      '#description' => t('To change the default batch size, press "Save configuration".'),
    );
  }

  $form['ip_geoloc_data_collection_options'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Data collection options'),
  );
  $form['ip_geoloc_data_collection_options']['ip_geoloc_allow_session_storage'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow session storage'),
    '#default_value' => variable_get('ip_geoloc_allow_session_storage', TRUE),
    '#description' => t('The current visitor\'s location data is temporarily stored in either the $_SESSION variable or via the module <a target="_project" href="@url_project">Session Cache API</a>, if enabled. <br/>To disable both of these session storage functions, untick this box. However unticking this box means you will lose all functions regarding Wifi/GPS-based visitor geolocation. Location of the visitor based on IP address through either the <strong>Smart IP</strong> or <strong>GeoIP</strong> modules will continue to operate normally, if enabled.', array(
      '@url_project' => url('http://drupal.org/project/session_cache'),
    )),
  );
  $form['ip_geoloc_data_collection_options']['ip_geoloc_store_addresses'] = array(
    '#type' => 'checkbox',
    '#title' => t('Store reverse-geocoded addresses with their corresponding latitude/longitude on the database'),
    '#default_value' => variable_get('ip_geoloc_store_addresses', TRUE),
    '#description' => t('This allows you to create maps of recent visitors to your site.'),
  );
  $note1 = t('Untick, if you do not need periodic visitor location updates. Consider the <em>Set my location</em> block as an alternative.');
  $note2 = t('You can also use the <a href="@project_context">Context module</a> to conditionally geolocate the visitor based on device type, page visited etc.', array('@project_context' => url('http://drupal.org/project/context')));
  $note3 = ''; // t('Used in conjunction with the options below.');
  $form['ip_geoloc_data_collection_options']['ip_geoloc_google_to_reverse_geocode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Employ a free Google service to <em>periodically</em> auto reverse-geocode visitor locations to street addresses'),
    '#default_value' => variable_get('ip_geoloc_google_to_reverse_geocode', FALSE),
    '#description' => "$note1<br>$note2<br/>"
      . t('Reverse-geocoding takes place via the Javascript version of the Google Maps API and the HTML5 way of obtaining a visitor\'s location. This involves visitors being prompted to accept sharing of their location.<br/>For the upload of historic visitor location data the server-side version of the Google Maps API is used. The latter is subject to a Google-imposed daily limit on the number of calls coming from the same server.')
      . '<br/>' . $note3,
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_allow_session_storage"]' => array('checked' => TRUE)),
    ),
  );
  $form['ip_geoloc_data_collection_options']['ip_geoloc_location_check_interval'] = array(
    '#type' => 'textfield',
    '#size' => 10,
    '#field_suffix' => t('seconds'),
    '#title' => t('Minimum elapsed time before geolocation data for the same user will be collected again'),
    '#default_value' => variable_get('ip_geoloc_location_check_interval', IP_GEOLOC_LOCATION_CHECK_INTERVAL),
    '#description' => t('Operates in combination with the checkbox above. Geolocation information associated with an IP address may change over time, for instance when the visitor is using a mobile device and is moving. Use zero to geolocate the visitor <em>once</em> and then refrain from repeat location collection until their session has expired.'),
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_allow_session_storage"]' => array('checked' => TRUE)),
    ),
  );
  $form['ip_geoloc_data_collection_options']['ip_geoloc_include_pages'] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t("Pages on which the visitor's HTML5 location may be sampled and reverse-geocoded to a street address"),
    '#default_value' => variable_get('ip_geoloc_include_pages', '*'),
    '#description' => t("Enter relative paths, one per line. Where they exist use the URL aliases rather than the node numbers. <strong>&lt;front&gt;</strong> means the front page.<br/>The asterisk <em>*</em> is the wildcard character, i.e. <em>recipes/mains*</em> denotes all pages that have a path starting with <em>recipes/mains</em><br/>The asterisk by itself means any page on your site."),
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_allow_session_storage"]' => array('checked' => TRUE)),
    ),
  );
  $form['ip_geoloc_data_collection_options']['ip_geoloc_exclude_pages'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Exceptions: pages excluded from the set of pages specified above'),
    '#default_value' => variable_get('ip_geoloc_exclude_pages', IP_GEOLOC_DEFAULT_PAGE_EXCLUSIONS),
    '#description' => t('As above, one path specification per line.'),
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_allow_session_storage"]' => array('checked' => TRUE)),
    ),
  );
  $form['ip_geoloc_data_collection_options']['ip_geoloc_roles_to_reverse_geocode'] = array(
    '#type' => 'checkboxes',
    '#title' => t("User roles for which the HTML5 location may be sampled and reverse-geocoded to a street address"),
    '#default_value' => variable_get('ip_geoloc_roles_to_reverse_geocode', array(DRUPAL_ANONYMOUS_RID, DRUPAL_AUTHENTICATED_RID)),
    '#options' => user_roles(),
    '#description' => t('Selected roles are effective only when the check box on the data collection option above is also ticked.'),
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_allow_session_storage"]' => array('checked' => TRUE)),
    ),
  );

  $form['ip_geoloc_data_collection_options']['ip_geoloc_smart_ip_as_backup'] = array(
    '#type' => 'checkbox',
    '#title' => t('Employ Smart IP as a backup to the Google Maps JS API as well as declined or failed HTML5 location retrievals in Views'),
    '#default_value' => variable_get('ip_geoloc_smart_ip_as_backup', FALSE),
    '#description' => t('This refers to situations where the lat/long coords could not be established. An example is the user declining to share their location. Another is when the Google Maps API reverse-geocode function fails or is not enabled through the tick box at the top of this section.<br/>Smart IP lookups tend to be less detailed than the Google Maps reverse-geocoded results.<br/>If this box is <strong>not</strong> ticked, but the <a href="@geoip">GeoIP API module</a> is enabled, then GeoIP will be used as the Google Maps API fallback and to load historic lat/long coordinates.', array(
      '@geoip' => url('http://drupal.org/project/geoip'),
    )),
    '#states' => array(
      'visible' => array('input[name="ip_geoloc_allow_session_storage"]' => array('checked' => TRUE)),
    ),
  );
  $form['ip_geoloc_data_collection_options']['ip_geoloc_throbber_text2'] = array(
    '#type' => 'textfield',
    '#title' => t('Message displayed while visitor is being geolocated'),
    '#size' => 30,
    '#default_value' => variable_get('ip_geoloc_throbber_text2', ''),
    '#description' => t('A standard status message to show the visitor that geolocation was initiated and is in progress. </br/>Defaults to %default <br/>You may use most HTML tags. Use <em>&lt;none&gt;</em> to have no message shown, which is probably the preferred choice if the <strong>Auto-refresh</strong> box below is unticked.', array(
      '%default' => IP_GEOLOC_THROBBER_DEFAULT_TEXT,
    )),
  );

  $form['ip_geoloc_advanced'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Advanced options'),
  );
  $form['ip_geoloc_advanced']['ip_geoloc_page_refresh'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto-refresh the page as soon as an HTML5 location update has come in'),
    '#default_value' => variable_get('ip_geoloc_page_refresh', TRUE),
    '#description' => t('The above tick box does not apply to administration pages.'),
  );
  $form['ip_geoloc_advanced']['ip_geoloc_debug'] = array(
    '#type' => 'textfield',
    '#title' => t('Detail execution progress with status messages'),
    '#default_value' => variable_get('ip_geoloc_debug'),
    '#description' => t('Enter a comma-separated list of names of users that should see status messages coming from this module, e.g., for debugging purposes. Use <strong>anon</strong> for the anonymous user.'),
  );
  $form['ip_geoloc_advanced']['ip_geoloc_erase_session'] = array(
    '#type' => 'submit',
    '#value' => t('Erase geolocation data from session now'),
    '#submit' => array('ip_geoloc_erase_session'),
  );
  $form['ip_geoloc_advanced']['ip_geoloc_erase_db'] = array(
    '#type' => 'submit',
    '#value' => t('Erase entire IP geolocation database now'),
    '#submit' => array('ip_geoloc_erase_db'),
  );

  return system_settings_form($form);
}

/**
 * Report on the configuration status.
 *
 * Reports in particular to the system access log, which is required for
 * visitor views and maps.
 *
 * @return int
 *   -1, if there's a problem, otherwise a count of IP addresses not stored
 */
function ip_geoloc_diagnose() {
  $geoloc_count = db_query('SELECT COUNT(DISTINCT ip_address) FROM {ip_geoloc}')->fetchField();
  drupal_set_message(t("The IP geolocation database currently contains information for %geoloc_count visited IP addresses.", array('%geoloc_count' => $geoloc_count)), 'status', FALSE);

  if (!db_table_exists('accesslog')) {
    drupal_set_message(t("The <strong>accesslog</strong> database table does not exist, probably because core's <strong>Statistics</strong> module is not enabled. Views and maps of visitors will not be available until you enable the <strong>Statistics</strong> module and its <strong>access log</strong>. The visitor location map blocks are not affected and should still display."), 'warning');
  }
  elseif (!module_exists('statistics')) {
    drupal_set_message(t('The <strong>Statistics</strong> module is not enabled. Views and maps of visitors will not be available or display errors until you enable the <strong>Statistics</strong> module and its <strong>access log</strong>. The visitor location map blocks are not affected and should still display.'), 'warning');
  }
  else {
    $ip_address_count = db_query('SELECT COUNT(DISTINCT hostname) FROM {accesslog}')->fetchField();
    drupal_set_message(t("The system access log currently contains entries from %ip_address_count IP addresses.", array('%ip_address_count' => $ip_address_count)), 'status', FALSE);
    if (!variable_get('statistics_enable_access_log', FALSE)) {
      drupal_set_message(t('The <strong>Statistics</strong> module is enabled, but its system <strong>access log</strong> is not. Therefore all visitor Views are frozen and will not grow. The visitor location map blocks are not affected and should still display. You can enable the <strong>access log</strong> at <a href="!url">Configuration >> Statistics</a>.',
        array('!url' => url('admin/config/system/statistics'))), 'warning');
    }
    else {
      $non_synched_ips = ip_geoloc_ips_to_be_synched();
      $count = count($non_synched_ips);
      if ($count > 0) {
        $t = t("%count IP addresses in the system access log currently have no associated lat/long or address information on the IP geolocation database. These are the most recent ones: %ips",
          array(
            '%count' => $count,
            '%ips' => implode(', ', array_slice($non_synched_ips, 0, 10, TRUE))));
        drupal_set_message($t, 'status', FALSE);
      }
      else {
        drupal_set_message(t("The IP geolocation database is up to date and in sync with the system access log."), 'status', FALSE);
      }
      return $count;
    }
  }
  return -1;
}

/**
 * Bring the visitor location database up to date with the system accesslog.
 *
 * Go through all the IP addresses in the {accesslog} table (Statistics module).
 * For each IP address not yet recorded in the {ip_geoloc} table, retrieve its
 * geolocation data and store in {ip_geoloc}.
 * This is a one-off process. Once synchronised the {ip_geoloc} table will lock
 * step with the {accesslog} table.
 * Returns the number of {accesslog} records processed or FALSE if no IP
 * geolocation retrieval function was found.
 *
 * Note: modules supported for the backfill currently are:
 *   Smart IP module
 *   GeoIP API module
 *   custom modules that implement hook_get_ip_geolocation_alter().
 */
function ip_geoloc_sync_with_accesslog() {
  // Wipe previous message to avoid confusion.
  drupal_get_messages();

  $use_smart_ip = variable_get('ip_geoloc_smart_ip_as_backup', FALSE) && module_exists('smart_ip');
  $use_google_to_reverse_geocode = variable_get('ip_geoloc_google_to_reverse_geocode', FALSE);

  // From Configuration >> IP Geolocation form.
  $batch_size = check_plain($_POST['ip_geoloc_sync_batch_size']);
  if (empty($batch_size)) {
    $batch_size = variable_get('ip_geoloc_sync_batch_size', 500);
  }
  $ips_to_be_processed = ip_geoloc_ips_to_be_synched();
  if (count($ips_to_be_processed) > $batch_size) {
    $ips_to_be_processed = array_slice($ips_to_be_processed, 0, $batch_size, TRUE);
  }
  $count = count($ips_to_be_processed);

  $batch = array(
    'file' => drupal_get_path('module', 'ip_geoloc') . '/ip_geoloc.admin.inc',
    'operations' => array(array('_ip_geoloc_process_access_log', array(
      $ips_to_be_processed, $use_smart_ip, $use_google_to_reverse_geocode))),
    'title' => t('Processing next %count IP addresses from access log', array(
      '%count' => $count)),
    'progress_message' => t('Time elapsed: @elapsed. Time remaining: @estimate.'),
    'error_message' => t('An error occurred while processing the access log.'),
    'finished' => '_ip_geoloc_process_access_log_finished',
  );
  batch_set($batch);
  return $count;
}

/**
 * Returns a list of IP addresses still to be processed.
 *
 * These are all IP addresses in the current access log that have not yet had
 * their geolocation data added to the ip_geoloc table.
 *
 * @return array
 *   A list of hostnames still to be processed.
 */
function ip_geoloc_ips_to_be_synched() {
  if (!db_table_exists('accesslog')) {
    return array();
  }
  $hostnames = db_query('SELECT DISTINCT hostname FROM {accesslog} ORDER BY aid DESC')->fetchCol('hostname');
  $ip_geolocations = db_query('SELECT DISTINCT ip_address FROM {ip_geoloc}')->fetchCol('ip_address');
  return array_diff($hostnames, $ip_geolocations);
}

/**
 * Erase geoloc data from session.
 */
function ip_geoloc_erase_session() {
  drupal_get_messages();
  _ip_geoloc_set_session_value(FALSE);
  drupal_set_message(t('Geolocation data erased from session.'));
}

/**
 * Delete geoloc data from database.
 */
function ip_geoloc_erase_db() {
  // Wipe previous messages to avoid confusion.
  drupal_get_messages();
  db_delete('ip_geoloc')->execute();
}

/**
 * Callback for ip_geoloc_sync_with_accesslog batch process.
 */
function _ip_geoloc_process_access_log($ips_to_be_processed, $use_smart_ip, $use_google_to_reverse_geocode, &$context) {
  $sandbox = &$context['sandbox'];
  if (!isset($sandbox['progress'])) {
    $sandbox['progress'] = 0;
    $sandbox['max'] = count($ips_to_be_processed);
    $sandbox['ips'] = $ips_to_be_processed;
  }
  $ip_address = array_shift($sandbox['ips']);
  $location = array('ip_address' => $ip_address);

  if ($use_smart_ip) {
    // Depending on the value of the variable 'smart_ip_use_ipinfodb_service'
    // this will either use the IPInfoDB web service or Smart IP's database, as
    // created by importing the MaxMind CSV archive.
    $location = smart_ip_get_location($location['ip_address']);
  }
  else {
    ip_geoloc_use_geoip_api_if_enabled($location);
  }
  // Now that we have lat/long we can reverse-geocode to the street address.
  // Note, this call is subject to a limit of 2500/day.
  if ($use_google_to_reverse_geocode && $google_address = ip_geoloc_reverse_geocode($location['latitude'], $location['longitude'])) {
    // To avoid fields contradicting eachother, should we clear out, rather
    // than merge with whatever Smart IP or GeoIP put in the $location?
    // For example Google normally returns 'locality', whereas and Smart IP and
    // GeoIP return 'city' instead. Similarly 'administrative_area_level_1' vs
    // 'region'.
    // $location = array('ip_address' => $ip_address);
    ip_geoloc_flatten_google_address($google_address, $location);
  }

  if (empty($location['formatted_address'])) {
    // Just so that a record is created and the IP is taken off the list.
    $location['formatted_address'] = '-';
  }
  if (ip_geoloc_store_location($location) === FALSE) {
    return;
  }

  // Update our progress information.
  $sandbox['progress']++;
  // Store result for post-processing in the _finished callback.
  $context['results'][] = $location['ip_address'] . ': ' . (empty($location['formatted_address']) ? '?' : $location['formatted_address']);
  // Provide to the batch engine an estimate of the level of completion so far.
  if ($sandbox['progress'] < $sandbox['max']) {
    // Note the addition of 100 in the formula below. This is to make sure that
    // batch sizes of 200 or greater do not terminate prematurely.
    // E.g 199/200 = 0.995 ends up being rounded to 100% causing abort.
    $context['finished'] = floor(100 * $sandbox['progress'] / $sandbox['max']) / 100;
  }
}

/**
 * Callback to finish batch process.
 */
function _ip_geoloc_process_access_log_finished($success, $results, $operations, $elapsed) {
  if ($success) {
    drupal_set_message(t('%count new IP geolocation records compiled and stored in %elapsed-time.',
      array('%count' => count($results), '%elapsed-time' => $elapsed)));
  }
  else {
    drupal_set_message(t('An error occurred. Processing of the access log did not complete.'), 'error');
    $message = format_plural(count($results), 'One IP address successfully processed:', '@count IP addresses successfully processed:');
    $message .= theme('item_list', array('items' => $results));
    drupal_set_message($message);
  }
}
