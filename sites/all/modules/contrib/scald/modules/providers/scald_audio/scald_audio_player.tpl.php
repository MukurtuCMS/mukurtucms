<?php
/**
 * @file
 * Scald Audio player template
 * Created by Hervé Tubaldo - herve@webup.fr
 */
?>
<object type="application/x-shockwave-flash" data="<?php echo base_path().drupal_get_path('module','ma_scald'); ?>/players/dewplayer/dewplayer.swf" width="200" height="7" id="dewplayer-<?php echo $vars['atom']->sid ?>" name="dewplayer">
  <param name="movie" value="<?php echo base_path().drupal_get_path('module','ma_scald'); ?>/players/dewplayer/dewplayer.swf" />
  <param name="flashvars" value="mp3=<?php echo file_create_url($vars['audio_uri']) ?>" />
  <param name="wmode" value="transparent" />
</object>
