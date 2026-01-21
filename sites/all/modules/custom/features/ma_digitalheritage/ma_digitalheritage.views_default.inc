<?php

/**
 * @file
 * ma_digitalheritage.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ma_digitalheritage_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dh_nodes_available_to_dh';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'DH nodes available to DH';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'digital_heritage' => 'digital_heritage',
  );
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Filter criterion: Content: Published status */
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
    'digital_heritage' => 'digital_heritage',
  );
  /* Filter criterion: Content: Book Parent (field_book_parent) */
  $handler->display->display_options['filters']['field_book_parent_target_id']['id'] = 'field_book_parent_target_id';
  $handler->display->display_options['filters']['field_book_parent_target_id']['table'] = 'field_data_field_book_parent';
  $handler->display->display_options['filters']['field_book_parent_target_id']['field'] = 'field_book_parent_target_id';
  $handler->display->display_options['filters']['field_book_parent_target_id']['operator'] = 'empty';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['dh_nodes_available_to_dh'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('All'),
    t('Entity Reference'),
  );
  $export['dh_nodes_available_to_dh'] = $view;

  $view = new view();
  $view->name = 'dh_related_items_teasers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'DH Related Items Teasers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'DH Related Items Teasers';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_related_content_node']['id'] = 'reverse_field_related_content_node';
  $handler->display->display_options['relationships']['reverse_field_related_content_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_related_content_node']['field'] = 'reverse_field_related_content_node';
  $handler->display->display_options['relationships']['reverse_field_related_content_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Media Assets */
  $handler->display->display_options['fields']['field_media_asset']['id'] = 'field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['table'] = 'field_data_field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['field'] = 'field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['label'] = '';
  $handler->display->display_options['fields']['field_media_asset']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_asset']['type'] = 'mukurtu_scald_related_items';
  $handler->display->display_options['fields']['field_media_asset']['settings'] = array(
    'link' => '1',
  );
  $handler->display->display_options['fields']['field_media_asset']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_media_asset']['delta_offset'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_related_content_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published status */
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
    'digital_heritage' => 'digital_heritage',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['dh_related_items_teasers'] = array(
    t('Master'),
    t('DH Related Items Teasers'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Content referencing Content from field_related_content'),
    t('All'),
    t('Block'),
  );
  $export['dh_related_items_teasers'] = $view;

  $view = new view();
  $view->name = 'digital_heritage_grid_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Digital Heritage Browse';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'browse-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Grid/List switcher';
  $handler->display->display_options['header']['area']['content'] = '<div><a class="list btn">List</a> <a class="grid btn">Grid</a> <a class="map btn">Map</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results matched your search.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Sort criterion: Indexed Node: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    8 => 0,
    7 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'digital_heritage' => 'digital_heritage',
  );
  /* Filter criterion: Indexed Node: Community */
  $handler->display->display_options['filters']['field_community_ref']['id'] = 'field_community_ref';
  $handler->display->display_options['filters']['field_community_ref']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_community_ref']['field'] = 'field_community_ref';
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: All */
  $handler = $view->new_display('panel_pane', 'All', 'all');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Community-filtered */
  $handler = $view->new_display('panel_pane', 'Community-filtered', 'community');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: All (Map) */
  $handler = $view->new_display('panel_pane', 'All (Map)', 'all_map');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_coverage';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = '#rendered_entity';
  $handler->display->display_options['style_options']['view_mode'] = 'map_popup';
  $handler->display->display_options['style_options']['map'] = 'google-high-res';
  $handler->display->display_options['style_options']['height'] = '600';
  $handler->display->display_options['style_options']['hide_empty'] = 1;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Indexed Node: Location */
  $handler->display->display_options['fields']['field_coverage']['id'] = 'field_coverage';
  $handler->display->display_options['fields']['field_coverage']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_coverage']['field'] = 'field_coverage';
  $handler->display->display_options['fields']['field_coverage']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_coverage']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    8 => 0,
    7 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'digital_heritage' => 'digital_heritage',
  );
  /* Filter criterion: Location: Geo Type (indexed) */
  $handler->display->display_options['filters']['field_coverage_geo_type']['id'] = 'field_coverage_geo_type';
  $handler->display->display_options['filters']['field_coverage_geo_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_coverage_geo_type']['field'] = 'field_coverage_geo_type';
  $handler->display->display_options['filters']['field_coverage_geo_type']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_coverage_geo_type']['value'] = array();
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['digital_heritage_grid_list'] = array(
    t('Master'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Grid/List switcher'),
    t('<div><a class="list btn">List</a> <a class="grid btn">Grid</a> <a class="map btn">Map</a></div>'),
    t('No results matched your search.'),
    t('Node ID'),
    t('.'),
    t(','),
    t('All'),
    t('View panes'),
    t('Community-filtered'),
    t('All (Map)'),
    t('Location'),
    t('Title'),
    t('Status'),
  );
  $export['digital_heritage_grid_list'] = $view;

  $view = new view();
  $view->name = 'export_digital_heritage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Manage Digital Heritage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Export Digital Heritage';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'php';
  $handler->display->display_options['access']['php_access'] = '$admin = user_role_load_by_name(\'administrator\');
$mukurtuadmin = user_role_load_by_name(\'Mukurtu Administrator\');

if(user_has_role($admin->rid) || user_has_role($mukurtuadmin->rid)) {
     return TRUE;
}
return FALSE;';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_media_asset' => 'field_media_asset',
    'changed' => 'changed',
    'field_summary' => 'field_summary',
    'field_community_ref' => 'field_community_ref',
    'field_category' => 'field_category',
    'field_creator' => 'field_creator',
    'field_contributor' => 'field_contributor',
    'field_date' => 'field_date',
    'field_collection' => 'field_collection',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_media_asset' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_community_ref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_creator' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contributor' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_collection' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select All';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::mukurtu_export_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::ma_importexport_dc_action_xml_export' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Media Assets */
  $handler->display->display_options['fields']['field_media_asset']['id'] = 'field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['table'] = 'field_data_field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['field'] = 'field_media_asset';
  $handler->display->display_options['fields']['field_media_asset']['type'] = 'sdl_library_item';
  $handler->display->display_options['fields']['field_media_asset']['settings'] = array(
    'link' => '0',
  );
  $handler->display->display_options['fields']['field_media_asset']['delta_offset'] = '0';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'exif';
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['exclude'] = TRUE;
  /* Field: Content: Community */
  $handler->display->display_options['fields']['field_community_ref']['id'] = 'field_community_ref';
  $handler->display->display_options['fields']['field_community_ref']['table'] = 'field_data_field_community_ref';
  $handler->display->display_options['fields']['field_community_ref']['field'] = 'field_community_ref';
  $handler->display->display_options['fields']['field_community_ref']['delta_offset'] = '0';
  /* Field: Field: Category */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['delta_offset'] = '0';
  /* Field: Content: Creator */
  $handler->display->display_options['fields']['field_creator']['id'] = 'field_creator';
  $handler->display->display_options['fields']['field_creator']['table'] = 'field_data_field_creator';
  $handler->display->display_options['fields']['field_creator']['field'] = 'field_creator';
  $handler->display->display_options['fields']['field_creator']['delta_offset'] = '0';
  /* Field: Field: Contributor */
  $handler->display->display_options['fields']['field_contributor']['id'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['table'] = 'field_data_field_contributor';
  $handler->display->display_options['fields']['field_contributor']['field'] = 'field_contributor';
  $handler->display->display_options['fields']['field_contributor']['delta_offset'] = '0';
  /* Field: Content: Original Date Description */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  /* Field: Content: Collections */
  $handler->display->display_options['fields']['field_collection']['id'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['table'] = 'field_data_field_collection';
  $handler->display->display_options['fields']['field_collection']['field'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_collection']['delta_offset'] = '0';
  /* Filter criterion: Content: Published status */
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
    'digital_heritage' => 'digital_heritage',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Community (field_community_ref) */
  $handler->display->display_options['filters']['field_community_ref_nid']['id'] = 'field_community_ref_nid';
  $handler->display->display_options['filters']['field_community_ref_nid']['table'] = 'field_data_field_community_ref';
  $handler->display->display_options['filters']['field_community_ref_nid']['field'] = 'field_community_ref_nid';
  $handler->display->display_options['filters']['field_community_ref_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['operator_id'] = 'field_community_ref_nid_op';
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['label'] = 'Community';
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['operator'] = 'field_community_ref_nid_op';
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['identifier'] = 'field_community_ref_nid';
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_community_ref_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Field: Category (field_category) */
  $handler->display->display_options['filters']['field_category_tid']['id'] = 'field_category_tid';
  $handler->display->display_options['filters']['field_category_tid']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_tid']['field'] = 'field_category_tid';
  $handler->display->display_options['filters']['field_category_tid']['value'] = '';
  $handler->display->display_options['filters']['field_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_category_tid']['expose']['operator_id'] = 'field_category_tid_op';
  $handler->display->display_options['filters']['field_category_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_category_tid']['expose']['operator'] = 'field_category_tid_op';
  $handler->display->display_options['filters']['field_category_tid']['expose']['identifier'] = 'field_category_tid';
  $handler->display->display_options['filters']['field_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_category_tid']['group_info']['label'] = 'Category (field_category)';
  $handler->display->display_options['filters']['field_category_tid']['group_info']['identifier'] = 'field_category_tid';
  $handler->display->display_options['filters']['field_category_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_category_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_category_tid']['vocabulary'] = 'category';
  /* Filter criterion: Content: Creator (field_creator) */
  $handler->display->display_options['filters']['field_creator_tid']['id'] = 'field_creator_tid';
  $handler->display->display_options['filters']['field_creator_tid']['table'] = 'field_data_field_creator';
  $handler->display->display_options['filters']['field_creator_tid']['field'] = 'field_creator_tid';
  $handler->display->display_options['filters']['field_creator_tid']['value'] = '';
  $handler->display->display_options['filters']['field_creator_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_creator_tid']['expose']['operator_id'] = 'field_creator_tid_op';
  $handler->display->display_options['filters']['field_creator_tid']['expose']['label'] = 'Creator';
  $handler->display->display_options['filters']['field_creator_tid']['expose']['operator'] = 'field_creator_tid_op';
  $handler->display->display_options['filters']['field_creator_tid']['expose']['identifier'] = 'field_creator_tid';
  $handler->display->display_options['filters']['field_creator_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_creator_tid']['vocabulary'] = 'creator';
  /* Filter criterion: Content: Community Record Parent (field_community_record_parent) */
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['id'] = 'field_community_record_parent_target_id';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['table'] = 'field_data_field_community_record_parent';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['field'] = 'field_community_record_parent_target_id';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['expose']['operator_id'] = 'field_community_record_parent_target_id_op';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['expose']['label'] = 'Community Record Parent (field_community_record_parent)';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['expose']['operator'] = 'field_community_record_parent_target_id_op';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['expose']['identifier'] = 'field_community_record_parent_target_id';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['group_info']['label'] = 'Is Community Record';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['group_info']['identifier'] = 'field_community_record_parent_target_id';
  $handler->display->display_options['filters']['field_community_record_parent_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => 'not empty',
      'value' => array(
        'value' => '2',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'No',
      'operator' => 'empty',
      'value' => array(
        'value' => '2',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Content: Book Parent (field_book_parent) */
  $handler->display->display_options['filters']['field_book_parent_target_id']['id'] = 'field_book_parent_target_id';
  $handler->display->display_options['filters']['field_book_parent_target_id']['table'] = 'field_data_field_book_parent';
  $handler->display->display_options['filters']['field_book_parent_target_id']['field'] = 'field_book_parent_target_id';
  $handler->display->display_options['filters']['field_book_parent_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_book_parent_target_id']['expose']['operator_id'] = 'field_book_parent_target_id_op';
  $handler->display->display_options['filters']['field_book_parent_target_id']['expose']['label'] = 'Book Parent (field_book_parent)';
  $handler->display->display_options['filters']['field_book_parent_target_id']['expose']['operator'] = 'field_book_parent_target_id_op';
  $handler->display->display_options['filters']['field_book_parent_target_id']['expose']['identifier'] = 'field_book_parent_target_id';
  $handler->display->display_options['filters']['field_book_parent_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_book_parent_target_id']['group_info']['label'] = 'Book Pages';
  $handler->display->display_options['filters']['field_book_parent_target_id']['group_info']['identifier'] = 'field_book_parent_target_id';
  $handler->display->display_options['filters']['field_book_parent_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Show first page only',
      'operator' => 'empty',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Show all pages',
      'operator' => 'not empty',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Digital Heritage */
  $handler = $view->new_display('page', 'Digital Heritage', 'page');
  $handler->display->display_options['path'] = 'manage/digital-heritage';

  /* Display: Dictionary */
  $handler = $view->new_display('page', 'Dictionary', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Export Dictionary Words';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select All';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::mukurtu_export_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_dictionary_word_language']['id'] = 'field_dictionary_word_language';
  $handler->display->display_options['fields']['field_dictionary_word_language']['table'] = 'field_data_field_dictionary_word_language';
  $handler->display->display_options['fields']['field_dictionary_word_language']['field'] = 'field_dictionary_word_language';
  /* Field: Field: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'exif';
  /* Field: Content: Original Date Description */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
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
    'dictionary_word' => 'dictionary_word',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Language (field_dictionary_word_language) */
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['id'] = 'field_dictionary_word_language_tid';
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['table'] = 'field_data_field_dictionary_word_language';
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['field'] = 'field_dictionary_word_language_tid';
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['value'] = '';
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['expose']['operator_id'] = 'field_dictionary_word_language_tid_op';
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['expose']['operator'] = 'field_dictionary_word_language_tid_op';
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['expose']['identifier'] = 'field_dictionary_word_language_tid';
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_dictionary_word_language_tid']['vocabulary'] = 'language';
  $handler->display->display_options['path'] = 'manage/dictionary-words';
  $translatables['export_digital_heritage'] = array(
    t('Master'),
    t('Export Digital Heritage'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Select All'),
    t('- Choose an operation -'),
    t('Title'),
    t('Media Assets'),
    t('Updated date'),
    t('Summary'),
    t('Community'),
    t('Category'),
    t('Creator'),
    t('Contributor'),
    t('Original Date Description'),
    t('Collections'),
    t('Category (field_category)'),
    t('Community Record Parent (field_community_record_parent)'),
    t('Is Community Record'),
    t('Book Parent (field_book_parent)'),
    t('Book Pages'),
    t('Digital Heritage'),
    t('Dictionary'),
    t('Export Dictionary Words'),
    t('Language'),
    t('Keywords'),
  );
  $export['export_digital_heritage'] = $view;

  return $export;
}
