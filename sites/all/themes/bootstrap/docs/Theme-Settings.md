<!-- @file Overview of theme settings for Drupal Bootstrap based themes. -->
<!-- @defgroup theme_settings -->
# Theme Settings

To override a setting, open `./subtheme/subtheme.info` and add the following:

`settings[BOOTSTRAP_SETTING] = VALUE`

Where `BOOTSTRAP_SETTING` is the name of the setting and `VALUE` is the value.

---

Below is a complete list of default setting values in the [Drupal Bootstrap]
base theme:

## Global
| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| toggle_name                                      | `1`                       |
| toggle_search                                    | `1`                       |
{.table.table-striped}

## Containers

| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_fluid_container                        | `0`                       |
{.table.table-striped}

## Buttons

| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_button_size                            | `''`                      |
| bootstrap_button_colorize                        | `1`                       |
| bootstrap_button_iconize                         | `1`                       |
{.table.table-striped}

## Images

| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_image_shape                            | `''`                      |
| bootstrap_image_responsive                       | `1`                       |
{.table.table-striped}

## Tables

| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_table_bordered                         | `0`                       |
| bootstrap_table_condensed                        | `0`                       |
| bootstrap_table_hover                            | `1`                       |
| bootstrap_table_striped                          | `1`                       |
| bootstrap_table_responsive                       | `1`                       |
{.table.table-striped}

## Breadcrumbs

| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_breadcrumb                             | `1`                       |
| bootstrap_breadcrumb_home                        | `0`                       |
| bootstrap_breadcrumb_title                       | `1`                       |
{.table.table-striped}

## Navbar
| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_navbar_position                        | `''`                      |
| bootstrap_navbar_inverse                         | `0`                       |
{.table.table-striped}

## Pager
| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_pager_first_and_last                   | `1`                       |
{.table.table-striped}

## Wells (Regions)
| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_region_well-navigation                 | `''`                      |
| bootstrap_region_well-header                     | `''`                      |
| bootstrap_region_well-highlighted                | `''`                      |
| bootstrap_region_well-help                       | `''`                      |
| bootstrap_region_well-content                    | `''`                      |
| bootstrap_region_well-sidebar_first              | `'well'`                  |
| bootstrap_region_well-sidebar_second             | `''`                      |
| bootstrap_region_well-footer                     | `''`                      |
{.table.table-striped}

## Anchors
| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_anchors_fix                            | `1`                       |
| bootstrap_anchors_smooth_scrolling               | `1`                       |
{.table.table-striped}

## Forms
| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_forms_required_has_error               | `0`                       |
| bootstrap_forms_has_error_value_toggle           | `1`                       |
| bootstrap_forms_smart_descriptions               | `1`                       |
| bootstrap_forms_smart_descriptions_limit         | `250`                     |
| bootstrap_forms_smart_descriptions_allowed_tags  | `'b, code, em, i, kbd, span, strong'` |
{.table.table-striped}

## Popovers
| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_popover_enabled                        | `1`                       |
| bootstrap_popover_animation                      | `1`                       |
| bootstrap_popover_html                           | `0`                       |
| bootstrap_popover_placement                      | `'right'`                 |
| bootstrap_popover_selector                       | `''`                      |
| [bootstrap_popover_trigger]['hover']             | `0`                       |
| [bootstrap_popover_trigger]['focus']             | `0`                       |
| [bootstrap_popover_trigger]['click']             | `'click'`                 |
| bootstrap_popover_trigger_autoclose              | `1`                       |
| bootstrap_popover_title                          | `''`                      |
| bootstrap_popover_content                        | `''`                      |
| bootstrap_popover_delay                          | `0`                       |
| bootstrap_popover_container                      | `'body'`                  |
{.table.table-striped}

## Tooltips
| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_tooltip_enabled                        | `1`                       |
| bootstrap_tooltip_animation                      | `1`                       |
| bootstrap_tooltip_html                           | `0`                       |
| bootstrap_tooltip_placement                      | `'auto left'`             |
| bootstrap_tooltip_selector                       | `''`                      |
| [bootstrap_tooltip_trigger]['hover']             | `'hover'`                 |
| [bootstrap_tooltip_trigger]['focus']             | `'focus'`                 |
| [bootstrap_tooltip_trigger]['click']             | `0`                       |
| bootstrap_tooltip_delay                          | `0`                       |
| bootstrap_tooltip_container                      | `'body'`                  |
{.table.table-striped}

## Advanced
| Setting                                          | Default value {.col-xs-4} |
| ------------------------------------------------ | ------------------------- |
| bootstrap_cdn_provider         | `'jsdelivr'`                                                                |
| bootstrap_cdn_custom_css       | `'https://cdn.jsdelivr.net/npm/bootstrap@3.4.1/dist/css/bootstrap.css'`     |
| bootstrap_cdn_custom_css_min   | `'https://cdn.jsdelivr.net/npm/bootstrap@3.4.1/dist/css/bootstrap.min.css'` |
| bootstrap_cdn_custom_js        | `'https://cdn.jsdelivr.net/npm/bootstrap@3.4.1/dist/js/bootstrap.js'`       |
| bootstrap_cdn_custom_js_min    | `'https://cdn.jsdelivr.net/npm/bootstrap@3.4.1/dist/js/bootstrap.min.js'`   |
| bootstrap_cdn_jsdelivr_version | `'3.4.1'`                                                                   |
| bootstrap_cdn_jsdelivr_theme   | `'bootstrap'`                                                               |
{.table.table-striped}

[Drupal Bootstrap]: https://www.drupal.org/project/bootstrap
[Bootstrap Framework]: https://getbootstrap.com/docs/3.4/
