# Mukurtu CMS 3.0.7
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
  * [Local Testing & Evaluation using DDEV](#ddev)
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
Most commercial web hosting companies will be able to host a Mukurtu CMS site. Look for support for Drupal 7. Reclaim Hosting (http://reclaimhosting.com) has a simple one-step install option for Mukurtu CMS.

#### <a name="self-hosted"></a>Self-Hosted
Mukurtu CMS is available as an open source distribution through https://github.com/MukurtuCMS/mukurtucms to run on a local server or install on your preferred web platform.

##### <a name="system-requirements"></a>System Requirements
Mukurtu CMS is built using Drupal 7 and has all of the same [minimum system requirements](https://www.drupal.org/docs/7/system-requirements). This includes:
* A web server with PHP support, such as Apache or nginx.
* [PHP](http://www.php.net/) version 7.4 or 8.0/8.1. Note: If using PHP 8, it is recommended to disable deprecation warnings in `error_reporting`.
* A database server such as [MySQL](http://www.mysql.com/) or [MariaDb](https://mariadb.org/)

##### <a name="installation"></a>Installation
Mukurtu CMS is built on Drupal 7 and can be installed in exactly the same way. Drupal 7 is included with Mukurtu CMS, it is not necessary to download and install Drupal 7 separately. Instructions on how to install Drupal 7 for in your environment are directly applicable to installing Mukurtu CMS, simply download the Mukurtu CMS code repository in place of Drupal 7. More detailed installation information can be found in INSTALL.txt in the same directory as this document or online at [Installing Drupal 7](https://www.drupal.org/docs/7/install). It is highly recommended to use git to download Mukurtu CMS rather than downloading files directly (e.g., the zip package). It will make the process of updating the application files much easier in the future.

##### Configuration and Post-installation Steps
* Review the recommended settings for PHP and more [here](https://github.com/MukurtuCMS/mukurtucms/wiki/Quick-Installation-Information-for-Experienced-Drupal-Admins).
* Configure the Drupal private file path. This is critical. Cultural protocols will not function as expected if you skip this step. You can read the official [information about the Drupal private path](https://www.drupal.org/docs/7/core/modules/file/overview). The basic steps are as follows.
  * Create a new directory, ideally outside of your web root, for private files to be stored. This will be where your users' uploaded media and files will reside.
  * The web server user will need read and write access to this directory.
  * Edit `sites/default/settings.php` and add the path of your new private files directory to the `file_private_path` setting. If you do not yet have a `settings.php` file, you can copy and rename `default.settings.php` to use as a starting point.
* Set the 'database', 'username', and 'password' values to match your database configuration.
* Once your site is installed, configure cron at `/admin/config/system/cron`.

##### <a name="upgrading"></a>Upgrading

If you are using a vendor hosted solution (such as Reclaim Hosting), check their support documentation before upgrading. Some vendors provide automated Mukurtu CMS upgrades via the control panel.

If you are self-hosting Mukurtu CMS, it is best to update the application files using git. Updates to Drupal 7 and contributed modules are included in each Mukurtu CMS release, and in general you should not attempt to update individual modules yourself outside of official Mukurtu releases. Update steps can be found in the [release notes](https://github.com/MukurtuCMS/mukurtucms/blob/master/VERSION.md), but in general upgrades should be done as follows:

* In a terminal, navigate to the directory you have Mukurtu CMS installed at.
* Retrieve the most recent files using git.
```
git pull
```
* Run any database updates. You can use drush for this. Installation instructions for drush can be found at http://docs.drush.org/en/master/install/. You can also do this step via the web interface by visiting `/update.php` on your site. Repeat this step until there are no more database upgrades available.
 ```
 drush updb -y
 ```
* Some updates will require you to revert some or all features. Features package Mukurtu CMS specific configuration as code for distribution. Reverting a feature will reset it to match the current Mukurtu CMS configuration. Check each version's release notes for specific notes on which features need to be reverted, but as an example here is how you could revert all features:
```
drush fra -y
```
* Aspects of some releases may not take effect until you clear the caches. Note that a full cache clear can cause temporary performance issues on larger sites as the cache is rebuilt.
```
drush cc all
```


### <a name="ddev"></a>Local Testing & Evaluation using DDEV
Mukurtu CMS can be installed locally using [DDEV](https://ddev.com/).
* Download and install [DDEV](https://github.com/drud/ddev), following the instructions for your operating system.
* Open a terminal and clone the Mukurtu CMS repository to a new directory.
```
git clone https://github.com/MukurtuCMS/mukurtucms.git my-mukurtu-site
```
* Change into that directory, replacing 'my-mukurtu-site' with whatever you used in the above step.
```
cd my-mukurtu-site
```
* Initialize the ddev project. Follow the prompts for Drupal 7 and use the current directory as the docroot.
```
ddev config
```
* Start ddev:
```
ddev start
```
* Launch your new ddev project:
```
ddev launch
```
* You should now see the Mukurtu CMS installer, ready for you to use. Follow the form's instructions.
* When you are done, you can stop the ddev instance with:
```
ddev stop
```

### <a name="developers"></a>Developers

Check the [Mukurtu CMS Wiki](https://github.com/MukurtuCMS/mukurtucms/wiki) for the most recent information.

#### <a name="code-contributing"></a>Contributing Code to Mukurtu
Mukurtu CMS is a distribution of Drupal. You can join Mukurtu’s developer community by [forking Mukurtu CMS](https://github.com/mukurtucms/mukurtucms) on GitHub.
Mukurtu Core is maintained by the [Center for Digital Scholarship and Curation (CDSC)](http://cdsc.libraries.wsu.edu) at Washington State University. Any pull requests will be reviewed and tested before acceptance by a core committer.

### <a name="bug-reports"></a>Bug Reports and Feature Requests
Please use the GitHub [issue tracker](https://github.com/MukurtuCMS/mukurtucms/issues) for reporting all bugs and features.
