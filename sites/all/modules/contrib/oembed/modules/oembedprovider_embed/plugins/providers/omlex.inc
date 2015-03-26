<?php

$plugin = array(
  'title' => 'Omlex',
  'callback' => 'oembedprovider_embed_omlex_callback',
  'scheme' => '*',
);

function oembedprovider_embed_omlex_callback($plugin, $url, $matches, $parameters) {
  $embed = FALSE;

  $ombed = new Omlex\OEmbed($url);

  // oEmbed response is a protected property of the object, so casting to an array is
  // the only way. See http://www.php.net/manual/en/language.types.array.php#language.types.array.casting

  $object = (array) $ombed->getObject($parameters);
  if ($object) {
    $embed = (array) $object["\x00*\x00object"];
  }

  return $embed;
}
