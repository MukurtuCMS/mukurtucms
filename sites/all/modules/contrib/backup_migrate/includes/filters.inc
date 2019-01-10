<?php

/**
 * @file
 * All of the filter handling code needed for Backup and Migrate.
 */

/**
 * Gets the available destination types.
 */
function backup_migrate_get_filters($op = NULL) {
  $filters = &drupal_static('backup_migrate_get_filters', NULL);
  if ($filters === NULL) {
    $filters = array();
    $definitions = module_invoke_all('backup_migrate_filters');
    foreach ($definitions as $definition) {
      // Include the necessary file if specified by the filter.
      if (!empty($definition['file'])) {
        require_once './' . $definition['file'];
      }
      $filters[] = new $definition['class']();
    }
  }
  $sort = array();
  // Sort the filters based on the weight for the given operation.
  foreach ($filters as $filter) {
    $sort[] = $filter->weight($op);
  }
  array_multisort($sort, SORT_ASC, SORT_NUMERIC, $filters);
  return $filters;
}

/**
 * Implements hook_backup_migrate_filters().
 *
 * Get the built in Backup and Migrate filters.
 */
function backup_migrate_backup_migrate_filters() {
  return array(
    'backup_restore' => array(
      'file' => drupal_get_path('module', 'backup_migrate') . '/includes/filters.backup_restore.inc',
      'class' => 'backup_migrate_filter_backup_restore',
    ),
    'compression' => array(
      'file' => drupal_get_path('module', 'backup_migrate') . '/includes/filters.compression.inc',
      'class' => 'backup_migrate_filter_compression',
    ),
    'encryption' => array(
      'file' => drupal_get_path('module', 'backup_migrate') . '/includes/filters.encryption.inc',
      'class' => 'backup_migrate_filter_encryption',
    ),
    'statusnotify' => array(
      'file' => drupal_get_path('module', 'backup_migrate') . '/includes/filters.statusnotify.inc',
      'class' => 'backup_migrate_filter_statusnotify',
    ),
    'utils' => array(
      'file' => drupal_get_path('module', 'backup_migrate') . '/includes/filters.utils.inc',
      'class' => 'backup_migrate_filter_utils',
    ),
  );
}

/**
 * Invokes the given method on all of the available filters.
 */
function backup_migrate_filters_invoke_all() {
  $args    = func_get_args();
  $op      = array_shift($args);
  $out     = array();
  $filters = backup_migrate_get_filters($op);
  foreach ($filters as $filter) {
    if (method_exists($filter, $op)) {
      /* call_user_func_array() ignores the function signature, so we cannot
       * use it to pass references. (Call-time pass-by-reference is deprecated
       * in PHP5.3.) Work around it, since we have unknown function signatures.
       */
      switch (count($args)) {
        case 1:
          $ret = $filter->$op($args[0]);
          break;

        case 2:
          $ret = $filter->$op($args[0], $args[1]);
          break;

        default:
          // This assumes that no functions with more than 2 arguments expect a
          // reference as argument. If so, add another 'case block'.
          $ret = call_user_func_array(array($filter, $op), $args);
      }
      $out = array_merge_recursive($out, (array) $ret);
    }
  }
  return $out;
}

/**
 * Filters a backup file before sending it to the destination.
 */
function backup_migrate_filters_backup($file, &$settings) {
  backup_migrate_filters_invoke_all('pre_backup', $file, $settings);
  $filters = backup_migrate_get_filters('backup');
  foreach ($filters as $filter) {
    if ($file) {
      $file = $filter->backup($file, $settings);
    }
  }
  backup_migrate_filters_invoke_all('post_backup', $file, $settings);

  return $file;
}

/**
 * Filters a backup file before sending it to the destination.
 */
function backup_migrate_filters_restore($file, &$settings) {
  backup_migrate_filters_invoke_all('pre_restore', $file, $settings);
  $filters = backup_migrate_get_filters('restore');
  foreach ($filters as $filter) {
    if ($file) {
      $file = $filter->restore($file, $settings);
    }
  }
  backup_migrate_filters_invoke_all('post_restore', $file, $settings);
  return $file;
}

/**
 * Gets the backup settings for all of the filters.
 */
function backup_migrate_filters_settings_form($settings, $op) {
  $out = backup_migrate_filters_invoke_all($op . '_settings_form', $settings);
  $out = backup_migrate_filters_settings_form_set_parents($out);
  return $out;
}

/**
 * Adds form parent to filter settings so the values are saved in correct table.
 */
function backup_migrate_filters_settings_form_set_parents($form) {
  foreach (element_children($form) as $key) {
    if (!isset($form[$key]['#parents'])) {
      $form[$key]['#parents'] = array('filters', $key);
      $form[$key] = backup_migrate_filters_settings_form_set_parents($form[$key]);
    }
  }
  return $form;
}

/**
 * Validates all the filters.
 */
function backup_migrate_filters_settings_form_validate($op, $form, &$form_state) {
  backup_migrate_filters_invoke_all($op . '_settings_form_validate', $form, $form_state);
}

/**
 * Submits all of the filters.
 */
function backup_migrate_filters_settings_form_submit($op, $form, &$form_state) {
  backup_migrate_filters_invoke_all($op . '_settings_form_submit', $form, $form_state);
}

/**
 * Gets the default settings for the filters.
 */
function backup_migrate_filters_settings_default($op) {
  return backup_migrate_filters_invoke_all($op . '_settings_default');
}

/**
 * Get the backup settings for all of the filters.
 */
function backup_migrate_filters_before_action_form($settings, $op) {
  $out = array();
  $out += backup_migrate_filters_invoke_all('before_action_form', $op, $settings);
  $out += backup_migrate_filters_invoke_all('before_' . $op . '_form', $settings);
  return $out;
}

/**
 * Get the backup settings for all of the filters.
 */
function backup_migrate_filters_before_action_form_validate($settings, $op, $form, &$form_state) {
  backup_migrate_filters_invoke_all('before_action_form_validate', $op, $settings, $form, $form_state);
  backup_migrate_filters_invoke_all('before_' . $op . '_form_validate', $settings, $form, $form_state);
}

/**
 * Get the backup settings for all of the filters.
 */
function backup_migrate_filters_before_action_form_submit($settings, $op, $form, &$form_state) {
  backup_migrate_filters_invoke_all('before_action_form_submit', $op, $settings, $form, $form_state);
  backup_migrate_filters_invoke_all('before_' . $op . '_form_submit', $settings, $form, $form_state);
}

/**
 * Get the file types for all of the filters.
 */
function backup_migrate_filters_file_types() {
  return backup_migrate_filters_invoke_all('file_types');
}

/**
 * A base class for basing filters on.
 */
class backup_migrate_filter {
  public $weight = 0;
  public $op_weights = array();

  /**
   * Get the weight of the filter for the given op.
   */
  public function weight($op = NULL) {
    if ($op && isset($this->op_weights[$op])) {
      return $this->op_weights[$op];
    }
    return $this->weight;
  }

  /**
   * Get the form for the settings for this filter.
   */
  public function backup_settings_default() {
    return array();
  }

  /**
   * Get the form for the settings for this filter.
   */
  public function backup_settings_form($settings) {
    return array();
  }

  /**
   * Get the form for the settings for this filter.
   */
  public function backup_settings_form_validate($form, &$form_state) {
  }

  /**
   * Submit the settings form. Any values returned will be saved.
   */
  public function backup_settings_form_submit($form, &$form_state) {
  }

  /**
   * Get the form for the settings for this filter.
   */
  public function restore_settings_default() {
    return array();
  }

  /**
   * Get the form for the settings for this filter.
   */
  public function restore_settings_form($settings) {
    return array();
  }

  /**
   * Get the form for the settings for this filter.
   */
  public function restore_settings_form_validate($form, &$form_state) {
  }

  /**
   * Submit the settings form. Any values returned will be saved.
   */
  public function restore_settings_form_submit($form, &$form_state) {
    return $form_state['values'];
  }

  /**
   * Get a list of file types handled by this filter.
   */
  public function file_types() {
    return array();
  }

  /**
   * Declare any default destinations for this filter.
   */
  public function destinations() {
    return array();
  }

  /**
   * Called on a backup file after the backup has been completed.
   */
  public function backup($file, $settings) {
    return $file;
  }

  /**
   * This function is called immediately prior to backup.
   */
  public function pre_backup($file, $settings) {

  }

  /**
   * This function is called immediately post backup.
   */
  public function post_backup($file, $settings) {

  }

  /**
   * This function is called on a backup file before importing it.
   */
  public function restore($file, $settings) {
    return $file;
  }

  /**
   * This function is called immediately prior to restore.
   */
  public function pre_restore($file, $settings) {

  }

  /**
   * This function is called immediately post restore.
   */
  public function post_restore($file, $settings) {

  }

}
