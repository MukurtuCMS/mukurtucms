[![Build Status](https://travis-ci.org/subhojit777/views_base_url.svg?branch=7.x-1.x)](https://travis-ci.org/subhojit777/views_base_url)

This module provides a site base URL token in Views. The main purpose of this
module is to create a link with absolute path through **Global:Custom text**
option.

##### Usage:
- Select field formatter in view, and add **Global: Base url**
- Select **Exclude from display** option.
- Create custom link by adding a **Global: Custom text**
- Create link using replacement pattern like this:
```html
<a href="[base_url]/home">My home page</a>
```

##### Why use this module:
You can also create custom links though Drupal
[l()](https://api.drupal.org/api/drupal/includes!common.inc/function/l)
function, in this case you have to use
[Views PHP](https://www.drupal.org/project/views_php) module. The code is stored
in database, hence it will not be cached. PHP execution through
[eval()](http://www.php.net/manual/en/function.eval.php) is slow.
This module eliminates this problem.

##### Alternatives:
Only module I found closest to this is
[Views BaseURL](https://www.drupal.org/sandbox/ergonlogic/1274240), it's in
sandbox and that too it was last modified years ago, means its not maintained.
