<?php
/**
 * @file
 * oa_wysiwyg.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_wysiwyg_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: filter
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_border-1|border"] = 'border';
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_border-2|border-color"] = 'border-color';
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_border-2|border-style"] = 'border-style';
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_color|background-color"] = 'background-color';
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_list|list-style-type"] = 'list-style-type';
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|valid_elements"] = 'a[!href|target<_blank|title|style|class],
              div[style|class|align<center?justify?left?right],
              br,em,i,strong,cite,code,blockquote,
              ul[style|list-style-type],ol[style|list-style-type],li,dl,dt,dd,
              span[style],p[style|class],
              h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
              img[!src|title|alt|style|width|height|class|hspace|vspace],
              @[style|class],
              table[style|class],th[style|class],tr[style|class],td[style|class],tbody[style|class]';

  // Exported overrides for: wysiwyg
  $overrides["wysiwyg.panopoly_wysiwyg_text.settings|buttons|advlist"] = array(
    'advlist' => 1,
  );
  $overrides["wysiwyg.panopoly_wysiwyg_text.settings|buttons|table"] = array(
    'tablecontrols' => 1,
  );

 return $overrides;
}
