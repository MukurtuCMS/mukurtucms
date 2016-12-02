// This file can be loaded very soon by Drupal because it has to prepare
// translated strings. If it is loaded before CKEditor, make sure that it does
// not throw an error.
if (typeof CKEDITOR !== 'undefined' && typeof CKEDITOR.plugins !== 'undefined') {
  CKEDITOR.plugins.setLang('dndck4', 'en', {
    atom_properties: Drupal.t('Edit atom properties'),
    atom_view: Drupal.t('View'),
    atom_edit: Drupal.t('Edit'),
    atom_refresh: Drupal.t('Refresh'),
    atom_copy: Drupal.t('Copy'),
    atom_cut: Drupal.t('Cut'),
    atom_paste: Drupal.t('Paste'),
    atom_delete: Drupal.t('Delete'),
    atom_none: Drupal.t('Please select an atom first'),
    properties_has_caption: Drupal.t('Add a caption'),
    properties_classes: Drupal.t('CSS Classes'),
    properties_context: Drupal.t('Context'),
    properties_alignment: Drupal.t('Alignment'),
    tab_advanced: Drupal.t('Advanced'),
    tab_info: Drupal.t('Atom Properties'),
    alignment_none: Drupal.t('None'),
    alignment_left: Drupal.t('Left'),
    alignment_right: Drupal.t('Right'),
    alignment_center: Drupal.t('Center'),
    link_image_only: Drupal.t('This option is currently available for Image Atoms only.')
  });
}
