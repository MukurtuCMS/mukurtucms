<!-- @file Maintaining the Drupal Bootstrap project. -->
<!-- @defgroup -->
# Maintainers

Generally speaking, these topics will not be very helpful to you unless you are
a maintainer for this project. If you're simply curious about the process or
even want to help improve this aspect of the project, all suggestions will be
appreciated!

## Drupal Bootstrap Styles
The stylesheets bundled with this base theme (formerly known as "overrides")
have moved to a separate and dedicated project. Please file issues there:

https://github.com/unicorn-fail/drupal-bootstrap-styles

## Releases
This project attempts to provide more structured release notes. This allows the
project to communicate more effectively to the users what exactly has changed
and where to go for additional information. This documentation is intended for
the project maintainers to help provide consistent results between releases.

### Release notes template
The following is just a template to show a typical structured format used as
release notes for this project:

```html
<h3 id="change-records">Change Records</h3>
<!-- Change records table HTML -->

Optionally, you can insert any additional verbiage here.
However, if it is long, it should really be a change record.

<p>&nbsp;</p>
<h3 id="notes">Notes</h3>

<p>&nbsp;</p>
<p>Changes since <!-- previous release --> (<!-- commit count -->):</p>

<h3 id="security">Security Announcements</h3>
<ul>
  <li><!-- Issue/Commit Message --></li>
</ul>

<h3 id="features">New Features</h3>
<ul>
  <li><!-- Issue/Commit Message --></li>
</ul>

<h3 id="bugs">Bug Fixes</h3>
<ul>
  <li><!-- Issue/Commit Message --></li>
</ul>
```

### Create a Release Node

{.alert.alert-info} **NOTE:** This project currently relies on the
[Drush Git Release Notes](https://www.drupal.org/project/grn) tool to
automatically generate the the bulk of the release notes. This does, however,
requires maintainers to do the following extra steps. This entire process will
eventually be converted into a fully automated grunt task. Until then, please
download and install this tool and follow the remaining steps.

1. Create a [tag in git](https://www.drupal.org/node/1066342) that follows the
   previous version and push it to the repository.
2. Create a [project release node](https://www.drupal.org/node/1068944) for this
   newly created tag.
3. _(Skip this step if this is a new "alpha/beta" release)_ In a separate tab,
   go to this project's [releases](https://www.drupal.org/node/259843/release)
   page. Open and edit the previous release node. It should have followed the
   release note template. If it has, copy and paste its contents into the new
   release node body.
4. In a separate tab, go to the [change records](https://www.drupal.org/list-changes/bootstrap)
   for this project and filter by the new official release version
   ("alpha/beta/RC" releases should always use the next "official" version for
   their change records). If there are no change records, then remove this
   section. Otherwise, copy and paste the entire table into the template
   (replacing any existing one, if necessary).
5. Generate a list of issues/commits by executing the following from the root
   of the project:

   `drush release-notes <old> <new> --commit-count`
   (e.g. `drush release-notes 7.x-3.0 7.x-3.1 --commit-count`)

   If this is a follow-up "alpha/beta/RC" release, always use the last
   "alpha/beta/RC" release version instead. This will allow for a quicker
   parsing of the list to merge into the previously copied release notes:

   `drush release-notes <old> <new> --commit-count`
   (e.g. `drush release-notes 7.x-3.1-beta2 7.x-3.1-beta3 --commit-count`)

6. Copy the entire generated output into the template, just under where the
   "Change Records" section would be, replacing only the commit count (do not
   replace the "since last {offical} version").
7. Go though each item (`<li>`) that contains an issue link, ignoring duplicates
   and standalone verbiage (direct commits). Move (cut and paste) these items
   into the appropriate "New Features" or "Bug Fixes" sections.
8. Once complete the generated list should be empty (e.g. `<ul></ul>`), remove
   it.
9. Save the release node.
