CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Recommended Modules
 * Installation
 * Configuration


INTRODUCTION
------------

The Chaos tool suite (ctools) module is primarily a set of APIs and tools to
improve the developer experience. It also contains a module called the Page
Manager whose job is to manage pages. In particular it manages panel pages, but
as it grows it will be able to manage far more than just Panels.

The Chaos Tool Suite (ctools) is a series of tools that makes code readily
available for developers and creates libraries for other modules to use. Modules
that use ctools include Views and Panels.

End users will use ctools as underlying user interface libraries when operating
Views and Panels modules and will not need to explore further (ctools is geared
more toward developer usage). Developers will use the module differently and
work more with the tools provided.

For the moment, it includes the following tools:

 * Plugins -- tools to make it easy for modules to let other modules implement
   plugins from .inc files.
 * Exportables -- tools to make it easier for modules to have objects that live
   in database or live in code, such as 'default views'.
 * AJAX responder -- tools to make it easier for the server to handle AJAX
   requests and tell the client what to do with them.
 * Form tools -- tools to make it easier for forms to deal with AJAX.
 * Object caching -- tool to make it easier to edit an object across multiple
   page requests and cache the editing work.
 * Contexts -- the notion of wrapping objects in a unified wrapper and providing
   an API to create and accept these contexts as input.
 * Modal dialog -- tool to make it simple to put a form in a modal dialog.
 * Dependent -- a simple form widget to make form items appear and disappear
   based upon the selections in another item.
 * Content -- pluggable content types used as panes in Panels and other modules
   like Dashboard.
 * Form wizard -- an API to make multi-step forms much easier.
 * CSS tools -- tools to cache and sanitize CSS easily to make user-input CSS
   safe.

 * For a full description of the module visit:
   https://www.drupal.org/project/ctools

 * To submit bug reports and feature suggestions, or to track changes visit:
   https://www.drupal.org/project/issues/ctools


REQUIREMENTS
------------

This module requires no modules outside of Drupal core.


RECOMMENDED MODULES
-------------------

The Advanced help module provides extended documentation. Once enabled,
navigate to Administration > Advanced Help and select the Chaos tools link to
view documentation.

 * Advanced help - https://www.drupal.org/project/advanced_help


INSTALLATION
------------

 * Install the Chaos tool suite module as you would normally install a
   contributed Drupal module. Visit https://www.drupal.org/node/895232 for
   further information.
