<!-- @file Instructions on how to sub-theme the Drupal Bootstrap base theme. -->
<!-- @defgroup -->
# Sub-Theming

- [Prerequisite](#prerequisite)
- [Setup](#setup)
  - [Choose an Existing Starterkit](#starterkit)
  - [Create a New Sub-theme](#create)
  - [Enable Your New Sub-theme](#enable)

## Prerequisite
Read the @link getting_started Getting Started @endlink topic.

---

## Setup
Below are instructions on how to create a [Drupal Bootstrap] based sub-theme.
There are several different variations on how to accomplish this task, but this
topic will focus on the two primarily and most common ways.

#### Choose an Existing Starterkit {#starterkit}

- @link subtheme_cdn CDN Starterkit @endlink - uses the "out-of-the-box"
  CSS and JavaScript files served by the [jsDelivr CDN].
- @link subtheme_less Less Starterkit @endlink - uses the [Bootstrap Framework]
  source files and a local [Less] preprocessor.
- @link subtheme_sass Sass Starterkit @endlink - uses the [Bootstrap Framework]
  source files and a local [Sass] preprocessor.

#### Create a New Sub-theme {#create}

1. Copy over one of the starterkits you have chosen from the
   `./bootstrap/starterkits` folder into `sites/all/themes` or a respective
   `sites/*/themes` folder.
2. Rename the folder to a unique machine readable name. This will be your
   sub-theme's "name". For this example and future examples we'll use
   `subtheme`.
3. Rename `./subtheme/cdn.starterkit` or, if using the LESS Starterkit,
   `./subtheme/less.starterkit` to match the folder name and append `.info`
   (e.g. `./subtheme/subtheme.info`).
4. Open `./subtheme/subtheme.info` and change the name, description and any
   other properties to suite your needs.

{.alert.alert-warning} **WARNING:** Ensure that the `.starterkit` suffix is
not present on your sub-theme's `.info` filename. This suffix is simply a stop
gap measure to ensure that the bundled starter kit sub-theme cannot be enabled
or used directly. This helps people unfamiliar with Drupal avoid modifying the
starter kit sub-theme directly and instead forces them to create a new sub-theme
to modify.

#### Enable Your New Sub-theme {#enable}
In your Drupal site, navigate to `admin/appearance` and click the `Enable and
set default` link next to your newly created sub-theme.

---

{.alert.alert-info} Please refer to [Choose an Existing Starterkit](#starterkit)
for additional documentation pertaining to the chosen Starterkit.

[Drupal Bootstrap]: https://www.drupal.org/project/bootstrap
[Bootstrap Framework]: https://getbootstrap.com/docs/3.3/
[jsDelivr CDN]: https://www.jsdelivr.com
[Less]: http://lesscss.org
[Sass]: http://sass-lang.com
