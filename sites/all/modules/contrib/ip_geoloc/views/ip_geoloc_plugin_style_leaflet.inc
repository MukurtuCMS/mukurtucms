<?php

/**
 * @file
 * ip_geoloc_plugin_style_leaflet.inc
 *
 * Views Style plugin extension for Leaflet (if enabled).
 */

require_once 'ip_geoloc_plugin_style.inc';

define('LEAFLET_MARKERCLUSTER_EXCLUDE_FROM_CLUSTER', 1);
define('LEAFLET_SYNC_CONTENT_TO_MARKER', 1 << 1);
define('LEAFLET_SYNC_MARKER_TO_CONTENT', 1 << 2);
define('LEAFLET_SYNC_MARKER_TO_CONTENT_WITH_POPUP', 1 << 3);
define('LEAFLET_SYNC_REVERT_LAST_MARKER_ON_MAP_OUT', 1 << 4);

class ip_geoloc_plugin_style_leaflet extends views_plugin_style {

  /**
   * Set default Leaflet options.
   */
  public function option_definition() {
    $options = parent::option_definition();

    // The leaflet.module default.
    $options['map'] = array('default' => 'OSM Mapnik');
    $options['map_height'] = array('default' => 300);

    $latitude  = module_exists('location') ? 'location_latitude' : 'ip_geoloc_latitude';
    $longitude = module_exists('location') ? 'location_longitude' : ($latitude == 'ip_geoloc_latitude' ? 'ip_geoloc_longitude' : $latitude);
    $options['ip_geoloc_views_plugin_latitude'] = array('default' => $latitude);
    $options['ip_geoloc_views_plugin_longitude'] = array('default' => $longitude);

    $options['default_marker'] = array(
        'contains' => array(
            'default_marker_color' => array('default' => ''),
            'default_marker_special_char' => array('default' => ''),
            'default_marker_special_char_class' => array('default' => ''),
        ),
    );
    $options['visitor_marker'] = array(
        'contains' => array(
            'visitor_marker_color' => array('default' => ''),
            'visitor_marker_special_char' => array('default' => ''),
            'visitor_marker_special_char_class' => array('default' => ''),
            'visitor_marker_accuracy_circle' => array('default' => FALSE),
        ),
    );

    $options['differentiator'] = array(
        'contains' => array(
            'differentiator_field' => array('default' => ''),
        ),
    );

    $options['center_option'] = array('default' => 0);

    $options['tags'] = array(
        'contains' => array(
            'marker_tag' => array('default' => ''),
            'tag_css_class' => array('default' => 'tag-inside-marker'),
        ),
    );

    $options['tooltips'] = array(
        'contains' => array(
            'marker_tooltip' => array('default' => ''),
        ),
    );

    $options['sync'] = array(
        'contains' => array(
            LEAFLET_SYNC_CONTENT_TO_MARKER => array('default' => FALSE),
            LEAFLET_SYNC_MARKER_TO_CONTENT => array('default' => FALSE),
            LEAFLET_SYNC_MARKER_TO_CONTENT_WITH_POPUP => array('default' => TRUE),
            LEAFLET_SYNC_REVERT_LAST_MARKER_ON_MAP_OUT => array('default' => TRUE),
        ),
    );
    $options['full_screen'] = array('default' => FALSE);
    $options['scale_metric'] = array('default' => FALSE);
    $options['scale_imperial'] = array('default' => FALSE);
    $options['zoom_indicator'] = array('default' => FALSE);
    $options['open_balloons_on_click'] = array('default' => TRUE);
    $options['open_balloons_on_hover'] = array('default' => FALSE);
    $options['goto_content_on_click'] = array('default' => FALSE);
    $options['map_reset'] = array('default' => FALSE);
    $options['map_reset_css_class'] = array('default' => 'R');
    $options['map_cluster_toggle'] = array('default' => FALSE);

    $options['mini_map'] = array(
        'contains' => array(
            'on' => array('default' => FALSE),
            'height' => array('default' => 100),
            'width' => array('default' => 150),
            'toggle' => array('default' => TRUE),
            'scope_color' => array('default' => 'red'),
            'zoom_delta' => array('default' => -5),
        ),
    );

    $options['cluster_radius'] = array('default' => module_exists('leaflet_markercluster') ? 80 : '');
    $options['disable_clustering_at_zoom'] = array('default' => '');

    $options['cluster_differentiator'] = array(
        'contains' => array(
            'cluster_differentiator_fields' => array('default' => ''),
            'zoom_ranges' => array('default' => array()),
            'cluster_tooltips' => array('default' => TRUE),
            'cluster_outline' => array('default' => 0),
            'cluster_touch_mode' => array('default' => 1),
        ),
    );

    $options['cluster_aggregation'] = array(
        'contains' => array(
            'aggregation_field' => array('default' => ''),
            'aggregation_function' => array('default' => ''),
            'ranges' => array('contains' => array()),
            'precision' => array('default' => '')
        ),
    );
    $range = 10;
    foreach (array('small', 'medium', 'large') as $size) {
      $options['cluster_aggregation']['contains']['ranges']['contains'][$size] = array('default' => $range);
      $range *= 10;
    }
    $options['disable_clustering_at_zoom'] = array('default' => '');

    $options['empty_map_center'] = array('default' => '');

    $options['map_options'] = array(
        'contains' => array(
            'maxzoom' => array('default' => 18),
            'zoom' => array('default' => 2),
            'zoom_on_click' => array('default' => ''),
            'center_lat' => array('default' => ''),
            'center_lon' => array('default' => ''),
            'scrollwheelzoom' => array('default' => TRUE),
            'dragging' => array('default' => TRUE),
            'separator' => array('default' => '<br/>'),
        ),
    );
    return $options;
  }

  /**
   * Implements options_form().
   *
   * @todo refactor, break up into more mangeable pieces
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $path = drupal_get_path('module', 'ip_geoloc');
    $select_css_file = strpos(ip_geoloc_marker_directory(), 'amarkers') ? 'ip_geoloc_admin_select_amarkers.css' : 'ip_geoloc_admin_select_markers.css';

    $form['#attached'] = array('css' => array(
        "$path/css/ip_geoloc_admin.css",
        "$path/css/$select_css_file",
    ));
    $form_state['renderer'] = 'leaflet';

    $weight = 1;
    $this->_add_map_and_height($form, $weight);
    ip_geoloc_plugin_style_bulk_of_form($this, $weight, $form, $form_state);
    $form['center_option']['#options'][0] = t('Auto-box to fit all markers (include visitor marker if color <strong>not</strong> set to &lt;none&gt;)');

    $lib_markercluster = module_exists('leaflet_markercluster') ? leaflet_markercluster_get_library_path() : FALSE;
    $fields = ip_geoloc_get_display_fields($this->display->handler, FALSE, TRUE);

    $this->_add_default_marker($form, $weight);
    $this->_add_visitor_marker($form, $weight);
    $this->_add_check_boxes($form, $lib_markercluster, $weight);
    $this->_add_mini_map_inset($form, $weight);
    $this->_add_marker_tags($form, $fields, $weight);
    $this->_add_marker_tooltips($form, $fields, $weight);
    $this->_add_sync($form, $weight);
    $this->_add_markercluster($form, $lib_markercluster, $weight);
    $this->_add_cluster_differentiator($form, $form_state, $lib_markercluster, $weight);
    $this->_add_more_map_options($form, $weight);
  }

  private function _add_map_and_height(&$form, &$weight) {
    $maps = array();
    foreach (ip_geoloc_plugin_style_leaflet_map_get_info() as $key => $map) {
      $maps[$key] = $map['label'];
    }
    $form['map'] = array(
        '#title' => t('Map'),
        '#type' => 'select',
        '#options' => $maps,
        '#default_value' => $this->options['map'],
        '#required' => TRUE,
        '#weight' => $weight++,
    );
    $desc1 = t('Examples: <em>250</em> or <em>50em</em> or <em>40vh</em> (percentage of viewport height).');
    $desc2 = t('If left blank, the height defaults to 300 pixels. The width of the map will extend to its bounding container.');
    $desc3 = t('You may enter <em>&lt;none></em>. If you do, then the height attribute must be set through Javascript or CSS elsewhere or the map will not display. CSS example: <em>.ip-geoloc-map .leaflet-container { height: 150px; }</em>');
    $form['map_height'] = array(
        '#title' => t('Map height'),
        '#type' => 'textfield',
        '#size' => 7,
        '#default_value' => $this->options['map_height'],
        '#description' =>  $desc1 . '<br/>' . $desc2 . '<br/>' . $desc3,
        '#weight' => $weight++,
    );
  }

  private function _add_default_marker(&$form, &$weight) {
    $path = drupal_get_path('module', 'ip_geoloc');
    $desc1 = t('In addition to selecting a color, you may superimpose a special icon on top of each marker. <br><a target="fsymbols" href="!url_fsymbols">fsymbols</a> characters can be copied and pasted straight into the <strong>Font icon character</strong> field. Other libraries like <a target="fontawesome" href="!url_fontawesome">Font Awesome</a> and <a target="flaticon" href="!url_flaticon">flaticon</a> use names that you type in the <strong>Font icon class</strong> field.', array(
        '!url_fsymbols' => url('http://fsymbols.com'),
        '!url_fontawesome' => url('http://fortawesome.github.io/Font-Awesome/cheatsheet'),
        '!url_flaticon' => url('http://flaticon.com'),
    ));
    $desc2 = t('<em>fsymbols</em> require no further installation. For other libraries see the <a target="readme" href="!url_readme">README</a>.', array(
        '!url_readme' => url("$path/README.txt"),
    ));
    $desc3 = t('All this works best with the markers from the <em>/amarkers</em> directory, configurable <a target="config" href="!url_config">here</a>.', array(
        '!url_config' => url('admin/config/system/ip_geoloc'),
    ));

    $form['default_marker'] = array(
        '#type' => 'fieldset',
        '#title' => t('Default marker style'),
        '#description' => $desc1 . '<br/>' . $desc2 . '<br/>' . $desc3,
        '#weight' => $weight++,
    );
    $form['default_marker']['default_marker_color'] = array(
        '#title' => t('Style/color'),
        '#type' => 'select',
        '#default_value' => $this->options['default_marker']['default_marker_color'],
        '#options' => ip_geoloc_marker_colors(),
        '#description' => t('Select an image to use for all location markers whose images are not overridden by the <strong>Location differentiator</strong> below.'),
        '#attributes' => array('class' => array('marker-color')),
    );
    $form['default_marker']['default_marker_special_char'] = array(
        '#title' => t('Font icon character'),
        '#type' => 'textfield',
        '#size' => 8,
        '#default_value' => $this->options['default_marker']['default_marker_special_char'],
        '#description' => t('Paste directly from <a target="fsymbols" href="!url_fsymbols">fsymbols</a>. If the character displays in color or as a square then it may not save or display correctly.', array(
            '!url_fsymbols' => url('http://text-symbols.com'),
        )),
    );
    $desc4 =  t('Use the class name from the font icon library you are using. Append <strong>light</strong>, <strong>dark</strong> or <strong>red</strong> to change the color. Examples:<br/>Font Awesome: <strong>fa fa-beer light</strong><br/>flaticon: <strong>flaticon-bicycle12 red</strong>');
    $form['default_marker']['default_marker_special_char_class'] = array(
        '#title' => t('Font icon class'),
        '#type' => 'textfield',
        '#size' => 25,
        '#default_value' => $this->options['default_marker']['default_marker_special_char_class'],
        '#description' => $desc4,
    );
  }

  private function _add_visitor_marker(&$form, &$weight) {
    $form['visitor_marker'] = array(
        '#type' => 'fieldset',
        '#title' => t('Visitor marker style'),
        '#description' => t('For the visitor marker to show, enable the <em>Set my location</em> block and/or tick the option to periodically reverse-geocode via Google, under the <a href="@config_page">Data collection options</a>.', array(
            '@config_page' => url('admin/config/system/ip_geoloc'),
        )),
        '#weight' => $weight++,
    );

    $visitor_marker_colors = array(
        'none' => '<' . t('none') . '>') +
        ip_geoloc_marker_colors();
        unset($visitor_marker_colors['0']);

        $form['visitor_marker']['visitor_marker_color'] = array(
            '#title' => t('Style/color'),
            '#type' => 'select',
            '#multiple' => FALSE,
            '#default_value' => $this->options['visitor_marker']['visitor_marker_color'],
            '#options' => $visitor_marker_colors,
            '#attributes' => array('class' => array('marker-color')),
        );
        $form['visitor_marker']['visitor_marker_special_char'] = array(
            '#title' => t('Font icon character'),
            '#type' => 'textfield',
            '#size' => 8,
            '#default_value' => $this->options['visitor_marker']['visitor_marker_special_char'],
            '#description' => t('As above'),
        );
        $form['visitor_marker']['visitor_marker_special_char_class'] = array(
            '#title' => t('Font icon class'),
            '#type' => 'textfield',
            '#size' => 25,
            '#default_value' => $this->options['visitor_marker']['visitor_marker_special_char_class'],
            '#description' => t('As above.'),
        );
        $form['visitor_marker']['visitor_marker_accuracy_circle'] = array(
            '#title' => t('Accuracy circle'),
            '#type' => 'checkbox',
            '#default_value' => $this->options['visitor_marker']['visitor_marker_accuracy_circle'],
            '#description' => t("Display a circle depicting where the visitor's real location is most likely to be."),
        );
  }

  private function _add_marker_tags(&$form, $fields, &$weight) {
    $form['tags'] = array(
        '#title' => t('Marker tags'),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => empty($this->options['tags']['marker_tag']),
        '#description' => t('Each marker may have a tag. A tag is a number or short text shown permanently above, below or inside the marker.'),
        '#weight' => $weight++,
    );
    $form['tags']['marker_tag'] = array(
        '#title' => t('Views field to populate tags'),
        '#type' => 'select',
        '#default_value' => $this->options['tags']['marker_tag'],
        '#options' => $fields,
        '#description' => t('Example: "Content: Title". Use "Global: View result counter" if you want to number your locations.'),
    );
    $form['tags']['tag_css_class'] = array(
        '#title' => t('Tag position and style'),
        '#type' => 'textfield',
        '#default_value' => $this->options['tags']['tag_css_class'],
        '#description' => t('The CSS class or classes applied to each tag. Tagged marker CSS classes coming with this module are <strong>tag-above-marker</strong>, <strong>tag-below-marker</strong> and <strong>tag-inside-marker</strong>. If you opted to have <em>no markers</em>, i.e. tags only, you may use <strong>tag-rounded-corners</strong> or <strong>tag-pointy-circle</strong>, which is recommended for numbers. You may also create your own CSS classes and use them here.'),
    );
  }

  private function _add_marker_tooltips(&$form, $fields, &$weight) {
    $form['tooltips'] = array(
        '#title' => t('Marker tooltips'),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => empty($this->options['tooltips']['marker_tooltip']),
        '#description' => t('In addition to balloons, which pop up when markers are <em>clicked</em>, you can have tooltips. A tooltip is a short text that appears when you <em>hover</em> over a marker.'),
        '#weight' => $weight++,
    );
    $note_polygons = t('Applies to markers. If you want tooltips for lines and polygons too, please use this selector in combination with <a href="@url_leaflet_label">Leaflet Label</a>.', array(
        '@url_leaflet_label' => url('http://drupal.org/project/leaflet_label'))
        );
    $form['tooltips']['marker_tooltip'] = array(
        '#title' => t('Views field to populate tooltips'),
        '#type' => 'select',
        //'#multiple' => TRUE,
        //'#size' => 6,
        '#default_value' => $this->options['tooltips']['marker_tooltip'],
        '#options' => $fields,
        '#description' => t('Example: "Content: Title"') . '<br/>' . $note_polygons,
    );
  }

  private function _add_check_boxes(&$form, $lib_markercluster, &$weight) {
    $form['full_screen'] = array(
        '#title' => t('Add a full-screen toggle to the map'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['full_screen'],
        '#weight' => $weight++,
    );
    $lib_fullscreen = libraries_get_path('leaflet-fullscreen');
    if ($lib_fullscreen) {
      $file_fullscreen = $lib_fullscreen . '/dist/Leaflet.fullscreen.min.js';
      if (!file_exists($file_fullscreen)) {
        $form['full_screen']['#description'] = t('Error: <em>leaflet-fullscreen</em> library found, but %js_file is missing.', array('%js_file' => $file_fullscreen));
      }
    }
    else {
      $form['full_screen']['#description'] = t('Requires this <a target="_js" href="@js_lib">JS library</a> to be downloaded to <em>/sites/all/libraries</em>. Change the directory name to <em>leaflet-fullscreen</em>.', array(
          '@js_lib' => 'https://github.com/Leaflet/Leaflet.fullscreen'));
    }

    $form['scale_imperial'] = array(
        '#title' => t('Add an imperial (miles) scale'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['scale_imperial'],
        '#weight' => $weight++,
    );
    $form['scale_metric'] = array(
        '#title' => t('Add a metric (km) scale'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['scale_metric'],
        '#weight' => $weight++,
    );
    $form['zoom_indicator'] = array(
        '#title' => t('Add an indicator showing the active zoom level'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['zoom_indicator'],
        '#weight' => $weight++,
    );
    $form['map_reset'] = array(
        '#title' => t('Add a reset button'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['map_reset'],
        '#description' => t('This button allows the visitor to reset the map to its initial bounds (center and zoom level).'),
        '#weight' => $weight++,
    );
    $form['map_reset_css_class'] = array(
        '#title' => t('CSS class to apply to reset button'),
        '#type' => 'textfield',
        '#size' => 40,
        '#default_value' => $this->options['map_reset_css_class'],
        '#description' => t('You can use this to superimpose a font-icon on the button. For instance, if you have the Font Awesome library loaded for your markers, try <strong>fa fa-repeat</strong>. If you enter only one or two characters, for example <strong>R</strong>, these will be used verbatim as the label instead.'),
        '#weight' => $weight++,
        '#states' => array(
            'visible' => array('input[name="style_options[map_reset]"]' => array('checked' => TRUE)),
        ),
    );
    $form['map_cluster_toggle'] = array(
        '#title' => t('Add cluster toggle button'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['map_cluster_toggle'],
        '#description' => t('This button allows the visitor to toggle marker clustering on/off at any time and at any zoom level.') . '<br/>'
        . t('A cluster radius must be specified below.'),
        '#weight' => $weight++,
    );
    $form['open_balloons_on_click'] = array(
        '#title' => t('Display non-excluded fields in a pop-up balloon above the marker, when <em>clicked</em>.'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['open_balloons_on_click'],
        '#weight' => $weight++,
    );
    $form['open_balloons_on_hover'] = array(
        '#title' => t('Display non-excluded fields in a pop-up balloon above the marker, when <em>hovered</em>.'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['open_balloons_on_hover'],
        '#weight' => $weight++,
    );
    $form['goto_content_on_click'] = array(
        '#title' => t('Go to the associated content page, when a marker is <em>clicked</em>.'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['goto_content_on_click'],
        '#weight' => $weight++,
    );
    if (!$lib_markercluster) {
      $form['map_cluster_toggle']['#description'] .= '<br/>' .
          t('<a href="!url_project">Leaflet MarkerCluster</a> must be enabled.', array('!url_project' => url('http://drupal.org/project/leaflet_markercluster')));
    }
  }

  private function _add_sync(&$form, &$weight) {
    $form['sync'] = array(
        '#title' => t('Cross-highlighting between map markers and page content outside the map'),
        '#description' => '<br/>' . t('For the cross-highlighting to work, content outside the map must have the CSS class <em>.sync-id-[nid]</em>, where <em>[nid]</em> represents the content ID.') . ' '
        . t('For Views content, you can do this by adding a <strong>Row class</strong> to the Grid, Table, HTML or Unformatted list formats of your Views Attachment or Block displays.'),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => empty($this->options['sync'][LEAFLET_SYNC_CONTENT_TO_MARKER]),
        '#weight' => $weight++,
    );
    $note = t('You can redefine this class to change the default look.');
    $form['sync'][LEAFLET_SYNC_CONTENT_TO_MARKER] = array(
        '#title' => t('When hovering markers on the map, highlight associated content on the page'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['sync'][LEAFLET_SYNC_CONTENT_TO_MARKER] && $this->options['sync'][LEAFLET_SYNC_MARKER_TO_CONTENT],
        '#description' => t('Content is highlighted dynamically through the automatic addition of the CSS class <em>.synced-marker-hover</em>.') . ' '
        . $note,
        '#weight' => $weight++,
    );
    $caveat = t('For this feature to work in combination with any <em>sorting</em> on the hovered content, the associated Views display must have <em>Use Ajax: No</em>.');
    $form['sync'][LEAFLET_SYNC_MARKER_TO_CONTENT] = array(
        '#title' => t('When hovering content, highlight associated markers on the map'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['sync'][LEAFLET_SYNC_MARKER_TO_CONTENT],
        '#description' => t('Markers are highlighted dynamically through the automatic addition of the CSS class <em>.synced-content-hover</em>.') . ' '
        . $note . '<br/>' . $caveat,
        '#weight' => $weight++,
    );
    $form['sync'][LEAFLET_SYNC_MARKER_TO_CONTENT_WITH_POPUP] = array(
        '#title' => t('As above, but also pop up marker balloons'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['sync'][LEAFLET_SYNC_MARKER_TO_CONTENT_WITH_POPUP],
        '#states' => array(
            'visible' => array(':input[name="style_options[sync][4]"]' => array('checked' => TRUE)),
        ),
        '#weight' => $weight++,
    );
    $form['sync'][LEAFLET_SYNC_REVERT_LAST_MARKER_ON_MAP_OUT] = array(
        '#title' => t('Unhighlight marker and close its balloon when hovering off the map'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['sync'][LEAFLET_SYNC_REVERT_LAST_MARKER_ON_MAP_OUT],
        '#states' => array(
            'visible' => array(':input[name="style_options[sync][4]"]' => array('checked' => TRUE)),
        ),
        '#weight' => $weight++,
    );
  }

  private function _add_mini_map_inset(&$form, &$weight) {

    $form['mini_map'] = array(
        '#title' => t('Mini-map inset'),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => !empty($this->options['mini_map']['on']),
        '#description' => t('A zoomed-out version of the main map as a mini-map inset in the bottom corner.'),
        '#weight' => $weight++,
    );
    $form['mini_map']['on'] = array(
        '#title' => t('Enable mini-map inset'),
        '#type' => 'checkbox',
        '#default_value' => !empty($this->options['mini_map']['on']),
    );
    $form['mini_map']['height'] = array(
        '#title' => t('Height of inset'),
        '#type' => 'textfield',
        '#size' => 4,
        '#field_suffix' => t('px'),
        '#default_value' => $this->options['mini_map']['height'],
        '#states' => array(
            'visible' => array('input[name="style_options[mini_map][on]"]' => array('checked' => TRUE)),
        ),
    );
    $form['mini_map']['width'] = array(
        '#title' => t('Width of inset'),
        '#type' => 'textfield',
        '#size' => 4,
        '#field_suffix' => t('px'),
        '#default_value' => $this->options['mini_map']['width'],
        '#states' => array(
            'visible' => array('input[name="style_options[mini_map][on]"]' => array('checked' => TRUE)),
        ),
    );
    $form['mini_map']['toggle'] = array(
        '#title' => t('Allow visitor to minimise inset'),
        '#type' => 'checkbox',
        '#default_value' => !empty($this->options['mini_map']['toggle']),
        '#states' => array(
            'visible' => array('input[name="style_options[mini_map][on]"]' => array('checked' => TRUE)),
        ),
    );
    $form['mini_map']['scope_color'] = array(
        '#title' => t('Scope rectangle color'),
        '#type' => 'textfield',
        '#size' => 10,
        '#default_value' => $this->options['mini_map']['scope_color'],
        '#description' => t('<em>#rrggbb</em> or <a target="_colors" href="@url">color name</a>.', array(
            '@url' => url('http://www.w3schools.com/html/html_colornames.asp'))),
        '#states' => array(
            'visible' => array('input[name="style_options[mini_map][on]"]' => array('checked' => TRUE)),
        ),
    );
    $form['mini_map']['zoom_delta'] = array(
        '#title' => t('Zoom delta'),
        '#type' => 'textfield',
        '#size' => 3,
        '#default_value' => $this->options['mini_map']['zoom_delta'],
        '#description' => t('The difference between the zoom levels of main map and mini-map.'),
        '#states' => array(
            'visible' => array('input[name="style_options[mini_map][on]"]' => array('checked' => TRUE)),
        ),
    );
    $lib_minimap = libraries_get_path('leaflet-minimap');
    if ($lib_minimap) {
      $file_minimap = $lib_minimap . '/dist/Control.MiniMap.min.js';
      if (!file_exists($file_minimap)) {
        $form['mini_map']['#description'] .= '<br/>' . t('Error: <em>leaflet-minimap</em> library found, but %js_file is missing.', array('%js_file' => $file_minimap));
      }
    }
    else {
      $form['mini_map']['#description'] .= '<br/>' . t('Requires this <a target="_js" href="@js_lib">JS library</a> to be downloaded to <em>/sites/all/libraries</em>. Change the directory name to <em>leaflet-minimap</em>.', array(
          '@js_lib' => 'https://github.com/Norkart/Leaflet-Minimap'));
    }
  }

  private function _add_markercluster(&$form, $lib_markercluster, &$weight) {
    $desc_a = t('A typical cluster radius is 20 to 100 px. When you use a <em>cluster region differentiator</em> (see below), a marker radius of 200 px or more may give superior results. <br/>The visitor marker is excluded from clustering. Enter 0 to disable clustering altogether.');
    $desc_b = t('Requires the <a target="project" href="!url_project">Leaflet MarkerCluster</a> module.', array(
        '!url_project' => url('http://drupal.org/project/leaflet_markercluster')
    ));
    $form['cluster_radius'] = array(
        '#title' => t('Marker cluster radius'),
        '#type' => 'textfield',
        '#field_suffix' => t('px'),
        '#size' => 4,
        '#default_value' => $this->options['cluster_radius'],
        '#description' => $lib_markercluster ? $desc_a : $desc_b,
        '#weight' => $weight++,
    );
    $form['disable_clustering_at_zoom'] = array(
        '#title' => t('Disable clustering at zoom'),
        '#type' => 'textfield',
        '#size' => 4,
        '#default_value' => is_numeric($this->options['disable_clustering_at_zoom']) ? $this->options['disable_clustering_at_zoom'] : '',
        '#description' => t('If you specify a zoom level, then there will be no clustering beyond that zoom level, regardless of the radius specified.'),
        '#weight' => $weight++,
    );
    $form['allow_clusters_of_one'] = array(
        '#title' => t('Allow clusters of one'),
        '#type' => 'checkbox',
        '#default_value' => $this->options['allow_clusters_of_one'],
        '#description' => t('Especially recommended when your clusters employ aggregation functions.'),
        '#weight' => $weight++,
    );
  }

  private function _add_cluster_differentiator(&$form, &$form_state, $lib_markercluster, &$weight) {
    $path = drupal_get_path('module', 'ip_geoloc');
    $intro = t('Region-aware marker clustering with <a target="regionbound" href="!url_regionbound">RegionBound</a>. See the <a target="readme" href="!url_readme">README</a> for details.', array(
        '!url_regionbound' => url('http://regionbound.com'),
        '!url_readme' => url("$path/README.txt"),
    ));
    $form['cluster_differentiator'] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        '#title' => t('Cluster region differentiator'),
        '#description' => '<em>' . $intro . '</em><br/>',
        // The id in the prefix must match the AJAX submit handlers below.
        '#prefix' => '<div id="cluster-differentiator-wrapper">',
        '#suffix' => '</div>',
        '#weight' => $weight++,
    );
    $region_field_names = NULL;
    if (isset($form_state['triggering_element'])) {
      // Get here when any form element with #ajax was changed/clicked causing
      // an auto-rebuild of the form.
      if (strpos($form_state['triggering_element']['#id'], 'cluster-differentiator-field') > 0) {
        // Get here when it was the cluster-differentiator multi-select that was clicked.
        $region_field_names = $form_state['triggering_element']['#value'];
      }
    }
    else {
      $region_field_names = $this->options['cluster_differentiator']['cluster_differentiator_fields'];
    }
    if (!module_exists('leaflet_markercluster')) {
      $desc = t('Requires the <a target="project" href="!url_project">Leaflet MarkerCluster</a> module', array(
          '!url_project' => url('http://drupal.org/project/leaflet_markercluster')
      ));
      $form['cluster_differentiator']['#description'] .= $desc . ' ' . t('and <a href="!url_regionbound">RegionBound</a> JS plugin.', array('!url_regionbound' => url('http://regionbound.com')));
    }
    elseif ($lib_markercluster && (empty($region_field_names) || !reset($region_field_names))) {
      $note_region = t('Download the file %js from <a target="regionbound" href="!url_regionbound">Regionbound</a> and drop it in %directory, without renaming. Then select your region differentiator below.', array(
          '%js' => IP_GEOLOC_LEAFLET_MARKERCLUSTER_REGIONBOUND_JS,
          '%directory' => $lib_markercluster,
          '!url_regionbound' => url('http://regionbound.com'),
      ));
      $form['cluster_differentiator']['#description'] .= "<p>$note_region</p>";
    }
    $fields = ip_geoloc_get_display_fields($this->display->handler, FALSE, FALSE);
    $form['cluster_differentiator']['cluster_differentiator_fields'] = array(
        '#title' => t('Region differentiator'),
        '#type' => 'select',
        '#multiple' => TRUE,
        '#size' => 6,
        '#options' => $fields,
        '#default_value' => $region_field_names,
        '#ajax' => array(
            'callback' => '_ip_geoloc_plugin_style_leaflet_refresh_cluster_fieldset_js',
            'wrapper' => 'cluster-differentiator-wrapper',
            'effect' => 'fade',
            'speed' => 'fast',
        ),
        '#description' => t('Select a field (or sequence of fields) that reflect for each location marker the region hierarchy it belongs to. Examples are an <a target="drupal" href="!url_addressfield">AddressField</a>, a hierarchical taxonomy term based on regions, or individual fields for country, state, city, suburb (<em>in that order</em>). Make sure that the region differentiator you wish to use is included as a field in your view, so it appears in the list above. Note that region differentiators do <em>not</em> need to be associated with latitudes or longitudes. They are just name fields.', array(
            '!url_addressfield' => url('http://drupal.org/project/addressfield'),
        )),
    );
    $level = 0;
    if (!empty($region_field_names)) {
      foreach ($region_field_names as $region_field_name) {
        $region_field = field_info_field($region_field_name);
        $field_type = empty($region_field['type']) ? '' : $region_field['type'];
        $region_depth = $this->get_region_field_depth($region_field);
        $zoom_titles = $this->_get_zoom_titles($field_type, $fields[$region_field_name], $region_depth);
        foreach ($zoom_titles as $title) {
          $level++;
          $default_value = isset($this->options['cluster_differentiator']['zoom_ranges'][$level])
          ? $this->options['cluster_differentiator']['zoom_ranges'][$level] : '';
          $form['cluster_differentiator']['zoom_ranges'][$level] = array(
              '#type' => 'textfield',
              '#title' => filter_xss_admin($title),
              '#size' => 28,
              '#default_value' => $default_value,
              '#element_validate' => array('ip_geoloc_range_widget_validate'),
          );
        }
      }
      if ($level > 0) {
        $desc1 = ($level === 1)
        ? t('Below enter the zoom level range to be associated with the selected differentiator.')
        : t('Below enter the zoom level ranges to which each of the region hierarchy levels apply.') . '<br/>' . t('Zoom ranges may start and end at any level, but must not overlap.');
        $desc2 = ''; // t('Minimum and maximum zoom levels for this map can be found below under <strong>More map options</strong>.');
        $desc3 = t('Or leave all fields blank to use the defaults and refine later.');
        $zoom1 = t('Typical zoom ranges for Europe: country: 3--6, province: 7--9, city: 10--14, postcode: 15--18');
        $zoom2 = t('Typical zoom ranges for US & Canada: country: 1--3, state: 4--8, city: 9--13, zip: 14--18');
        $zoom3 = t('Typical zoom ranges for Australia: country: 1--2, state: 3--9, city: 10--13, suburb/postcode: 14--18');

        $form['cluster_differentiator']['cluster_differentiator_fields']['#description'] =
        implode('<br/>', array("$desc1 $desc2<br/>$desc3<br/>", $zoom1, $zoom2, $zoom3));
      }
      $form['cluster_differentiator']['cluster_tooltips'] = array(
          '#title' => t('Add cluster tooltips'),
          '#type' => 'checkbox',
          '#default_value' => $this->options['cluster_differentiator']['cluster_tooltips'],
          '#description' => t("When hovering a cluster, tooltips reveal the cluster region name and the names of its populated subregions."),
      );
      $form['cluster_differentiator']['cluster_touch_mode'] = array(
          '#title' => t('Cluster action on touch devices (e.g. mobile phones)'),
          '#type' => 'radios',
          '#options' => array(
              1 => t('Single tap displays cluster regions, double-tap drills into cluster (default)'),
              0 => t('Single tap drills into cluster. Sub-region names not displayed, but visible on mouse devices.'),
          ),
          '#default_value' => $this->options['cluster_differentiator']['cluster_touch_mode'],
          '#description' => t('Applies only to devices that do not have a mouse, like mobile phones.'),
      );
      $form['cluster_differentiator']['cluster_outline'] = array(
          '#title' => t('Cluster population outline'),
          '#type' => 'select',
          '#options' => array(
              0 => t('Traditional (convex hull)'),
              1 => t('Avant-garde (heuristic hull)'),
          ),
          '#default_value' => $this->options['cluster_differentiator']['cluster_outline'],
          '#description' => t('When hovering a cluster, a <a target="regionbound" href="!url_regionbound">coverage outline</a> visualises the envelope or footprint of the underlying marker population. Select your preferred style of doing this.', array(
              '!url_regionbound' => url('http://regionbound.com/enhanced-cluster-envelope-using-heuristic-hull'),
          )),
      );
    }
    $intro = t('Use clusters to report on region aggregates; requires <a target="regionbound" href="!url_regionbound">RegionBound</a>', array(
        '!url_regionbound' => url('http://regionbound.com/coffee-prices-across-melbourne'),
    ));
    $desc = t('This feature aggregates values of a selected field across every region and displays the resulting <em>sum/average/min/max</em> on each cluster icon at every zoom level. It also colours each cluster icon based on its aggregated value, rather than its marker count.');
    $form['cluster_aggregation'] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#title' => t('Cluster aggregation'),
        '#description' => "<em>$intro</em><p>$desc</p>",
        '#weight' => $weight++,
    );
    $form['cluster_aggregation']['aggregation_field'] = array(
        '#title' => t('Field to perform aggregation on'),
        '#type' => 'select',
        '#default_value' => $this->options['cluster_aggregation']['aggregation_field'],
        '#options' => $fields,
        '#description' => t('For aggregation to make sense, the selected field must be numeric or represent a list. If a list, aggregation will be applied to the element <em>count</em>.'),
    );
    $form['cluster_aggregation']['aggregation_function'] = array(
        '#title' => t('Aggregation function'),
        '#type' => 'select',
        '#default_value' => $this->options['cluster_aggregation']['aggregation_function'],
        '#options' => array(
            'average' => t('Average'),
            'maximum' => t('Maximum'),
            'minimum' => t('Minimum'),
            'sum' => t('Sum'),
        ),
    );
    $form['cluster_aggregation']['ranges'] = array(
        '#type' => 'item',
        '#description' => t('Edit the above to change the color-coding of cluster icons based on their aggregate values.'),
        '#prefix' => '<div id="cluster-aggregation-aggregate">',
        '#suffix' => '</div>',
    );
    foreach (array('small', 'medium', 'large') as $size) {
      $default_value = isset($this->options['cluster_aggregation']['ranges'][$size])
      ? $this->options['cluster_aggregation']['ranges'][$size] : '';
      $form['cluster_aggregation']['ranges'][$size] = array(
          '#title' => "$size " . t('goes to'),
          '#type' => 'textfield',
          '#size' => 8,
          '#default_value' => $default_value,
      );
    }
    $form['cluster_aggregation']['precision'] = array(
        '#title' => t('Precision'),
        '#type' => 'textfield',
        '#size' => 2,
        '#default_value' => $this->options['cluster_aggregation']['precision'],
        '#description' => t('Number of significant digits used to display the aggregate value on the cluster icon. Leave blank for native formatting.'),
    );
  }

  private function _add_more_map_options(&$form, &$weight) {
    $selected_map = ip_geoloc_plugin_style_leaflet_map_get_info($this->options['map']);
    $zoom_top = 21;
    if (isset($selected_map['settings']['maxZoom'])) {
      $zoom_top = $selected_map['settings']['maxZoom'];
    }
    $form['map_options'] = array(
        '#title' => t('More map options'),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        // Or: empty($this->options['map_options']['zoom']) ?
        '#collapsed' => TRUE,
        '#weight' => $weight++,
    );
    $form['map_options']['maxzoom'] = array(
        '#title' => t('Maximum zoom level (0..@zoomtop)', array('@zoomtop' => $zoom_top)),
        '#type' => 'textfield',
        '#size' => 2,
        '#default_value' => $this->options['map_options']['maxzoom'],
        '#description' => t('Note that not all maps support all zoom levels.'),
    );
    $initial_zoom_max = $zoom_top;
    if (is_numeric($this->options['map_options']['maxzoom'])) {
      $initial_zoom_max = min($zoom_top, $this->options['map_options']['maxzoom']);
    }
    $form['map_options']['zoom'] = array(
        '#title' => t('Initial zoom level (0..@maxzoom)', array('@maxzoom' => $initial_zoom_max)),
        '#type' => 'textfield',
        '#size' => 2,
        '#default_value' => $this->options['map_options']['zoom'],
        '#description' => t('Does not apply to auto-box centering except when only one or no markers are shown.'),
    );
    $form['map_options']['zoom_on_click'] = array(
        '#title' => t('Zoom-on-click zoom level (1..@maxzoom)', array('@maxzoom' => $zoom_top)),
        '#type' => 'textfield',
        '#size' => 2,
        '#default_value' => $this->options['map_options']['zoom_on_click'],
        '#description' => t('Level to zoom to when a marker is clicked. Leave blank to disable this feature.'),
    );
    $form['map_options']['center_lat'] = array(
        '#title' => t('Latitude of initial center of map'),
        '#type' => 'textfield',
        '#size' => 6,
        '#default_value' => $this->options['map_options']['center_lat'],
        '#description' => t('If both latitude and longitude are filled out, these override any centering option until the visitor changes their location.'),
    );
    $form['map_options']['center_lon'] = array(
        '#title' => t('Longitude of initial center of map'),
        '#type' => 'textfield',
        '#size' => 6,
        '#default_value' => $this->options['map_options']['center_lon'],
        '#description' => t('If both latitude and longitude are filled out, these override any centering option until the visitor changes their location.'),
    );
    $form['map_options']['scrollwheelzoom'] = array(
        '#title' => t('Enable scroll wheel zoom'),
        '#type' => 'select',
        '#default_value' => $this->options['map_options']['scrollwheelzoom'],
        '#options' => array(TRUE => t('Yes'), FALSE => t('No')),
    );
    $form['map_options']['dragging'] = array(
        '#title' => t('Dragging/Panning of the map'),
        '#type' => 'select',
        '#default_value' => $this->options['map_options']['dragging'],
        '#options' => array(TRUE => t('Yes'), FALSE => t('No')),
    );
    $form['map_options']['separator'] = array(
        '#title' => t('Separator used in marker balloons'),
        '#type' => 'textfield',
        '#size' => 10,
        '#default_value' => $this->options['map_options']['separator'],
        '#description' => t('You may use most HTML tags.'),
    );
  }

  /**
   * Validate the options form.
   */
  public function options_validate(&$form, &$form_state) {
    ip_geoloc_plugin_style_bulk_of_form_validate($form, $form_state);
    $style_options = $form_state['values']['style_options'];
    $map_height = trim($style_options['map_height']);
    if (is_numeric($map_height) && $map_height <= 0) {
      form_error($form['map_height'], t('Map height must be a positive number.'));
    }
    $selected_map = ip_geoloc_plugin_style_leaflet_map_get_info($style_options['map']);
    $zoom_top = 18;
    if (isset($selected_map['settings']['maxZoom'])) {
      $zoom_top = $selected_map['settings']['maxZoom'];
    }
    $max_zoom = $style_options['map_options']['maxzoom'];
    if ($max_zoom != '' && (!is_numeric($max_zoom) || $max_zoom < 0 || $max_zoom > $zoom_top)) {
      form_error($form['map_options']['maxzoom'], t('"Maximum zoom level" for %map must be in range 0..@zoomtop', array(
          '%map' => $selected_map['label'], '@zoomtop' => $zoom_top)));
    }
    $zoom = $style_options['map_options']['zoom'];
    if ($zoom != '' && (!is_numeric($zoom) || $zoom < 0 || $zoom > $max_zoom)) {
      form_error($form['map_options']['zoom'], t('"Initial zoom level" must be a non-negative number not greater than "Maximum zoom level".'));
    }
    $disable_zoom = $style_options['disable_clustering_at_zoom'];
    if ($disable_zoom != '' && (!is_numeric($disable_zoom) || $disable_zoom < 0 || $disable_zoom > $max_zoom)) {
      form_error($form['disable_clustering_at_zoom'], t('"Disable clustering at zoom" level must be a positive number not greater than "Maximum zoom level".'));
    }
    if (isset($style_options['cluster_aggregation'])) {
      $cluster_aggregation = $style_options['cluster_aggregation'];
      if (!empty($cluster_aggregation['aggregation_field'])) {
        $aggregation_field_info = field_info_field($cluster_aggregation['aggregation_field']);
        $valid_types = array('number_integer', 'number_decimal', 'number_float', 'entityreference');
        if (!$aggregation_field_info || !in_array($aggregation_field_info['type'], $valid_types)) {
          drupal_set_message(t('A cluster aggregation field that cannot be interpreted as a number may cause unexpected errors.'));
        }
      }
    }
  }

  /**
   * Transform the View result in a list of marker locations and render on map.
   *
   * @todo refactor
   */
  public function render() {
    if (empty($this->options['map']) || !($map = ip_geoloc_plugin_style_leaflet_map_get_info($this->options['map']))) {
      return t('No Leaflet map was selected or map configuration was not found.');
    }
    if (!empty($this->view->live_preview)) {
      return t('The preview function is incompatible with Leaflet maps so cannot be used. Please visit the page path or the block to view your map.');
    }
    $render_start = microtime(TRUE);

    ip_geoloc_plugin_style_render_fields($this);

    $open_balloons_on_click = !empty($this->options['open_balloons_on_click']);
    $open_balloons_on_hover = !empty($this->options['open_balloons_on_hover']);

    $enable_balloons = $open_balloons_on_click || $open_balloons_on_hover;
    $locations = ip_geoloc_plugin_style_extract_locations($this, $enable_balloons);

    $this->fill_out_location_regions($locations);

    $marker_color = $this->options['default_marker']['default_marker_color'];
    $visitor_marker_color = $this->options['visitor_marker']['visitor_marker_color'];
    $center_option = !isset($this->options['center_option']) ? 0 : $this->options['center_option'];
    $sync_flags = 0;
    if (!empty($this->options['sync'][LEAFLET_SYNC_CONTENT_TO_MARKER])) {
      $sync_flags |= LEAFLET_SYNC_CONTENT_TO_MARKER;
    }
    if (!empty($this->options['sync'][LEAFLET_SYNC_MARKER_TO_CONTENT])) {
      $sync_flags |= LEAFLET_SYNC_MARKER_TO_CONTENT;
      if (!empty($this->options['sync'][LEAFLET_SYNC_MARKER_TO_CONTENT_WITH_POPUP])) {
        $sync_flags |= LEAFLET_SYNC_MARKER_TO_CONTENT_WITH_POPUP;
      }
      if (!empty($this->options['sync'][LEAFLET_SYNC_REVERT_LAST_MARKER_ON_MAP_OUT])) {
        $sync_flags |= LEAFLET_SYNC_REVERT_LAST_MARKER_ON_MAP_OUT;
      }
    }
    $has_full_screen = !empty($this->options['full_screen']);
    $has_mini_map = !empty($this->options['mini_map']['on']);
    $zoom_indicator = empty($this->options['zoom_indicator']) ? FALSE : TRUE; /*array('position' => 'topleft')*/;
    $scale_control = FALSE;
    if (!empty($this->options['scale_metric']) || !empty($this->options['scale_imperial'])) {
      $scale_control = array(
          'metric' => !empty($this->options['scale_metric']),
          'imperial' => !empty($this->options['scale_imperial']),
      );
    }
    $goto_content_on_click = !empty($this->options['goto_content_on_click']);
    $reset_control = FALSE;
    if (!empty($this->options['map_reset'])) {
      $label = filter_xss_admin($this->options['map_reset_css_class']);
      $reset_control = array('label' => empty($label) ? ' ' : $label);
    }
    $cluster_control = FALSE;
    if (module_exists('leaflet_markercluster') && !empty($this->options['map_cluster_toggle'])) {
      $cluster_control = array('label' => 'C');
    }
    $cluster_radius = (int)_ip_geoloc_get_session_value('markercluster-radius');
    if ($cluster_radius < 2) {
      $cluster_radius = (int)$this->options['cluster_radius'];
    }
    $disable_clustering_at_zoom = $this->options['disable_clustering_at_zoom'];
    $hull_hug_factor = empty($this->options['cluster_differentiator']['cluster_outline']) ? -1 : 'auto';
    $cluster_tooltips = !empty($this->options['cluster_differentiator']['cluster_tooltips']);
    $cluster_touch_mode = empty($this->options['cluster_differentiator']['cluster_touch_mode']) ? 0 : 'auto';
    $cluster_aggregation_field = $this->options['cluster_aggregation']['aggregation_field'];
    $cluster_aggregation_function = $this->options['cluster_aggregation']['aggregation_function'];
    $cluster_aggregate_ranges = $this->options['cluster_aggregation']['ranges'];
    $cluster_aggregate_precision = $this->options['cluster_aggregation']['precision'];
    $allow_clusters_of_one = !empty($this->options['allow_clusters_of_one']);
    $tag_css_classes = $this->options['tags']['tag_css_class'];
    $module_path = drupal_get_path('module', 'ip_geoloc');
    $marker_path = file_create_url(ip_geoloc_marker_directory());
    $max_zoom = (int) $this->options['map_options']['maxzoom'];
    $zoom = max(1, (int)$this->options['map_options']['zoom']);
    $zoom_on_click = (int) $this->options['map_options']['zoom_on_click'];
    $scroll_wheel_zoom = (bool) $this->options['map_options']['scrollwheelzoom'];
    $dragging = (bool) $this->options['map_options']['dragging'];

    $visitor_location = ip_geoloc_get_visitor_location();
    if (!isset($visitor_location['latitude'])) {
      $visitor_location = db_query('SELECT * FROM {ip_geoloc} WHERE ip_address = :ip_address', array(':ip_address' => ip_address()))->fetchAssoc();
    }
    $use_specified_center = !empty($this->options['map_options']['center_lat']) && !empty($this->options['map_options']['center_lon'])
    && empty($visitor_location['is_updated']);
    if ($use_specified_center) {
      $map['center'] = array(
          'lat' => $this->options['map_options']['center_lat'],
          'lon' => $this->options['map_options']['center_lon'],
      );
    }
    elseif (!empty($locations) &&
        ($center_option == IP_GEOLOC_MAP_CENTER_ON_FIRST_LOCATION ||
            ($visitor_marker_color == 'none' && count($locations) == 1))) {
              $map['center'] = _ip_geoloc_get_center(reset($locations));
    }
    elseif (($center_option == IP_GEOLOC_MAP_CENTER_OF_LOCATIONS || $center_option == IP_GEOLOC_MAP_CENTER_OF_LOCATIONS_WEIGHTED) && !empty($locations)) {
      list($center_lat, $center_lon) = ip_geoloc_center_of_locations($locations, $center_option == IP_GEOLOC_MAP_CENTER_OF_LOCATIONS_WEIGHTED);
      $map['center'] = array(
          'lat' => $center_lat,
          'lon' => $center_lon,
      );
    }
    if (!$use_specified_center && (empty($locations) || $center_option == IP_GEOLOC_MAP_CENTER_ON_VISITOR) && isset($visitor_location['latitude'])) {
      $map['center'] = array(
          'lat' => $visitor_location['latitude'],
          'lon' => $visitor_location['longitude'],
      );
    }

    if (empty($locations)) {
      $ll = trim($this->options['empty_map_center']);
      if (empty($ll)) {
        // No map whatsoever.
        return;
      }
      if ($ll != t('visitor')) {
        // Empty map centered on coordinates provided.
        list($map['center']['lat'], $map['center']['lon']) = preg_split("/[\s,]+/", $ll);
      }
      // else: empty map centered on visitor location, as set above.
    }
    else {
      uasort($locations, '_ip_geoloc_plugin_style_leaflet_compare');
    }

    $marker_dimensions = explode('x', ip_geoloc_marker_dimensions());
    $marker_width  = (int) $marker_dimensions[0];
    $marker_height = (int) $marker_dimensions[1];

    switch (variable_get('ip_geoloc_marker_anchor_pos', 'bottom')) {
      case 'top':
        $marker_anchor = 0;
        break;

      case 'middle':
        $marker_anchor = (int) (($marker_height + 1) / 2);
        break;

      default:
        $marker_anchor = $marker_height;
    }

    $features = array();
    foreach ($locations as $location) {
      $feature = array();
      if (isset($location->latitude) || isset($location->lat)) {
        $feature['type'] = 'point';
        $feature['lat'] = isset($location->latitude)  ? $location->latitude  : $location->lat;
        $feature['lon'] = isset($location->longitude) ? $location->longitude : $location->lon;
        if (!empty($location->random_displacement)) {
          ip_geoloc_add_random_displacement($feature, $location->random_displacement);
          $circle = array(
              'type'=> 'circle',
              'lat' => $feature['lat'],
              'lon' => $feature['lon'],
              'radius' => $location->random_displacement,
          );
          $features[] = $circle;
        }
      }
      elseif (isset($location->component)) {
        // Possibly parsed by leaflet_process_geofield()
        // see _ip_geoloc_plugin_style_extract_lat_lng().
        $feature['type'] = $location->type;
        $feature['component'] = $location->component;
      }
      elseif (isset($location->points)) {
        $feature['type'] = $location->type;
        $feature['points'] = $location->points;
      }

      if (isset($location->id)) {
        // Allow marker events to identify the corresponding node.
        $feature['feature_id'] = $location->id;
      }

      // At this point $feature['type'] should be set.
      if (!empty($feature['type']) && $feature['type'] != 'point') {
        // Linestring, polygon ...
        $feature['flags'] = LEAFLET_MARKERCLUSTER_EXCLUDE_FROM_CLUSTER;
      }
      elseif (!isset($feature['lat'])) {
        // Points must have coords.
        continue;
      }
      if (!empty($sync_flags)) {
        $feature['flags'] = isset($feature['flags']) ? $feature['flags'] | $sync_flags : $sync_flags;
      }
      if ($enable_balloons && isset($location->balloon_text)) {
        $feature['popup'] = $location->balloon_text;
      }
      if (!empty($location->marker_special_char) || !empty($location->marker_special_char_class)) {
        $has_special_markers = TRUE;
        if (!empty($location->marker_special_char)) {
          $feature['specialChar'] = filter_xss_admin($location->marker_special_char);
        }
        if (!empty($location->marker_special_char_class)) {
          $feature['specialCharClass'] = filter_xss_admin($location->marker_special_char_class);
        }
      }
      elseif (!empty($this->options['default_marker']['default_marker_special_char'])
          || !empty($this->options['default_marker']['default_marker_special_char_class'])) {
            $has_special_markers = TRUE;
            $feature['specialChar'] = $this->options['default_marker']['default_marker_special_char'];
            $feature['specialCharClass'] = $this->options['default_marker']['default_marker_special_char_class'];
      }
      if (!empty($location->marker_tooltip)) {
        if (module_exists('leaflet_label')) {
          $feature['label'] = $location->marker_tooltip;
        }
        else {
          $has_special_markers = TRUE;
          $feature['tooltip'] = $location->marker_tooltip;
        }
      }

      if (!empty($location->regions)) {
        $has_special_markers = TRUE;
        // Make sure we start with 0 or regions will come across as Object
        // rather than array.
        $feature['regions'] = array(0 => '') + $location->regions;

        if (isset($location->aggregation_value)) {
          $feature['aggregationValue'] = (float)$location->aggregation_value;
        }
        // Note: cannot use <br/>  or HTML in tooltip as separator. Use \n.
        $feature['tooltip'] = empty($feature['tooltip']) ? '' : $feature['tooltip'] . "\n";
        $second_last = count($feature['regions']) - 2;
        if ($second_last > 0) {
          $feature['tooltip'] .= $feature['regions'][$second_last] . ' - ';
        }
        $feature['tooltip'] .= end($feature['regions']);
      }
      if (!empty($location->marker_tag)) {
        $has_special_markers = TRUE;
        $feature['tag'] = $location->marker_tag;
      }
      if (!empty($tag_css_classes)) {
        $feature['cssClass'] = $tag_css_classes;
      }
      if ((isset($location->marker_color) && _ip_geoloc_is_no_marker($location->marker_color)) ||
          (!isset($location->marker_color) && _ip_geoloc_is_no_marker($marker_color))) {
            // "No marker" as opposed to "default" marker.
            $has_special_markers = TRUE;
            $feature['icon'] = FALSE;
          }
          elseif (!empty($location->marker_color) || !empty($marker_color)) {
            // Switch from default icon to specified color.
            $color = empty($location->marker_color) ? $marker_color : $location->marker_color;
            $feature['icon'] = array(
                'iconUrl' => $marker_path . "/$color.png",
                'iconSize' => array('x' => $marker_width, 'y' => $marker_height),
                'iconAnchor' => array('x' => (int) (($marker_width + 1) / 2), 'y' => $marker_anchor),
                // Just above topline, center.
                'popupAnchor' => array('x' => 0, 'y' => -$marker_height - 1),
            );
          }
          $features[] = $feature;
    }
    if (isset($visitor_location['latitude'])) {
      if ($visitor_marker_color != 'none') {
        // See leaflet/README.txt for examples of Leaflet "features"
        $visitor_feature = array(
            'type' => 'point',
            'lat' => $visitor_location['latitude'],
            'lon' => $visitor_location['longitude'],
            'specialChar' => filter_xss_admin($this->options['visitor_marker']['visitor_marker_special_char']),
            'specialCharClass' => filter_xss_admin($this->options['visitor_marker']['visitor_marker_special_char_class']),
            'popup' => !empty($visitor_location['popup']) ? $visitor_location['popup'] : t('Your approximate location'),
            'tooltip' => !empty($visitor_location['tooltip']) ? $visitor_location['tooltip'] : t('Your approximate location'),
            'zIndex' => 9999,
            // See leaflet_markercluster.drupal.js.
            'flags' => LEAFLET_MARKERCLUSTER_EXCLUDE_FROM_CLUSTER,
        );
        if ($visitor_marker_color != '') {
          if (!empty($visitor_feature['specialChar']) || !empty($visitor_feature['specialCharClass'])) {
            $has_special_markers = TRUE;
          }
          $visitor_feature['icon'] = array(
              'iconUrl' => $marker_path . "/$visitor_marker_color.png",
              'iconSize' => array('x' => $marker_width, 'y' => $marker_height),
              'iconAnchor' => array('x' => (int) (($marker_width + 1) / 2), 'y' => $marker_anchor),
              // Just above topline, center.
              'popupAnchor' => array('x' => 0, 'y' => -$marker_height - 1),
          );
        }
        $features[] = $visitor_feature;
      }
      if (!empty($this->options['visitor_marker']['visitor_marker_accuracy_circle']) && !empty($visitor_location['accuracy'])) {
        $visitor_accuracy_circle = array(
            'type' => 'circle',
            'lat' => $visitor_location['latitude'],
            'lon' => $visitor_location['longitude'],
            'radius' => (float) $visitor_location['accuracy'],
            'popup' => !empty($visitor_location['popup']) ? $visitor_location['popup'] : t("You are within @m meters of the centre of this circle.", array('@m' => $visitor_location['accuracy'])),
            'label' => !empty($visitor_location['tooltip']) ? $visitor_location['tooltip'] : t('You are within this circle'), // requires Leaflet Label
            'zIndex' => 9998,
            'flags' => LEAFLET_MARKERCLUSTER_EXCLUDE_FROM_CLUSTER,
        );
        $features[] = $visitor_accuracy_circle;
      }
    }
    // If auto-box is chosen ($center_option==0), zoom only when there are
    // 0 or 1 markers [#1863374]
    if (!$use_specified_center && empty($center_option) && count($features) > 1) {
      unset($map['center']);
    }
    else {
      $map['settings']['zoom'] = $zoom;
      if (!empty($map['center'])) {
        // A leaflet.drupal.js quirk? Have to specify AND force a center...
        $map['center']['force'] = TRUE;
      }
    }
    $map['settings']['maxZoom'] = $max_zoom;
    $map['settings']['scrollWheelZoom'] = $scroll_wheel_zoom;
    $map['settings']['dragging'] = $dragging;

    $map['settings']['revertLastMarkerOnMapOut'] =
    (bool)($sync_flags & LEAFLET_SYNC_REVERT_LAST_MARKER_ON_MAP_OUT);

    $map['settings']['maxClusterRadius'] = 0;
    if ($cluster_radius > 0) {
      if (module_exists('leaflet_markercluster')) {
        $map['settings']['maxClusterRadius'] = $cluster_radius;
        $map['settings']['disableClusteringAtZoom'] = $disable_clustering_at_zoom;
        $map['settings']['addRegionToolTips'] = $cluster_tooltips;
        $map['settings']['hullHugFactor'] = $hull_hug_factor;
        $map['settings']['touchMode'] = $cluster_touch_mode;
        $map['settings']['animateAddingMarkers'] = TRUE;
        if (!empty($cluster_aggregation_field)) {
          $map['settings']['clusterAggregationFunction'] = $cluster_aggregation_function;
          $map['settings']['clusterAggregateRanges'] = $cluster_aggregate_ranges;
          $map['settings']['clusterAggregatePrecision'] = $cluster_aggregate_precision;
          drupal_add_css(leaflet_markercluster_get_library_path() . '/MarkerCluster.Aggregations.css');
        }
        if ($allow_clusters_of_one) {
          $map['settings']['allowClustersOfOne'] = TRUE;
          $map['settings']['spiderfyDistanceMultiplier'] = 4.0;
        }
      }
      else {
        $display_name = $this->view->get_human_name() . ' (' . $this->display->display_title . ')';
        drupal_set_message(t('Cannot cluster markers in View %display_name, as the module Leaflet MarkerCluster is not enabled.', array('%display_name' => $display_name)), 'warning');
      }
    }

    $zoom_ranges = array_filter($this->options['cluster_differentiator']['zoom_ranges']);
    if (!empty($zoom_ranges)) {
      // Make sure we start array with 0 and no missing elements. Otherwise this
      // array will arrive as an Object on the JS side.
      $region_levels = array_fill(0, $max_zoom + 1, 0);
      foreach ($zoom_ranges as $level => $zoom_range) {
        for ($zoom = 1; $zoom <= $max_zoom; $zoom++) {
          if (ip_geoloc_is_in_range($zoom, $zoom_range)) {
            $region_levels[$zoom] = $level;
          }
        }
      }
      // Remove any gaps and zeroes.
      for ($z = 1; $z <= $max_zoom; $z++) {
        if (empty($region_levels[$z])) {
          $region_levels[$z] = $region_levels[$z - 1];
        }
      }
      $map['settings']['regionLevels'] = $region_levels;
    }
    // See [#1802732].
    $map_id = 'ip-geoloc-map-of-view-' . $this->view->name . '-' . $this->display->id . '-' . md5(serialize($features));

    drupal_add_js(drupal_get_path('module', 'leaflet') . '/leaflet.drupal.js');

    // Don't load sync JS and CSS when option is not requested.
    if ($sync_flags !== 0) {
      drupal_add_js($module_path . '/js/ip_geoloc_leaflet_sync_content.js', array('weight' => 2));
      drupal_add_css($module_path . '/css/ip_geoloc_leaflet_sync_content.css');
    }
    if ($has_full_screen) {
      // Load the 'leaflet-fullscreen' library, containing JS and CSS.
      if (drupal_add_library('ip_geoloc', 'leaflet-fullscreen')) {
        $map['settings']['fullscreenControl'] = array('position' => 'topright');
      }
    }
    if ($has_mini_map) {
      // Load the 'leaflet-minimap' library, containing JS and CSS.
      // See https://github.com/Norkart/Leaflet-MiniMap for more settings.
      if (drupal_add_library('ip_geoloc', 'leaflet-minimap')) {
        $map['settings']['miniMap'] = array(
            'autoToggleDisplay' => TRUE,
            'height' => $this->options['mini_map']['height'],
            'width' => $this->options['mini_map']['width'],
            'position' => 'bottomright', // 'bottomright'
            'toggleDisplay' => !empty($this->options['mini_map']['toggle']),
            'zoomAnimation' => FALSE,
            'zoomLevelOffset' => (int)$this->options['mini_map']['zoom_delta'],
            // Superimposed rectangle showing extent of main map on the inset.
            'aimingRectOptions' => array(
                'color' => $this->options['mini_map']['scope_color'],
                'weight' => 3,
                'fillOpacity' => 0.1,
            ),
            // The "shadow" rectangle that shows the new map outline.
            'shadowRectOptions' => array(
                'color' => '#888',
                'weight' => 1
            ),
        );
      }
    }
    $map['settings']['zoomIndicator'] = $zoom_indicator;
    $map['settings']['zoomOnClick'] = $zoom_on_click;
    $map['settings']['resetControl'] = $reset_control;
    $map['settings']['clusterControl'] = $cluster_control;
    $map['settings']['scaleControl'] = $scale_control;
    if ($has_mini_map || $zoom_indicator || $reset_control || $cluster_control || $scale_control) {
      drupal_add_js($module_path . '/js/ip_geoloc_leaflet_controls.js', array('weight' => 1));
      drupal_add_css($module_path . '/css/ip_geoloc_leaflet_controls.css');
    }
    $map['settings']['openBalloonsOnHover'] = $open_balloons_on_hover;
    $map['settings']['gotoContentOnClick'] = $goto_content_on_click;
    if ($open_balloons_on_hover || $goto_content_on_click) {
      drupal_add_js($module_path . '/js/ip_geoloc_leaflet_goto_content_on_click.js', array('scope' => 'footer'));
    }
    $settings = array(
        'mapId' => $map_id,
        'map' => $map,
        'features' => $features,
    );
    $options = array(
        'type' => 'setting',
        // 'footer' only works for type 'inline'.
        'scope' => 'footer',
    );
    drupal_add_js(array('leaflet' => array($settings)), $options);

    libraries_load('leaflet');

    // Little hacky this, but can't see another way to load libraries for
    // Leaflet More Maps, Leaflet MarkerCluster, Leaflet Hash...
    drupal_alter('leaflet_map_prebuild', $settings);

    if ($reset_control || $cluster_control || !empty($has_special_markers)) {
      // Load the CSS that comes with the font icon library which in return
      // tells the browser to fetch either the WOFF, TTF or SVG files that
      // define the font faces.
      drupal_add_library('ip_geoloc', 'ip_geoloc_font_icon_libs');
      drupal_add_css($module_path . '/css/ip_geoloc_leaflet_markers.css');
      drupal_add_js($module_path . '/js/ip_geoloc_leaflet_tagged_marker.js', array('weight' => 1));
    }
    if ($zoom_on_click) {
      drupal_add_js($module_path . '/js/ip_geoloc_leaflet_zoom_on_click.js', array('scope' => 'footer'));
    }
    // drupal_alter('leaflet_build_map', $build); // @todo [#2567391]

    $output = theme('ip_geoloc_leaflet', array(
        'map_id' => $map_id,
        'height' => trim($this->options['map_height']),
        'view' => $this->view,
    ));

    ip_geoloc_debug(t('-- Leaflet map preparation time: %sec s', array('%sec' => number_format(microtime(TRUE) - $render_start, 2))));
    return $output;
  }

  public function get_region_field_depth($region_field) {
    if (empty($region_field['type'])) {
      // Dodgy business. Return 1 and hope for the best.
      return 1;
    }
    if ($region_field['type'] === 'addressfield') {
      return 4;
    }
    if (empty($region_field['settings']['allowed_values'])) {
      return 1;
    }
    // Possibly a taxonomy or list.
    $depth = 0;
    foreach ($region_field['settings']['allowed_values'] as $tree) {
      if ($vocabulary = taxonomy_vocabulary_machine_name_load($tree['vocabulary'])) {
        if ($terms = taxonomy_get_tree($vocabulary->vid, $tree['parent'])) {
          foreach ($terms as $term) {
            $depth = max($term->depth, $depth);
          }
          break;
        }
      }
    }
    return $depth + 1;
  }

  private function _get_zoom_titles($field_type, $label, $region_depth) {
    $titles = array();
    if ($field_type === 'addressfield') {
      $titles[] = t('Zoom range for country');
      $titles[] = t('Zoom range for administrative area (state, district, county)');
      $titles[] = t('Zoom range for locality (city, town, village)');
      $titles[] = t('Zoom range for post code (ZIP)');
      return $titles;
    }
    $pos_colon = strrpos($label, ':');
    $label = drupal_substr($label, $pos_colon > 0 ? $pos_colon + 1 : 0);
    if ($field_type === 'taxonomy_term_reference') {
      for ($level = 1; $level <= $region_depth; $level++) {
        $titles[] = t('Zoom range for %field level @level', array(
            '%field' => $label,
            '@level' => $level
        ));
      }
    }
    else {
      $titles[] = t('Zoom range for %field', array('%field' => $label));
    }
    return $titles;
  }

  /**
   * Fills out the region hierarchy belonging to a location object.
   *
   * @param string $field_type
   *   'taxonomy_term_reference', 'addressfield' or other
   * @param object $location
   *   The location object whose regions attribute will be fleshed ut
   * @param string $region
   *   Region or region hierarchy taken from the View result in the form of a
   *   taxonomy term (leaf) or AddressField. Or call the function repeatedly on
   *   the same location object passing in regions as plain fields, one by one,
   *   going from the big region (country) down to the small (suburb)
   * @param int $level
   *   Level of the region in the hierarchy, updated on return
   */
  private function _fill_out_location_region($field_type, &$location, $region, &$level) {

    switch ($field_type) {

      case 'taxonomy_term_reference':
        $region_hierarchy = taxonomy_get_parents_all($region);
        // Reverse, to order region hierarchy from large region to small.
        foreach (array_reverse($region_hierarchy) as $region_term) {
          $location->regions[$level++] = trim($region_term->name);
        }
        break;

      case 'addressfield':
        //$region = reset($region);
        if (!empty($region)) {
          $format_callback = 'addressfield_format_address_generate';
          if (function_exists($format_callback) && isset($region['country'])) {
            $format = array();
            $context = array('mode' => NULL);
            // Replace state and country codes by their full names.
            addressfield_format_address_generate($format, $region, $context);
            if (isset($format['country']['#options'][$region['country']])) {
              $region['country'] = $format['country']['#options'][$region['country']];
            }
            if (isset($region['administrative_area']) && isset($format['locality_block']['administrative_area']['#options'][$region['administrative_area']])) {
              $region['administrative_area'] = $format['locality_block']['administrative_area']['#options'][$region['administrative_area']];
            }
          }
          else {
            //drupal_set_message(t('IPGV&M: cannot flesh out countries and states on locations. Format callback %name is not available.', array('%name' => $format_callback)), 'warning', FALSE);
          }
          $location->regions = array(
              1 => isset($region['country']) ? trim($region['country']) : '',
              2 => isset($region['administrative_area']) ? trim($region['administrative_area']) : '',
              3 => isset($region['locality']) ? trim($region['locality']) : '',
              4 => isset($region['postal_code']) ? trim($region['postal_code']) : '',
          );
          $level = 5;
        }
        break;

      default:
        // Note: $location->regions is meant to be ordered big to small
        $location->regions[$level++] = trim($region);
    }
  }

  protected function fill_out_location_regions($locations) {
    // When an AddressField or hierarchical vocabulary is used, this normally
    // returns a single field name (as an array).
    if (empty($this->options['cluster_differentiator']['cluster_differentiator_fields'])) {
      return;
    }
    $region_fields = array();
    foreach ($this->options['cluster_differentiator']['cluster_differentiator_fields'] as $region_fieldname) {
      $region_field = field_info_field($region_fieldname);
      $region_fields[] = empty($region_field) ? $region_fieldname : $region_field;
    }
    if (empty($region_fields) || !reset($region_fields)) {
      return;
    }
    foreach ($this->view->result as $key => $row) {
      if (isset($locations[$key])) {
        $level = 1;
        foreach ($region_fields as $region_field) {
          $region_values = ip_geoloc_get_view_result($this, $region_field, $key);
          $field_type = isset($region_field['type']) ? $region_field['type'] : 'text';
          // If the region is multi-valued, use the last value. A particular
          // case is a hierarchical region taxonomy. We want the smallest of the
          // regions in the hierarchy.
          $region = ($field_type == 'addressfield') ? $region_values : end($region_values);
          if (empty($region)) {
            // Make sure region is a string, not 0 or FALSE.
            $region = '';
          }
          $this->_fill_out_location_region($field_type, $locations[$key], $region, $level);
        }
      }
    }
  }
}

/**
 * Ajax callback in response to new rows or the diff. drop-down being changed.
 *
 * At this point the $form has already been rebuilt. All we have to do here is
 * tell AJAX what part of the browser form needs to be updated.
 */
function _ip_geoloc_plugin_style_leaflet_refresh_cluster_fieldset_js($form, &$form_state) {
  // Return the updated fieldset, so that ajax.inc can issue commands to the
  // browser to update only the targeted sections of the page.
  return $form['options']['style_options']['cluster_differentiator'];
}

/**
 * Get the center of a lat/lon pair.
 */
function _ip_geoloc_get_center($location) {
  if (empty($location->type) || $location->type == 'point') {
    $lat = isset($location->lat) ? $location->lat : (isset($location->latitude) ? $location->latitude : 0.0);
    $lon = isset($location->lon) ? $location->lon : (isset($location->longitude) ? $location->longitude : 0.0);
    return array('lat' => $lat, 'lon' => $lon);
  }
  if (!empty($location->component[0]['points'][0])) {
    return $location->component[0]['points'][0];
  }
}

/**
 * Checks if marker color is a good value.
 *
 * @param mixed $marker_color
 *   The color of the marker.
 *
 * @return bool
 *   TRUE if marker color is "0", zero, or FALSE
 *   FALSE if marker color equals '' or NULL
 */
function _ip_geoloc_is_no_marker($marker_color) {
  return isset($marker_color) && ($marker_color === '0' || $marker_color === 0 || $marker_color === FALSE);
}

/**
 * Wrapper around the only programmatic dependency we have on Leaflet module.
 *
 * Note: this indirectly calls ip_geoloc_leaflet_map_info_alter($map_info).
 */
function ip_geoloc_plugin_style_leaflet_map_get_info($map_name = NULL) {
  return module_exists('leaflet') ? leaflet_map_get_info($map_name) : array();
}

/**
 * Callback to compare locations based on weight.
 */
function _ip_geoloc_plugin_style_leaflet_compare($location1, $location2) {
  $weight1 = empty($location1->weight) ? 0 : $location1->weight;
  $weight2 = empty($location2->weight) ? 0 : $location2->weight;
  return $weight2 - $weight1;
}
