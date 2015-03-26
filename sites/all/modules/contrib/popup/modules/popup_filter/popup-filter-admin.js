(function ($) {

Drupal.behaviors.popupFilter = {

  attach:

    function(context){

      if ($('.class-popup-filter-admin-form', context).length == 0){
        return;
      }

      // Show/Hide appropriate sections based on type

      $('#popup-type')
        .change(updateSections)
        .keyup(updateSections)
        .click(updateSections);

      function updateSections(){
        $('.popup-content-' + $('#popup-type').val())
          .fadeIn()
          .siblings('.popup-content-section')
            .fadeOut();
      }

      $('.class-popup-filter-admin-form').bind(
        'shown',
        function(){
          updateSections();
        }
      );


      // En/Disable the close button checkbox

      $('#popup-activate')
        .change(toggleClose)
        .keyup(toggleClose)
        .click(toggleClose);

      function toggleClose(){
        if ($('#popup-activate').val() == 'click'){
          $('#popup-close').removeAttr('disabled');
        } else {
          $('#popup-close').attr('disabled', 'disabled');
        }
      }
      toggleClose();

      // En/Disable the ajax checkbox

      $('#popup-type')
        .change(toggleAjax)
        .keyup(toggleAjax)
        .click(toggleAjax);

      function toggleAjax(){
        if ($('#popup-type').val() in {'block':0, 'node':0, 'form':0, 'view':0}){
          $('#popup-ajax').removeAttr('disabled');
        } else {
          $('#popup-ajax').attr('disabled', 'disabled');
        }
      }
      toggleAjax();

      // En/Disable the menu > inline checkbox

      $('#popup-content-menu-flat')
        .change(toggleInline)
        .keyup(toggleInline)
        .click(toggleInline);

      function toggleInline(){
        if ($('#popup-content-menu-flat').attr('checked')){
          $('#popup-content-menu-inline').removeAttr('disabled');
        } else {
          $('#popup-content-menu-inline').attr('disabled', 'disabled');
        }
      }
      toggleInline();

      // Node title autocomplete

      $('#popup-content-node-title')
        .change(setNodeId)
        .keyup(setNodeId);

      function setNodeId(){
        var matches = $('#popup-content-node-title').val().match(/\[([0-9]+)\]/);
        if (matches){
          $('#popup-content-node-id').val(matches[1]);
        }
      }


      // Block delta selection box

      $('#popup-content-block-module')
        .change(loadBlockDelta)
        .keyup(loadBlockDelta)
        .click(loadBlockDelta);

      function loadBlockDelta(){
        $.get(
          '/ajax/popup-filter/getdeltas/' + $('#popup-content-block-module').val(),
          null,
          function(data) {
            $('#popup-content-block-delta').html(data);
          }
        );
      }
      loadBlockDelta();


      // View display selection box

      $('#popup-content-view')
        .change(loadViewDisplay)
        .keyup(loadViewDisplay)
        .click(loadViewDisplay);

      function loadViewDisplay(){
        $.get(
          '/ajax/popup-filter/getdisplays/' + $('#popup-content-view').val(),
          null,
          function(data) {
            $('#popup-content-view-display').html(data);
          }
        );
      }
      loadViewDisplay();


      // Insert popup tag

      $('#insert-popup-tag')
        .click(insert);

      function insert(){

        var type = $('#popup-type').val();
        if (errors(type)){
          return;
        }

        setNodeId();
        $('#edit-body').focus();
        $('.class-popup-filter-admin-form').trigger('hide');

        var title = $('#popup-title').val();
        var id = $('#popup-id').val();
        var popupClass = $('#popup-class').val();
        var link = $('#popup-link').val();
        var image = $('#popup-image').val();
        var effect = $('#popup-effect').val();
        var origin = $('#popup-origin').val();
        var expand = $('#popup-expand').val();
        var activate = $('#popup-activate').val();
        var width = $('#popup-width').val();
        var format = $('#popup-format').val();
        var close = $('#popup-close').attr('checked') && !$('#popup-close').attr('disabled');
        var ajax = $('#popup-ajax').attr('checked') && !$('#popup-ajax').attr('disabled');
        var inline= $('#popup-content-menu-inline').attr('checked') && !$('#popup-content-menu-inline').attr('disabled');

        var rendered =
          '[popup ' +
            (title != '' ? 'title="' + title + '" ' : '') +
            (id != '' ? 'id="' + id + '" ' : '') +
            (popupClass != '' ? 'class="' + popupClass + '" ' : '') +
            (link != '' ? 'link="' + link + '" ' : '') +
            (origin != '0' ? 'origin=' + origin + ' ' : '') +
            (expand != '0' ? 'expand=' + expand + ' ' : '') +
            (image.length ? 'image="' + image + '" ' : '') +
            (activate != '0' ? 'activate=' + activate + ' ' : '') +
            (effect != '0' ? 'effect=' + effect + ' ' : '') +
            (format != '0' ? 'format="' + format + '" ' : '') +
            (width != '0' ? 'width=' + width + ' ' : '') +
            (close ? 'close ' : '') +
            (ajax ? 'ajax ' : '') +
            type;

        switch(type){

          case 'text':
            var text = $('#popup-content-text').val();
            if (text.match(/\s/)){
              if (text.match(/'/)){
                rendered += '="' + text + '"';
              } else {
                rendered += "='" + text + "'";
              }
            } else {
              rendered += '=' + text;
            }
          break;

          case 'node':
            rendered += '=' + $('#popup-content-node-id').val();
            var teaser = $('#popup-content-node-teaser').attr('checked');
            rendered += teaser ? ' teaser-display' : '';
            var page = $('#popup-content-node-page').attr('checked');
            rendered += page ? ' page-display' : '';
            var links = $('#popup-content-node-links').attr('checked');
            rendered += links ? ' links' : '';
            var panel = $('#popup-content-node-panel').attr('checked');
            rendered += panel ? ' panel-display' : '';
          break;

          case 'block':
            var delta = $('#popup-content-block-delta').val();
            rendered +=
              ' module=' + $('#popup-content-block-module').val() +
              (delta != null ? ' delta=' + delta : '');
          break;

          case 'form':
            rendered += '=' + $('#popup-content-form-id').val();
          break;

          case 'menu':
            rendered += '=' + $('#popup-content-menu').val();
            var flat = $('#popup-content-menu-flat').attr('checked');
            rendered += flat ? ' flat' : '';
            rendered += inline ? ' inline' : '';
          break;

          case 'view':
            rendered += '=' + $('#popup-content-view').val();
            rendered += ' display=' + $('#popup-content-view-display').val();
            var args = $('#popup-content-view-arguments').val();
            if (args != ''){
              if (args.match(/\s/)){
                if (args.match(/'/)){
                  rendered += ' args="' + args + '"';
                } else {
                  rendered += " args='" + args + "'";
                }
              } else {
                rendered += ' args=' + args;
              }
            }
          break;

          case 'php':
            var php = $('#popup-content-php').val();
            if (php.match(/\s/)){
              if (php.match(/'/)){
                rendered += '="' + php + '"';
              } else {
                rendered += "='" + php + "'";
              }
            } else {
              rendered += '=' + php;
            }
          break;

        }

        rendered += ']';
        var textField = $('#edit-body-value, #edit-body-und-0-value');

        textField.insertAtCaret(rendered);

      }


      // Input errors
      function errors(type){

        var error = false;

        switch(type){

          case 'block':
            var element = $('#popup-content-block-delta');
            if (element.val() == null){
              flashElement(element);
              error = true;
            }
          break;

          case 'form':
            var element = $('#popup-content-form-id');
            if (element.val() == ''){
              flashElement(element);
              error = true;
            }
          break;

          case 'node':
            var element = $('#popup-content-node-id');
            if (isNaN(element.val()) || element.val() == ''){
              flashElement(element);
              flashElement($('#popup-content-node-title'));
              error = true;
            }
          break;

          case 'php':
            var element = $('#popup-content-php');
            if (element.val() == ''){
              flashElement(element);
              error = true;
            }
          break;

          case 'text':
            var element = $('#popup-content-text');
            if (element.val() == ''){
              flashElement(element);
              error = true;
            }
          break;

        }

        return error;
      }

      function flashElement(element){
        element.addClass('error');
        setTimeout(function(){element.removeClass('error')}, 500);
        element.focus();
      }
    }
  }

  // By Alex King, adapted to jquery by Alex Brem http://www.mail-archive.com/jquery-en@googlegroups.com/msg08708.html
  $.fn.insertAtCaret = function (myValue) {

    return this.each(function(){
      //IE support
      if (document.selection) {
        this.focus();
        sel = document.selection.createRange();
        sel.text = myValue;
        this.focus();
      }
      //MOZILLA/NETSCAPE support
      else if (this.selectionStart || this.selectionStart == '0') {
        var startPos = this.selectionStart;
        var endPos = this.selectionEnd;
        var scrollTop = this.scrollTop;
        this.value = this.value.substring(0, startPos) + myValue + this.value.substring(endPos, this.value.length);
        this.focus();
        this.selectionStart = startPos + myValue.length;
        this.selectionEnd = startPos + myValue.length;
        this.scrollTop = scrollTop;
      } else {
        this.value += myValue;
        this.focus();
      }
    });

  };

})(jQuery);


