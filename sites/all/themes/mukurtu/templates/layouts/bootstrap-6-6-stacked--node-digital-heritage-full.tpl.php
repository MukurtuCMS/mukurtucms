<?php
/**
 * @file
 * Bootstrap 6-6 stacked template for Display Suite.
 */
?>

<?php
// Multi-page carousel display
?>
<?php if ($node->field_book_children OR $node->field_book_parent): ?>
<?php
if(isset($node->field_book_children) && count($node->field_book_children) > 0) {
    $first_page = $node; 
} else {
    $first_page = node_load($node->field_book_parent[LANGUAGE_NONE][0]['target_id']);
}
$pages = $first_page->field_book_children[LANGUAGE_NONE];
?>
<div id="mukurtu-multipage-carousel" class="slick-carousel slick-carousel-multipage">
  <?php
    $page = 0;
    $initial_slide = 0;
    if(!empty($first_page->field_media_asset[LANGUAGE_NONE])) {
        $classes = "";
        if($first_page->nid == $node->nid) {
            $initial_slide = $page;
            $classes .= 'current-page';
        }
        $sid = $first_page->field_media_asset[LANGUAGE_NONE][0]['sid'];
        print "<div class=\"$classes\">";
        $url = url(drupal_get_path_alias('node/' . $first_page->nid));
        print "<a href='$url'>";
        print scald_render($sid, 'mukurtu_multi_page_carousel');
        print "</a></div>";
    }

    foreach($first_page->field_book_children[LANGUAGE_NONE] as $child_page) {
        $child_node = node_load($child_page['target_id']);

        // Check if this is the currently selected page
        $classes = "";
        $page++;
        if($child_node->nid == $node->nid) {
            $initial_slide = $page;
            $classes .= 'current-page';
        }

        $sid = $child_node->field_media_asset[LANGUAGE_NONE][0]['sid'];
        print "<div class=\"$classes\">";
        $url = url(drupal_get_path_alias('node/' . $child_node->nid));
        print "<a href='$url'>";
        print scald_render($sid, 'mukurtu_multi_page_carousel');
        print "</a></div>";
    }
    drupal_add_js(array('mukurtu' => array('dh_multipage_initial_slide' => $initial_slide)), 'setting');
  ?>
</div>
<div class="mukurtu-page-number"><?php print t("Page %current of @total", array('%current' => $initial_slide, '@total' => $page)); ?></div>
<?php endif; ?>


<?php if (isset($cr_tabs[$nid])): ?>
<div class="btn-group">
<button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Item Menu <span class="caret"></span></button>
<h2 class="element-invisible">Primary tabs</h2>
<ul class="dropdown-menu tabs--primary nav nav-tabs">
<?php print render($cr_tabs[$nid]);?>
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
      <<?php print $left_wrapper; ?> class="col-sm-8 <?php print $left_classes; ?>">
        <?php print $left; ?>
      </<?php print $left_wrapper; ?>>
      <<?php print $right_wrapper; ?> class="col-sm-4 <?php print $right_classes; ?>">
       <div class="metadata-wrapper">
        <?php print $right; ?>
       </div>
      </<?php print $right_wrapper; ?>>
    </div>
  <?php endif; ?>
  <?php if ($bottom): ?>
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
