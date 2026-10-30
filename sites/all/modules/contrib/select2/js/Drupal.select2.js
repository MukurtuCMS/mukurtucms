/**
 * Provides Select2 plugin for elements.
 */
(function ($, window, document) {

  String.prototype.extTrim = function (char) {

    var trimRegex = new RegExp('^' + char + '+|' + char + '+$', "g");

    if (trimRegex.test(this)) {
      return this.replace(trimRegex, '');
    }

    return this.toString();
  };
  
  String.prototype.quote_trim = function () {
    var trimRegex = new RegExp('^"(.*)?"$', "g"),
        resultString = this;
    
    while (trimRegex.test(resultString)) {
      resultString = this.replace(trimRegex, '$1');
    }

    return resultString.toString();
  };
  
  String.prototype.regExpReplace = function (rule, replaceValue, ruleFlags) {
    ruleFlags = ruleFlags || 'g';
    var trimRegex = new RegExp(rule, ruleFlags),
        resultString = this;
    
    resultString = this.replace(trimRegex, replaceValue);

    return resultString.toString();
  };
  
  String.prototype.trimDotes = function() {
    return this.extTrim('\\.');
  }
  
  Drupal.select2functions = Drupal.select2functions || {};
  
  /**
   * @constructor
   * @this {Drupal.Select2}
   * @param {DOM} context The context.
   */
  Drupal.Select2 = function(context) {
    
    /**
     * Current context.
     * @public
     */
    this.context = context;
    
    this.contextSettings = null;
    
    this.Defaults = Drupal.Select2.Defaults;
    
    this.functionsScopesNames = [
      'Drupal.Select2.functionsScope',
      'Drupal.select2functions'
    ];
    
    function setSelect2Defaults () {
      $.extend(true, $.fn.select2.defaults, Drupal.Select2.Defaults);
      $.extend(true, $.fn.select2.defaults, Drupal.settings.select_2.default_settings);
    }
    
    setSelect2Defaults();
    
  };
  
  /**
   * Default options for the Select2.
   * @public
   */
  Drupal.Select2.Defaults = Drupal.Select2.Defaults || {
    'adaptContainerCssClass': function (className) {
      if (!Drupal.Select2.Defaults.classesListForCopyFromElement
          && !Drupal.Select2.Defaults.classesExcludedForCopy) {
        return clazz;
      }
      switch (typeof Drupal.Select2.Defaults.classesListForCopyFromElement) {
        case 'string':
          if (className == Drupal.Select2.Defaults.classesListForCopyFromElement) {
            return className;
          }
          break;
        case 'object':
          if ($.inArray(className, Drupal.Select2.Defaults.classesListForCopyFromElement) >= 0) {
            return className;
          }
          break;
      }
      return false;
    },
    'classesListForCopyFromElement': ['error'],
    'width': 'copy',
    'predefineExcludions': [
      '.tabledrag-hide select'
    ],
  };
  
  Drupal.Select2.prototype.attachBehaviors = function(element) {
    $.each(Drupal.behaviors, function () {
      if ($.isFunction(this.select2attach)) {
        this.select2attach(element);
      }
    });
  }
  
  Drupal.Select2.functionsScope = Drupal.Select2.functionsScope || {}; 
  
  Drupal.Select2.functionsScope.formatSelectionTaxonomyTermsItem = function (term) {

    if (term.hover_title) {
      return term.hover_title;
    }

    return term.text;
  };
  
  Drupal.Select2.functionsScope.formatSelection_taxonomy_terms_item = Drupal.Select2.functionsScope.formatSelectionTaxonomyTermsItem;
  
  Drupal.Select2.functionsScope.formatResultTaxonomyTermsItem = function (term) {

    var attributes = '';
    var prefix = '';

    if (term.hover_title != undefined) {
      attributes = 'title="' + term.hover_title + '" ';
      prefix = '<span class="visible-on-hover">' + term.hover_title + '</span>';
    }

    return '<span class="taxonomy_terms_item" ' + attributes + '>' + term.text + ' </span>' + prefix;
  };
  
  Drupal.Select2.functionsScope.formatResult_taxonomy_terms_item = Drupal.Select2.functionsScope.formatResultTaxonomyTermsItem;
  
  Drupal.Select2.functionsScope.acFormatResult = function (result) {
    return result.text;
  };
  
  Drupal.Select2.functionsScope.ac_format_result = Drupal.Select2.functionsScope.acFormatResult;
  
  Drupal.Select2.functionsScope.acFielsFormatSelection = function (item) {
    return item.text;
  };
  
  Drupal.Select2.functionsScope.ac_fiels_FormatSelection = Drupal.Select2.functionsScope.acFielsFormatSelection;
  
  Drupal.Select2.functionsScope.acS2InitSelecttion = function (element, callback) {
    var def_values = $(element).select2('val');

    callback({
      id: def_values,
      text: def_values
    });

  };
  
  Drupal.Select2.functionsScope.entityReferenceInitSelecttion = function (element, callback) {
    var def_values = $(element).select2('val'),
        select2 = $(element).data('select2'),
        select2Options = select2 ? select2.opts : false,
        hideIds = select2Options ? select2Options.hideEntityIds : false,
        comaReplacement = select2Options ? select2Options.comma_replacement : false;

    if (typeof def_values == 'string') {

      var label = def_values;
      label = label.quote_trim().replace(/"{2,}/g, '"');

      if (hideIds) {
        label = label.replace(/\([0-9]+\)$/g, '');
      }
      
      if (comaReplacement) {
        label = label.regExpReplace('{' + comaReplacement + '}', ',');
      }
      
      callback({
        id: def_values,
        text: label
      });
    } else if (typeof (def_values) == 'object') {

      data = [];
      for (var i = 0; i < def_values.length; i++) {

        var label = def_values[i];
        label = label.quote_trim().replace(/"{2,}/g, '"');

        if (hideIds) {
          label = label.replace(/\([0-9]+\)$/g, '');
        }
        
        if (comaReplacement) {
          label = label.regExpReplace('{' + comaReplacement + '}', ',');
        }
        
        data.push({
          id: def_values[i],
          text: label
        });
      }
      callback(data);
    }

  };
  
  Drupal.Select2.functionsScope.ac_s2_init_selecttion = Drupal.Select2.functionsScope.acS2InitSelecttion;
  
  Drupal.Select2.functionsScope.taxonomyTermRefAcS2InitSelecttion = function (element, callback) {

    var def_values = $(element).select2('val');

    if (typeof def_values == 'string') {

      var label = def_values;
      label = label.quote_trim().replace(/{{;}}/g, ',').replace(/"{2,}/g, '"');

      callback({
        id: def_values,
        text: label
      });
    } else if (typeof (def_values) == 'object') {

      data = [];
      for (var i = 0; i < def_values.length; i++) {

        var label = def_values[i];
        label = label.quote_trim().replace(/{{;}}/g, ',').replace(/"{2,}/g, '"');

        data.push({
          id: def_values[i],
          text: label
        });
      }
      callback(data);
    }

  };
  
  Drupal.Select2.functionsScope.taxonomy_term_ref_ac_s2_init_selecttion = Drupal.Select2.functionsScope.taxonomyTermRefAcS2InitSelecttion;
  
  Drupal.Select2.functionsScope.getAjaxObjectForAcElement = function (options) {
    return {
      url: function (term) {
        if (options.path_is_absolute) {
          return options.autocomplete_path + Drupal.encodePath(term);
        }
        return Drupal.settings.basePath + options.autocomplete_path + '/' + Drupal.encodePath(term);
      },
      dataType: 'json',
      quietMillis: 100,
      results: function (data) {
        // notice we return the value of more so Select2 knows if more results can be loaded

        var results_out = [];

        $.each(data, function (id, title) {
          results_out.push({
            id: id,
            text: title
          });
        });

        return {
          results: results_out
        };
      },
      params: {
        error: function (jqXHR, textStatus, errorThrown) {
          if (textStatus == 'abort') {

          }
        }
      }
    };
  };
  
  Drupal.Select2.functionsScope.ac_element_get_ajax_object = Drupal.Select2.functionsScope.getAjaxObjectForAcElement;
  
  Drupal.Select2.prototype.setContext = function(context, settings) {
    this.context = context;
    this.processElements();
  }
  
  Drupal.Select2.prototype.processElements = function() {
    this.markExcludedElements();
    this.attachSelect2();
  }
  
  Drupal.Select2.prototype.markExcludedElements = function() {
    
    if (!this.context) return;
    
    $.each(this.Defaults.predefineExcludions, function(index, selector) {
      $(selector, this.context).once('select2-predefined-excludions').addClass('no-select2');
    })
    
    if (Drupal.settings.select_2.excludes.by_selectors.length > 0) {
      for (i = 0; i < Drupal.settings.select_2.excludes.by_selectors.length; ++i) {
        $(Drupal.settings.select_2.excludes.by_selectors[i], this.context)
        .once('select2-excluded-by-selectors').addClass('no-select2');
      }
    }
    
    if (Drupal.settings.select_2.excludes.by_class.length > 0) {
      var byClassSelector = Drupal.settings.select_2.excludes.by_class.join(', .');
      byClassSelector = '.' + byClassSelector;
      try {
        $(byClassSelector, this.context).once('select2-excluded-by-classes').addClass('no-select2');
      } catch (e) {
        throw 'ERROR while setting exlution classes by classes list: ' + e.message;
      }
    }
  }
  
  Drupal.Select2.prototype.attachSelect2 = function() {
    
    if (!this.context) return;
    
    if (Drupal.settings.select_2.process_all_selects_on_page) {
      $('select', this.context).once('select2-attach').atachSelect2();
    }
    
    $('select.use-select-2, input[type="text"].use-select-2, input[type="hidden"].use-select-2', this.context)
    .once('select2-attach').atachSelect2();
  }
  
  Drupal.Select2.prototype.attachSelect2ToElement = function($element) {
    
    if ($element.hasClass('no-select2')) return;
    
    var self = this,
        id = $element.attr('id');
    
    $element.id = id;
    
    if (this.checkElementForExclusions($element)) {
      $element.addClass('no-select2');
      return;
    }
    
    var options = Drupal.settings.select_2.elements[id]
                  ? Drupal.settings.select_2.elements[id]
                  : {};
    
    options = this.prepareElementOptions(options, $element);
               
    $(document).trigger('select2.alterElementOptions', [$element, options]);
    
    try {
      $element.select2(options);
    } catch (e) {
      if (typeof window.console == "object" && typeof console.error == "function") {
        console.error('Error: ' + e);
        return;
      }
    }
    
    Drupal.Select2Processor.attachBehaviors($element);
    
    var select2Container = false;

    if (options.events_hadlers) {
      $.each(options.events_hadlers, function (eventName, handlerName) {
        var handler = self.getObjectOrFunctionByName(handlerName);
        if (handler && typeof handler == 'function') {
          $element.on(eventName, handler);
        }
      })
    }
    
    if ($element.data('select2') != undefined) {
      if ($element.data('select2').$container != undefined) {
        select2Container = $element.data('select2').$container;
      } else if ($element.data('select2').container != undefined) {
        select2Container = $element.data('select2').container;
      }
    }
    
    if (select2Container) {
      // need fix select2 container width
      var stylesForFixWidth = ['element', 'copy'],
          cur_width = select2Container.outerWidth();
      if (options.width && $.inArray(options.width, stylesForFixWidth)
          && cur_width <= 6) {
        select2Container.width('auto');
      }
    }
    
    if (select2Container && options.jqui_sortable && $.fn.sortable) {
      select2Container.find("ul.select2-choices").sortable({
        containment: 'parent',
        start: function () {
          $element.select2("onSortStart");
        },
        update: function () {
          $element.select2("onSortEnd");
        }
      });
    }
    
  };
  
  Drupal.Select2.prototype.searchFunctionInScope = function(functionName) {

    var self = this,
        func = false;
    
    functionName = functionName.toString().trimDotes();
    
    if (functionName.indexOf('.') > -1) {
      if (func = this.getObjectOrFunctionByName(functionName)) {
        return func;
      }
    }
    
    $.each(this.functionsScopesNames, function (index, scopeName) {
      if (func = self.getObjectOrFunctionByName(scopeName + '.' + functionName)) {
        return false;
      }
    });
    
    return func;
  }
  
  Drupal.Select2.prototype.getObjectPropertyByName = function (obj, prop) {

    if (typeof obj === 'undefined') {
        return false;
    }

    var _index = prop.indexOf('.');
    if (_index > -1) {
        return this.getObjectPropertyByName(obj[prop.substring(0, _index)], prop.substr(_index + 1));
    }

    return obj[prop];
  }
  
  Drupal.Select2.prototype.getObjectOrFunctionByName = function (name) {
    return this.getObjectPropertyByName(window, name);
  }
  
  Drupal.Select2.prototype.prepareElementOptions = function(options, $element) {
    var self = this,
        optionsForStringToFunctionConversion = [
          'data', 'ajax', 'query', 'formatResult', 'formatSelection', 'initSelection'
        ],
        elementTagName = $element.prop("tagName");
    
    $.each(optionsForStringToFunctionConversion, function (index, propertyName) {
      if (options[propertyName] && typeof options[propertyName] == 'string') {
        var func = self.searchFunctionInScope(options[propertyName]);
        if (func) {
          if (propertyName == 'ajax' && typeof func == 'function') {
            options[propertyName] = func(options);
          } else {
            options[propertyName] = func;
          }
        }
      }
    });
    
    if (options.selectedOnNewLines != undefined && options.selectedOnNewLines) {
      options.containerCssClass += ' one-option-per-line';
    }
    
    if ($element.hasClass('filter-list')) {
      options.allowClear = false;
    }
    
    if (options.allowClear || $('option[value=""]', $element).length > 0) {
      if ($('option[value=""]', $element).length > 0) {
        // Checking for empty option exist and set placeholder by its value if
        // placeholder does not setted
        if (options.placeholder == undefined) {
          options.placeholder = $('option[value=""]', $element).text();
        }
        // Clear empty option text
        $('option[value=""]', $element).html('');
      }
      if (options.placeholder == undefined && $element.attr('placeholder') == undefined) {
        // If placeholder not defined set allowClear option to false
        options.allowClear = false;
      } else if (options.allowClear == undefined) {
        options.allowClear = true;
      }
    }
    
    if (options.allow_add_onfly) {
      options.createSearchChoice = function (term, data) {
        if ($(data).filter(
          function () {
            return this.text.localeCompare(term) === 0;
          }
        ).length === 0) {
          return {
            id: term,
            text: term
          };
        }
      };
    }
    
    if (options.taxonomy_ref_ac_allowed) {
      options.createSearchChoice = function (term, data) {
        if ($(data).filter(
          function () {
            //return this.text.localeCompare(term) === 0;
          }
        ).length === 0) {
          return {
            id: term,
            text: term
          };
        }
      };
    }
    
    if (options.comma_replacement) {
      var cur_val = "" + $element.val();
      cur_val = cur_val.replace(/".*?"/g, function (match) {
        return match.replace(/,/g, '{{;}}');
      });
      $element.val(cur_val);
    }
    
    if (elementTagName == 'SELECT') {
      // disabled_options process
      if (options.disabled_options) {
        $.each(options.disabled_options, function (index, value) {
          $('option[value="' + value + '"]', $element).prop('disabled', true);
        });
      }
      options.jqui_sortable = false;
    }
    
    return options;
  }
  
  /**
   * Check element for matching exclusions rules.
   * @public
   * @param {jQuery object} $element The element that must be checked according to the rules exceptions.
   * @return {Bool} true if element must be skipped and false otherwise.
   */
  Drupal.Select2.prototype.checkElementForExclusions = function($element) {
    if (!$element.id) return false;
    
    var excludeIds = Drupal.settings.select_2.excludes.by_id.values;
    
    if ($.inArray($element.id, excludeIds) >= 0) {
      return true;
    } else if (Drupal.settings.select_2.excludes.by_id.reg_exs.length > 0) {
      // check by regexs for ids
      for (i = 0; i < Drupal.settings.select_2.excludes.by_id.reg_exs.length; ++i) {
        var regex = new RegExp(Drupal.settings.select_2.excludes.by_id.reg_exs[i], "ig");

        if (regex.test($element.id)) {
          return true;
        }
      }
    }
    
    return false;
  }
  
  $.fn.atachSelect2 = function () {
    return this.each(function (index) {
      if (!Drupal.Select2Processor) return;
      
      var $element = $(this);
      
      Drupal.Select2Processor.attachSelect2ToElement($element);
      
    });
  }
  
  Drupal.behaviors.select2 = {
    attach: function (context, settings) {
      
      if (typeof ($.fn.select2) == 'undefined') return;
      
      Drupal.Select2Processor = Drupal.Select2Processor || new Drupal.Select2();
      
      if (Drupal.settings.select_2.settings_updated) {
        Drupal.Select2Processor.setContext(context);
      }
      else {
        
        Drupal.settings.select_2.settings_updated = true;
        
        var setting_update_url = Drupal.settings.basePath + 'select2/ajax/get_settings',
        jqxhr = $.ajax(setting_update_url)
        .done(function (data) {
          //merging with element defined settings
          try {
            Drupal.settings.select_2.excludes = data[0].settings.select_2.excludes;
          } catch (e) {
            throw 'ERROR while updating settings for select2: ' + e.message;
          }
        })
        .fail(function () {
          throw 'Select2 setting update ajax request failed.';
        })
        .always(function () {
          Drupal.Select2Processor.setContext(context);
        });
      }
      
    }
  };
  
})(jQuery, window, document);