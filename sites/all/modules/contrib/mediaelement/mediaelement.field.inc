<?php

/**
 * @file
 * Field integration for the MediaElement module.
 */

/**
 * Implements hook_field_formatter_info().
 */
function mediaelement_field_formatter_info() {
  $formatters = array();

  $formatters['mediaelement_video'] = array(
    'label' => t('MediaElement Video'),
    'field types' => array('file', 'link_field'),
    'settings' => array(
      'features' => array(
        'playpause' => variable_get('mediaelement_video_default_features_playpause', 1),
        'current' => variable_get('mediaelement_video_default_features_current', 1),
        'progress' => variable_get('mediaelement_video_default_features_progress', 1),
        'duration' => variable_get('mediaelement_video_default_features_duration', 1),
        'tracks' => variable_get('mediaelement_video_default_features_tracks', 1),
        'volume' => variable_get('mediaelement_video_default_features_volume', 1),
        'fullscreen' => variable_get('mediaelement_video_default_features_fullscreen', 1),
      ),
      'volume' => variable_get('mediaelement_video_default_volume', 0.8),
      'controls' => variable_get('mediaelement_video_default_controls', TRUE),
      'show_description' => variable_get('mediaelement_video_default_description', 'none'),
      'width' => variable_get('mediaelement_video_default_width', '640'),
      'height' => variable_get('mediaelement_video_default_height', '385'),
      'autoplay' => variable_get('mediaelement_video_default_autoplay', FALSE),
      'loop' => variable_get('mediaelement_video_default_loop', FALSE),
      'download_link' => variable_get('mediaelement_video_default_download_link', FALSE),
      'download_text' => variable_get('mediaelement_video_default_download_text', t('Download')),
      'preload' => variable_get('mediaelement_video_default_preload', 'none'),
    ),
  );

  $formatters['mediaelement_audio'] = array(
    'label' => t('MediaElement Audio'),
    'field types' => array('file', 'link_field'),
    'settings' => array(
      'features' => array(
        'playpause' => variable_get('mediaelement_audio_default_features_playpause', 1),
        'current' => variable_get('mediaelement_audio_default_features_current', 1),
        'progress' => variable_get('mediaelement_audio_default_features_progress', 1),
        'duration' => variable_get('mediaelement_audio_default_features_duration', 1),
        'tracks' => variable_get('mediaelement_audio_default_features_tracks', 1),
        'volume' => variable_get('mediaelement_audio_default_features_volume', 1),
        'fullscreen' => variable_get('mediaelement_audio_default_features_fullscreen', 1),
      ),
      'volume' => variable_get('mediaelement_audio_default_volume', 0.8),
      'controls' => variable_get('mediaelement_audio_default_controls', TRUE),
      'show_description' => variable_get('mediaelement_audio_default_description', 'none'),
      'width' => variable_get('mediaelement_audio_default_width', '300'),
      'height' => variable_get('mediaelement_audio_default_height', '30'),
      'autoplay' => variable_get('mediaelement_audio_default_autoplay', FALSE),
      'loop' => variable_get('mediaelement_audio_default_loop', FALSE),
      'download_link' => variable_get('mediaelement_audio_default_download_link', FALSE),
      'download_text' => variable_get('mediaelement_audio_default_download_text', t('Download')),
      'preload' => variable_get('mediaelement_audio_default_preload', 'none'),
    ),
  );

  return $formatters;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function mediaelement_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $element = array();

  $element['features'] = array(
    '#title' => t('Features'),
    '#description' => t('Controls on the control bar.'),
    '#type' => 'fieldset',
  );
  $element['features']['playpause'] = array(
    '#title' => t('Play/pause button'),
    '#type' => 'checkbox',
    '#default_value' => $settings['features']['playpause'],
  );
  $element['features']['current'] = array(
    '#title' => t('Current time'),
    '#type' => 'checkbox',
    '#default_value' => $settings['features']['current'],
  );
  $element['features']['progress'] = array(
    '#title' => t('Progress'),
    '#type' => 'checkbox',
    '#default_value' => $settings['features']['progress'],
  );
  $element['features']['duration'] = array(
    '#title' => t('Duration'),
    '#type' => 'checkbox',
    '#default_value' => $settings['features']['duration'],
  );
  $element['features']['tracks'] = array(
    '#title' => t('Tracks'),
    '#type' => 'checkbox',
    '#default_value' => $settings['features']['tracks'],
  );
  $element['features']['volume'] = array(
    '#title' => t('Volume'),
    '#type' => 'checkbox',
    '#default_value' => $settings['features']['volume'],
  );
  $element['features']['fullscreen'] = array(
    '#title' => t('Fullscreen'),
    '#type' => 'checkbox',
    '#default_value' => $settings['features']['fullscreen'],
  );

  $element['volume'] = array(
    '#title' => t('Initial volume'),
    '#type' => 'textfield',
    '#description' => t("Number between 0 and 1."),
    '#default_value' => $settings['volume'],
  );

  $element['controls'] = array(
    '#title' => t('Controls'),
    '#type' => 'checkbox',
    '#default_value' => $settings['controls'],
  );

  $element['show_description'] = array(
    '#title' => t('Show description'),
    '#type' => 'select',
    '#options' => array(
      'none' => t('Do not display'),
      'above' => t('Above element'),
      'below' => t('Below element'),
    ),
    '#default_value' => $settings['show_description'],
  );

  $element['width'] = array(
    '#title' => t('Width'),
    '#type' => 'textfield',
    '#description' => t('Specify width unit using px or %. Valid examples (enter without quotes): "100%" or "345px"'),
    '#default_value' => $settings['width'],
  );

  $element['height'] = array(
    '#title' => t('Height'),
    '#type' => 'textfield',
    '#description' => t('Specify height unit using px or %. Valid examples (enter without quotes): "100%" or "345px"'),
    '#default_value' => $settings['height'],
  );

  $element['autoplay'] = array(
    '#title' => t('Autoplay'),
    '#type' => 'checkbox',
    '#default_value' => $settings['autoplay'],
  );

  $element['loop'] = array(
    '#title' => t('Loop'),
    '#type' => 'checkbox',
    '#default_value' => $settings['loop'],
  );

  $element['download_link'] = array(
    '#title' => t('Download Link'),
    '#type' => 'checkbox',
    '#default_value' => $settings['download_link'],
  );

  $element['download_text'] = array(
    '#title' => t('Download Link Text'),
    '#type' => 'textfield',
    '#default_value' => $settings['download_text'],
  );

  $element['preload'] = array(
    '#title' => t('Preload'),
    '#description' => t('Provide a hint to the user agent about whether it should pre-load the media resource.'),
    '#type' => 'radios',
    '#options' => array(
      'none' => t('None: Do not preload the resource.'),
      'metadata' => t('Metadata: Load only the resource metadata (dimensions, first frame, track list, duration, etc). May cause full preload.'),
      'auto' => t('Automatic: Preload is possible.'),
    ),
    '#default_value' => $settings['preload'],
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function mediaelement_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $autoplay = !empty($settings['autoplay']) ? t('Yes') : t('No');
  $loop = !empty($settings['loop']) ? t('Yes') : t('No');
  return t('Width: @width, Height: @height, Autoplay: @autoplay, Loop: @loop', array(
    '@width' => $settings['width'],
    '@height' => $settings['height'],
    '@autoplay' => $autoplay,
    '@loop' => $loop,
  ));
}

/**
 * Implements hook_field_formatter_view().
 */
function mediaelement_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  // A unique caller per page for the JS specific settings to use. This may be
  // different for ever page view and should not be used for styling.
  static $id = 0;
  $element = array();
  $path = drupal_get_path('module', 'mediaelement');
  foreach ($items as $delta => $item) {
    // Support the link field type which stores it's data in 'url'.
    $src = ($field['type'] == 'link_field') ? $item['url'] : $item['uri'];
    $display['settings']['description'] = $item['description'];
    $settings = $display['settings'];
    $js_settings = array();
    $js_settings['opts'] = array();
    $js_settings['controls'] = (bool) $settings['controls'];
    if ($display['type'] == 'mediaelement_video') {
      $js_settings['opts']['videoHeight'] = $settings['height'];
      $js_settings['opts']['videoWidth'] = $settings['width'];
    }
    elseif ($display['type'] == 'mediaelement_audio') {
      $js_settings['opts']['audioHeight'] = $settings['height'];
      $js_settings['opts']['audioWidth'] = $settings['width'];
    }

    $js_settings['opts']['features'] = array();
    foreach ($settings['features'] as $feature => $value) {
      if (!empty($value)) {
        $js_settings['opts']['features'][] = $feature;
      }
    }
    $js_settings['opts']['startVolume'] = (float) $settings['volume'];

    $class = 'mediaelement-formatter-identifier-' . time() . '-' . $id++;
    $element[$delta] = array(
      '#file' => (object) $item,
      '#attributes' => array(
        'src' => file_create_url($src),
        'class' => array($class),
        'preload' => $display['settings']['preload'],
      ),
      '#settings' => $settings,
      '#attached' => array(
        'library' => array(array('mediaelement', 'mediaelement')),
        'js' => array(
          $path . '/mediaelement.js' => array(),
          0 => array('type' => 'setting', 'data' => array('mediaelement' => array('.' . $class => $js_settings))),
        ),
      ),
    );
    if (!empty($settings['controls'])) {
      $element[$delta]['#attributes']['controls'] = 'controls';
    }

    if ($display['type'] == 'mediaelement_video') {
      $element[$delta]['#theme'] = 'mediaelement_video';
      $element[$delta]['#attributes']['height'] = $display['settings']['height'];
      $element[$delta]['#attributes']['width'] = $display['settings']['width'];
      if (!empty($display['settings']['autoplay'])) {
        // "autoplay" is boolean attribute, i.e. it only needs to be present.
        // http://www.w3.org/TR/html5/media-elements.html#attr-media-autoplay.
        $element[$delta]['#attributes']['autoplay'] = 'autoplay';
      }
      if (!empty($display['settings']['loop'])) {
        $element[$delta]['#attributes']['loop'] = 'loop';
      }
    }
    elseif ($display['type'] == 'mediaelement_audio') {
      $element[$delta]['#theme'] = 'mediaelement_audio';
      if (!empty($display['settings']['autoplay'])) {
        $element[$delta]['#attributes']['autoplay'] = '';
      }
      if (!empty($display['settings']['loop'])) {
        $element[$delta]['#attributes']['loop'] = '';
      }
    }
  }
  return $element;
}
