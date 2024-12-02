<?php
/**
 * @file
 * oa_wysiwyg.features.inc
 */

/**
 * Implements hook_filter_default_formats_alter().
 */
function oa_wysiwyg_filter_default_formats_alter(&$data) {
  if (isset($data['panopoly_wysiwyg_text'])) {
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_border-1']['border'] = 'border'; /* WAS: 0 */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_border-2']['border-color'] = 'border-color'; /* WAS: 0 */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_border-2']['border-style'] = 'border-style'; /* WAS: 0 */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_color']['background-color'] = 'background-color'; /* WAS: 0 */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_list']['list-style-type'] = 'list-style-type'; /* WAS: 0 */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['valid_elements'] = 'a[!href|target<_blank|title|style|class],
                div[style|class|align<center?justify?left?right],
                br,em,i,strong,cite,code,blockquote,
                ul[style|list-style-type],ol[style|list-style-type],li,dl,dt,dd,
                span[style],p[style|class],
                h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
                img[!src|title|alt|style|width|height|class|hspace|vspace],
                @[style|class],
                table[style|class],th[style|class],tr[style|class],td[style|class],tbody[style|class]'; /* WAS: '@[style|class],
    a[!href|target<_blank|title],
    div[align<center?justify?left?right],
    br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,
    span,p,
    h1,h2,h3,h4,h5,h6,
    img[!src|title|alt|width|height|hspace|vspace],' */
  }
}

/**
 * Implements hook_wysiwyg_default_profiles_alter().
 */
function oa_wysiwyg_wysiwyg_default_profiles_alter(&$data) {
  if (isset($data['panopoly_wysiwyg_text'])) {
    $data['panopoly_wysiwyg_text']['settings']['buttons']['advlist'] = array(
      'advlist' => 1,
    ); /* WAS: '' */
    $data['panopoly_wysiwyg_text']['settings']['buttons']['table'] = array(
      'tablecontrols' => 1,
    ); /* WAS: '' */
  }
}
