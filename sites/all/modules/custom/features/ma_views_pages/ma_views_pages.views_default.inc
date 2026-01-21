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
  $handler->display->display_options['title'] = 'Browse by Category';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-xs-12 col-sm-6 col-md-3 image-grid';
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
  /* Field: Taxonomy term: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail_image']['id'] = 'field_thumbnail_image';
  $handler->display->display_options['fields']['field_thumbnail_image']['table'] = 'field_data_field_thumbnail_image';
  $handler->display->display_options['fields']['field_thumbnail_image']['field'] = 'field_thumbnail_image';
  $handler->display->display_options['fields']['field_thumbnail_image']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail_image']['alter']['path'] = '/digital-heritage/category/[php]';
  $handler->display->display_options['fields']['field_thumbnail_image']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail_image']['empty'] = '<a href="/digital-heritage/category/[php]"><img src="/sites/all/modules/custom/features/ma_digitalheritage/images/no_media_available.jpg"/></a>';
  $handler->display->display_options['fields']['field_thumbnail_image']['click_sort_column'] = 'sid';
  $handler->display->display_options['fields']['field_thumbnail_image']['type'] = 'mukurtu_browse_by_grid_7_4';
  $handler->display->display_options['fields']['field_thumbnail_image']['settings'] = array(
    'link' => '0',
  );
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
  $handler->display->display_options['path'] = 'categories-browse';
  $translatables['browse_digital_heritage_by_category'] = array(
    t('Master'),
    t('Browse by Category'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('.'),
    t(','),
    t('Edit Taxonomy Term'),
    t('<a href="/digital-heritage/category/[php]"><img src="/sites/all/modules/custom/features/ma_digitalheritage/images/no_media_available.jpg"/></a>'),
    t('[name]'),
    t('Block'),
    t('Page'),
  );
  $export['browse_digital_heritage_by_category'] = $view;

  $view = new view();
  $view->name = 'browse_digital_heritage_by_community';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Browse Digital Heritage by Community';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Browse by Community';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-xs-6 col-md-3 image-grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return drupal_get_path_alias("node/{$row->nid}");';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['fields']['contextual_links']['check_access'] = 0;
  $handler->display->display_options['fields']['contextual_links']['destination'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_community_image_thumbnail']['id'] = 'field_community_image_thumbnail';
  $handler->display->display_options['fields']['field_community_image_thumbnail']['table'] = 'field_data_field_community_image_thumbnail';
  $handler->display->display_options['fields']['field_community_image_thumbnail']['field'] = 'field_community_image_thumbnail';
  $handler->display->display_options['fields']['field_community_image_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_community_image_thumbnail']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_community_image_thumbnail']['alter']['path'] = '[php]';
  $handler->display->display_options['fields']['field_community_image_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_community_image_thumbnail']['click_sort_column'] = 'sid';
  $handler->display->display_options['fields']['field_community_image_thumbnail']['type'] = 'mukurtu_scald_taxonomy_thumbnail';
  $handler->display->display_options['fields']['field_community_image_thumbnail']['settings'] = array(
    'link' => '0',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'community' => 'community',
  );
  /* Filter criterion: Content: Parent Community (field_parent_community) */
  $handler->display->display_options['filters']['field_parent_community_target_id']['id'] = 'field_parent_community_target_id';
  $handler->display->display_options['filters']['field_parent_community_target_id']['table'] = 'field_data_field_parent_community';
  $handler->display->display_options['filters']['field_parent_community_target_id']['field'] = 'field_parent_community_target_id';
  $handler->display->display_options['filters']['field_parent_community_target_id']['operator'] = 'empty';
  /* Filter criterion: Content: Thumbnail Image (field_community_image_thumbnail:sid) */
  $handler->display->display_options['filters']['field_community_image_thumbnail_sid']['id'] = 'field_community_image_thumbnail_sid';
  $handler->display->display_options['filters']['field_community_image_thumbnail_sid']['table'] = 'field_data_field_community_image_thumbnail';
  $handler->display->display_options['filters']['field_community_image_thumbnail_sid']['field'] = 'field_community_image_thumbnail_sid';
  $handler->display->display_options['filters']['field_community_image_thumbnail_sid']['operator'] = 'not empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['browse_digital_heritage_by_community'] = array(
    t('Master'),
    t('Browse by Community'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Edit'),
    t('Block'),
  );
  $export['browse_digital_heritage_by_community'] = $view;

  $view = new view();
  $view->name = 'mukurtu_frontpage_browse_by_community';
  $view->description = 'Show all content (nodes) of a group.';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->human_name = 'Mukurtu Frontpage Browse by Community';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'content pane';
  $handler->display->display_options['css_class'] = 'masonry-grid';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-xs-12 col-sm-6 col-md-4 left-right-image-title';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'thumbed';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no communities to display. Only communities with thumbnail images will be displayed here.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Node field */
  $handler->display->display_options['fields']['nodefield']['id'] = 'nodefield';
  $handler->display->display_options['fields']['nodefield']['table'] = 'node';
  $handler->display->display_options['fields']['nodefield']['field'] = 'nodefield';
  $handler->display->display_options['fields']['nodefield']['label'] = '';
  $handler->display->display_options['fields']['nodefield']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nodefield']['build_mode'] = 'browse_teaser';
  $handler->display->display_options['fields']['nodefield']['links'] = 0;
  $handler->display->display_options['fields']['nodefield']['comments'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'community' => 'community',
  );
  /* Filter criterion: Content: Thumbnail Image (field_community_image_thumbnail:sid) */
  $handler->display->display_options['filters']['field_community_image_thumbnail_sid']['id'] = 'field_community_image_thumbnail_sid';
  $handler->display->display_options['filters']['field_community_image_thumbnail_sid']['table'] = 'field_data_field_community_image_thumbnail';
  $handler->display->display_options['filters']['field_community_image_thumbnail_sid']['field'] = 'field_community_image_thumbnail_sid';
  $handler->display->display_options['filters']['field_community_image_thumbnail_sid']['operator'] = 'not empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Browse by Community';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['mukurtu_frontpage_browse_by_community'] = array(
    t('Defaults'),
    t('content pane'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('There are no communities to display. Only communities with thumbnail images will be displayed here.'),
    t('OG membership from node'),
    t('Block'),
    t('Browse by Community'),
  );
  $export['mukurtu_frontpage_browse_by_community'] = $view;

  $view = new view();
  $view->name = 'mukurtu_frontpage_featured_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mukurtu Frontpage Featured Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Featured Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-4 col-sm-6 col-xs-12';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'featured_content';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No content has been featured. To mark content as featured, edit the content, go to the "Publishing options" tab, select "Promoted to front page" and save the content.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'collection' => 'collection',
    'community' => 'community',
    'dictionary_word' => 'dictionary_word',
    'digital_heritage' => 'digital_heritage',
    'person' => 'person',
    'word_list' => 'word_list',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['mukurtu_frontpage_featured_content'] = array(
    t('Master'),
    t('Featured Content'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No content has been featured. To mark content as featured, edit the content, go to the "Publishing options" tab, select "Promoted to front page" and save the content.'),
    t('Block'),
  );
  $export['mukurtu_frontpage_featured_content'] = $view;

  return $export;
}
