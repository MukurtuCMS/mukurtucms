<?php
/**
 * @file
 * OG Invite module installation file.
 */

/**
 * Configuration form for administrator.
 */
function og_invite_settings_form($form, &$form_state) {
  $form['og_invite_send_invitation_by_rules'] = array(
    '#type' => 'checkbox',
    '#title' => t('Check this checkbox if you want to use Rules to send the invitation.'),
    '#default_value' => variable_get('og_invite_send_invitation_by_rules', FALSE),
  );

  return system_settings_form($form);
}
