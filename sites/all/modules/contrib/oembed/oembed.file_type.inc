<?php

/**
 * Implements hook_file_default_types_alter().
 */
function oembed_file_default_types_alter(&$types) {
  $types['image']->mimetypes[] = 'image/oembed';
  $types['image']->streams[] = 'oembed';

  $types['video']->mimetypes[] = 'video/oembed';
  $types['video']->streams[] = 'oembed';

  $types['document']->mimetypes[] = 'text/oembed';
  $types['document']->streams[] = 'oembed';

  $types['audio']->mimetypes[] = 'audio/oembed';
  $types['audio']->streams[] = 'oembed';
}
