SCALD FILE
---------------------------------

Homepage: http://drupal.org/project/scald_file

Contents of this file:

 * Introduction
 * Installation

INTRODUCTION
------------

This module introduces a file provider for the scald module. 
It also provides a common display for all the files in wysiwyg,
atom reference fields and in the library, where the file type 
icon is shown with the filename, and the filename is a link 
to the actual file.

INSTALLATION
------------

Scald file depends on the following module:

- Scald version 1.2 or higher

OPTIONAL COMPONENTS
-------------------
In order to have a preview of the PDF files in the thumbnail,
you may install one of the following:
 * mudraw CLI command (mupdf-tools or mupdf package)
 * pdfdraw CLI command
 * convert CLI command (imagemagick package)
 * Imagick PHP extension

For the CLI commands, PHP must be able to exec().
