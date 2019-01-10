Backup and Migrate
------------------
This module makes the task of backing up a site's Drupal database, code and
all uploaded files and of migrating data from one Drupal install to another
easier.

Database backup files are a list of SQL statements which can be executed with a
tool such as phpMyAdmin or the command-line mysql client. File and code backup
files are tarballs which can be restored by extracting them to the desired
directory.


Installation
-------------------------------------------------------------------------------
* Put the module in the Drupal modules directory and enable it via
  admin/modules.
* Go to admin/people/permissions and grant permission to any roles that need to
  be able to backup or restore the database.
* Configure and use the module at admin/config/system/backup_migrate.

OPTIONAL:
* To drop all tables before import, expand "Advanced options" panel under the
  "Restore" and "Saved backups" tabs and tick the option.
* Enable token.module to allow token replacement in backup file names.
* To Backup to Amazon S3:
  - Download the most recent version from:
    https://github.com/tpyo/amazon-s3-php-class
  - Or clone it with command:
    git clone https://github.com/tpyo/amazon-s3-php-class.git s3-php5-curl
  - Rename the unzipped folder to s3-php5-curl

The most recent version of the library known to work is 0.5.1.


Additional requirements for LigHTTPd
-------------------------------------------------------------------------------
Add the following code to the lighttp.conf to secure the backup directories:
  $HTTP["url"] =~ "^/sites/default/files/backup_migrate/" {
    url.access-deny = ( "" )
  }
It may be necessary to adjust the path to reflect the actual path to the files.


Additional requirements for IIS 7
-------------------------------------------------------------------------------
Add the following code to the web.config code to secure the backup
directories:
<rule name="postinst-redirect" stopProcessing="true">
   <match url="sites/default/files/backup_migrate" />
   <action type="Rewrite" url=""/>
</rule>
It may also be necessary to adjust the path to reflect the actual path to the
files.


VERY IMPORTANT SECURITY NOTE
-------------------------------------------------------------------------------
Backup files may contain sensitive data and, by default, are saved to the web
server in a directory normally accessible by the public. This could lead to a
very serious security vulnerability. Backup and Migrate attempts to protect
backup files using a .htaccess file, but this is not guaranteed to work on all
environments (and is guaranteed to fail on web servers that are not Apache). It
is imperitive to test to see if the site's backup files are publicly
accessible, and if in doubt do not save backups to the server, or use the
destinations feature to save to a folder outside of the site's webroot.


Other warnings
-------------------------------------------------------------------------------
A failed restore can destroy the database and therefore the entire Drupal
installation. ALWAYS TEST BACKUP FILES ON A TEST ENVIRONMENT FIRST. If in doubt
do not use this module.

This module has only been tested with MySQL and does not work with any other
dbms. Assistance in adding support for other database systems would be
appreciated, see the issue queue for further details.

Make sure the PHP timeout is set high enough to complete a backup or restore
operation. Larger databases require more time. Also, while the module attempts
to keep memory needs to a minimum, a backup or restore will require
significantly more memory than most Drupal operations.

If the backup file contains the 'sessions' table all other users will be logged
out after running a restore. To avoid this, exclude the sessions table when
creating the backups. Be aware though that this table is still required to run
Drupal, so it will need to be recreated if the backup is restored onto an empty
database.

Do not change the file extension of backup files or the restore function will be
unable to determine the compression type of the file and will not function
correctly.

The module's permissions should only be given to trusted users due to the
inherent security vulnerabilities in allowing people access to a site's database
and/or files backups.


If a restore fails
-------------------------------------------------------------------------------
Don't panic!

The restore file should still work with phpMyAdmin's import function or with
the mysql command line tool.

If the backup does not restore using either a graphical tool or the command line tools, then it is likely corrupt; you may panic now.

MAKE SURE THAT THIS MODULE IS NOT THE ONLY FORM OF BACKUP.


Known problems and workarounds
-------------------------------------------------------------------------------
* If backups fail due to an out-of-memory, try adjusting the memory limit using
  the "backup_migrate_memory_limit" variable by adding one of these lines
  to the site's settings.php file:

  // Backup & Migrate: Use 512MB when generating backups.
  $conf['backup_migrate_memory_limit'] = '512M';

  // Backup & Migrate: Use 1GB when generating backups.
  $conf['backup_migrate_memory_limit'] = '1G';

* If backups fail due to a PHP timeout error, especially an error saying "MySQL
  server has gone away", use the "backup_migrate_backup_max_time" variable to
  adjust the timeout. Before doing this, check to see what PHP's
  "max_execution_time" is set to, then set the "backup_migrate_backup_max_time"
  variale to a higher number, e.g. if max_execution_time is 180 (seconds) try
  setting backup_migrate_backup_max_time to 240 seconds / 4 minutes, or 300
  seconds / 5 minutes

  // Backup & Migrate: Adjust the PHP timeout to 5 minutes / 300 seconds.
  $conf['backup_migrate_backup_max_time'] = 300;

* A variable has been added which may help with problems. Setting the variable
  'backup_migrate_verbose' to TRUE will make the module log additional messages
  to watchdog as the module performs certain actions.

  // Backup & Migrate: Log extra messages as the module is working.
  $conf['backup_migrate_verbose'] = TRUE;

* It can be frustrating working from a production database backup on non-prod
  servers as schduled backups will automatically run via cron the same as they
  run on production. The custom cron tasks may be disabled using the
  "backup_migrate_disable_cron" variable. Note: this doesn't prevent people
  from manually running backups via the UI or from the Drush commands, so it is
  safe to hardcode to TRUE on all site instances and then hardcode to FALSE on
  production environments.

  // Backup & Migrate: Don't run backups via cron.
  $conf['backup_migrate_disable_cron'] = TRUE;

* There are three different variables that control how MySQL data is processed.
  Should a site have problems with memory limits, it is worth testing these to
  see which ones work the best.

  - backup_migrate_data_rows_per_query
    Controls how many records are loaded from the database at once. Defaults to
    "1000", i.e. 1,000 rows. Note that setting this to a high number can cause
    problems when exporting large data sets, e.g. cache tables can have huge
    volumes of data per record.

    // Backup & Migrate: Load 10,000 rows at once.
    $conf['backup_migrate_data_rows_per_query'] = 10000;

  - backup_migrate_data_rows_per_line
    Controls how many records are included in a single INSERT statement.
    Defaults to "30", i.e. 30 records.

    // Backup & Migrate: Combine no more than five records in a single row.
    $conf['backup_migrate_data_rows_per_line'] = 5;

  - backup_migrate_data_bytes_per_line
    Controls how much data will be inserted at once using a single INSERT
    statement. This works with the "backup_migrate_data_rows_per_line" variable
    to ensure that each INSERT statement doesn't end up being too large.
    Defaults to "2000", i.e. 2,000 bytes.

    // Backup & Migrate: Limit the output to 1000 bytes at a time.
    $conf['backup_migrate_data_bytes_per_line'] = 1000;


Credits / contact
--------------------------------------------------------------------------------
Currently maintained by Alex Andrascu [1], Damien McKenna [1] and Daniel Pickering [3]. All original development up through 2015 was by Ronan Dowling [4]
with help by Drew Gorton [5].

The best way to contact the authors is to submit an issue, be it a support
request, a feature request or a bug report, in the project issue queue:
  https://www.drupal.org/project/issues/backup_migrate


References
--------------------------------------------------------------------------------
1: https://www.drupal.org/u/damienmckenna
2: https://www.drupal.org/u/alex-andrascu
3: https://www.drupal.org/u/ikit-claw
4: https://www.drupal.org/u/ronan
5: https://www.drupal.org/u/dgorton