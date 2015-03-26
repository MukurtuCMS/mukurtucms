<?php 
  drupal_set_title($site_name);
?>
<div class="container-fluid main-content">

<div class="header<?php if(!$frontpage['page_items']['header']) { echo ' navbar-fixed-top'; } ?>">
  <div class="header-block">
   <?php
    if($frontpage['page_items']['header']) {
      $block = block_load('boxes', 'ma_site_header');
      echo drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
    }
   ?>
  </div>

  <?php //if(($frontpage['page_items']['header'])) { ?>
  <div class="navbar row-fluid">
  <div class="logo-container span2">
    <?php echo '<a href="#' . $frontpage['page_items']['sections'][0]['anchor'] . '"><img class="logo" src="' . $logo . '" /></a>'; ?>
  </div>
  <?php //} ?>
  <div id="navigation" class="navigation span10 navigation-wide hidden-phone">
    <ul class="item-list">
    <?php foreach($frontpage['page_items']['sections'] as $item) {
      if($item['title'] != '') {
        echo '<li><a class="tab" href="#' . $item['anchor'] . '"><span class="link">' . $item['title'] . '</span>'
          . '<span class="detail">' . $item['detail'] .'</span></a></li>';
      }
    }
    ?>
    </ul>
  </div>


  <div id="navigation-small" class="navigation-small span10 visible-phone">
    <ul class="item-list">
    <?php foreach($frontpage['page_items']['sections'] as $item) {
      if($item['title'] != '') {
        echo '<li><a href="#' . $item['anchor'] . '"><span class="link">' . $item['title'] . '</span>'
          . '</a></li>';
      }
    }
    ?>
    </ul>
  </div>


  </div>
</div>
<?php
$count = 0;
$output = '';
foreach($frontpage['page_items']['sections'] as $item) {
  if($item['display'] == TRUE) {
    $output .= t('<div class="frontpage-content frontpage-' . $count . ' row" id="' . $item['anchor'] . '">');
  
    $output .= t('<h2>' . $item['title'] . '</h2>' );
  
/*
    if($count == count($frontpage['page_items']['sections']) - 1 ) {
      $output .= '<footer>';  
    }
*/
    
    $output .= $item['content'];
    
    if(!empty($item['jsondata']) || $item['jsondata'] !== '') { 
    $output .=  '<div id="' . $item['anchor'] . '-list">
        <script type="text/template" id="' . $item['anchor'] . 'Template">
          <ul class="list jcarousel jcarousel-skin-default">
            <% _.each(mukurtu_frontpage.localData["' . $item['anchor'] .'"], function (item) { %> 
              <li class="item">
              <% if (item.image !== null) { %>
                <a href="<%= item.path %>"><%= item.image %></a>
              <% } %>
              <span class="content">
              <% if (item.title !== null) { %>
               <h4><%= item.title %></h4>
              <% } %>
              <% if (item.description !== null) { %>              
                <%= item.description %>
              <% } %>
              </span>
              </li>
            <% }); %>
          </ul>
      </script>
  
      </div>';
    }

    if($item['blockname']) {
      $block = block_load('boxes', $item['blockname']);
      $output .= drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
    }
    
/*
    if($count == count($frontpage['page_items']['sections']) - 1 ) {
      $output .= '</footer>';  
    }
*/

    $output .= $item['content_suffix'];

    $output .= '</div>';
    
  }
  $count++;

} 
  echo $output;
?>
<div class="footer-block">   
 <?php
  if($frontpage['page_items']['footer']) {
    $block = block_load('boxes', 'ma_site_footer');
    echo drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
  }
 ?>
</div>  
</div>
