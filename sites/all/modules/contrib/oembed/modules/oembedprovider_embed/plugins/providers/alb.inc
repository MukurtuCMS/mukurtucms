<?php

$plugin = array(
  'title' => 'Alb',
  'callback' => 'oembedprovider_embed_alb_callback',
  'scheme' => '*',
);

function oembedprovider_embed_alb_callback($plugin, $url, $matches, $parameters) {
  $embed = FALSE;

  $response = Alb\OEmbed\Simple::request($url, $parameters);
  if ($response) {
    $embed = $response->toArray();
  }

  return $embed;
}
