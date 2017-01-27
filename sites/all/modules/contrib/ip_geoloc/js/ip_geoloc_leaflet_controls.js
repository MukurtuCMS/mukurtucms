
// Inspired by Roger Codina and
// http://gis.stackexchange.com/questions/87199/how-does-one-reset-map-fitbounds-zoomtofeature-to-the-original-zoom

(function ($) {

  $(document).bind('leaflet.map', function(event, map_and_features, lMap) {
    var mapSettings = map_and_features.settings;
    // Use a flag on the map object to prevent controls being added multiple
    // times. This can happen in AJAX contexts.
    if (lMap && mapSettings) {
      if (mapSettings.zoomIndicator) {
        lMap.addControl(L.control.zoomIndicator(mapSettings.zoomIndicator));
      }
      if (mapSettings.resetControl) {
        lMap.addControl(L.control.reset(mapSettings.resetControl));
      }
      if (mapSettings.clusterControl) {
        lMap.addControl(L.control.clusterToggle(mapSettings.clusterControl));
      }
      if (mapSettings.scaleControl) {
        lMap.addControl(L.control.scale(mapSettings.scaleControl));
      }
      if (mapSettings.miniMap) {
        for (var key in lMap._layers) {
          var layer = lMap._layers[key];
          if (layer instanceof L.TileLayer) {
            // Copy the (first) main map layer for use in a mini-map inset.
            var tileLayer = (layer._type === 'quad')
              // See leaflet_more_maps/leaflet_more_maps.js
              ? L.tileLayerQuad(layer._url, layer.options)
              : L.tileLayer(layer._url, layer.options);
            lMap.addControl(L.control.minimap(tileLayer, mapSettings.miniMap));
            break;
          }
        }
      }
    }
  });
})(jQuery);

L.Control.ZoomIndicator = L.Control.extend({

  options: {
    position: 'topleft',
    prefix: 'z'
  },

  onAdd: function(map) {
    this.indicator = L.DomUtil.create('div', 'leaflet-control-zoom-indicator leaflet-bar');
    this.indicator.setAttribute('title', Drupal.t('Zoom level'));
    this.indicator.innerHTML = this.options.prefix + map.getZoom();
    map.on('zoomend', this.update, this);
    return this.indicator;
  },

  update: function(event) {
    this.indicator.innerHTML = event.target.getZoom();
  }
});
L.control.zoomIndicator = function(options) {
  return new L.Control.ZoomIndicator(options);
};

L.Control.Reset = L.Control.extend({

  options: {
    position: 'topleft',
    label: 'R'
  },

  onAdd: function(map) {
    this._map._initialBounds = map.getBounds();

    var button = L.DomUtil.create('a', 'leaflet-control-reset leaflet-bar');
    if (this.options.label.length <= 2) {
      button.innerHTML = this.options.label;
    }
    else {
      // Assume label is a font-icon specification, e.g. 'fa fa-repeat'.
      L.DomUtil.addClass(button, this.options.label);
    }
    button.setAttribute('title', Drupal.t('Reset'));

    // Must pass "this" in as context, or onClick() will not know us.
    L.DomEvent
      .on(button, 'click', this.onClick, this)
      .on(button, 'dblclick', L.DomEvent.stopPropagation)
      .on(button, 'dblclick', function(event) {
         alert(Drupal.t('A single click is sufficient!'));
      });

    return button;
  },

  onClick: function(event) {
    this._map.fitBounds(this._map._initialBounds);
  }
});
L.control.reset = function(options) {
  return new L.Control.Reset(options);
};

L.Control.ClusterToggle = L.Control.extend({

  options: {
    position: 'topright'
  },

  onAdd: function(map) {
    var leafletSettings = Drupal.settings.leaflet;
    for (var m = 0; m < leafletSettings.length; m++) {
      // Get here once per map, i.e. once per containing div.
      if (L.DomUtil.get(leafletSettings[m].mapId) === map._container) {
        this._masterSettings = leafletSettings[m].map.settings;
        break;
      }
    }
    var button = L.DomUtil.create('a', 'leaflet-control-cluster leaflet-bar');
    button.setAttribute('title', Drupal.t('Toggle clustering'));

    // Must pass "this" in as context, or onClick() will not know us.
    L.DomEvent
      .on(button, 'click', this.onClick, this)
      .on(button, 'dblclick', L.DomEvent.stopPropagation)
      .on(button, 'dblclick', function(event) {
         alert(Drupal.t('A single click is sufficient!'));
      });

    return button;
  },

  onClick: function(event) {
    // This normally only loops once, as there's only one _topClusterLevel
    for (var leaflet_id in this._map._layers) {
      if (this._map._layers[leaflet_id]._topClusterLevel) {
        var clusterGroup = this._map._layers[leaflet_id];
        clusterGroup._map = null;
        if (clusterGroup.options.disableClusteringAtZoom < 0) {
          // Restore the old disableClusteringAtZoom setting.
          clusterGroup.options.disableClusteringAtZoom = this._masterSettings ? this._masterSettings.disableClusteringAtZoom : null;
        }
        else {
          // Easiest way to stop clustering safely is this way:
          clusterGroup.options.disableClusteringAtZoom = -1;
        }
        clusterGroup.clearLayers();
        // In order for the clusterGroup to be reinitialised with the new
        // option value(s) set above, clusterGroup._needsClustering needs to
        // hold all markers to be added, before onAdd(map) can be called.
        clusterGroup._needsClustering = clusterGroup._topClusterLevel.getAllChildMarkers();
        clusterGroup.onAdd(this._map);
      }
    }
  }
});
L.control.clusterToggle = function(options) {
  return new L.Control.ClusterToggle(options);
};

if (L.Control.MiniMap) {
  L.extend(L.Control.MiniMap.prototype, {
    hideText: Drupal.t('Hide this inset'),
    showText: Drupal.t('Show map inset')
  });
}