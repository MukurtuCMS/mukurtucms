<?php
/**
 */
?>
<object width="<?php print $vars['flash_width'] ?>" height="<?php print $vars['flash_height'] ?>" classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000">
  <param name="movie" value="<?php print $vars['flash_uri'] ?>"></param>
  <param name="allowFullScreen" value="true"></param>
  <param name="allowScriptAccess" value="always"></param>
  <param name="wmode" value="transparent"></param>
  <object data="<?php print $vars['flash_uri'] ?>" type="application/x-shockwave-flash" width="<?php print $vars['flash_width'] ?>" height="<?php print $vars['flash_height'] ?>" allowfullscreen="true" allowscriptaccess="always" wmode="transparent">
    <img src="<?php print $vars['thumbnail'] ?>" alt="" class="dnd-dropped" width="<?php print $vars['flash_width'] ?>" />
  </object>
</object>
