<?php
/**
 * @file
 * Bootstrap 6-6 bricks template for Display Suite.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <?php if ($top) : ?>
    <div class="row">
      <<?php print $top_wrapper; ?> class="col-sm-12 <?php print $top_classes; ?>">
        <?php print $top; ?>
      </<?php print $top_wrapper; ?>>
    </div>
  <?php endif; ?>
  <?php if ($topleft || $topright) : ?>
    <div class="row">
      <<?php print $topleft_wrapper; ?> class="col-sm-6 <?php print $topleft_classes; ?>">
        <?php print $topleft; ?>
      </<?php print $topleft_wrapper; ?>>
      <<?php print $topright_wrapper; ?> class="col-sm-6 <?php print $topright_classes; ?>">
        <?php print $topright; ?>
      </<?php print $topright_wrapper; ?>>
    </div>
  <?php endif; ?>
  <?php if ($central) : ?>
    <div class="row">
      <<?php print $central_wrapper; ?> class="col-sm-12 <?php print $central_classes; ?>">
        <?php print $central; ?>
      </<?php print $central_wrapper; ?>>
    </div>
  <?php endif; ?>
  <?php if ($bottomleft || $bottomright) : ?>
    <div class="row">
      <<?php print $bottomleft_wrapper; ?> class="col-sm-6 <?php print $bottomleft_classes; ?>">
        <?php print $bottomleft; ?>
      </<?php print $bottomleft_wrapper; ?>>
      <<?php print $bottomright_wrapper; ?> class="col-sm-6 <?php print $bottomright_classes; ?>">
        <?php print $bottomright; ?>
      </<?php print $bottomright_wrapper; ?>>
    </div>
  <?php endif; ?>
  <?php if ($bottom) : ?>
    <div class="row">
      <<?php print $bottom_wrapper; ?> class="col-sm-12 <?php print $bottom_classes; ?>">
        <?php print $bottom; ?>
      </<?php print $bottom_wrapper; ?>>
    </div>
  <?php endif; ?>
</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
