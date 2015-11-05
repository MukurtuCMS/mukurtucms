<?php

/**
 * @file
 * API documentation for Leaflet More Maps module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Implements hook_leaflet_map_info().
 *
 * This is in fact a Leaflet hook, not a Leaflet More Maps hook.
 *
 * For details see:
 * http://www.icc.cat/cat/Home-ICC/Geoinformacio-digital/Serveis-en-linia-Geoserveis/WMS-WMTS-rapids-de-cartografia-raster
 *
 * @return array
 *   an array of map options, indexed by map machine name
 */
function leaflet_catalunya_leaflet_map_info() {

  $settings = array(
    'minZoom' => 8,
    'layerControl' => TRUE,
  )
  + leaflet_more_maps_default_settings();

  $base_url = 'http://mapcache.icc.cat/map/bases_noutm/wmts';
  $zxy = '{z}/{x}/{y}.jpeg';
  $attr = t('Tiles &copy; <a href="http://www.icc.cat">Institut Cartogràfic de Catalunya</a>');
  $options = array('attribution' => $attr);

  $map_info['catalunya'] = array(
    'label' => 'Catalunya (zoom 8..18)',
    'description' => t('Detailed maps of Catalunya'),
    'settings' => $settings,
    'layers' => array(
      // The first layer will be rendered as the default layer of the map.
      t('Topographic') => array(
        'urlTemplate' => "$base_url/topo/GRID3857/$zxy",
        'options' => $options,
      ),
      t('Topographic grey') => array(
        'urlTemplate' => "$base_url/topogris/GRID3857/$zxy",
        'options' => $options,
      ),
      t('Orthophoto') => array(
        'urlTemplate' => "$base_url/orto/GRID3857/$zxy",
        'options' => $options,
      ),
    ),
  );
  return $map_info;
}

/**
 * @} End of "addtogroup hooks".
 */
