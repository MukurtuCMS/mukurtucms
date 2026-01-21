<?php
/**
 * @file
 * Scald Video player template
 * Created by SylvainM, cmi75
 * Thanks to defr
 */
?>
<video id="scald-video-<?php echo $vars['atom']->sid; ?>" controls="controls" preload="metadata" class="<?php echo $vars['class']; ?>" width="<?php echo $vars['video_width']; ?>" height="<?php echo $vars['video_height']; ?>" poster="<?php echo file_create_url($vars['thumbnail']); ?>">
  <?php foreach ($vars['video_sources'] as $source) { ?>
  <source src="<?php echo $source['path']; ?>" type="<?php echo $source['mime_type']; ?>" />
  <?php } ?>
</video>
