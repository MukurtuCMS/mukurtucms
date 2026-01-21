<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('Two Column Bricks'),
  'category' => t('Bootstrap'),
  'icon' => 'bootstrap_twocol_bricks.png',
  'theme' => 'bootstrap_twocol_bricks',
  'admin css' => '../panels-bootstrap-layouts-admin.css',
  'regions' => array(
    'top' => t('Top'),
    'left_above' => t('Left above'),
    'right_above' => t('Right above'),
    'middle' => t('Middle'),
    'left_below' => t('Left below'),
    'right_below' => t('Right below'),
    'bottom' => t('Bottom'),
  ),
);
