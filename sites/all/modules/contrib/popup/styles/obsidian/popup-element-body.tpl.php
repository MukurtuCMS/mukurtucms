<div class="<?php print $class; ?>">
  <?php
    /* *Shudder*
     * Tables were the only way to get semi-transparent borders and backgrounds to work, especially in IE.
     * If you have a better way of implementing this that works, please let me know!
     */
  ?>
  <table class="popup-layout">
    <tr class="top"><td class="left"></td><td class="center"></td><td class="right"></td></tr>
    <tr class="center">
      <td class="left"></td>
      <td class="center">
        <div class="inner">
          <?php print $close; ?>
          <?php print $body; ?>
         </div>
      </td>
      <td class="right"></td>
    </tr>
    <tr class="bottom"><td class="left"></td><td class="center"></td><td class="right"></td></tr>
  </table>

</div>


