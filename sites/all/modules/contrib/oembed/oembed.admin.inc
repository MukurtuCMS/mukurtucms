<?php

/**
 * @file
 * OEmbed admin pages.
 */

/**
 * oEmbed admin settings page callback.
 */
function oembed_settings() {
  $form = array();
  $period = drupal_map_assoc(array(3600, 10800, 21600, 32400, 43200, 86400, 172800, 259200, 604800, 1209600, 2419200, 4838400, 9676800), 'format_interval');
  $period[CACHE_PERMANENT] = t('Indefinite');
  $form['oembed_cache_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('Minimum oEmbed cache lifetime'),
    '#options' => $period,
    '#default_value' => variable_get('oembed_cache_lifetime', 3600),
    '#description' => t('Cached oEmbed output will not be re-requested until at least this much time has elapsed.'),
  );
  $form['oembed_cache_flush'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clear oEmbed cache when all Drupal caches are cleared'),
    '#default_value' => variable_get('oembed_cache_flush', TRUE),
    '#description' => t('Unselect this to retain unexpired cached oEmbed output even when drupal_flush_all_caches() is called. In conjunction with a long %lifetime, this can help reduce costs when using an oEmbed provider service that charges a fee per request.', array('%lifetime' => t('Minimum oEmbed cache lifetime'))),
  );
  return system_settings_form($form);
}

/**
 * oEmbed sandbox callback.
 */
function oembed_test($form, &$form_state) {
  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#description' => t('URL to request from oEmbed provider'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  if (isset($form_state['embed'])) {
    $form['response'] = array(
      '#type' => 'container',
    );
    $form['response']['display']['oembed'] = array(
      '#type' => 'fieldset',
      '#title' => t('oEmbed'),
    );
    $form['response']['display']['oembed'][] = $form_state['display']['oembed'];
    $form['response']['display']['oembed'][] = array(
      '#prefix' => '<pre>',
      '#markup' => check_plain(drupal_render($form_state['display']['oembed'])),
      '#suffix' => '</pre>',
    );

    $form['response']['display']['oembed_thumbnail'] = array(
      '#type' => 'fieldset',
      '#title' => t('oEmbed Thumbnail'),
    );
    $form['response']['display']['oembed_thumbnail'][] = $form_state['display']['oembed_thumbnail'];
    $form['response']['display']['oembed_thumbnail'][] = array(
      '#prefix' => '<pre>',
      '#markup' => check_plain(drupal_render($form_state['display']['oembed_thumbnail'])),
      '#suffix' => '</pre>',
    );
    $form['response']['details'] = array(
      '#type' => 'fieldset',
      '#title' => t('Details'),
    );
    $form['response']['details']['data'] = array(
      '#prefix' => '<pre>',
      '#markup' => $form_state['embed'],
      '#suffix' => '</pre>',
    );
  }
  return $form;
}

/**
 * Validate input by attemping to request URL and generate display.
 */
function oembed_test_validate($form, &$form_state) {

  // Normalize input and look up
  $url = $form_state['values']['url'];
  $embed = oembed_get_data($url);
  if (!empty($embed)) {
    $form_state['embed'] = check_plain(print_r($embed, TRUE));
    $form_state['display']['oembed'] = oembed_render_element('oembed', $url);
    $form_state['display']['oembed_thumbnail'] = oembed_render_element('oembed_thumbnail', $url);
  }
  else {
    form_set_error('url', t("%input is not valid oEmbed URL. Please check the !link for messages.", array('%input' => $form_state['values']['url'], '!link' => l(t("error log"), 'admin/reports/dblog'))));
  }
}

/**
 * Rebuild form.
 */
function oembed_test_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}
