<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <?php print $content['top']; ?>
  </div>
  <div class="row">
    <?php print $content['left_above']; ?>
    <?php print $content['right_above']; ?>
  </div>
  <div class="row">
    <?php print $content['middle']; ?>
  </div>
  <div class="row">
    <?php print $content['left_below']; ?>
    <?php print $content['right_below']; ?>
  </div>
  <div class="row">
    <?php print $content['bottom']; ?>
  </div>
</div>
