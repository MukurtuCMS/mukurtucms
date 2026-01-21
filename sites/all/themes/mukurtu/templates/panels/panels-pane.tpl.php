<?php
/**
 * @file Panels-pane.tpl.php
 * Main panel pane template.
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<?php $collapse = (strpos($pane->subtype, 'facetapi') !== FALSE) ? TRUE : FALSE ?>
<?php if ($pane_prefix): ?>
  <?php print $pane_prefix; ?>
<?php endif; ?>
<div class="<?php print $classes; ?>" <?php print $id; ?> <?php print $attributes; ?>>
  <?php if ($admin_links): ?>
    <?php print $admin_links; ?>
  <?php endif; ?>
<?php
if($collapse) {
//    kpr($pane);
}
?>
  <?php print render($title_prefix); ?>
  <?php if($collapse): ?>
    <a data-toggle="collapse" href="#facet-pane-<?php print $pane->pid?>">
  <?php endif; ?>
  <?php if ($title): ?>
    <<?php print $title_heading; ?><?php print $title_attributes; ?>>
        <?php if($collapse): ?>
        <i class="fa fa-caret-right" aria-hidden="true"></i>
        <i class="fa fa-caret-down" aria-hidden="true"></i>
        <?php endif; ?>
      <?php print $title; ?>
    </<?php print $title_heading; ?>>
  <?php endif; ?>
  <?php if($collapse): ?>
    </a>
  <?php endif; ?>        
  <?php print render($title_suffix); ?>

  <?php if ($feeds): ?>
    <div class="feed">
      <?php print $feeds; ?>
    </div>
  <?php endif; ?>

  <?php if($collapse): ?>
  <div id="facet-pane-<?php print $pane->pid?>" class="pane-content collapse in">
  <?php else: ?>
  <div class="pane-content">
  <?php endif; ?>
    <?php print render($content); ?>
  </div>

  <?php if ($links): ?>
    <div class="links">
      <?php print $links; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <div class="more-link">
      <?php print $more; ?>
    </div>
  <?php endif; ?>
</div>
<?php if ($pane_suffix): ?>
  <?php print $pane_suffix; ?>
<?php endif; ?>
