<?php
/**
 * @file
 * MailhandlerMultipleEmailAuthenticate class.
 */

$plugin = array(
  'name' => 'Multiple Email authentication',
  'description' => 'Authenticate messages using Multiple Email module',
  'handler' => array(
    'class' => 'MailhandlerMultipleEmailAuthenticate',
    'parent' => 'MailhandlerAuthenticate',
  ),
);
