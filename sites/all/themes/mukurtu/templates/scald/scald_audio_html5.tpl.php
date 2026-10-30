<?php
/**
 * @file
 * Scald Audio player template
 * Changed to use HTML5 Audio element by Mark Conroy - https://www.drupal.org/user/336910
 */

$type = "";
if(substr($vars['audio_uri'], -3, 3) == 'm4a') {
  $type = 'type="audio/mp4"';
  }
?>
<audio controls preload="metadata" style="width:100%;height:100%;">
 <source src="<?php echo file_create_url($vars['audio_uri']) ?>" <?php echo $type ?>>
 <p>Your browser does not support the audio element.</p>
</audio>
