<!-- @file Overview of the theme registry workflow in Drupal Bootstrap. -->
<!-- @defgroup registry -->
# Theme Registry

- [File Structure](#file-structure)
- [Theme Functions](#theme-functions)
- [Theme Process and Preprocess Functions (.vars.php)](#theme-preprocess)
- [Theme Templates](#theme-templates)
- [Theme Hook Naming Conventions](#theme-hook-naming-conventions)

## File Structure
The [Drupal Bootstrap] base theme handles some very complex theme registry
alterations to assist with the organization and maintenance of its source code.

By leveraging Drupal's ability to include files only when a specific theme hook
is invoked, this base theme is able to reduce its per page PHP memory footprint.
It also allows for easier maintenance and organization with as many overrides as
this base theme implements.

This base theme provides a multitude of [pre]process functions, theme functions
and templates stored inside the `./bootstrap/templates` folder. The base
theme will traverse all folders inside this folder as well as a subtheme's
`./subtheme/templates` folder.

Over time this base theme has grown exponentially and this type of change will
help ensure future growth, without sacrificing performance. It's an easy and
hierarchical folder structure based on the module they originated from.

Sub-themes, while not required to do so, can emulate this same type of file
structure and take advantage of this base theme's unique ability.

Rest assured though, there is no need to structure your sub-theme this way. If
you feel more comfortable storing everything in your sub-theme's '`template.php`
file, feel free to do so.

It's highly recommended, however, that you at least understand how the base
theme structures its functions and templates so you can easily copy them over
to your sub-theme should the need arise.

## Theme Functions (.func.php) {#theme-functions}
Theme functions can be be stored in a dedicated file. These files should end in
a `.func.php` extension where the name of the file relates to the base "theme
hook" being invoked. For example: the theme hook `breadcrumb` is rendered by
the `bootstrap_breadcrumb()` theme function located in the
`./bootstrap/templates/system/breadcrumb.func.php` file.

{.help-block} See related sub-topic below for a list of functions.

## Theme Process and Preprocess Functions (.vars.php) {#theme-preprocess}
Theme process and preprocess functions can be stored in a dedicated file. These
files must end with a `.vars.php` extension where the name of the file relates
to the base "theme hook" being invoked.

For example: the theme hook `page` has both the process function
`bootstrap_process_page()` and the preprocess function
`bootstrap_preprocess_page()` which are located in the
`./bootstrap/templates/system/page.vars.php` file.

This file should also contain any helper functions that are specific to the
theme hook as well. If a function becomes too large, break it apart so it can
become more legible.

{.help-block} See related sub-topic below for a list of functions.

## Theme Templates (.tpl.php)  {#theme-templates}
Theme template files should end with a `.tpl.php` extension where the name of
the file relates to the base "theme hook" being invoked. For example: the
template for the theme hook `page` is located at
`./bootstrap/templates/system/page.tpl.php`.

{.help-block} See related sub-topic below for a list of templates.

## Theme Hook Naming Conventions
As a general rule, theme hooks must convert all underscores (`_`) to hyphens
(`-`) for the file name. This can sometimes be especially confusing for some at
first. Any time a file name has been changed, you must also rebuild the theme
registry. The easiest way to do this is to "Clear all caches" on the
`admin/config/development/performance` page.

The exception for this rule would be theme function (`.func.php`) and
\[pre\]process function (`.vars.php`) files. These file names should only be
named using the base theme hook (using the general rule).

Theme hook suggestions should not be used in the file name, but rather their
suggestion functions placed inside the base theme hook `.func.php` or
`.vars.php` file. An example of this would be the
`bootstrap_menu_tree__primary()` theme function where the base theme hook is
`menu_tree` (the hook name before `__`) and located in the
`./bootstrap/templates/menu/menu-tree.func.php` file.

[Drupal Bootstrap]: https://www.drupal.org/project/bootstrap
