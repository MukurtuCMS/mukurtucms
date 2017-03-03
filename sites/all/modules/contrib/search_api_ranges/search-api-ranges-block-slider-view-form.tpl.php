<?php
/**
 * @file
 * Custom Search API ranges Min/Max UI slider widget.
 */
?>
<div class="search-api-ranges-text"><?php print drupal_render($form['text-range']); ?></div>
<div class="search-api-ranges-elements">
  <div class="search-api-ranges-element range-box range-box-left">
    <?php print drupal_render($form['range-from']); ?>
  </div>
  <div class="search-api-ranges-element range-slider-box">
    <?php print drupal_render($form['range-slider']); ?>
  </div>
  <div class="search-api-ranges-element range-box range-box-right">
    <?php print drupal_render($form['range-to']); ?>
  </div>
</div>
<?php print drupal_render($form['submit']); ?>
<?php
  // Render required hidden fields.
  print drupal_render_children($form);
?>
