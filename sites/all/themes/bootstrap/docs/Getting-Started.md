<!-- @file The "Getting Started" topic. -->
<!-- @defgroup -->
# Getting Started

## Installation
- Install the Bootstrap base theme in `sites/all/themes` or a similar
  `sites/*/themes` folder.
- Enable the [Drupal Bootstrap] base theme. If you do not intend to use the base
  theme as the default theme, and instead choose to create a sub-theme, you will
  still need to enable the [Drupal Bootstrap] base theme (see warning below).
- Ensure your site's jQuery version has been configured to meet the
  [Bootstrap Framework] minimum version requirement. The preferred method for
  updating Drupal's jQuery is to install the [jQuery Update] module.

{.alert.alert-warning} **WARNING:** Due to a bug in Drupal 7, base themes may
appear to still "work" even if they are not enabled. This fact does not mean
that the base theme still isn't required to be enabled. Not all features will
work properly if the base theme is disabled, especially if certain
functionality relies on a list of "enabled" themes.

## Bootstrap Framework Fundamentals
Generally speaking, you should really read the entire [Bootstrap Framework]
documentation site, if you haven't already. Here are the four basic "sections"
that site is split into:

- [Getting Started](http://getbootstrap.com/getting-started) - An overview of
  the [Bootstrap Framework], how to download and use, basic templates and
  examples, and more.
- [CSS](http://getbootstrap.com/css/) - Global CSS settings, fundamental HTML
  elements styled and enhanced with extensible classes, and an advanced grid
  system.
- [Components](http://getbootstrap.com/components/) - Over a dozen reusable
  components built to provide iconography, dropdowns, input groups, navigation,
  alerts, and much more.
- [JavaScript](http://getbootstrap.com/javascript/) - Bring the
  [Bootstrap Framework] components to life with over a dozen custom jQuery
  plugins. Easily include them all, or one by one.

[Drupal Bootstrap]: https://www.drupal.org/project/bootstrap
[Bootstrap Framework]: http://getbootstrap.com
[jQuery Update]: https://drupal.org/project/jquery_update
