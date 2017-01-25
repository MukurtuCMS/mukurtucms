<?php
/**
 * @file
 * ma_views_pages.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_views_pages_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'browse_digital_heritage_by_category';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Browse Digital Heritage by Category';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Digital Heritage Categories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-xs-6 col-md-3 image-grid';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term edit link */
  $handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['label'] = '';
  $handler->display->display_options['fields']['edit_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_term']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_term']['alter']['text'] = 'Edit Taxonomy Term';
  $handler->display->display_options['fields']['edit_term']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_term']['alter']['path'] = '/taxonomy/term/[tid]/edit';
  $handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_term']['element_default_classes'] = FALSE;
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_type'] = '0';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_term' => 'edit_term',
  );
  $handler->display->display_options['fields']['contextual_links']['check_access'] = 0;
  $handler->display->display_options['fields']['contextual_links']['destination'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$path = drupal_get_path_alias(\'taxonomy/term/\' . $row->tid);
return substr($path, strripos($path, \'/\') + 1);';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'digital-heritage/category/[php]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail_image']['id'] = 'field_thumbnail_image';
  $handler->display->display_options['fields']['field_thumbnail_image']['table'] = 'field_data_field_thumbnail_image';
  $handler->display->display_options['fields']['field_thumbnail_image']['field'] = 'field_thumbnail_image';
  $handler->display->display_options['fields']['field_thumbnail_image']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail_image']['alter']['path'] = '/digital-heritage/category/[php]';
  $handler->display->display_options['fields']['field_thumbnail_image']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail_image']['empty'] = '<img src="/sites/all/modules/custom/features/ma_digitalheritage/images/no_media_available.jpg"/>';
  $handler->display->display_options['fields']['field_thumbnail_image']['click_sort_column'] = 'sid';
  $handler->display->display_options['fields']['field_thumbnail_image']['type'] = 'mukurtu_scald_taxonomy_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail_image']['settings'] = array(
    'link' => '0',
  );
  /* Sort criterion: Taxonomy vocabulary: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'category' => 'category',
  );
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Browse By Category';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'categories-browse';
  $translatables['browse_digital_heritage_by_category'] = array(
    t('Master'),
    t('Digital Heritage Categories'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('.'),
    t(','),
    t('Edit Taxonomy Term'),
    t('[name]'),
    t('<img src="/sites/all/modules/custom/features/ma_digitalheritage/images/no_media_available.jpg"/>'),
    t('Block'),
    t('Page'),
    t('Browse By Category'),
  );
  $export['browse_digital_heritage_by_category'] = $view;

  return $export;
}
