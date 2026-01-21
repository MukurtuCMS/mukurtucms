<?php

/**
 * @file
 * owlcarousel.variable.inc
 */

/**
 * Implements hook_variable_type_info().
 */
function owlcarousel_variable_type_info() {
  $type['instance_id'] = array(
    'title' => t('Instance ID'),
    'options callback' => 'owlcarousel_instance_callback_list',
    'type' => 'select',
  );

  return $type;
}
 
/**
 * Implements hook_variable_group_info().
 */
function owlcarousel_variable_group_info() {
  $groups['owlcarousel'] = array(
    'title' => t('Owl Carousel'),
    'description' => t('Define instance settings for each owl carousel.'),
    'access' => 'administer owlcarousel settings',
    'path' => array('admin/config/user-interface/owlcarousel'),
  );

  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function owlcarousel_variable_info($options) {
  $variable['owlcarousel_items_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Items', array(), $options),
    'description' => t('The number of items you want to see on the screen.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 3,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_margin_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Margin', array(), $options),
    'description' => t('Margin-right(px) on item.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 0,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_loop_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Loop', array(), $options),
    'description' => t('Inifnity loop. Duplicate last and first items to get loop illusion.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_center_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Center', array(), $options),
    'description' => t('Center item. Works well with even an odd number of items.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_mouse_drag_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Mouse Drag', array(), $options),
    'description' => t('Mouse drag enabled.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => TRUE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_touch_drag_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Touch Drag', array(), $options),
    'description' => t('Touch drag enabled.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => TRUE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_pull_drag_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Pull Drag', array(), $options),
    'description' => t('Stage pull to edge.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => TRUE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_free_drag_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Free Drag', array(), $options),
    'description' => t('Item pull to edge.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_stage_padding_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Stage Padding', array(), $options),
    'description' => t('Padding left and right on stage (can see neighbours).', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 0,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_merge_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Merge', array(), $options),
    'description' => t('Merge items. Looking for data-merge={number} inside item.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_merge_fit_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Merge Fit', array(), $options),
    'description' => t('Fit merged items if screen is smaller than items value.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => TRUE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_auto_width_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Auto Width', array(), $options),
    'description' => t('Set non grid content. Try using width style on divs.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_start_position_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Start Position', array(), $options),
    'description' => t('Start position or URL Hash string like #id.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 0,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_url_hash_listener_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('URL Hash Listener', array(), $options),
    'description' => t('Listen to url hash changes. data-hash on items is required.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_nav_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Navigation', array(), $options),
    'description' => t('Show next/prev buttons.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_nav_rewind_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Nav Rewind', array(), $options),
    'description' => t('Go to first/last.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => TRUE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_nav_text_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Navigation Text', array(), $options),
    'description' => t('Cusomize your own text for navigation.', array(), $options),
    'repeat' => array(
      'type' => 'array',
      'default' => array('prev', 'next'),
    ),
    'localize' => TRUE,
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_slide_by_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Slide By', array(), $options),
    'description' => t('Navigation slide by x. page string can be set to slide by page.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 1,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_dots_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Dots', array(), $options),
    'description' => t('Show dots navigation.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => TRUE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_dots_each_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Dots Each', array(), $options),
    'description' => t('Show dots each x item.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 0,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_dot_data_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Dot Data', array(), $options),
    'description' => t('Used by data-dot content.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_lazy_load_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Lazy Load', array(), $options),
    'description' => t('Lazy load images. data-src and data-src-retina for highres. Also load images into background inline style if element is not <img>.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_lazy_content_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Lazy Content', array(), $options),
    'description' => t('lazyContent was introduced during beta tests but i removed it from the final release due to bad implementation. It is a nice options so i will work on it in the nearest feature.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_autoplay_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Autoplay', array(), $options),
    'description' => t('Autoplay carousel.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_autoplay_timeout_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Autoplay Timeout', array(), $options),
    'description' => t('Autoplay interval timeout.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 5000,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_autoplay_hover_pause_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Autoplay Hover Pause', array(), $options),
    'description' => t('Pause on mouse hover.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_smart_speed_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Smart Speed', array(), $options),
    'description' => t('Speed Calculate. More info to come.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 250,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_fluid_speed_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Fluid Speed', array(), $options),
    'description' => t('Speed Calculate. More info to come.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 250,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_autoplay_speed_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Autoplay Speed', array(), $options),
    'description' => t('Autoplay speed.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 0,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_nav_speed_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Navigation Speed', array(), $options),
    'description' => t('Navigation speed.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 0,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_dots_speed_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Dots Speed', array(), $options),
    'description' => t('Pagination speed.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 0,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_drag_end_speed_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Drag End Speed', array(), $options),
    'description' => t('Drag end speed.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 0,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_callbacks_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Callbacks', array(), $options),
    'description' => t('Enable callback events.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_responsive_refresh_rate_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Responsive Refresh Rate', array(), $options),
    'description' => t('Responsive refresh rate.', array(), $options),
    'repeat' => array(
      'type' => 'number',
      'default' => 200,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_responsive_base_element_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Responsive Base Element', array(), $options),
    'description' => t('Set on any DOM element. If you care about non responsive browser (like ie8) then use it on main wrapper. This will prevent from crazy resizing.', array(), $options),
    'repeat' => array(
      'type' => 'string',
      'default' => 'window',
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_responsive_class_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Responsive Class', array(), $options),
    'description' => t("Optional helper class. Add 'owl-reponsive-' + 'breakpoint' class to main element. Can be used to stylize content on given breakpoint.", array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_video_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Video', array(), $options),
    'description' => t('Enable fetching YouTube/Vimeo videos.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_video_height_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Video Height', array(), $options),
    'description' => t('Set height for videos.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_video_width_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Video Width', array(), $options),
    'description' => t('Set width for videos.', array(), $options),
    'repeat' => array(
      'type' => 'boolean',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_animate_out_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Animate Out', array(), $options),
    'description' => t('CSS3 animation out.', array(), $options),
    'repeat' => array(
      'type' => 'string',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_animate_in_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Animate In', array(), $options),
    'description' => t('CSS3 animation in.', array(), $options),
    'repeat' => array(
      'type' => 'string',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_fallback_easing_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Fallback Easing', array(), $options),
    'description' => t('Easing for CSS2 $.animate.', array(), $options),
    'repeat' => array(
      'type' => 'string',
      'default' => 'swing',
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_info_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Info', array(), $options),
    'description' => t('Callback to retrieve basic information (current item/pages/widths). Info function second parameter is Owl DOM object reference.', array(), $options),
    'repeat' => array(
      'type' => 'string',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_nested_item_selector_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Nested Item Selector', array(), $options),
    'description' => t("Use it if owl items are deep nasted inside some generated content. E.g 'youritem'. Dont use dot before class name.", array(), $options),
    'repeat' => array(
      'type' => 'string',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_item_element_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Item Element', array(), $options),
    'description' => t('DOM element type for owl-item.', array(), $options),
    'repeat' => array(
      'type' => 'string',
      'default' => 'div',
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_stage_element_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Stage Element', array(), $options),
    'description' => t('DOM element type for owl-stage.', array(), $options),
    'repeat' => array(
      'type' => 'string',
      'default' => 'div',
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_nav_container_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Navigation Container', array(), $options),
    'description' => t('Set your own container for nav.', array(), $options),
    'repeat' => array(
      'type' => 'string',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );
  $variable['owlcarousel_dots_container_[instance_id]'] = array(
    'type' => 'multiple',
    'title' => t('Pagination Container', array(), $options),
    'description' => t('Set your own container for pagination.', array(), $options),
    'repeat' => array(
      'type' => 'string',
      'default' => FALSE,
    ),
    'group' => 'owlcarousel',
  );

  return $variable;
}
