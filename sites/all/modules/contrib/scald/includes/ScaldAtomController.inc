<?php
/**
 * @file
 * This file contains the Scald Atom controller.
 */

/**
 * Controller class for Scald Atoms.
 *
 * This extends DrupalDefaultEntityController, adding special handling
 * for ScaldAtom objects.
 */
class ScaldAtomController extends DrupalDefaultEntityController {
  /**
   * Overrides DrupalDefaultEntityController::attachLoad().
   */
  protected function attachLoad(&$atoms, $revision_id = FALSE) {
    foreach ($atoms as $atom) {
      $atom->data = unserialize($atom->data);
    }

    parent::attachLoad($atoms, $revision_id);
  }

  /**
   * Prepares and returns the default thumbnail path for an atom type.
   */
  public static function getThumbnailPath($type) {
    $field = field_info_field('scald_thumbnail');
    $instance = field_info_instance('scald_atom', 'scald_thumbnail', $type);
    if ($field && $instance) {
      $directory = file_field_widget_uri($field, $instance);
      if (file_prepare_directory($directory, FILE_CREATE_DIRECTORY)) {
        return $directory;
      }
      drupal_set_message(t('The directory "@directory" must be writable by the webserver. Your upload will not be saved. Please contact your server administrator to configure permissions.', array('@directory' => $directory)), 'error', FALSE);
    }
  }

  /**
   * Returns the default description for a file or image field for an atom type.
   */
  public static function getFieldDescription($type, $field_name = 'scald_thumbnail') {
    $description = '';
    $field = field_info_field($field_name);
    $instance = field_info_instance('scald_atom', $field_name, $type);
    if ($field && $instance) {
      $description = $instance['description'];
    }
    return $description;
  }

  /**
   * Returns the default upload validators for a file or image field for an atom type.
   */
  public static function getFieldUploadValidators($type, $field_name = 'scald_thumbnail') {
    $upload_validators = array();
    $field = field_info_field($field_name);
    $instance = field_info_instance('scald_atom', $field_name, $type);
    if ($field && $instance) {
      // Add upload file validation.
      $upload_validators = file_field_widget_upload_validators($field, $instance);
      if ($type === 'image' && (!empty($instance['settings']['max_resolution']) || !empty($instance['settings']['min_resolution']))) {
        // Add upload image validation.
        $upload_validators['file_validate_image_resolution'] = array($instance['settings']['max_resolution'], $instance['settings']['min_resolution']);
      }
    }
    return $upload_validators;
  }

  /**
   * Add a Scald unified type.
   *
   * This function create a new type if it does not already exist. It can be
   * used inside atom providers hook_install(), to easily ensure that the type
   * of the atom the module will provide is defined.
   *
   * @return bool
   *   TRUE if the new type was added, FALSE if already exists.
   */
  public static function addType($type, $title, $description) {
    // Check if this type already exists.
    $types = scald_types();
    if (!empty($types[$type])) {
      return FALSE;
    }

    // Create a new type.
    db_insert('scald_types')
      ->fields(array('type', 'title', 'description', 'provider'))
      ->values(array($type, $title, $description, 'scald'))
      ->execute();

    // And add fields on it, starting with the Scald Thumbnail field.
    $instance = array(
      'field_name' => 'scald_thumbnail',
      'entity_type' => 'scald_atom',
      'bundle' => $type,
      'label' => 'Thumbnail',
      'required' => FALSE,
      'display' => array(
        'default' => array(
          'type' => 'hidden',
        ),
      ),
      'settings' => array(
        'file_directory' => 'thumbnails/' . $type,
      ),
    );
    if (!field_read_instance($instance['entity_type'], $instance['field_name'], $instance['bundle'])) {
      field_create_instance($instance);
      $instance = field_info_instance($instance['entity_type'], $instance['field_name'], $instance['bundle']);
      foreach ($instance['display'] as $view_mode => $settings) {
        $instance['display'][$view_mode]['type'] = 'hidden';
      }
      field_update_instance($instance);
    }

    // Instantiate the Scald Authors field, if the vocabulary exists, and if
    // the field exists for us to instantiate. Otherwise, assume that one or
    // both were intentionally deleted and don't re-create.
    $vocabulary_name = variable_get('scald_author_vocabulary', 'scald_authors');
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);
    $instance = array(
      'field_name' => 'scald_authors',
      'entity_type' => 'scald_atom',
      'bundle' => $type,
      'label' => 'Authors',
      'required' => FALSE,
      'widget' => array(
        'type' => 'taxonomy_autocomplete',
      ),
    );
    if ($vocabulary && field_read_field($instance['field_name']) && !field_read_instance($instance['entity_type'], $instance['field_name'], $instance['bundle'])) {
      field_create_instance($instance);
    }

    // Instantiate the Scald Tags field. As with Scald Authors above, only do
    // this if the vocabulary and the field already exist.
    $vocabulary_name = variable_get('scald_tags_vocabulary', 'scald_tags');
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);
    $instance = array(
      'field_name' => 'scald_tags',
      'entity_type' => 'scald_atom',
      'bundle' => $type,
      'label' => 'Tags',
      'required' => FALSE,
      'widget' => array(
        'type' => 'taxonomy_autocomplete',
      ),
    );
    if ($vocabulary && field_read_field($instance['field_name']) && !field_read_instance($instance['entity_type'], $instance['field_name'], $instance['bundle'])) {
      field_create_instance($instance);
    }

    // Flush our caches.
    scald_contexts(TRUE);
    scald_types(TRUE);

    return TRUE;
  }

  /**
   * Remove a Scald unified type.
   *
   * This function removes a type. It can be used inside atom providers
   * hook_uninstall(), to easily ensure that the type of the atom the module
   * provides is removed if no other use it.
   *
   * @param string $type
   *   Machine name of atom type.
   *
   * @return bool
   *   TRUE if the type was removed, FALSE otherwise.
   */
  public static function removeType($type) {
    if (!array_key_exists($type, scald_atom_providers())) {
      db_delete('scald_types')
        ->condition('type', $type)
        ->execute();
      scald_types(TRUE);

      foreach (array('scald_thumbnail', 'scald_authors', 'scald_tags') as $field_name) {
        $instance = field_info_instance('scald_atom', $field_name, $type);
        if (!empty($instance)) {
          field_delete_instance($instance, FALSE);
        }
      }
      return TRUE;
    }

    return FALSE;
  }

  /**
   * Save changes to a Scald Atom, or create a new one.
   *
   * @param ScaldAtom $atom
   *   At minimum, 'type', 'provider', and 'base_id' (which uniquely identifies
   *   a given Atom) are required.  Additional included values which are keyed
   *   by recognized Scald Atom Object members will be used for those members
   *   and any additional values will be passed along to the Providers.
   *
   * @return mixed
   *   The saved atom upon successful save.
   *   NULL upon failure.
   */
  public static function save($atom) {
    // First pass Atom object validation.
    $types = scald_types();

    // Verify type.
    if (empty($atom->type) || empty($atom->provider) || empty($types[$atom->type])) {
      return NULL;
    }

    // Ensure the Atom Object has all the required members.
    if (!isset($atom->publisher)) {
      $atom->publisher = NULL;
    }
    if (!isset($atom->actions)) {
      $atom->actions = NULL;
    }
    if (!isset($atom->title)) {
      $atom->title = '';
    }
    if (!isset($atom->data)) {
      $atom->data = array();
    }
    if (!isset($atom->created)) {
      $atom->created = REQUEST_TIME;
    }
    if (!isset($atom->changed)) {
      $atom->changed = REQUEST_TIME;
    }

    $op = empty($atom->sid) ? 'insert' : 'update';

    if ($op == 'update') {
      $hook = 'scald_update_atom';
      $atom->original = entity_load_unchanged('scald_atom', $atom->sid);

      // Nobody updated the changed date, so we do it.
      if($atom->original->changed === $atom->changed) {
        $atom->changed = REQUEST_TIME;
      }
    }
    else {
      $hook = 'scald_register_atom';
    }

    // The Type Provider can implement some other defaults at this point, but
    // the Atom Provider may override them.
    module_invoke($types[$atom->type]->provider, $hook, $atom, 'type');

    // Hand the Atom off to the Atom Provider to do additional processing and
    // population.
    // NOTE: Providers explicitly have access to change the Atom's basic members
    // to allow for hypothetical "dispatch Providers" which would determine the
    // appropriate Provider and/or characteristics of an Atom upon registration.
    module_invoke($atom->provider, $hook, $atom, 'atom');

    // Another round of member validation is necessary due to the potential for
    // the Providers to modify them.  By design!
    if (empty($atom->type) || empty($atom->provider) || empty($types[$atom->type])) {
      return NULL;
    }

    // Only supply defaults for the Actions bitstring if the Provider did
    // nothing. Otherwise assume that the bitstring is intentional.
    if (is_null($atom->actions)) {
      $defaults = scald_atom_defaults($atom->type);
      $atom->actions = $defaults->actions;
    }

    // Do "poor-man's" UID validation.
    if (empty($atom->publisher) || !is_numeric($atom->publisher) || !($atom->publisher > 0)) {
      global $user;
      $atom->publisher = $user->uid;
    }

    // Let Field API have a pass at our atom too.
    field_attach_presave('scald_atom', $atom);

    // Inform all modules before writing the atom in the database.
    module_invoke_all('scald_atom_presave', $atom);
    module_invoke_all('entity_presave', $atom, 'scald_atom');

    // Put the basic data in the Scald Atom Registry.
    if ($op == 'update') {
      $written = drupal_write_record('scald_atoms', $atom, array('sid'));
    }
    else {
      $written = drupal_write_record('scald_atoms', $atom);
    }

    if (!$written) {
      return NULL;
    }

    $function = 'field_attach_' . $op;
    $function('scald_atom', $atom);

    // Notify all modules of our new atom.
    module_invoke_all('scald_atom_' . $op, $atom);
    module_invoke_all('entity_' . $op, $atom, 'scald_atom');

    // Transcoding.
    // Only fire hook_register_atom() for Transcoder Providers that might be
    // responsible for transcoding this Atom (based on the currently-configured
    // Context and Transcoder settings).
    $contexts = scald_contexts();
    $transcoders = scald_transcoders();

    foreach ($contexts as $context => $details) {
      if (isset($details['type_format'][$atom->type])) {
        $transcoder = $details['type_format'][$atom->type]['transcoder'];
        $values['@ccontext'] = $context;
        module_invoke($transcoders[$transcoder]['provider'], $hook, $atom, 'transcoder');
      }
    }

    // Clear the render cache.
    cache_clear_all($atom->sid . ':', 'cache_scald', TRUE);

    // Clear the static caches.
    entity_get_controller('scald_atom')->resetCache(array($atom->sid));

    return $atom;
  }
}
