<?php
/**
 * @file
 * ma_importexport_media.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ma_importexport_media_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'media_feed_importer';
  $feeds_importer->config = array(
    'name' => 'Import Media Metadata: Images',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFileProcessor',
      'config' => array(
        'file_type' => 'image',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'filename',
            'target' => 'filename',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'field_media_title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'description',
            'target' => 'field_media_description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'caption',
            'target' => 'field_caption',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'username',
            'target' => 'user_name',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'headline',
            'target' => 'field_iptc_headline',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'date_time',
            'target' => 'field_exif_datetime',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'tags',
            'target' => 'field_tags',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['media_feed_importer'] = $feeds_importer;

  return $export;
}
