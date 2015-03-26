<?php

/**
 * @file
 * Flag as inappropriate page callbacks for Mollom module.
 */

/**
 * Helper function to retrieve public reasons to flag content as inappropriate.
 * PHP does not allow defining these as a constant but at least
 * they can be defined once for code maintenance purposes.
 */
function _mollom_flag_reasons() {
  return array(
    'spam' => t('Spam, unsolicited advertising'),
    'profanity' => t('Obscene, abusive, profane language'),
    'unwanted' => t('Off-topic'),
  );
}

/**
 * Helper function to retrieve the flag counts for a particular entity.
 *
 * @param $entity
 *   The type of entity to retrieve counts for.
 * @param id
 *   The id of the entity to retrieve counts for.
 *
 */
function _mollom_flag_entity_count($entity, $id) {
  // Get the data for this entity.
  $data = mollom_data_load($entity, $id);

  // default values
  $totals = array(
    'spam' => 0,
    'profanity' => 0,
    'unwanted' => 0,
    'quality' => 0,
    'total' => 0,
  );

  // Update the totals for all reasons.
  if (!empty($data)) {
    $totals['spam'] = $data->flags_spam;
    $totals['profanity'] = $data->flags_profanity;
    $totals['unwanted'] = $data->flags_unwanted;
    $totals['quality'] = $data->flags_quality;
    $totals['total'] = $data->flags_spam + $data->flags_profanity + $data->flags_unwanted + $data->flags_quality;
    arsort($totals);
  }
  return $totals;
}

/**
 * Adds Mollom's flag as inappropriate links to entities.
 * Called from hook_entity_view().
 */
function mollom_flag_entity_view($entity, $type, $view_mode, $langcode) {
  if (!_mollom_flag_access($type, $entity)) {
    return;
  }

  // Define the internal source for feedback.
  $source = 'mollom_flag_entity_view_' . $type . '_' . $view_mode;

  list($id, $vid, $bundle) = entity_extract_ids($type, $entity);

  $dialog = mollom_flag_dialog_check();
  if (isset($dialog['link prepare callback'])) {
    $function = $dialog['link prepare callback'];
    $link_attributes = $function();
  }
  else {
    // Add Mollom reporting link to the existing comment link structure.
    $entity->content['#pre_render'][] = 'mollom_flag_entity_view_prerender';
    $link_attributes = array('class' => array('use-ajax', 'mollom-flag'));
    $attached = array(
      'library' => array(
        array('mollom', 'flag'),
      ),
    );
  }

  $link_attributes += array(
    'id' => "mollom_$type$id",
  );

  $links = array(
    'mollom-flag' => array(
      'title' => t('report'),
      'href' => "mollom/flag/nojs/$type/$id/$source",
      'html' => TRUE,
      'attributes' => $link_attributes,
    ),
  );
  $entity->content['links']['mollom'] = array(
    '#theme' => 'links__comment__mollom',
    '#links' => $links,
    '#attributes' => array('class' => array('links', 'inline')),
  );

  if (isset($attached)) {
    $entity->content['links']['#attached'] = $attached;
  }
}

/**
 * Pre-render callback for entities that can be flagged as inappropriate.
 */
function mollom_flag_entity_view_prerender($element) {
  if (!isset($element['#prefix'])) {
    $element['#prefix'] = '';
  }
  if (!isset($element['#suffix'])) {
    $element['#suffix'] = '';
  }
  // Add a wrapping element that can be targeted by the Ajax framework.
  $element['#prefix'] .= '<div class="mollom-flag-content mollom-flag-content-' . $element['#entity_type'] . '">';
  $element['#suffix'] .= '</div>';

  return $element;
}

/**
 * Callback handler for public users to report content as inappropriate.
 * This is step one of the two-step process.  The user can now indicate the
 * reason for the report as one of spam, quality, profanity, or unwelcome.
 *
 * @param $type
 *   The request type submitted, one of "ajax" or "nojs".
 * @param $entity
 *   The type of entity that is being reported.
 * @param $id
 *   The entity identifier that is being reported.
 * @param $source
 *   The optional internal source to be submitted along with feedback.
 */
function _mollom_flag($type, $entity, $id, $source = NULL) {
  $detail = FALSE;
  if ($type === 'nojs' || $_SERVER['REQUEST_METHOD'] !== 'POST') {
    $detail = TRUE;
  }
  $form = drupal_get_form('mollom_flag_reason_form', $entity, $id, $detail, $source);

  // If not submitted via Ajax post, then return a plain Drupal form page.
  if ($detail) {
    return $form;
  }

  $dialog = mollom_flag_dialog_check();
  if (isset($dialog['display form callback'])) {
    $function = $dialog['display form callback'];
    return $function($form, t('Report'));
  }

  // Deliver via custom Mollom dialog.
  $commands = array();
  $formHtml = '<div class="mollom-flag-container" role="dialog" aria-label="' . t('Report') . '">' . render($form) . '</div>';
  $commands[] = ajax_command_prepend(".mollom-flag-content-$entity:has(#mollom_$entity$id)",$formHtml);
  $page = array('#type' => 'ajax', '#commands' => $commands);
  ajax_deliver($page);
}

/**
 * Form builder for flag as inappropriate reporting.
 * This is used in both JavaScript enabled and disabled environments.
 *
 * @param $entity
 *   The type of entity that is being reported.
 * @param $id
 *   The entity id that is being reported.
 * @param $detail
 *   True if the form should return details of the entity to report.
 *   False to leave entity details out of the form display.
 * @param $source
 *   The internal source to be submitted along with feedback.
 */
function mollom_flag_reason_form($form, &$form_state, $entity, $id, $detail, $source = NULL) {
  $form['#prefix'] = "<div id=\"mollom-flag-$entity-$id\" class=\"mollom-flag-reasons\">";
  $form['#suffix'] = '</div>';

  // If the user is able to moderate content, then inform them that this will not
  // delete the content as they might expect from standard moderation.
  if (mollom_report_access($entity, $id)) {
    $form['moderation_notice'] = array(
      '#markup' => '<p>' . t('Admin mode enabled: feedback will be sent to Mollom.') . '<br />' . t('You will still need to remove content through standard means.') . '</p>',
    );
    $form['feedback_type'] = array(
      '#type' => 'value',
      '#value' => 'moderate',
    );
  }
  else {
    $form['feedback_type'] = array(
      '#type' => 'value',
      '#value' => 'flag',
    );
  }

  // Add content summary if details should be shown.
  $form['detail'] = array(
    '#type' => 'hidden',
    '#value' => $detail,
  );
  if ($detail !== FALSE) {
    $entity_objects = entity_load($entity,array($id));
    $entity_subject = isset($entity_objects[$id]->subject) ? $entity_objects[$id]->subject : $entity_objects[$id]->title;

    $form['detailset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Reporting'),
      '#tree' => TRUE,
    );
    $form['detailset']['detail'] = array(
      '#markup' => '<div class="mollom-report-content">' . filter_xss($entity_subject) . '</div>',
    );
  }

  $form['reason'] = array(
    '#type' => 'radios',
    '#title' => t('Why are you reporting this content?'),
    '#options' => _mollom_flag_reasons(),
    '#default_value' => 'spam',
    '#required' => TRUE,
  );

  $form['entity'] = array(
    '#type' => 'value',
    '#value' => $entity,
  );

  $form['id'] = array(
    '#type' => 'value',
    '#value' => $id,
  );

  $form['source'] = array(
    '#type' => 'value',
    '#value' => $source,
  );

  $form['actions'] = array(
    '#type' => 'actions',
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit report'),
    '#ajax' => array(
      'callback' => 'mollom_flag_reason_form_submit_ajax',
      'wrapper' => "mollom-flag-$entity-$id",
    ),
  );

  // Override the cancel link to handle close actions.
  $form['actions']['cancel'] = array(
    '#type'   => 'submit',
    '#value'  => t('Cancel'),
    '#submit' => array('mollom_flag_reason_form_cancel'),
    '#ajax'   => array(
      'callback' => 'mollom_flag_reason_form_cancel_ajax',
      'wrapper' => "mollom-flag-$entity-$id",
    ),
  );

  return $form;
}

/**
 * Form submit handler for mollom_flag_reason_form().
 */
function mollom_flag_reason_form_submit($form, &$form_state) {
  $entity = $form_state['values']['entity'];
  $id = $form_state['values']['id'];
  $feedback_type = $form_state['values']['feedback_type'];
  $reason = $form_state['values']['reason'];
  $source = $form_state['values']['source'];
  $count_field = 'flags_' . $reason;

  $data = mollom_data_load($entity, $id);
  // We can only send data to Mollom that has been processed.
  if (!empty($data)) {
    _mollom_send_feedback($data, $reason, $feedback_type, $source);
    $data->$count_field += 1;
    mollom_data_save($data);
  }
  else {
    // Save the minimum entity data to be able to track reporting counts.
    $data = new stdClass();
    $data->entity = $entity;
    $data->id = $id;
    $data->$count_field = 1;
    mollom_data_save($data);
  }
  // If the form was shown on its own page with detail then display a standard
  // Drupal message style.  Forms shown in a dialog handle confirmation
  // separately.
  if ($form_state['values']['detail']) {
    drupal_set_message(t('Thank you for your feedback.'));
  }
}

/**
 * Form cancellation handler for mollom_flag_reason_form().
 */
function mollom_flag_reason_form_cancel($form, &$form_state) {
  $url = isset($form_state['values']['destination']) ? $form_state['values']['destination'] : '';
  $form_state['redirect'] = $url;
}

/**
 * Form ajax callback handler for mollom_flag_reason_form().
 */
function mollom_flag_reason_form_submit_ajax($form, &$form_state) {
  $dialog = mollom_flag_dialog_check();
  if (isset($dialog['submit form callback'])) {
    $function = $dialog['submit form callback'];
    return $function($form, $form_state);
  }
  // Custom Mollom dialog submission handler.
  $entity = $form_state['values']['entity'];
  $id = $form_state['values']['id'];
  // JavaScript behaviors handle closing this window so no need to provide
  // a close link/button.
  $commands = array();
  $confirmHtml = '<span class="mollom-flag-confirm">' . t('Thank you for your feedback.') . '</span>';
  $commands[] = ajax_command_replace("#mollom-flag-$entity-$id form",$confirmHtml);
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Form cancellation ajax callback handler for mollom_flag_reason_form().
 */
function mollom_flag_reason_form_cancel_ajax($form, &$form_state) {
  $dialog = mollom_flag_dialog_check();
  if (isset($dialog['close callback'])) {
    $function = $dialog['close callback'];
    return $function();
  }
  // Custom Mollom dialog cancellation handler.
  $entity = $form_state['values']['entity'];
  $id = $form_state['values']['id'];

  $commands = array();
  $commands[] = ajax_command_remove(".mollom-flag-container:has(#mollom-flag-$entity-$id)");
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Helper function to add row to node and comment admin tables for
 * flag as inappropriate counts.
 *
 * @param $type
 *   The entity type that is being shown.
 * @param $headers
 *   A reference to the headers associative array.
 * @param $rows
 *   A reference to the row associate array
 *
 * @see mollom_form_node_admin_content_alter
 * @see mollom_form_comment_admin_overview_alter
 */
function _mollom_table_add_flag_counts($type, &$headers, &$rows) {
  if (!mollom_flag_entity_type_access($type)) {
    return;
  }

  // Add the header for the flag as inappropriate column.
  $headers['flagged'] = array(
    'data' => t('Flagged'),
    'field' => 'flagged',
  );

  // Add the flag data to each row
  $flags = mollom_entity_type_load($type);
  foreach($rows as $id => $data) {
    $count = 0;
    if (isset($flags[$id])) {
      $count = $flags[$id]->flags_spam + $flags[$id]->flags_profanity + $flags[$id]->flags_quality + $flags[$id]->flags_unwanted;
    }
    if ($count > 0) {
      $rows[$id]['flagged'] = array(
        'data' => array(
          '#type' => 'link',
          '#title' => $count,
          '#href' => "$type/$id/edit",
          '#options' => array(
            'query' => array('mollom_flag_details' => 1),
            'fragment' => 'mollom-flag-details',
          ),
        ),
        'sort' => $count,
      );
    } else {
      $rows[$id]['flagged'] = $count;
    }
  }

  // Handle custom sorting requirements if sorting by the new column.
  $q = drupal_get_query_parameters();
  if (isset($q['order']) && $q['order'] == 'Flagged') {
    if (isset($q['sort']) && $q['sort'] === 'desc') {
      uasort($rows, '_mollom_compare_flag_count_desc');
    }
    else {
      uasort($rows, '_mollom_compare_flag_count');
    }
  }
}

/**
 * Helper comparison function to sort data by flag count ascending.
 * @see _mollom_table_add_flag_counts
 */
function _mollom_compare_flag_count($a, $b) {
  return $a['flagged']['sort'] - $b['flagged']['sort'];
}

/**
 * Helper comparison function to sort data by flag count descending.
 * @see _mollom_table_add_flag_counts
 */
function _mollom_compare_flag_count_desc($a, $b) {
  return $b['flagged']['sort'] - $a['flagged']['sort'];
}

/**
 * Adds flag data to comment edit form for administrators.
 * Called from hook_form_FORMID_alter().
 */
function mollom_flag_comment_form_alter(&$form, &$form_state, $form_id) {
  // Make sure we are editing a comment.
  $comment = $form_state['comment'];
  if (empty($comment) || empty($form_state['comment']->cid)) {
    return;
  }
  // Make sure the user is an admin.
  if (!user_access('administer comments')) {
    return;
  }
  // Make sure this form is protected by Mollom.
  $forms = mollom_form_cache();
  if (!isset($forms['protected'][$form_id])) {
    return;
  }
  // Find out if flag as inappropriate is enabled for this entity.
  $forms = mollom_form_list();
  $info = $forms[$form_id];
  if (!empty($info) && isset($info['entity report access callback'])) {
    $function = $info['entity report access callback'];
    if (!$function($comment)) {
      return;
    }
  }
  else {
    return;
  }

  // Get the flag counts for this comment.
  $totals = _mollom_flag_entity_count('comment', $comment->cid);

  $output = array();
  $markup = $totals['total'] . ' ' . t('total');
  if ($totals['total'] > 0) {
    $reasons = _mollom_flag_reasons();
    foreach($totals as $reason=>$total) {
      if ($total > 0 && $reason !== 'total') {
        $output[] = $total . ': ' . $reasons[$reason];
      }
    }
    $markup = theme('item_list', array(
      'items' => $output,
      'attributes' => array('class' => 'form-item'),
      )
    );
  }

  $form['author']['mollom_flags'] = array(
    '#type' => 'item',
    '#title' => t('User flags'),
    '#markup' => $markup,
  );

  // Expand the admin fieldset if requested.
  $params = drupal_get_query_parameters();
  if (!empty($params['mollom_flag_details'])) {
    $form['author']['#collapsed'] = FALSE;
  }
}

/**
 * Add flag details to a node edit form.
 *
 * @see mollom_form_node_form_alter
 */
function mollom_flag_node_form_alter(&$form, &$form_state, $form_id) {
  $node = $form_state['node'];
  // Make sure this is a node edit form.
  if (!isset($node->nid) || isset($node->is_new)) {
    return;
  }

  $params = drupal_get_query_parameters();

  // Node options for administrators
  $form['mollom_flags'] = array(
    '#type' => 'fieldset',
    '#access' => user_access('administer mollom') && mollom_flag_entity_type_access('node'),
    '#title' => t('User flags'),
    '#collapsible' => TRUE,
    '#collapsed' => empty($params['mollom_flag_details']) ? TRUE : FALSE,
    '#group' => 'additional_settings',
    '#weight' => 100,
  );
  
  $totals = _mollom_flag_entity_count('node', $node->nid);
  if ($totals['total'] == 0) {
    $form['mollom_flags']['details'] = array(
      '#markup' => t('This content has not been flagged by users as inappropriate.'),
    );
  }
  else {
    $reasons = _mollom_flag_reasons();
    $output = array();
    foreach($totals as $reason=>$flag_count) {
      if ($flag_count > 0 && $reason !== 'total') {
        $output[] = $flag_count . ': ' . $reasons[$reason];
      }
    }
    $form['mollom_flags']['details'] = array(
      '#title' => format_plural($totals['total'], 'Flagged by users 1 time.', 'Flagged by users @count times.'),
      '#items' => $output,
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#attributes' => array('id' => 'mollom-flag-details'),
    );
  }
}

/**
 * Callback to show the flag details for a particular entity.
 *
 * @param $type
 *   The page callback type, one of "nojs" or "ajax"
 * @param $entity
 *   The type of entity to show details for.
 * @param $id
 *   The id for the entity to show details for.
 */
function mollom_flag_details($type, $entity, $id) {
  $detail = FALSE;
  if ($type === 'nojs' || $_SERVER['REQUEST_METHOD'] !== 'POST') {
    $links = array();
    $links[] = l(t('Home'), NULL);
    $links[] = l(t('Administration'), 'admin');
    $links[] = l(t('Content'), 'admin/content');
    $links[] = l(ucfirst($entity), "admin/content/$entity");
    drupal_set_breadcrumb($links);
    $detail = TRUE;
  }
  // Get the flag counts for this entity.
  $totals = _mollom_flag_entity_count($entity, $id);
 
  $list_data = array();
  foreach($totals as $reason => $flag_count) {
    if ($flag_count > 0 && $reason !== 'total') {
      $display = $reasons[$reason];
      $list_data[] = "$flag_count: $display";
    }
  }
  if ($detail) {
    $entity_objects = entity_load($entity,array($id));
    $entity_subject = isset($entity_objects[$id]->subject) ? $entity_objects[$id]->subject : $entity_objects[$id]->title;

    $output = '<fieldset>';
    $output .= '<legend>' . t('Flagged: ') . $entity . '</legend>';
    $output .= '<div class="fieldset-wrapper">' . filter_xss($entity_subject) . '</div>';
    $output .= '</fieldset>';
    $output .= theme('item_list', array(
      'type' => 'ul',
      'items' => $list_data,
    ));
    $output .= '</div>';
    return $output;
  }
  else {
    $output = t('Flag details:') . '\n';
    foreach($list_data as $item) {
      $output .= " - $item\n";
    }
    $commands = array();
    $commands[] = ajax_command_alert($output);
    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
}

/**
 * Defines the integrated dialog modules.
 *
 * A dialog implementation may provide one or more of the callbacks in order to
 * affect the dialog output.  The hooks needed will vary by dialog
 * implementation.  If a callback is not found for a particular step in the
 * process, the default Mollom functionality will be used.
 *
 * The following information can be set:
 * - title: (required) the title of the dialog solution that is displayed
 *   to site administrator within the advanced configuration settings area.
 * - link prepare callback: callback function to prepare links to use the dialog
 *   solution from hook_entity_view.  This callback returns an array of
 *   classes for any links that should be opened in the dialog solution.
 * - display form callback: callback function to open a form in a new dialog.
 *   This callback receives the form to display and the title for the dialog.
 * - close callback: callback to close the dialog window
 *
 * The site administrator can select to use one of the following in the
 * Mollom advanced settings if the module is installed and enabled for their
 * site.
 *
 * @todo: Move this into a hook implementation to allow others to extend.
 */
function mollom_flag_dialog_info() {
  $modules = array(
    'ctools' => array(
      'title' => 'CTools (used by CTools Automodal and Modal Forms)',
      'link prepare callback' => 'mollom_ctools_link_prepare',
      'display form callback' => 'mollom_ctools_display_form',
      'close callback' => 'mollom_ctools_close',
    )
  );
  return $modules;
}

/**
 * Checks to see what dialog option to use based on the user's configuration.
 *
 * @return mixed
 *   Returns an array of dialog information for the selected dialog or FALSE
 *   if the Mollom custom dialog should be used.
 *
 * @see mollom_flag_dialog_info()
 */
function mollom_flag_dialog_check() {
  // Return dialog information for dialog selected in settings if it is
  // still enabled.
  $modules = mollom_flag_dialog_info();
  $configured_dialog = variable_get('mollom_fai_dialog', '');
  if (isset($modules[$configured_dialog]) && module_exists($configured_dialog)) {
    return $modules[$configured_dialog];
  }
  return FALSE;
}

/**
 * Callback handler for setting up links to use ctools.
 */
function mollom_ctools_link_prepare() {
  module_load_include('module', 'ctools', 'ctools');
  ctools_include('modal');
  ctools_modal_add_js();

  return array(
    'class' => 'ctools-use-modal'
  );
}

/**
 * Callback handler for public users to report content as inappropriate using
 * ctools modal dialog.
 *
 * @param $form
 *   The form to display within the dialog.
 * @param $title
 *   The title of the dialog window.
 */
function mollom_ctools_display_form($form, $title) {
  // Utilize existing ctools constructs.
  module_load_include('module', 'ctools', 'ctools');
  ctools_include('modal');

  $output = drupal_render($form);

  $form_state = array(
    'title' => $title,
    'ajax' => TRUE,
  );
  $commands = ctools_modal_form_render($form_state, $output);
  $page = array('#type' => 'ajax', '#commands' => $commands);
  ajax_deliver($page);
}

/**
 * Ctools enabled form cancellation ajax callback handler for
 * mollom_flag_reason_form().
 */
function mollom_ctools_close() {
  module_load_include('module', 'ctools', 'ctools');
  ctools_include('modal');

  $commands[] = ctools_modal_command_dismiss();
  return array('#type' => 'ajax', '#commands' => $commands);
}

