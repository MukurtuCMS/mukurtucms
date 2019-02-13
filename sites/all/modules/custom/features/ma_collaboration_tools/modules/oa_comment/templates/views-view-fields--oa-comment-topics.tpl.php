<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<div class='oa-list oa-discussion-topic clearfix'>
  <div class='user-picture oa-pull-left'>
    <?php // Mukurtu uncomment this when profile pics are more common. print $field_user_picture; ?>
  </div>
  <div class='oa-list-header oa-description oa-list-category oa-pull-right'>
    <div>
      <?php if (!empty($new_mark)): ?>
        <span class="oa-reply-mark label <?php print $mark_class; ?>"><?php print $new_mark; ?></span>
      <?php endif; ?>
      <?php if (!empty($comment_count)): ?>
        <span class="oa-reply-text <?php print $reply_class; ?>">
          <a href="<?php print $last_comment_link; ?>"><?php print $reply_title; ?></a>
        </span>
        <span class="oa-reply-icon <?php print $reply_class; ?>" title="<?php print $reply_title; ?>">
          <span class="oa-reply-count">
            <a href="<?php print $last_comment_link; ?>"><?php print $comment_count; ?></a>
          </span><i class="fa fa-comment"></i>
        </span>
      <?php endif; ?>
    </div>
    <?php if ($comment_count > 0): ?>
      <div class="oa-reply-last">
        <a href="<?php print $last_comment_link; ?>"><?php print t(" Last reply"); ?></a>
        <?php print t(' by ');  ?>
        <span class="user-info">
          <?php print $name_1; ?>
        </span>
      </div>
    <?php endif; ?>
  </div>
  <div class='oa-list-header'>
    <h5>
      <?php print $title; ?>
    </h5>
    <div class="oa-description">
      <?php print t('By '); ?>
      <span class="user-info">
        <?php print $name; ?>
      </span>
      <?php print t(' on '); ?>
      <span class="oa-date">
        <?php print $created; ?>
      </span>
    </div>
  </div>
</div>
