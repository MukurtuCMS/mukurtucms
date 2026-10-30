<?php
/**
 * @file
 * Template for HTML emails.
 *
 * $body - The message body text.
 * $module - The first argument to drupal_mail(), which is, by convention, the
 *           machine-readable name of the sending module.
 * $key - The second argument to drupal_mail(), which should give some indication
 *        of why this email is being sent.
 * $message - The message object. Not always available.
 * $message_id - The email message id, which should be equal to "{$module}_{$key}".
 * $headers - An array of email (name => value) pairs.
 * $from - The configured sender address.
 * $to - The recipient email address.
 * $to_user - User object for the recipient's user. Not always available.
 * $to_user_details - Array of details about recipient's user. Not always available.
 * $subject - The message subject line.
 * $body - The formatted message body.
 * $language - The language object for this message.
 * $params - Any module-specific parameters.
 * $template_name - The basename of the active template.
 * $template_path - The relative path to the template directory.
 * $template_url - The absolute URL to the template directory.
 * $theme - The name of the Email theme used to hold template files. If the Echo
 *          module is enabled this theme will also be used to transform the
 *          message body into a fully-themed webpage.
 * $theme_path - The relative path to the selected Email theme directory.
 * $theme_url - The absolute URL to the selected Email theme directory.
 * $debug - TRUE to add some useful debugging info to the bottom of the message.
 */
?>

<?php
// Styles
$table_style = 'width: 100%;
background: #fbfbfb;
border: 1px solid #E3E3E3;
border-radius: 4px;';
$subject_style = 'font-size: 20px;';
$user_badge_style = 'width: 170px;
background-color: #f9f9f9;
border: 1px solid #CCC;
border-radius: 4px;
text-align: right;
padding: 10px;';
$body_style = 'padding: 10px;
font-size: 14px;
line-height: 20px;
color: #333;';
?>

<h2 style="<?php print $subject_style; ?>"><?php print $subject; ?></h2>
<table style="<?php print $table_style; ?>">
  <tr>
    <td></td>
    <td style="<?php print $user_badge_style; ?>">
      <?php if (!empty($to_user->uid)): ?>
      <a href="<?php print url('user/' . $to_user->uid); ?>">
        <?php print $to_user_details['realname']; ?>
        <?php print $to_user_details['picture']; ?>
      </a>
      <?php endif; ?>
    </td>
  </tr>
  <tr>
    <td style="<?php print $body_style; ?>"><?php print $body; ?></div></td>
  </tr>
</table>
