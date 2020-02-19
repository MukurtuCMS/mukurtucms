<?php

/**
 * @file
 * ma_collaboration_tools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_collaboration_tools_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_collaboration_tools_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ma_collaboration_tools_node_info() {
  $items = array(
    'calendar' => array(
      'name' => t('Calendar'),
      'base' => 'node_content',
      'description' => t('A collaboration section to show within a Cultural Protocol.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'discussion_space' => array(
      'name' => t('Discussion Space'),
      'base' => 'node_content',
      'description' => t('A collaboration section to show within a Cultural Protocol.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'discussion_topic' => array(
      'name' => t('Discussion Topic'),
      'base' => 'node_content',
      'description' => t('A collaboration discussion topic'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'document_library' => array(
      'name' => t('Document Library'),
      'base' => 'node_content',
      'description' => t('A collaboration section to show within a Cultural Protocol.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'document_page' => array(
      'name' => t('Document Page'),
      'base' => 'node_content',
      'description' => t('An collaboration Document/Wiki page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('A collaboration Event'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'following_notification' => array(
      'name' => t('Following Notification'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'oa_ical_importer' => array(
      'name' => t('iCal Importer'),
      'base' => 'node_content',
      'description' => t('A feeds node to import event from an iCal feed.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function ma_collaboration_tools_default_search_api_index() {
  $items = array();
  $items['document_pages'] = entity_import('search_api_index', '{
    "name" : "Document Pages",
    "machine_name" : "document_pages",
    "description" : "Index of the Document pages (collaborative tools) only.",
    "server" : "search_api_db_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "document_page" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_document_doc_lib_section" : { "type" : "integer", "entity_type" : "node" },
        "field_document_doc_lib_section:nid" : { "type" : "integer" },
        "field_oa_media:file" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_1" : { "type" : "text", "boost" : "5.0" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "string", "boost" : "5.0" },
        "title_az_glossary" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Title as fulltext",
                "type" : "fulltext",
                "separator" : "\\n\\n",
                "fields" : [ "title" ],
                "description" : "A Fulltext aggregation of the following fields: Title."
              }
            }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : { "fields" : { "title" : true }, "exceptions" : "texan=texa" }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
