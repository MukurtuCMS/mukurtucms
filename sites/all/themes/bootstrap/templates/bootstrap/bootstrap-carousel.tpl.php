<?php
/**
 * @file
 * Default theme implementation to display a Bootstrap carousel component.
 *
 * @todo Fill out list of available variables.
 *
 * @ingroup templates
 */
?>
<div<?php print $attributes; ?>>
  <?php if($indicators && ($item_length = count($items))): ?>
    <ol class="carousel-indicators">
      <?php for ($i = 0; $i < $item_length; $i++): ?>
        <li data-target="<?php print $target; ?>" data-slide-to="<?php print $i; ?>"<?php print ($start_index === $i ? ' class="active"' : ''); ?>></li>
      <?php endfor; ?>
    </ol>
  <?php endif; ?>
  <div class="carousel-inner">
    <?php foreach ($items as $i => $item): ?>
      <div class="item<?php print ($start_index === $i ? ' active' : ''); ?>">
        <?php print render($item['image']); ?>
        <?php if ($item['title'] || $item['description']): ?>
          <div class="carousel-caption">
            <?php if ($item['title']): ?>
              <h3><?php print $item['title']; ?></h3>
            <?php endif; ?>
            <?php if ($item['description']): ?>
              <p><?php print $item['description']; ?></p>
            <?php endif; ?>
          </div>
        <?php endif; ?>
      </div>
    <?php endforeach; ?>
  </div>
  <?php if($controls): ?>
    <a class="left carousel-control" href="<?php print $target; ?>" role="button" data-slide="prev">
      <span class="glyphicon glyphicon-chevron-left"></span>
    </a>
    <a class="right carousel-control" href="<?php print $target; ?>" role="button" data-slide="next">
      <span class="glyphicon glyphicon-chevron-right"></span>
    </a>
  <?php endif; ?>
</div>
