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
<div class='oa-list oa-news clearfix'>
  <?php if (!empty($field_user_picture)): ?>
  <div class='user-picture pull-right'>
    <?php print $field_user_picture; ?>
  </div>
  <?php endif; ?>
  <div class='oa-news-header'>
    <?php print $title; ?>
    <?php if (!empty($timestamp)): ?>
      <span class='pull-right'>
        &nbsp;<?php print $timestamp; ?>
      </span>
    <?php endif; ?>
    <div class='oa-news-posted'>
      <span class="user-info">
        <?php if (!empty($name)): ?>
        <?php print t('By '); ?>
        <?php print $name; ?>
        <?php endif; ?>
        <?php if (!empty($created)): ?>
        <?php print t(' on '); ?>
        <span class="oa-date"><?php print $created; ?></span>
        <?php endif; ?>
      </span>
      <?php if (!empty($edit_node)): ?>
        <span class="oa-edit-node">
          <?php print $edit_node; ?>
        </span>
      <?php endif; ?>
    </div>
  </div>
  <div class='oa-news-body'>
    <?php if (!empty($field_oa_media)): ?>
      <div class='oa-news-image pull-left'>
        <?php print $field_oa_media; ?>
      </div>
    <?php elseif (!empty($field_featured_image)): ?>
      <div class='oa-news-image pull-left'>
        <?php print $field_featured_image; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($body_summary)): ?>
    <div class='oa-news-body'>
      <?php print $body_summary; ?>
    </div>
    <?php endif; ?>
    <?php if (!empty($term_node_tid)): ?>
      <div class='oa-news-tags'>
        <?php print t('Categories: ') . $term_node_tid; ?>
      </div>
    <?php endif; ?>
  </div>
</div>
