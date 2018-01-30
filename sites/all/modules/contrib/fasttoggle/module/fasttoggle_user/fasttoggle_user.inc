<?php

function fasttoggle_potential_toggleable_roles() {
  static $roles;

  if (!isset($roles)) {
    $roles = user_roles(TRUE);
    unset($roles[DRUPAL_AUTHENTICATED_RID]);
  }

  return $roles;
}

function fasttoggle_sitewide_toggleable_roles() {
  static $roles;

  if (!isset($roles)) {
    $potential_roles = fasttoggle_potential_toggleable_roles();

    $defaults = array();
    foreach ($potential_roles as $rid => $role_name) {
      $defaults["role_{$rid}"] = "role_{$rid}";
    }

    $values = variable_get('fasttoggle_user_role_settings', $defaults);
    $allowed_roles = array_filter(variable_get('fasttoggle_user_role_settings', $defaults));

    // Trim the group ("role_") off the front of each key
    $new_array = array();
    foreach ($allowed_roles as $role) {
      $new_array[substr(array_pop($allowed_roles), 5)] = $role;
    }
    $roles = $new_array ? array_intersect_key(fasttoggle_potential_toggleable_roles(), $new_array) : array();
  }

  return $roles;
}

function fasttoggle_user_toggleable_roles($account = NULL) {
  global $user;
  static $roles;

  if (!$account) {
    $account = $user;
  }

  if (!isset($roles[$account->uid])) {
    $roles[$account->uid] = array();

    foreach(fasttoggle_sitewide_toggleable_roles() as $rid => $name) {
      if (user_access(fasttoggle_role_permission($name), $account)) {
        $roles[$account->uid][$rid] = $name;
      }
    }
  }

  return $roles[$account->uid];
}
