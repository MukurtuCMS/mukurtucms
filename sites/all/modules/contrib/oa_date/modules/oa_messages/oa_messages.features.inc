<?php
/**
 * @file
 * oa_messages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_messages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function oa_messages_default_message_type() {
  $items = array();
  $items['oa_comment'] = entity_import('message_type', '{
    "name" : "oa_comment",
    "description" : "Comment",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[[message:field-oa-message-space]] [message:field-oa-node-ref:title]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[[message:field-oa-message-space]] [message:field-oa-node-ref:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Ch3\\u003E@{message:user:name} replied to \\u003Ca href=\\u0022[message:field-oa-comment-ref:url]\\u0022\\u003E[message:field-oa-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\r\\n[message:field-oa-message-text:value] [message:field-oa-comment-ref:comment-body:value]",
          "format" : "full_html",
          "safe_value" : "\\u003Ch3\\u003E@{message:user:name} replied to \\u003Ca href=\\u0022[message:field-oa-comment-ref:url]\\u0022\\u003E[message:field-oa-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\n[message:field-oa-message-text:value] [message:field-oa-comment-ref:comment-body:value]"
        },
        {
          "value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022 class=\\u0022oa-userlink\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E replied to \\u003Ca href=\\u0022[message:field-oa-comment-ref:url]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022 class=\\u0022oa-userlink\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E replied to \\u003Ca href=\\u0022[message:field-oa-comment-ref:url]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E"
        },
        {
          "value" : "[message:field-oa-message-text:value] [message:field-oa-node-ref:title]",
          "format" : "full_html",
          "safe_value" : "[message:field-oa-message-text:value] [message:field-oa-node-ref:title]"
        },
        {
          "value" : "[message:field-oa-comment-ref:comment-body:value]",
          "format" : "full_html",
          "safe_value" : "[message:field-oa-comment-ref:comment-body:value]"
        }
      ]
    }
  }');
  $items['oa_create'] = entity_import('message_type', '{
    "name" : "oa_create",
    "description" : "New Content",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" },
      "token options" : { "clear" : 1 }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[[message:field-oa-message-space]] [message:field-oa-node-ref:title]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[[message:field-oa-message-space]] [message:field-oa-node-ref:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Ch3\\u003E@{message:user:name} created \\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003E[message:field-oa-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\r\\n\\u003Cp\\u003E[message:field-oa-message-text:value]\\u0026nbsp;[message:field-oa-node-ref:body]\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ch3\\u003E@{message:user:name} created \\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003E[message:field-oa-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\n\\u003Cp\\u003E[message:field-oa-message-text:value]\\u0026nbsp;[message:field-oa-node-ref:body]\\u003C\\/p\\u003E"
        },
        {
          "value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022 class=\\u0022oa-userlink\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022 class=\\u0022oa-userlink\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E"
        },
        {
          "value" : "[message:field-oa-message-text:value] [message:field-oa-node-ref:body]",
          "format" : "full_html",
          "safe_value" : "[message:field-oa-message-text:value] [message:field-oa-node-ref:body]"
        },
        {
          "value" : "[message:field-oa-node-ref:body]",
          "format" : "full_html",
          "safe_value" : "[message:field-oa-node-ref:body]"
        }
      ]
    }
  }');
  $items['oa_delete'] = entity_import('message_type', '{
    "name" : "oa_delete",
    "description" : "Deleted",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" },
      "token options" : { "clear" : 1 }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[[message:field-oa-message-space]] [message:field-deleted-title]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[[message:field-oa-message-space]] [message:field-deleted-title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "@{message:user:name} deleted [message:field-deleted-title]",
          "format" : "full_html",
          "safe_value" : "@{message:user:name} deleted [message:field-deleted-title]"
        },
        {
          "value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E deleted \\u003Cstrong\\u003E[message:field-deleted-title]\\u003C\\/strong\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E deleted \\u003Cstrong\\u003E[message:field-deleted-title]\\u003C\\/strong\\u003E"
        },
        {
          "value" : "[message:field-deleted-summary:value]",
          "format" : "panopoly_html_text",
          "safe_value" : "\\u003Cp\\u003E[message:field-deleted-summary:value]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field-deleted-summary:value]",
          "format" : "panopoly_html_text",
          "safe_value" : "\\u003Cp\\u003E[message:field-deleted-summary:value]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['oa_member'] = entity_import('message_type', '{
    "name" : "oa_member",
    "description" : "Membership",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" },
      "token options" : { "clear" : 1 }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[message:field-oa-message-space:title] : @{message:user:name} updated members of Space",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[message:field-oa-message-space:title] : @{message:user:name} updated members of Space\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field-oa-message-space:title] : [message:field-oa-message-text:value]",
          "format" : "full_html",
          "safe_value" : "[message:field-oa-message-space:title] : [message:field-oa-message-text:value]"
        },
        {
          "value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E updated Space : \\u003Ca href=\\u0022[site:url]node\\/[message:field-oa-message-space:nid]\\u0022\\u003E[message:field-oa-message-space:title]\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E updated Space : \\u003Ca href=\\u0022[site:url]node\\/[message:field-oa-message-space:nid]\\u0022\\u003E[message:field-oa-message-space:title]\\u003C\\/a\\u003E"
        }
      ]
    }
  }');
  $items['oa_update'] = entity_import('message_type', '{
    "name" : "oa_update",
    "description" : "Updated",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" },
      "token options" : { "clear" : 1 }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[[message:field-oa-message-space]] [message:field-oa-node-ref:title]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[[message:field-oa-message-space]] [message:field-oa-node-ref:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Ch3\\u003E@{message:user:name} updated \\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003E[message:field-oa-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\r\\n\\u003Cp\\u003E[message:field-oa-message-text:value]\\u0026nbsp;[message:field-oa-node-ref:oa-log]\\u003C\\/p\\u003E\\u003Cp\\u003E!{message:field-oa-node-ref:oa-diff}\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ch3\\u003E@{message:user:name} updated \\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003E[message:field-oa-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\n\\u003Cp\\u003E[message:field-oa-message-text:value]\\u0026nbsp;[message:field-oa-node-ref:oa-log]\\u003C\\/p\\u003E\\u003Cp\\u003E!{message:field-oa-node-ref:oa-diff}\\u003C\\/p\\u003E"
        },
        {
          "value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022 class=\\u0022oa-userlink\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E updated \\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022 class=\\u0022oa-userlink\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E updated \\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E"
        },
        {
          "value" : "@{message:field-oa-node-ref:log}",
          "format" : "full_html",
          "safe_value" : "@{message:field-oa-node-ref:log}"
        },
        {
          "value" : "!{message:field-oa-node-ref:oa-diff}",
          "format" : "full_html",
          "safe_value" : "!{message:field-oa-node-ref:oa-diff}"
        }
      ]
    }
  }');
  return $items;
}
