Drupal select2 module:
------------------------
Maintainers:
  Andrey G Polyakov (http://drupal.org/user/1200780)
Requires - Drupal 7, Libraries API (7.x-2.x), jQuery Update 
License - GPL (see LICENSE)


Overview:
--------
Select2 is a jQuery (1.8.2+) based replacement for select boxes.
It supports searching, remote data sets, and infinite scrolling of results.
This module allows for integration of Select2 into Drupal.
The jQuery library is a part of Drupal since version 5+.

* jQuery - http://jquery.com/
* Select2 - http://ivaynberg.github.io/select2/


Features:
---------

The Select2 module:

* Provide function for using Select2 plugin by Drupal Form API

The Colorbox plugin:

* Enhancing native selects with search.
* Enhancing native selects with a better multi-select interface.
* Loading data from JavaScript: easily load items via ajax and have them searchable.
* Nesting optgroups: native selects only support one level of nested. Select2 does not have this restriction.
* Tagging: ability to add new items on the fly.
* Working with large, remote datasets: ability to partially load a dataset based on the search term.
* Paging of large datasets: easy support for loading more pages when the results are scrolled to the end.
* Templating: support for custom rendering of results and selections.


Installation:
------------
1. Download and unpack the Libraries module (2.x) directory in your modules folder
   (this will usually be "modules/").
   Link: http://drupal.org/project/libraries
2. Download and unpack jQuery Update module - you must use jQuery Update module version
   that can set jQuery version for admin pages - 7.x-2.x-dev at this moment (01-01-2014). 
   Use 1.8 or higher version of jQuery.
2. Download and unpack the Select2 module directory in your modules folder
   (this will usually be "modules/").
3. Download and unpack the Select2 plugin (3.4.5+) in "libraries".
    Make sure the path to the plugin file becomes:
    "libraries/select2/select2.js"
   Link: https://github.com/ivaynberg/select2/tags
4. Go to "Administer" -> "Modules" and enable the Select2 module.


Configuration:
-------------
Go to "Configuration" -> "User Interface" -> "Select2" to find
all the configuration options.


Using Select2 in Forms API:
----------------------------------------
For attaching Select2 plugin with custom properties to form element
you must define '#select2' key as array for form element

  'products_categories' => array(
    '#title' => t('Element title'),
    '#type'     => 'select',
    '#options' => array(),
    '#empty_option' => t('Select element'),
    '#multiple'     => 1,
    '#select2' => array(),
  );

You can define all (except value as function) properties of Select2 plugin
(look at http://ivaynberg.github.io/select2/#documentation), in "#select2" array
of element: array key - property name, value - property value. 

  'products_categories' => array(
    '#title' => t('Element title'),
    '#type'     => 'select',
    '#options' => array(),
    '#empty_option' => t('Select element'),
    '#multiple'     => 1,
    '#select2' => array(
      'width' => 300,
      'allowClear' => true,
      'minimumInputLength' => 1,
      ...
    ),
  );

For some fields (if field type supported by module) you can define Select2 properties on field settings page.


  