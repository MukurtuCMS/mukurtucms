<?php

/**
 * @file
 * Default display configuration for the default file types.
 */

/**
 * Implements hook_file_default_displays().
 */
function oembed_file_default_displays() {
  $file_displays = array();

  // Audio.
  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__default__oembed';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => '',
  );
  $file_displays['audio__default__oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'audio__preview__oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '100',
    'height' => '100',
  );
  $file_displays['audio__preview__oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__oembed';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '280',
    'height' => '170',
    'wmode' => '',
  );
  $file_displays['audio__teaser__oembed'] = $file_display;

  // Document.
  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__default__oembed';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => '',
  );
  $file_displays['document__default__oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__preview__oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '100',
    'height' => '100',
  );
  $file_displays['document__preview__oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__teaser__oembed';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '280',
    'height' => '170',
    'wmode' => '',
  );
  $file_displays['document__teaser__oembed'] = $file_display;

  // Image.
  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__oembed';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => '',
  );
  $file_displays['image__default__oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '100',
    'height' => '100',
  );
  $file_displays['image__preview__oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__oembed';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '280',
    'height' => '170',
    'wmode' => '',
  );
  $file_displays['image__teaser__oembed'] = $file_display;

  // Video.
  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__oembed';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '560',
    'height' => '340',
    'wmode' => '',
  );
  $file_displays['video__default__oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__preview__oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '100',
    'height' => '100',
  );
  $file_displays['video__preview__oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__teaser__oembed';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '280',
    'height' => '170',
    'wmode' => '',
  );
  $file_displays['video__teaser__oembed'] = $file_display;

  return $file_displays;
}
