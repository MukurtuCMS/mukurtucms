<?php

/**
 * @file
 * ma_search_api.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_search_api_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
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
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_aggregation_1" : {
                "name" : "Translation Sort",
                "type" : "first",
                "separator" : "\\n\\n",
                "fields" : [ "field_word_entry:field_translation" ],
                "description" : "A First aggregation of the following fields: Word Entry \\u00bb Translation."
              },
              "search_api_aggregation_2" : {
                "name" : "Node Title",
                "type" : "first",
                "separator" : "\\n\\n",
                "fields" : [ "title" ],
                "description" : "A First aggregation of the following fields: Title."
              },
              "search_api_aggregation_3" : {
                "name" : "Person Record",
                "type" : "fulltext",
                "separator" : "\\n\\n",
                "fields" : [
                  "field_people",
                  "field_mukurtu_terms:field_mukurtu_records:field_people"
                ],
                "description" : "A Fulltext aggregation of the following fields: People, Mukurtu Terms \\u00bb Records \\u00bb People."
              },
              "search_api_aggregation_4" : {
                "name" : "Child Node Score",
                "type" : "count",
                "separator" : "\\n\\n",
                "fields" : [ "field_book_parent", "field_community_record_parent" ],
                "description" : "A Count aggregation of the following fields: Book Parent, Community Record Parent."
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
          "settings" : { "fields" : {
              "title" : true,
              "field_summary" : true,
              "field_collection_credit" : true,
              "field_collection_summary" : true,
              "search_api_aggregation_1" : true,
              "body:value" : true,
              "field_description:value" : true,
              "field_tk_body:value" : true,
              "field_word_entry:field_source" : true,
              "field_word_entry:field_definition" : true,
              "field_word_entry:field_sample_sentence" : true,
              "field_word_entry:field_translation" : true
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
            "spaces" : "[\\\\p{P}|\\\\p{C}|\\\\p{Z}|\\\\p{S}]",
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
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_summary" : true,
              "field_transcription" : true,
              "field_date" : true,
              "field_identifier" : true,
              "field_source" : true,
              "field_collection_credit" : true,
              "field_collection_summary" : true,
              "body:value" : true,
              "field_people:name" : true,
              "field_contributor:name" : true,
              "field_category:name" : true,
              "field_tags:name" : true,
              "field_description:value" : true,
              "field_book_children:title" : true,
              "field_book_children:field_summary" : true,
              "field_book_children:field_transcription" : true,
              "field_book_children:field_date" : true,
              "field_book_children:field_identifier" : true,
              "field_book_children:field_source" : true,
              "field_book_children:field_collection_credit" : true,
              "field_book_children:field_collection_summary" : true,
              "field_dh_type:name" : true,
              "field_coverage_description:value" : true,
              "field_creator:name" : true,
              "field_format:name" : true,
              "field_language:name" : true,
              "field_subject:name" : true,
              "field_tk_body:value" : true,
              "field_word_entry:field_source" : true,
              "field_word_entry:field_alternate_spelling" : true,
              "field_word_entry:field_definition" : true,
              "field_word_entry:field_sample_sentence" : true,
              "field_word_entry:field_translation" : true,
              "field_book_children:body:value" : true,
              "field_book_children:field_contributor:name" : true,
              "field_book_children:field_category:name" : true,
              "field_book_children:field_tags:name" : true,
              "field_book_children:field_description:value" : true,
              "field_book_children:field_dh_type:name" : true,
              "field_book_children:field_coverage_description:value" : true,
              "field_book_children:field_creator:name" : true,
              "field_book_children:field_format:name" : true,
              "field_book_children:field_language:name" : true,
              "field_book_children:field_subject:name" : true,
              "field_book_children:field_tk_body:value" : true,
              "field_word_entry:field_pronunciation:value" : true
            },
            "exceptions" : "texan=texa"
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
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "dh_original_year" : { "type" : "integer" },
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
        "field_book_children:field_format:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
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
        "field_collections_child_coll" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_collections_parent_coll" : { "type" : "integer", "entity_type" : "node" },
        "field_community_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_contributor:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_coverage:geo_type" : { "type" : "string" },
        "field_coverage_description:value" : { "type" : "text" },
        "field_creator:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_date" : { "type" : "text" },
        "field_description:value" : { "type" : "text" },
        "field_dh_type:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_dictionary_word_language" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_dictionary_word_related_dh" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_digital_heritage_count" : { "type" : "integer" },
        "field_format:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_identifier" : { "type" : "text" },
        "field_language:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lesson_days:field_day" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lesson_days:field_elaborate:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lesson_days:field_elders:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lesson_days:field_engage:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lesson_days:field_explain:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lesson_days:field_explore_environment:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lesson_days:field_related_content" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "node"
        },
        "field_lesson_micro_tasks:field_day" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lesson_micro_tasks:field_key_student_outcomes:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lesson_micro_tasks:field_related_content" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "node"
        },
        "field_lesson_micro_tasks:field_task:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_lesson_micro_tasks:field_word_list" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "node"
        },
        "field_lesson_resources:value" : { "type" : "text" },
        "field_lesson_tech_integration:value" : { "type" : "text" },
        "field_media_asset:type" : { "type" : "list\\u003Cstring\\u003E" },
        "field_mukurtu_terms" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_mukurtu_terms:field_mukurtu_records" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "node"
        },
        "field_mukurtu_terms:field_mukurtu_records:field_people" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_mukurtu_terms:field_mukurtu_records:field_people:name" : { "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E" },
        "field_mukurtu_terms:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_original_date:timestamp" : { "type" : "integer" },
        "field_people" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_people:field_mukurtu_records" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "node"
        },
        "field_people:field_mukurtu_records:field_people" : {
          "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_people:field_mukurtu_records:field_people:name" : { "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E" },
        "field_people:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_related_content" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_related_dictionary_words" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_source" : { "type" : "text" },
        "field_subject:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_summary" : { "type" : "text" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_tk_body:value" : { "type" : "text" },
        "field_transcription" : { "type" : "text" },
        "field_unit_assessments" : { "type" : "text" },
        "field_unit_class_period_length" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_unit_conceptual" : { "type" : "text" },
        "field_unit_grade_level" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_unit_language_learning" : { "type" : "text" },
        "field_unit_lessons" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_unit_nature_of_science" : { "type" : "text" },
        "field_unit_overarching" : { "type" : "text" },
        "field_unit_subject" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_unit_teacher" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_unit_technical" : { "type" : "text" },
        "field_unit_unit_length" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_unit_week_of" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_word_entry:field_alternate_spelling" : { "type" : "list\\u003Ctext\\u003E" },
        "field_word_entry:field_definition" : { "type" : "list\\u003Ctext\\u003E" },
        "field_word_entry:field_part_of_speech" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_word_entry:field_pronunciation:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_word_entry:field_sample_sentence" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E", "boost" : "0.8" },
        "field_word_entry:field_source" : { "type" : "list\\u003Ctext\\u003E" },
        "field_word_entry:field_translation" : { "type" : "list\\u003Ctext\\u003E" },
        "field_word_list" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_words" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_1" : { "type" : "string" },
        "search_api_aggregation_2" : { "type" : "string" },
        "search_api_aggregation_4" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "title_az_glossary" : { "type" : "string" },
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
            "type" : "list\\u003Ctext\\u003E",
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
            "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E",
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
          },
          "field_dictionary_word_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_dictionary_word_language",
            "type" : "integer",
            "boost" : "1.0"
          },
          "title_az_glossary" : {
            "table" : "search_api_db_default_node_index",
            "column" : "title_az_glossary",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_dictionary_word_related_dh" : {
            "table" : "search_api_db_default_node_index_field_dictionary_word_related",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_word_entry:field_source" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_word_entry:field_definition" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_word_entry:field_translation" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0",
            "column" : "value"
          },
          "field_word_entry:field_part_of_speech" : {
            "table" : "search_api_db_default_node_index_field_word_entry_field_part_o",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_word_entry:field_sample_sentence" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E",
            "boost" : "0.8"
          },
          "field_words" : {
            "table" : "search_api_db_default_node_index_field_words",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_word_list" : {
            "table" : "search_api_db_default_node_index_field_word_list",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_aggregation_1" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_aggregation_1",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_word_entry:field_pronunciation:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_related_dictionary_words" : {
            "table" : "search_api_db_default_node_index_field_related_dictionary_word",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_word_entry:field_alternate_spelling" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "search_api_aggregation_2" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_aggregation_2",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_original_date:timestamp" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_original_date_timestamp",
            "type" : "integer",
            "boost" : "1.0"
          },
          "dh_original_year" : {
            "table" : "search_api_db_default_node_index",
            "column" : "dh_original_year",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_collections_child_coll" : {
            "table" : "search_api_db_default_node_index_field_collections_child_coll",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_collections_parent_coll" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_collections_parent_coll",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_mukurtu_terms" : {
            "table" : "search_api_db_default_node_index_field_mukurtu_terms",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_people:field_mukurtu_records" : {
            "table" : "search_api_db_default_node_index_field_people_field_mukurtu_re",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_people:field_mukurtu_records:field_people:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_people:field_mukurtu_records:field_people" : {
            "table" : "search_api_db_default_node_index_field_people_field_mukurtu__1",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_mukurtu_terms:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_mukurtu_terms:field_mukurtu_records" : {
            "table" : "search_api_db_default_node_index_field_mukurtu_terms_field_muk",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_mukurtu_terms:field_mukurtu_records:field_people" : {
            "table" : "search_api_db_default_node_index_field_mukurtu_terms_field_m_1",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Clist\\u003Cinteger\\u003E\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_mukurtu_terms:field_mukurtu_records:field_people:name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Clist\\u003Clist\\u003Ctext\\u003E\\u003E\\u003E",
            "boost" : "1.0"
          },
          "search_api_aggregation_4" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_aggregation_4",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_unit_teacher" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_unit_teacher",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_unit_subject" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_unit_subject",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_unit_grade_level" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_unit_grade_level",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_unit_unit_length" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_unit_unit_length",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_unit_class_period_length" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_unit_class_period_length",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_unit_week_of" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_unit_week_of",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_unit_overarching" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_unit_conceptual" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_unit_nature_of_science" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_unit_language_learning" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_unit_technical" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_unit_assessments" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_unit_lessons" : {
            "table" : "search_api_db_default_node_index_field_unit_lessons",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_micro_tasks:field_word_list" : {
            "table" : "search_api_db_default_node_index_field_lesson_micro_tasks_fi_1",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_days:field_day" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_tech_integration:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_related_content" : {
            "table" : "search_api_db_default_node_index_field_related_content",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_days:field_related_content" : {
            "table" : "search_api_db_default_node_index_field_lesson_days_field_relat",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_micro_tasks:field_related_content" : {
            "table" : "search_api_db_default_node_index_field_lesson_micro_tasks_fiel",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_micro_tasks:field_day" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_days:field_elaborate:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_days:field_elders:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_days:field_engage:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_days:field_explain:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_days:field_explore_environment:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_micro_tasks:field_key_student_outcomes:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_micro_tasks:field_task:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_lesson_resources:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
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
