<?php
/**
 * Override the views-data-export-xml-body.tpl.php template for the MODS export to show nested attributes.
 * Note, the views-data-export-xml-body.tpl.php is already patched to work with XML multivals, and that patch is effectively included in this.
 */
$indentation_size = 2;
foreach ($themed_rows as $count => $row) {
  print str_repeat(' ', $indentation_size) . "<" . $item_node . ">";
  foreach ($row as $field => $values) {
    foreach ($values as $value) {
      $xml_tags_nested = explode('-', $xml_tag[$field]);
      $xml_tags_nested_count = count($xml_tags_nested);
      if ($xml_tags_nested_count > 1) {
        $identations = [];
        foreach ($xml_tags_nested as $i => $xml_tag_nested_individual) {
          if ($i < $xml_tags_nested_count) {
            $identations[$xml_tag_nested_individual] = $indentation_size * ($i+1) + $indentation_size;
            print "\n" . str_repeat(' ', $identations[$xml_tag_nested_individual]);
          }
          print "<" . $xml_tag_nested_individual . ">";
        }
        print $value;
        foreach (array_reverse($xml_tags_nested) as $i => $xml_tag_nested_individual) {
          if ($i > 0) {
            print "\n" . str_repeat(' ', $identations[$xml_tag_nested_individual]);
          }
          print "</" . $xml_tag_nested_individual . ">";
        }
      }
      else {
        print "\n" . str_repeat(' ', $indentation_size + $indentation_size) . "<" . $xml_tag[$field] . ">" . $value . "</" . $xml_tag[$field] . ">";
      }
    }
  }
  print "\n" . str_repeat(' ', $indentation_size) . "</" . $item_node . ">\n";
}
