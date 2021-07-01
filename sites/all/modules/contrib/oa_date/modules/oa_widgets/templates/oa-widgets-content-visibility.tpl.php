<?php

/**
 * @file
 * Provides the view for the content visibility widget.
 *
 * - $public: boolean, whether or not content is public.
 * - $accessors: array of arrays that represent things that have access to the
 *   content
 *   - ['label']: string label of the accessor
 *   - ['links']: array of link strings
 */
?>

<?php if ($archived): ?>
  <div class="oa-visibility-private"><?php print t('Archived'); ?></div>

<?php elseif (!$published): ?>
  <div class="oa-visibility-private"><?php print t('Unpublished'); ?></div>

<?php elseif ($public): ?>
  <div class="oa-visibility-public"><?php print t('Public'); ?></div>
<?php else: ?>
  <div class="oa-visibility-private">
    <i class="icon-lock"></i> <?php print t('Private'); ?>
  </div>
  <?php if (!empty($accessors)): ?>
  <p><em><?php print t('Only the following can see this page'); ?></em></p>
  <p class="oa-visibility-list">
    <?php foreach ($accessors as $class => $accessor): ?>
      <?php if (!empty($accessor['links'])): ?>
        <div class="oa-visibility-<?php print $class ?>">
          <div class='oa-visibility-header'>
            <?php print $accessor['label']; ?>
          </div>
          <div class='oa-visibility-list'>
            <?php print implode(', ', $accessor['links']); ?>
          </div>
        </div>
      <?php endif; ?>
    <?php endforeach ?>
  </p>
  <?php endif; ?>
  <?php if (!empty($space_public_in_private)): ?>
    <p class="alert alert-danger"><em><?php print t('Space is marked as PUBLIC within a PRIVATE parent.'); ?></em></p>
  <?php endif; ?>
<?php endif ?>
