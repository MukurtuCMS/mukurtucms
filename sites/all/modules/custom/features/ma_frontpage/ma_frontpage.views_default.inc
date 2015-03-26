<?php
/**
 * @file
 * ma_frontpage.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_frontpage_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'featured';
  $view->description = 'Adds a menu tab linking to a browser with search/filter tools showing Digital Heritage thumbnails and content';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Featured';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'label' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
    'tid_1' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
    'tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
    'keys' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '18';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['row_class'] = 'grid-2';
  $handler->display->display_options['style_options']['columns'] = '6';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['content'] = 'No results found';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['group']['id'] = 'group';
  $handler->display->display_options['relationships']['group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['group']['field'] = 'group';
  $handler->display->display_options['relationships']['group']['relationship'] = 'og_membership_rel';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Node field */
  $handler->display->display_options['fields']['nodefield_1']['id'] = 'nodefield_1';
  $handler->display->display_options['fields']['nodefield_1']['table'] = 'node';
  $handler->display->display_options['fields']['nodefield_1']['field'] = 'nodefield';
  $handler->display->display_options['fields']['nodefield_1']['label'] = '';
  $handler->display->display_options['fields']['nodefield_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nodefield_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nodefield_1']['build_mode'] = 'browse_teaser';
  $handler->display->display_options['fields']['nodefield_1']['links'] = 0;
  $handler->display->display_options['fields']['nodefield_1']['comments'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
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
    'digital_heritage' => 'digital_heritage',
  );

  /* Display: Page (featured) */
  $handler = $view->new_display('page', 'Page (featured)', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    1 => '1',
    2 => '2',
    4 => '4',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Node field */
  $handler->display->display_options['fields']['nodefield_1']['id'] = 'nodefield_1';
  $handler->display->display_options['fields']['nodefield_1']['table'] = 'node';
  $handler->display->display_options['fields']['nodefield_1']['field'] = 'nodefield';
  $handler->display->display_options['fields']['nodefield_1']['label'] = '';
  $handler->display->display_options['fields']['nodefield_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nodefield_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nodefield_1']['build_mode'] = 'browse_teaser';
  $handler->display->display_options['fields']['nodefield_1']['links'] = 0;
  $handler->display->display_options['fields']['nodefield_1']['comments'] = 0;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::add_to_my_collection_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::export_by_field_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Export node(s)',
      'settings' => array(
        'url' => 'admin/batch-node-export',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::delete_from_my_collection_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::sync_nodes_from_source_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  $handler->display->display_options['path'] = 'featured';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Browse';
  $handler->display->display_options['menu']['description'] = 'Browse the digital heritage collection';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Browse';
  $handler->display->display_options['tab_options']['description'] = 'Browse digital heritage items';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'featured.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Featured Grid */
  $handler = $view->new_display('block', 'Featured Grid', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'Featured Grid';

  /* Display: Featured Slideshow */
  $handler = $view->new_display('block', 'Featured Slideshow', 'block_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'path' => 0,
    'nodefield_1' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['hide_on_single_slide'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'nodefield_1' => 'nodefield_1',
    'path' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_hover'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['hide_on_single_slide'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '3';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Node field */
  $handler->display->display_options['fields']['nodefield_1']['id'] = 'nodefield_1';
  $handler->display->display_options['fields']['nodefield_1']['table'] = 'node';
  $handler->display->display_options['fields']['nodefield_1']['field'] = 'nodefield';
  $handler->display->display_options['fields']['nodefield_1']['label'] = '';
  $handler->display->display_options['fields']['nodefield_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nodefield_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nodefield_1']['build_mode'] = 'featured';
  $handler->display->display_options['fields']['nodefield_1']['links'] = 0;
  $handler->display->display_options['fields']['nodefield_1']['comments'] = 0;
  $handler->display->display_options['block_description'] = 'Featured Slideshow';
  $translatables['featured'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No results'),
    t('No results found'),
    t('OG membership from node'),
    t('group'),
    t('All'),
    t('Page (featured)'),
    t('Feed'),
    t('Featured Grid'),
    t('Featured Slideshow'),
  );
  $export['featured'] = $view;

  $view = new view();
  $view->name = 'ma_recent_comments';
  $view->description = 'Contains a block and a page to list recent comments; the block will automatically link to the page, which displays the comment body as well as a link to the node.';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'Mukurtu Recent Comments';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent Comments';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = 5;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Manage comments link */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'Manage comments link';
  $handler->display->display_options['header']['area']['content'] = '<a href="/admin/content/comment">Manage Comments</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Comment: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Comment: Title */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  /* Field: Comment: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'comment';
  $handler->display->display_options['fields']['timestamp']['field'] = 'changed';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Sort criterion: Comment: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'comment';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'changed';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['row_options']['separator'] = '&nbsp;';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Reply to';
  /* Field: Comment: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'comment';
  $handler->display->display_options['fields']['timestamp']['field'] = 'changed';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: Comment: Title */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  /* Field: Comment: Comment */
  $handler->display->display_options['fields']['comment']['id'] = 'comment';
  $handler->display->display_options['fields']['comment']['table'] = 'field_data_comment_body';
  $handler->display->display_options['fields']['comment']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment']['label'] = '';
  $handler->display->display_options['path'] = 'comments/recent';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['ma_recent_comments'] = array(
    t('Master'),
    t('Recent Comments'),
    t('More'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="/admin/content/comment">Manage Comments</a>'),
    t('Content'),
    t('Page'),
    t('more'),
    t('Reply to'),
    t('Block'),
  );
  $export['ma_recent_comments'] = $view;

  $view = new view();
  $view->name = 'map';
  $view->description = 'Adds a menu tab linking to a browser with search/filter tools showing Digital Heritage thumbnails and content';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Map';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'label' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
    'tid_1' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
    'tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
    'keys' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '150';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'geofield_map_map';
  $handler->display->display_options['style_options']['data_source'] = 'field_coverage';
  $handler->display->display_options['style_options']['popup_source'] = 'nodefield_1';
  $handler->display->display_options['style_options']['geofield_map_height'] = '500px';
  $handler->display->display_options['style_options']['geofield_map_zoom'] = '4';
  $handler->display->display_options['style_options']['geofield_map_controltype'] = 'small';
  $handler->display->display_options['style_options']['geofield_map_baselayers_satellite'] = 0;
  $handler->display->display_options['style_options']['geofield_map_baselayers_physical'] = 1;
  $handler->display->display_options['style_options']['geofield_map_scale'] = 1;
  $handler->display->display_options['style_options']['geofield_map_overview'] = 1;
  $handler->display->display_options['style_options']['geofield_map_scrollwheel'] = 1;
  $handler->display->display_options['style_options']['geofield_map_draggable'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['content'] = 'No results found';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['group']['id'] = 'group';
  $handler->display->display_options['relationships']['group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['group']['field'] = 'group';
  $handler->display->display_options['relationships']['group']['relationship'] = 'og_membership_rel';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Node field */
  $handler->display->display_options['fields']['nodefield_1']['id'] = 'nodefield_1';
  $handler->display->display_options['fields']['nodefield_1']['table'] = 'node';
  $handler->display->display_options['fields']['nodefield_1']['field'] = 'nodefield';
  $handler->display->display_options['fields']['nodefield_1']['label'] = '';
  $handler->display->display_options['fields']['nodefield_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nodefield_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nodefield_1']['build_mode'] = 'browse_teaser';
  $handler->display->display_options['fields']['nodefield_1']['links'] = 0;
  $handler->display->display_options['fields']['nodefield_1']['comments'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
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
    'digital_heritage' => 'digital_heritage',
  );

  /* Display: Page (map) */
  $handler = $view->new_display('page', 'Page (map)', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    3 => '3',
    8 => '8',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Node field */
  $handler->display->display_options['fields']['nodefield_1']['id'] = 'nodefield_1';
  $handler->display->display_options['fields']['nodefield_1']['table'] = 'node';
  $handler->display->display_options['fields']['nodefield_1']['field'] = 'nodefield';
  $handler->display->display_options['fields']['nodefield_1']['label'] = '';
  $handler->display->display_options['fields']['nodefield_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nodefield_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nodefield_1']['build_mode'] = 'browse_teaser';
  $handler->display->display_options['fields']['nodefield_1']['links'] = 0;
  $handler->display->display_options['fields']['nodefield_1']['comments'] = 0;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_coverage']['id'] = 'field_coverage';
  $handler->display->display_options['fields']['field_coverage']['table'] = 'field_data_field_coverage';
  $handler->display->display_options['fields']['field_coverage']['field'] = 'field_coverage';
  $handler->display->display_options['fields']['field_coverage']['label'] = '';
  $handler->display->display_options['fields']['field_coverage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coverage']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_coverage']['type'] = 'geofield_geojson';
  $handler->display->display_options['fields']['field_coverage']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_coverage']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_coverage']['group_columns'] = array(
    'wkt' => 'wkt',
  );
  $handler->display->display_options['path'] = 'map/content';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Browse';
  $handler->display->display_options['menu']['description'] = 'Browse the digital heritage collection';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Browse';
  $handler->display->display_options['tab_options']['description'] = 'Browse digital heritage items';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['map'] = array(
    t('Master'),
    t('Map'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('No results'),
    t('No results found'),
    t('OG membership from node'),
    t('group'),
    t('All'),
    t('Page (map)'),
    t('Block'),
  );
  $export['map'] = $view;

  return $export;
}
