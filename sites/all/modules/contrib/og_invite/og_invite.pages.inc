<?php
/**
 * @file
 * Organic groups invite pages callbacks.
 */

// -----------------------------------------------------------------------------
// Invitation form

/**
 * Invitation form callback.
 */
function _og_invite_form($form, &$form_state, $group_type, $gid, $invitee = NULL) {
  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));

  $group = entity_load_single($group_type, $gid);
  $label = entity_label($group_type, $group);

  drupal_set_title(t('Invite People to Join @g', array('@g' => $group->title)));

  $form['group_type'] = array('#type' => 'value', '#value' => $group_type);
  $form['gid'] = array('#type' => 'value', '#value' => $gid);

  // Preset invitee field if an invitee has been provided by URL.
  $invitee_value = NULL;
  if (NULL !== $invitee) {
    $ogm = og_get_membership($group_type, $gid, 'user', $invitee->uid);
    if (!empty($ogm)) {
      if ($ogm->state == OG_STATE_ACTIVE) {
        $errmsg = t('This user is already a member of the group.');
      }
      elseif (!empty($ogm->{OG_INVITE_MEMBERSHIP_FIELD}[LANGUAGE_NONE][0]['value'])) {
        $errmsg = t('This user has already been invited to the group.');
      }
      drupal_set_message($errmsg, 'error');
      drupal_goto('group/' . $group_type . '/' . $gid . '/admin/people/invite-users');
    }

    $invitee_value = $invitee->name;
    if (module_exists('realname')) {
      $invitee_value = $invitee->realname;
    }
    $invitee_value .= ' [' . $invitee->uid . ']';
  }

  $form['invitee'] = array(
    '#type'               => 'textfield',
    '#title'              => t('Invitees'),
    '#description'        => NULL,
    '#default_value'      => $invitee_value,
    '#required'           => TRUE,
    '#disabled'           => !empty($invitee_value),
    '#autocomplete_path'  => 'group/' . $group_type . '/' . $gid . '/admin/people/invite-users/autocomplete',
  );

  $form['message'] = array(
    '#type'               => 'textarea',
    '#title'              => t('Message'),
    '#description'        => t('Give these potential members a good reason to join your group.'),
    '#default_value'      => '',
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Invite'));

  return $form;
}

/**
 * Invitation form validation callback.
 */
function _og_invite_form_validate($form, &$form_state) {
  global $user;

  $group_type = $form_state['values']['group_type'];
  $gid = $form_state['values']['gid'];
  $invitees = explode(',', str_replace(', ', ',', $form_state['values']['invitee']));

  $unrelated = array();
  $unexisting = array();
  $good = array();
  foreach ($invitees as $invitee) {
    if (empty($invitee)) {
      continue;
    }
    list($name, $uid) = explode('||', preg_replace('#^(.*)\s\[([0-9]+)\]$#', '$1||$2', $invitee));

    // Check if the user exists.
    $exists = db_select('users', 'u')
      ->fields('u', array('uid'))
      ->condition('uid', $uid)
      ->execute()
      ->fetchField();
    if (empty($exists)) {
      $unexisting[] = check_plain($name);
    }
    // If the user exist and if needed check if it is related to the current user.
    elseif (module_exists('user_relationships') && !og_user_access($group_type, $gid, 'invite any user')) {
      $related = db_select('user_relationships', 'ur')
        ->fields('ur', array('rid'))
        ->condition('ur.approved', 1)
        ->condition('ur.requester_id', $user->uid)
        ->condition('ur.requestee_id', $uid)
        ->execute()
        ->fetchField();
      if (empty($related)) {
        $unrelated[] = check_plain($name);
      }
      else {
        $good[] = $invitee;
      }
    }
    // If the user exists and no relation check is needed.
    else {
      $good[] = $invitee;
    }
  }

  // Only keep existing and related users
  $form_state['values']['invitee'] = implode(',', $good);

  // Display error messages for unexisting and unrelated users.
  if (!empty($unexisting)) {
    drupal_set_message(t('The following users do not exist:')
      . ' ' . implode(', ', $unexisting)
      . '<br />' . t('They have been removed from your invitation list.'), 'warning');
  }
  if (!empty($unrelated)) {
    drupal_set_message(t('You cannot invite the following users because they are not in relation with you:')
      . ' ' . implode(', ', $unrelated)
      . '<br />' . t('They have been removed from your invitation list.'), 'warning');
  }
}

/**
 * Invitation form submit callback.
 */
function _og_invite_form_submit($form, &$form_state) {
  $group_type = $form_state['values']['group_type'];
  $gid = $form_state['values']['gid'];
  $message = check_plain($form_state['values']['message']);
  $invitees = explode(',', str_replace(', ', ',', $form_state['values']['invitee']));

  $entity = entity_load_single($group_type, $gid);
  list(,, $group_bundle) = entity_extract_ids($group_type, $entity);
  $label = entity_label($group_type, $entity);

  foreach ($invitees as $invitee) {
    if (empty($invitee)) {
      continue;
    }
    $result = NULL;
    list($name, $uid) = explode('||', preg_replace('#^(.*)\s\[([0-9]+)\]$#', '$1||$2', $invitee));
    if ($account = user_load($uid)) {
      $field_name = og_get_best_group_audience_field('user', $account, $group_type, $group_bundle, TRUE);
      if ($field_name) {
        $result = og_invite_invite($group_type, $gid, $field_name, $uid, $message);
      }
    }

    if (!empty($result)) {
      drupal_set_message(t('<em>@user</em> has been invited to the group <em>@label</em>.', array('@user' => $name, '@label' => $label)));
      $form_state['redirect'] = 'group/' . $group_type . '/' . $gid . '/admin/people/invite-users';
    }
    else {
      drupal_set_message(t('An error happened while inviting <em>@user</em> to the group <em>@label</em>', array('@user' => $name, '@label' => $label)), 'error');
    }
  }
}

/**
 * Invitation autocomplete callback.
 */
function _og_invite_autocomplete($group_type, $gid, $string) {
  $field_name = 'name';

  $names = array();
  // 1: Parse $string and build list of valid user names.
  $fragments = explode(',', $string);
  foreach ($fragments as $name) {
    if ($name = trim($name)) {
      $names[$name] = $name;
    }
  }

  // 2: Find the next user name suggestion.
  $fragment = array_pop($names);
  $matches = array();
  if ($string) {
    $search_conditions = db_or();
    $restrict_conditions = db_and();

    $query = db_select('users', 'u')
      ->fields('u', array('uid'));
    $search_conditions->condition('u.name', '%' . db_like($fragment) . '%', 'LIKE');
    $restrict_conditions->condition('u.status', 1);

    // Real Name integration.
    if (module_exists('realname')) {
      $query->innerJoin('realname', 'rn', 'u.uid = rn.uid');
      $search_conditions->condition('rn.realname', '%' . db_like($fragment) . '%', 'LIKE');
      $field_name = 'realname';
    }

    // User Relationships integration.
    if (module_exists('user_relationships') && !og_user_access($group_type, $gid, 'invite any user')) {
      global $user;

      $query->innerJoin('user_relationships', 'ur', 'u.uid = %alias.requestee_id');
      $restrict_conditions->condition('ur.approved', 1);
      $restrict_conditions->condition('ur.requester_id', $user->uid);
    }

    // Restrict to users not already in the group.
    $join = "%alias.etid = u.uid AND %alias.entity_type = 'user' AND %alias.group_type = :gtype AND %alias.gid = :gid";
    $query->leftJoin('og_membership', 'ogm', $join, array(':gtype' => $group_type, ':gid' => $gid));
    $restrict_conditions->condition('ogm.state', NULL);

    $query->condition($search_conditions)
      ->condition($restrict_conditions)
      ->range(0, 10);

    $uids = $query->execute()->fetchCol();
    $matching_users = user_load_multiple($uids);
    foreach ($matching_users as $matching_user) {
      $matches[$matching_user->uid] = $matching_user;
    }
  }

  // 3: Format the suggestions and filter them to avoid to add someone twice.
  $themed_matches = array();
  foreach ($matches as $key => $match) {
    $uname = check_plain($match->{$field_name});
    if (!in_array($uname, $names)) {
      $themed_matches[$key] = $uname;
    }
  }

  // 4: Prefix the matches and convert them to the correct form for the
  // autocomplete.
  $prefix = count($names) ? implode(", ", $names) . ", " : '';
  $suggestions = array();
  foreach ($themed_matches as $uid => $match) {
    $suggestions[$prefix . $match . ' [' . $uid . '], '] = $match;
  }
  if (empty($suggestions)) {
    $suggestions[$prefix . $fragment] = '<em>' . t('Sorry no matches were found for "@fragment".', array('@fragment' => $fragment)) . '</em>';
  }

  // convert to object to prevent drupal bug, see http://drupal.org/node/175361
  drupal_json_output((object)$suggestions);
}

// -----------------------------------------------------------------------------
// Invitation answer

/**
 * Answer to an invitation title callback.
 */
function _og_invite_answer_title($group_type, $gid, $hash, $op = 'answer') {
  $entity = entity_load_single($group_type, $gid);
  $label = entity_label($group_type, $entity);

  $str = '';
  switch ($op) {
    case 'approve':
      $str = 'Approve your invitation in the group <em>@label</em>';
      break;
    case 'decline':
      $str = 'Decline your invitation in the group <em>@label</em>';
      break;
    case 'always-decline':
      $str = 'Decline your invitation in the group <em>@label</em> and refuse future invitations';
      break;
    case 'answer':
      $str = 'Answer to your invitation in the group <em>@label</em>';
      break;
  }
  $title = t($str, array('@label' => $label));
  drupal_set_title($title, PASS_THROUGH);
  return $title;
}

/**
 * Answer to an invitation callback.
 */
function _og_invite_answer($group_type, $gid, $hash, $op = 'answer') {
  switch ($op) {
    case 'approve':
    case 'decline':
    case 'always-decline':
      _og_invite_answer_handle($group_type, $gid, $hash, $op);
      $entity = entity_load_single($group_type, $gid);
      $url = entity_uri($group_type, $entity);
      drupal_goto($url['path']);
      break;
    case 'answer':
    default:
      return drupal_get_form('_og_invite_answer_form', $group_type, $gid, $hash);
      break;
  }
}

/**
 * Invitation answer form.
 */
function _og_invite_answer_form($form, &$form_state, $group_type, $gid, $hash) {
  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));

  $ogm = og_invite_get_membership_from_hash($hash);
  if (empty($ogm)) {
    drupal_set_message(t('Your hash is incorrect. You may have already answered this invitation.'), 'error');

    $entity = entity_load_single($group_type, $gid);
    $url = entity_uri($group_type, $entity);
    drupal_goto($url['path']);
  }

  $form['group_type'] = array('#type' => 'value', '#value' => $group_type);
  $form['gid'] = array('#type' => 'value', '#value' => $gid);
  $form['hash'] = array('#type' => 'value', '#value' => $hash);

  $form['answer'] = array(
    '#type'               => 'radios',
    '#title'              => t('Answer'),
    '#options'            => array(
      'approve'        => t('Accept the invitation and become a member of the group'),
      'decline'        => t('Decline the invitation'),
      'always-decline' => t('Decline the invitation and block future invitations from this group'),
    ),
    '#default_value'      => 'approve',
    '#required'           => TRUE,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Send the answer'));

  return $form;
}

/**
 * Invitation answer form validation.
 */
function _og_invite_answer_form_validate($form, &$form_state) {
  $ogm = og_invite_get_membership_from_hash($form_state['values']['hash']);
  if (empty($ogm)) {
    drupal_set_message(t('Your hash is incorrect. You may have already answered this invitation.'), 'error');

    $entity = entity_load_single($form_state['values']['group_type'], $form_state['values']['gid']);
    $url = entity_uri($group_type, $entity);
    drupal_goto($url['path']);
  }
}

/**
 * Invitation answer form submit.
 */
function _og_invite_answer_form_submit($form, &$form_state) {
  $group_type =   $form_state['values']['group_type'];
  $gid = $form_state['values']['gid'];
  $hash = $form_state['values']['hash'];
  $answer = $form_state['values']['answer'];

  _og_invite_answer_handle($group_type, $gid, $hash, $answer);

  $entity = entity_load_single($group_type, $gid);
  $url = entity_uri($group_type, $entity);
  $form_state['redirect'] = $url['path'];
}

/**
 * Invitation answer handle.
 */
function _og_invite_answer_handle($group_type, $gid, $hash, $op = 'decline') {
  $ogm = og_invite_get_membership_from_hash($hash);
  if (empty($ogm)) {
    drupal_set_message(t('Your hash is incorrect. You may have already answered this invitation.'), 'error');
    return;
  }
  switch ($op) {
    case 'approve':
      $ogm->state = OG_STATE_ACTIVE;
      $ogm->{OG_INVITE_MEMBERSHIP_FIELD} = array();
      og_membership_save($ogm);
      drupal_set_message(t('Your invitation has been accepted. Welcome to the group!'), 'status');
      break;
    case 'always-decline':
      $wrapper = entity_metadata_wrapper('og_membership', $ogm);
      $wrapper->state->set(OG_STATE_BLOCKED);
      $wrapper->{OG_MEMBERSHIP_REQUEST_FIELD}->set(t('Invitation declined'));
      og_membership_save($ogm);
      drupal_set_message(t('Your invitation has been permanently declined. If you want to become a member of this group you will have to join on your own.'), 'warning');
      break;
    case 'decline':
    default:
      og_membership_delete($ogm->id);
      drupal_set_message(t('Your invitation has been declined.'), 'warning');
      break;
  }
}
