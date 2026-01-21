<?php

/**
 * @file
 * ma_lesson_plan.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ma_lesson_plan_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_-lesson:node/add/lesson.
  $menu_links['main-menu_-lesson:node/add/lesson'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/lesson',
    'router_path' => 'node/add/lesson',
    'link_title' => '+ Lesson',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'mukurtu-actions',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_-lesson:node/add/lesson',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'main-menu_add-content:node/add',
  );
  // Exported menu link: main-menu_-unit-plan:node/add/unit-plan.
  $menu_links['main-menu_-unit-plan:node/add/unit-plan'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/unit-plan',
    'router_path' => 'node/add/unit-plan',
    'link_title' => '+ Unit Plan',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'mukurtu-actions',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_-unit-plan:node/add/unit-plan',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'parent_identifier' => 'main-menu_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('+ Lesson');
  t('+ Unit Plan');

  return $menu_links;
}
