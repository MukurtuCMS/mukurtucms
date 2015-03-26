# MUKURTU
--------------------------------------------------------------------------------

# Changelog

## Release 1.5
- Front page app feature
- Simplified Batch Import
- Demo content examples available
- Services integration for Mukurtu Mobile
- Change site highlight color through theme interface
- Bug fixes (style, layout)
- Pantheon update
- Drupal upgrade & Security updates
- Contrib Module updates (all except Media & OG)
- updated mukurtu_clean.mysql database with settings for new modules & all patches


## Release 1.5 installation instructions
- Most of the features of Mukurtu are set in the codebase, except for some of the persistently difficult to integrate file display/display suite settings, some organic groups permissions, fitvids, the jQuery update to 1.8 settings. Like Release 1.0 there are patches to apply if you are installing from code. You are welcome to help us improve the installer to be totally pure, that's the goal. We recommend that if you are starting from scratch that you just use the clean install database.


## Manual upgrade instructions
- Update the code. The code is in the master branch, and also replicated in branch v.1.5.0. 
- Run update.php
- Enable modules: Mukurtu Front Page App, Mukurtu Batch Import, Mukurtu Services
- Ignore errors such as "Warning: Invalid argument supplied for foreach() in element_children() (line 6383 of /srv/bindings/5d4acf7490fd4455822a154ac1c0c4ea/code/includes/common.inc)."
You must enable the jCarousel, jQuery Update, FitVids, Services Views modules to install Mukurtu Services.
Would you like to continue with the above?
- Click Continue.

- Update to jQuery 1.8: /admin/config/development/jquery_update

- Add settings for FitVids -- /admin/config/media/fitvids

Paste this into Video Containers

.node.view-mode-full .oembed-video
.node .file-type-video
.frontpage-app .file-type-video
.frontpage-app .oembed-video


Check to see if there are any major features that need to be updated   /admin/structure/features

This depends on how you have configured your site. You should have taken notes about your configuration changes, you may want to replicate those changes depending on what changes you made. This effects changes to field names, the theme, default content pages overrides, views and anything else you may have changed.




## Installing on Pantheon
You can have a free Pantheon account, without a custom domain name. This is a good option for testing Mukurtu. You can move your site off Pantheon if you want to later. Pantheon is tuned for Drupal, and the max file storage is 1GB, after which Mukurtu will break. To have a custom domain name is $25/month for hosting & you may need to get extra file storage if you hit limits by contacting Pantheon.












--------------------------------------------------------------------------------

## Release 1.0

- First installer.

## Release 1.0 installation instructions



### Manual upgrade instructions
The previous release is tagged as v1.0 and branch v.1.0.0.
















## Install Mukurtu from Source Code

Mukurtu is a Drupal installation profile, which runs on tuned LAMP stacks. The source code is hosted in a (currently) private repository on GitHub.

You should be able to install Mukurtu without much difficulty if you know how to move source code files to a server.

To access the source code, please send your github username to Michael Ashley, who will forward it to the Mukurtu engineering lead, Chach Sikes.

You can clone the git repository, or download the source code as a zip file (currently 42MB.) Everything you need is in the download. If you install via the database, the default admin login is admin, password: changeme

This is not the final public repository. Through working with a small group of alpha-testers, we can improve this documentation and ensure that the installation process from the github repository is as smooth as possible.


_______________________________________________


## Installation Profile
This means that you install Mukurtu the way you would install a normal Drupal site. 

* Tuned Lamp Stack
Mukurtu requires a LAMP stack -- which is available on most webhosts. If you want do theme development, you should set up a local server. There are many online resources about how to set up a localhost for developing Drupal, and those methods will work for Mukurtu.

* Tuned Cloud Services as a hosting option
This also means that low-powered shared webhosts such as Dreamhost may have some performance issues, but we have not tested Mukurtu installation on Dreamhost recently, so it might work. 
There are other alternatives for hosting your code for free or low cost, such as Pantheon, dotCloud, Acquia DevCloud and OpenShift. With these services, low-traffic sites pay very little, or you pay to have a custom domain name; when you are popular (and, theoretically more fundable) you can pay for more room and bandwidth. These servers have more features that make Drupal perform faster. Many of these services are newer on the market and are suffer from occasional outages.

* Drupal Customizations
As a Drupal install, Mukurtu has a lot of configurations and customizations to provide you with a multimedia web archive for your digital heritage materials.

Most configurations are stored in features and custom modules, and are enabled upon installation. A handful of configurations are not yet able to be stored in Drupal, and need to be added after installation through an update script and by replacing a few database tables. For those who find this task difficult, we provide an installation database snapshot as well. 

Additionally, some configurations are necessary to personalize your site and use external services (such as spam protection.)

* Moving Mukurtu Files to a Server
We do not recommend FTP for Drupal projects because there are thousands of files. FTP transfers fail, and it can be extremely difficult to find the missing file. Also, it takes a long time. Tarballing your source code is much easier.

It’s much easier if your server has git installed. If so, you can clone the git repo on your server by ssh’ing into your server (you must have shell access to do this) -- and cloning the repo. To test if your server has git installed, on most servers you can type ‘which git’ -- if you get a response of a path to git, then you have git installed.

If you are doing actual development, it will be likely that you will need to set up your SSH key. If you have not done this before. This is well documented on the github website. It is the way that most of these cloud services authenticate, so a valuable and necessary investment of time. It is not that hard.

Bear in mind, that installing Mukurtu is a server administration task. By hosting your own code, you become a server administrator, and that does require a lot of specialized knowledge. Many people have done it though, and if this is newer to you, do not despair. Anyone who has installed any PHP/Mysql software should be able to help you -- so that includes Drupal, WordPress, Joomla and other CMS’s.

Git submodules & Forking your version of Mukurtu
If you develop a custom theme for your mukurtu site, then you could create your own theme folder, versioned with git, and clone your theme into the themes folder. 

For more extremely modification and feature development, you can fork Mukurtu into your own github account, and clone the entire repository from your forked version of Mukurtu. 


* Github repository location
https://github.com/codamatic/mukurtu
(note: you must be added to the private repository to see it)
All people with access to the GitHub repo are part of the Mukurtu Code Preview Team, and have pull access only.

Active developers belong to the team Mukurtu Code Development, and can have push and pull access. This option is will be available for teams that are actively working on the Mukurtu Source Code.

#### Instructions

##### Clone the repository
1. Get access to the git repo. (Create an account on github.com, set up your ssh key on github (and on your computer as necessary if you will be doing development. ))
2. Make sure git is installed on your server computer (on your computer if hosting locally, or on your webserver -- this will require shell access.)
3. Go to the terminal. (This is easier on a Mac, harder on a PC, some people use cygwin, but also there are new GUI tools for interacting with git - which we recommend. This is all well-documented by googling for it.)
4. Navigate to the location in your computer where you want to install Mukurtu. You want to be one directory up from the root folder that renders web files.

5. Clone the repository

git clone git@github.com:codamatic/mukurtu.git

This will create a new folder called mukurtu

You can rename your repository by doing:
git clone git@github.com:codamatic/mukurtu.git mukurtu

Or load it into your current directory by doing:
git clone git@github.com:codamatic/mukurtu.git .

6. If you haven’t already, you may need to authenticate with github by setting up your private key. (Documented in github)

7. Make sure your new folder of Mukurtu files is visible to the webserver.
8. DATABASE: In mysql, create a new database. Note your login credentials: hostname, username, password, and port if necessary.
9. You can then visit the URL for your site from a web browser. You should get an install screen. If not, visit http://yourwebserver.com/install.php


## Install via ZIP
If you are just testing out Mukurtu locally, and git is a bit over your head, you can still try out the source code by downloading a zip file from the github page. This will come with no source control history, and you will not be able to pull changes and updates from our site to yours without relinking your codebase with github. (Which you can do by doing git init, and adding the remote and sorting out any merge conflicts -- or just cloning the repo and putting your changes back into the codebase.)

## Installing Mukurtu
From here, the process is pretty easy. You have two options.

A. Just install the database snapshot.
There is a compressed mysql db file in sites/all/modules/custom/mukurtu_platform/db_snapshot. You can decompress this and install via the mysql command line. (It’s probably too big for PhpMyAdmin) 
mysql -u username -p database_name < nameofmysqldump.sql

By doing this, you skip the need to install Mukurtu through install.php, because that has already been run. The caches have already been cleared, but it would be good to clear the caches anyways, run cron, visit the modules page to trigger page reloads. You may need to check that the file system folder points to your /tmp folder.

The database admin password is username: admin  password: changeme
Do change your password, we recommend a strong password.



B. Go through the install process and then update a few mysql tables (recommended for advanced users who want to help improve the platform.) As soon as we get that working, just clicking the install button will be all you need to do. 


To do this:
1. Fill in the various fields for your site. (Site name, email, admin)
2. Fill in mysql database information as necessary. If you are familiar with Drupal you can use a settings.php file. Make sure your files folder is writable. Note that this version of Drupal is Pressflow, and is tuned for running on Pantheon’s servers (which have things like Apache Solr, Redis and Varnish already installed.) This is not straight up Drupal core. It makes Drupal go faster.
3. Run the installer. It will install 140+ modules. (As we say, we are using all of Drupal in Mukurtu.)
4. When it is finished (a few minutes) it will say it is done and let you finish configuration your site.

5. There are two more steps to kickstart your Mukurtu instance. Both are workarounds and not ideal, and we hope to find more seamless solutions but to date, we have not. (Open to suggestions.)

a. Run the updater.

- in your code editor go to: sites/all/modules/custom/mukurtu_platform/mukurtu_platform.install
- edit the last update item number -- increment by 1. 
ex. the most recent update is : mukurtu_platform_update_7039()
change it to mukurtu_platform_update_7040()

This will trigger your Drupal install to notice there is an update. You can then visit update.php and run the updater and these particular updates will get triggered. They happen on install because of conflicts of certain installation items not being in place.

b. Overwrite MYSQL tables.
There are 4 sql files in sites/all/modules/custom/mukurtu_platform/sql_overrides
Each has been set up to rewrite the default installed mysql tables.

To load them, use the mysql terminal (PhpMyAdmin should work to) -- you are just replacing tables.
ex. mysql -u root -p dbname < sites/all/modules/custom/mukurtu_platform/sql_overrides/file_display.mysql

* you do not need to do this in any particular order

6. For admins, admin_menu is installed. There is also a DASHBOARD (admin/dashboard) which has a lot of links to manage and administrate your Mukurtu site.
-- You can configure your site information, manage groups and content (like any Drupal site.)

### Special areas of configuration include:
Set Private File Path
Drupal requires you to set the path to the private folder in the file system.
Configure Google Analytics
You will need to create a Google Analytics account and then configure Google Analytics on this site.
Configure Mollom
Configure Mollom. Requires an account.
Rebuild Site Permissions
If doing a lot of site content editing, you may need to rebuild permissions to make sure that access permissions remain set correctly.
Make Search Work (Run Cron to build Search Index)
If you are not getting search results, your site content has probably not been indexed. Search will update if you run cron. See if all content is indexed in search: admin/config/search/settings

#### Mukurtu Demo Content
Also, there is a special area of Mukurtu Demo Content. Mukurto has a lot of features for admins and content managers -- around importing content, and giving you an idea of what the site looks like when filled in. You can install this content and play around with it. To remove the content, you can either delete it all, or else rebuild your Mukurtu installation.

#### Updates and Upgrades
We periodically update modules for security reasons, for new features, and for bug fixes. Many changes will simply come with features changes. (admin/structure/features) -- When you make changes to Mukurtu, things you do may override the features settings. The new feature will NOT update until you resolve those changes. We recommend that you develop a practice of noting and logging which changes you do, so that when you upgrade, you will be able to keep track.

The kinds of changes include changes to the menu, content pages, views. 

A few settings are permanently overridden because of the mysql permissions overrides. You may disregard these (unless you change permissions yourself.)

When we offer new upgrades, there will be instructions for pulling the code and running update.php and an overview of what is different. It will be up to you to review our changes and reconcile with your own changes.

For serious and major upgrades in the future, remember that the content in Mukurtu is designed to be exported and imported again. Right now nearly everything related to content is fully exportable and importable (digital heritage, media, most taxonomies, users, groups -- everything except user comments.) So for migration to, say Drupal 8 (in a long, long time) -- it may be easier to just export and reimport your content since the system changes may be very drastic.

#### Help Test Upgrades before they are released
We are interested to make it as easy as possible for you to upgrade. Those interested in early upgrades will be able to try out the upgrade and work with us to make sure it goes smoothly. We will not be able to do this for everyone, but rather a few people on different kinds of systems. If you are interested, please let us know so we can consider your installation in this process.

#### Things to know
Some modules are not upgraded because of how heavily they have been modified for use in Mukurtu. OG and Media module in particular. There are related custom modules that use these, and then configurations in features.
Some theme module customizations is in sites/all/modules/custom/features/ma_base_theme
The contrib-dev, contrib-patch and contrib-stable folders are currently out of sync and those folder specifications are generally meaningless.
There are patched modules and one or two core patches (related to files) in addition to the fact that this is Pantheon’s version of Drupal pressflow that we are using.
In cases where you cannot wait for Mukurtu to provide an upgrade or bug fix and take this on yourself, the recommended module upgrade & code contribution process is to:

For module upgrades: do a diff against the current version of the module (and/or check the git log file -- there are enough competing systems at play to make this the simplest method) -- find the newer module. Install, update as necessary -- and then perform a series of tests of file display, access etc. 

For code contributions, new features and bug fixes:
If you are successful, please create an issue on github, and document your change. You can submit your patch to the Mukurtu team and we will review it and test it (when possible and where appropriate) and roll it into the next Mukurtu upgrade.

We periodically update Drupal Core, but wait for Pantheon to do this first.



#### Installing in a Cloud Hosted Server
To date, we have only used Pantheon.

To install one site on Pantheon.
1. Create an account. 
2. Create a site. 
3. Install Drupal 7.
4. Add your Pantheon git repo as another remote repo. (You will have two -- origin (github), and pantheon.
```
git remote add pantheon git://gitrepoaddress.git
```
5. Force push the code to your pantheon server.
```
git push pantheon master --force
```
6. *Updates* We keep Mukurtu in sync with Pantheon’s changes and history, Pantheon will occasionally give you notices that there are new updates. We recommend just waiting for us to handle these and force pushing code again. We do not recommend messing with .gitignore and settings.php -- Patheon seems to handle the settings.php. You can import a database through Pantheon’s interface, or use mysql to connect. 


### Known Bugs and Feedback
For general Mukurtu feedback, please use the Feedback form.
We also can use the GitHub issue tracker for code centric work.
For active development, we use Pivotal Tracker
The git repo does not contain the full development history. That git repo is 700MB. If you want to do serious development and need the full history, just let us know and we can add you to that private repository.


#### A note on how configurations load in the Mukurtu platform

Any new developments in Mukurtu should be featurizeable. But with Drupal, this is not always guaranteed. When items are not featurizable, they are set in the install settings in the main installer (profiles/mukurtu) and then also in mukurtu_platform (sites/all/modules/custom/mukurtu_platform.) Some configurations can only happen after the platform is fully installed, and so they may be part of a feature that is installed later. 

More configurations are triggered through update.php. Right now, this requires incrementing the update number in code and then running update.php. (The alternative is to put these changes in a module, and have you manually enable the module after you install, or to create a configuration page, with shows you a button you have to push after you finish the main install successfully.)

There were a handful of features that could only be integrated with Mukurtu as part of update.php, and a few which seem to fail, and need much more development work to allow this to be completely seamless.

The settings for og_permissions, wysiwyg, file_display and demo users attempt to load if you run the update.php, but this does not seem to be 100% reliable. 

What *is* reliable is simply to completely replace the database table. This presents one difficulty, which is that we must export the sql dump whenever there are changes. 

Mukurtu has a great deal of complexity with regard to OG and Media configuration - so tests need to be run to make sure that none of the changes break the file display and access -- both of which are critical to the function of Mukurtu. 

The Media Module and OG permissions are critical to Mukurtu, and as complex Drupal projects, it is not likely that this will be an easy fix.

For those who are interested, the key problems are:
-- the Organic Groups permission table does not save properly with features. 
-- the Media module file display permissions have a weight issue which prevents them from saving as a feature in the correct order, which destroys the file presentation
-- the WYSIWYG settings are apparently not exportable
-- we have some demo users content which was not fully exportable



## Tests
To make sure the Mukurtu is working as expected.

### Test Access Protocols
* Install Demo Content
- Make sure that mukurtu_batch_import module is installed on your instance.
- http://mukurtu.local/admin/mukurtu/batch_import
- download the demo file
- import it

This will load demo content with sample digital heritage, cp and communities.
The content is designed to demonstrate access protocols and also provide a test that the platform is working correctly.

To test that these communities work:

Test that certain access restricted content is not visible:

- Strict works
http://mukurtu.local/browse 
- Logged in as admin, switch to user: 
(open user) Gordon:  should see non strict and open content with green and circles -- he can see community content that contains these items, but not strict content.
(community user) Beryl: should only see blue, green, white, circles and triangles
(strict user) Alberto: should see blue, green, white, circles and triangles AND red and squares



### Test Export Content
http://mukurtu.local/browse

Export
Items by field
Select the arrow right next to the nav box
Select a field to exclude
Continue
download files and check their contents
You should have a zip file with media in folders, and a csv file linking to that content.
Note: to reimport you will need to move all of the media into their own single folder. We cannot support that at this time. There are notes on this and you should use a tool to do this if there are a lot of items. 


### Security and Going Live

** You should change all of the passwords on your instance of Mukurtu, especially when you start adding content and having people actually use the site.

For convenience and ease of development in creating an installation profile, and of teaching how to use Mukurtu we use highly insecure passwords, such as demo and changeme

You should change the admin, Community Admin, Mukurtu Admin, Librarian, demo, demo users and other passwords on your installation if you install from the database snapshot. (If you install via the installer, then you create the password yourself.)

It is a good idea to change any other passwords that come with the site. It would be very easy for anyone to log in to any instance of Mukurtu if they know these users exist. 



## Mukurtu Custom Modules

* Mukurtu platform itself installs like this:

/profiles/mukurtu.install - settings that get loaded -- leave these as is, or comment them out…we will need them when the site is totally loaded from features, if that ever happens…
/profiles/mukurtu.profile - installer interface - will prob need editing
/profiles/mukurtu.info --> triggers installation of a cascade of .info dependencies. Not so important for this install, since we are just loading from the database and leaving the code alone.
/profiles/rebuild.sh -- leftover from civicactions - prob not helpful. Go head and delete it if this proves to be the case.

/sites/all/modules/custom/mukurtu_splash - dashboard, and followup responses on installation
/sites/all/modules/custom/ -- This is the folder that has custom mukurtu modules.
/sites/all/modules/custom/mukurtu_platform - this is the module that deals with setting up the platform
/sites/all/modules/custom/features - all features -- these have dependencies that get triggered on normal install.
/sites/all/modules/custom/license - custom tk licensing
/sites/all/modules/custom/mukurtu_apps - special add on module that extend mukurtu
/sites/all/modules/custom/mukurtu_mods - inherited from civic actions, incredible delicate code that handles permissions. pay close attention to the language -- localization breaks this which breaks the platform completely. total integration with features. pain in the butt to deal with.
/sites/all/modules/custom/mukurtu_mods_collection - deprecated
/sites/all/modules/custom/views_autocomplete ?? - overwritten?
/sites/all/modules/custom/zip_export_media ?? - overwritten?









--------------------------------------------------------------------------------

### Installing in Dreamhost (Tip: Don't. It's really slow.)
Notes by Dario Magillo 
August 17, 2012

I tried installing Mukurtu on a subdomain on dreamhost (http://mukurtu.zooper.org)
It works, but it's really slow: probably too much for a cheap shared hosting (I don't have a VPS, just web hosting).
After visiting some pages once, now it's a bit quicker thanks to drupal cache.
Anyway it's okay for testing/developing purpose.

Mukurtu doesn't work out of the box on dreamhost, mainly for wrong php.ini settings.
These are the steps I followed:

1. create a new subdomain (or a new domain)
	- choose fully hosted
	- ask for "www" redirect
	- choose a directory name for subdomain e.g. mukurtu
	- use PHP 5.3 FastCGI

2. create a new database
   - this will create a new hostname for DB e.g. mysql.mukurtu.zooper.org
   - create a new database user with full access to the new DB (use a strong password!)

3. ssh to your domain (if you don't have ssh, open a support ticket request to obtain it)
   - you need to override some php.ini settings (for details http://wiki.dreamhost.com/PHP.ini#PHP_5.3) 
WARNING! this will affect every php5.3 sites hosted on your account

   - create a directory for your php configuration hooks 
mkdir -p ~/.php/5.3/

   - create a file phprc
vi ~/.php/5.3/phprc
or 
nano ~/.php/5.3/phprc

   - paste the following lines to phprc
max_execution_time = 1600
max_input_time = 1600
memory_limit = 256M

   - you must restart phpcgi to apply new settings, launch
killall php53.cgi

- create a php file in ~/public_html (or in any directory reachable by web). e.g. ~/public_html/info.php
- put a call to phpinfo() in the new php file. e.g. put in new file just <?php phpinfo(); ?> 
- go to http://yourdomain.com/info.php in your browser to confirm new settings have been applied

4. Install mukurtu files 
	- move to your new subdomain dir (e.g. ~/mukurtu)
	- many dreamhost shared servers have git preinstalled, try launch git -h
	- if you don't have git on your server open a ticket request or build it by yourself () following http://wiki.dreamhost.com/Git#Setup_Two:_More_Thoughtful
	(- If you don't want to mess with git I think downloading mukurtu tarball from github and extract it on dreamhost will be ok)
	- if using git, clone repository following Chach manual

git clone git@github.com:codamatic/mukurtu.git .

5. Install mukurtu DB
  - I tried to complete install.php wizard without success, so I had to follow DB dump option. I have no tried again after tweaking php.ini settings, I think wizard fails on dreamhost for memory limit (default 90M) and for timeouts. 
  - unzip and import DB dump as explained in manual, just remember your mysql server is installed on another host
mysql -u <your_db_user> -h mysql.subdomain.yourdomain.com -p<your_pwd> <db_name> < MukurtuCMS-2012-08-16T05-15-14.mysql

6. edit settings.php database settings
vi sites/default/settings.php

   - put your new database conf as follow
$databases = array (
  'default' =>
  array (
	'default' =>
	array (
  	'database' => 'your_db_name',
  	'username' => 'your_db_user',
  	'password' => 'your_db_pass',
  	'host' => 'mysql.subdomain.yourdomain.com',
  	'port' => '',
  	'driver' => 'mysql',
  	'prefix' => '',
	),
  ),
);

7. test your installation. It's quite slow but should work.
  - login as admin and change your password!

* I can also confirm Services module is working well with mukurtu, no need to tweak anything by now.
* I installed mukurtu locally on MAMP too, tweaking same php settings and some mysql stuff (packet size limit), it's ok for developing but I get a lot of warnings since MAMP uses php 5.4 as default.
* I had to apply some patches and disabling some modules, so no very clean by now.
* I will try again with the new clean repository and swiching MAMP to php 5.3, if it works I'll let you know.