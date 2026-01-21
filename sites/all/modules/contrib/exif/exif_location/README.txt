README file for the EXIF Location Drupal module.

Description
***********
This module provides a bridge between EXIF and Node Locations modules by
copying field_gps_gpslatitude and field_gps_gpslongitudelatitude values
(extracted from an image by the EXIF module) into the latitude and longitude
fields of a node.


Requirements
************
EXIF (http://drupal.org/project/exif)
Location (http://drupal.org/project/location)
Node Locations (a submodule included with Location)


Usage
*****
There are no settings for this module. If the node's Latitude and Longitude
fields are empty and EXIF latitude and longitude data exists, then it will be
copied to the Location fields. This design allows EXIF data to be used as a
starting point with further refinement of coordinates still possible using
Location module.

To restore the original EXIF data as coordinates, simply remove the latitude
and longitude values from the node's location.
