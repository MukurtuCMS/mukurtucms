<?php
/**
 * @file views-views-json-style-simple.tpl.php
 * Default template for the Views JSON style plugin using the simple format
 *
 * Variables:
 * - $view: The View object.
 * - $rows: Hierachial array of key=>value pairs to convert to JSON
 * - $options: Array of options for this style
 *
 * @ingroup views_templates
 */


if (!empty($options["grouping"][0]["field"])) {
  $group = $options["grouping"][0]["field"];
  // If a label is set for the grouped field, get it and use it instead of the machine name.
  // $options uses the labeled name of the field, so we need to match that for grouping.
  $group_label = $view->query->pager->display->handler->handlers['field'][$group]->options['label'];
  if (strlen($group_label) > 0) {
    $group = $group_label;
  }
  $root = $options["root_object"];
  $top_child = $options["top_child_object"];

  $grouped = array();
  foreach ($rows[$root] as $key => $array) { // Values are numeric
    // Grab the grouping field value from inside the 3rd-level array.
    $groupnode = $array[$top_child][$group];
    foreach ($array[$top_child] as $prop => $value) {
      if ($prop != $group) { // Ignore grouped field
        $grouped[$root][$groupnode][$prop][$key] = $value;
      }
    }
  }
  $rows = $grouped;
}

// Uncomment everything below for prod
$jsonp_prefix = $options['jsonp_prefix'];
if ($view->override_path) {
  // We're inside a live preview where the JSON is pretty-printed.
  $json = _views_json_encode_formatted($rows, $options);
  if ($jsonp_prefix) $json = "$jsonp_prefix($json)";
  print "<code>$json</code>";
}
else {
  $json = _views_json_json_encode($rows, $bitmask);
  if ($options['remove_newlines']) {
     $json = preg_replace(array('/\\\\n/'), '', $json);
  }

  if (isset($_GET[$jsonp_prefix]) && $jsonp_prefix) {
    $json = check_plain($_GET[$jsonp_prefix]) . '(' . $json . ')';
  }

  if ($options['using_views_api_mode']) {
    // We're in Views API mode.
    print $json;
  }
  else {
    // We want to send the JSON as a server response so switch the content
    // type and stop further processing of the page.
    $content_type = ($options['content_type'] == 'default') ? 'application/json' : $options['content_type'];
    drupal_add_http_header("Content-Type", "$content_type; charset=utf-8");
    print $json;
    drupal_page_footer();
    exit;
  }
}
