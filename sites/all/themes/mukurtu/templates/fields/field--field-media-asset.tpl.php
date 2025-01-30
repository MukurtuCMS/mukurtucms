<?php

/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used by Drupal core, which uses theme functions instead for
 * performance reasons. The markup is the same, though, so if you want to use
 * template files rather than functions to extend field theming, copy this to
 * your custom theme. See theme_field() for a discussion of performance.
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
?>
<?php
    $id="mukurtu-carousel";
    if(isset($element['#object']->nid)) {
       $id .= '-' . $element['#object']->nid;
    }
    $carousel_class = "";
    if(count($items) > 1) {
        $carousel_class = "slick-carousel-single slick-carousel";
    }
?>
<?php if (FALSE): ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div id="<?php print $id; ?>" class="<?php print $carousel_class; ?> field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="<?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>>
         <?php print render($item); ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
<?php endif; ?>





<?php
    $id="mukurtu-carousel";
    if(isset($element['#object']->nid)) {
       $id .= '-' . $element['#object']->nid;
    }
    $carousel_class = "";
    if(count($items) > 1) {
        $carousel_class = "slick-carousel-slider-for slick-carousel";
    }
?>
<?php if (count($items) > 1): ?>
<div class="slick-carousel-slider-nav slick-carousel">
    <?php foreach ($items as $delta => $item): ?>
      <div class="<?php print $delta % 2 ? 'odd' : 'even'; ?>">
         <?php
             $sid = $element['#object']->field_media_asset[LANGUAGE_NONE][$delta]['sid'];
//             $atom = scald_atom_load($sid);
//dpm($atom);
             $rendered_thumnail = scald_render($sid, 'mukurtu_carousel_thumbnail');
             if($rendered_thumnail) {
                 print $rendered_thumnail;
             }
//print $sid;
         ?>
      </div>
    <?php endforeach; ?>
</div>
<?php endif; ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div id="<?php print $id; ?>" class="<?php print $carousel_class; ?> field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="<?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>>
         <?php print render($item); ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>

