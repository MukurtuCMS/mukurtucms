<?php
/**
 * @file
 * Template for oa_members_toolbar pane.
 */
?>
<ul class="oa-members-toolbar oa_toolbar">
  <li class='dropdown btn-group'>
    <a href="#" class="dropdown-toggle <?php print $btn_class; ?> <?php print $direction; ?>" data-toggle='dropdown' title="<?php print $title?>">
      <i class="<?php print $icon; ?>"></i><span class="element-invisible"><?php print $title;?></span>
    </a>
    <ul class="dropdown-menu" role="menu">
      <li class="dropdown-column">
        <div class="item-list">
          <h3><?php print $space_title; ?></h3>
          <?php print $links; ?>
          <?php if (!empty($admins)): ?>
            <h4 class="oa-border-top"><?php print t('Admins'); ?></h4>
            <?php print $admins; ?>
          <?php endif; ?>
          <h4 class="oa-border-top"><?php print t('Members'); ?></h4>
          <?php if (!empty($members)): ?>
            <?php print $members; ?>
          <?php else: ?>
            <h5><?php print t('No members'); ?></h5>
          <?php endif; ?>
        </div>
      </li>
    </ul>
  </li>
</ul>
