<?php

/**
 * @file
 * Default theme template for HTML Body of notification emails from Atrium.
 *
 * Copy this file in your default theme folder to create a custom themed mail.
 * Rename it to oa-messages-body--[message_type].tpl.php to override it for a
 * specific message type.
 *
 * Available variables:
 * - $recipient: The recipient of the message
 * - $subject: The message subject
 * - $body: The message body
 * - $css: Internal style sheets
 * - $module: The sending module
 * - $key: The message identifier (type)
 * - $message: The full message object
 * - $timestamp: timestamp of message
 *
 * @see template_preprocess_mimemail_message()
 */

/*
  NOTE: We use some inline styles here because GMail strips css in the
  <style> tag of the email.  So really important css needs to be inline.
*/
?>

<?php if (!empty($message['separator'])): ?>
  <?php print $message['separator']; ?>
<?php endif; ?>
<div class="mail-table">
  <?php if (!empty($message['username'])): ?>
    <div class="user-badge" style="float:right;padding: 5px 10px;">
      <a href="<?php print url('user/' . $user->uid); ?>">
        <?php print $message['username']; ?>&nbsp;
        <?php if (!empty($message['picture'])): ?>
          <?php print $message['picture']; ?>
        <?php endif; ?>
      </a>
    </div>
  <?php endif; ?>
  <div class="heading" style="padding:10px;border-bottom:1px solid #EEE;">
    <?php if (!empty($timestamp)): ?>
    <div class="timestamp"><?php print $timestamp; ?></div>
    <?php endif; ?>
    <?php if (!empty($message['title'])): ?>
      <h3 style="margin:0;"><?php print $message['title']; ?></h3>
    <?php endif; ?>
  </div>
  <div class="body" style="padding:10px;"><?php print $body; ?></div>
  <?php if (!empty($message['footer'])): ?>
    <div class="footer" style="padding:10px;
  border-top:1px solid #EEE;"><?php print $message['footer']; ?></div>
  <?php endif; ?>
</div>
