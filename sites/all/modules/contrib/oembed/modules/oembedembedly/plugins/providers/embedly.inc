<?php

$plugin = array(
  'title' => 'Embed.ly',
  'callback' => 'oembedembedly_provider_callback',
  'get child' => 'oembedembedly_provider_get_child',
  'scheme callback' => 'oembedembedly_embedly_provider_scheme',
  'endpoint' => 'http://api.embed.ly/1/oembed',
  'consumer' => TRUE,
);

function oembedembedly_embedly_provider_scheme() {
  $json = oembedembedly_providers();
  $schemes = array();
  if (is_array($json)) {
    $selections = oembedembedly_default_selected();
    foreach ($json as $provider_name => $info) {
      if ($selections[$provider_name]) {
        $schemes['embedly:'. $provider_name] = $info->regex;
      }
    }
  }
  return $schemes;
}

function oembedembedly_provider_get_child($plugin, $parent, $child) {
  $json = oembedembedly_providers();

  $plugin['name'] = $parent .':'. $child;
  $plugin['title'] = $json[$child]->displayname;
  $plugin['description'] = $json[$child]->about;
  $plugin['scheme'] = $json[$child]->regex;

  // Force the plugin to be processed again because it will persist in the static cache
  // of ctools_get_plugins(). Therefore, strip out the features of the child plugin
  // that make it look like the parent.
  unset($plugin['scheme callback']);
  unset($plugin['scheme map']);
  unset($plugin['weight']);
  $info = ctools_plugin_get_info('oembed', 'providers');
  $function = ctools_plugin_get_function($info, 'process');
  $function($plugin, $info);

  return $plugin;
}

function oembedembedly_provider_callback($plugin, $url, $matches, $parameters) {
  $parameters['key'] = variable_get('oembedembedly_api_key', NULL);

  // This guarantees that the plugin's file is loaded.
  $function = ctools_plugin_load_function('oembed', 'providers', 'default', 'callback');
  $response = oembed_default_callback($plugin, $url, $matches, $parameters);

  $providers = oembedembedly_providers();
  if (is_array($providers)) {
    list($parent, $child) = explode(':', $plugin['name'], 2);
    if (isset($providers[$child])) {
      if ($providers[$child]->type == 'audio') {
        $response['mime_type'] = 'audio/oembed';
      }
    }
  }
  return $response;
}
