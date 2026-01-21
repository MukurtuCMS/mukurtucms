<?php

/**
 * @file
 * Contains implementations of Views hooks.
 */

/**
 * Implements hook_views_data().
 */
function mail_logger_views_data() {
  // Basic table information.
  $data['mail_logger']['table']['group']  = t('Mail log');

  // Advertise this table as a possible base table
  $data['mail_logger']['table']['base'] = array(
    'field' => 'mlid',
    'title' => t('Mail message'),
    'help' => t('A record of a mail sent by the site.'),
    'weight' => 10,
  );

  // Mail id
  $data['mail_logger']['mlid'] = array(
    'title' => t('Mail id'),
    'help' => t('The serial id of the mail log entry.'),
    'field' => array(
      'handler' => 'mail_logger_handler_field_mail_logger_entry',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Mail key
  $data['mail_logger']['mailkey'] = array(
    'title' => t('Mail key'),
    'help' => t('The internal key the mail used for drupal_mail().'),
    'field' => array(
      'handler' => 'mail_logger_handler_field_mail_logger_entry',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // 'From' address
  $data['mail_logger']['mailfrom'] = array(
    'title' => t('From address'),
    'help' => t('The address the mail was sent from.'),
    'field' => array(
      'handler' => 'mail_logger_handler_field_mail',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // 'To' address
  $data['mail_logger']['mailto'] = array(
    'title' => t('To address'),
    'help' => t('The address the mail was sent to.'),
    'field' => array(
      'handler' => 'mail_logger_handler_field_mail',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Subject
  $data['mail_logger']['subject'] = array(
    'title' => t('Subject'),
    'help' => t('The subject line of the mail.'),
    'field' => array(
      'handler' => 'mail_logger_handler_field_mail_logger_entry',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Body
  $data['mail_logger']['body'] = array(
    'title' => t('Body'),
    'help' => t('The body text of the mail.'),
    'field' => array(
      'handler' => 'mail_logger_handler_field_mail_logger_entry',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Date
  $data['mail_logger']['date_sent'] = array(
    'title' => t('Date sent'),
    'help' => t('The date the email was sent.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );

  // Language field
  $data['mail_logger']['language'] = array(
    'title' => t('Mail language'),
    'help' => t('The language that the email is in.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
