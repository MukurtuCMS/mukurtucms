<?php
/**
 * @file
 * Definition of the paragraphs item plugin.
 */

$plugin = array(
  'handler' => 'PanelizerEntityParagraphsItem',
  'entity path' => NULL,
  'hooks' => array(
    'menu' => TRUE,
    'admin_paths' => TRUE,
    'page_alter' => TRUE,
    'permission' => TRUE,
    'panelizer_defaults' => TRUE,
    'form_alter' => TRUE,
  ),
);
