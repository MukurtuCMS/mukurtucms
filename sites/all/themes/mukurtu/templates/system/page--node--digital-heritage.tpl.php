<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
?>

<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
<div class="mukurtu-menu <?php print $container_class; ?>">
        <nav role="navigation">
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
        </nav>
  </div>
  <div class="mukurtu-menu mukurtu-login-menu <?php print $container_class; ?>">
        <nav role="navigation">
        <?php
        $menu = menu_navigation_links('menu-log-in-log-out');
        if($menu) {
          print theme('links__menu_log_in_log_out', array('links' => $menu));
        }
        ?>
        </nav>
  </div>
  <div id="mukurtu-collapse-menu-container" class="<?php print $container_class; ?>">
    <div class="navbar-header">
      <?php if ($logo): ?>
        <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navbar-collapse">
          <div class="collapse-menu-color-bars">
            <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </div>
          <div class="collapse-menu-label">Menu</div>
        </button>
      <?php endif; ?>
    </div>

    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="navbar-collapse collapse" id="navbar-collapse">
        <nav role="navigation">
          <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>
        </nav>
      </div>
    <?php endif; ?>
  </div>
</header>

<div class="main-container <?php print $container_class; ?>">

  <header role="banner" id="page-header">
    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb;
      endif;?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>



<?php
/////////////////////////////////////////////////////
// Start Digital Heritage multi-page carousel display
/////////////////////////////////////////////////////
?>
<?php
// If this is a community record, use the parent node for multipage checks
if(!empty($node->field_community_record_parent[LANGUAGE_NONE])) {
    $multipage_node = node_load($node->field_community_record_parent[LANGUAGE_NONE][0]['target_id']);
} else {
    $multipage_node = $node;
}
?>
<?php
// Is this a multi-page item?
$edit = (!is_numeric(basename(current_path()))) ? TRUE : FALSE;
if (!$edit && ($multipage_node->field_book_children || $multipage_node->field_book_parent)):
?>
<?php
// Find the first page
if(isset($multipage_node->field_book_children) && count($multipage_node->field_book_children) > 0) {
    $first_page = $multipage_node;
} else {
    $first_page = node_load($multipage_node->field_book_parent[LANGUAGE_NONE][0]['target_id']);
}
$pages = $first_page->field_book_children[LANGUAGE_NONE];
?>
<div class="row">
<div id="mukurtu-multipage-carousel" class="slick-carousel slick-carousel-multipage">
  <?php
    $dh_page = 0;
    $initial_slide = 0;
    $options = array();
    $options[-1] = t("Skip to page");
    if(!empty($first_page->field_media_asset[LANGUAGE_NONE])) {
        $classes = "";
        if($first_page->nid == $multipage_node->nid) {
            $initial_slide = $dh_page;
            $classes .= 'current-page';
        }
        $sid = $first_page->field_media_asset[LANGUAGE_NONE][0]['sid'];
        print "<div class=\"$classes\"><span class=\"mukurtu-loader\"></span>";
        $url = url(drupal_get_path_alias('node/' . $first_page->nid));
        print "<a href='$url'>";
        print scald_render($sid, 'mukurtu_multi_page_carousel');
        print "</a></div>";
        $options[$dh_page] = $first_page->title;
    }

    foreach($first_page->field_book_children[LANGUAGE_NONE] as $child_page) {
        $child_node = node_load($child_page['target_id']);

        // Check if this is the currently selected page
        $classes = "";
        $dh_page++;
        if($child_node->nid == $multipage_node->nid) {
            $initial_slide = $dh_page;
            $classes .= 'current-page';
        }

        $sid = $child_node->field_media_asset[LANGUAGE_NONE][0]['sid'];
        print "<div class=\"$classes\"><span class=\"mukurtu-loader\"></span>";
        $url = url(drupal_get_path_alias('node/' . $child_node->nid));
        print "<a href='$url'>";
        print scald_render($sid, 'mukurtu_multi_page_carousel');
        print "</a></div>";
        $options[$dh_page] = $child_node->title;
    }
    drupal_add_js(array('mukurtu' => array('dh_multipage_initial_slide' => $initial_slide)), 'setting');
    $initial_slide++;
    $dh_page++;
  ?>
</div>
<div class="mukurtu-page-number col-xs-6"><?php print t("Page %current of @total", array('%current' => $initial_slide, '@total' => $dh_page)); ?></div>
<div class="mukurtu-page-select col-xs-6">
   <form name="digital-heritage-multi-page-page-select">
      <div class="mukurtu-page-select-wrapper"><select>
        <?php
        foreach($options as $delta => $option) {
            print "<option value=\"$delta\">$option</option>";
        }
        ?>
      </select></div>
   </form>
</div>
</div>
<?php endif; ?>
<?php
///////////////////////////////////////////////////
// End Digital Heritage multi-page carousel display
///////////////////////////////////////////////////
?>


      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>

<?php if (!empty($page['footer'])): ?>
  <footer class="footer <?php print $container_class; ?>">
    <?php print render($page['footer']); ?>
  </footer>
<?php endif; ?>
