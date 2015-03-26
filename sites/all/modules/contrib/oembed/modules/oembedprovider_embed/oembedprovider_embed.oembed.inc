<?php

/**
 * Impements hook_oembedprovider().
 *
 * The provider established by this module will attempt to resolve every URL it can.
 */
function oembedprovider_embed_oembedprovider() {
  return array(
    '*' => array(
      'name' => variable_get('oembedprovider_embed_provider', 'embed'),
      'callback' => 'oembedprovider_embed_provider',
    ),
  );
}
