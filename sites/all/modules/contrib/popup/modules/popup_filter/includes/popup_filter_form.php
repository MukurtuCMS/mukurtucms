
<div  class="popup-filter-form-wrapper">

  <div  class="popup-attributes">

    <div class="form-item form-item-first">
      <label for="popup-title"><?php print $text['title']; ?>:</label>
      <input id="popup-title" class="form-text" />
    </div>

    <div class="form-item form-item-first">
      <label for="popup-image"><?php print $text['image']; ?>:</label>
      <input id="popup-image" class="form-text" />
      <div class="description"><?php print $text['image description']; ?></div>
    </div>

    <div class="form-item">
      <label for="popup-link"><?php print $text['link']; ?>:</label>
      <input id="popup-link" class="form-text" />
    </div>

    <div class="form-item inline left-column">
      <label for="popup-id"><?php print $text['css id']; ?>:</label>
      <input id="popup-id" class="form-text" />
    </div>

    <div class="form-item inline right-column">
      <label for="popup-class"><?php print $text['css class']; ?>:</label>
      <input id="popup-class" class="form-text" />
    </div>

    <div class="form-item inline section">
      <label for="popup-format"><?php print $text['format']; ?>:</label>
      <select id="popup-format" class="form-select"><?php print $format_options; ?></select>
      <div class="description"><?php print $text['format description']; ?></div>
    </div>

    <div class="form-item inline left-column">
      <label for="popup-origin"><?php print $text['origin']; ?>:</label>
      <select id="popup-origin" class="form-select"><?php print $position_options; ?></select>
    </div>

    <div class="form-item inline right-column">
      <label for="popup-expand"><?php print $text['expand']; ?>:</label>
      <select id="popup-expand" class="form-select"><?php print $position_options; ?></select>
    </div>

    <div class="form-item inline left-column">
      <label for="popup-effect"><?php print $text['effect']; ?>:</label>
      <select id="popup-effect" class="form-select"><?php print $effect_options; ?></select>
    </div>

    <div class="form-item inline right-column">
      <label for="popup-width"><?php print $text['width']; ?>:</label>
      <select id="popup-width" class="form-select"><?php print $width_options; ?></select>
    </div>

    <div class="form-item inline left-column">
      <label for="popup-activate"><?php print $text['activate']; ?>:</label>
      <select id="popup-activate" class="form-select"><?php print $activate_options; ?></select>
    </div>

    <div class="form-item inline right-column">
      <label for="popup-close">
        <input id="popup-close" type="checkbox" /><?php print $text['close button']; ?>
      </label>
    </div>

  </div>

  <div class="popup-content">

    
    <div class="form-item form-item-first inline">
      <label for="popup-type"><?php print $text['type']; ?>:</label>
      <select id="popup-type" class="form-select"><?php print $type_options; ?></select>
    </div>

    
    <div class="popup-content-block popup-content-section">

      <div class="form-item inline">
        <label for="popup-content-block-module"><?php print $text['module']; ?>:</label>
        <select id="popup-content-block-module" class="form-select"><?php print $module_options; ?></select>
      </div>

      <div class="form-item inline">
        <label for="popup-content-block-delta"><?php print $text['delta']; ?>:</label>
        <select id="popup-content-block-delta" class="form-select"></select>
      </div>

    </div>


    <div class="popup-content-form popup-content-section">

      <div class="form-item">
        <label for="popup-content-form-id"><?php print $text['form']; ?>:</label>
        <input id="popup-content-form-id" class="form-text" />
        <div class="description"><?php print $text['form description']; ?></div>
      </div>
      
    </div>


    <div class="popup-content-menu popup-content-section">

      <div class="form-item inline">
        <label for="popup-content-menu"><?php print $text['menu']; ?>:</label>
        <select id="popup-content-menu" class="form-select"><?php print $menu_options; ?></select>
      </div>

      <div class="form-item inline left-column">
        <label for="popup-content-menu-flat">
          <input id="popup-content-menu-flat" type="checkbox" /><?php print $text['flat']; ?>
        </label>
        <div class="description"><?php print $text['flat description']; ?></div>
      </div>

      <div class="form-item inline right-column">
        <label for="popup-content-menu-inline">
          <input id="popup-content-menu-inline" type="checkbox" /><?php print $text['inline']; ?>
        </label>
        <div class="description"><?php print $text['inline description']; ?></div>
      </div>

    </div>


    <div class="popup-content-node popup-content-section">

      <div class="form-item">
        <label for="popup-content-node-id"><?php print $text['node id']; ?>:</label>
        <input id="popup-content-node-id" class="form-text" />
      </div>

      <div><?php print $text['or']; ?></div>

      <?php print $node_title; ?>

      <div class="form-item inline">
        <label>Display:</label>
        <div class="form-radios">
          <label class="option" for="popup-content-node-default">
            <input id="popup-content-node-default" type="radio" checked name="node-display" /><?php print $text['default']; ?>
          </label>
          <label class="option" for="popup-content-node-teaser">
            <input id="popup-content-node-teaser" type="radio" name="node-display" /><?php print $text['teaser']; ?>
          </label>
          <label class="option" for="popup-content-node-page">
            <input id="popup-content-node-page" type="radio" name="node-display" /><?php print $text['page']; ?>
          </label>
          <?php if (module_exists('ctools')){ ?>
          <label class="option" for="popup-content-node-panel">
            <input id="popup-content-node-panel" type="radio" name="node-display" /><?php print $text['panel']; ?>
          </label>
          <?php } ?>
        </div>
        <label for="popup-content-node-links">
          <input id="popup-content-node-links" type="checkbox" /><?php print $text['links']; ?>
        </label>
      </div>

    </div>


    <div class="popup-content-php popup-content-section">

      <div class="form-item">
        <label for="popup-content-php"><?php print $text['php']; ?>:</label>
        <textarea id="popup-content-php"></textarea>
        <div class="description"><?php print $text['php description']; ?></div>
      </div>

    </div>

    <div class="popup-content-text popup-content-section">

      <div class="form-item">
        <label for="popup-content-text"><?php print $text['text']; ?>:</label>
        <textarea id="popup-content-text"></textarea>
      </div>

    </div>

    <div class="popup-content-view popup-content-section">

      <?php if($view_options) { ?>

      <div class="form-item inline">
        <label for="popup-content-view"><?php print $text['view']; ?>:</label>
        <select id="popup-content-view" class="form-select"><?php print $view_options; ?></select>
      </div>

      <div class="form-item inline">
        <label for="popup-content-view-display"><?php print $text['display']; ?>:</label>
        <select id="popup-content-view-display" class="form-select"></select>
      </div>

      <div class="form-item">
        <label for="popup-content-view-arguments"><?php print $text['arguments']; ?>:</label>
        <input id="popup-content-view-arguments" class="form-text" />
        <div class="description"><?php print $text['argument description']; ?></div>
      </div>

      <?php } else { ?>
        <?php print $text['views disabled']; ?>
      <?php } ?>

    </div>

    <div class="popup-insert">

      <div class="form-item inline">
        <label for="popup-ajax">
          <input id="popup-ajax" type="checkbox" /><?php print $text['ajax']; ?>
        </label>
      </div>

      <div class="form-item">
        <p class="description"><?php print $text['filter reminder']; ?></p>
        <input type="button" class="form-submit" id="insert-popup-tag" value="<?php print $text['insert']; ?>" />
      </div>
    </div>

  </div>

</div>