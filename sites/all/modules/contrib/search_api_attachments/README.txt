INTRODUCTION
------------

Search API Attachments

This module is an add-on to the Search API which allows the indexing and
searching of attachments.

The extraction can be done using :
Apache Tika Library
or
The Solr built-in extractor
or
Acquia Search
or
pdftotext for pdfs
or
python pdf2text for pdfs

REQUIREMENTS
------------

Requires the ability to run java on your server and an installation of the
Apache Tika library if you don't want to use the Solr build in extractor.

PHP-iconv to index txt files.

MODULE INSTALLATION
-------------------
Copy search_api_attachments into your modules folder

Install the search_api_attachments module in your Drupal site

Go to the configuration: admin/config/search/search_api/attachments

Choose an extraction method and follow the instructions under the respective
heading below.


EXTRACTION CONFIGURATION (Tika)
-------------------------------

Install java

Download Apache Tika library: http://tika.apache.org/download.html
Downloaded file is something like tika-app-y.x.jar

in admin/config/search/search_api/attachments, Enter the parent directory
and the file name of the .jar file.

- Hidden settings

search_api_attachments_java:
  By changing this variable, you can set the path to your java executable. The
  default is 'java'.

EXTRACTION CONFIGURATION (Solr)
-------------------------------

This requires Solr search (search_api_solr) module and the Solr config files
that come with it.

Please follow the Solr search module instructions for configuring asearch api
solr server.

EXTRACTION CONFIGURATION (Pdftotext)
------------------------------------

Pdftotext is a command line utility tool included by default on many linux
distributions. See the wikipedia page for more info:
https://en.wikipedia.org/wiki/Pdftotext

EXTRACTION CONFIGURATION (python Pdf2txt)
-----------------------------------------

Install Pdf2txt (tested with package version 20110515+dfsg-1 and python 2.7.9)
> sudo apt-get install python-pdfminer

SUBMODULES
-------------------------------
For each of these, find more details in contrib folder.

search_api_attachments_comment
search_api_attachments_commerce_product_reference
search_api_attachments_entityreference
search_api_attachments_field_collections
search_api_attachments_links
search_api_attachments_multifield
search_api_attachments_multiple_entities
search_api_attachments_paragraphs
search_api_attachments_references
search_api_attachments_user_content

CACHING
-------
Extracting files content can take a long time and it may not be needed to do it
again each time a node gets reindexed.
search_api_attachments have a cache bin where we store all the extracted files
contents: this is the cache_search_api_attachments table.
cache keys are in the form of: 'cached_extraction_[fid]' where [fid] is the file
id.
When a file is deleted or updated, we drop its extracted stored cache.
When the sidewide cache is deleted (drush cc all per example) we drop all the
stored extracted files cache only if 'Preserve cached extractions across cache
 clears.' option is unchecked in the configuration form of the module.

DEVELOPMENT
-----------
On the admin form of Search API attachements, you can enable the debug feature.
It will add a lot of information in the watchdog while indexing.

Hidden Features
---------------
This module suggests a Views filter to choose to search in attachments files too
or not.

HOOKS
-----
This module provides hook_search_api_attachments_indexable.
See more details in search_api_attachments.api.php
