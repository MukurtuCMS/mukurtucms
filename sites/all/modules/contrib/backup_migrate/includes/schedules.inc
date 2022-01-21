<?php

/**
 * @file
 * All of the schedule handling code needed for Backup and Migrate.
 */

define('BACKUP_MIGRATE_KEEP_ALL', 0);
define('BACKUP_MIGRATE_STANDARD_DELETE', -1);
define('BACKUP_MIGRATE_SMART_DELETE', -2);

define('BACKUP_MIGRATE_CRON_BUILTIN', 'builtin');
define('BACKUP_MIGRATE_CRON_ELYSIA', 'elysia');
define('BACKUP_MIGRATE_CRON_NONE', 'none');


define('BACKUP_MIGRATE_SMART_KEEP_SUBHOURLY', 3600);
define('BACKUP_MIGRATE_SMART_KEEP_HOURLY', 24);
define('BACKUP_MIGRATE_SMART_KEEP_DAILY', 30);
define('BACKUP_MIGRATE_SMART_KEEP_WEEKLY', PHP_INT_MAX);

define('BACKUP_MIGRATE_KEEP_DEFAULT', 100);

require_once dirname(__FILE__) . '/crud.inc';

/**
 * Implements hook_backup_migrate_destination_types().
 *
 * Get the built in Backup and Migrate destination types.
 */
function backup_migrate_backup_migrate_schedule_types() {
  $out = array();
  $out += array(
    'backup' => array(
      'include' => 'schedule',
      'type_name' => t('Backup Schedule'),
      'class' => 'backup_migrate_schedule',
    ),
  );
  return $out;
}

/**
 * Run the preconfigured schedules. Called on cron.
 */
function backup_migrate_schedules_cron() {
  require_once dirname(__FILE__) . '/profiles.inc';

  foreach (backup_migrate_get_schedules() as $schedule) {
    $schedule->cron();
  }
  backup_migrate_cleanup();
}

/**
 * Run the preconfigured schedules regardless of scheduled time settings.
 */
function backup_migrate_schedules_run() {
  require_once dirname(__FILE__) . '/profiles.inc';

  foreach (backup_migrate_get_schedules() as $schedule) {
    $schedule->run();
  }
  backup_migrate_cleanup();
}

/**
 * Run the preconfigured schedules. Called on cron.
 */
function backup_migrate_schedule_run($schedule_id) {
  require_once dirname(__FILE__) . '/profiles.inc';

  if (($schedule = backup_migrate_get_schedule($schedule_id)) && $schedule->is_enabled()) {
    $schedule->run();
  }
  backup_migrate_cleanup();
}

/**
 * Get all the available backup schedules.
 */
function backup_migrate_get_schedules() {
  $schedules = &drupal_static('backup_migrate_get_schedules');
  // Get the list of schedules and cache them locally.
  if ($schedules === NULL) {
    $schedules = backup_migrate_crud_get_items('schedule');
  }
  return $schedules;
}

/**
 * Get the schedule info for the schedule with the given ID, or NULL if none exists.
 */
function backup_migrate_get_schedule($schedule_id) {
  $schedules = backup_migrate_get_schedules();
  return @$schedules[$schedule_id];
}

/**
 * A schedule class for crud operations.
 */
class backup_migrate_schedule extends backup_migrate_item {
  public $db_table = "backup_migrate_schedules";
  public $type_name = 'schedule';
  public $singular = 'schedule';
  public $plural = 'schedules';
  public $title_plural = 'Schedules';
  public $title_singular = 'Schedule';
  public $default_values = array();

  /**
   * This function is not supposed to be called. It is just here to help the po extractor out.
   */
  public function strings() {
    // Help the pot extractor find these strings.
    t('Schedule');
    t('Schedules');
    t('schedule');
    t('schedules');
  }

  /**
   * Get the default values for this item.
   */
  public function get_default_values() {
    return array(
      'name' => t("Untitled Schedule"),
      'source_id' => 'db',
      'enabled' => 1,
      'keep' => BACKUP_MIGRATE_KEEP_ALL,
      'period' => 60 * 60 * 24,
      'storage' => BACKUP_MIGRATE_STORAGE_NONE,
      'cron' => BACKUP_MIGRATE_CRON_BUILTIN,
      'cron_schedule' => '0 4 * * *',
    );
  }

  /**
   * Return as an array of values.
   */
  public function to_array() {
    $out = parent::to_array();
    unset($out['last_run']);
    return $out;
  }

  /**
   * Get the columns needed to list the type.
   */
  public function get_list_column_info() {
    $out = parent::get_list_column_info();
    $out = array(
      'name'                  => array('title' => t('Name')),
      'destination_name'      => array('title' => t('Destinations'), 'html' => TRUE),
      'profile_name'          => array('title' => t('Profile'), 'html' => TRUE),
      'frequency_description' => array('title' => t('Frequency')),
      'keep_description'      => array('title' => t('Keep')),
      'enabled_description'   => array('title' => t('Enabled')),
      'last_run_description'  => array('title' => t('Last run')),
    ) + $out;
    return $out;
  }

  /**
   * Get the columns needed to list the type.
   */
  public function get_settings_path() {
    // Pull the schedules tab up a level to the top.
    return BACKUP_MIGRATE_MENU_PATH . '/' . $this->type_name;
  }

  /**
   * Get the menu items for manipulating this type.
   */
  public function get_menu_items() {
    $items = parent::get_menu_items();
    $path = $this->get_settings_path();
    return $items;
  }

  /**
   * Get a row of data to be used in a list of items of this type.
   */
  public function get_list_row() {
    drupal_add_css(drupal_get_path('module', 'backup_migrate') . '/backup_migrate.css');
    $row = parent::get_list_row();
    if (!$this->is_enabled()) {
      foreach ($row as $key => $field) {
        if (!is_array($field)) {
          $row[$key] = array('data' => $field, 'class' => 'schedule-list-disabled');
        }
        elseif (isset($row[$key]['class'])) {
          $row[$key]['class'] .= ' schedule-list-disabled';
        }
        else {
          $row[$key]['class'] = 'schedule-list-disabled';
        }
      }
    }
    return $row;
  }

  /**
   * Is the schedule enabled and valid.
   */
  public function is_enabled() {
    $destination = $this->get_destination();
    $profile = $this->get_profile();
    return (!empty($this->enabled) && !empty($destination) && !empty($profile));
  }

  /**
   * Get the destination object of the schedule.
   */
  public function get_destination() {
    $destinations = (array) $this->get_destinations();
    return reset($destinations);
  }

  /**
   * Get the destination object of the schedule.
   */
  public function get_destination_ids() {
    $out = array();
    foreach (array('destination_id', 'copy_destination_id') as $key) {
      if ($id = $this->get($key)) {
        $out[$key] = $id;
      }
    }
    return $out;
  }

  /**
   * Get the destination object of the schedule.
   */
  public function get_destinations() {
    require_once dirname(__FILE__) . '/destinations.inc';

    $out = array();
    foreach ($this->get_destination_ids() as $id) {
      if ($dest = backup_migrate_get_destination($id)) {
        $out[$id] = $dest;
      }
    }
    return $out;
  }

  /**
   * Get the destination object of the schedule.
   */
  public function get_destination_remote() {
    require_once dirname(__FILE__) . '/destinations.inc';

    return backup_migrate_get_destination($this->get('destination_remote_id'));
  }

  /**
   * Get the destination object of the schedule.
   */
  public function get_destination_local() {
    require_once dirname(__FILE__) . '/destinations.inc';

    return backup_migrate_get_destination($this->get('destination_local_id'));
  }

  /**
   * Get the name of the destination.
   */
  public function get_destination_name() {
    if ($destinations = $this->get_destinations()) {
      $out = array();
      foreach ((array) $destinations as $destination) {
        $out[] = check_plain($destination->get_name());
      }
      return implode(', ', $out);
    }
    return '<div class="row-error">' . t("Missing") . '</div>';
  }

  /**
   * Get the destination of the schedule.
   */
  public function get_profile() {
    require_once dirname(__FILE__) . '/profiles.inc';

    if ($settings = backup_migrate_get_profile($this->get('profile_id'))) {
      $settings->file_info = empty($settings->file_info) ? array() : $settings->file_info;
      $settings->file_info += array(
        'schedule_id'   => $this->get_id(),
        'schedule_name' => $this->get('name'),
      );
    }
    return $settings;

  }

  /**
   * Get the name of the source.
   */
  public function get_profile_name() {
    if ($profile = $this->get_profile()) {
      return check_plain($profile->get_name());
    }
    return '<div class="row-error">' . t("Missing") . '</div>';
  }

  /**
   * Format a frequency in human-readable form.
   */
  public function get_frequency_description() {
    $period = $this->get_frequency_period();
    $cron = $this->get('cron');
    if ($cron == BACKUP_MIGRATE_CRON_BUILTIN) {
      $out = format_plural(($this->period / $period['seconds']), $period['singular'], $period['plural']);
    }
    elseif ($cron == BACKUP_MIGRATE_CRON_ELYSIA) {
      $out = $this->get('cron_schedule');
    }
    else {
      $out = t('None');
    }
    return $out;
  }

  /**
   * Format the number to keep in human-readable form.
   */
  public function get_keep_description() {
    return $this->generate_keep_description($this->keep);
  }

  /**
   * Format a number to keep in human readable from.
   */
  public function generate_keep_description($keep, $terse = TRUE) {
    if ($keep == BACKUP_MIGRATE_KEEP_ALL) {
      return t('all backups');
    }
    elseif ($keep == BACKUP_MIGRATE_SMART_DELETE) {
      $keep_hourly = variable_get('backup_migrate_smart_keep_hourly', BACKUP_MIGRATE_SMART_KEEP_HOURLY);
      $keep_daily  = variable_get('backup_migrate_smart_keep_daily', BACKUP_MIGRATE_SMART_KEEP_DAILY);
      $keep_weekly = variable_get('backup_migrate_smart_keep_weekly', BACKUP_MIGRATE_SMART_KEEP_WEEKLY);
      if ($terse) {
        return t('!hours hourly, !days daily, !weeks weekly backups',
          array(
            '!hours' => $keep_hourly == PHP_INT_MAX ? t('all') : $keep_hourly,
            '!days'  => $keep_daily == PHP_INT_MAX ? t('all') : $keep_daily,
            '!weeks' => $keep_weekly == PHP_INT_MAX ? t('all') : $keep_weekly,
          ));
      }
      else {
        return t('hourly backups !hours, daily backups !days and weekly backups !weeks',
          array(
            '!hours' => $keep_hourly == PHP_INT_MAX ? t('forever') : format_plural($keep_hourly, 'for 1 hour', 'for the past @count hours'),
            '!days'  => $keep_daily == PHP_INT_MAX ? t('forever') : format_plural($keep_daily, 'for 1 day', 'for the past @count days'),
            '!weeks' => $keep_weekly == PHP_INT_MAX ? t('forever') : format_plural($keep_weekly, 'for 1 week', 'for the past @count weeks'),
          )
        );
      }
    }

    return format_plural($keep, 'last 1 backup', 'last @count backups');
  }

  /**
   * Format the enabled status in human-readable form.
   */
  public function get_enabled_description() {
    return !empty($this->enabled) ? t('Enabled') : t('Disabled');
  }

  /**
   * Format the enabled status in human-readable form.
   */
  public function get_last_run_description() {
    $last_run = $this->get('last_run');
    return !empty($last_run) ? format_date($last_run, 'small') : t('Never');
  }

  /**
   * Get the number of excluded tables.
   */
  public function get_exclude_tables_count() {
    return count($this->exclude_tables) ? count($this->exclude_tables) : t("No tables excluded");
  }

  /**
   * Get the number of excluded tables.
   */
  public function get_nodata_tables_count() {
    return count($this->nodata_tables) ? count($this->nodata_tables) : t("No data omitted");
  }

  /**
   * Get the edit form.
   */
  public function edit_form() {
    require_once dirname(__FILE__) . '/destinations.inc';
    require_once dirname(__FILE__) . '/sources.inc';
    require_once dirname(__FILE__) . '/profiles.inc';

    $form = parent::edit_form();

    $form['name'] = array(
      "#type" => "textfield",
      "#title" => t("Schedule Name"),
      "#default_value" => $this->get('name'),
    );

    $form += _backup_migrate_get_source_form($this->get('source_id'));

    $form['profile_id'] = array(
      "#type" => "select",
      "#title" => t("Settings Profile"),
      "#options" => _backup_migrate_get_profile_form_item_options(),
      "#default_value" => $this->get('profile_id'),
    );
    $form['profile_id']['#description'] = ' ' . l(t('Create new profile'), BACKUP_MIGRATE_MENU_PATH . '/settings/profile/add');
    if (!$form['profile_id']['#options']) {
      $form['profile_id']['#options'] = array('0' => t('-- None Available --'));
    }

    $period_options = array();
    foreach ($this->frequency_periods() as $type => $period) {
      $period_options[$type] = $period['title'];
    }
    $default_period     = $this->get_frequency_period();
    $default_period_num = $this->get('period') / $default_period['seconds'];

    $form['enabled'] = array(
      '#type' => "checkbox",
      '#title' => t('Enabled'),
      '#default_value' => $this->get('enabled'),
    );
    $form['cron_settings'] = array(
      '#type' => 'backup_migrate_dependent',
      '#dependencies' => array(
        'enabled' => TRUE,
      ),
    );

    $cron = $this->get('cron');
    $form['cron_settings']['cron_builtin'] = array(
      "#type" => "radio",
      "#title" => t('Run using Drupal\'s cron'),
      '#return_value' => BACKUP_MIGRATE_CRON_BUILTIN,
      "#description" => t('Run this schedule when !cron runs.', array('!cron' => l(t('your cron task'), 'http://drupal.org/cron'))),
      "#default_value" => $cron ? $cron : BACKUP_MIGRATE_CRON_BUILTIN,
      '#parents' => array('cron'),
    );

    $form['cron_settings']['period_settings'] = array(
      '#type' => 'backup_migrate_dependent',
      '#dependencies' => array(
        'cron' => BACKUP_MIGRATE_CRON_BUILTIN,
      ),
    );
    $form['cron_settings']['period_settings']['period'] = array(
      "#type" => "item",
      "#title" => t("Backup every"),
      "#prefix" => '<div class="container-inline">',
      "#suffix" => '</div>',
      "#tree" => TRUE,
      '#parents' => array('period'),
    );
    $form['cron_settings']['period_settings']['period']['number'] = array(
      "#type" => "textfield",
      "#size" => 6,
      "#default_value" => $default_period_num,
      '#parents' => array('period', 'number'),
    );
    $form['cron_settings']['period_settings']['period']['type'] = array(
      "#type" => "select",
      "#options" => $period_options,
      "#default_value" => $default_period['type'],
      '#parents' => array('period', 'type'),
    );

    $form['cron_settings']['cron_elysia'] = array(
      "#type" => "radio",
      "#title" => t('Run using Elysia cron'),
      '#return_value' => BACKUP_MIGRATE_CRON_ELYSIA,
      "#description" => t('You can specify exactly when this schedule should run using !elysia.', array('!elysia' => l(t('the Elysia Cron module'), 'http://drupal.org/project/elysia_cron'))),
      "#default_value" => $cron ? $cron : BACKUP_MIGRATE_CRON_BUILTIN,
      '#parents' => array('cron'),
    );
    if (!module_exists('elysia_cron') && !module_exists('ultimate_cron')) {
      $form['cron_settings']['cron_elysia']['#disabled'] = TRUE;
      $form['cron_settings']['cron_elysia']['#description'] .= ' ' . t('Install !elysia to enable this option.', array('!elysia' => l(t('Elysia Cron'), 'http://drupal.org/project/elysia_cron')));
    }
    $form['cron_settings']['cron_schedule_settings'] = array(
      '#type' => 'backup_migrate_dependent',
      '#dependencies' => array(
        'cron' => BACKUP_MIGRATE_CRON_ELYSIA,
      ),
    );
    $form['cron_settings']['cron_schedule_settings']['cron_schedule'] = array(
      "#type" => "textfield",
      "#title" => t('Cron Schedule'),
      '#length' => 10,
      "#description" => t('Specify the frequency of the schedule using standard cron notation. For more information see the !elysiareadme.', array('!elysiareadme' => l(t('the Elysia Cron README'), 'http://drupalcode.org/project/elysia_cron.git/blob/refs/heads/7.x-1.x:/README.txt'))),
      "#default_value" => $this->get('cron_schedule'),
      '#parents' => array('cron_schedule'),
    );

    $form['cron_settings']['cron_none'] = array(
      "#type" => "radio",
      "#title" => t('Do not run automatically'),
      '#return_value' => 'none',
      "#description" => t('Do not run this schedule automatically. You can still run it using !drush.', array('!drush' => l(t('Drush'), 'http://drupal.org/project/drush'))),
      "#default_value" => $cron ? $cron : BACKUP_MIGRATE_CRON_BUILTIN,
      '#parents' => array('cron'),
    );

    $keep = $this->get('keep');
    $form['delete'] = array(
      '#type' => 'checkbox',
      '#default_value' => $keep != 0,
      '#title' => t('Automatically delete old backups'),
    );
    $form['delete_settings'] = array(
      '#type' => 'backup_migrate_dependent',
      '#dependencies' => array(
        'delete' => TRUE,
      ),
    );

    $form['delete_settings']['smartdelete'] = array(
      "#type" => "radio",
      "#title" => t('Smart Delete'),
      '#return_value' => BACKUP_MIGRATE_SMART_DELETE,
      "#description" => t('Keep !keep. <strong>Recommended</strong>', array('!keep' => $this->generate_keep_description(BACKUP_MIGRATE_SMART_DELETE, FALSE))),
      "#default_value" => $keep ? $keep : BACKUP_MIGRATE_SMART_DELETE,
      '#parents' => array('deletetype'),
    );
    $form['delete_settings']['smartdelete_keep_settings'] = array(
      '#type' => 'backup_migrate_dependent',
      '#dependencies' => array(
        'deletetype' => BACKUP_MIGRATE_SMART_DELETE,
      ),
    );
    $form['delete_settings']['smartdelete_keep_settings']['keep_hourly'] = array(
      "#type" => "textfield",
      "#title" => t('Number of Hourly Backup files to Keep'),
      '#length' => 20,
      "#description" => t('Keep a specified number of hourly backups before deleting the oldest ones.'),
      "#default_value" => variable_get('backup_migrate_smart_keep_hourly', BACKUP_MIGRATE_SMART_KEEP_HOURLY),
    );
    $form['delete_settings']['smartdelete_keep_settings']['keep_daily'] = array(
      "#type" => "textfield",
      "#title" => t('Number of Daily Backup files to Keep'),
      '#length' => 20,
      "#description" => t('Keep a specified number of daily backups before deleting the oldest ones.'),
      "#default_value" => variable_get('backup_migrate_smart_keep_daily', BACKUP_MIGRATE_SMART_KEEP_DAILY),
    );
    $form['delete_settings']['smartdelete_keep_settings']['keep_weekly'] = array(
      "#type" => "textfield",
      "#title" => t('Number of Weekly Backup files to Keep'),
      '#length' => 20,
      "#description" => t('Keep a specified number of weekly backups before deleting the oldest ones.'),
      "#default_value" => variable_get('backup_migrate_smart_keep_weekly', BACKUP_MIGRATE_SMART_KEEP_WEEKLY),
    );

    $form['delete_settings']['standarddelete'] = array(
      "#type" => "radio",
      "#title" => t('Simple Delete'),
      '#return_value' => BACKUP_MIGRATE_STANDARD_DELETE,
      "#description" => t("Keep a specified number of files deleting the oldest ones first."),
      "#default_value" => $keep > 0 ? BACKUP_MIGRATE_STANDARD_DELETE : 0,
      '#parents' => array('deletetype'),
    );
    $form['delete_settings']['keep-settings'] = array(
      '#type' => 'backup_migrate_dependent',
      '#dependencies' => array(
        'deletetype' => BACKUP_MIGRATE_STANDARD_DELETE,
      ),
    );
    $form['delete_settings']['keep-settings']['keep'] = array(
      "#type" => "textfield",
      "#size" => 6,
      "#title" => t("Number of Backup files to keep"),
      "#description" => t("The number of backup files to keep before deleting old ones."),
      "#default_value" => $keep > 0 ? $keep : BACKUP_MIGRATE_KEEP_DEFAULT,
    );

    $form['destination'] = _backup_migrate_get_destination_pulldown('scheduled backup', $this->get('destination_id'), $this->get('copy_destination_id'));

    return $form;
  }

  /**
   * Submit the edit form.
   */
  public function edit_form_validate($form, &$form_state) {
    if (!is_numeric($form_state['values']['period']['number']) || $form_state['values']['period']['number'] <= 0) {
      form_set_error('period][number', t('Backup period must be a number greater than 0.'));
    }

    if (!$form_state['values']['delete']) {
      $form_state['values']['keep'] = 0;
    }
    elseif ($form_state['values']['deletetype'] == BACKUP_MIGRATE_SMART_DELETE) {
      $form_state['values']['keep'] = BACKUP_MIGRATE_SMART_DELETE;

      if (!is_numeric($form_state['values']['keep_hourly']) || $form_state['values']['keep_hourly'] < 0) {
        form_set_error('keep_hourly', t('Number to keep hourly must be an integer greater than or equal to 0.'));
      }
      elseif (!is_numeric($form_state['values']['keep_daily']) || $form_state['values']['keep_daily'] < 0) {
        form_set_error('keep_daily', t('Number to keep daily must be an integer greater than or equal to 0.'));
      }
      elseif (!is_numeric($form_state['values']['keep_weekly']) || $form_state['values']['keep_weekly'] < 0) {
        form_set_error('keep_weekly', t('Number to keep weekly must be an integer greater than or equal to 0.'));
      }
    }
    elseif (!is_numeric($form_state['values']['keep']) || $form_state['values']['keep'] <= 0) {
      form_set_error('keep', t('Number to keep must be a number greater than 0.'));
    }
    parent::edit_form_validate($form, $form_state);
  }

  /**
   * Submit the edit form.
   */
  public function edit_form_submit($form, &$form_state) {
    variable_set('backup_migrate_smart_keep_hourly', $form_state['values']['keep_hourly']);
    variable_set('backup_migrate_smart_keep_daily', $form_state['values']['keep_daily']);
    variable_set('backup_migrate_smart_keep_weekly', $form_state['values']['keep_weekly']);

    $periods = $this->frequency_periods();
    $period = $periods[$form_state['values']['period']['type']];
    $form_state['values']['period'] = $form_state['values']['period']['number'] * $period['seconds'];
    parent::edit_form_submit($form, $form_state);
  }

  /**
   * Get the period of the frequency (ie: seconds, minutes etc.).
   */
  public function get_frequency_period() {
    foreach (array_reverse($this->frequency_periods()) as $period) {
      if ($period['seconds'] && ($this->period % $period['seconds']) === 0) {
        return $period;
      }
    }
  }

  /**
   * Get a list of available backup periods. Only returns time periods which have a
   *  (reasonably) consistent number of seconds (ie: no months).
   */
  public function frequency_periods() {
    return array(
      'seconds' => array('type' => 'seconds', 'seconds' => 1, 'title' => t('Seconds'), 'singular' => t('Once a second'), 'plural' => t('Every @count seconds')),
      'minutes' => array('type' => 'minutes', 'seconds' => 60, 'title' => t('Minutes'), 'singular' => t('Once a minute'), 'plural' => t('Every @count minutes')),
      'hours' => array('type' => 'hours', 'seconds' => 3600, 'title' => t('Hours'), 'singular' => t('Once an hour'), 'plural' => t('Every @count hours')),
      'days' => array('type' => 'days', 'seconds' => 86400, 'title' => t('Days'), 'singular' => t('Once a day'), 'plural' => t('Every @count days')),
      'weeks' => array('type' => 'weeks', 'seconds' => 604800, 'title' => t('Weeks'), 'singular' => t('Once a week'), 'plural' => t('Every @count weeks')),
    );
  }

  /**
   * Get the message to send to the user when confirming the deletion of the item.
   */
  public function delete_confirm_message() {
    return t('Are you sure you want to delete the schedule %name? Backups made with this schedule will not be deleted.', array('%name' => $this->get('name')));
  }

  /**
   * Perform the cron action. Run the backup if enough time has elapsed.
   */
  public function cron() {
    $now = time();

    // Add a small negative buffer (1% of the entire period) to the time to account for slight difference in cron run length.
    $wait_time = $this->period - ($this->period * variable_get('backup_migrate_schedule_buffer', BACKUP_MIGRATE_SCHEDULE_BUFFER));

    $cron = $this->get('cron');
    if ($cron == BACKUP_MIGRATE_CRON_BUILTIN && $this->is_enabled() && ($now - $this->get('last_run')) >= $wait_time) {
      $this->run();
    }
  }

  /**
   * Run the actual schedule.
   */
  public function run() {
    // Clear cached profile data as it could have been altered by a previous
    // schedule run.
    drupal_static_reset('backup_migrate_get_profiles');

    if ($settings = $this->get_profile()) {
      $settings->source_id = $this->get('source_id');
      $settings->destination_id = $this->get('destination_ids');

      $this->update_last_run(time());
      backup_migrate_perform_backup($settings);
      $this->remove_expired_backups();
    }
    else {
      backup_migrate_backup_fail("Schedule '%schedule' could not be run because requires a profile which is missing.", array('%schedule' => $schedule->get_name()), $settings);
    }
  }

  /**
   * Set the last run time of a schedule to the given timestamp, or now if none specified.
   */
  public function update_last_run($timestamp = NULL) {
    if ($timestamp === NULL) {
      $timestamp = time();
    }
    variable_set('backup_migrate_schedule_last_run_' . $this->get('id'), $timestamp);
  }

  /**
   * Set the last run time of a schedule to the given timestamp, or now if none specified.
   */
  public function get_last_run() {
    return variable_get('backup_migrate_schedule_last_run_' . $this->get('id'), 0);
  }

  /**
   * Remove older backups keeping only the number specified by the aministrator.
   */
  public function remove_expired_backups() {
    require_once dirname(__FILE__) . '/destinations.inc';

    $num_to_keep = $this->keep;
    // If num to keep is not 0 (0 is infinity).
    foreach ((array) $this->get_destinations() as $destination) {
      if ($destination && $destination->op('delete') && $destination_files = $destination->list_files()) {
        if ($num_to_keep == BACKUP_MIGRATE_SMART_DELETE) {
          $this->smart_delete_backups(
            $destination,
            $destination_files,
            variable_get('backup_migrate_smart_keep_subhourly', BACKUP_MIGRATE_SMART_KEEP_SUBHOURLY),
            variable_get('backup_migrate_smart_keep_hourly', BACKUP_MIGRATE_SMART_KEEP_HOURLY),
            variable_get('backup_migrate_smart_keep_daily', BACKUP_MIGRATE_SMART_KEEP_DAILY),
            variable_get('backup_migrate_smart_keep_weekly', BACKUP_MIGRATE_SMART_KEEP_WEEKLY)
          );
        }
        elseif ($num_to_keep != BACKUP_MIGRATE_KEEP_ALL) {
          $this->delete_backups($destination, $destination_files, $num_to_keep);
        }
      }
    }
  }

  /**
   * Remove older backups keeping only the number specified by the aministrator.
   */
  public function delete_backups($destination, $files, $num_to_keep) {
    require_once dirname(__FILE__) . '/destinations.inc';

    $num_to_keep = $this->keep;

    // Sort the files by modified time.
    $i = 0;
    foreach ($files as $id => $file) {
      if ($file->is_recognized_type()) {
        $time = $file->info('filetime');
        $sorted[$id] = $time;
      }
    }
    asort($sorted);

    // If we are beyond our limit, remove as many as we need.
    $num_files = count($files);

    if ($num_files > $num_to_keep) {
      $num_to_delete = $num_files - $num_to_keep;
      // Delete from the start of the list (earliest).
      foreach ($sorted as $id => $time) {
        if (!$num_to_delete--) {
          break;
        }
        $destination->delete_file($id);
      }
    }
  }

  /**
   * Delete files keeping the specified number of hourly, daily, weekly and monthly backups.
   */
  public function smart_delete_backups($destination, $files, $keep_subhourly = 3600, $keep_hourly = 24, $keep_daily = 14, $keep_weekly = PHP_INT_MAX, $keep_monthly = PHP_INT_MAX) {
    // Each period must be an exact multiple of the next smallest period.
    $now = time();
    $periods = array(
      'subhourly' => array(
        'delta' => 1,
        'keep' => $keep_subhourly,
        'last_time' => 0,
        'files' => array(),
      ),
      'hourly' => array(
        'delta' => 60 * 60,
        'keep' => $keep_hourly,
        'last_time' => 0,
        'files' => array(),
      ),
      'daily' => array(
        'delta' => 60 * 60 * 24,
        'keep' => $keep_daily,
        'last_time' => 0,
        'files' => array(),
      ),
      'weekly' => array(
        'delta' => 60 * 60 * 24 * 7,
        'keep' => $keep_weekly,
        'last_time' => 0,
        'files' => array(),
      ),
      /*
      'monthly' => array(
        'delta' => 60*60*24*7*4,
        'keep' => $keep_monthly,
        'last_time' => 0,
        'files' => array(),
      ),
      */
    );

    $keep_files = $filetimes = $times = $groups = $sorted = $saved = array();
    foreach ($files as $id => $file) {
      if ($file->is_recognized_type()) {
        $time = $file->info('filetime');
        $sorted[$id] = $time;
      }
    }
    // Sort files, oldest first.
    asort($sorted);

    // Reset internal pointer and get the oldest file time.
    $oldest_file_time = reset($sorted);
    // Save the oldest file.
    $keep_files[key($sorted)] = key($sorted);

    foreach ($periods as $i => $period) {
      $period_keep_files = array();
      $time = $oldest_file_time;

      // Set time from which we start saving files.
      $period_start_time = $now - (($period['keep'] + 1) * $period['delta']);

      // Increase time to within one period time span of the period start
      // time. This keeps all the different period starts aligned.
      if ($time < $period_start_time) {
        $time += ((int) ceil(($period_start_time - $time) / $period['delta'])) * $period['delta'];
      }

      $file_id = $this->find_nearest_file($sorted, $time);

      do {
        $period_keep_files[$file_id] = $file_id;
        $last_file_id = $file_id;
        $time += $period['delta'];
        $file_id = $this->find_nearest_file($sorted, $time);
      } while ($time < $now);

      $keep_files = array_merge($keep_files, $period_keep_files);
    }

    // Do the delete.
    foreach ($files as $id => $file) {
      if (!isset($keep_files[$id])) {
        $destination->delete_file($file->file_id());
      }
    }
  }

  /**
   *
   */
  protected function find_nearest_file($files, $time) {
    $last_file_id = NULL;
    $last_file_time = NULL;

    foreach ($files as $id => $file_time) {
      if ($file_time >= $time) {
        if ($last_file_time == NULL) {
          return $id;
        }
        if ($file_time == $time) {
          return $id;
        }
        $time_to_prev = $time - $last_file_time;
        $time_to_next = $file_time - $time;
        if ($time_to_prev >= $time_to_next) {
          return $id;
        }
        else {
          return $last_file_id;
        }

        // Shouldn't hit this but you never know.
        break;
      }
      $last_file_id = $id;
      $last_file_time = $file_time;
    }
  }

}
