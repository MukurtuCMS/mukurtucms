<?php
/**
 * @file
 * Theme functions for Open Atrium Access module.
 */

/**
 * Returns HTML for the Group and Team permissions forms.
 */
function theme_oa_access_permissions_form($variables) {
  $permissions = $variables['permissions'];
  $first = NULL;

  $rows = array();
  foreach (element_children($permissions) as $module) {
    $child_rows = array();
    foreach (element_children($permissions[$module]) as $name) {
      // Capture the first permission to use later for the table headers.
      if (is_null($first)) {
        $first = $permissions[$module][$name];
      }

      if (!isset($permissions[$module][$name]['#access']) || $permissions[$module][$name]['#access']) {
        // Remove the individual labels, because they are going into the
        // table header.
        unset(
          $permissions[$module][$name]['name']['#title'],
          $permissions[$module][$name]['groups']['#title']
        );

        // Render them into the table row.
        $child_rows[] = array(
          array(
            'data' => drupal_render($permissions[$module][$name]['name']),
            'class' => array('permission'),
          ),
          drupal_render($permissions[$module][$name]['groups']),
        );
      }
    }

    if (count($child_rows) > 0) {
      // Render the parent row.
      $rows[] = array(array(
        'data' => drupal_render($permissions[$module]),
        'class' => array('module'),
        'id' => 'module-' . $permissions[$module]['#id'],
        'colspan' => 2,
      ));
      // Merge in the child rows.
      $rows = array_merge($rows, $child_rows);
    }
    else {
      // Make sure the module header doesn't get rendered at the end.
      $permissions[$module]['#access'] = FALSE;
    }
  }

  if (count($rows) == 0) {
    return '<p><em>' . t('No permissions available.') . '</em></p>';
  }

  // Build the table header.
  $header = array(
    $first['name']['#title'],
    $first['groups']['#title'],
  );
  // Render the table.
  $output  = theme('system_compact_link');
  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(
      // So that the theming for the standard user permission page is also
      // used here.
      'id' => 'permissions',
    ),
  ));
  $output .= drupal_render_children($permissions);
  return $output;
}
