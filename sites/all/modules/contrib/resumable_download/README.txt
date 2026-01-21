--- README  -------------------------------------------------------------

Resumable download

Written by Sina Salek
  http://sina.salek.ws


-- Description --------------------------------------------------------
Drupal does not support download resume , meaning that downloading large private files can be troublesome because if for any
reason the download fails , there is no way to continue downloading from where it stopped and the whole file should be
downloaded again.

It also supports several extra features
  
--- Features --------------------------------------------------------

* Multi Part/Section file download
* Resumable file download
* Download speed limit support
* Automatic client download abort detection

--- INSTALLATION --------------------------------------------------------

1. Install module, if you don't know how to do it , read this : http://drupal.org/node/70151

2. Enable "Resumable Download" under Administer > Site building > Modules.

--- Usage --------------------------------------------------------

If you want to limit download speed as well , goto admin/config/media/file-system/resumable_download

NOTICE : This module overwrites Drupal's file download method using alter menu, so if another module does the same
 It may conflict with this module and prevent it from working properly

--- Support --------------------------------------------------------

Found a bug? report it here http://drupal.org/node/add/project-issue/resumable_download