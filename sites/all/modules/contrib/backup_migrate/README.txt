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
* To backup to Amazon AWS S3 or compatible storage systems:
  - Download the most recent version of the required library from:
    https://github.com/tpyo/amazon-s3-php-class
    - Rename the unzipped folder to "s3-php5-curl".
  - Or clone it with command:
    git clone https://github.com/tpyo/amazon-s3-php-class.git s3-php5-curl
    - This should create a directory named "s3-php5-curl".
  - Place the directory inside the following directory: sites/all/libraries
  - The library path should be "sites/all/libraries/s3-php5-curl/S3.php".

  Note: The most recent version of the library known to work is 0.5.1.


Notes about Amazon AWS S3
-------------------------------------------------------------------------------
The library does not support Amazon AWS S3 signature SigV4. This signature has
been required in all AWS S3 regions launched after 2013, and will also required
for new buckets created after June 24, 2020 in all regions.  For details, see:
https://aws.amazon.com/blogs/aws/amazon-s3-update-sigv2-deprecation-period-extended-modified/

This means that the choice of regions to back up to is limited.

Also see this issue:
https://www.drupal.org/project/backup_migrate/issues/3062823


Advanced settings
-------------------------------------------------------------------------------
Several advanced options are available from the Advanced Settings page:
* admin/config/system/backup_migrate/settings-advanced

These settings should be handled with care, it is recommended to leave them at
their defaults unless there is a specific need to modify them. See the "Known
problems and workarounds" section below for more information.


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
is imperative to test to see if the site's backup files are publicly
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

If the backup does not restore using either a graphical tool or the command line
tools, then it is likely corrupt; you may panic now.

MAKE SURE THAT THIS MODULE IS NOT THE ONLY FORM OF BACKUP.


Known problems and workarounds
-------------------------------------------------------------------------------
The module has options to help resolve issues, generate workarounds, and debug
problems by adding variables to the site's settings.php file, or making
adjustments to the same variables located in the Backup and Migrate Advanced
Settings page: admin/config/system/backup_migrate/settings-advanced

Common issues and adjustments include:

* Out-of-memory error

  If backup fails due to an out-of-memory, try adjusting the memory limit by
  modifying the "Memory Limit" setting in Advanced Settings or adding the
  "backup_migrate_memory_limit" variable to the site's settings.php file:

  // Backup & Migrate: Use 512MB when generating backups.
  $conf['backup_migrate_memory_limit'] = '512M';

  // Backup & Migrate: Use 1GB when generating backups.
  $conf['backup_migrate_memory_limit'] = '1G';

* PHP timeout error (MySQL server has gone away)

  If backups fail due to a PHP timeout error, especially an error saying "MySQL
  server has gone away", try adjusting the "Time Limit" setting in Advanced
  Settings, or use the "backup_migrate_backup_max_time" variable to adjust the
  timeout. Before doing this, check to see what PHP's "max_execution_time" is
  set to, then set the "backup_migrate_backup_max_time" variable to a higher
  number, e.g. if max_execution_time is 180 (seconds) try setting
  backup_migrate_backup_max_time to 240 seconds (4 minutes), or 300 seconds
  (5 minutes).

  // Backup & Migrate: Adjust the PHP timeout to 300 seconds (5 minutes).
  $conf['backup_migrate_backup_max_time'] = 300;

* Verbose logging

  A variable has been added which may help with problems. Enable "Verbose
  Output" in Advanced Settings, or set the variable "backup_migrate_verbose"
  to TRUE. This will make the module log additional messages to watchdog as
  the module performs certain actions.

  // Backup & Migrate: Log extra messages as the module is working.
  $conf['backup_migrate_verbose'] = TRUE;

* Disable cron

  It can be frustrating working from a production database backup on non-prod
  servers as scheduled backups will automatically run via cron the same as they
  run on production. The custom cron tasks can be disabled by enabling "Disable
  Cron" in Advanced Settings, or using the "backup_migrate_disable_cron"
  variable. Note: this doesn't prevent people from manually running backups via
  the UI or from the Drush commands, so it is safe to hardcode to TRUE on all
  site instances and then hardcode to FALSE on production environments.

  // Backup & Migrate: Don't run backups via cron.
  $conf['backup_migrate_disable_cron'] = TRUE;

* Control how MySQL data is processed

  There are three options to control how MySQL data is processed. Should a site
  have problems with memory limits, it is worth testing these to see which ones
  work best.

  - "Rows Per Query" in Advanced Settings, or
  - "backup_migrate_data_rows_per_query" variable in settings.php
    Controls how many records are loaded from the database at once. Defaults to
    "50000", i.e. 50,000 rows. Note that setting this to a high number can cause
    problems when exporting large data sets, e.g. cache tables can have huge
    volumes of data per record.

    // Backup & Migrate: Load 10,000 rows at once.
    $conf['backup_migrate_data_rows_per_query'] = 10000;

  - "Rows Per Line" in Advanced Settings, or
  - "backup_migrate_data_rows_per_line" variable in settings.php
    Controls how many records are included in a single INSERT statement.
    Defaults to "10", i.e. 10 records.

    // Backup & Migrate: Combine no more than five records in a single row.
    $conf['backup_migrate_data_rows_per_line'] = 5;

  - "Data Bytes Per Line" in Advanced Settings, or
  - "backup_migrate_data_bytes_per_line" variable in settings.php
    Controls how much data will be inserted at once using a single INSERT
    statement. This works with the "backup_migrate_data_rows_per_line" variable
    to ensure that each INSERT statement doesn't end up being too large.
    Defaults to "2048", i.e. 2,048 bytes.

    // Backup & Migrate: Limit the output to 1000 bytes at a time.
    $conf['backup_migrate_data_bytes_per_line'] = 1000;


Development notes
--------------------------------------------------------------------------------
It is worth noting that some of the tests will fail when ran against nginx,
which is the default web server for some local development systems. As a result,
it is recommended to run tests on a server that uses Apache HTTPd Server instead
of nginx.


Credits / contact
--------------------------------------------------------------------------------
Currently maintained by Alex Andrascu [1], Damien McKenna [2] and
Daniel Pickering [3]. All original development up through 2015 was by
Ronan Dowling [4] with help by Drew Gorton [5].

The best way to contact the authors is to submit an issue, be it a support
request, a feature request or a bug report, in the project issue queue:
  https://www.drupal.org/project/issues/backup_migrate


References
--------------------------------------------------------------------------------
1: https://www.drupal.org/u/alex-andrascu
2: https://www.drupal.org/u/damienmckenna
3: https://www.drupal.org/u/ikit-claw
4: https://www.drupal.org/u/ronan
5: https://www.drupal.org/u/dgorton
