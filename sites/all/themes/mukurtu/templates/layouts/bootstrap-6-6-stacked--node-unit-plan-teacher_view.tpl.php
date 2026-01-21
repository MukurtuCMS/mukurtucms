<?php
/**
 * @file
 * Bootstrap 6-6 stacked template for Display Suite.
 */
?>

<?php if (isset($mukurtu_tabbed_local_tasks[$nid]) && !empty($mukurtu_tabbed_local_tasks[$nid])): ?>
<div class="btn-group">
<button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Item Menu <span class="caret"></span></button>
<h2 class="element-invisible">Primary tabs</h2>
<ul class="dropdown-menu tabs--primary nav nav-tabs">
<?php print render($mukurtu_tabbed_local_tasks[$nid]);?>
</ul>
</div>
<?php endif; ?>


<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <?php if ($top): ?>
    <div class="row">
      <<?php print $top_wrapper; ?> class="col-sm-12 <?php print $top_classes; ?>">
        <?php print $top; ?>
      </<?php print $top_wrapper; ?>>
    </div>
  <?php endif; ?>
  <?php if ($left || $right): ?>
    <div class="row">
      <<?php print $left_wrapper; ?> class="col-sm-8 digital-heritage-body <?php print $left_classes; ?>">
        <?php print $left; ?>
      </<?php print $left_wrapper; ?>>
      <<?php print $right_wrapper; ?> class="col-sm-4 metadata-sidebar <?php print $right_classes; ?>">
       <div class="metadata-wrapper">
        <?php print $right; ?>
       </div>
      </<?php print $right_wrapper; ?>>
    </div>
  <?php endif; ?>
  <?php if ($bottom): ?>
    <div class="row">
      <<?php print $bottom_wrapper; ?> class="col-sm-12 digital-heritage-body <?php print $bottom_classes; ?>">
        <?php print $bottom; ?>
      </<?php print $bottom_wrapper; ?>>
    </div>
  <?php endif; ?>
</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
