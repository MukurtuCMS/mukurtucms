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
<div class='oa-list <?php print ($display == 'user_activity') ? 'oa-user-activity' : ''; ?> oa-river well clearfix >'>
  <?php if ($display != 'user_activity'): ?>
    <div class='user-picture pull-left'>
      <?php print $field_user_picture; ?>
    </div>
  <?php endif; ?>
  <div class="oa-list-inner">
    <div class='oa-list-category oa-pull-right'>
      <?php if ($display == 'user_activity'): ?>
        <?php print $field_oa_message_space; ?>
      <?php endif; ?>
    </div>
    <div class='oa-list-header pull-right oa-description oa-date'>
      <?php print $timestamp; ?>
    </div>
    <?php if (strlen(trim(strip_tags($rendered_entity))) > 0): ?>
      <div class='oa-list-header'>
        <?php print $rendered_entity; ?>
        <?php if (($display != 'section_activity') && !empty($field_oa_message_section)): ?>
          <?php print t(' in ') . $field_oa_message_section; ?>
        <?php endif; ?>
        <?php if (!empty($fields['ops'])) {
          print $fields['ops']->content;
        } ?>
      </div>
      <?php if (strlen(trim(strip_tags($rendered_entity_2))) > 0): ?>
        <div class="accordion" id="oa-river-accordion<?php print $index; ?>">
          <div>
            <div class="accordion-heading">
              <a class="accordion-toggle" data-toggle="collapse"
                 data-parent="#oa-river-accordion<?php print $index; ?>"
                 href="#oa-river-body<?php print $index; ?>">
                <i class="fa fa-angle-down" vertical-align="middle"></i>
                <?php print $field_oa_message_text; ?>
                <?php print $rendered_entity_1; ?>
              </a>
            </div>
            <div id="oa-river-body<?php print $index; ?>"
                 class="accordion-body collapse">
              <div class="accordion-inner">
                <?php print $rendered_entity_2; ?>
              </div>
            </div>
          </div>
        </div>
      <?php else: ?>
        <div>
          <?php print $field_oa_message_text; ?>
          <?php print $rendered_entity_1; ?>
        </div>
      <?php endif; ?>
    <?php else: ?>
      <div>
        <?php print $field_oa_message_text; ?>
      </div>
    <?php endif; ?>
  </div>
</div>
