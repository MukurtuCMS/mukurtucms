<?php

/**
 * @file
 * Radix theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: An array of comment items. Use render($content) to print them all
 *   , or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the comment was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->created variable.
 * - $changed: Formatted date and time for when the comment was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->changed variable.
 * - $new: New comment marker.
 * - $permalink: Comment permalink.
 * - $submitted: Submission information created from $author and $created during
 *   template_preprocess_comment().
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - comment: The current template type, i.e., "theming hook".
 *   - comment-by-anonymous: Comment by an unregistered user.
 *   - comment-by-node-author: Comment by the author of the parent node.
 *   - comment-preview: When previewing a new or edited comment.
 *   The following applies only to viewers who are registered users:
 *   - comment-unpublished: An unpublished comment visible only to
 *     administrators.
 *   - comment-by-viewer: Comment by the user currently viewing the page.
 *   - comment-new: New comment since last the visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $paragraphs (html): Rendered paragraph output from field_oa_related.
 * - $reply_comment (html): Rendered comment reply link.
 * - $edit_comment (html): Rendered comment edit link.
 * - $delete_comment (html): Rendered comment delete link.
 *
 * These two variables are provided for context:
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_comment()
 * @see template_process()
 * @see theme_comment()
 * @see oa_comment_preprocess_comment()
 *
 * @ingroup themeable
 */
?>
<div class='oa-list oa-comment well clearfix'>
  <div class="user-picture pull-left">
    <span><?php // Mukurtu uncomment this when we want profile pics print $user_picture; ?></span>
  </div>
  <div class="accordion" id="oa-reply-accordion-<?php print $comment->cid; ?>">
    <div class="accordion-toggle">
      <div class="oa-list-header <?php print $status; ?> oa-description <?php print ($comment->new > 0) ? 'oa-comment-is-new' : 'oa-comment-hide' ?>">
        <div class="oa-comment-reply-body">
          <i class="pull-right fa fa-angle-down"></i>
          <div class="user-info">
            <?php print t('By') . " $author"; ?>
            <?php print t(' on '); ?>
            <span class="oa-date"> <?php
              // Mukurtu custom formatting of date
              print format_date($comment->created, 'custom', "F j, Y - g:ia"); ?></span>
            <span class="comment-label"><?php print $comment_link; ?></span>
            <?php if ($status == 'comment-unpublished'): ?>
              <span class="label mark-unpublished"><span class="marker">unpublished</span></span>
            <?php endif; ?>
            <?php if ($comment->new > 0): ?>
              <span class="label mark-new"><span class="marker">new</span></span>
            <?php endif; ?>
          </div>
          <?php if (isset($body) && strip_tags($body)): ?>
            <?php print $body; ?>
          <?php else: ?>
            <?php print $title; ?>
          <?php endif; ?>
          <?php
            unset($content['links']);
            unset($content['comment_body']);
            $content_extra = trim(drupal_render($content));
          ?>
          <?php if (!empty($content_extra)): ?>
            <div class="oa-comment-extra">
              <?php print $content_extra; ?>
            </div>
          <?php endif; ?>
          <?php if ($show_links): ?>
            <div class="links">
              <?php foreach ($comment_links as $key => $link): ?>
                <?php print $link; ?>
              <?php endforeach; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>
  </div>
</div>
