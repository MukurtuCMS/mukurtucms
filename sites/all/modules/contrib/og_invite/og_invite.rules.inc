<?php
/**
 * @file
 * OG Invite Rules integration.
 */

/**
 * Implements hook_rules_event_info().
 */
function og_invite_rules_event_info() {
  return array(
    'og_invite_send_invitation' => array(
      'label' => t('After an invitation have been created, send the message to the invitee.'),
      'module' => 'og_invite',
      'variables' => array(
        'inviter' => array(
          'type' => 'user',
          'label' => t('Inviter'),
        ),
        'invitee' => array(
          'type' => 'user',
          'label' => t('Invitee'),
        ),
        'og_membership' => array(
          'type' => 'og_membership',
          'label' => t('OG membership'),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t('Text of the invitation message.'),
        ),
        'hash' => array(
          'type' => 'text',
          'label' => t('Hash'),
          'description' => t('Hash of the invitation link.'),
        ),
        'invite_link' => array(
          'type' => 'uri',
          'label' => t('Invitation link'),
          'description' => t('Invitation link'),
        ),
      ),
      'group' => t('OG invite'),
    ),
  );
}
