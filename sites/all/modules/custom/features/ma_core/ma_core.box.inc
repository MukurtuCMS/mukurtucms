<?php

/**
 * @file
 * ma_core.box.inc
 */

/**
 * Implements hook_default_box().
 */
function ma_core_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ma_add_content';
  $box->plugin_key = 'simple';
  $box->title = 'Add Content';
  $box->description = 'Add Content Instructions';
  $box->options = array(
    'body' => array(
      'value' => '<p><img style="float: left; margin-left: 10px; margin-right: 10px;" src="http://www.mukurtu.org/wiki/images/a/a7/Add.png" alt="" width="50" height="50"><span class="Apple-style-span" style="color: #000000; font-family: georgia, palatino; line-height: 19px; white-space: pre-wrap;">You can add content to share with all archive users or with specific groups. <a title="Wiki: Mukurtu User Manual" href="http://www.mukurtu.org/wiki/Manual:Supported_formats" target="_blank">Supported content types</a> are images, videos, sounds, and documents. </span><span class="Apple-style-span" style="color: #000000; font-family: georgia, palatino; line-height: 19px; white-space: pre-wrap;"><a title="Wiki: Mukurtu User Manual" href="http://www.mukurtu.org/wiki/Manual:Add_content" target="_blank">Follow our wiki instructions</a></span> if you need help adding content.</p>',
      'format' => 'full_html',
    ),
  );
  $export['ma_add_content'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ma_cultural_protocols';
  $box->plugin_key = 'simple';
  $box->title = 'Cultural Protocols in Mukurtu Core';
  $box->description = 'Cultural Protocols';
  $box->options = array(
    'body' => array(
      'value' => '<div style="background-image: initial; background-attachment: initial; background-origin: initial; background-clip: initial; background-color: #ffffff; height: 100%; word-wrap: break-word; border-style: initial; border-color: initial; outline-width: 0px; outline-style: initial; outline-color: initial; border-width: 0px; padding: 0px; margin: 0px;"><p><span class="Apple-style-span" style="font-size: 87.5%; line-height: 1.5;"><img style="float: left; margin-left: 10px; margin-right: 10px;" src="http://www.mukurtu.org/wiki/images/e/ec/Cp.png" alt="" width="50" height="50"></span><span style="color: #000000; font-family: georgia, palatino;"><span class="Apple-style-span" style="line-height: 19px; white-space: pre-wrap;">Adding cultural protocols to your content allows you to decide how to define and circulate content among your community memebrs. Your Mukurtu administartor has already set up a dropdown menu with a list of protocols to choose from. Read more about cultural protocols </span><span class="Apple-style-span" style="font-size: 87.5%; line-height: 19px; white-space: pre-wrap;"> </span></span><span class="Apple-style-span" style="color: #000000; font-family: georgia, palatino; line-height: 19px; white-space: pre-wrap;"><a title="Wiki: Mukurtu User Manual" href="http://www.mukurtu.org/wiki/Manual:Add_cultural_protocols" target="_blank">on our wiki page</a>.</span></p></div>',
      'format' => 'full_html',
    ),
  );
  $export['ma_cultural_protocols'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ma_dublin_core';
  $box->plugin_key = 'simple';
  $box->title = 'Dublin Core';
  $box->description = 'Dublin Core';
  $box->options = array(
    'body' => array(
      'value' => '<div style="background-image: initial; background-attachment: initial; background-origin: initial; background-clip: initial; background-color: #ffffff; height: 100%; word-wrap: break-word; border-style: initial; border-color: initial; outline-width: 0px; outline-style: initial; outline-color: initial; border-width: 0px; padding: 0px; margin: 0px;"><p><span class="Apple-style-span" style="font-size: 87.5%; line-height: 1.5;"><img style="float: left; margin-left: 10px; margin-right: 10px;" src="http://www.mukurtu.org/wiki/images/d/d0/Dc.png" alt="" width="50" height="50"></span><span><span style="color: #000000; font-family: georgia, palatino;"><span class="Apple-style-span" style="line-height: 19px; white-space: pre-wrap;">Mukurtu comes standard with Simple Dublin Core elements. Find more information about using Dublin Core standard metadata formats in Mukurtu on our </span></span> </span><span class="Apple-style-span" style="color: #000000; font-family: georgia, palatino; line-height: 19px; white-space: pre-wrap;"><a title="Wiki: Mukurtu User Manual" href="http://www.mukurtu.org/wiki/Manual:Dublin_Core" target="_blank">wiki page</a>.</span></p></div>',
      'format' => 'full_html',
    ),
  );
  $export['ma_dublin_core'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ma_traditional_knowledge';
  $box->plugin_key = 'simple';
  $box->title = 'Traditional Knowledge';
  $box->description = 'Traditional Knowledge';
  $box->options = array(
    'body' => array(
      'value' => '<p><img style="float: left; margin-left: 10px; margin-right: 10px;" src="http://www.mukurtu.org/wiki/images/2/27/Tk.png" alt="" width="52" height="52"><span class="Apple-style-span" style="color: #000000; font-family: georgia, palatino; line-height: 19px; white-space: pre-wrap;"></span></p><p>You can add traditional knowledge to your content as you see fit. This field is an open field to provide you with maximum flexibility to express your knowledge in the most appropriate form. <a href="http://www.mukurtu.org/wiki/Manual:Add_traditional_knowledge">Go to wiki page.</a></p>',
      'format' => 'full_html',
    ),
  );
  $export['ma_traditional_knowledge'] = $box;

  return $export;
}
