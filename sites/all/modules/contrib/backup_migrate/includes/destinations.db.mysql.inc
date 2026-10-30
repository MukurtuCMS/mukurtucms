<?php

/**
 * @file
 */

require_once dirname(__FILE__) . '/destinations.db.inc';

/**
 * @file
 * Functions to handle the direct to database destination.
 */

/**
 * A destination type for saving to a database server.
 *
 * @ingroup backup_migrate_destinations
 */
class backup_migrate_destination_db_mysql extends backup_migrate_destination_db {

  /**
   * The table's data keyed by table name.
   *
   * @var array
   */
  protected static $tableData = array();

  /**
   * The tables keyed by name.
   *
   * @var array
   */
  protected static $tableNames = array();

  /**
   * The views keyed by name.
   *
   * @var array
   */
  protected static $viewNames = array();

  /**
   *
   */
  public function type_name() {
    return t("MySQL Database");
  }

  /**
   * Return a list of backup filetypes.
   */
  public function file_types() {
    return array(
      "sql" => array(
        "extension" => "sql",
        "filemime" => "text/x-sql",
        "backup" => TRUE,
        "restore" => TRUE,
      ),
      "mysql" => array(
        "extension" => "mysql",
        "filemime" => "text/x-sql",
        "backup" => TRUE,
        "restore" => TRUE,
      ),
    );
  }

  /**
   * Declare any mysql databases defined in the settings.php file as a possible destination.
   */
  public function destinations() {
    $out = array();
    global $databases;
    foreach ((array) $databases as $db_key => $target) {
      foreach ((array) $target as $tgt_key => $info) {
        // Only mysql/mysqli supported by this destination.
        $key = $db_key . ':' . $tgt_key;
        if ($info['driver'] === 'mysql') {
          // Compile the database connection string.
          $url = 'mysql://';
          $url .= urlencode($info['username']) . ':' . urlencode($info['password']);
          $url .= '@';
          $url .= urlencode($info['host']);
          if (!empty($info['port'])) {
            $url .= ':' . $info['port'];
          }
          $url .= '/' . urlencode($info['database']);

          if ($destination = backup_migrate_create_destination('mysql', array('url' => $url))) {
            // Treat the default database differently because it is probably
            // the only one available.
            if ($key == 'default:default') {
              $destination->set_id('db');
              $destination->set_name(t('Default Database'));
              // Dissalow backing up to the default database because that's confusing and potentially dangerous.
              $destination->remove_op('scheduled backup');
              $destination->remove_op('manual backup');
            }
            else {
              $destination->set_id('db:' . $key);
              $destination->set_name($key . ": " . $destination->get_display_location());
            }
            $out[$destination->get_id()] = $destination;
          }
        }
      }
    }
    return $out;
  }

  /**
   * Get the file type for to backup this destination to.
   */
  public function get_file_type_id() {
    return 'mysql';
  }

  /**
   * Get the form for the backup settings for this destination.
   */
  public function backup_settings_form($settings) {
    $form = parent::backup_settings_form($settings);

    $form['use_mysqldump'] = array(
      "#type" => "checkbox",
      "#title" => t("Use mysqldump command"),
      "#default_value" => !empty($settings['use_mysqldump']),
      "#description" => t("Use the mysqldump command line tool if available. This can be faster for large databases but will not work on all servers. Also exporting SQL views is not really solid with this option. EXPERIMENTAL"),
    );

    return $form;
  }

  /**
   * Backup the databases to a file.
   *
   *  Returns a list of sql commands, one command per line.
   *  That makes it easier to import without loading the whole file into memory.
   *  The files are a little harder to read, but human-readability is not a priority.
   */
  public function _backup_db_to_file($file, $settings) {
    if (!empty($settings->filters['use_mysqldump']) && $this->_backup_db_to_file_mysqldump($file, $settings)) {
      return TRUE;
    }

    $lines = 0;
    $exclude = !empty($settings->filters['exclude_tables']) ? $settings->filters['exclude_tables'] : array();
    $nodata = !empty($settings->filters['nodata_tables']) ? $settings->filters['nodata_tables'] : array();
    if ($file->open(TRUE)) {
      $file->write($this->_get_sql_file_header());
      $alltables = $this->_get_tables();
      $allviews = $this->_get_views();

      foreach ($alltables as $table) {
        if (_backup_migrate_check_timeout()) {
          return FALSE;
        }
        if ($table['name'] && !isset($exclude[$table['name']])) {
          $file->write($this->_get_table_structure_sql($table));
          $lines++;
          if (!in_array($table['name'], $nodata)) {
            $lines += $this->_dump_table_data_sql_to_file($file, $table);
          }
        }
      }
      foreach ($allviews as $view) {
        if (_backup_migrate_check_timeout()) {
          return FALSE;
        }
        if ($view['name'] && !isset($exclude[$view['name']])) {
          $file->write($this->_get_view_create_sql($view));
        }

      }
      $file->write($this->_get_sql_file_footer());
      $file->close();
      return $lines;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Backup the databases to a file using the mysqldump command.
   */
  public function _backup_db_to_file_mysqldump($file, $settings) {
    $success = FALSE;
    $nodata_tables = array();
    $alltables = $this->_get_tables();

    $command = 'mysqldump --result-file=%file --opt -Q --host=%host --port=%port --user=%user --password=%pass %db';
    $args = array(
      '%file' => $file->filepath(),
      '%host' => $this->dest_url['host'],
      '%port' => !empty($this->dest_url['port']) ? $this->dest_url['port'] : '3306',
      '%user' => $this->dest_url['user'],
      '%pass' => $this->dest_url['pass'],
      '%db' => $this->dest_url['path'],
    );

    // Ignore the excluded and no-data tables.
    $db = $this->dest_url['path'];
    if (!empty($settings->filters['exclude_tables'])) {
      foreach ((array) $settings->filters['exclude_tables'] as $table) {
        if (isset($alltables[$table])) {
          $command .= ' --ignore-table=' . $db . '.' . $table;
        }
      }
    }
    if (!empty($settings->filters['nodata_tables'])) {
      foreach ((array) $settings->filters['nodata_tables'] as $table) {
        if (isset($alltables[$table])) {
          $nodata_tables[] = $table;
          $command .= ' --ignore-table=' . $db . '.' . $table;
        }
      }
    }
    $success = backup_migrate_exec($command, $args);

    // Get the nodata tables.
    if ($success && !empty($nodata_tables)) {
      $tables = implode(' ', array_unique($nodata_tables));
      $command = "mysqldump --no-data --opt -Q --host=%host --port=%port --user=%user --password=%pass %db $tables >> %file";
      $success = backup_migrate_exec($command, $args);
    }
    return $success;
  }

  /**
   * Backup the databases to a file.
   */
  public function _restore_db_from_file($file, $settings) {
    $num = 0;

    if ($file->open() && $conn = $this->_get_db_connection()) {
      // Optionally drop all existing tables.
      if (!empty($settings->filters['utils_drop_all_tables'])) {
        $all_tables = $this->_get_tables();
        $table_names = array_map('backup_migrate_array_name_value', $all_tables);
        $table_list = join(', ', $table_names);
        $stmt = $conn->prepare("DROP TABLE IF EXISTS $table_list;\n");
        $stmt->execute();
      }

      // Read one line at a time and run the query.
      while ($line = $this->_read_sql_command_from_file($file)) {
        if (_backup_migrate_check_timeout()) {
          return FALSE;
        }
        if ($line) {
          // Prepeare and exexute the statement instead of the api function to avoid substitution of '{' etc.
          $stmt = $conn->prepare($line);
          $stmt->execute();
          $num++;
        }
      }
      // Close the file with fclose/gzclose.
      $file->close();
    }
    else {
      drupal_set_message(t("Unable to open file %file to restore database", array("%file" => $file->filepath())), 'error');
      $num = FALSE;
    }
    return $num;
  }

  /**
   * Read a multiline sql command from a file.
   *
   * Supports the formatting created by mysqldump, but won't handle multiline comments.
   */
  public function _read_sql_command_from_file($file) {
    $out = '';
    while ($line = $file->read()) {
      $first2 = substr($line, 0, 2);
      $first3 = substr($line, 0, 3);

      // Ignore single line comments. This function doesn't support multiline comments or inline comments.
      if ($first2 != '--' && ($first2 != '/*' || $first3 == '/*!')) {
        $out .= ' ' . trim($line);
        // If a line ends in ; or */ it is a sql command.
        if (substr($out, strlen($out) - 1, 1) == ';') {
          return trim($out);
        }
      }
    }
    return trim($out);
  }

  /**
   * Get a list of tables in the database.
   */
  public function _get_table_names() {
    if (empty(static::$tableNames)) {
      static::$tableNames = $this->query("SHOW FULL TABLES WHERE Table_Type = 'BASE TABLE'")
        ->fetchAllKeyed(0, 0);
    }

    return static::$tableNames;
  }

  /**
   * Get a list of views in the database.
   */
  public function _get_view_names() {
    if (empty(static::$viewNames)) {
      static::$viewNames = $this->query("SHOW FULL TABLES WHERE Table_Type = 'VIEW'")
        ->fetchAllKeyed(0, 0);
    }

    return static::$viewNames;
  }

  /**
   * Lock the list of given tables in the database.
   */
  public function _lock_tables($tables) {
    if ($tables) {
      $tables_escaped = array();
      foreach ($tables as $table) {
        $tables_escaped[] = '`' . db_escape_table($table) . '`  WRITE';
      }
      $this->query('LOCK TABLES ' . implode(', ', $tables_escaped));
    }
  }

  /**
   * Unlock all tables in the database.
   */
  public function _unlock_tables($settings) {
    $this->query('UNLOCK TABLES');
  }

  /**
   * Get a list of table and view data in the db.
   */
  protected function get_table_data() {
    if (empty(static::$tableData)) {
      $tables = $this->query('SHOW TABLE STATUS')
        ->fetchAll(PDO::FETCH_ASSOC);

      foreach ($tables as $table) {
        // Lowercase the keys because between Drupal 7.12 and 7.13/14 the
        // default query behavior was changed.
        // See: http://drupal.org/node/1171866
        $table = array_change_key_case($table);
        static::$tableData[$table['name']] = $table;
      }
    }

    return static::$tableData;
  }

  /**
   * Get a list of tables in the db.
   */
  public function _get_tables() {
    $out = array();
    foreach ($this->get_table_data() as $table) {
      if (!empty($table['engine'])) {
        $out[$table['name']] = $table;
      }
    }

    return $out;
  }

  /**
   * Get a list of views in the db.
   */
  public function _get_views() {
    $out = array();
    foreach ($this->get_table_data() as $table) {
      if (empty($table['engine'])) {
        $out[$table['name']] = $table;
      }
    }
    return $out;
  }

  /**
   * Get the sql for the structure of the given table.
   */
  public function _get_table_structure_sql($table) {
    $out = "";
    $result = $this->query("SHOW CREATE TABLE `" . $table['name'] . "`", array(), array('fetch' => PDO::FETCH_ASSOC));
    foreach ($result as $create) {
      // Lowercase the keys because between Drupal 7.12 and 7.13/14 the default query behavior was changed.
      // See: http://drupal.org/node/1171866
      $create = array_change_key_case($create);
      $out .= "DROP TABLE IF EXISTS `" . $table['name'] . "`;\n";
      // Remove newlines and convert " to ` because PDO seems to convert those for some reason.
      $out .= strtr($create['create table'], array("\n" => ' ', '"' => '`'));
      if ($table['auto_increment']) {
        $out .= " AUTO_INCREMENT=" . $table['auto_increment'];
      }
      $out .= ";\n";
    }
    return $out;
  }

  /**
   * Get the sql for the structure of the given table.
   */
  public function _get_view_create_sql($view) {
    $out = "";
    // Switch SQL mode to get rid of "CREATE ALGORITHM..." what requires more permissions + troubles with the DEFINER user.
    $sql_mode = $this->query("SELECT @@SESSION.sql_mode")->fetchField();
    $this->query("SET sql_mode = 'ANSI'");
    $result = $this->query("SHOW CREATE VIEW `" . $view['name'] . "`", array(), array('fetch' => PDO::FETCH_ASSOC));
    $this->query("SET SQL_mode = :mode", array(':mode' => $sql_mode));
    foreach ($result as $create) {
      $out .= "DROP VIEW IF EXISTS `" . $view['name'] . "`;\n";
      $out .= "SET sql_mode = 'ANSI';\n";
      $out .= strtr($create['Create View'], "\n", " ") . ";\n";
      $out .= "SET sql_mode = '$sql_mode';\n";
    }
    return $out;
  }

  /**
   * Get the sql to insert the data for a given table.
   */
  public function _dump_table_data_sql_to_file($file, $table) {
    $rows_per_query = variable_get('backup_migrate_data_rows_per_query', BACKUP_MIGRATE_DATA_ROWS_PER_QUERY);
    $rows_per_line = variable_get('backup_migrate_data_rows_per_line', BACKUP_MIGRATE_DATA_ROWS_PER_LINE);
    $bytes_per_line = variable_get('backup_migrate_data_bytes_per_line', BACKUP_MIGRATE_DATA_BYTES_PER_LINE);

    if (variable_get('backup_migrate_verbose')) {
      _backup_migrate_message('Table: %table', array('%table' => $table['name']), 'success');
    }

    // Escape backslashes, PHP code, special chars.
    $search = array('\\', "'", "\x00", "\x0a", "\x0d", "\x1a");
    $replace = array('\\\\', "''", '\0', '\n', '\r', '\Z');

    $lines = 0;
    $from = 0;
    $args = array('fetch' => PDO::FETCH_ASSOC);
    while ($data = $this->query("SELECT * FROM `" . $table['name'] . "`", array(), $args, $from, $rows_per_query)) {
      if ($data->rowCount() == 0) {
        break;
      }

      $rows = $bytes = 0;

      $line = array();
      foreach ($data as $row) {
        $from++;

        // DB Escape the values.
        $items = array();
        foreach ($row as $key => $value) {
          $items[] = is_null($value) ? "null" : "'" . str_replace($search, $replace, $value) . "'";
        }

        // If there is a row to be added.
        if ($items) {
          // Start a new line if we need to.
          if ($rows == 0) {
            $file->write("INSERT INTO `" . $table['name'] . "` VALUES ");
            $bytes = $rows = 0;
          }
          // Otherwise add a comma to end the previous entry.
          else {
            $file->write(",");
          }

          // Write the data itself.
          $sql = implode(',', $items);
          $file->write('(' . $sql . ')');
          $bytes += strlen($sql);
          $rows++;

          // Finish the last line if we've added enough items.
          if ($rows >= $rows_per_line || $bytes >= $bytes_per_line) {
            $file->write(";\n");
            $lines++;
            $bytes = $rows = 0;
          }
        }
      }

      // Finish any unfinished insert statements.
      if ($rows > 0) {
        $file->write(";\n");
        $lines++;
      }
    }

    if (variable_get('backup_migrate_verbose')) {
      _backup_migrate_message('Peak memory usage: %mem', array('%mem' => backup_migrate_get_peak_memory_usage() . 'MB'), 'success');
    }

    return $lines;
  }

  /**
   * Get the db connection for the specified db.
   */
  public function _get_db_connection() {
    if (!$this->connection) {
      $this->connection = parent::_get_db_connection();
    }
    return $this->connection;
  }

  /**
   * Run a query on this destination's database using Drupal's MySQL engine.
   *
   * @param string $query
   *   The query string.
   * @param array $args
   *   Arguments for the query.
   * @param array $options
   *   Options to pass to the query.
   * @param int|null $from
   *   The starting point for the query; when passed will perform a queryRange()
   *   method instead of a regular query().
   * @param int|null $count
   *   The number of records to obtain from this query. Will be ignored if the
   *   $from argument is empty.
   *
   * @see DatabaseConnection_mysql::query()
   * @see DatabaseConnection_mysql::queryRange()
   */
  public function query($query, array $args = array(), array $options = array(), $from = NULL, $count = NULL) {
    if ($conn = $this->_get_db_connection()) {
      // If no $from is passed in, just do a basic query.
      if (is_null($from)) {
        return $conn->query($query, $args, $options);
      }
      // The $from variable was passed in, so do a ranged query.
      else {
        return $conn->queryRange($query, $from, $count, $args, $options);
      }
    }
  }

  /**
   * The header for the top of the sql dump file. These commands set the connection
   *  character encoding to help prevent encoding conversion issues.
   */
  public function _get_sql_file_header() {
    return "/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE=NO_AUTO_VALUE_ON_ZERO */;

SET NAMES utf8mb4;

";
  }

  /**
   * The footer of the sql dump file.
   */
  public function _get_sql_file_footer() {
    return "

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
";
  }

}
