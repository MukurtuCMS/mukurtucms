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
      <a href="<?php print $target; ?>" class="panel-title fieldset-legend<?php print ($collapsed ? ' collapsed' : ''); ?>" data-toggle="collapse"><?php print $title; ?></a>
    </legend>
    <?php else: ?>
    <legend class="panel-heading">
      <span class="panel-title fieldset-legend"><?php print $title; ?></span>
    </legend>
    <?php endif; ?>
  <?php endif; ?>
  <div<?php print $body_attributes; ?>>
    <?php if ($description): ?><div class="help-block"><?php print $description; ?></div><?php
    endif; ?>
    <?php print $content; ?>
  </div>
</fieldset>
