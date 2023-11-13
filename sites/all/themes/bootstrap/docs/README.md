<!-- @file Documentation landing page and topics for the https://drupal-bootstrap.org site. -->
<!-- @mainpage -->
# Drupal Bootstrap Documentation

{.lead} The official documentation site for the [Drupal Bootstrap] base theme

The majority of this site is automatically generated from source files
located through out the project's repository. Topics are extracted from Markdown
files and the rest is extracted from embedded PHP comments.

---

## Topics

Below are some topics to help get you started using the [Drupal Bootstrap] base
theme. They are ordered based on the level one typically progresses while using
a base theme like this.

#### [Contributing](<!-- @url contributing -->)

#### [Getting Started](<!-- @url getting_started -->)

#### [Theme Settings](<!-- @url theme_settings -->)

#### [Sub-Theming](<!-- @url sub_theming -->)

#### [Utilities](<!-- @url utility -->)

#### [Theme Registry](<!-- @url registry -->)

- [Preprocess Functions (.vars.php)](<!-- @url theme_preprocess -->)
- [Process Functions (.vars.php)](<!-- @url theme_process -->)
- [Templates (.tpl.php)](<!-- @url templates -->)
- [Theme Functions (.func.php)](<!-- @url theme_functions -->)

#### [Project Maintainers](<!-- @url maintainers -->)

---

## Terminology

The term **"bootstrap"** can be used excessively through out this project's
documentation. For clarity, we will always attempt to use this word verbosely
in one of the following ways:

- **[Drupal Bootstrap]** refers to the Drupal base theme project.
- **[Bootstrap Framework]** refers to the external front end framework.
- **[`drupal_bootstrap`](https://api.drupal.org/apis/drupal_bootstrap)** refers
  to Drupal's bootstrapping process or phase.
  
When referring to files inside the [Drupal Bootstrap] project directory, they
will always start with `./sites/all/themes/bootstrap` and continue to specify
the full path to the file or directory inside it. The dot (`.`) is
representative of your Drupal installation's `DOCROOT` folder. For example, the
file that is responsible for displaying the text on this page is located at
`./sites/all/themes/bootstrap/docs/README.md`.

When referring to files inside a sub-theme, they will always start with
`./sites/all/themes/THEMENAME/`, where `THEMENAME` is the machine name of your
sub-theme. They will continue to specify the full path to the file or directory
inside it. For example, the primary file Drupal uses to determine if a theme
exists is: `./sites/all/themes/THEMENAME/THEMENAME.info`.

{.alert.alert-info} **NOTE:** It is common practice to place projects found on
Drupal.org inside a sub-folder named `contrib` and custom/site-specific code
inside a `custom` folder. If your site is set up this way, please adjust all
paths accordingly (i.e. `./sites/all/themes/contrib/bootstrap` and
`./sites/all/themes/custom/THEMENAME`). If you have a multi-site setup, you
will need to replace the `all` portion of the path with the appropriate site
name (i.e. `./sites/example.com/themes/contrib/bootstrap`).

[Drupal Bootstrap]: https://www.drupal.org/project/bootstrap
[Bootstrap Framework]: https://getbootstrap.com/docs/3.4/
