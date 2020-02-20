<?php

/**
 * @file
 * Admin settings.
 */

/**
 * Page callback to show the settings for the attachments.
 */
function search_api_attachments_settings_form($form, &$form_state) {
  $form['search_api_attachments_extract_using'] = array(
    '#type' => 'radios',
    '#title' => t('Extraction method'),
    '#options' => array(
      'pdftotext' => t('Pdftotext'),
      'python_pdf2txt' => t('Pdf2txt (local python application)'),
      'solr' => t('Solr (remote server)'),
      'tika' => t('Tika (local java application)'),
      'tika_server' => t('Tika (server)'),
    ),
    '#description' => t('Choose extraction method, remote or local (extraction will be faster if run locally using tika).'),
    '#default_value' => variable_get('search_api_attachments_extract_using', 'tika'),
  );
  $form['search_api_attachments_tika_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tika extraction settings'),
    '#description' => t('Required if using the "Tika" extraction method (above).'),
    '#collapsible' => TRUE,
  );
  $form['search_api_attachments_tika_settings']['search_api_attachments_tika_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Tika directory path:'),
    '#default_value' => variable_get('search_api_attachments_tika_path', ''),
    '#description' => t('The full path to tika directory. All library jars must be in the same directory. E.g. /var/apache-tika-4.0/'),
  );
  $form['search_api_attachments_tika_settings']['search_api_attachments_tika_jar'] = array(
    '#type' => 'textfield',
    '#title' => t('Tika jar file:'),
    '#default_value' => variable_get('search_api_attachments_tika_jar', 'tika-app-1.6.jar'),
    '#description' => t('The name of the tika CLI application jar file, e.g. tika-app-1.6.jar.'),
  );
  $form['search_api_attachments_tika_server_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tika server settings'),
    '#description' => t('Required if using the "Tika" server method (above).'),
    '#collapsible' => TRUE,
  );
  $form['search_api_attachments_tika_server_settings']['search_api_attachments_tika_server_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Host:'),
    '#default_value' => variable_get('search_api_attachments_tika_server_host', 'localhost'),
    '#description' => t('The current host name, E.g. localhost'),
  );
  $form['search_api_attachments_tika_server_settings']['search_api_attachments_tika_server_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Port:'),
    '#default_value' => variable_get('search_api_attachments_tika_server_port', 9998),
    '#description' => t('The port tika server is running on'),
  );
  $form['search_api_attachments_python_pdf2txt_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pdf2txt extraction settings'),
    '#description' => t('Required if using the "Pdf2txt" extraction method (above).'),
    '#collapsible' => TRUE,
  );
  $form['search_api_attachments_python_pdf2txt_settings']['search_api_attachments_python_pdf2txt_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Pdf2txt directory path:'),
    '#default_value' => variable_get('search_api_attachments_python_pdf2txt_path', '/usr/bin'),
    '#description' => t('The full path to python_pdf2txt directory. All library jars must be in the same directory. E.g. /usr/bin'),
  );
  $form['search_api_attachments_python_pdf2txt_settings']['search_api_attachments_python_pdf2txt_script'] = array(
    '#type' => 'textfield',
    '#title' => t('Pdf2txt Script file:'),
    '#default_value' => variable_get('search_api_attachments_python_pdf2txt_script', 'pdf2txt'),
    '#description' => t('The name of the pdf2txt Python Script file, e.g. pdf2txt.'),
  );
  $form['search_api_attachments_solr_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Solr extraction settings'),
    '#description' => t('Required if using the "Solr" extraction method (above).'),
    '#collapsible' => TRUE,
  );
  $form['search_api_attachments_solr_settings']['search_api_attachments_extracting_servlet_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr extracting servlet path:'),
    '#default_value' => variable_get('search_api_attachments_extracting_servlet_path', 'update/extract'),
    '#description' => t('The path to the extracting servlet. E.g. update/extract or extract/tika'),
  );
  $form['search_api_attachments_cache_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Caching settings'),
    '#collapsible' => TRUE,
  );
  $form['search_api_attachments_cache_settings']['search_api_attachments_preserve_cache'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('search_api_attachments_preserve_cache', FALSE),
    '#title' => t('Preserve cached extractions across cache clears.'),
    '#description' => t('When checked, clearing the sidewide cache will not clear the cache of extracted files.'),
  );
  $form['search_api_attachments_debug'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('search_api_attachments_debug', FALSE),
    '#title' => t('Debug extraction of attachments.'),
    '#description' => t('When checked, debugging statements will be logged to watchdog.'),
  );
  return system_settings_form($form);
}

/**
 * Validation handler for the settings form.
 */
function search_api_attachments_settings_form_validate($form, &$form_state) {
  // We only need to validate the tika path if we're using local extraction.
  if ($form_state['values']['search_api_attachments_extract_using'] == 'tika') {
    // Tika extraction without tika jar error.
    if (empty($form_state['values']['search_api_attachments_tika_jar'])) {
      form_set_error('search_api_attachments_tika_jar', t('Tika jar is mandatory.'));
    }

    // Check that the file exists.
    $path = realpath($form_state['values']['search_api_attachments_tika_path']);
    $tika = $path . '/' . $form_state['values']['search_api_attachments_tika_jar'];
    if (!file_exists($tika)) {
      form_set_error('search_api_attachments_tika_path', t('Tika jar file not found at this path.'));
    }
    // Check that the file is an executable jar.
    else {
      $cmd = escapeshellcmd(variable_get('search_api_attachments_java', 'java')) . ' -jar ' . escapeshellarg($tika) . ' -V';
      exec($cmd, $output, $return_code);
      // $return_code = 1 if it fails. 0 instead.
      if ($return_code) {
        form_set_error('search_api_attachments_tika_path', t('There may be a problem with tika path.'));
        form_set_error('search_api_attachments_tika_jar', t('Tika jar file is not an executable jar. Please check if you have not downloaded a corrupted jar file.'));
      }
    }
  }
  elseif ($form_state['values']['search_api_attachments_extract_using'] == 'python_pdf2txt') {
    // Pdf2txt extraction without pdf2txt python script error.
    if (empty($form_state['values']['search_api_attachments_python_pdf2txt_script'])) {
      form_set_error('search_api_attachments_python_pdf2txt_script', t('Pdf2txt Python script is mandatory.'));
    }

    // Check that the file exists.
    $path = realpath($form_state['values']['search_api_attachments_python_pdf2txt_path']);
    $pdf2txt = $path . '/' . $form_state['values']['search_api_attachments_python_pdf2txt_script'];
    if (!file_exists($pdf2txt)) {
      form_set_error('search_api_attachments_python_pdf2txt_path', t('Pdf2txt Python script not found at this path.'));
    }
    // Check that the file is an executable Python Script.
    else {
      $cmd = escapeshellcmd('python') . ' ' . escapeshellarg($pdf2txt);
      exec($cmd, $output, $return_code);
      // $return_code = 1 if it fails. 100 instead.
      if ($return_code != 100) {
        form_set_error('search_api_attachments_python_pdf2txt_path', t('There may be a problem with python pdf2txt path.'));
        form_set_error('search_api_attachments_python_pdf2txt_script', t('Pdf2txt Python script file is not executable.'));
      }
    }
  }
  elseif ($form_state['values']['search_api_attachments_extract_using'] == 'tika_server') {
    // Set server URL.
    $server = 'http://' . $form_state['values']['search_api_attachments_tika_server_host'] . ':' . $form_state['values']['search_api_attachments_tika_server_port'] . '/tika';

    $ch = curl_init($server);
    // Check if server exists.
    curl_exec($ch);
    $httpCode = curl_getinfo($ch, CURLINFO_HTTP_CODE);

    if ($httpCode != 200) {
      form_set_error('search_api_attachments_tika_server_host', t('No tika server was found. Please check if host and server are correct'));
    }

    curl_close($ch);
  }
}
