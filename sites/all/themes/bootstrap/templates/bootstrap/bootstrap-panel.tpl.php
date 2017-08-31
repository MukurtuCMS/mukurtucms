<?php
/**
 * @file
 * Default theme implementation to display a Bootstrap panel component.
 *
 * @todo Fill out list of available variables.
 *
 * @ingroup templates
 */
?>
<fieldset <?php print $attributes; ?>>
  <?php if ($title): ?>
    <?php if ($collapsible): ?>
    <legend class="panel-heading">
      <a href="#" class="panel-title fieldset-legend" data-toggle="collapse" data-target="<?php print $target; ?>"><?php print $title; ?></a>
    </legend>
    <?php else: ?>
    <legend class="panel-heading">
      <span class="panel-title fieldset-legend"><?php print $title; ?></span>
    </legend>
    <?php endif; ?>
  <?php endif; ?>
  <?php if ($collapsible): ?>
  <div class="panel-collapse collapse fade<?php print (!$collapsed ? ' in' : ''); ?>">
  <?php endif; ?>
  <div class="panel-body">
    <?php if ($description): ?><div class="help-block"><?php print $description; ?></div><?php endif; ?>
    <?php print $content; ?>
  </div>
  <?php if ($collapsible): ?>
  </div>
  <?php endif; ?>
</fieldset>
