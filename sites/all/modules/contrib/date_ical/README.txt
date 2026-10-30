Date iCal

This module allows users to export iCal feeds using Views, and import iCal feeds
from other sites using Feeds. Any entity that contains a Date field can act as
the source/target to export/import an iCal feed.


===============================================================================
INSTALLATION
===============================================================================
Date iCal has several required dependencies, and an optional one:
- The Views (version 3.5+), Entity API, Libraries API (version 2.0+), and Date
  modules are required.
- The iCalcreator library v2.20.2 is required.
- PHP 5.3 is required for the iCalcreator library to properly handle timezones.
- The Feeds module is optional. It's needed only if you you wish to import iCal
  feeds from other sites.

To install the iCalcreator library, download the project's v2.20.2 zip file:
https://github.com/iCalcreator/iCalcreator/archive/e3dbec2cb3bb91a8bde989e467567ae8831a4026.zip
Extract it, and copy iCalcreator.class.php to a folder in your Drupal site
named sites/all/libraries/iCalcreator (you'll need to create that folder).

Or, if you have drush, you can install iCalcreator by running this command from
your site's root directory:
drush make sites/all/modules/date_ical/date_ical.make --no-core

Then, clear the cache on your site by using either "drush cc all" or logging in
to your site and going to Configuration -> Development -> Performance and click
the "Clear all caches" button. This is necessary because libraries are cached,
and you may see confusing behavior from Date iCal if the iCalcreator library
gets cached at a bad time.

To confirm that iCalcreator is installed correctly, log in to your Drupal site
and navigate to the admin/reports/status page. If the row titled "Date iCal" is
green, Date iCal is ready to go. If it's red, the iCalcreator library is not
properly installed. If it's missing, you'll need to enable Date iCal.


===============================================================================
EXPORTING AN ICAL FEED USING Views
===============================================================================
There are two plugins that export iCal feeds. You can use either one, though
the iCal Fields plugin (described later) is a bit more versatile.

HOW TO EXPORT AN ICAL FEED USING THE iCal Entities PLUGIN

1.  Go to the Manage Display page for the content type you want to export in an
    iCal feed. On the "Default" tab, check the box for "iCal" in the section
    titled "Use custom display settings for the following view modes", then
    click Save.
2.  Click the new "iCal" tab that now appears in the upper-right corner of the
    Manage Display page for this content type.
3.  Set up the iCal view mode to contain whatever should be exported as the
    'Description' field for the iCal feed. You can trim the text to the desired
    size, include additional information from other fields, etc.
4.  Do this for each of the content types that you wish to include in your
    site's iCal feeds.
5.  Create a new View that displays the entities that you want to include in
    the iCal feed.
6.  Add a "Feed" display to the same View. Change the Format to "iCal Feed".
    When you click "Apply" from that dialog, you'll be given the option to name
    the calendar, which will appear in your users' calendar clients as the
    calendar's title.
7.  Change the Show setting to "iCal Entity".
8.  In the settings for iCal Entity, select the date field that should be used
    as the event date for the iCal feed. Make sure that you choose a field that
    is a part of every entity that your View displays. Otherwise, the entities
    which don't have that field will be left out of the iCal feed.
9.  You may optionally choose a field that will be used to populate the
    Location property of events in your iCal feed. This field can be a text
    field, a Node Reference field, an Addressfield, or a Location field.
10. Give the Feed a path like 'calendar/%/export.ics', including a '/%/' for
    every contextual filter in the view.
11. Make sure the Pager options are set to "Display all items".
12. Add date filters or arguments that will constrain the view to the items you
    want to be included in the iCal feed.
13. Using the "Attach to:" setting in the Feed Settings panel, attach the feed
    to a another display in the same view (usually a Page display). Be aware,
    though, that the Feed will display exactly what its settings tell it to,
    regardless of how the Page display is set up. Thus, it's best to ensure
    that both displays are configured to include the same content.
14. Save the View.
15. Navigate to a page which displays the view (usually the Page display's
    "path" setting). You should see the iCal icon at the bottom of the view's
    output. Clicking on the icon will subscribe your calendar app to the iCal
    feed.
16. If you don't have a calendar app set up on your computer, or you want your
    users to download the ical feed rather than subscribe to it, you'll want to
    go back to the View settings page, click the Settings link next to
    "Format: iCal Feed", and check "Disable webcal://". Then save your View.
    This will make the iCal icon download a .ics file with the events, instead
    of loading the events directly into the user's calendar app.
17. If events that you expect your feed to include are not appearing when it
    gets consumed by a calendar app, check the Drupal permissions for your
    event content type. If anonymous users can't view the event nodes, they
    won't appear in your feed when it gets loaded by a calendar app.

HOW TO EXPORT AN ICAL FEED USING THE iCal Fields PLUGIN
1-6.These steps are the same as above.
7.  Add views fields for each piece of information that you want to populate
    your iCal feed with. A Date field is required, and fields that will act as
    the Title and Description of the events are recommended. You can also
    include a Location field.
8.  Back in the FORMAT section, change the "Show" setting to 'iCal Fields'.
9.  In the settings for iCal Fields, choose which views fields you want to use
    for the Date, Title, Description, and Location.
10+ These steps are the same as above.


===============================================================================
IMPORTING AN ICAL FEED FROM ANOTHER SITE USING Feeds
===============================================================================
- Install the Feeds module, which is the framework upon which Date iCal's
  import functionality is built.
- Login to your Drupal site and navigate to the admin/structure/feeds page.
- Click the "Add importer" link, and give it a name and description.
- Clicking "Create" will bring you to the general Feeds importer settings page.
  This page displays some general information about making Feeds importers,
  which you should familiarize yourself with.
- In the left sidebar, you'll see "Basic settings", "Fetcher", "Parser", and
  "Processor". The Parser and Processor settings are what we're interested in.
- In the Parser section, click "change". This will bring up the Parser
  selection page, on which you should select the radio button for "iCal Parser"
  and then click Save.
- Now, under Processor, click the "Settings" link. Most of the time, you'll
  want to use the "Update existing nodes (slower than replacing them)" setting.
  Then select the Content type of the nodes you'd like to create from iCal
  events. You can leave the other settings as their defaults, or change them
  as you need. Click Save.
- Now click the "Mapping" link at the bottom of the left sidebar. This page is
  where you'll define how iCal event properties get mapped into your nodes'
  fields. Expand the "Legend" for a detailed description of each source and
  target field. Sources are the attributes available in iCal event objects,
  and Targets are the fields in your nodes.
- Most of this setup is going to be dependent upon how your content type's
  fields are configured, but there are some universal requirements:
  1) You MUST map the "UID" source to the "GUID" target. Then, after clicking
     "Add", click the gear-shaped button that appears in the new table row,
     and check the "Unique" checkbox. Then click "Update", and then before
     you add any more mappings, click "Save" at the bottom of the page.
  2) It's a good idea to map the "Summary/Title" source to the "Title" target,
     and the "Description" source to whatever field is the "body" of the node.
  3) AS OF 2014/04/10 THERE IS A MAJOR BUG IN Feeds WHICH LEAVES THE DATE
     VALUES ON ALL IMPORTED EVENTS BLACNK. YOU MUST APPLY A PATCH TO Feeds
     TO FIX THIS PROBLEM. IT IS AVAILABLE HERE: http://drupal.org/node/2237177.
- Once you've completed all the mappings, click the "Save" button on the
  bottom left side of the page.
- Now you can import the iCal feed into nodes by going to the /import page of
  your site (e.g. http://www.exmaple.com/import). Click the link for the
  importer you just created, and enter the URL of the feed into the "URL"
  field. Click the "Import" button, and observe the progress.
- Once it's done, you should see a green message saying "Created X nodes." If
  you do, you've successfully set up your iCal importer. If you get some other
  message, you'll need to tweak the importer's settings.

Remember, you have to map the UID source to the GUID target, and make it
unique, or your imports won't work!


===============================================================================
IMPORTANT NOTE ABOUT THE DATE FIELD TIMEZONE SETTING
===============================================================================
Date fields have a setting called "Time zone handling" which determines how
dates are stored in the database, and how they are displayed to users.
 - "Site's time zone" converts the date to UTC as it stores it to the DB. Upon
  display, it converts the date to the "Default time zone" that's set on your
  site's Regional Settings configuration page (/admin/config/regional/settings).
 - "Date's time zone" stores the date as it is entered, along with the timezone
  name. Upon display, it converts the date from the stored timezone into the
  site's default timezone. Well, I'm pretty sure it's *supposed* to do that, but
  the code behind this setting is very buggy. DO NOT USE THIS SETTING.
 - "User's time zone" converts the date to UTC as it stores it to the DB. Upon
  display, it converts the date to the current user's timezone setting.
 - "UTC" converts the date to UTC as it stores it to the DB. Upon display, it
  performs no conversion, showing the UTC date directly to the user.
 - "No time zone conversion" performs no conversion as it stores the date in
  the DB. It also performs no conversion upon display.

The appropriate setting to choose here will depend upon how you want times to
be displayed on your site. The best setting *would* be "Date's time zone",
but since that setting is so buggy, I must recommend against it. Instead,
I'd suggest using "Site's time zone" for sites which host events that are
mostly in the same timezone (set the site's default timezone appropriately).
This works just right for local users of your site, and will be the least
confusing for users who live in a different timezone.

For sites which store events that take place in multiple different timezones,
the "User's time zone" setting is probably the most appropriate. Most users will
presumably be tuning in to your events online or on TV (since many take place
far away from them), which means they'll want to know what time the event occurs
in their local timezone, so they don't miss the broadcast.

If your Date field is already set to "Date's time zone", you won't be able to
change it, because that setting uses a different table schema than the others.
Since "Date's time zone" is very buggy, I'd strongly recommend deleting the
field and recreating it with a different setting. This will delete all the
dates in existing event nodes which use this field.


===============================================================================
HOW TO FIX THE "not a valid timezone" ERROR
===============================================================================
If you are seeing a warning about invalid timezones when you import an iCal
feed, you'll need to implement hook_date_ical_import_timezone_alter() in a
custom module to fix it. To do so, either edit an existing custom module, or
make a new module and add this function to it:

<?php
/**
 * Implements hook_date_ical_import_timezone_alter().
 */
function <module>_date_ical_import_timezone_alter(&$tzid, $context) {
  if (!empty($tzid)) {
    // Do something to fix your invalid timezone.
    // For instance, if all your events take place in one timezone, find your
    // region's official TZID, and replace $tzid with it. Like this:
    // $tzid = 'America/Los_Angeles';
  }
}
?>

Replace <module> with the name of your module, change the code to do whatever
needs to be done to fix your timezones, and clear your Drupal cache.


===============================================================================
ADDITIONAL NOTES
===============================================================================
Date iCal only supports exporting iCal calendars by using Views.
To put an "Add to calendar" button on individual event nodes, try the
Add to Cal module (http://drupal.org/project/addtocal), or follow the
instructions created by the estimable nmc at:
http://nmc-codes.blogspot.ca/2012/11/creating-ical-feed-for-single-node-in.html

The Feeds Tamper module is useful for altering the data in imported iCal feeds.

Developers who wish to implement more powerful manipulation of event data can
read the date_ical.api.php file to learn about the various alter hooks that
date_ical exposes.

The libraries/windowsZones.json file, which Date iCal uses to map Windows-style
timezone names to real timezone IDs, is from Version24 of the Unicode CLDR:
http://cldr.unicode.org/.

The author of iCalcreator made extenside backwards incompatible changes to the
library in the v2.22 release. Thus Date iCal does not support any version of
iCalcreator after v2.20.2.
