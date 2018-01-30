<?php

/**
 * @file
 * Hooks provided by the Fasttoggle module.
 */

/**
 * hook_fasttoggle_get_available_links
 *
 * @param $type
 *   (optional) The object type for which available links are being sought.
 *
 * @param $subtype
 *   (optional) An object object for which available links are being sought.
 *   The object's subtype (where applicable) may be used to further filter
 *   the links which are returned.
 *
 * @return
 *   If the parameter is NULL, returns an array containing all available links,
 *   indexed by type, is returned. If $type if not NULL, only the subtree for
 *   that type is returned. In the later case, hooks not supporting the chosen
 *   type may skip the work of doing any calculations or calls, saving time and
 *   memory.
 */
function fasttoggle_node_fasttoggle_available_links($type = NULL, $obj = NULL) {

  // This function only handles nodes so there's no point in doing anything if
  // we're not after nodes.
  if (!is_null($type) && $type != 'node')
    return array();

  // This is the structure that controls everything fasttoggle does.
  $result = array(
      'node' => array(                              // A brief name for the object type being matched
        'id_field' => 'nid',                        // The name of the ID field for this object type
        'title_field' => 'title',                   // Used in the non-ajax form.
        'save_fn' => 'fasttoggle_node_save',        // (Optional) The non-generic function used for saving state changes
        'object_type' => 'node',                    // The machine name for the object type. Used in menu paths, so should
        // not include spaces or other HTML special characters.
        'subtype_field' => 'type',                  // (Optional) The field in an object specifying the subtype.
        'access' => array('fasttoggle_node_edit_access'), // Optional an object-type wide access function (see below)
        'global_settings_desc' => t('In addition to these global settings, you need to enable fasttoogle in the settings page for each content type you wish to use.'),
        // The description to be used in the system wide settings page.
        'extra_settings' => array(                  // Extra values to be used in building the settings page.
          'help_text' => array(
            '#value' => t('Configure access restrictions for these settings on the <a href="@url">access control</a> page.', array('@url' => url('admin/user/permissions', array('fragment' => 'module-fasttoggle')))),
            '#prefix' => '<div>',
            '#suffix' => '</div>',
            ),
          'fasttoggle_enhance_node_overview_page' => array( // Extra elements may be added for submodule specific settings pages
            '#type' => 'checkbox',
            '#title' => t('Add published/unpublished toggle links to the node overview page.'),
            '#default_value' => variable_get('fasttoggle_enhance_node_overview_page', TRUE),
            '#weight' => 50,
            )
          ),
        'fields' => array(                          // 'fields' contains all the option information
            'status' => array(                      // The toplevel in the array is the name of a group of options (eg roles)
              'display' => array('node_links'),     // A submodule may add additional items for its own purposes
              'instances' => array(                 // The array of attributes of an object that may be toggled
                'status' => array(                  // The name of the object (= published in this case)
                  'description' => t('Status <small>(published/unpublished)</small>'),
                  'default' => TRUE,                // Whether enabled by default in the settings.
                  'access' => array('fasttoggle_node_status_access'), // An access control function
                  'labels' => array(                // The labels that are displayed for each state / label type
                    FASTTOGGLE_LABEL_ACTION => array(0 => t('publish'), 1 => t('unpublish')),
                    FASTTOGGLE_LABEL_STATUS => array(0 => t('not published'), 1 => t('published'))
                    ),
                  ),
                'sticky' => array(
                  'description' => t('Sticky <small>(stays at the top of listings)</small>'),
                  'default' => TRUE,
                  'access' => array('fasttoggle_node_sticky_access'),
                  'labels' => array(
                    FASTTOGGLE_LABEL_ACTION => array(0 => t('make sticky'), 1 => t('make unsticky')),
                    FASTTOGGLE_LABEL_STATUS => array(0 => t('not sticky'), 1 => t('sticky'))
                    ),
                  ),
                'promote' => array(
                  'description' => t('Promoted <small>(visible on the front page)</small>'),
                  'default' => TRUE,
                  'access' => array('fasttoggle_node_promote_access'),
                  'labels' => array(
                    FASTTOGGLE_LABEL_ACTION => array(0 => t('promote'), 1 => t('demote')),
                    FASTTOGGLE_LABEL_STATUS => array(0 => t('not promoted'), 1 => t('promoted'))
                    ),
                  ),
                ),
                ),
                ),
                ),
                );
  return $result;
}

/**
 * Access control function
 *
 * An access control function should check permissions of the user to modify the
 * object, generally wrapping the check in fasttoggle_deny_access_if() if a TRUE
 * return value should result in access being denied, or fasttoggle_allow_access_if
 * if a TRUE value should result in access being granted.
 *
 * A single hook may invoke either or both functions, as many times as are needed.
 * The first invocation that allows or denies access will be the effective one.
 *
 * If the neither of these functions are invoked by a hook with the TRUE value,
 * other hooks will be invoked, providing other modules the opportunity to perform
 * access checks. A TRUE value will cause other hooks to be skipped.
 *
 * The site and group-wide settings for disabling settings are always also checked.
 *
 * @param $obj
 *   The object being checked.
 * @param $type
 *   The type of the object.
 * @param $group
 *   The group to which the setting belongs. NULL if sitewide access is being checked.
 * @param $instance
 *   The instance being checked. NULL if site or groupwide access is being checked.
 */

function fasttoggle_node_status_access($obj) {
  fasttoggle_allow_access_if(user_access("override {$obj->type} published option"));
  fasttoggle_deny_access_if(!user_access('moderate posts'));
}

/**
 * Object save function
 *
 * @param $options
 *   The configuration array (the hook might want information from it).
 * @param $group
 *   The group to which the modified setting belongs.
 * @param $instance
 *   The field being modified in the object.
 * @param $new_value
 *   The new value to be saved, possibly '[unset]'.
 * @param $object
 *   The object to be modified and saved.
 */ 
function fasttoggle_node_save($options, $group, $instance, $new_value, $object) {
  if ($new_value === '[unset]') {
    unset($object->$instance);
  } else
    $object->$instance = $new_value;
  node_save($object);
}

/**
 * hook_fasttoggle_toggle
 *
 * Called when a link has been invoked, updating the value of a setting.
 *
 * @param $object_type
 *   The type of object being handled.
 * @param $object
 *   An instance of the object that has been modified, as saved.
 * @param $group
 *  The group to which the setting being modified belongs.
 * @param $instance
 *   The setting which was toggled.
 */
function example_toggle($type, $obj, $group, $instance)
{
  drupal_set_message("The {$instance} {$group} setting in a {$type} has been modified.");
}

/**
 * hook_fasttoggle_ajax_alter
 *
 * Hook allowing callees to modify the ajax sent back to a browser after a link
 * is toggled.
 *
 * @param $ajax_commands
 *   The default ajax commands (arg to ajax_render).
 * @param $object_type
 *   The type of object being handled.
 * @param $object
 *   An instance of the object that has been modified, as saved.
 * @param $params
 *   An array of further parameters, since drupal_alter only supports 3
 *   parameters. The array contains the group, option and view strings
 *   that describe what option was toggled and what view (if any) was
 *   applied to the object in its original render.
 */
function fasttoggle_node_fasttoggle_ajax_alter(&$ajax_commands, $object_type, $object, $params)
{
  if ($object_type != "node")
    return;

  // Replace the original content with that the updated content, so far as we're able (we don't
  // get it exactly right yet).
  $unrendered = node_view($object, $params['view']);
  if ($object->comment > 0 && module_exists('comment') && $params['view'] == 'full') {
    $unrendered['comments'] = comment_node_page_additions($object);
  }
  $replacement_content = drupal_render($unrendered);
  $ajax_commands[] = ajax_command_replace('.' . 'node-content-' . $object->nid, $replacement_content);
}
