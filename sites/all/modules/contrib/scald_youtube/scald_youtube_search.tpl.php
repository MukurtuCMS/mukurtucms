<?php
/**
 * @file
 * Default theme implementation for the Scald Youtube Search Grid.
 */
?>
<?php if (!empty($videos)): ?>
  <?php foreach ($videos as $video): ?>
    <div class="youtube-result-item">
      <div class="youtube-result-item-image"><img src="<?php echo $video->snippet->thumbnails->default->url ?>" /></div>
      <div class="youtube-result-item-title"><?php echo check_plain($video->snippet->title) ?></div>
      <div class="youtube-result-item-id"><?php echo $video->id->videoId ?></div>
    </div>
  <?php endforeach; ?>
<?php endif; ?>
