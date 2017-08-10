<?php
/**
 * @file
 * Default theme implementation for the Scald Youtube Player.
 */
?>
<?php if ($vars['enable_defer']): ?>
  <iframe class="scald-youtube js-scald-youtube" title="<?php print $vars['title'] ?>" width="<?php print $vars['video_width'] ?>" height="<?php print $vars['video_height'] ?>" src="" data-src="<?php print $vars['video_url'] ?>" allowfullscreen></iframe>
<?php else: ?>
  <iframe class="scald-youtube" title="<?php print $vars['title'] ?>" width="<?php print $vars['video_width'] ?>" height="<?php print $vars['video_height'] ?>" src="<?php print $vars['video_url'] ?>" allowfullscreen></iframe>
<?php endif; ?>
