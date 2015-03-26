<?php

$plugin = array(
  'schema' => 'oembed_provider',
  'access' => 'administer oembed',
  'menu' => array(
    'menu prefix' => 'admin/config/media/oembed/provider',
    'menu item' => 'default',
    'menu title' => 'Remote endpoints',
    'menu description' => 'Add, edit and remove oembed providers from the system.',
  ),
  'handler' => array(
    'class' => 'oembed_provider_ui',
    'parent' => 'ctools_export_ui',
  ),
  'title singular' => t('provider'),
  'title singular proper' => t('Provider'),
  'title plural' => t('providers'),
  'title plural proper' => t('Providers'),
);
