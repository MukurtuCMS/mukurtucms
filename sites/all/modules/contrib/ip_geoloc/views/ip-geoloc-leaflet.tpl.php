<?php
/**
 * @file
 * ip-geoloc-leaflet.tpl.php
 *
 * This template is used to output a placeholder for a map with location
 * markers taken from a View.
 *
 * Variables available:
 * - $map_id
 * - $height
 * - $view (to add title?)
 */

  $marker_set = ip_geoloc_marker_directory();
  $marker_set = drupal_substr($marker_set, strrpos($marker_set, '/') + 1);
  $height = empty($height) ? '300px' : (is_numeric($height) ? $height . 'px' : trim($height));
  $style = (drupal_substr($height, 0, 6) == '<none>') ? '' : ' style="height:' . check_plain($height) .'"';
?>
<div class="ip-geoloc-map leaflet-view <?php echo $marker_set; ?>">
  <div id="<?php echo $map_id; ?>" <?php echo $style; ?>></div>
</div>
