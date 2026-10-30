<?php
/**
 * @file
 * Provides the view for the spaces summary panel.
 *
 * $title - Title of the space
 * $description - Space description
 * $picture - Markup for the space's image.
 * $links - Array of links.
 *    'favorite' - Link to mark the space as favorite. Only available if user
 *                 is logged in.
 *    'edit' - Link to edit the space. Only available if user can edit it.
 */
?>
<div class="space-details clearfix">
  <?php if ($picture): ?>
    <?php print $picture; ?>
  <?php endif ?>
  <div class="description">
    <?php print $description; ?>
    <?php if (!empty($related)) { print $related; } ?>
  </div>
</div>
<?php if (!empty($links)): ?>
<div class="space-links clearfix">
  <?php foreach($links as $class => $link): ?>
    <div class="<?php print $class; ?>">
      <?php print $link; ?>
    </div>
  <?php endforeach; ?>
</div>
<?php endif ?>
