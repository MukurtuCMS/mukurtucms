# Mukurtu CMS 2.0.0

###Mukurtu CMS provides:

* Local cultural protocols to provide granular access parameters for digital heritage content;
* Flexible templates that adapt to various indigenous stakeholder needs;
* Traditional knowledge fields customizable for curating content alongside standard Dublin Core metadata fields;
* An innovative set of Traditional Knowledge Labels that work with traditional copyright and Creative Commons licenses to better serve Indigenous needs; and
* A safe, secure, free and open source platform for managing digital cultural heritage materials online and offline

### License

Mukurtu is distributed under the terms of the GNU General Public License (or "GPL"), which means anyone is free to download it and share it with others. This open development model means that people are constantly working to make sure Mukurtu is a cutting-edge platform that supports the unique needs of indigenous libraries, archives and museums as they seek to preserve and share their digital heritage. Mukurtu encourages collaboration and innovation as we seek to offer respectful and responsible models for content management.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

### Availability

#### Hosted through Mukurtu.net
Mukurtu is available through Mukurtu.net’s MAAS (Mukurtu as a service) for an out-of-the-box hosted Mukurtu CMS website that is completely yours. To get in touch with Mukurtu.net and check out our other services, including training and configuration, go to http://mukurtu.net. 

#### Self - Hosted
Mukurtu CMS is available as an open source distribution through Github.com/mukurtucms/mukurtucms to run on a local server or install on your preferred web platform.

To install on your own server, please find system requirements and installation procedures belo.w
##### System Requirements
* [Apache 2.0 (or greater)](http://httpd.apache.org)
  * mod_rewrite module enabled
  * the ability to use local .htaccess files
* [PHP 5.2.4 (or greater)](http://www.php.net/)
* [MySQL 5.0.15 (or greater)](http://www.mysql.com/)

##### Installation 
Mukurtu CMS is built on Drupal. More detailed installation information can be found in INSTALL.txt in the same directory as this document.

1. Create an Apache vhost for your domain
1. Clone the Mukurtu CMS Github repository
        git clone git@github.com:MukurtuCMS/mukurtucms.git
1. Rename the created mukurtucms directory to the path you set for your vhost (or set your vhost path to this directory)
1. Navigate into your vhost directory, eg.
        cd mukurtucms
1. Files permissions
 * Public files
    * This directory is already created at sites/default/files. However, you need to make sure it is writable by the Apache user. One way of doing this would be:
            chmod a+w sites/default/files
 * Private files
    * This directory does not yet exist. By default, Mukurtu CMS will look for the private files directory at `sites/default/files/private`. So you can create that directory. However, this is insecure (publicly-accessible) unless special measures are taken to secure it (beyond the scope of this document). A simpler method is to create a private files directory anywhere outside of your web root, and ensure it is readable and writable by the Apache user. Take note of this path as you will need it later.
1. Create an empty MySQL database
1. Create the settings.php file
        cp sites/default/default.settings.php sites/default/settings.php
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

### Developers

Mukurtu CMS is a distribution of Drupal. You can join Mukurtu’s developer community by [forking Mukurtu CMS](https://github.com/mukurtucms/mukurtucms) on GitHub.
Mukurtu Core is co-maintained by the [Center for Digital Scholarship and Curation (CDSC)](http://libraries.wsu.edu/cdsc) at Washington State University and the [Center for Digital Archaeology (CoDA)](http://codifi.org/). Any pull requests will be reviewed and tested before acceptance by a core committer.

### Bug Reports and Feature Requests
Please use the GitHub [issue tracker](https://github.com/MukurtuCMS/mukurtucms/issues) for reporting all bugs and features.

