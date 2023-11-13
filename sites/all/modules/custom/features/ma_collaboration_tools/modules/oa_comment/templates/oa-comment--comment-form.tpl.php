<?php
/**
 * @file
 * Template for comment form.
 *
 * Available variables:
 * - $comment_parent: The parent comment for a reply.
 * - $comment_form: The comment body and format selector.
 * - $paragraph_buttons: Buttons that add a new paragraph attachment.
 * - $action_links: Submit buttons.
 */
?>

<div class="row">
  <?php if (isset($comment_parent)): ?>
    <div class="reply-comment-parent col-md-12">
      <?php print $comment_parent; ?>
    </div>
  <?php endif; ?>

  <div class="comment-form col-md-12">
    <?php print $comment_form; ?>
  </div>

  <div class="paragraph-form col-md-12">
    <?php print $paragraph_buttons; ?>
  </div>

  <div class="comment-reply-post-button pull-right col-md-2">
    <?php print $action_links; ?>
  </div>
</div>
