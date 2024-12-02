<?php
/**
 * @file
 * Provides view for user profile panel.
 *
 * $picture - Markup of the user's profile picture.
 * $realname - Real name field. Defaults to unique name if unavailable.
 * $name - Unique user name.
 * $links - Array of useful links.
 *    'dashboard' - Link to the user's page.
 *    'edit_profile' - Link to edit user's profile.
 *    'logout' - Logout link.
 */
?>

<div class="well well-sm">
<div class="details clearfix">
    <div class="pull-left user-picture">
      <?php print $picture ?>
    </div>
    <div class="pull-right user-info">
      <div class="user-realname">
        <?php print l($realname, $links['dashboard']); ?>
      </div>
      <span class="user-name">
        <?php print $name; ?>
      </span>
    </div>
  </div>
  <div class="links">
    <?php print l(t('Manage my profile'), $links['edit_profile']); ?>
    <?php print l(t('Logout'), $links['logout']); ?>
  </div>
</div>