<?php
/*

  The following variables are available:
    $css_id - CSS ID
    $class  - CSS class of the popup element
    $title  - Themed title of the popup
    $body   - Themed content of the popup

 */
?>



<div id="<?php print $css_id;?>" class="<?php print $class;?>">
  <?php print $title; ?>
  <?php print $body; ?>
</div>