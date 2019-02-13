<?php

/**
 * @file
 * Display Suite 2 column template.
 */
?>

<?php  if (isset($mukurtu_tabbed_local_tasks[$nid]) && !empty($mukurtu_tabbed_local_tasks[$nid])): ?>
<div class="btn-group">
<button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Item Menu <span class="caret"></span></button>
<h2 class="element-invisible">Primary tabs</h2>
<ul class="dropdown-menu tabs--primary nav nav-tabs">
<?php print render($mukurtu_tabbed_local_tasks[$nid]);?>
</ul>
</div>
<?php endif; ?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-2col <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $left_wrapper ?> class="group-left<?php print $left_classes; ?>">
    <?php print $left; ?>
  </<?php print $left_wrapper ?>>

  <<?php print $right_wrapper ?> class="group-right<?php print $right_classes; ?>">
    <?php print $right; ?>
  </<?php print $right_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
