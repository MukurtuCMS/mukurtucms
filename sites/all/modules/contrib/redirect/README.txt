CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Installation
 * Recommended Modules
 * Configuration
 * Maintainers


INTRODUCTION
------------

The Redirect module provides a unified redirection API (also replaces
path_redirect and globalredirect) and allows users to redirect from old URLs to
new URLs.


 * For a full description of the module visit:
   https://www.drupal.org/project/redirect

 * To submit bug reports and feature suggestions, or to track changes visit:
   https://www.drupal.org/project/issues/redirect


REQUIREMENTS
------------

This module requires no modules outside of Drupal core.


RECOMMENDED MODULES
-------------------

Multi-path autocomplete helps provide auto-complete listings for the destination
textfield on the redirect form.
 * Multi-path autocomplete - https://www.drupal.org/project/mpac

Pathauto can be configured to automatically generate path redirects to ensure
that URL alias changes do not break existing links.
 * Pathauto - https://www.drupal.org/project/pathauto

Pathologic helps transform relative links in content to absolute URLs. Most
helpful when you move your site to a new domain or different folder.
 * Pathologic - https://www.drupal.org/project/pathologic

Match Redirect provides redirecting based on path patterns with wildcards. Does
not extend or require the Redirect module itself.
 * Match Redirect - https://www.drupal.org/project/match_redirect


INSTALLATION
------------

 * Install the Redirect module as you would normally install a contributed
   Drupal module. Visit https://www.drupal.org/node/895232 for further
   information.


CONFIGURATION
--------------

    1. Navigate to Administration > Modules and enable the module.
    2. Navigate to Administration > Configuration > Search and Metadata > URL
       redirects for configuration.
    3. Select "Add redirect" and in the "Path" field add the old path.
    4. In the "To" field, start typing the title of a piece of content to select
       it. You can also enter an internal path such as /node/add or an external
       URL such as http://example.com. Enter <front> to link to the front page.
    5. Open the Advanced options and select the Redirect status: 300 Multiple
       Choices, 301 Moved Permanently, 302 Found, 303 See Other, 304 Not
       Modified, 305 Use Proxy, or 307 Temporary Redirect. Save.
    6. Once a redirect has been added, it will be listed in the URL Redirects
       vertical tab group on the content's edit page.



MAINTAINERS
-----------

 * Sascha Grossenbacher (Berdir) - https://www.drupal.org/u/berdir
 * Dave Reid - https://www.drupal.org/u/dave-reid

Supporting organizations:

 * Lullabot - https://www.drupal.org/lullabot
 * Acquia - https://www.drupal.org/acquia
