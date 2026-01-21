<div class="oa-users-submitted align-<?php print $align;?>">
  <?php if ($align == 'left'):?>
    <?php if (!empty($picture)):?>
      <span class="user-picture pull-left"><?php print $picture; ?></span>
    <?php endif; ?>
  <?php endif; ?>
  <?php if ($show_title): ?><h1 class="title <?php print !$show_author ? 'no-picture' : ''; ?>" id="page-title"><?php print $title; ?></h1><?php endif; ?>
  <?php if ($show_author): ?>
    <div class="user-info align-<?php print $align;?>">
      <?php if ($align == 'left'):?>
        <?php print t('By '); ?>
        <div class="user-badge">
          <?php if (!empty($userlink)):?>
            <span><?php print $userlink; ?></span>
          <?php endif; ?>
        <?php if (!empty($date)):?>
          <?php print t(' on '); ?>
          <span class="oa-date"><?php print $date; ?></span>
        <?php endif; ?>
        </div>
      <?php else: ?>
        <?php print t('Posted '); ?>
        <?php if (!empty($date)):?>
          <span class="oa-date"><?php print $date; ?></span>
        <?php endif; ?>
        <?php if (!empty($userlink)):?>
          <?php print t(' by '); ?>
          <div class="user-badge">
              <span><?php print $userlink; ?></span>
          </div>
        <?php endif; ?>
        <?php if (!empty($picture)):?>
          <span class="user-picture"><?php print $picture; ?></span>
        <?php endif; ?>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>
