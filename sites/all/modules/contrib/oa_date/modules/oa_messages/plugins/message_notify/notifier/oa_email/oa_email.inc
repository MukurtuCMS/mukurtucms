<?php

/**
 * @file
 * Provides a message notifier that extends the default's email capabilities
 * with some Open Atrium specific additions.
 */

$plugin = array(
  'title' => t('OA Email'),
  'description' => t('Send Message via email, with Open Atrium enchancements.'),
  'class' => 'OaEmail',
  'options' => array(
    'html' => TRUE,
    'to' => FALSE,
    'from' => FALSE,
  ),
  // A notifier must define its own view modes.
  // Those view modes are later going to be rendered and sent.
  'view_modes' => array(
    'message_notify_email_subject' => array('label' => t('Notify - Email subject')),
    'message_notify_email_body' => array('label' => t('Notify - Email body')),
  ),
);

