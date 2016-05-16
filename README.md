# Mukurtu CMS 2.0.4
### [Release Notes] (VERSION.md)

## Contents
* [What is Mukurtu?] (#whatis)
* [License](#license)
* [Availability](#availability)
  * [Hosted through Mukurtu.net] (#mukurtu-hosted)
  * [Self-Hosted] (#self-hosted)
    * [System Requirements] (#system-requirements)
    * [Installation] (#installation)
    * [Upgrading] (#upgrading)
* [Developers] (#developers)
  * [Contributing Code to Mukurtu] (#code-contributing)
  * [Code Overview] (#code-overview)
    * [Code Location] (#code-location)
    * [Features Overview] (#features-overview)
    * [Permissions] (#permissions)
    * [Scald] (#scald)
    * [Search API] (#search-api)
    * [Areas for Improvement] (#areas-improvement)
* [Bug Reports] (#bug-reports)

### <a name="whatis"></a>What is Mukurtu?
##### Mukurtu CMS Provides:

* Local cultural protocols to provide granular access parameters for digital heritage content;
* Flexible templates that adapt to various indigenous stakeholder needs;
* Traditional knowledge fields customizable for curating content alongside standard Dublin Core metadata fields;
* An innovative set of Traditional Knowledge Labels that work with traditional copyright and Creative Commons licenses to better serve Indigenous needs; and
* A safe, secure, free and open source platform for managing digital cultural heritage materials online and offline

### <a name="license"></a>License

Mukurtu is distributed under the terms of the GNU General Public License (or "GPL"), which means anyone is free to download it and share it with others. This open development model means that people are constantly working to make sure Mukurtu is a cutting-edge platform that supports the unique needs of indigenous libraries, archives and museums as they seek to preserve and share their digital heritage. Mukurtu encourages collaboration and innovation as we seek to offer respectful and responsible models for content management.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

### <a name="availability"></a>Availability

#### <a name="mukurtu-hosted">Hosted through Mukurtu.net
Mukurtu is available through Mukurtu.net’s MAAS (Mukurtu as a service) for an out-of-the-box hosted Mukurtu CMS website that is completely yours. To get in touch with Mukurtu.net and check out our other services, including training and configuration, go to http://mukurtu.net.

#### <a name="self-hosted"></a>Self-Hosted
Mukurtu CMS is available as an open source distribution through https://github.com/mukurtucms/mukurtucms to run on a local server or install on your preferred web platform.

To install on your own server, please find system requirements and installation procedures below.

##### <a name="system-requirements"></a>System Requirements
* [Apache 2.0 (or greater)](http://httpd.apache.org)
  * mod_rewrite module enabled
  * the ability to use local .htaccess files
* [PHP 5.2.4 (or greater)](http://www.php.net/)
* [MySQL 5.0.15 (or greater)](http://www.mysql.com/)

##### <a name="installation"></a>Installation
Mukurtu CMS is built on Drupal. More detailed installation information can be found in INSTALL.txt in the same directory as this document.

1. Create an Apache vhost for your domain
1. Clone the Mukurtu CMS Github repository: `git clone git@github.com:MukurtuCMS/mukurtucms.git`
1. Rename the created mukurtucms directory to the path you set for your vhost (or set your vhost path to this directory)
1. Navigate into your vhost directory, eg.: `cd mukurtucms`
1. Files permissions
 * Public files
    * This directory is already created at sites/default/files. However, you need to make sure it is writable by the Apache user. One way of doing this would be: `chmod a+w sites/default/files`
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

Mukurtu upgrades are done via its Github repository. Knowing that important security updates are pushed to the Github repository in a timely manner, do not attempt to update either Drupal core or Drupal contributed modules internally -- they could cause system breakage. Upgrades should be done as follows:

1. Login to your server and navigate to your site root mukurtu htdocs directory.
1. Update your repository: `git pull`
1. Ensure that Drush is installed. See http://docs.drush.org/en/master/install/
1. Run the database updates: `drush updb -y`
1. Revert all features, then clear the cache, and revert again: `drush fra -y && drush cc all && drush fra -y`
1. Check for feature overrides (there should not be any): `drush fd`
1. Determine your site's current version by looking at the VERSION.md file in the site root, or within the Support block of the Dashboard when logged into your site as a Mukurtu Administrator. In the [release notes] (VERSION.md), check for a subsection named "Manual Upgrade Steps" for each version newer than what your site is running. If there are any, run these steps now. All command line steps should be run from the site root.
  * Steps within each release should be run in the order listed, but steps for older releases should be done prior to steps for newer releases. If the step appears more than once (eg. in different release versions), it only needs to be completed once, at its newest release point (ie. ignore it in the older release(s)).

### <a name="developers"></a>Developers

#### <a name="code-contributing"></a>Contributing Code to Mukurtu
Mukurtu CMS is a distribution of Drupal. You can join Mukurtu’s developer community by [forking Mukurtu CMS](https://github.com/mukurtucms/mukurtucms) on GitHub.
Mukurtu Core is co-maintained by the [Center for Digital Scholarship and Curation (CDSC)](http://libraries.wsu.edu/cdsc) at Washington State University and the [Center for Digital Archaeology (CoDA)](http://codifi.org/). Any pull requests will be reviewed and tested before acceptance by a core committer.

#### <a name="code-overview"></a>Code Overview

##### <a name="code-location"></a>Code Location
All Mukurtu code (all code not from Drupal core and Drupal contributed modules) is organized as follows:
* sites/all/modules/custom/features
  * Features contain the heart of the Mukurtu code. Aside from feature components, features' module files contain custom code. If working on anything that changes feature components, note that this work will get lost when reverting features during site upgrades, unless you contribute your work to Github and it is accepted and merged into the master branch by the Mukurtu maintainers prior to your upgrade.
* sites/all/modules/custom (except for features)
  * There are several custom modules here not within features.
* profiles/mukurtu
  * The installation profile contains elements of the site that can be changed by individual sites that will, unlike features, be retained during site upgrades. For example, the front page block content is in here. Since the install profile only runs once, any changes to it only affect sites that do not yet exist. As such, the install profile should be used minimally, relying on features instead, though noting the limitation with features with respect to upgrades. Key work in the install profile should be done in mukurtu_install_tasks: https://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_install_tasks/7
* sites/all/themes/mukurtu_starter
  * This is the Mukurtu theme, which is a sub-theme of Bootstrap. All the CSS styling is done here, specifically in /sites/all/themes/mukurtu_starter/less/content.less. The LESS compiler is then run on this file to generate the CSS.
* sites/all/modules/contrib_patches
  * Whenever a contributed module is customized, a patch is generated (see https://www.drupal.org/patch). The patch is then moved to this directory, in a subdirectory named according to the contrib module. This way, when contrib modules are upgraded, any custom patches to it are readily found, at which point it is checked whether the patch is still necessary, and if so, it is reapplied.
  * Patches require more maintenance. Only use when necessary. If a hook can be be used instead of a patch, that is much preferred.
* core_patches
  * Everything regarding contributed module patches applies here.
  * Core patches are discouraged, moreso than with contrib patches. Only use when necessary.

##### <a name="features-overview"></a>Features Overview
* Drupal's Features module allows site configuration that would otherwise be in the database only to be stored in file content. This file content then becomes part of the Github rep. Thus, features should never have overridden components (except during development, ie. before a change is committed to a feature). As of writing, (Mukurtu 2.02) all enabled features are enabled for all client sites, ie. it is not intended for users to enable or disable features.
* In addition to feature components, the {feature_name}.module file for each feature can contain custom code which logically pertains to the functionality that that feature provides. Much of the Mukurtu code lives in these module files.

##### <a name="permissions"></a>Permissions
Permissions within Mukurtu happen on multiple levels. That said, the primary content type in Mukurtu is the Digital Heritage item, and the permission to view a Digital Heritage item depends on which Cultural Protocol(s) it belongs to. This is itself requires a multi-pronged approach, and is explained in the "HOW DIGITAL HERITAGE CULTURAL PROTOCOL PERMISSIONS ARE IMPLEMENTED" comment in mukurtu_protocol_field.module

##### <a name="scald"></a>Scald
* Mukurtu relies heavily on the Scald module. Understanding what this module does and how it works is important if developing anything to do with the media items in Mukurtu. See the module page at https://www.drupal.org/project/scald.
* As our use of Scald is highly customized, note we have a number of patches on Scald including the scald sub-modules. We recommend reviewing these patches, especially alter_atom_view.patch if working on search results views, prior to doing any scald development.

##### <a name="search-api"></a>Search API
The search/browse pages (Browse Digital Heritage, Browse Collections) are built using Search API with a Drupal database backend. As such, it will be easy to substitute the highly-performant Apache Solr for the Drupal database backend when sites need to scale up to handle hundreds of thousands of indexed items.

##### <a name="areas-improvement"></a>Areas for Improvement
* Remove legacy code from Mukurtu 1.0 and Mukurtu 1.5. These can still be seen in some unused modules in sites/all/modules/contrib, some unused modules in sites/all/modules/custom, and in some unused feature components (especially in ma_core, ma_base_theme, ma_media, ma_importexport_users, and ma_community_manage).
* ma_core and ma_base_theme should be merged into a single feature, dropping the legacy components. Possibly, certain components in this merged feature should go into other, more relevant features.
* ma_community_manage and ma_community should be merged into a single feature.
* Some of the contrib patches may already be rolled into development releases, in which case those modules should be upgraded and the patch removed.
* Other contrib patches have not been contributed back to their contrib modules because they are highly custom to Mukurtu. In particular, the patches on Scald will need attention when the inevitable upgrading of Scald occurs. The alter_atom_view.patch should be turned into a hook_field_formatter_view implementation if possible, though there were some issues with this originally.


### <a name="bug-reports"></a>Bug Reports and Feature Requests
Please use the GitHub [issue tracker](https://github.com/MukurtuCMS/mukurtucms/issues) for reporting all bugs and features.
