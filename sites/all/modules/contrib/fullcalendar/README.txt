This module requires the 3rd party library for FullCalendar located at
http://arshaw.com/fullcalendar.

Download the most recent version of the plugin. When unzipped, the plugin
contains several directories. The fullcalendar/fullcalendar directory should be
moved to sites/all/libraries/fullcalendar
(e.g., sites/all/libraries/fullcalendar/fullcalendar.min.js). Do not include
the demos or jQuery directories.

If you are using drush, using `drush fullcalendar-plugin` will download the
correct version of the plugin and move the files accordingly.

To use the FullCalendar module:
  1) Install Views, Date, Date API, and Date Views modules
  2) Create a new entity that has a date field
  3) Create a view and add filters for the entity
  4) In the "Format" section, change the "Format" to "FullCalendar"
  5) Optionally, enable the "Use AJAX" option under "Advanced"
