<?php
/**
 * @file
 * admin forms for select2.
 */

/**
 * Impelemnts hook_form().
 */
function select2_settings_form($form, &$form_state) {

  $form['setting_vtabs'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['setting_vtabs']['loading_rules'] = array(
    '#type' => 'fieldset',
    '#title' => 'Plugin loading rules',
  );

  $form['setting_vtabs']['loading_rules']['select2_compression_type'] = array(
    '#type' => 'radios',
    '#title' => t('Choose Select2 compression level'),
    '#options' => array(
      'minified' => t('Production (Minified)'),
      'source' => t('Development (Uncompressed Code)'),
    ),
    '#default_value' => variable_get('select2_compression_type', 'minified'),
  );

  $form['setting_vtabs']['loading_rules']['select2_update_settings_by_ajax'] = array(
    '#title' => t('Update setting by ajax'),
    '#description' => t('This option can be used when cache enabled for pages.
<b>After enabling/disabling this option your current cache will be cleared.</b>.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('select2_update_settings_by_ajax', FALSE),
  );

  $form['setting_vtabs']['loading_rules']['select2_use_for_all_select_elements'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use for all select elements'),
    '#description' => t('If checked, Select2 plugin will be applied for all select elements on pages.'),
    '#default_value' => variable_get('select2_use_for_all_select_elements', FALSE),
  );

  $form['setting_vtabs']['loading_rules']['select2_use_for_all_select_elements_for_admin_pages'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use for all select elements on admin pages'),
    '#description' => t('If checked, Select2 plugin will be applied for all select elements on admin pages.'),
    '#default_value' => variable_get('select2_use_for_all_select_elements_for_admin_pages', FALSE),
    '#states' => array(
      'invisible' => array(
        ':input[name="select2_use_for_all_select_elements"]' => array('checked' => FALSE),
      ),
    ),
  );

  $form['setting_vtabs']['loading_rules']['select2_use_for_ac_elements'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use for select2 for elements with autocomplete'),
    '#description' => t('If checked, Select2 plugin will be applied for all elements with autocomplete feature.'),
    '#default_value' => variable_get('select2_use_for_ac_elements', FALSE),
  );

  $form['setting_vtabs']['excluded_elements'] = array(
    '#type' => 'fieldset',
    '#title' => t('Exclusion rules'),
    '#collapsible' => 1,
    '#collapsed' => 1,
    '#description' => t('Lists of items, that do not need to use the Select2 plugin.'),
  );

  $form['setting_vtabs']['excluded_elements']['select2_excluded_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Don\'t load Select2 for specific pages'),
    '#default_value' => variable_get('select2_excluded_paths', ''),
    '#description' => t('Specify pages by using their paths.
Enter one path per line. The "*" character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.', array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );

  $form['setting_vtabs']['excluded_elements']['select2_excluded_ids'] = array(
    '#type' => 'textarea',
    '#title' => t("ID's"),
    '#default_value' => variable_get('select2_excluded_ids', ''),
    '#description' => t('Enter one ID per line without # symbol.<br/>
You can define ID by regular expression, in this case wrap it by #.<br>
For example:<br><br>
<dl>
  <dt>"<b>edit-menu-weight</b>"</dt>
  <dd>will exclude element with id="edit-menu-weight" for Select2 attaching;</dd>
  <dt>"<b>#^edit-menu-#</b>"</dt>
  <dd>will exclude all elements that have the id attribute with a value beginning exactly with a "edit-menu-" for Select2 attaching;</dd>
</dl>.'),
  );

  $form['setting_vtabs']['excluded_elements']['select2_excluded_cleasses'] = array(
    '#type' => 'textarea',
    '#title' => t('Classes'),
    '#default_value' => variable_get('select2_excluded_cleasses', ''),
    '#description' => t('Enter one class name per line without dots and spaces.<br>
For example: "menu-parent-select" will disable attach Select2
for parent menu select element on node edit and other pages.<br>
All classes, defined in this field, will be automatically combined to one jQuery selector: "jQuery(\'.class-name-1, .class-name-2, ...\')"'),
  );

  $form['setting_vtabs']['excluded_elements']['select2_excluded_selectors'] = array(
    '#type' => 'textarea',
    '#title' => t('Selectors'),
    '#default_value' => variable_get('select2_excluded_selectors', ''),
    '#description' => t('Enter one selector per line.<br>
All elements, that will match for defined selector, will be skipped for attaching Select2.<br>
For example: define "<b>.form-item select</b>" selector for skipping all select elements
that have parents with "<b>form-item</b>" class.'),
  );

  $form['setting_vtabs']['default_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default plugin settings'),
    '#collapsible' => 1,
    '#collapsed' => 1,
  );

  $form['setting_vtabs']['default_settings']['select2_min_options_count_for_search'] = array(
    '#type' => 'textfield',
    '#title' => t('Options count for enabling search.'),
    '#default_value' => variable_get('select2_min_options_count_for_search', 15),
    '#element_validate' => array('_select2_element_validate_integer_positive_or_zero'),
    '#description' => t('If count of available options is less of value of this field, search box will be hided.'),
  );

  $form['setting_vtabs']['default_settings']['select2_default_width'] = array(
    '#type' => 'select',
    '#title' => t('Default "width" property value'),
    '#default_value' => variable_get('select2_default_width', 'element'),
    '#options' => array(
      'off' => 'Off',
      'element' => 'Element',
      'copy' => 'Copy',
      'resolve' => 'Resolve',
      'auto' => 'Auto',
    ),
    '#description' => t('Values description:
<ul>
<li><b>off</b> - No width attribute will be set. Keep in mind that the container div copies classes from the source element so setting the width attribute may not always be necessary.</li>
<li><b>element</b> - Uses javascript to calculate the width of the source element.</li>
<li><b>copy</b> - Copies the value of the width style attribute set on the source element.</li>
<li><b>resolve</b> - First attempts to <u>copy</u> than falls back on <u>element</u>.</li>
</ul>'),
  );

  $form = system_settings_form($form);

  $form['#submit'][] = 'select2_settings_form_submit';

  return $form;
}

/**
 * Implements hook_form_submit().
 */
function select2_settings_form_submit($form, &$form_state) {

  if ($form['setting_vtabs']['loading_rules']['select2_update_settings_by_ajax']['#default_value'] != $form_state['values']['select2_update_settings_by_ajax']) {
    drupal_flush_all_caches();
    drupal_set_message(t('Caches cleared.'));
  }
}
