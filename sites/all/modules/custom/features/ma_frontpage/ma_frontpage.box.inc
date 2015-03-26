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
  $box->delta = 'ma_site_footer';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Custom Site Footer';
  $box->options = array(
    'body' => array(
      'value' => '<p>Edit Site Footer here.</p>',
      'format' => 'full_html',
    ),
  );
  $export['ma_site_footer'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ma_site_header';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Custom Site Header';
  $box->options = array(
    'body' => array(
      'value' => '<p><img src="sites/all/themes/mukurtu_starter/mukurtu_default_banner.jpg" alt="" width="1140" /></p>

<h1> Welcome to Mukurtu CMS </h1>
<p> Mukurtu (MOOK-oo-too) is a grassroots project aiming to empower communities to manage, share and exchange their digital heritage in culturally relevant and ethically-minded ways. We are committed to maintaining an open, community-driven approach to Mukurtu’s continued development. Our first priority is to help build a platform that fosters relationships of respect and trust. <a href="about"> Learn More >> </a></p>',
      'format' => 'ds_code',
    ),
    'additional_classes' => '',
  );
  $export['ma_site_header'] = $box;

  return $export;
}
