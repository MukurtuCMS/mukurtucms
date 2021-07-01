<?php

/**
 * @file
 * Displays the date views pager.
 *
 * Available variables:
 * - $attributes: A string of attributes to apply to the pager wrapper element.
 * - $items: A render array of pagination items.
 * - $mini: Flag indicating whether simple pager items should be shown.
 * - $nav_title: The formatted title for this view. In the case of block views,
 *   it will be a link to the full view, otherwise it will be the formatted name
 *   of the year, month, day, or week. See theme_date_nav_title() for more
 *   details.
 * - $prev_options: An list of link options that is passed to the link theme
 *   hook.
 * - $prev_url: URL for the previous calendar page.
 * - $next_options: An list of link options that is passed to the link theme
 *   hook.
 * - $next_url: URL for the next calendar page.
 * - $plugin: The pager plugin object. This contains the view.
 *
 * @see bootstrap_process_date_views_pager()
 * @see bootstrap_preprocess_date_views_pager()
 * @see template_preprocess_date_views_pager()
 *
 * @ingroup templates
 */
?>
<?php if (!empty($pager_prefix)): ?>
<?php print $pager_prefix; ?>
<?php endif; ?>
<nav<?php print $attributes;?>>
  <?php print render($items); ?>
  <h3><?php print $nav_title ?></h3>
</nav>
