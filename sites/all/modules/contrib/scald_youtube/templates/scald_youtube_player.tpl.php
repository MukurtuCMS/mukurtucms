<?php
/**
 * @file
 * Default theme implementation for the Scald Youtube Player.
 */
?>
<?php if ($vars['enable_defer']): ?>
  <?php if ($vars['enable_consent']): ?>
    <div class="scald-youtube-consent-wrapper">
      <?php print $vars['consent_text']; ?>
      <?php if ($vars['consent_button']): ?>
        <button class="js-scald-youtube-consent"><?php print $vars['consent_button']; ?></button>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <iframe class="scald-youtube js-scald-youtube" title="<?php print $vars['title'] ?>" width="<?php print $vars['video_width'] ?>" height="<?php print $vars['video_height'] ?>" src="about:blank" data-src="<?php print $vars['video_url'] ?>" allow="autoplay; fullscreen" allowfullscreen></iframe>
<?php else: ?>
  <iframe class="scald-youtube" title="<?php print $vars['title'] ?>" width="<?php print $vars['video_width'] ?>" height="<?php print $vars['video_height'] ?>" src="<?php print $vars['video_url'] ?>" allow="autoplay; fullscreen" allowfullscreen></iframe>
<?php endif; ?>
