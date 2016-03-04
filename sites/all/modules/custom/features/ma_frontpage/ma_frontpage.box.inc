<?php
/**
 * @file
 * ma_frontpage.box.inc
 */

/**
 * Implements hook_default_box().
 */
function ma_frontpage_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ma_site_header';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Custom Site Header';
  $box->options = array(
    'body' => array(
      'value' => '<h1><strong>Plateau Peoples\'</strong><br/>Web Portal</h1>
<p>This portal is a gateway to the cultural materials of Plateau peoples that are held in Washington State University\'s Libraries, Manuscripts, Archives and Special Collections (MASC), the Museum of Anthropology and by national donors. The collections represented here have been chosen and curated by tribal consultants working in cooperation with University and Museum staff. <a href="about" title="Learn More">More Details &raquo;</a></p>',
      'format' => 'ds_code',
    ),
    'additional_classes' => '',
  );
  $export['ma_site_header'] = $box;

  return $export;
}
