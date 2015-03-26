<?php

$plugin = array(
  'title' => 'Embed',
  'callback' => 'oembedprovider_embed_embed_callback',
  'scheme' => '*',
);

function oembedprovider_embed_embed_callback($plugin, $url, $matches, $parameters) {
  $embed = FALSE;

  $provider = Embed\Embed::create(new Embed\Url($url));
  if ($provider->OEmbed) {
    $embed = $provider->OEmbed->get();
  }
  return $embed;
}
