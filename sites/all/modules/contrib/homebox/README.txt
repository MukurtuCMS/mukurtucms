INSTALLATION
------------

 * Enable optional modules
   - Color picker - http://drupal.org/project/colorpicker
   - Views -  http://drupal.org/project/views
 * Enable Homebox module
 * Visit the Status Report page and make sure there are no Homebox errors
 * Go to Administer > Site building > Homebox
 * Create an new page


UPGRADING FROM 1.x TO 2.x
-------------------------

Sorry, but there is no upgrade path between the 1.x version of Homebox and the
2.x version. In order for Homebox 2 to work correctly, you must completely
uninstall any previous versions and cleanly install this version.


CONTROLLING ACCESS TO HOME BOX PAGES
------------------------------------

Access controls for Homebox pages (not the admin interface) are no longer
located in the standard Drupal permissions table. When creating/editing each
Homebox page, you can choose which roles are allowed to view the page. Unlike
other Drupal components, if you do not choose any roles, then only admins can
view the page. So, choose at least one role. For obvious reasons, anonymous
users will not be able to save pages or add custom items.


CREATING PANELS-LIKE HOME BOX LAYOUTS
-------------------------------------

Homebox can create panels-like layouts. After creating a new Homebox page,
click the 'Settings' link. Under the 'Custom column widths' fieldset, you can
specify the width percentage of each region. If you wanted to create a layout
like:

[-----top----]
[--l--][--r--]
[---bottom---]

You'd use widths of 100, 50, 50, and 100.


"CUSTOM ITEMS"
--------------

Users can enter custom items into their Homebox. Each Homebox page has the
option to turn this on or off. If set on, users can enter as many custom blocks
as they like - supplying a block title and body (full HTML allowed). This is
useful if they want to paste code for an external widget.


PROFILE INTEGRATION
-------------------

Homebox integrates with Drupal's core profile module. After creating a page,
you can navigate to admin/user/homebox and choose any available Homebox page to
reside as a tab on user's profiles. User's can only view their own Homebox
profile tab.


FEATURES INTEGRATION
--------------------

Homebox can import and export pages, as well as have them live in code. Because
of this, Homebox has been made to integrate with the Features.module. For more
information about Features, please visit http://drupal.org/project/features.
