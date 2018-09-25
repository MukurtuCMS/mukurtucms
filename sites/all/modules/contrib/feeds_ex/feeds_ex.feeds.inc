<?php

/**
 * @file
 * Feeds hooks for feeds_ex.
 */

/**
 * Implements hook_feeds_plugins().
 */
function feeds_ex_feeds_plugins() {
  $path = drupal_get_path('module', 'feeds_ex') . '/src';

  // In some cases, the module is not loaded yet when this include gets called.
  // @todo Figure out why.
  drupal_load('module', 'feeds_ex');

  $plugins = array(
    'FeedsExBase' => array(
      'hidden' => TRUE,
      'handler' => array(
        'parent' => 'FeedsParser',
        'class' => 'FeedsExBase',
        'file' => 'FeedsExBase.inc',
        'path' => $path,
      ),
    ),
    'FeedsExXml' => array(
      'name' => 'XML Xpath parser',
      'description' => 'Parse XML with XPath.',
      'handler' => array(
        'parent' => 'FeedsExBase',
        'class' => 'FeedsExXml',
        'file' => 'FeedsExXml.inc',
        'path' => $path,
      ),
    ),
    'FeedsExHtml' => array(
      'name' => 'HTML Xpath parser',
      'description' => 'Parse HTML with XPath.',
      'handler' => array(
        'parent' => 'FeedsExXml',
        'class' => 'FeedsExHtml',
        'file' => 'FeedsExHtml.inc',
        'path' => $path,
      ),
    ),
  );

  if (feeds_ex_library_path('jmespath.php', 'vendor/autoload.php')) {
    $plugins['FeedsExJmesPath'] = array(
      'name' => 'JSON JMESPath parser',
      'description' => 'Parse JSON with JMESPath.',
      'handler' => array(
        'parent' => 'FeedsExBase',
        'class' => 'FeedsExJmesPath',
        'file' => 'FeedsExJmesPath.inc',
        'path' => $path,
      ),
    );
    $plugins['FeedsExJmesPathLines'] = array(
      'name' => 'JSON Lines JMESPath parser',
      'description' => 'Parse JSON Lines with JMESPath.',
      'handler' => array(
        'parent' => 'FeedsExJmesPath',
        'class' => 'FeedsExJmesPathLines',
        'file' => 'FeedsExJmesPathLines.inc',
        'path' => $path,
      ),
    );
  }

  if (module_exists('querypath')) {
    $plugins['FeedsExQueryPathXml'] = array(
      'name' => 'QueryPath XML parser',
      'description' => 'Parse XML with QueryPath.',
      'handler' => array(
        'parent' => 'FeedsExXml',
        'class' => 'FeedsExQueryPathXml',
        'file' => 'FeedsExQueryPathXml.inc',
        'path' => $path,
      ),
    );
    $plugins['FeedsExQueryPathHtml'] = array(
      'name' => 'QueryPath HTML parser',
      'description' => 'Parse HTML with QueryPath.',
      'handler' => array(
        'parent' => 'FeedsExQueryPathXml',
        'class' => 'FeedsExQueryPathHtml',
        'file' => 'FeedsExQueryPathHtml.inc',
        'path' => $path,
      ),
    );
  }

  if (feeds_ex_jsonpath_library_path()) {
    $plugins['FeedsExJsonPath'] = array(
      'name' => 'JSON JSONPath parser',
      'description' => 'Parse JSON with JSONPath.',
      'handler' => array(
        'parent' => 'FeedsExBase',
        'class' => 'FeedsExJsonPath',
        'file' => 'FeedsExJsonPath.inc',
        'path' => $path,
      ),
    );
    $plugins['FeedsExJsonPathLines'] = array(
      'name' => 'JSON Lines JSONPath parser',
      'description' => 'Parse JSON Lines with JSONPath.',
      'handler' => array(
        'parent' => 'FeedsExJsonPath',
        'class' => 'FeedsExJsonPathLines',
        'file' => 'FeedsExJsonPathLines.inc',
        'path' => $path,
      ),
    );
  }

  return $plugins;
}
