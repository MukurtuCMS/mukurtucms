# TODOs

This file tracks backwards-incompatible tasks for a major rewrite.

* Do not catch exceptions inside class, leave it to client implementation instead.
* Rewrite and require PHP 5.3+, leverage (vendor) namespaces, rename to `Mollom\Client`.
* Add unit tests based on [PHPUnit](http://phpunit.de).
* Re-implement based on [Guzzle](http://guzzlephp.org), leverage its OAuth plugin and support for Web Service Definitions (WSD).

