<?php

/**
 * @file
 * ma_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ma_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/dashboard' => 'admin/dashboard',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mukurtu_splash-manage_community' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'manage_community',
          'region' => 'dashboard_main',
          'weight' => '-22',
        ),
        'mukurtu_splash-manage_content' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'manage_content',
          'region' => 'dashboard_main',
          'weight' => '-21',
        ),
        'mukurtu_splash-demo_config' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'demo_config',
          'region' => 'dashboard_main',
          'weight' => '-10',
        ),
        'mukurtu_splash-user' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'user',
          'region' => 'dashboard_sidebar',
          'weight' => '-10',
        ),
        'mukurtu_splash-support' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'support',
          'region' => 'dashboard_sidebar',
          'weight' => '-9',
        ),
        'mukurtu_splash-site_start' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'site_start',
          'region' => 'dashboard_sidebar',
          'weight' => '-10',
        ),
        'mukurtu_splash-site_config' => array(
          'module' => 'mukurtu_splash',
          'delta' => 'site_config',
          'region' => 'dashboard_sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['dashboard'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page';
  $context->description = 'Mukurtu Starter Theme - Front Page';
  $context->tag = 'mukurtustarter';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'theme' => array(
      'values' => array(
        'mukurtu_starter' => 'mukurtu_starter',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-ma_site_header' => array(
          'module' => 'boxes',
          'delta' => 'ma_site_header',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-communities_content-block_1' => array(
          'module' => 'views',
          'delta' => 'communities_content-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Mukurtu Starter Theme - Front Page');
  t('mukurtustarter');
  $export['front_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mukurtu_theme-all_pages';
  $context->description = 'Mukurtu Theme - All Pages';
  $context->tag = 'mukurtu';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'theme' => array(
      'values' => array(
        'mukurtu' => 'mukurtu',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-breadcrumb' => array(
          'module' => 'delta_blocks',
          'delta' => 'breadcrumb',
          'region' => 'header',
          'weight' => '-10',
        ),
        'mukurtu_theme_blocks-mukurtu_theme_footer' => array(
          'module' => 'mukurtu_theme_blocks',
          'delta' => 'mukurtu_theme_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Mukurtu Theme - All Pages');
  t('mukurtu');
  $export['mukurtu_theme-all_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mukurtu_theme-front_page';
  $context->description = 'Mukurtu Theme - Front Page';
  $context->tag = 'mukurtu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'theme' => array(
      'values' => array(
        'mukurtu' => 'mukurtu',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-frontpage-hero-image-one-column' => array(
          'module' => 'bean',
          'delta' => 'frontpage-hero-image-one-column',
          'region' => 'header',
          'weight' => '-9',
        ),
        'bean-frontpage-hero-image-two-columns' => array(
          'module' => 'bean',
          'delta' => 'frontpage-hero-image-two-columns',
          'region' => 'header',
          'weight' => '-8',
        ),
        'views-c3e75cf63f3ce664337f20e351ba7938' => array(
          'module' => 'views',
          'delta' => 'c3e75cf63f3ce664337f20e351ba7938',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-450f9588d7199dab32cfdceb4015cb67' => array(
          'module' => 'views',
          'delta' => '450f9588d7199dab32cfdceb4015cb67',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Mukurtu Theme - Front Page');
  t('mukurtu');
  $export['mukurtu_theme-front_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'Mukurtu Starter Theme - Site Wide';
  $context->tag = 'mukurtustarter';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'theme' => array(
      'values' => array(
        'mukurtu_starter' => 'mukurtu_starter',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-ma_site_footer' => array(
          'module' => 'boxes',
          'delta' => 'ma_site_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Mukurtu Starter Theme - Site Wide');
  t('mukurtustarter');
  $export['sitewide'] = $context;

  return $export;
}
