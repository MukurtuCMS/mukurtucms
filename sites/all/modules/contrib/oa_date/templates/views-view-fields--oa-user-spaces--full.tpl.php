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
 * - $field_feature_image: space image.
 * - $title: Title of the space.
 * - $created: How long user has been a member.
 * - $sections: Array of sections belonging to the space.
 *    - 'title': Title of the section.
 *    - 'href': Path to the section.
 *
 * @ingroup views_templates
 */
?>
<?php
$id = $row->node_og_membership_nid;
$has_sections = empty($sections) ? FALSE : TRUE;
?>

<div class="space-container">
  <div class="space-details clearfix">
    <div class="pull-left picture">
      <?php print $field_featured_image; ?>
    </div>
    <div class="details">
      <div class="title">
        <h5><?php print $title; ?></h5>
      </div>
      <div class="body">
        <?php print $body ?>
      </div>
    </div>
  </div>

  <?php if ($has_sections): ?>
  <div class="accordion sections-wrapper clearfix">
    <div class="toggle">
      <i class="icon-plus"></i>
      <a data-toggle="collapse" href="#sections-<?php print $id; ?>">Sections</a>
    </div>
    <div id="sections-<?php print $id; ?>" class="sections collapse">
      <?php foreach ($sections as $section): ?>
      <div class="section">
        <h6><?php print l($section['title'], $section['href']); ?></h6>
      </div>
      <?php endforeach; ?>
    </div>
  </div>
  <?php endif; ?>
</div>
