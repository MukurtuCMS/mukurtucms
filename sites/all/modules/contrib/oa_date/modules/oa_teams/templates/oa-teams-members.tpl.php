<?php
/**
 * @file
 * Template that provides the view for the space members widget.
 *
 * $owners - Array of owners.
 *   'title'    - Link to the owner user.
 *   'picture'  - Rendered image of the user.
 * $teams - Array of teams.
 *   'title'    - Link to the team node.
 * $users - Array of users.
 *   'title'    - Link to the owner user.
 *   'picture'  - Rendered image of the user.
 */
?>
<?php if (!empty($members)): ?>
  <div class='clearfix members'>
    <?php foreach ($members as $id => $member): ?>
      <?php if (empty($links['remove'])): ?>
        <div class='oa-pull-left user-badge'>
        <?php print $member['picture']; ?>
          <?php print $member['title']; ?>
        </div>
      <?php else: ?>
        <div class="dropdown oa-dropdown btn-group">
          <div class="dropdown-toggle btn oa-pull-left user-badge"
               data-toggle="dropdown">
            <?php print $member['picture']; ?>
            <?php print $member['title']; ?>
            <i class='icon-chevron-down'></i>
          </div>
          <div class="dropdown-menu" role="menu" aria-labelledby="dropdownMenu">
            <ul>
              <li><?php print l(t('Dashboard'), $links['dashboard'] . $member['uid']); ?></li>
              <li><?php print l(t('Remove from team'), $links['remove'] . $member['uid'], $links['remove_options'][$id]); ?></li>
            </ul>
          </div>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
