<?php
/*

The following variables are available:
  $class - CSS classes of the body element
  $close - The close button, if applicable
  $body  - The generated content of the popup body

*/
?>



<div class="<?php print $class; ?>">
  <div class="inner">
    <?php print $close; ?>
    <?php print $body; ?>
  </div>
</div>