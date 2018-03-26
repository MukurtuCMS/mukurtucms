<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function mukurtu_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {
  // Mukurtu.
  $form['mukurtu'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mukurtu'),
    //'#group' => 'mukurtu',
  );

  // Footer.
  $form['mukurtu']['footer'] = array(
    '#type' => 'fieldset',
    '#title' => t('Footer'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Email us text.
  $form['mukurtu']['footer']['mukurtu_theme_email_us_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Email us text'),
    '#default_value' => theme_get_setting('mukurtu_theme_email_us_message', 'mukurtu'),
    '#description'   => t("Leave empty to omit from display."),
  );

  // Contact email.
  $form['mukurtu']['footer']['mukurtu_theme_contact_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Contact email address'),
    '#default_value' => theme_get_setting('mukurtu_theme_contact_email', 'mukurtu'),
    '#description'   => t("Leave empty to omit from display."),
  );

  // Twitter.
  $form['mukurtu']['footer']['mukurtu_theme_twitter_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter message text'),
    '#default_value' => theme_get_setting('mukurtu_theme_twitter_message', 'mukurtu'),
    '#description'   => t("Leave empty to omit from display."),
  );

  $form['mukurtu']['footer']['mukurtu_theme_twitter1'] = array(
    '#type' => 'textfield',
    '#title' => t('First Twitter account'),
    '#default_value' => theme_get_setting('mukurtu_theme_twitter1', 'mukurtu'),
    '#description'   => t("Leave empty to omit from display."),
  );

  $form['mukurtu']['footer']['mukurtu_theme_twitter2'] = array(
    '#type' => 'textfield',
    '#title' => t('Second Twitter account'),
    '#default_value' => theme_get_setting('mukurtu_theme_twitter2', 'mukurtu'),
    '#description'   => t("Leave empty to omit from display."),
  );

  // Copyright message.
  $form['mukurtu']['footer']['mukurtu_theme_copyright'] = array(
    '#type' => 'textfield',
    '#title' => t('Footer Copyright Message'),
    '#default_value' => theme_get_setting('mukurtu_theme_copyright', 'mukurtu'),
    '#description'   => t("Use replacement token [year] for the current year."),
  );

}