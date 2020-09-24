# Mukurtu CMS 2.1.5
### [Release Notes](VERSION.md)

## Contents
* [What is Mukurtu?](#whatis)
* [License](#license)
* [Availability](#availability)
  * [Vendor Hosted](#vendor-hosted)
  * [Self-Hosted](#self-hosted)
    * [System Requirements](#system-requirements)
    * [Installation](#installation)
    * [Upgrading](#upgrading)
* [Developers](#developers)
  * [Contributing Code to Mukurtu](#code-contributing)
* [Bug Reports](#bug-reports)

### <a name="whatis"></a>What is Mukurtu?
##### Mukurtu CMS Provides:

* Local cultural protocols to provide granular access parameters for digital heritage content
* Extended metadata fields alongside Dublin Core
* Supports community engagement through multiple records for individual items
* An innovative set of Traditional Knowledge Labels that work with traditional copyright and Creative Commons licenses to better serve Indigenous needs
* A safe, secure, free and open source platform for managing digital cultural heritage materials

### <a name="license"></a>License

Mukurtu is distributed under the terms of the GNU General Public License (or "GPL"), which means anyone is free to download it and share it with others. This open development model means that people are constantly working to make sure Mukurtu is a cutting-edge platform that supports the unique needs of indigenous libraries, archives and museums as they seek to preserve and share their digital heritage. Mukurtu encourages collaboration and innovation as we seek to offer respectful and responsible models for content management.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

### <a name="availability"></a>Availability

#### <a name="vendor-hosted"></a> Vendor Hosted
Most commercial webhosting companies will be able to host a Mukurtu CMS site but Reclaim Hosting (http://reclaimhosting.com) has a simple one-step install option for Mukurtu CMS.

#### <a name="self-hosted"></a>Self-Hosted
Mukurtu CMS is available as an open source distribution through https://github.com/mukurtucms/mukurtucms to run on a local server or install on your preferred web platform.

To install on your own server, please find system requirements and installation procedures below.

##### <a name="system-requirements"></a>System Requirements
* A web server that supports PHP, such as Apache
* [PHP](http://www.php.net/) version 7.1 or 7.2. Mukurtu currently does not support PHP 7.3.
* A database server such as [MySQL 5.0.15 (or higher)](http://www.mysql.com/) or [MariaDb 5.1.44 (or higher)](https://mariadb.org/)

##### <a name="installation"></a>Installation
Mukurtu CMS is built on Drupal. More detailed installation information can be found in INSTALL.txt in the same directory as this document or on the [Drupal website](https://www.drupal.org/docs/7/install).

###### An Example Installation on Linux using the Apache HTTP Server
1. Create an Apache vhost for your domain
1. Clone the Mukurtu CMS Github repository: `git clone git@github.com:MukurtuCMS/mukurtucms.git`
1. Rename the created mukurtucms directory to the path you set for your vhost (or set your vhost path to this directory)
1. Navigate into your vhost directory, e.g.,: `cd mukurtucms`
1. Files permissions
 * Public files
    * This directory is already created at sites/default/files. However, you need to make sure it is writable by the Apache user (often 'apache' or 'www-data').
 * Private files
 * This directory does not yet exist. By default, Mukurtu CMS will look for the private files directory at `sites/default/files/private`. So you can create that directory. However, this is insecure (publicly-accessible) unless special measures are taken to secure it (beyond the scope of this document). A simpler method is to create a private files directory anywhere outside of your web root, and ensure it is readable and writable by the Apache user. Take note of this path as you will need it later.
1. Create an empty MySQL database
1. Create the settings.php file: `cp sites/default/default.settings.php sites/default/settings.php`
1. Edit the settings file you just created with a text editor. Near the bottom is the $databases array. At minimum, you will need to fill out 'database', 'username', and 'password' to connect to the database you just created.
1. Run the installation profile
 * Assuming your vhost and database are configured correctly, you can now launch the installation profile. Visit http://{your_domain}/install.php
 * The install script will run for 5-10 minutes, and will then present you with a form to fill out. Complete this form.
 * The install script will run for another 3-5 minutes. After this, you are provided with a link to the site. Click on it to ensure the profile installation was successful.
1. Set the private files path
 * Go to http://{your_domain}/admin/config/media/file-system
 * Fill "Private file system path" with the private files directory you created earlier.
1. Setup cron job
    * See https://www.drupal.org/cron for information on how to set up your cron job. Note automated cron is disabled by default in the Mukurtu CMS. You can enable it at http://{your_domain}/admin/config/system/cron.
1. Upload your site logo
    * Go to http://{your_domain}/admin/appearance/settings/mukurtu_starter
    * Click on "Logo Image Settings", and upload your logo in the field "Upload logo image", then click on "Save configuration"

##### <a name="upgrading"></a>Upgrading

If you are using a vendor hosted solution (such as Reclaim Hosting), check their support documentation before upgrading. Some vendors provide automated Mukurtu upgrades via the control panel.

Mukurtu upgrades are done via its Github repository. Knowing that important security updates are pushed to the Github repository in a timely manner, do not attempt to update either Drupal core or Drupal contributed modules internally -- they could cause system breakage. Upgrades should be done as follows:

1. Login to your server and navigate to your site root mukurtu htdocs directory.
1. Update your repository: `git pull`
1. Ensure that Drush is installed. See http://docs.drush.org/en/master/install/
1. Run the database updates: `drush updb -y`
1. Revert all features, then clear the cache, and revert again: `drush fra -y ; drush cc all ; drush fra -y`
1. Check for feature overrides (there should not be any): `drush fd`
1. Determine your site's current version by looking at the VERSION.md file in the site root, or within the Support block of the Dashboard when logged into your site as a Mukurtu Administrator. In the [release notes](VERSION.md), check for a subsection named "Manual Upgrade Steps" for each version newer than what your site is running. If there are any, run these steps now. All command line steps should be run from the site root.
  * Steps within each release should be run in the order listed, but steps for older releases should be done prior to steps for newer releases. If the step appears more than once (e.g., in different release versions), it only needs to be completed once, at its newest release point (i.e., ignore it in the older release(s)).

### <a name="developers"></a>Developers

Check the [Mukurtu CMS Wiki](https://github.com/MukurtuCMS/mukurtucms/wiki) for the most recent information.

#### <a name="code-contributing"></a>Contributing Code to Mukurtu
Mukurtu CMS is a distribution of Drupal. You can join Mukurtu’s developer community by [forking Mukurtu CMS](https://github.com/mukurtucms/mukurtucms) on GitHub.
Mukurtu Core is maintained by the [Center for Digital Scholarship and Curation (CDSC)](http://cdsc.libraries.wsu.edu) at Washington State University. Any pull requests will be reviewed and tested before acceptance by a core committer.

### <a name="bug-reports"></a>Bug Reports and Feature Requests
Please use the GitHub [issue tracker](https://github.com/MukurtuCMS/mukurtucms/issues) for reporting all bugs and features.
