<?php
/**
 * @file
 *   Default Scald DnD Library row theme.
 */
foreach ($library_items as $id => $item): ?>
  <div class="editor-item clearfix" id="sdl-<?php print $id; ?>">
    <?php print $item; ?>
  </div>
<?php endforeach; ?>
