<?php
/**
 * @file
 * User-facing UI components for the Mail Logger module.
 */

/**
 * Menu callback; displays a listing of logged mails.
 */
function mail_logger_overview() {
  drupal_add_css(drupal_get_path('module', 'mail_logger') . '/mail_logger.css');
  $form = drupal_get_form('mail_logger_form_overview');
  $output = drupal_render($form);
  $date_format = variable_get('mail_logger_log_date_format', 'short');

  // Fix the annoying lower casing by the menu module.
  drupal_set_title(t('Outgoing Mail Log'));

  $table = array(
    'header' => array(
      array('data' => t('Date Sent'), 'field' => 'date_sent', 'sort' => 'desc'),
      array('data' => t('Mailkey'), 'field' => 'mailkey'),
      array('data' => t('Language'), 'field' => 'language'),
      array('data' => t('To'), 'field' => 'mailto'),
      array('data' => t('From'), 'field' => 'mailfrom'),
      array('data' => t('Subject'), 'field' => 'subject'),
      array('data' => t('IP Addr'), 'field' => 'ipaddr'),
      ),
    'rows' => array(),
    'empty' => t('No outgoing email available.'),
    'attributes' => array('id' => 'mail-logger-log'),
    );

  $query = db_select('mail_logger', 'ml')
    ->extend('PagerDefault')->limit(variable_get('mail_logger_log_lines_per_page', 50))
    ->extend('TableSort')->orderByHeader($table['header'])
    ->fields('ml', array(
      'mlid',
      'mailkey',
      'language',
      'mailto',
      'mailfrom',
      'subject',
      'date_sent',
      'ipaddr',
    ));

  $type = $_SESSION['mail_logger_overview_filter'];

  if ($type != 'all') {
    $query->condition('mailkey', $type);
  }

  if (!empty($_SESSION['mail_logger_overview_from_date'])) {
    $from_time = strtotime($_SESSION['mail_logger_overview_from_date']['year'].'-'.$_SESSION['mail_logger_overview_from_date']['month'].'-'.$_SESSION['mail_logger_overview_from_date']['day']);
  }
  else{
    $from_time = strtotime('-1 month');
  }

  if (!empty($_SESSION['mail_logger_overview_to_date'])) {
    $to_time = strtotime($_SESSION['mail_logger_overview_to_date']['year'].'-'.$_SESSION['mail_logger_overview_to_date']['month'].'-'.$_SESSION['mail_logger_overview_to_date']['day'] . 't23:59:59');
  }
  else{
    $to_time = strtotime('now') + 86400;
  }
  $query->condition('date_sent', $from_time, '>=');
  $query->condition('date_sent', $to_time, '<=');

  if (!empty($_SESSION['mail_logger_overview_search_field']) && !empty($_SESSION['mail_logger_overview_search_value'])) {
    $search_field = $_SESSION['mail_logger_overview_search_field'];
    $search_value = $_SESSION['mail_logger_overview_search_value'];
    $query->condition($search_field, '%'.$search_value.'%', 'LIKE');
  }

  $result = $query->execute();

  foreach ($result as $mail_logger) {
    // Alter encrypted mail log records back to their original state.
    $context = array('operation' => 'read');
    drupal_alter('mail_logger_record', $mail_logger, $context);

    $subject = (empty($mail_logger->subject) ? t('Missing subject') : $mail_logger->subject);
    $mailto = $mail_logger->mailto;
    if (strpos($mailto, ';') !== FALSE) {
      $list = explode(';', $mailto);
    }
    else {
      $list = explode(',', $mailto);
    }

    $table['rows'][] = array('data' =>
      array(
        // Cells
        array('data' => format_date($mail_logger->date_sent, $date_format), 'class' => array('date-sent')),
        array('data' => $mail_logger->mailkey, 'class' => array('mail-key')),
        array('data' => $mail_logger->language, 'class' => array('mail-language')),
        array('data' => implode('<br />', $list), 'class' => array('mail-to')),
        array('data' => $mail_logger->mailfrom, 'class' => array('mail-from')),
        array('data' => l(truncate_utf8($subject, 56, TRUE, TRUE), 'admin/reports/mail-logger/mail/' . $mail_logger->mlid), 'class' => array('mail-subject')),
        array('data' => $mail_logger->ipaddr, 'class' => array('mail-ipaddr')),
        ),
      );
  }

  $output .= theme('table', $table);
  $output .= theme('pager', array());

  return $output;
}

/**
 * Page callback at admin/reports/mail-logger/mail/xyz to show a single email.
 *
 * The menu wildcard loader %mail_logger invokes mail_logger_load, and the
 * resulting $mail object is passed as a parameter.
 *
 * @param Object $mail
 * A mail object returned from mail_logger_load().
 *
 * @return String
 * Themed HTML to display a single mail.
 */
function mail_logger_read_mail($id) {
  if (!isset($id) || !is_numeric($id)) {
    return 'Invalid Mail Logger ID parameter';
  }
  elseif ($mail = mail_logger_load($id)) {
    drupal_add_css(drupal_get_path('module', 'mail_logger') . '/mail_logger.css');
    return theme('mail_logger_read_mail', array('mail' => $mail));
  }
  else {
    return t('No Mail Logger record found with id: %id', array('%id' => $id));
  }
}

/**
 * Form to filter the list of logged emails.
 */
function mail_logger_form_overview() {
  $names['all'] = t('all mail types');
  foreach (_mail_logger_get_mailkey_types() as $type) {
    $names[$type] = t('!type', array('!type' => t($type)));
  }

  if (empty($_SESSION['mail_logger_overview_filter'])) {
    $_SESSION['mail_logger_overview_filter'] = 'all';
  }

  $first_mail = db_select('mail_logger', 'ml')
    ->fields('ml', array(
      'date_sent'
    ))
    ->orderBy('date_sent', 'ASC')
    ->range(0, 1)
    ->execute()
    ->fetchField();

  $timezone = new DateTimeZone(date_default_timezone_get());
  $default_from_date = $first_mail ? DateTime::createFromFormat('U', $first_mail) : DateTime::createFromFormat('U', strtotime('-1 month'));
  $default_from_date->setTimezone($timezone);
  $default_from_date = array('year' => $default_from_date->format('Y'), 'month' => $default_from_date->format('n'), 'day' => $default_from_date->format('j'));

  $is_filtering = $_SESSION['mail_logger_overview_filter'] != 'all' || !empty($_SESSION['mail_logger_overview_from_date']) || !empty($_SESSION['mail_logger_overview_to_date']) || !empty($_SESSION['mail_logger_overview_search_field']) || !empty($_SESSION['mail_logger_overview_search_value']);

  $form['filter_logs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filter Mail Log'),
    '#collapsible' => TRUE,
    '#collapsed' => !$is_filtering,
  );
  $form['filter_logs']['from_date'] = array(
    '#type' => 'date',
    '#title' => t('From Date'),
    '#default_value' => (!empty($_SESSION['mail_logger_overview_from_date'])) ? $_SESSION['mail_logger_overview_from_date'] : $default_from_date,
  );

  $default_to_date = DateTime::createFromFormat('U', time() + 86400);
  $default_to_date->setTimezone($timezone);
  $default_to_date = array('year' => $default_to_date->format('Y'), 'month' => $default_to_date->format('n'), 'day' => $default_to_date->format('j'));

  $form['filter_logs']['to_date'] = array(
    '#type' => 'date',
    '#title' => t('To Date'),
    '#default_value' => (!empty($_SESSION['mail_logger_overview_to_date'])) ? $_SESSION['mail_logger_overview_to_date'] : $default_to_date,
  );

  $form['filter_logs']['search_field'] = array(
    '#type' => 'select',
    '#options' => array(
      '' => '-- Select a field --',
      'mailto' => 'To Email Address',
      'mailfrom' => 'From Email Address',
      'subject' => 'Subject',
      'body' => 'Body',
      'language' => 'Language',
      ),
    '#title' => t('Field'),
    '#default_value' => (!empty($_SESSION['mail_logger_overview_search_field'])) ?
      $_SESSION['mail_logger_overview_search_field'] : ''
  );
  $form['filter_logs']['search_value'] = array(
    '#type' => 'textfield',
    '#title' => t('Contains'),
    '#default_value' => (!empty($_SESSION['mail_logger_overview_search_value'])) ? $_SESSION['mail_logger_overview_search_value'] : ''
  );

  $form['filter_logs']['filter'] = array(
    '#type' => 'select',
    '#title' => t('Filter by Mailkey'),
    '#options' => $names,
    '#default_value' => $_SESSION['mail_logger_overview_filter']
  );
  $form['filter_logs']['submit'] = array('#type' => 'submit', '#value' => t('Filter'), '#attributes' => array('filter'));
  $form['filter_logs']['reset'] = array('#type' => 'submit', '#value' => t('Reset'), '#attributes' => array('reset'));
  $form['#redirect'] = FALSE;

  $form['mail_logger_clear'] = array(
    '#type' => 'fieldset',
    '#title' => t('Clear mail log'),
    '#description' => t('This will permanently remove the log messages from the database.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mail_logger_clear']['clear'] = array(
    '#type' => 'submit',
    '#value' => t('Clear mail messages'),
    '#submit' => array('_mail_logger_overview_clear_logs_submit'),
  );

  return $form;
}

function mail_logger_form_overview_validate($form, &$form_state) {
  if (in_array('reset', $form_state['triggering_element']['#attributes'])) {
    return;
  }

  $from_date = strtotime($form_state['values']['from_date']['year']
    . '-' . str_pad($form_state['values']['from_date']['month'], 2, '0', STR_PAD_LEFT)
    . '-' . str_pad($form_state['values']['from_date']['day'], 2, '0', STR_PAD_LEFT));
  $to_date = strtotime($form_state['values']['to_date']['year']
    . '-' . str_pad($form_state['values']['to_date']['month'], 2, '0', STR_PAD_LEFT)
    . '-' . str_pad($form_state['values']['to_date']['day'], 2, '0', STR_PAD_LEFT));
  if ($to_date < $from_date) {
    form_set_error('to_date', 'The To Date must be after the From Date.');
  }
  if (!empty($form_state['values']['search_value']) && empty($form_state['values']['search_field'])) {
    form_set_error('search_field', 'Please choose a search field.');
  }
  elseif (empty($form_state['values']['search_value']) && !empty($form_state['values']['search_field'])) {
    form_set_error('search_value', 'Please enter a search text.');
  }
}

/**
 * hook_submit for mail_logger_form_overview
 */
function mail_logger_form_overview_submit($form, &$form_state) {
  if (in_array('filter', $form_state['triggering_element']['#attributes'])) {
    $_SESSION['mail_logger_overview_filter'] = $form_state['values']['filter'];
    $_SESSION['mail_logger_overview_from_date'] = $form_state['values']['from_date'];
    $_SESSION['mail_logger_overview_to_date'] = $form_state['values']['to_date'];
    $_SESSION['mail_logger_overview_search_field'] = $form_state['values']['search_field'];
    $_SESSION['mail_logger_overview_search_value'] = $form_state['values']['search_value'];
  }
  elseif (in_array('reset', $form_state['triggering_element']['#attributes'])) {
    $_SESSION['mail_logger_overview_filter'] = 'all';
    $_SESSION['mail_logger_overview_from_date'] = '';
    $_SESSION['mail_logger_overview_to_date'] = '';
    $_SESSION['mail_logger_overview_search_field'] = '';
    $_SESSION['mail_logger_overview_search_value'] = '';
  }
}

/**
 * Callback: Deletes mail logs.
 */
function _mail_logger_overview_clear_logs_submit($form, &$form_state) {
  db_truncate('mail_logger')->execute();
  drupal_set_message(t('Mail logs cleared.'));
}
