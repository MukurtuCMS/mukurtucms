(function ($) {

Drupal.behaviors.popup = {

  attach: function(context){

    // Make sure we have an overlay space
    if(!$('#popup-active-overlay').length){
      $('body').append('<div id="popup-active-overlay"></div>');
    }

    // Process flat menu containers
    $('.popup-menu-flat:not(.popup-menu-flat-processed)').each(
      function(){
        var thisObject = $(this);
        thisObject.addClass('popup-menu-flat-processed');
        new PopupMenuContainerElement(thisObject);
      }
    );

    // Process popup-elements
    $('.popup-element:not(.popup-element-processed)').each(
      function(){
        var thisObject = $(this);
        thisObject
          .addClass('popup-element-processed')
          .removeClass('popup-element-noscript');
        new PopupElement(thisObject);
      }
    );

    // Process menu leaves
    $('.popup-menu-leaf-title:not(.popup-menu-leaf-processed)').each(
      function(){
        var thisObject = $(this);
        thisObject.addClass('popup-menu-leaf-processed');
        new PopupMenuLeafElement(thisObject);
      }
    );

    // Process relative links in AJAX loaded content
    $("a[href^='/ahah/popup/view']", context).each(
      function(){

        var thisObject = $(this);
        var thisContext = $(thisObject.parents('div.inner').get(0));

        var placeContent = function(data){
          thisContext.html(data);
          Drupal.attachBehaviors(context);
        }

        var fetchContent = function(){
          $.get(thisObject.attr('href'), null, placeContent);
          return false;
        }

        thisObject.click(fetchContent);
      }
    );

    // Correct relative form submits
    $(".ajax form").each(
      function(){
        var thisForm = $(this);

        if (thisForm.attr('action').match(/^\/ahah\/popup/)){
          thisForm.attr('action', '');
        }
      }
    );

    // Reposition on window resize
    var reposition = function(){
      $('.popup-element').trigger('reposition');
    }
    $(window).unbind('resize', reposition).resize(reposition);

  }

}



/* ---- Popup element objects ---- */



PopupElement = function(element){

  var thisObject = this;

  // Gather elements
  this.element = element;
  this.title = $($('.popup-element-title', this.element)[0]);
  this.body = $($('.popup-element-body', this.element)[0]);
  this.elementId = this.element.attr('id');
  this.closeButton = $('.popup-close', this.body);

  this.children = new Array();

  this.isRoot = this
    .title
    .parents('.popup-element-body,.popup-menu-flat')
    .length == 0;

  this.body.data('popupElement', this);

  // Assign show/hide effects
  PopupElement.assignEffects.apply(this);

  // Assign origin positioning function
  PopupElement.assignPositioning.apply(this);

  // Move body and add a wrapper
  PopupElement.dom.apply(this);

  // Assign expansion function
  PopupElement.assignExpansion.apply(this);

  // Assign activation/deactivation events
  PopupElement.assignEvents.apply(this);

  // Apply css attributes
  PopupElement.applyAttributes.apply(this);

  // Attach AJAX behaviors
  PopupElement.applyAJAX.apply(this);

  // Reposition on window resize
  this.element.bind(
    'reposition',
    function(){
      thisObject.position();
    }
  );

  // Close button
  this.closeButton.click(
    function(){
      PopupElement.hide.apply(thisObject);
      return false;
    }
  );

}



PopupMenuLeafElement = function(element){

  this.element = element;
  this.parent = this.element.parents('.popup-element-body,.popup-menu-flat').data('popupElement');
  var thisObject = this;

  this.element.mouseover(
    function(){
      if (thisObject.parent){
        for(var i in thisObject.parent.children){
          PopupElement.hide.apply(thisObject.parent.children[i]);
        }
      }
    }
  );
}



PopupMenuContainerElement = function(element){

  this.element = element;
  this.body = element;
  this.children = new Array();
  this.element.data('popupElement', this);

}



PopupElement.count = 0;



/* ---- DOM preparation ---- */



PopupElement.dom = function(){

  this.body.appendTo('#popup-active-overlay');

  var classAttr = this.element.attr('class');
  var styleClass = classAttr.match(/popup-style-[^'\s]+/);

  this.body.wrap(
      '<div id="' +
        this.elementId +
      '-active" class="popup-element-wrapper' + (styleClass ? ' ' + styleClass : '') + '">'
    );

  this.wrapper = this.body.parent();
  this.wrapper.css('position', 'absolute');

  // Wrap in origin element
  this.body.wrap('<div class="popup-element-origin">');
  this.origin = this.body.parent();
  this.origin.css('position', 'absolute');
}



/* ---- Dynamic functions ---- */



PopupElement.assignEffects = function(){
  var effectName = this
    .element
    .attr('class')
    .match(/effect-([^\s]+)/)[1];
  this.animShow = new Function(
    Drupal.settings.popup.effects.show[effectName]
  );
  this.animHide = new Function(
    Drupal.settings.popup.effects.hide[effectName]
  );
}



PopupElement.assignPositioning = function(){
  var originName = this
    .element
    .attr('class')
    .match(/origin-([^\s]+)/)[1];
  this.position = PopupElement.position[originName];
}



PopupElement.assignExpansion = function(){
  var expandName = this
    .element
    .attr('class')
    .match(/expand-([^\s]+)/)[1];
  PopupElement.expand[expandName].apply(this);
}



PopupElement.assignEvents = function(){
  if (this.element.hasClass('activate-hover')){
    PopupElement.hoverEvents.apply(this);
  } else {
    PopupElement.clickEvents.apply(this);
  }

  var thisObject = this;

  // API show/hide events
  this.element.bind(
    'hide',
    function(){
      PopupElement.hide.apply(thisObject);
    }
  ).bind(
    'show',
    function(){
      PopupElement.show.apply(thisObject);
    }
  );

}



PopupElement.applyAttributes = function(){

  if (this.body.attr('class')){

    var opacity = this.body.attr('class').match(/opacity-([^\s]+)/);
    if (opacity && opacity[1] < 1){
      this.body.css(
        {
          opacity: opacity[1],
          filter: 'alpha(opacity=' + opacity[1] + ')'
        }
      );
    }

    var width = this.body.attr('class').match(/width-([^\s]+)/);
    if (width){
      $('.inner', this.body).css('width', width[1] + 'px');
    }
  }
}



/* ---- AJAX preparation ---- */



PopupElement.applyAJAX = function(){

  var thisObject = this;

  var placeContent = function(data, destination){

    thisObject.body.unbind('showing', fetchContent);
    var close = $('.popup-close-button', destination);

    if (close.length){
      close.siblings().remove();
      destination.append(data);
    } else {
      destination.html(data);
    }

    Drupal.attachBehaviors(destination);
  }

  var fetchContent = function(){

    var placeHolder = thisObject.body.find('.popup-ahah-placeholder');
    var destination = placeHolder.parent();
    var url = $('a.ahah-path', placeHolder).attr('href');

    $.get(url, null, function(data){ placeContent(data, destination); });
  }

  // Ajax
  if (this.body.hasClass('ajax')){
    this.body.bind('showing', fetchContent);
  }

}



/* ---- Popup actions ---- */



PopupElement.hide = function(){
  if (this.visible){
    this.body.trigger('hiding');
    this.animHide();
    this.title.removeClass('popup-title-active');
    this.element.removeClass('popup-element-active');
    this.visible = false;
    this.body.queue('function(){ PopupElement.count--; }');
    this.body.trigger('hidden');
  }
}



PopupElement.show = function(){
  if (!this.visible){
    this.body.css('z-index', ++PopupElement.count);
    this.body.trigger('showing');
    this.position();
    this.animShow();
    this.title.addClass('popup-title-active');
    this.element.addClass('popup-element-active');
    this.visible = true;
    this.body.trigger('shown');
  }
}



/* ---- Popup events ---- */



PopupElement.clickEvents = function(){

  this.visible = false;
  var thisObject = this;

  this.title.click(
    function(){
      if (thisObject.visible == true){
        PopupElement.hide.apply(thisObject);
      } else {
        PopupElement.show.apply(thisObject);
      }
      return false;
    }
  );
}



PopupElement.hoverEvents = function(){

  var thisObject = this;

  if (!this.isRoot){
    var popupElement = this.title.parents('.popup-element-body').data('popupElement');
    this.parent = popupElement
      ? popupElement
      : this.title.parents('.popup-menu-flat').data('popupElement');
    this.parent.children.push(this);
  }

  // Trigger hiding
  var delayedHide = function(){
    clearTimeout(thisObject.hideTimeout);
    if (thisObject.showTimeout) {
      clearTimeout(thisObject.showTimeout);
    }
    thisObject.hideTimeout = setTimeout(
      function(){
        PopupElement.hide.apply(thisObject);
      },
      Drupal.settings.popup.linger
    );
    if (!thisObject.isRoot){
      thisObject.parent.body.trigger('mouseleave');
    }
  }
  this.body.bind('mouseleave', delayedHide);
  this.title.bind('mouseleave', delayedHide);

  // Cancel hiding
  var cancelHide = function(){
    var element = thisObject;
    clearTimeout(thisObject.hideTimeout);
    while(element = element.parent){
      clearTimeout(element.hideTimeout);
    }
  }
  this.body.bind('mouseover', cancelHide);
  this.title.bind('mouseover', cancelHide);

  // Trigger showing
  var handler = function(event){
    thisObject.showTimeout = setTimeout(
			function(){
				if (!thisObject.visible){
					PopupElement.show.apply(thisObject);
					if (thisObject.parent){
						for(var i in thisObject.parent.children){
							if (thisObject.parent.children[i] != thisObject){
								PopupElement.hide.apply(thisObject.parent.children[i]);
							}
						}
					}
				}
      }, Drupal.settings.popup.delay
    );
	}

  this.title.bind('mouseenter', handler);
}



/* ---- Popup positioning ---- */



PopupElement.position = {

  'top-left': function(){
    var origin = this.title.offset();
    this.origin.css(
      {
        top: origin.top,
        left: origin.left
      }
    );
  },

  'top-right': function(){
    var origin = this.title.offset();
    this.origin.css(
      {
        top: origin.top,
        left: origin.left + this.title.outerWidth()
      }
    );
  },

  'bottom-left': function(){
    var origin = this.title.offset();
    this.origin.css(
      {
        top: origin.top + this.title.outerHeight(),
        left: origin.left
      }
    );
  },

  'bottom-right': function(){
    var origin = this.title.offset();
    this.origin.css(
      {
        top: origin.top + this.title.outerHeight(),
        left: origin.left + this.title.outerWidth()
      }
    );
  }

}



PopupElement.expand = {

  'top-left': function(){
    this.body.css({bottom: 0, right: 0});
  },

  'top-right': function(){
    this.body.css({bottom: 0, left: 0});
  },

  'bottom-left': function(){
    this.body.css({top: 0, right: 0});
  },

  'bottom-right': function(){
    this.body.css({top: 0, left: 0});
  }

}


})(jQuery);