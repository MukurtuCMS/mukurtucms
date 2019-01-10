<?php
/**
 * @file
 * Code for controlling redirection of login
 * Some of this code comes from the login_destination module
 */

/**
 * Implements hook_form_FORM_ID_alter() for user_profile_form.
 */
function oa_core_form_user_profile_form_alter(&$form, &$form_state, $form_id) {
  // We redirect by using the drupal_goto_alter hook. If we simply
  // call drupal_goto() it may break compability with other modules. If we set
  // the $_GET['destination'] variable we will loose the possibility to redirect
  // to an external URL.

  // Please note the the system_goto_action() calls drupal_goto()
  // More on this issue http://drupal.org/node/732542.

  // If we add the $form_state['redirect'] here it will be overriden by the
  // user_login_submit(). So we add a submit handler instead and will set the
  // redirect later. Our submit handler will be executed after the execution
  // of user_login_submit(). This is because form_submit() functions are
  // appended to form before hook_form_alter() is executed.

  if (isset($_GET['pass-reset-token'])) {
    // Redirect only from user_pass_reset
    // You have to explicitally turn on the option to always redirect from
    // the profile page. This is for constistency.
    $form['#submit'][] = 'oa_core_login_submit';
  }
}

/**
 * Implements hook_form_FORM_ID_alter() for user_login_block.
 */
function oa_core_form_user_login_block_alter(&$form, &$form_state) {
  $form['links']['#markup'] = '<span class="password-reset">' . t('If you forgot your password') . ', ' .
        l(t('request a new password.'), 'user/password') . '</span>';
}

/**
 * Helper submit function.
 */
function oa_core_login_submit($form, &$form_state) {
  oa_core_login_perform_redirect('login');
}

/**
 * Implements hook_user_login
 */
function oa_core_user_login(&$edit, $account) {
  if (!isset($_POST['form_id']) || $_POST['form_id'] != 'user_pass_reset') {
    oa_core_login_perform_redirect('login');
  }
}

/**
 * Implements hook_user_logout
 */
function oa_core_user_logout($account) {
  oa_core_login_perform_redirect('logout');
}

/**
 * Implements hook_drupal_goto_alter
 */
function oa_core_drupal_goto_alter(&$path, &$options, &$http_response_code) {
  // Note that this functionality cannot be backported do 6.x as Drupal 6 does
  // not call drupal_alter for drupal_goto.

  // This actually may be used also by templates.
  if (isset($GLOBALS['destination'])) {
    $destination = $GLOBALS['destination'];

    // alter drupal_goto
    if (is_array($destination)) {
      $path = $destination[0];
      $options = array();
      if (count($destination) > 1) {
        $options = $destination[1];
      }
    }
    else {
      $path = $destination;
    }
  }
}

/**
 * Pass destination to drupal_goto.
 */
function oa_core_login_prepare_goto($destination) {
  // Check if $_GET['destination'] should overwrite us
  if (!isset($_GET['destination']) || !variable_get('login_destination_preserve_destination', TRUE)) {
    $GLOBALS['destination'] = $destination;
  }
}

/**
 * Evaluate rules and perform redirect.
 * This function is intended to be used by external modules.
 * @param <type> $trigger
 * @param <type> $current if null $_GET['q'] is used
 */
function oa_core_login_perform_redirect($trigger = '', $current = NULL) {
  $destination = oa_core_login_get_destination($trigger, $current);

  // Check if we redirect
  if ($destination !== FALSE) {
    oa_core_login_prepare_goto($destination);
  }
}

/**
 * Process all destination rules and return destination path.
 * This function is intended to be used by external modules.
 */
function oa_core_login_get_destination($trigger = '', $current = NULL) {
  global $user;

  $homepage = variable_get('site_frontpage', 'home');
  // Get all the login destination rules from the database.
  if ($trigger == 'login') {
    $spaces = oa_core_get_groups_by_user($user, 'node');
    // if not a member of any spaces, go to default home
    if (count($spaces) <= 0) {
      return $homepage;
    }
    return 'user/' . $user->uid . '/view';
  }
  elseif ($trigger == 'logout') {
    return $homepage;
  }

  // no rule matched
  return FALSE;
}
