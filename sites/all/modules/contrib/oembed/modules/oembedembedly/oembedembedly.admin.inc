<?php

/**
 * Admin form to configure embedly provider.
 */
function oembedembedly_admin() {
  $providers = oembedembedly_providers();
  $selections = oembedembedly_default_selected();
  $types = array();
  $form = array();
  $form['oembedembedly_providers'] = array(
    '#type' => 'fieldset',
    '#title' => 'Providers',
    '#weight' => 1,
    '#description' => t('Embedly directly integrates with <a href="@providers">@count content providers</a>. You can control which Embedly providers are supported on your site by enabling or disabling them individually.', array('@count' => count($providers), '@providers' => 'http://embed.ly/providers')),
  );

  foreach ($providers as $provider) {
    $variables = array(
      'path' => $provider->favicon,
      'width' => 16,
      'height' => 16,
      'alt' => $provider->displayname,
    );
    $title = theme('image',  $variables) .' '. $provider->displayname;
    $element = array(
      '#type' => 'checkbox',
      '#title' => $title,
      '#description' => $provider->about,
      '#default_value' => $selections[$provider->name],
      '#parents' => array('oembedembedly_providers', $provider->name),
    );
    $form['oembedembedly_providers'][$provider->type][$provider->name] = $element;

    if (!isset($types[$provider->type])) {
      $types[$provider->type] = array(
        '@type' => $provider->type,
        '@count' => 0,
        '@enabled' => 0,
      );
    }
    $types[$provider->type]['@count']++;
    if ($selections[$provider->name]) {
      $types[$provider->type]['@enabled']++;
    }
  }

  foreach (element_children($form['oembedembedly_providers']) as $key) {
    $element = &$form['oembedembedly_providers'][$key];
    $element['#type'] = 'fieldset';
    $element['#collapsible'] = TRUE;
    $element['#collapsed'] = TRUE;
    $element['#title'] = t("@type (@enabled of @count enabled)", $types[$key]);
  }

  $form['oembedembedly_providers']['oembedembedly_schemes'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Additional schemes'),
    '#required'      => FALSE,
    '#default_value' => variable_get('oembedembedly_schemes', ''),
    '#description'   => t('Newline separated list of schemes like !example. To make Embedly handle all requests, add !wildcard.', array('!example' => 'http://*.revision3.com/*', '!wildcard' => '*')),
  );

  $form['oembedembedly_default'] = array(
    '#type'          => 'radios',
    '#title'         => t('Providers enabled by default'),
    '#default_value' => variable_get('oembedembedly_default', TRUE),
    '#options'       => array(
      FALSE => t('Disabled'),
      TRUE  => t('Enabled'),
    ),
    '#description'   => t('This option defines whether providers should be enabled by default or not.'),
  );
  $form['oembedembedly_api_key'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Embedly API Key'),
    '#default_value' => variable_get('oembedembedly_api_key', NULL),
    '#description'   => t('Embedly requires developers to authenticate their requests to all endpoints. You must <a href="@pricing">sign up for any of the plans</a> to receive a key.', array('@pricing' => 'http://embed.ly/pricing')),
  );

  $form['#submit'][] = 'oembedembedly_admin_submit';
  return system_settings_form($form);
}

/**
 * Submit handler clears cache to refresh providers.
 */
function oembedembedly_admin_submit($form, &$form_state) {
  oembed_providers_reset();
}
