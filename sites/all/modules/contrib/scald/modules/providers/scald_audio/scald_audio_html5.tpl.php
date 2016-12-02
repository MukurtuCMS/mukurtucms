<?php
/**
 * @file
 * Scald Audio player template
 * Changed to use HTML5 Audio element by Mark Conroy - https://www.drupal.org/user/336910
 */
?>
<audio controls preload="metadata">
 <source src="<?php echo file_create_url($vars['audio_uri']) ?>">
 <p>Your browser does not support the audio element.</p>
</audio>
