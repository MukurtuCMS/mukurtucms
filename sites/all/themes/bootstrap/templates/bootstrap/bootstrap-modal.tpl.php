<?php
/**
 * @file
 * Default theme implementation to display a Bootstrap modal component.
 *
 * Markup for Bootstrap modals.
 *
 * Variables:
 * - $attributes: Attributes for the outer modal div.
 * - $dialog_attributes: Attributes for the inner modal div.
 * - $heading: Modal title.
 * - $body: The rendered body of the modal.
 * - $footer: The rendered footer of the modal.
 * - $size: The size of the modal. Can be empty, "sm" or "lg". This is
 *   automatically added in the $dialog_attributes. See
 *   bootstrap_preprocess_bootstrap_modal().
 *
 * @ingroup templates
 */
?>
<div<?php print $attributes; ?>>
  <div<?php print $dialog_attributes; ?>>
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h4 class="modal-title"><?php print $heading; ?></h4>
      </div>
      <div class="modal-body"><?php print $body; ?></div>
      <div class="modal-footer"><?php print $footer; ?></div>
    </div>
  </div>
</div>
