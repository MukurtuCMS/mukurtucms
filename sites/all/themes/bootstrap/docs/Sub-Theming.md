<!-- @file Instructions on how to sub-theme the Drupal Bootstrap base theme. -->
<!-- @defgroup sub_theming -->
# Sub-Theming

If you haven't already installed the Drupal Bootstrap theme, read the
[Getting Started](<!-- @url getting_started -->) topic. Below are instructions
on how to create a [Drupal Bootstrap] based sub-theme. There are several
different variations on how to accomplish this task, but this topic will focus
on the two primarily and most common ways.

You should never modify any theme or sub-theme that is packaged and released
from Drupal.org, such as Drupal Bootstrap. If you do, all changes you have made
will be lost once that theme is updated. Instead, you should create a sub-theme
from one of the provided starterkits (this is considered a best practice). Once
you've done that, you can override CSS, templates, and theme processing.

- [Using the Starterkit](#starterkit)
- [Using Source Files](#source)
  - [LESS](#less)
  - [SASS](#sass)
  - [Compile](#compile)
- [Override Settings](#settings)
- [Override Templates](#templates)

## Using the Starterkit {#starterkit}

The starterkit provided by this base-theme supplies the basic file structure on
how to construct a proper Bootstrap based sub-theme for use with a CDN Provider
(like [jsDelivr]) or for use with compiling [Bootstrap Framework] source files.

{.alert.alert-info} **NOTE:** Using a CDN Provider is the preferred method
for loading the [Bootstrap Framework] CSS and JS on simpler sites that do not
use a site-wide CDN. There are advantages and disadvantages to using a
CDN Provider and you will need to weigh the benefits based on your site's own
requirements. Using a CDN Provider does mean that it depends on a third-party
service. There is no obligation or commitment made by this project or these
third-party services that guarantees up-time or quality of service. If you need
to customize Bootstrap, you must compile the [Bootstrap Framework] source code
locally and disable the
[`bootstrap_cdn_provider` theme setting](<!-- @url theme_settings -->).

{.alert.alert-warning} **WARNING:** All locally compiled versions of Bootstrap
will be superseded by any enabled CDN Provider; **do not use both**.

1. Copy `./sites/all/themes/bootstrap/starterkits/THEMENAME` to `./sites/all/themes`.
   * Rename the `THEMENAME` directory to a unique machine readable name. This is
   your sub-theme's "machine name". When referring to files inside a sub-theme,
   they will always start with `./sites/all/themes/THEMENAME/`, where `THEMENAME`
   is the machine name of your sub-theme. They will continue to specify the full
   path to the file or directory inside it. For example, the primary file Drupal
   uses to determine if a theme exists is:
   `./sites/all/themes/THEMENAME/THEMENAME.info`.
2. Rename `./sites/all/themes/THEMENAME/THEMENAME.starterkit` to match
   `./sites/all/themes/THEMENAME/THEMENAME.info`.
   * Open this file and change the name, description and any other properties
     to suite your needs.
   * (Optional) If you plan on using a local precompiler (i.e. [Less] or [Sass])
     then uncomment the appropriate JavaScript entries inside this file to
     enable the assets provided by the [Bootstrap Framework].
   * (Optional) If you plan on using a local precompiler (i.e. [Less] or [Sass])
     then you will need to disable the
     [`bootstrap_cdn_provider` theme setting](<!-- @url theme_settings -->).
     You can do this several different ways, but it's recommended that you
     uncomment the following line in this file so the CDN Provider is
     automatically disabled when your sub-theme is installed:
     ```
     ; Uncomment if using Sass or Less source files. This disables the CDN provider
     ; so compiled source files can be used instead.
     settings[bootstrap_cdn_provider] = ''
     ```

{.alert.alert-warning} **WARNING:** Ensure that the `.starterkit` suffix is
not present on your sub-theme's `.info` filename. This suffix is simply a
stop gap measure to ensure that the bundled starter kit sub-theme cannot be
enabled or used directly. This helps people unfamiliar with Drupal avoid
modifying the starter kit sub-theme directly and instead forces them to create
a new sub-theme to modify.

## Using Source Files {#source}

By default, the starterkit is designed to be used with a CDN Provider for
quick setup.

While there are a multitude of different approaches on how to actually compile
the [Bootstrap Framework] source files, this base-theme does not and will not
provide templates or suggest specific tools to use. It is up to you, the
developer, to figure out which solution is best for your particular needs.

### LESS {#less}
- You must understand the basic concept of using the [Less] CSS pre-processor.
- You must use a **[local Less compiler](https://www.google.com/search?q=less+compiler)**.
- You must use the latest `3.x.x` version of [Bootstrap Framework LESS Source Files]
  ending in the `.less` extension, not files ending in `.css`.
- You must download a copy of [Drupal Bootstrap Styles] and copy over the `less`
  folder located at `./drupal-bootstrap-styles/src/3.x.x/7.x-3.x/less`.

### SASS {#sass}
- You must understand the basic concept of using the [Sass] CSS pre-processor.
- You must use a **[local Sass compiler](https://www.google.com/search?q=sass+compiler)**.
- You must use the latest `3.x.x` version of [Bootstrap Framework SASS Source Files]
  ending in the `.scss` extension, not files ending in `.css`.
- You must download a copy of [Drupal Bootstrap Styles] and copy over the `scss`
  folder located at `./drupal-bootstrap-styles/src/3.x.x/7.x-3.x/scss`.

### Compile {#compile}

Download and extract the source files into the root of your new sub-theme:
`./sites/all/themes/THEMENAME`. After it has been extracted, the directory should be
renamed (if needed) so it reads `./sites/all/themes/THEMENAME/bootstrap`.

If for whatever reason you have an additional `bootstrap` directory wrapping
the first `bootstrap` directory (e.g. `./sites/all/themes/THEMENAME/bootstrap/bootstrap`),
remove the wrapping `bootstrap` directory. You will only ever need to touch
these files if or when you upgrade your version of the [Bootstrap Framework].

{.alert.alert-warning} **WARNING:** Do not modify the files inside of
`./sites/all/themes/THEMENAME/bootstrap` directly. Doing so may cause issues when
upgrading the [Bootstrap Framework] in the future.

Depending on which precompiler you chose, you should have a `less/style.less`
or `scss/style.scss` file respectively. This file is the main compiling entry
point. Follow further instructions provided by the `README.md` inside the
`less` or `scss` folder.

## Override Settings {#settings}
Please refer to the [Theme Settings](<!-- @url theme_settings -->) topic.

## Override Templates {#templates}
Please refer to the [Templates](<!-- @url templates -->) and
[Theme Registry](<!-- @url registry -->) topics.

## Enable Your New Sub-theme {#enable}
In your Drupal site, navigate to `admin/appearance` and click the `Enable and
set default` link next to your newly created sub-theme.

[Drupal Bootstrap]: https://www.drupal.org/project/bootstrap
[Drupal Bootstrap Styles]: https://github.com/unicorn-fail/drupal-bootstrap-styles
[Bootstrap Framework]: https://getbootstrap.com/docs/3.4/
[Bootstrap Framework LESS Source Files]: https://github.com/twbs/bootstrap/releases
[Bootstrap Framework SASS Source Files]: https://github.com/twbs/bootstrap-sass
[jsDelivr]: http://www.jsdelivr.com
[Less]: http://lesscss.org
[Sass]: http://sass-lang.com
