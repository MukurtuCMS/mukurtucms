<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * Available variables:
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 *
 * @ingroup templates
 */
?>
<?php if ($responsive): ?>
<div class="table-responsive">
<?php endif; ?>
<table <?php print $classes ? 'class="' . $classes . '" ' : ''; ?><?php print $attributes; ?>>
  <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <th <?php print $header_classes[$field] ? 'class="' . $header_classes[$field] . '" ' : ''; ?>>
            <?php print $label; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php print $row_classes[$row_count] ? 'class="' . implode(' ', $row_classes[$row_count]) . '"' : ''; ?>>
        <?php foreach ($row as $field => $content): ?>
          <td <?php print $field_classes[$field][$row_count] ? 'class="' . $field_classes[$field][$row_count] . '" ' : ''; ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php print $content; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
<?php if ($responsive): ?>
  </div>
<?php endif; ?>
