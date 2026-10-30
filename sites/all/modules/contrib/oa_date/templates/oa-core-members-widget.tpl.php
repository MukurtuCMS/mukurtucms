<?php
/**
 * @file
 * Template that provides the view for the space members widget.
 *
 * $tabs[$category] = array
 *   'title' - title of category
 *   'items' - array of users
 *   'links' - array of links
 *
 * array of users = array
 *   'title' - name of user
 *   'picture' - user picture
 *   'uid' - user id
 *
 * array of links = array
 *   'title' - link text
 *   'url' - link url.  user id will be appended to this url
 */
?>

<div id="oa-core-messages"></div>

<?php if ($show_as_tabs): ?>
  <ul class="nav nav-tabs">
    <?php foreach ($categories as $cat): ?>
      <?php if (!empty($tabs[$cat]['items']) || !empty($tabs[$cat]['global_links'])): ?>
        <li
          class="tab-<?php print $cat; ?> <?php if ($cat == $active): print 'active'; endif; ?>">
          <a href="#tab-<?php print $cat ?>" data-toggle="tab">
            <?php print $tabs[$cat]['caption']; ?>
          </a></li>
      <?php endif; ?>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
<div class="tab-content">
  <?php foreach ($categories as $cat): ?>
    <?php if (!empty($tabs[$cat]['items']) || !empty($tabs[$cat]['global_links'])): ?>
      <?php if ($show_as_tabs): ?>
        <div class="tab-pane <?php if ($cat == $active): print 'active'; endif; ?>" id="<?php print 'tab-' . $cat; ?>">
      <?php endif; ?>
      <?php
      $tab = $tabs[$cat];
      $well = (!empty($tab['title'])) ? ' well well-sm' : '';
      ?>
      <div class='clearfix <?php print $well . ' ' . $cat; ?>'>
        <?php if (!empty($tab['items']) || !empty($tab['global_links'])): ?>
          <?php if (!empty($tab['title'])): ?>
            <h5><?php print $tab['title'] ?></h5>
          <?php endif; ?>
          <?php foreach ($tab['items'] as $key => $items): ?>
            <?php if (!is_numeric($key)): ?>
              <h5 class='clear-both'>
                <?php print $key; ?>
              </h5>
            <?php endif; ?>
            <?php foreach ($items as $item): ?>
              <?php if (empty($tab['links'])): ?>
                <div class='oa-pull-left label'>
                  <?php print $item['title']; ?>
                </div>
              <?php elseif (empty($item['uid'])): ?>
                <div class='oa-pull-left dropdown oa-dropdown btn-group'>
                  <div class="dropdown-toggle btn oa-pull-left user-badge">
                    <?php print $item['picture']; ?>
                    <?php print $item['title']; ?>
                  </div>
                </div>
              <?php else: ?>
                <div class="oa-pull-left dropdown oa-dropdown btn-group">
                  <div class="dropdown-toggle btn oa-pull-left user-badge"
                       data-toggle="dropdown">
                    <?php print $item['picture']; ?>
                    <?php print $item['title']; ?>
                    <i class='icon-chevron-down'></i>
                  </div>
                  <div class="dropdown-menu" role="menu"
                       aria-labelledby="dropdownMenu">
                    <ul>
                      <?php foreach ($tab['links'] as $lid): ?>
                        <?php if (!empty($links[$lid]['url'])): ?>
                          <li>
                            <?php
                            $url = str_replace('%uid', $item['uid'], $links[$lid]['url']);
                            print l($links[$lid]['title'], $url,
                              empty($links[$lid]['noajax']) ? $item['options'] : array()); ?>
                          </li>
                        <?php endif; ?>
                      <?php endforeach; ?>
                    </ul>
                  </div>
                </div>
              <?php endif; ?>
            <?php endforeach; ?>
          <?php endforeach; ?>
        <?php endif; ?>
        <?php if (!empty($tab['form'])): ?>
          <div class='clear-both'>
            <hr>
            <?php print render($tab['form']) ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($tab['global_links'])): ?>
          <div class='clear-both oa-global-links'>
            <?php foreach ($tab['global_links'] as $link): ?>
              <a href="<?php print $link['url'] ?>"
                 class="btn btn-sm btn-default"><?php print $link['title'] ?></a>
            <?php endforeach; ?>
          </div>
        <?php endif; ?>
      </div>
      <?php if ($show_as_tabs): ?>
        </div>
      <?php endif; ?>
    <?php endif; ?>
  <?php endforeach; ?>
</div>
