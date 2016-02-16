<?php
/**
 * @file
 * ma_search_api.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_search_api_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function ma_search_api_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "search_api_db_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_summary" : true,
              "field_collection_credit" : true,
              "field_collection_summary" : true,
              "body:value" : true,
              "field_description:value" : true,
              "field_tk_body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_summary" : true,
              "field_collection_credit" : true,
              "field_collection_summary" : true,
              "body:value" : true,
              "field_description:value" : true,
              "field_tk_body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_summary" : true,
              "field_collection_credit" : true,
              "field_collection_summary" : true,
              "body:value" : true,
              "field_description:value" : true,
              "field_tk_body:value" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_summary" : true,
              "field_collection_credit" : true,
              "field_collection_summary" : true,
              "body:value" : true,
              "field_description:value" : true,
              "field_tk_body:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "field_book_children:author" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "field_book_children:body:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_category" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_book_children:field_category:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_book_children:field_collection_credit" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_collection_summary" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_community_ref" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "node"
        },
        "field_book_children:field_contributor:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_book_children:field_coverage_description:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_creator:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_book_children:field_date" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_description:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_dh_type:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_book_children:field_format:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_identifier" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_language:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_book_children:field_people" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_book_children:field_source" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_subject:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_book_children:field_summary" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_tags" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_book_children:field_tags:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_book_children:field_tk_body:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:field_transcription" : { "type" : "list\\u003Ctext\\u003E" },
        "field_book_children:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_category:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_collection" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_collection_credit" : { "type" : "text" },
        "field_collection_summary" : { "type" : "text" },
        "field_community_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_contributor:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_coverage:geo_type" : { "type" : "string" },
        "field_coverage_description:value" : { "type" : "text" },
        "field_creator:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_date" : { "type" : "text" },
        "field_description:value" : { "type" : "text" },
        "field_dh_type:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_digital_heritage_count" : { "type" : "integer" },
        "field_digital_heritage_items" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_format:name" : { "type" : "text" },
        "field_identifier" : { "type" : "text" },
        "field_language:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_media_asset:type" : { "type" : "list\\u003Cstring\\u003E" },
        "field_people" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_people:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_source" : { "type" : "text" },
        "field_subject:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_summary" : { "type" : "text" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_tk_body:value" : { "type" : "text" },
        "field_transcription" : { "type" : "text" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function ma_search_api_default_search_api_server() {
  $items = array();
  $items['search_api_db_server'] = entity_import('search_api_server', '{
    "name" : "Search API DB Server",
    "machine_name" : "search_api_db_server",
    "description" : "Search server provisioned by the Search API Database Search module, which uses the normal database for the index. Can be replaced wholesale by Solr when the time comes.",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 0,
      "indexes" : { "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index",
            "column" : "promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "comment_count" : {
            "table" : "search_api_db_default_node_index",
            "column" : "comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_media_asset:type" : {
            "table" : "search_api_db_default_node_index_field_media_asset_type",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_summary" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_description:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_tk_body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_community_ref" : {
            "table" : "search_api_db_default_node_index_field_community_ref",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_collection_credit" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_digital_heritage_items" : {
            "table" : "search_api_db_default_node_index_field_digital_heritage_items",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_collection_summary" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_digital_heritage_count" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_digital_heritage_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_collection" : {
            "table" : "search_api_db_default_node_index_field_collection",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_default_node_index",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_default_node_index_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "nid" : {
            "table" : "search_api_db_default_node_index",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_date" : {
            "table" : "search_api_db_default_node_index_text",
            "column" : "field_date",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_identifier" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0",
            "column" : "field_identifier"
          },
          "field_source" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_dh_type:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_creator:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_format:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_subject:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_tags:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_category:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_contributor:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_category" : {
            "table" : "search_api_db_default_node_index_field_category",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_tags" : {
            "table" : "search_api_db_default_node_index_field_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_language:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_coverage_description:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_transcription" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_book_children:title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:author" : {
            "table" : "search_api_db_default_node_index_field_book_children_author",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_community_ref" : {
            "table" : "search_api_db_default_node_index_field_book_children_field_com",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_summary" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_category" : {
            "table" : "search_api_db_default_node_index_field_book_children_field_cat",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_date" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_identifier" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_source" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_tags" : {
            "table" : "search_api_db_default_node_index_field_book_children_field_tag",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_transcription" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_collection_credit" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_collection_summary" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_dh_type:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_category:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_contributor:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_coverage_description:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_creator:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_description:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_format:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_language:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_subject:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_tags:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_tk_body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_coverage:geo_type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_coverage_geo_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_people" : {
            "table" : "search_api_db_default_node_index_field_people",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_people:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_book_children:field_people" : {
            "table" : "search_api_db_default_node_index_field_book_children_field_peo",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
