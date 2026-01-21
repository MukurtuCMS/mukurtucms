## Mukurtu 3.0.7
- Added pre-migration summary report tool
- Updated to Drupal 7.103
- Fixed bug that crashed the atoms page if no cultural protocols exist
- Fixed bug that broke the formatting of the modules page

#### Manual Upgrade Steps
This version requires a database update.
- database update: `drush updb`

## Mukurtu 3.0.6
- Updated to Drupal 7.102
- Updated jQuery Update module to 7.x-4.1
- Fixed bug on deleting collections

#### Manual Upgrade Steps
This version requires a database update.
- database update: `drush updb`

## Mukurtu 3.0.5
- Updated to Drupal 7.97
- Contrib module updates
- Improved PHP 8 compatibility

#### Manual Upgrade Steps
This version requires a database update.
- database update: `drush updb`

## Mukurtu 3.0.4
- Updated to Drupal 7.95
- Contrib module security updates
- Add support for PHP 8

#### Manual Upgrade Steps
This version requires a database update.
- database update: `drush updb`

## Mukurtu 3.0.3
- Updated to Drupal 7.91
- Contrib module security updates
- Fixed a bug where newer versions of Chrome could not open collapsible fieldsets.

#### Manual Upgrade Steps
This version does not require any database updates.

## Mukurtu 3.0.2
- Updated to Drupal 7.88
- Updated Colorbox

#### Manual Upgrade Steps
This version does not require any database updates.

## Mukurtu 3.0.1
- Updated to Drupal 7.87
- Change default permissions for 'delete all items' option in feeds
- Updated contrib modules for PHP 7.4

#### Manual Upgrade Steps
This version requires both a database update and a cache clear.
- database update: `drush updb`
- cache clear: `drush cc all`

## Mukurtu 3.0.0
- Added support for the new version of [Mukurtu Mobile](https://mukurtu.org/mobile/)
- Updated to Drupal 7.81
- Many contrib module updates

#### Manual Upgrade Steps
This version requires both database and feature updates.
Many features have been changed. It is strongly recommended to have a current backup of your site before updating.
- database update: `drush updb`
- revert all features: `drush fra`

## Mukurtu 2.1.8
- Updated to Drupal 7.80
- Updated handling of Soundcloud API
- Fixed a date format bug for original date field import

#### Manual Upgrade Steps
- database update: `drush updb`

## Mukurtu 2.1.7
- Updated to Drupal 7.78
- Fixed a bug where imported content would not use the correct field language

#### Manual Upgrade Steps
- database update: `drush updb`

## Mukurtu 2.1.6
- Updated to Drupal 7.74
- Fixed a bug where new imported content would not use the default site language
- Fixed a bug where taxonomy terms may be imported with the incorrect language
- Changed the method used to populate some entity reference fields. Item edit forms on sites with a large number of items may load faster now
- Updated contrib modules to add support for PHP 7.3+

#### Manual Upgrade Steps
- database update: `drush updb`

## Mukurtu 2.1.5
- Updated to Drupal 7.73
- Fixed a bug where new content would not be correctly added to collections/related content fields
- Fixed a bug where the 'View published content' permission could be incorrectly overridden

#### Manual Upgrade Steps
- database update: `drush updb`

## Mukurtu 2.1.4
- Updated to Drupal 7.70
- Added a media export page
- Fixed a bug where in some cases when exporting only media, the binary file would not export
- The recent content list in the dashboard now includes edit links
- Fixed a bug where exports may result in an empty zip file on some systems
- Made the "tags" field name consistent across all media types
- Mukurtu admins can now administer content warnings
- Fixed some color inconsistencies on the red & bone color scheme
- Improved the display of the small hero image with welcome message

#### Manual Upgrade Steps
- database update: `drush updb`
- revert features: `drush fr ma_scald`

## Mukurtu 2.1.3
- Content type specific related fields (e.g., “Related Digital Heritage Items”) have been generalized and consolidated into a single “Related Content” field
- The [TK Clan](https://localcontexts.org/tk/cl/1.0) label has been added
- Default image style resolution has been doubled for the most common image styles
- Fixed permission issue that could cause CSV exports to fail for some user roles
- Switched default browse sort to search relevance
- The Original Date field will no longer auto-fill the current date during import
- Created a custom HTTP 403 error page
- The link to add users to a community now works correctly on sites installed as a sub-folder
- Theme management links now link to the correct sub-theme
- Related items featuring audio will now correctly use the HTML 5 player on the digital heritage item page
- Fixed some minor theme inconsistencies
- Reduced the number of common repeated PHP notices and warnings in the watchdog log
- Updated to Drupal 7.69
- Updated contrib modules

#### Manual Upgrade Steps
- database update: `drush updb`
- revert features: `drush fra`

## Mukurtu 2.1.2
- Fixed a bug that caused the import of some audio/video files to fail
- Adjusted the default Mukurtu theme to make sub-theming easier
- Security: Update to Drupal 7.67

#### Manual Upgrade Steps
- database update: `drush updb`

## Mukurtu 2.1.1
- Fixed bug that caused some sites to not be able to create sub-collections
- During import, original date fields will no longer default to the current date if left empty
- Fixed a bug where for some upgraded sites the original date field was preventing search from indexing completely
- Scald atoms in drag and drop fields are now exported more reliably
- Resolved an issue where language stewards could not edit dictionary words in their language community
- Added trim tamper by default to identifier fields in Mukurtu importers
- Fixed an issue importing YouTube videos with new Mukurtu importers
- Security updates, including contrib modules and Drupal 7.66

#### Manual Upgrade Steps
- database update: `drush updb`
- update the search index: `drush sapi-r && drush sapi-i`

## Mukurtu 2.1.0
- A new, responsive default theme has been added
- Collections can now have nested sub-collections
- A new type of collection, “Personal Collections” have been added. Personal collections allow users to group content on their user page for their specific needs. They can be private or can be made public to share with others. Cultural protocols still apply as normal to contents within personal collections
- Collections without thumbnails now use the first unrestricted image from a digital heritage item in that collection
- Import/export now supports all Mukurtu content types
- Community records are now indexed on the Digital Heritage browse page
- A new browse page has been added that indexes all standard Mukurtu public content types (Digital Heritage, Collections, Dictionary Words, Word Lists, and Person Records) in a single page. Site administrators can configure the default browse page by clicking on the ‘Configure Default Browse Page’ link in the dashboard
- Links to community records will now load that record as the active tab, rather than the first record
- Content action buttons (Save/Preview/Delete) now show at the top of forms as well as the bottom
- New sorting options have been added to browse pages
- Deleted taxonomy terms will no longer appear as taxonomy IDs on browse pages
- Text labels have been added to Scald library icons for accessibility
- The area that can be dragged and dropped from the Scald library tray has been expanded
- Scald atoms with restricted protocols will no longer show to non-member users (displayed as “media unavailable” previously)
- Users will no longer appear multiple times in membership lists if they have multiple roles
- Adding users to a cultural protocol now defaults to ‘Not an invitation’. This adds the user immediately to the group
- jQuery now defaults to version 1.10
- The WYSIWYG editor will now more closely use the theme CSS, so elements such as bullet points should be consistent between the editor and content views
- Mukurtu now installs correctly on PHP 7+
- Added the ability to zoom on colorbox images
- Two new TK Labels have been added ([Multiple Communities and Non-Verified](http://localcontexts.org/tk-labels/))
- File Fixity support has been added (ability to create and manage md5 and SHA-1 and SHA-256 file fixity information for files hosted on your Mukurtu CMS instance)
- Updates to Drupal and contrib modules

#### Manual Upgrade Steps
- Please do these upgrade steps in the order written.
- This upgrade process will set many pages/views to Mukurtu defaults. Make sure you have backups and note any changes you have made that have not been captured with Features Overrides before starting this process.
- database update: `drush updb` Note: The conversion from date to partial date can take a very long time and will fail the first time. This is normal.
- revert features: `drush fra`
- revert features again: `drush fra`
- clear all caches: `drush cc all`
- update the search index: `drush sapi-c && drush sapi-i` Note: You must perform this step for the new search features to function correctly.
- second database update: `drush updb`

## Mukurtu 2.0.14
- Critical security update for Drupal core to 7.63.

#### Manual Upgrade Steps
- clear all caches: `drush cc all`

## Mukurtu 2.0.13.1
- Update Rules and Backup and Migrate modules to avoid installation errors on PHP 7.

#### Manual Upgrade Steps
- database update: `drush updb`

## Mukurtu 2.0.13
- Use Honeypot for spam prevention (bot user registration) on user registration form.

#### Manual Upgrade Steps
- clear all caches: `drush cc all`
- revert the Mukurtu Core feature: `drush fr ma_core -y`
- re-clear all caches: `drush cc all`

## Mukurtu 2.0.12
- Critical security update for Drupal core from 7.59 to 7.60.

#### Manual Upgrade Steps
- clear all caches: `drush cc all`

## Mukurtu 2.0.11
- Critical security update for Drupal core from 7.58 to 7.59.
- Critical security update for Media module from 2.10 to 2.19.
- Non-critical udate for File Entity module from 2.4 to 2.20, to go along with the Media module updte.
#### Manual Upgrade Steps
- clear all caches: `drush cc all`

## Mukurtu 2.0.10
- Critical security update for Display Suite from 2.14 to 2.15.
#### Manual Upgrade Steps
- clear all caches: `drush cc all`

## Mukurtu 2.0.9
- Upgraded Drupal core from 7.56 to 7.58. Includes two critical security updates.
#### Manual Upgrade Steps
- clear all caches: `drush cc all`

## Mukurtu 2.0.8
- Added an initial beta implementation of Mukurtu Taxonomy Records, a system that provides the ability to enhance taxonomy terms with additional content
- Added the “Person” content type, which can be used as a taxonomy record, to provide additional metadata about a specific person
- Added a media content warning system, used to display warnings before displaying potentially sensitive or graphic media
- Changed default Search API configuration to better handle some UTF-8 characters
- Added the “People” field to all Scald media types
- Consolidated the display of Scald atom metadata to streamline atom creation
- Added pagination for dictionary word lists
- Stopped displaying the “Author” field (Mukurtu username) to users without edit permission, when viewing digital heritage items
- Added an option in community/protocol items to hide or limit the membership list display
- Improved the dependency handling and messaging of the Zip batch importer
- Improved the default display of taxonomy term pages
- Fixed Google Maps configuration issue
- Fixed a bug that could cause some digital heritage items to not appear in collections
- Fixed a bug that caused the community/protocol “Do not show on registration page” option to not work in some cases
- Fixed a bug which caused the Scald library to not load in some cases
- Fixed a bug which would allow DH items to reference deleted collections
- Fixed a bug where users who had permission to create a book page were not being presented with the option to do so
- Fixed a bug where the old style media player was being displayed by default in the dictionary
- Fixed a bug which prevented adding multiple media items to a single book page
- Removed the “Digital Heritage Count” facet from the collection browse page
- Updated Drupal and contrib modules

#### Manual Upgrade Steps
- database update: `drush updb`
- rebuild registry: `drush rr`
- revert features: `drush fra`. Please first review if there are any custom changes you have done that may be overwritten.
- clear all caches: `drush cc all`
- search re-indexing: `drush sapi-c && drush sapi-i`.

## Mukurtu 2.0.7
- Now defaulting to HTML5 player for Scald atoms, rather than dewplayer
- Scald has been updated, with many usability improvements
- SoundCloud support for Scald has been added
- Added the “Features Override” module, which can be used to preserve local customizations during Mukurtu upgrades [(Overview)](https://github.com/MukurtuCMS/mukurtucms/wiki/Using-Features-Override-to-Capture-Local-Site-Customization)
- The local tasks tab interface (e.g. view, edit, export) has been moved below the community record tab interface, and now correctly controls the viewed record
- A optional “Browse by Category” page has been added [(How-to)](https://github.com/MukurtuCMS/mukurtucms/wiki/Changing-the-Front-Page-to-Display-Categories)
- Fixed styling of the front page where the browse community section would overlap with the footer
- Taxonomy terms are displayed as links in community records
- Community records can now have related items
- The grouping on the manage communities/protocols page has been improved
- Format field has been made a multi-value field
- Fixed a bug that prevented Contributors from editing their own items
- Fixed a bug where renaming a digital heritage item, then renaming it back to the original title, created an infinite redirect loop
- Fixed bug where some users would lose group memberships after hiding the Wizard
- Fixed bug in dictionary importer that would result in some unused fields being populated with empty values
- Fixed bug in dictionary that would present invalid language options for new words for some users
- Added an importer for Word Lists
- Parts of Speech terms will now auto-create on import
- Alternate spelling in dictionary words is now included in search
- Updated Scald Atom importers to use semi-colon delimiters for protocol field
- Fixed bug where some Scald atom permissions for edit and delete were not being respected
- Fixed bug where users with no assigned communities would be incorrectly presented with the content creation buttons
- Updated Font-Awesome in default theme
- Security and module updates

#### Manual Upgrade Steps
- database update: `drush updb`
- rebuild registry: `drush rr`
- revert features: `drush fra`. Please first review if there are any custom changes you have done that may be overwritten.
- clear all caches: `drush cc all`
- search re-indexing: `drush sapi-c && drush sapi-i`.

## Mukurtu 2.0.6
#### Initial Release of Dictionary Feature
- This is an early offering, please provide feedback on bugs or ideas for future changes at [GitHub](https://github.com/MukurtuCMS/mukurtucms/issues) or send email to [support@mukurtu.org](mailto:support@mukurtu.org)
- The dictionary is disabled by default, but can be enabled from the dashboard
- The dictionary introduces several new content types
- A “Dictionary Word” is a the basic dictionary content type
- Each dictionary word can contain multiple “Word Entries” to list different sources, spellings, uses, etc
- A “Language Community” is a dictionary specific community that controls which users can contribute dictionary words to a language's dictionary. Access to individual dictionary words is controlled by cultural protocols.
- A “Word List” is a collection of dictionary words

#### Dictionary Quick Start
- Enable the dictionary from the dashboard
- Make sure there is at least one language in the language taxonomy. This can be done from the “Manage Language” link in the dashboard
- Create a language community for the desired dictionary language using the “Manage Language Communities” link in the dashboard
- Start creating dictionary words using the “+ Dictionary Word” button in the toolbar

#### Other Changes
- Scald audio atoms have a new metadata field 'contributor' which is the preferred field for the speaker of a recording
- Fixed a bug that caused the batch exporter to fail when exporting large files
- Fixed a bug causing the installer to fail on MySQL 5.7 platforms
- Fixed a bug where the “Add a book page” option would be presented to unauthenticated users if the author of the content was 'anonymous'
- Removed Mukurtu feature and module dependency on the community tags module
- TK labels no longer show the version number in the public facing display
- Added a warning to the "Delete Items" feeds import page informing the user that it will delete all items imported, not just the most recent batch
- Updated Drupal to 7.51
- Security updates for ctools, flag, google_analytics, og, panels, and views_data_export modules

#### Manual Upgrade Steps
- database update: `drush updb`
- rebuild registry: `drush rr`
- revert features: `drush fra`. Please first review if there are any custom changes you have done that may be overwritten.
- clear all caches: `drush cc all`
- search re-indexing: `drush sapi-r && drush sapi-i`.  Some sites may need to clear indexes: `drush sapi-c`

## Mukurtu 2.0.5
- New thumbnail carousel view for multi-page Digital Heritage items
- Images with Exif orientation data will now generate automatically rotated thumbnails
- Fixed a bug where a user would lose community/protocol membership after updating their profile
- The "Community Record Parent" field in the Digital Heritage importer has been removed and a separate importer for adding community records in that manner has been added
- Erroneous drop-down menu item in the dashboard has been removed
- "Duplicate Record" functionality will no longer copy community record or multi-page relationships
- People field permissions are now configured like the other taxonomies
- People field now displays properly on community records
- "View Media" link has been restored to the dashboard for Mukurtu Admins
- Fixed a bug where the zip importer was generating an incorrect download URL for previously uploaded zip files
- The zip importer will now handle the case where the files have been placed within a single sub-folder (as many zip archive programs do by default)
- Fixed a bug where the cultural protocol importer would fail when given a numeric '0' for the 'sharing protocol' field
- Fixed a bug in digital heritage node view that would cause multiple notices/warnings to be generated in the error log
- Updated Drupal core to 7.50
- Security updates for Features, Google Analytics, Search API, and Views modules

#### Manual Upgrade Steps
- database update: `drush updb`
- rebuild registry: `drush rr`
- revert features: `drush fra`. Please first review if there are any custom changes you have done that may be overwritten.
- clear all caches: `drush cc all`
- search re-indexing: `drush sapi-r && drush sapi-i`.  Some sites may need to clear indexes: `drush sapi-c`

## Mukurtu 2.0.4
- Digital Heritage items now support multiple TK labels
- The text of individual TK labels can now be customized at the site or community level
- Removed the option to delete a cultural protocol that is being actively referenced
- An option to export digital heritage has been added, as well as new import functionality
- Remove some bypass permissions from the 'Mukurtu Administrator' role so that protocols work as expected
- A 'people' field was added to the Digital Heritage content type
- The link to edit a community record now only appears to users with edit permissions for that item
- Community pages now link to the browse screen with the community facet selected
- Changed wording of the media "Download" link
- Fixed a bug where it was possible for a digital heritage item to be incorrectly saved as a community record
- Fixed a bug where it was possible to get stuck in the map view on the digital heritage browse page
- Fixed a bug where clicking an auto-completed taxonomy term would result in the term being double-quoted
- Fixed case where latitude and longitude would not be imported correctly from digital heritage importer
- Multi-value delimiters should now be a consistent ';' for both the web UI and the importers
- Subject field in Digital Heritage importer now accepts multiple values
- The type field for the Digital Heritage importer was added
- Fixed bug where audio files imported from Mukurtu Mobile had incorrect file extension
- Fixed minor display issues in the Digital Heritage edit screen
- Changed the Mukurtu Video Channel link to point to Vimeo instead of YouTube
- Security updates

#### Manual Upgrade Steps
- database update: `drush updb`
- rebuild registry: `drush rr`
- revert features: `drush fra`. Please first review if there are any custom changes you have done that may be overwritten.
- clear all caches: `drush cc all`
- search re-indexing: `drush sapi-r && drush sapi-i`.  Some sites may need to clear indexes: `drush sapi-c`

## Mukurtu 2.0.3
- Updated Drupal core to 7.41
- Various contrib module security updates,
- Map view of Digital Heritage items. Browse Digital Heritage now offers a Map view along with the existing List and Grid views. All Digital Heritage items that have a Location set, and also match the current search and filter criteria (and current user view permissions), display on the map as pins. Clicking on a pin reveals a popup which can be clicked through to the item.
- Scald Services resource, allows for creating Digital Heritage items and their media assets via mobile json client.
- Community Records on Book Pages. Community Records can now be added to the individual book pages of a Digital Heritage item.
- Related Items teasers. There is a new option in the Administrator's Dashboard in the "Set up Site" section, "Enable Related Items teasers". Once enabled, any Digital Heritage items that have Related Items have those items shown, in addition to their existing location at the bottom of the Digital Heritage item, in a paged teaser format at the top of the right column.
- Protocol Stewards can now edit any Digital Heritage items that are in one of their Cultural Protocols. Previously, only the original creator of the Digital Heritage item (and administrators) could edit these.
- Youtube and Vimeo videos can now be imported during Digital Heritage imports from CSV. Simply enter the Youtube or Vimeo URL in the Media Assets column.
- Collections Digital Heritage counts which appear in parentheses beside the name of a Collection in Browse Collections now reflect the number of Digital Heritage items the current user has permission to view, instead of the total count, which may differ. Additionally, the Digital Heritage Count filter now only shows to administrators, because this filter necessarily shows the total count.
- Fixed bug that prevented nodes from being unpublished. Unpublishing a Digital Heritage item, for example, hides it from the Browse Digital Heritage page, but it remains available to be republished by the author, or an administrator via the Content menu.
- Intelligent truncation for long Community Record tab names
- Fixed TK Labels not showing
- Removed Author and Tag fields that showed on the initial form when uploading an image. The fields are still available on the subsequent form, along with the other metadata fields.
- Moved frontpage context from ma_core feature into install profile so that blocks can be added/removed from the frontpage for clients without creating feature override
- Fixed linespacing for recent DH view on community page
- Fixed LESS not compiling due to missing bootstrap files

#### Manual Upgrade Steps
- database update: `drush updb`
- rebuild registry: `drush rr`
- clear all caches: `drush cc all`
- search re-indexing: `drush sapi-r && drush sapi-i`.  Some sites may need to clear indexes: `drush sapi-c`.

## Mukurtu 2.0.2
- Hierarchical Digital Heritage items.  Digital Heritage items now support hierarchical relationships to better represent multi-page content.  Ordering is changed by editing the parent node
- add a new 'Transcription' field to the Digital Heritage 'Additional Metadata' section
- fix bug where child communities could be dropped when the parent community was altered
- change default thumbnail handling for Collections view.  If no Collection thumbnail is provided, the view will try to use one of the member's image atoms
- add media specific feed importers for Scald atoms
- update Scald YouTube provider to reflect YouTube API changes
- improve Scald rendering when drag and dropping Scald atoms into multi-line text fields
- set static width and height for in-line Scald audio player during atom edit to fix display issues
- add 'Media Assets' field to Digital Heritage importer that will automatically create or use previously imported Scald atoms
- remove 'published' column from the Digital Heritage importer, as that field is set automatically by feeds
- make some fields required on Digital Heritage import to avoid creating items with no Cultural Protocols
- move Community and Cultural Protocol node views off panels to display suite
- update WYSIWYG to ckeditor and restrict to only editor buttons that work
- allow only protocol stewards to set or unset Parent Communities that they are Community managers of
- change widget for Parent Community field on Protocol nodes
- fine tune search indexing on Digital Heritage nodes and their relations
- stop redirecting users if logging in via services

#### Manual Upgrade Steps
- database update: `drush updb`
- rebuild registry: `drush rr`
- clear all caches: `drush cc all`
- search re-indexing: `drush sapi-r && drush sapi-i`.  Some sites may need to clear indexes: `drush sapi-c`.


## Mukurtu 2.0.1

- Community Records. Protocol Stewards may create community-specific "Community Records" within Digital Heritage items that share the media assets but otherwise have custom information
- Parent Communities. Communities can now be placed within Parent Communities. Explanation is provided within the field's help text.
- added "Mukurtu Administrator" role, which is the default user role for the primary user on new deployments. It has less than full Administrator permissions.
- major reworking of Digital Heritage Cultural Protocol permissions implementation. Full explanation is in comment in mukurtu_protocol_field.module, "how digital heritage cultural protocol permissions are implemented"
- fixed bug causing users to get wrongly added into Communities and Cultural Protocols
- upgrade Drupal core to 7.35. Addresses a security issue. Removes Pantheon customization.
- security updates to various contrib modules
- rename "Protocol Manager" to "Protocol Steward"
- automatically make the creator of a Community node its Community Manager, and the creator of a Cultural Protocol node its Protocol Steward
- do not redirect user when doing a password reset, fixes infinite loop with trying to reset password
- various readability improvements to the tooltip (popup help text) display on node forms
- added some permissions for the Mukurtu Administrator that were previously linked from the Dashboard but access denied
- users must now be a Protocol Steward or Contributor of a Cultural Protocol instead of just a member of it to be able to add Digital Heritage items to it
- in Digital Heritage form, use semicolon instead of comma as delimiter for multiple values and allow quotes in Digital Heritage taxonomy fields: Creator, Contributor, Keywords, Publisher, Type, Language, and Subject, and provide help text on these fields explaining this
- comma-delimit multiple values for all fields in the Digital Heritage node view, except for Creator and Contributor use one line per value
- link all linkable fields in Digital Heritage node view including Author and the taxonomy fields
- add some spacing between media items in the Digital Heritage full node view (otherwise the "Download" or "{type} Metadata" links can appear to refer to the item below instead of the correct one above
- changed which fields display in the Digital Heritage search result listing
- fix Digital Heritage grid title positioning and width
- removed Cultural Protocol filter from the the Digital Heritage browse page. This is for security reasons, since otherwise a private Cultural Protocol title can show in cases the user does not have access to it
- upgraded Creative Commons license options to their 4.0 versions
- enable media item drag and drop into certain text fields
- extract metadata from all images (not just first) when uploading multiple images in a single media upload
- show thumbnails (if uploaded) for file and audio media items in Digital Heritage node view
- use simple (non-playist) version of the dewplayer for audio items
- use better widget for the Protocol field on media items, and improve the help text explaining what the field is
- added various fields to the search index. Search will now return more results
- list of Indexed Fields page added and linked from Dashboard
- do not show tooltips on the Dashboard blocks, as they block the buttons
- updated Dashboard links style
- updated some Dashboard links text
- "Change Logo" Dashboard link now goes to correct place
- removed deprecated views from Community and Protocol nodes
- do not show Community Members block directly on Community node
- core patch to allow custom logo and favicon with private file system, and limit logo to 70 pixels height
- fix alignment of Collections with no image in Browse Collections
- fix Collections Digital Heritage count not being updated
- moved "About" page into install profile to make it user-customizable, and changed the default text
- added Github README.md file
- disabled automatic cron runs. Self-deployments should use system crontab
- remove various pieces of deprecated (Mukurtu 1.0 and 1.5) code
- remove OG role "Administrator Member"
- disable Admin Menu toolbar by default

#### Manual Upgrade Steps
- search reindexing: `drush sapi-r && drush sapi-i`
