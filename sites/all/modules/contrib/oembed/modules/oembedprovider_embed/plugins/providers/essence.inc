<?php

$plugin = array(
  'title' => 'Essence',
  'callback' => 'oembedprovider_embed_essence_callback',
  'scheme' => '*',
);

function oembedprovider_embed_essence_callback($plugin, $url, $matches, $parameters) {
  $embed = FALSE;

  $Essence = new fg\Essence\Essence();
  $Media = $Essence->embed($url, $parameters);
  if ($Media) {
    $embed = $Media->properties();
  }
  return $embed;
}
