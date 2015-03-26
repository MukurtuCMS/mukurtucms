<?php

$plugin = array(
  'title' => 'Embed.ly2',
  'callback' => 'oembedprovider_embed_embedly2_callback',
  'scheme' => '*',
);

function oembedprovider_embed_embedly2_callback($plugin, $url, $matches, $parameters) {
  $embed = FALSE;

  $api = new Embedly\Embedly(array('key' => variable_get('oembedembedly_api_key', NULL)));
  $parameters['url'] = $url;

  $objs = $api->oembed($parameters);
  if ($objs) {
    $embed = (array) array_pop($objs);
  }

  return $embed;
}
