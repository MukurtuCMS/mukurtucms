
IP GEOLOCATION VIEWS AND MAPS
=============================
This documentation concentrates on the installation and configuration of the
IP Geolocation Views & Maps (IPGV&M) module. For an overall introduction see
http://drupal.org/project/ip_geoloc.

IMPORTANT:
---------
The Google Maps API, which include geolocation services, requires either a
Google API Key or a Google Client ID. If you are using Leaflet maps you may
still need a key when you use geolocation services also.
Obtain a free API Key or Client ID here:
https://developers.google.com/maps/documentation/javascript/get-api-key


CONFIGURATION OF VIEW-BASED MAPS
================================
Read this if you are using IPGV&M primarily for its Views mapping interface. If
you focus is on the recording of visitor locations, past and present, read the
next section.

Download and enable IPGV&M like any other module. Then visit its configuration
page, .../admin/config/system/ip_geoloc.
If you intend to use IPGV&M's built-in interface to Google Maps, untick all
"Data collection option" boxes.
If you intend to use IPGV&M with the OpenLayers (v2) or Leaflet modules and also
wish to show and center on the visitor's HTML5 retrieved location, then you have
two options:
a) tick the first "Data collection option" and select applicable roles below it
b) enable the "Set my location" block, so visitors can center the map using
their HTML5 location, or, using the same block type, a city or partial address,
like "New York".

You are now ready to map your View of Location, Geofield, Geolocation Field or
GetLocations.

If you have one of the Location, Geofield, Geolocation Field or Get Locations
modules enabled, then first create a normal tabular content View of nodes that
hold location coordinates via one of these modules. The coordinate fields will
show up in the Field list of your View.
Unless you use the Location module (with User Locations or Node Locations), make
sure you have included in your view's field selection a field named "Content:
your_Geofield/Geolocation_field". Only one copy is required, you do NOT need
both a latitude version plus a longitude version. The "Formatter", if it pops
up, is relevant only if you want the location field to appear in the marker
balloons. Make sure "Use field template" is UNTICKED. Commerce Kickstart tends
to have the box ticked, so UNTICK it. Untick it for the differentiator too, if
used.
Then, after selecting the View Format "Map (Google, via IPGV&M)", "Map (Leaflet,
via IPGV&M)" or "Map (OpenLayers, via IPGV&M)" select or type field_name in the
"Name of latitude field in Views query".
Note that IPGV&M can handle multiple fields containing latitudes. This comes in
handy when your View brings together content types with different latitude field
machine names. When using multiple fields for the latitude, you must select
<none> for "Name of LONGITUDE field in Views query".
Fill out the remaining options to your liking. Save.

Visit the IPGV&M configuration page to specify an alternative marker set. When
using Leaflet you can superimpose scalable font icon on top of your markers, as
found at http://text-symbols.com, flaticon.com or fontello.com. See below for
details.

The "Views PHP" module is required for the included /visitor-log View.

The core module Statistics must be enabled also when you wish to collect visitor
data. It is not required for maps in general.

The "Session Cache API" and "High-performance Javascript callback handler"
(7.x-2.x) modules are optional, but recommended.

If you want to center the map on the visitor's location, but don't want to use
the HTML5 style of location retrieval involving a browser prompt, you an UNtick
the box "Employ the Google Maps API to reverse-geocode HTML5 visitor locations
to street addresses" and configure an alternative lat/long lookup based on IP
address. For this follow installation instruction B1a or B1b below, depending on
whether you'd like to employ Smart IP or GeoIP for this.
Or you can enable the "Set my location" block, which will only prompt the user
to confirm when they explicitly request to share and reverse-geocode their
location.

TROUBLE-SHOOTING
================
You can switch on useful debug and status messages per USER (rather than role)
at admin/config/system/ip_geoloc, section "Advanced options".

CONFIGURATION FOR COLLECTION OF VISITOR RESULTS
===============================================
Location providers supported by this module include the specific hardware
(desktop, tablet, phone...) your visitors use, which may employ GPS, WiFi and
mobile cell towers. Nowadays the fine detail can be almost frightening, i.e.
lat/long coordinates with an accuracy of 30 meters and postal addresses down to
the street and street number. If you don't want to collect or expose this degree
of detail, you can switch it off on the configuration page and have IPGV&M fall
back on a less fine-grained service or API, as provided by Smart IP, GeoIP API
or one you write yourself.
The process used is called reverse-geocoding. IPGV&M therefore adds to
geocoding modules like Location, Geofield/Geocoder, Geolocation field or
Get Locations, which are about giving users the facility to enter postal
addresses or lat/long coordinates themselves and then mapping those.
IPGV&M is also different from most in that, if desired, it can collect locations
of guests that visited your site from before you installed this module, going
back all the way to the day you launched your site.
For present and future visitor geolocation information IPGV&M's built-in data
collection techniques are hard to beat and may involve WiFi, GPS and mobile cell
towers. For historic visitor data, IPGV&M supports existing tried-and-tested
contributed modules to pull in IP-to-lat/long and IP-to-city/suburb/village
data. The following modules are supported as lat/long data sources:

o Smart IP (its submodule Device Geolocation is not required)
o GeoIP API (note: the port of this module to D7 appears to be still in
  progress, but this dev version appears to work fine).
o any module that implements hook_get_ip_geolocation_alter($location) -- see the
For programmers section further down this page
IPGV&M does not require you to load any libraries. You do not need to register
for any API keys, except when you use Smart IP in combination with the IPinfoDB
web service. The API key required on the Smart IP configuration page is free and
is sent to you by return email after you've applied at
http://ipinfodb.com/register.php. Alternatively you could use the file-based
option of Smart IP or employ GeoIP API, which is also based on a file,
downloadable from here: GeoLiteCity.dat.gz. The file is free and no key is
required.
For reasons of reporting efficiency and flexibility via Views IPGV&M maintains
its own small database of location information of past visitors to your site.
It does not copy the entire Smart IP or GeoIP databases.

If you want to auto-record visitor address details then complete the steps
under A and B below.

A. Present and future: maps of guests visiting after you enabled IPGV&M
-----------------------------------------------------------------------

1. Install and enable like any other module, use Drush if you wish. Remain
connected to the internet.

2. Make sure the core Statistics module is enabled. Then at Configuration >>
Statistics, section System, verify that the access log is enabled. Select the
"Discard access logs older than" option as you please. "Never" is good.

3. Visit the IPGV&M configuration page at Configuration >> IP Geolocation V&M
If you don't see any errors or warnings (usually yellow) you're
good to proceed. Don't worry about any of the configuration options for now,
the defaults are fine.

4. At Structure >> Blocks put the block "Map of 20 most recent visitors" in the
content region of all or a selected page. View the page. That marker represents
you (or your service provider). Clicking the marker reveals more details.

5. Enable the Views and Views PHP (http://drupal.org/project/views_php) modules.
Then have a look at Structure >> Views for a couple of handy Views, e.g. the
"Visitor log", which shows for each IP address that visited, its street address,
as well as a local map. Or "Visitor log (lite)", which combines nicely when put
on the same page with the block "Map of 20 most recent visitors".
Modify these views as you please.

B. Historic data: location info about visits to your site from way back when
----------------------------------------------------------------------------

Note, that this step relies on you having had the Statistics module enabled
before you installed IPGV&M, as the access log is used as the source of IP
addresses that have visited your site previously.
There are a couple of options here. Use either
http://drupal.org/project/smart_ip and one of the web services it uses, or
http://drupal.org/project/geoip, which takes its data from a file you download
for free.

1a. If you decide to employ Smart IP....
Install and enable Smart IP. There is no need to enable the Device Geolocation
submodule as IPGV&M already has that functionality, plus more. At
Configuration >> Smart IP you'll find a number of source to upload historic
lat/long data. Pick any of these. A low-cost option is to download
http://geolite.maxmind.com/download/geoip/database/GeoLiteCity.dat.gz and
uncompress it in /sites/default/private/smart_ip.
You may untick all the check boxes under the heading "Smart IP settings" on
the Configuration >> Smart IP page.

1b. If you decide to employ GeoIP instead of Smart IP...
Download and enable the module. Then download
http://geolite.maxmind.com/download/geoip/database/GeoLiteCity.dat.gz and 
uncompress it in sites/all/libraries/geoip. Go to the GeoIP configuration page
and type the name of the file you've just downloaded, GeoLiteCity.dat. Save.

2. With either Smart IP or GeoIP configured, visit Configuration >> IPGV&M.
Tick the check boxes as appropriate.

3. On the same page, start a small batch import of, say, size 10. Data for the
most recent visitors will be loaded first, so you don't have to complete the
import to check it's all working. For instance, the block "Map showing locations
of 10 most recent visitors" should now show more markers.

4. Go back the Configuration >> IPGV&M and complete the import process
with a larger batch size until the IP geolocation database is up to date with
the access log. It will automatically remain in sync from now on.

LEAFLET TIPS
============
You need to download and install the Leaflet package on your system, but you
only have to enable the main module, no need for the Leaflet Views submodule.
Don't forget to download the Leaflet javascript library from
http://leafletjs.com/download.html dropping it in sites/all/libraries and
changing the folder name to leaflet. Remember to install and enable the
Libraries API module too.
When all's ok, you won't see any errors in the Status Report, i.e.
.../admin/reports/status.

OPENLAYERS TIPS
===============
Use http://drupal.org/project/openlayers version 7.x-2.0 or 7.x-2.x.
Of the modules in the OpenLayers package you only need to enable OpenLayers and
OpenLayers UI. In fact, you could even disable OpenLayers UI when you're done
configuring your maps.
Initially the location markers are likely to show up as black circles. To
change the marker shapes and colours you need to first associate the "Location
markers" layer with your map at Structure >> OpenLayers >> Maps >> List. If
there is no custom map on this page yet, you have to first clone and save under
a different name one of the existing maps. Once you've done that, you'll find
that on Structure >> OpenLayers >> Maps >> List the map appears with an Edit
link. Click that, followed by the "Layers & Styles" vertical tab. In the bottom
section of the page you'll find the "Current visitor marker" layer and a number
of "Location markers" layers. You'll only need to activate Location markers #1,
unless you have defined a "differentiator" (e.g. taxonomy term) on your view.
Pick marker styles from the drop-downs as you please and press Save. Note that
the location markers won't show up in the map preview, but the visitor marker
should. This is because the map doesn't know which view it will be paired with.
In fact there may be several views using the same map. Return to edit your view.
Under Format, Settings select the map you've just created and edited. Save the
format and the view. Visit the page containing your view and all markers should
appear in the colours you chose.
In order to make the text balloons pop up at a marker when hovered or clicked,
visit Structure >> OpenLayers >> Maps >> Edit and click the "Behaviors"
vertical tab. Scroll down the page until you reach the "Pop Up for Features"
check box. Tick it and select the layers you're interested with, e.g.
ip_geoloc_visitor_marker_layer1 and/or ip_geoloc_marker_layer. Same for
"Tooltip for Features". Other nice behaviors that you may wish to flick on on
the same page are "Full Screen", "Layer Switcher", "Pan and Zoom Bar Controls"
and "Scale Line".

ALTERNATIVE MARKER ICONS (LEAFLET, GOOGLE MAPS)
===============================================
Find on the web a marker icon set you like, eg http://mapicons.nicolasmollet.com
Download and extract the icon image files, which must have extension .png,
into a directory anywhere in your Drupal install, maybe
sites/all/libraries/map_markers1.
Now visit the IPGV&M configuration page at admin/config/system/ip_geoloc.
Expand the "Alternative markers" fieldset.
Enter the path to your markers directory and the dimensions of your markers.
The marker set will now be available in your map settings, in particular in the
differentiator settings.

FONT ICONS SUPERIMPOSED ON YOUR MARKER IMAGES (LEAFLET)
=======================================================
Some of the benefits of font icons are described in this article:
http://flink.com.au/ramblings/spruce-your-map-markers-font-icons

Most font icon libraries can be used and more than one can be used at the same
time. However some libraries may require some CSS tweaking in your theme file to
size and position the icons in the center of the markers you are using.
The style sheets that come with IPGV&M have been tested to work well in most
themes with the icons from fsymbols, Font Awesome and flaticon.

fsymbols can be copied and pasted from http://text-symbols.com/ as needed on the
IPGV&M Views map configuration panel. No need to refer to any library. Not all
of the fsymbols will agree with your database. The ones that don't work usually
show up as little squares when pasted.

To install Font Awesome visit http://fortawesome.github.io/Font-Awesome and
press the "Download" button. Unzip the downloaded file into the Drupal
libraries directory, typically sites/all/libraries. If you wish, remove the
version number from the directory name, so that the path to the essential style
sheet becomes sites/all/libraries/font-awesome/css/font-awesome.min.css.
Then enter that path at admin/config/system/ip_geoloc.
You can assemble your own icon set from Font Awesome and other repositories at
fontello.com and download it to sites/all/libraries. Then again enter the path
to the main .css file at admin/config/system/ip_geoloc.

Similarly flaticon icon packs can be selected from http://www.flaticon.com.
First create the directory sites/all/libraries/flaticon, then download and unzip
the pack into that directory, so that the path to the essential style sheet is
sites/all/libraries/flaticon/PACK/flaticon.css, where PACK may be something like
"food-icons".
Then enter that path at admin/config/system/ip_geoloc.

What to do when my font icons are off-centre, too big or too small?
-------------------------------------------------------------------
Because font icons are infinitely scalable this is easily fixed. In your theme
CCS file (style.css?) override the applicable styles from
ip_geoloc/css/ip_geoloc_leaflet_markers.css, in particular the attributes
"top", "left" and "font-size".

CLUSTER REGION DIFFERENTIATOR
=============================
The benefits of region-aware clustering are demonstrated here: regionbound.com
If you already use the Leaflet MarkerCluster module, then you can enhance it
with superior region-aware clustering by dropping into
sites/all/libraries/leaflet_markercluster/dist the .js file from the
regionbound.com download.
Check the Status Report page to see if IPGV&M automatically detected the new JS.
Now you can configure the region-aware clustering algorithm by filling out the
Cluster Region Differentiator panel on the IPGV&M Views UI.
Your View, and subsequently the content type that has a lat/lon associated with
it, must feature ONE of the following.
1a An AddressField (as in the http://drupal.org/project/addressfield module)
   in this case IPGV&M will automatically use for differentiation the
   region-hierarchy of the address field components country, administrative
   area, locality and postcode
1b Selected AddressField components: single out the ones you want to use
2  A selection of plain text fields designated by you to form the equivalent
   of an address, e.g., country, state, city.
3  Taxonomy term reference that refers to a hierarchical region vocabulary.
   Here's an example of a simple 2-level region vocabulary:
   - Melbourne
     -- CBD
     -- North
     -- East
     -- South
     -- West
   - Sydney
     -- CBD
     -- North
     -- East
     -- South
     -- West
   You can have as many levels in the region hierarchy as you like. Go for
   something that adequately reflects the scope and detail of your locations.


ADVANCED OPTIONS
================
If you use Geofield for coordinate storage, you have a number of great options
to create sophisticated maps. First you can use Geofield in combination
with Geocoder and AddressField (or any plain textfield) to have lat/lon
auto-generated from the street address typed on each piece of content.

Second, you get some great Views filters thrown in. When you select Geofield's
proximity filter you get a new option for the "Source of Origin Point", named
"Geocoded location with HTML5" default. When the visitor does not type in a
location into the exposed proximity filter, or types "me", the filter will use
the visitor's current location as the center of your map as well as the source
of origin for distance calculations. So your map will only show locations within
the specified radius.
You can display these distances in the marker balloons and/or a tabular
attachment too, by adding the Geofield proximity field in the Views UI. When
it comes to specifying the "Source of Origin Point" pick "Exposed Geofield
Proximity Filter" so that the distance quoted is with respect to the location
that the exposed filter is set to, be it a typed location or the visitor's HTML5
location.

To top it all off, add the "IPGV&M: Set my location" block, which supplies 3
ways for the user to specify the center of the map: by typed address, by region
taxonomy and by an explicit request to perform an HTML5 lookup. The latter
means that you can switch off the periodic prompting to share location, which
can become annoying, i.e. you can UNtick the box "Employ the Google Maps API to
reverse-geocode HTML5 visitor locations to street addresses".

HIGH PERFORMANCE AJAX
=====================
IPGV&M will take advantage of the "High-performance Javascript callback
handler" (7.x-2.x), if installed.

NOTE: the 7.x-2.x version of https://drupal.org/project/js has not been
working very well with IPGV&M lately. We discourage using it with IPGV&M

Installation instructions for Nginx: http://drupal.org/node/1876418
Installation instructions for Apache: 
o download and enable https://drupal.org/project/js, version 7.x-2.x
o find the .htacess in your document root -- the same folder as index.php
o visit admin/config/system/js; it displays 5 lines tailored for your server
o copy those lines and paste them into .htaccess below the line
  "RewriteEngine on".

IPGV&M will now perform its AJAX calls more efficiently. Results vary and 
depend not so much on IPGV&M but on the complexity and speed of your site during
initialisation. For an "average" site, expect a reduction of the page load time
of about 0.3s for the "Find me" function of the "Set my location" block, which
currently is the only place where the Javascript callback handler is used.

To switch this feature off, comment out the newly added lines from the
.htaccess file by putting a # in front of each of the 5 lines.

CONDITIONAL LOCATION FIELDS
===========================
Here's a great example on how to use IPGV&M in combination with the Views
Conditional module https://www.drupal.org/node/2470265 (solution in entry #4).

CONTEXT AND CONTEXT-SESSION MODULES
===================================
IPGV&M implements a "Locate visitor using GPS/Wifi" reaction for the Context
module, https://www.drupal.org/project/context.
If you also use enable the https://www.drupal.org/project/context_mobile_detect
module, then you can locate a visitor only when they're using, say, a phone or
tablet and only on certain pages (using Context's path condition).

You can also switch context using any address component as a condition, if you
also enable https://www.drupal.org/project/context_session.
Example: "location.locality=Melbourne"
context_session does not support the Session Cache API module, so, if you use it
the $_SESSION variable will still be used internally for storage.

ALTERNATIVE THROBBER
====================
Out of the box the "Set my location" block uses core's small throbber. If you
wish to use an alternative one, simply comment out the relevant lines in
file ip_geoloc/css/ip_geoloc_all.css
Depending on your theme, you may want to tweak your CSS a little.

FOR SITE BUILDERS AND PROGRAMMERS
=================================
IPGV&M stores location data for the current visitor in their session and makes
it available via ip_geoloc_get_visitor_location(). So you can display content
conditionally on the country or city that your users are visiting from. For
instance you can restrict visibility of a block containing an ad or a news flash
relevant only to a particular city by entering this little snippet in the
"Visibility settings" of the block, under "Pages on which this PHP code returns
TRUE":
<?php
  $location = ip_geoloc_get_visitor_location();
  return isset($location['locality']) && $location['locality'] == 'Melbourne';
?>

For debugging purposes you can display in a block the current user's session
location data. First make sure that you have the core module "PHP filter"
enabled. Then go Structure >> Blocks >> Add block. Set the Text forma to
"PHP code". For something half readable enter in the block body something like
this:
<?php
  foreach (ip_geoloc_get_visitor_location() as $key => $value) {
    echo "$key: $value <br>";
  }
?>
Note that, in order to see any meaningful session data when running on a local
server (127.0.0.1), you must be connected to the internet and have ticked at
Configuration >> IP Geolocation Views and Maps the data collection option
"Employ a free Google service to periodically auto reverse-geocode visitor
locations to street addresses". When debugging it is also recommended to
activate on the same page the advanced option "Detail execution progress with
status messages".

See ip_geoloc.api.php for functions to retrieve and respond to lat/long and
address information and to generate maps. Below are some of the functions
available. See ip_geoloc/ip_geoloc_api.inc for details.

function ip_geoloc_output_map_current_location($div_id, $map_opts...)
function ip_geoloc_output_map_multi_locations($locations, $div_id, $map_opts....)
function ip_geoloc_distance($location, $ref_location='current visitor');

Add, remove or alter locations as returned by the View before they're being
mapped, by implementing:
function hook_ip_geoloc_marker_locations_alter(&$locations, $view);

Some suspected web crawlers
You may find that the following are great fans of your web site, visiting it
repeatedly ;-)
"Mountain View, CA 94043, USA" (Google, IPs 66.249.68.*, 66.249.69.* etc)
"Sunnyvale, CA 94089, USA" (Yahoo!, IPs 67.195.*.*)
"Dongcheng, Beijing, China" (IPs 123.125.71.*, 180.76.5.*)

See also http://whois.domaintools.com

AUTHOR
======
rik @ flink dot com dot au, Melbourne, Australia.
