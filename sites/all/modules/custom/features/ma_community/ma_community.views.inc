<?php

/**
 * Implements hook_views_query_alter().
 */
function ma_community_views_query_alter(&$view, &$query) {
    // Modify the community members list view to support restricting who is displayed (all, managers, none)
    if($view->name == 'group_members') {
        if ($node = menu_get_object()) {
            if($node->type == 'community' || $node->type == 'cultural_protocol_group') {
                if(isset($node->field_membership_list_options[LANGUAGE_NONE][0]['value'])) {
                    $table['community']['role'] = 'community manager';
                    $table['community']['name'] = t('Community Managers');

                    $table['cultural_protocol_group']['role'] = 'protocol steward';
                    $table['cultural_protocol_group']['name'] = t('Protocol Stewards');

                    // Remove old where
                    foreach($query->where[1]['conditions'] as $condition_key => $condition) {
                        if($condition['field'] == 'og_users_roles_og_membership__og_role.name') {
                            unset($query->where[1]['conditions'][$condition_key]);
                        }
                    }

                    // Get the configured option from the community/protocol
                    $membership_option = $node->field_membership_list_options[LANGUAGE_NONE][0]['value'];

                    switch($membership_option) {
                    case 'none':
                        $query->add_where(1, 'og_users_roles_og_membership__og_role.name', array(), 'IN');
                        break;
                    case 'managers':
                        $view->build_info['title'] = $table[$node->type]['name'];
                        $query->add_where(1, 'og_users_roles_og_membership__og_role.name', array($table[$node->type]['role'] => $table[$node->type]['role']), 'IN');
                        break;
                    default:
                        $or = db_or()
                            ->condition('og_users_roles_og_membership__og_role.name', NULL, 'IS NULL')
                            ->condition('og_users_roles_og_membership__og_role.name', NULL, 'IS NOT NULL');
                        $query->add_where(3, $or);
                    }
                }
            }
        }
    }
}