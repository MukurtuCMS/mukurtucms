<?php

/**
 * @file
 * Class definition of FeedsNodeProcessor.
 */

/**
 * Creates nodes from feed items.
 */
class FeedsFileProcessor extends FeedsProcessor {
  protected $debug;

  /**
   * Define entity type.
   */
  public function entityType() {
    return 'file';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Files');
    return $info;
  }

  /**
   * Create a new entity.
   *
   * @param $source
   *   The feeds source that spawns this entity.
   *
   * @return
   *   A new entity object.
   */
  protected function newEntity(FeedsSource $source) {
    $file = new stdClass();
    $file->type = $this->config['bundle'] ? $this->config['bundle'] : FILE_TYPE_NONE;
    $file->timestamp = REQUEST_TIME;
    $file->uid = $this->config['author'];
    $file->status = FILE_STATUS_PERMANENT;

    $this->debug($file, 'newEntity');

    return $file;
  }

  /**
   * Load an existing entity.
   *
   * @param $source
   *   The feeds source that spawns this entity.
   * @param $entity_id
   *   The unique id of the entity that should be loaded.
   *
   * @return
   *   A new entity object.
   *
   * @todo We should be able to batch load these, if we found all of the
   *   existing ids first.
   */
  protected function entityLoad(FeedsSource $source, $fid) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $file = file_load($fid);
    }
    else {
      // We're replacing the existing file. Only load what's absolutely necessary.
      $file = db_query("SELECT fid, type, status, uri FROM {file_managed} WHERE fid = :fid", array(':fid' => $fid))->fetchObject();
      $file->uid = $this->config['author'];
    }

    $this->debug($file, 'entityLoad');

    return $file;
  }

  /**
   * Validate an entity.
   *
   * @throws FeedsValidationException $e
   *   If validation fails.
   */
  protected function entityValidate($entity, $source = NULL) {

  }

  /**
   * Access check for saving an enity.
   *
   * @param $entity
   *   Entity to be saved.
   *
   * @throws FeedsAccessException $e
   *   If the access check fails.
   */
  protected function entitySaveAccess($entity) {

    // The check will be skipped for anonymous files.
    if ($this->config['authorize'] && !empty($entity->uid)) {

      $author = user_load($entity->uid);

      // If the uid was mapped directly, rather than by email or username, it
      // could be invalid.
      if (!$author) {
        $message = 'User %uid is not a valid user.';
        throw new FeedsAccessException(t($message, array('%uid' => $entity->uid)));
      }

      if (empty($entity->fid)) {
        $op = 'create';
        $access = file_entity_access($op, $entity->type, $author);
      }
      else {
        $op = 'update';
        $access = file_entity_access($op, $entity, $author);
      }

      if (!$access) {
        $message = 'User %name is not authorized to %op file type %type.';
        throw new FeedsAccessException(t($message, array('%name' => $author->name, '%op' => $op, '%type' => $entity->type)));
      }
    }
  }

  /**
   * Save an entity.
   *
   * @param $entity
   *   Entity to be saved.
   */
  public function entitySave($entity) {
    $this->debug($entity, 'entitySave');

    // See if the media module is available. If it is, check to see
    // if it will handle the given URI.
    if (function_exists('media_parse_to_uri')) {
      try {
        $media_uri = media_parse_to_uri($entity->uri);
      }
      catch (Exception $e) {
        $media_uri = '';
      }
    }

    // If the media module is missing or can't handle the URL, we will see
    // try to copy it locally.
    if (!isset($media_uri) || !$media_uri) {
      // Is it remote?
      if (!file_entity_file_is_local($entity)) {
        $file = FALSE;
        try {
          $file = $this->entityCopyLocal($entity);
        }
        catch (Exception $e) {
          // Ignore any errors and let the file API try and handle things.
        }

        if ($file) {
          $entity = $file;
        }
      }

      // TODO: What if it's local but not in the Drupal path?
      // file_default_scheme() . ':/'
    }


    file_save($entity);
  }

  protected function entityCopyLocal($entity) {
    try {
      // Copy to temporary first.
      $source_uri = file_stream_wrapper_uri_normalize('temporary://' . basename($url));
      if (!@copy(@$entity->uri, $source_uri)) {
        throw new Exception('Unable to copy file ' . $entity->uri);
        return;
      }

      $source_file = file_uri_to_object($source_uri);
      $uri = file_build_uri($source_file->filename);

      // Now to its new home.
      $file = file_move($source_file, $uri, FILE_EXISTS_RENAME);

      return $file;
    }
    catch (Exception $e) {
      // Do nothing on error. We will let it fail out on entitySave if it's going to fail.
    }

    return FALSE;
  }

  /**
   * Delete a series of entities.
   *
   * @param $entity_ids
   *   Array of unique identity ids to be deleted.
   */
  protected function entityDeleteMultiple($fids) {
    $files = file_load_multiple($fids);
    foreach ($files as $file) {
      file_delete($file);
    }
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    $entity_info = entity_get_info('file');
    $types = $entity_info['bundles'];
    $type = isset($types['image']) ? 'image' : FILE_TYPE_NONE;

    return array(
      'bundle' => $type,
      'author' => 0,
      'authorize' => TRUE,
      'debug' => array(),
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);

    // There is no body field on files.
    unset($form['input_format']);

    $author = user_load($this->config['author']);
    $form['author'] = array(
      '#type' => 'textfield',
      '#title' => t('Author'),
      '#description' => t('Select the author of the files to be created - leave empty to assign "anonymous".'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => empty($author->name) ?  'anonymous' : check_plain($author->name),
    );
    $form['authorize'] = array(
      '#type' => 'checkbox',
      '#title' => t('Authorize'),
      '#description' => t('Check that the author has permission to create the file.'),
      '#default_value' => $this->config['authorize'],
    );

    $debug_options = array(
      'newEntity' => 'newEntity',
      'entityLoad' => 'entityLoad',
      'entitySave' => 'entitySave',
      'setTargetElement' => 'setTargetElement',
      'existingEntityId' => 'existingEntityId',
    );
    $form['debug_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Debug'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['debug_fieldset']['debug'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Debug query'),
      '#options' => $debug_options,
      '#default_value' => isset($this->config['debug']) ? $this->config['debug'] : array(),
    );

    return $form;
  }

  /**
   * Override parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
    if ($author = user_load_by_name($values['author'])) {
      $values['author'] = $author->uid;
    }
    else {
      $values['author'] = 0;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    $targets['fid'] = array(
      'name' => t('File ID'),
      'description' => t('The fid of the file. NOTE: use this feature with care, file ids are usually assigned by Drupal.'),
      'optional_unique' => TRUE,
    );
    $targets['filename'] = array(
      'name' => t('Filename'),
      'description' => t('The filename of the file.'),
      'optional_unique' => TRUE,
    );
    $targets['uri'] = array(
      'name' => t('File URI'),
      'description' => t('The URI of the file. NOTE: use this feature with care, file URIs are usually assigned by Drupal. If the media module is installed, it will attempt to parse the passed URI for remote files.'),
      'optional_unique' => TRUE,
    );
    $targets['bundle'] = array(
      'name' => t('File Type'),
      'description' => t('The type/bundle of the file. NOTE: use this feature with care, file types are usually assigned by Drupal.'),
    );
    $targets['uid'] = array(
      'name' => t('User ID'),
      'description' => t('The Drupal user ID of the file author.'),
    );
    $targets['user_name'] = array(
      'name' => t('Username'),
      'description' => t('The Drupal username of the file author.'),
    );
    $targets['user_mail'] = array(
      'name' => t('User email'),
      'description' => t('The email address of the file author.'),
    );

    // Let other modules expose mapping targets.
    self::loadMappers();
    $entity_type = $this->entityType();
    $bundle = $this->config['bundle'] ? $this->config['bundle'] : FILE_TYPE_NONE;
    drupal_alter('feeds_processor_targets', $targets, $entity_type, $bundle);

    return $targets;
  }

  /**
   * Override setTargetElement to operate on a target item that is a file.
   */
  public function setTargetElement(FeedsSource $source, $target_file, $target_element, $value) {
    $this->debug(array($source, $target_file, $target_element, $value), 'setTargetElement');

    switch ($target_element) {
      case 'uri':
        $uri = NULL;
        if (function_exists('media_parse_to_uri')) {
          $uri = media_parse_to_uri($value);
        }

        if (isset($uri)) {
          // Get full file object. This will had a FID if the URI already exists.
          $file = file_uri_to_object($uri);

          $target_file->filename = $file->filename;
          $target_file->uri = $file->uri;
          $target_file->filemime = $file->filemime;
          $target_file->filesize = $file->filesize;
          $target_file->status = $file->status;
        }
        else {
          $target_file->uri = $value;
        }
        break;
      case 'user_name':
        if ($user = user_load_by_name($value)) {
          $target_file->uid = $user->uid;
        }
        break;
      case 'user_mail':
        if ($user = user_load_by_mail($value)) {
          $target_file->uid = $user->uid;
        }
        break;
      default:
        parent::setTargetElement($source, $target_file, $target_element, $value);
        break;
    }
  }

  /**
   * Get nid of an existing feed item node if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($fid = parent::existingEntityId($source, $result)) {
      return $fid;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    $unique_targets = $this->uniqueTargets($source, $result);
    $this->debug($unique_targets, 'existingEntityId');

    foreach ($unique_targets as $target => $value) {
      switch ($target) {
        case 'fid':
          $fid = db_query("SELECT fid FROM {file_managed} WHERE fid = :fid", array(':fid' => $value))->fetchField();
          break;

        case 'filename':
          $fid = db_query("SELECT fid FROM {file_managed} WHERE filename = :filename", array(':filename' => $value))->fetchField();
          break;

        case 'uri':
          $value = trim($value);
          $uri = FALSE;

          // If the media module is present we will use it to match a URI.
          if (function_exists('media_parse_to_uri')) {
            try {
              $uri = media_parse_to_uri($value);
            }
            catch (Exception $e) {
              // TODO: watchdog the exception.
            }
          }
          // Else, do we have a valid preformed URI?
          elseif (file_valid_uri($value)) {
            $uri = $value;
          }
          // Else, just try to use the site's default scheme
          else {
            $uri = file_default_scheme() . '://' . $value;
          }

          if ($uri) {
            $uri = file_stream_wrapper_uri_normalize($uri);
            $fid = db_query("SELECT fid FROM {file_managed} WHERE uri = :uri", array(':uri' => $uri))->fetchField();
          }
          break;
      }
      if ($fid) {
        // Return with the first fid found.
        return $fid;
      }
    }
    return 0;
  }

  protected function debug($item, $source) {
    if (!isset($this->debug)) {
      $debug = isset($this->config['debug']) ? $this->config['debug'] : array();
      $this->debug = array_keys(array_filter($debug));
    }

    if (in_array($source, $this->debug)) {
      $o = '<ul>';
      foreach ($item as $key => $val) {
        $o .= '<li>' . check_plain($key) . ' => ' . check_plain(var_export($val, TRUE)) . '</li>';
      }
      $o .= '</ul>';
      drupal_set_message($source . ':' . $o);
    }
  }
}

