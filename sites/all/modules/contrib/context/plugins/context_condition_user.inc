<?php

/**
 * Expose current user role as a context condition.
 */
class context_condition_user extends context_condition {
  function condition_values() {
    $values = array();
    foreach (user_roles() as $rid => $role_name) {
      if ($rid == DRUPAL_ANONYMOUS_RID) {
        $values['anonymous user'] = check_plain($role_name);
      }
      elseif ($rid == DRUPAL_AUTHENTICATED_RID) {
        $values['authenticated user'] = check_plain($role_name);
      }
      else {
        $values[$role_name] = check_plain($role_name);
      }
    }
    return $values;
  }

  function options_form($context) {
    $defaults = $this->fetch_from_context($context, 'options');
    return array(
      'negate_role' => array(
        '#title' => t('Make role a negative condition'),
        '#type' => 'checkbox',
        '#description' => t("Checking this box will make this condition fire if the user's role is NOT one of the role's checked"),
        '#default_value' => isset($defaults['negate_role']) ? $defaults['negate_role'] : 0,
      ),
    );
  }

  function execute($account) {
    $all_roles = user_roles();
    $users_roles = $account->roles;
    foreach ($all_roles as $rid => $role) {
      foreach ($this->get_contexts($role) as $context) {
        $options = $this->fetch_from_context($context, 'options');
        if (empty($options['negate_role'])) {
          if (in_array($role, $users_roles)){
            $this->condition_met($context, $role);
          }
        }
        else {
          $negate_flag = TRUE;
          foreach ($this->fetch_from_context($context, 'values') as $nid => $negated_role) {
            if (!in_array($negated_role, $users_roles)) {
              $negate_flag &= TRUE;
            }
            else {
              $negate_flag &= FALSE;
            }
          }
          if ($negate_flag) {
            $this->condition_met($context, $role);
          }
        }
      }
    }
  }

}
