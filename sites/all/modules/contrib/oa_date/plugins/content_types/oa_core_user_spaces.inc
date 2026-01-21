<?php

/**
 * @file
 * Defines the space summary panels pane.
 */

define('SPACE_TAB_FAVORITE', 'Favorite');
define('SPACE_TAB_ARCHIVED', 'Archived');
define('SPACE_TAB_ACTIVE', 'Subscribed');
define('SPACE_TAB_MEMBERS', 'Memberships');
define('SPACE_TAB_INHERITED', 'Inherited');
define('SPACE_TAB_ALL', 'All');

$plugin = array(
  'title' => t('User Spaces'),
  'description' => t('Provides a list of spaces for a user.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_core_user_spaces_edit_form',
  'render callback' => 'oa_core_user_spaces_render',
  'required context' => new ctools_context_required(t('User'), 'user'),
  'defaults' => array(
    'tabs' => array(SPACE_TAB_FAVORITE, SPACE_TAB_MEMBERS, SPACE_TAB_INHERITED, SPACE_TAB_ALL),
    'image_size' => 'quarter',
    'show_description' => TRUE,
    'show_sections' => TRUE,
    'show_links' => TRUE,
    'link_class' => 'btn',
    'num_per_page' => 15,
    'types' => array(OA_SPACE_TYPE => OA_SPACE_TYPE),
  ),
);


/**
 * Render callback for the content visibility panel.
 */
function oa_core_user_spaces_render($subtype, $conf, $args, $context = NULL) {
  if (empty($context->data) || !user_access('access content')) {
    return;
  }
  $account = $context->data;
  $vars = array();

  if (isset($conf['types'])) {
    $group_types = array_filter($conf['types']);
  }
  else {
    $group_types = array(OA_SPACE_TYPE => OA_SPACE_TYPE);
  }
  $all_spaces_ids = oa_core_get_public_spaces($group_types);
  $active_spaces_ids = array();
  foreach ($group_types as $type) {
    $active_spaces_ids = array_merge($active_spaces_ids, oa_core_get_groups_by_user_access($account, FALSE, NULL, NULL, NULL, $type));
  }
  $active_spaces_ids = array_map(
    function($node) { return $node->nid; },
    $active_spaces_ids);
  $all_spaces_ids = array_merge($all_spaces_ids, $active_spaces_ids);

  $all_spaces_nodes = node_load_multiple($all_spaces_ids);
  $all_spaces = oa_core_build_space_display($all_spaces_nodes, $conf, $account, $group_types);

  $active_spaces_nodes = node_load_multiple($active_spaces_ids);
  $active_spaces = oa_core_build_space_display($active_spaces_nodes, $conf, $account, $group_types);

  $featured_spaces = array();
  if (module_exists('oa_favorites')) {
    $spaces = oa_favorites_get_spaces($account);
    $featured_spaces_nodes = node_load_multiple($spaces['ids']);
    $featured_spaces = oa_core_build_space_display($featured_spaces_nodes, $conf, $account, $group_types);
  }

  $archived_spaces = array();
  if (module_exists('oa_archive') && ($flag = flag_get_flag('trash'))) {
    $query = db_select('node', 'n');
    $query->join('flagging', 'a', 'a.fid = :fid AND n.nid = a.entity_id', array(':fid' => $flag->fid));
    $query
      ->fields('n', array('nid'))
      ->condition('n.type', $group_types, 'IN')
      ->addTag('node_access');
    $archived_spaces_ids = $query->execute()->fetchCol();
    $archived_spaces_nodes = node_load_multiple($archived_spaces_ids);
    $archived_spaces = oa_core_build_space_display($archived_spaces_nodes, $conf, $account, $group_types);
  }

  $page = 0;
  // set our maximum item per page
  $num_per_page = $conf['num_per_page'];
  $vars['space_groups'] = array();
  if (isset($conf['tabs'][SPACE_TAB_ACTIVE])) {
    $conf['tabs'][SPACE_TAB_MEMBERS] = $conf['tabs'][SPACE_TAB_ACTIVE];
    unset($conf['tabs'][SPACE_TAB_ACTIVE]);
  }
  if (!empty($conf['tabs'][SPACE_TAB_FAVORITE]) && !empty($featured_spaces)) {
    $vars['space_groups'][t(SPACE_TAB_FAVORITE)]['spaces'] = $featured_spaces;
  }
  if (!empty($conf['tabs'][SPACE_TAB_MEMBERS]) && !empty($active_spaces)) {
    if (!$conf['tabs'][SPACE_TAB_ALL] && ($num_per_page > 0)) {
      $active_spaces = array_slice($active_spaces, 0, $num_per_page);
      $vars['space_groups'][t(SPACE_TAB_MEMBERS)]['pager'] =
        l(t('See all'), 'spaces', array(
          'attributes' => array(
            'class' => $conf['link_class'],
        )));
    }
    $vars['space_groups'][t(SPACE_TAB_MEMBERS)]['spaces'] = $active_spaces;
  }
  if (!empty($conf['tabs'][SPACE_TAB_ARCHIVED]) && !empty($archived_spaces)) {
    $vars['space_groups'][t(SPACE_TAB_ARCHIVED)]['spaces'] = $archived_spaces;
  }
  if (!empty($conf['tabs'][SPACE_TAB_ALL])) {
    // pager_find_page() will return the current page number
    $page = pager_find_page();
    // build the offset variable
    $offset = $num_per_page * $page;
    // initialize our pager
    pager_default_initialize(count($all_spaces), $num_per_page);

    $all_spaces = array_slice($all_spaces, $offset, $num_per_page);
    $vars['space_groups'][t(SPACE_TAB_ALL)]['spaces'] = $all_spaces;
    $vars['space_groups'][t(SPACE_TAB_ALL)]['pager'] = theme('pager');
  }
  if ($page > 0) {
    $vars['active'] = SPACE_TAB_ALL;
  }
  else {
    $vars['active'] = key($vars['space_groups']);
  }
  $vars['title_tag'] = ($conf['show_description']) ? 'h4' : 'div';
  $vars['main_class'] = ($conf['show_description']) ? 'member-full' : 'member-sidebar';

  $block = new stdClass();
  $title = '';
  if (!empty($group_types[OA_SPACE_TYPE])) {
    $title = t('Spaces');
  }
  if (!empty($group_types[OA_GROUP_TYPE])) {
    if (empty($title)) {
      $title = t('Groups');
    }
    else {
      $title = t('Spaces and Groups');
    }
  }
  if (count($vars['space_groups']) == 1) {
    $block->title = key($vars['space_groups']) . ' ' . $title;
  }
  else {
    $block->title = $title;
  }
  $block->content = theme('oa_core_user_spaces', $vars);
  return $block;
}


/**
 * Builds display variables for spaces. Optionally sections as well.
 */
function oa_core_build_space_display($spaces, $conf, $account,
  $group_types = array(OA_SPACE_TYPE => OA_SPACE_TYPE)) {
  $vars = array();
  usort($spaces, 'oa_core_sort_node_by_title');
  foreach ($spaces as $space) {
    if (empty($group_types[$space->type]) || !node_access('view', $space)) {
      continue;
    }
    $vars[$space->nid]['title'] = check_plain($space->title);
    $vars[$space->nid]['href'] = url('node/' . $space->nid);
    $vars[$space->nid]['body'] = '';
    $vars[$space->nid]['links'] = '';
    $vars[$space->nid]['sections'] = array();

    if ($conf['show_links']) {
      $vars[$space->nid]['links'] = oa_core_user_spaces_get_links($space, $conf, $account);
    }

    if ($conf['show_description']) {
      $body = field_view_field('node', $space, 'body', 'teaser');
      $vars[$space->nid]['body'] = drupal_render($body);
    }

    $vars[$space->nid]['picture'] = '';
    if ($conf['image_size'] != 'none') {
      $picture = field_get_items('node', $space, 'field_featured_image');
      if (!empty($picture)) {
        $picture = array_shift($picture);
        $vars[$space->nid]['picture'] = theme('image_style', array(
          'style_name' => 'panopoly_image_' . $conf['image_size'],
          'path' => $picture['uri'],
          'width' => $picture['width'],
          'height' => $picture['height'],
          'alt' => $picture['alt'],
        ));
      }
    }
    if ($conf['show_sections']) {
      $include_archived = user_access('view trash content') || og_user_access('node', $space->nid, 'view trash content', $account);
      $sections = oa_core_space_sections($space->nid, NODE_PUBLISHED, FALSE, array(), $include_archived);
      foreach ($sections as $id => $title) {
        $vars[$space->nid]['sections'][$id] = l($title, 'node/' . $id);
      }
    }
  }

  return $vars;
}

/**
 * Generate the subscribed/unsubscribed links
 */
function oa_core_user_spaces_get_links($space, $conf, $account) {
  $links = oa_core_user_spaces_og_links($space, $account);
  $vars['links'] = array();
  if (!empty($links) && !empty($conf['link_class'])) {
    foreach ($links as $key => $link) {
      $links[$key]['#attributes'] = array('class' => $conf['link_class']);
    }
  }
  return $links;
}

/**
 * Return the OG subscribed/unsubscribed links
 * Code taken from og_ui_field_formatter_view
 * but that was hardcoded to use the logged-in user
 */
function oa_core_user_spaces_og_links($entity, $account) {
  global $user;

  $entity_type = 'node';
  $settings = array('field_name' => 'og_user_node');
  $uid = $account->uid;

  if (!og_is_group($entity_type, $entity)) {
    return;
  }

  if (!empty($entity->uid) && ($entity->uid == $account->uid)) {
    // User is the group manager.
    $element[0] = array('#markup' => t('You are the group manager'));
    return $element;
  }

  list($id, , $bundle) = entity_extract_ids($entity_type, $entity);
  if (og_is_member($entity_type, $id, 'user', $account, array(OG_STATE_ACTIVE, OG_STATE_PENDING))) {
    if (og_user_access($entity_type, $id, 'unsubscribe', $account)) {
      $links['title'] = t('Unsubscribe from group');
      if ($user->uid == $uid) {
        $links['href'] = "group/$entity_type/$id/unsubscribe";
      }
      else {
        $links['href'] = "group/$entity_type/$id/remove/single/$uid";
      }
      $links['options'] = array('query' => array('destination' => current_path()));
    }
  }
  else {
    if (og_is_member($entity_type, $id, 'user', $account, array(OG_STATE_BLOCKED))) {
      // If user is blocked, they should not be able to apply for
      // membership.
      return;
    }

    // Check if user can subscribe to the field.
    if (empty($settings['field_name']) && $audience_field_name = og_get_best_group_audience_field('user', $account, $entity_type, $bundle)) {
      $settings['field_name'] = $audience_field_name;
    }
    if (!$settings['field_name']) {
      return;
    }

    $field_info = field_info_field($settings['field_name']);

    // Check if entity is referencable.
    if ($field_info['settings']['target_type'] != $entity_type) {
      // Group type doesn't match.
      return;
    }
    if (!empty($field_info['settings']['handler_settings']['target_bundles']) && !in_array($bundle, $field_info['settings']['handler_settings']['target_bundles'])) {
      // Bundles don't match.
      return;
    }

    if (!og_check_field_cardinality('user', $account, $settings['field_name'])) {
      $element[0] = array('#markup' => format_plural($field_info['cardinality'], 'You are already registered to another group', 'You are already registered to @count groups'));
      return $element;
    }

    $url = "group/$entity_type/$id/add-member/$uid";
    if ($settings['field_name']) {
      $url .= '/' . $settings['field_name'];
    }
    $url .= '/nojs';

    if (og_user_access($entity_type, $id, 'subscribe without approval', $account)) {
      $links['title'] = t('Subscribe to group');
      if ($account->uid) {
        $links['href'] = $url;
        $links['options'] = array(
          'query' => array(
            'destination' => current_path(),
            'token' => drupal_get_token('node_' . $id . '_' . $account->uid),
          ),
        );
      }
      else {
        $links['href'] = 'user/login';
        $links['options'] = array('query' => array('destination' => $url));
      }
    }
    elseif (og_user_access($entity_type, $id, 'subscribe')) {
      $links['title'] = t('Request group membership');
      if ($account->uid) {
        $links['href'] = $url;
        $links['options'] = array(
          'query' => array(
            'destination' => current_path(),
            'token' => drupal_get_token('node_' . $id . '_' . $account->uid),
          ),
        );
     }
      else {
        $links['href'] = 'user/login';
        $links['options'] = array('query' => array('destination' => $url));
      }
    }
    else {
      $element[0] =  array('#markup' => t('This is a closed group. Only a group administrator can add you.'));
      return $element;
    }
  }

  if (!empty($links['title'])) {
    $links += array('options' => array());
    $element[0] = array(
      '#type' => 'link',
      '#title' => $links['title'],
      '#href' => $links['href'],
      '#options' => $links['options'],
    );
    return $element;
  }
  // User didn't have permissions.
}

/**
 * Sort function, sorts nodes by title.
 */
function oa_core_sort_node_by_title($n1, $n2) {
  return strcasecmp($n1->title, $n2->title);
}


/**
 * Edit form for the panel.
 */
function oa_core_user_spaces_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Types to show'),
    '#options' => array(
      OA_SPACE_TYPE => t('Spaces'),
      OA_GROUP_TYPE => t('Groups'),
    ),
    '#default_value' => $conf['types'],
  );

  $form['tabs'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Tabs'),
    '#options' => array(
      SPACE_TAB_FAVORITE => t(SPACE_TAB_FAVORITE),
      SPACE_TAB_ARCHIVED => t(SPACE_TAB_ARCHIVED),
      SPACE_TAB_MEMBERS => t(SPACE_TAB_MEMBERS),
      SPACE_TAB_INHERITED => t(SPACE_TAB_INHERITED),
      SPACE_TAB_ALL => t(SPACE_TAB_ALL),
    ),
    '#default_value' => $conf['tabs'],
  );

  $form['image_size'] = array(
    '#type' => 'radios',
    '#title' => t('Image size'),
    '#options' => array(
      'square' => t('Square'),
      'quarter' => t('Quarter'),
      'half' => t('Half'),
      'full' => t('Full'),
      'none' => t('None'),
    ),
    '#default' => $conf['image_size'],
  );

  $form['show_links'] = array(
    '#title' => t('Show links'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_links'],
  );
  $form['link_class'] = array(
    '#title' => t('CSS Link class'),
    '#type' => 'textfield',
    '#default_value' => $conf['link_class'],
    '#description' => 'Enter css classes for links, such as btn',
  );
  $form['show_description'] = array(
    '#title' => t('Show description'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_description'],
  );
  $form['show_sections'] = array(
    '#title' => t('Show sections'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_sections'],
  );
  $form['num_per_page'] = array(
    '#title' => t('Number per page'),
    '#type' => 'textfield',
    '#default_value' => $conf['num_per_page'],
    '#description' => 'Number per page, zero for all.',
  );

  return $form;
}


/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_core_user_spaces_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
