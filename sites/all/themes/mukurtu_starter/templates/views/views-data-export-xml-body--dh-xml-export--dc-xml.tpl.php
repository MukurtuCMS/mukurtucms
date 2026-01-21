<?php
/**
 * Override the views-data-export-xml-body.tpl.php template for the DC export to add an about attribute to the $item_node opening tag.
 * Note, the views-data-export-xml-body.tpl.php is already patched to work with XML multivals, and that patch is included in this.
 */
?>
<?php foreach ($themed_rows as $count => $row): ?>
  <<?php
  global $base_url;
  $path = url('node/' . $rows[$count]->nid);
  $item_node_attribute = ' rdf:about="' . $base_url . $path . '"';
  print $item_node . $item_node_attribute; ?>>
  <?php foreach ($row as $field => $values): ?>
    <?php foreach ($values as $value): ?>
      <<?php print $xml_tag[$field]; ?>><?php print $value; ?></<?php print $xml_tag[$field]; ?>>
    <?php endforeach; ?>
  <?php endforeach; ?>
  </<?php print $item_node; ?>>
<?php endforeach; ?>
