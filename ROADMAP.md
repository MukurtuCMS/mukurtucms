# Mukurtu Roadmap

9/22/2013
* We are moving towards opening up the codebase for the Drupal community.
* This document will detail upcoming sprints.
* This document reflects agreed upon feature requests and bug fixes.
* The project has a pivotal tracker account and support system that tracks bugs and feature requests.

# Current release
/master branch
- v1.5

## Sprint v1.6: Single-click Pantheon install
* Rework sites/all/modules/custom/mukurtu_platform to load the database: mukurtu_clean.mysql
* Mukurtu platform itself installs like this:

/profiles/mukurtu.install - settings that get loaded -- leave these as is, or comment them out…we will need them when the site is totally loaded from features, if that ever happens…
/profiles/mukurtu.profile - installer interface - will prob need editing
/profiles/mukurtu.info --> triggers installation of a cascade of .info dependencies. Not so important for this install, since we are just loading from the database and leaving the code alone.
/profiles/rebuild.sh -- leftover from civicactions - prob not helpful. Go head and delete it if this proves to be the case.

See also Mukurtu Custom Modules in MUKURTU.md

* No changes to the features of the site.
* Following these types
* Avoiding timeout issues

Notes:
- Spin-up Example - https://dashboard.getpantheon.com/products/murkurtu/spinup
- Documentation for Spin-up Codebase - helpdesk.getpantheon.com/customer/portal/articles/1150064-running-a-custom-distribution-on-pantheon
- Distributions from SQL Dump - http://www.lullabot.com/blog/article/5-step-drupal-distributions
- Zeus Datasheet - https://www.getpantheon.com/sites/default/files/ZeusPlanDatasheet.pdf

1. Fork Mukurtu

2. First build locally, the installer should run and load the database.
  Tests:
    * Run tests to make sure content loads and access restrictions are still working. See documentation in MUKURTU.md
3. Transfer to Pantheon and test the same.
    * Create new Pantheon instance
    * Set up Drupal 7
    * Push and replace code according to instructions in MUKURTU.md
    * Run installer
    * Do testing procedure
4. Update documentation
    * Update documentation with any errors in MUKURTU.md
    * Correct new Pantheon install process to reflect improved install process.
5. Send pull request.
6. Tag new changes as v1.6
7. Add notes to CHANGELOG.txt
8. Update ROADMAP.md
9. Send out Upgrade notes
  a. send notification of site takedown for maintenance
  b. pull/push new codebase
  c. backup site
  d. run update.php and/or do manual updates
  e. send notification of site update complete. detail new features. notice of where to send feedback.


## Sprint v1.7: Amazon S3/CDN integration

Notes:
- CDN + Pantheon - http://helpdesk.getpantheon.com/customer/portal/articles/733395-pantheon-cdn
1. Fork Mukurtu
2. Do integration
3. Feature-ize changes & update mukurtu_clean.mysql
4. Test with demo content
5. Create additional test of bulk content
6. Document any interface manual updates -- add to the Changelog
7. Send out Upgrade notes
  a. send notification of site takedown for maintenance
  b. pull/push new codebase
  c. backup site
  d. run update.php and/or do manual updates & clear caches
  e. send notification of site update complete. detail new features. notice of where to send feedback.
8. Tag new changes as v1.7


## Sprint v1.8: Bug fixes
- remove collections
- make authors non anonymous in batch installer
- login link on homepage (which homepage?)
- logo fix color module (broken?)
- taxonomy grid view by default
- live pantheon sites theme issue (cache?)
- switch to epic editor instead of wyiswyg?
- permissions: feed importer?
- permissions: related items?
- permissions: operations shouldn't be available to all users
- content grid spaces (check and see if this is broken)
- max page width (check and see if integration exists)
- block edit (fixed?)
- services feature -- not saving app settings, requires manual setup -- can be automated? (match mukurtumobile.org)

1. Fork Mukurtu
2. Do fixes
3. Feature-ize changes & update mukurtu_clean.mysql
4. Test with demo content & test on pantheon (including testing on dev, test and live)
5. Document any interface manual updates -- add to the Changelog
6. Clean out pivotal tracker.
7. Send out Upgrade notes
  a. send notification of site takedown for maintenance
  b. pull/push new codebase
  c. backup site
  d. run update.php and/or do manual updates & clear caches
  e. send notification of site update complete. detail new features. notice of where to send feedback.
8. Tag new changes as v1.8


## Sprint v1.9: Upgrade Media module

In Spring 2013 we did a test run of the media upgrade, but there were too many widespread problems.

New features & requirements:
- Change permission so that user can only see their own uploaded content, not everyone elses. (Check this to see if this is really the desired feature.)
- This will require manually reconfiguring file_display because the settings change.. and this effects features. It's a nightmare basically and there's no way around it, or at least there wasn't in spring 2013.
- Add download link
- rework media file display so that the file page shows a smaller image and has a download link by default
- add .doc files?

Things to test:
- media: community admin -- test
- media: multiple delete
- media: feedback error
- media:  context
- media:  icon size
- media:  database media settings & features on import
- media:  uploading .doc file?
- media:  media -- change to personal library

Notes:
1. Media module upgrade requires updates to the entire file display settings, all of the features, 
2. Will require a rebuild of the mukurtu_clean.mysql database
3. No not do any other upgrades at this time unless they are directly related to the media module. This will help eliminate confusion.
4. Test more rigorously and document what the tests are.
5. Since features does not save file_display correctly

Examples:
* Add media
* Delete media
* Add media from DH content page
* Delete media from DH content page
* Delete many items at once
* Edit media items
* check file display size in lists and thumbnails
* check all thumbnails: this includes oembed and drupal created thumbnails. This part is a pain. As soon as you get it perfect, make a backup of the 
file_display & og_role_permission tables (role permissions may or may not be implicated in this, not sure, but back up just in case or do a comparison.)

6. Get upgrade sorted out and tested.
7. Test on Pantheon platform.
8. Test on pantheon platform where files are moved from dev to test to live
9. Send out Upgrade notes
  a. send notification of site takedown for maintenance
  b. pull/push new codebase
  c. backup site
  d. run update.php and/or do manual updates & clear caches
  e. send notification of site update complete. detail new features. notice of where to send feedback.
* Tag new changes as v1.9

## Sprint v1.95: Update Drupal Core
Mukurtu uses Drupal core that matches Pantheon. They integrate with Pressflow.

To upgrade:
1. Fork Mukurtu
2. Pull changes from Pantheon (…pantheon.git drops… git link)
3. Run update.php
4. Try to ignore any contributed modules that have changes… except ones that are actually broken.
5. Test - access protocols
6. Send out Upgrade notes
  a. send notification of site takedown for maintenance
  b. pull/push new codebase
  c. backup site
  d. run update.php and/or do manual updates & clear caches
  e. send notification of site update complete. detail new features. notice of where to send feedback.
7. Tag new changes as v1.95


## Sprint v2.0: Update Contributed Modules
- Update Drupal contributed modules and features that rely on those modules
- Do not upgrade organic groups.

To upgrade:
1. Fork Mukurtu
2. Pull changes from Pantheon (…pantheon.git drops… git link)
3. Run update.php.
4. Do tests & make new mukurtu_clean.mysql
5. Send out Upgrade notes
  a. send notification of site takedown for maintenance
  b. pull/push new codebase
  c. backup site
  d. run update.php and/or do manual updates & clear caches
  e. send notification of site update complete. detail new features. notice of where to send feedback.
* Tag new changes as v1.95


## Sprint v2.1: PPWP integration
- Integrate Book scrapbook from PPWP
* Tag new changes as v2.1
1. Fork Mukurtu
2. Load / find feature-ized changes from PPWP
3. Test integration
4. Add as feature. Enable in appropriate .info file (the one with the list of all of the modules and dependencies)
5. Test with demo content.
6. If it seems necessary, create NEW test with demo content that will show that this feature works.
7. Update mukurtu_clean.mysql
8. Send out Upgrade notes
  a. send notification of site takedown for maintenance
  b. pull/push new codebase
  c. backup site
  d. run update.php and/or do manual updates & clear caches
  e. send notification of site update complete. detail new features. notice of where to send feedback.
* Tag new changes as v2.2


## Sprint -- Pantheon single click installer interface
- front end for installer on pantheon (design & build)
- design javascript & html for mukurtu.org interface pointing to pantheon single click install page.
- have a huge disclaimer about security -- all types - and what it means if you are hosting your own & things to consider.  
No tags, this is just a project.

## Sprint v2.2: Openshift integration Mukurtu
- See if Mukurtu will install on Openshift. 
- Create recommendations for how to get it to work.
* Tag new changes as v2.2


## Sprint 2.3: Update Organic Groups
The Organic Groups module has not been updated in a long time.
There are special integrations throughout mukurtu which rely on the specific version of organic groups that we are using.
- update strict patch
- update other permissions overrides
- make sure to back up og_role_permissions table
- resave that table and make a clean database mukurtu_clean.mysql
- do thorough tests of permissions.

1. Fork Mukurtu
2. Do OG module upgrade with all of the tests and troubleshooting and module fixing.
3. Integrate fixes with platform (update mukurtu_clean.mysql, features, .info files)
4. Test on Pantheon platform.
5. Send out Upgrade notes
  a. send notification of site takedown for maintenance
  b. pull/push new codebase
  c. backup site
  d. run update.php and/or do manual updates & clear caches
  e. send notification of site update complete. detail new features. notice of where to send feedback.
* Tag new changes as v2.3

## Sprint 2.4: Open codebase to the public
1. Create page on drupal.org for Mukurtu project describing it to the public
2. Switch github.com Mukurtu project from private to public
3. Mention the pantheon installation option.

Responsible codebase opening
- have drupal bug page or clearly documented project support page
- have dedicated person watching and getting notifications
- clearly document the process of integrating pull requests
- add new features and other notes to the roadmap - explaining where they come from
- be clear and realistic about the level of support actually available (budget, # people actually working on the project.)
- describe the limits and governance process of the codebase:
** who is the maintainer?
** how are new feature integrated?
** what improvements are on the horizon
** what are ways someone can fix something themselves, leave notes about how they did it (open up)
** community meetings / office hours
** all of this in addition to ongoing user support


Possible later sprints:
## Sprint 2.5: Complete featurize-ation of the codebase?
* Get installer to work from features and not with database?

* Top Requested Features
- More localization