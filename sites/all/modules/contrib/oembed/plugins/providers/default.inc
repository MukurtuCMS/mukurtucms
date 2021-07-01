<?php

$plugin = array(
  'title' => 'Remote endpoint',
  'description' => 'oEmbed provider for remote endpoints',
  'callback' => 'oembed_default_callback',
  'get child' => 'oembed_default_provider_get_child',
  'scheme callback' => 'oembed_default_provider_scheme',
  'consumer' => TRUE,
);

/**
 * Child plugins are oembed_provider objects that describe remote oEmbed endpoints.
 */
function oembed_default_provider_get_child($plugin, $parent, $child) {
  ctools_include('export');
  $provider = ctools_export_crud_load('oembed_provider', $child);
  $plugin['title'] = $provider->title;
  $plugin['endpoint'] = $provider->endpoint;
  $plugin['scheme'] = $provider->scheme;
  $plugin['name'] = $parent . ':' . $provider->name;

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

/**
 *
 */
function oembed_default_provider_scheme() {
  // oEmbed provider definitions are remote web services.
  ctools_include('export');
  $providers = ctools_export_load_object('oembed_provider');
  $schemes = array();
  foreach ($providers as $provider) {
    if (empty($provider->disabled) && !empty($provider->scheme)) {
      $schemes['default:'. $provider->name] = $provider->scheme;
    }
  }
  return $schemes;
}

/**
 * Default provider callback makes HTTP requests using drupal_http_request().
 */
function oembed_default_callback($plugin, $url, $matches, $parameters) {

  // Remote oEmbed endpoint request.
  $parameters['url'] = $url;
  $query = http_build_query($parameters, NULL, '&');
  $fetch_url = $plugin['endpoint'] . '?' . $query;

  //TODO: Add alternative ways of fetching the content - like http client?
  $response = drupal_http_request($fetch_url);

  if (isset($response->error)) {
    watchdog('oembed', 'Error fetching data from %url.', array('%url' => $fetch_url), WATCHDOG_ERROR);
    throw new RuntimeException($response->error, $response->code);
  }

  // JSON or XML data might be returned, so be agnostic about decoding it.
  $embed = drupal_json_decode($response->data);

  // json_decode returns null when the input is unparseable.
  if (is_null($embed)) {
    try {
      $xml = @new SimpleXMLElement($response->data);
      $embed = array();
      foreach ($xml as $key => $value) {
        $embed[$key] = (string) $value;
      }
    }
    catch (Exception $e) {
      $msg = 'Could not parse response from %url.';
      if (function_exists('json_last_error')) {
        $msg .= ' json='. json_last_error();
        if (function_exists('json_last_error_msg')) {
          $msg .= ' ('. json_last_error_msg() .')';
        }
      }
      watchdog_exception('oembed', $e, $msg, array('%url' => $fetch_url), WATCHDOG_ERROR);
      throw new RuntimeException(t($msg, array('%url' => $fetch_url)), WATCHDOG_ERROR, $e);
    }
  }

  if (!is_array($embed) || empty($embed['version']) || empty($embed['type']) || intval($embed['version']) != 1) {
    watchdog('oembed', 'Response from %url not a valid oEmbed response.', array('%url' => $fetch_url), WATCHDOG_ERROR);
    throw new RuntimeException(t('Response from %url not a valid oEmbed response.', array('%url' => $fetch_url)), WATCHDOG_ERROR);
  }

  if (!isset($embed['title'])) {
    $embed['title'] = '';
  }

  return $embed;
}
