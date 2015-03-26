// This file can be loaded very soon by Drupal because it has to prepare
// translated strings. If it is loaded before CKEditor, make sure that it does
// not throw an error.
if (typeof CKEDITOR !== 'undefined' && typeof CKEDITOR.plugins !== 'undefined') {
  CKEDITOR.plugins.setLang('dnd', 'en', {
    atom_properties: Drupal.t('Edit atom properties'),
    atom_cut: Drupal.t('Cut atom'),
    atom_paste: Drupal.t('Paste atom'),
    atom_delete: Drupal.t('Delete atom from textarea'),
    atom_none: Drupal.t('Please select an atom first'),
    properties_legend: Drupal.t('Legend'),
    properties_context: Drupal.t('Context'),
    properties_alignment: Drupal.t('Alignment'),
    alignment_none: Drupal.t('None'),
    alignment_left: Drupal.t('Left'),
    alignment_right: Drupal.t('Right'),
    alignment_center: Drupal.t('Center'),
    link_image_only: Drupal.t('This option is currently available for Image Atoms only.')
  });
}
