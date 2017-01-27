// Take advantage of Leaflet's Class idiom
L.Sync =  L.Class.extend({

	statics: {
    SYNC_CONTENT_TO_MARKER: 1 << 1,
    SYNC_MARKER_TO_CONTENT: 1 << 2,
    SYNC_MARKER_TO_CONTENT_WITH_POPUP: 1 << 3,

    SYNCED_CONTENT_HOVER: 'synced-content-hover',
    SYNCED_MARKER_HOVER : 'synced-marker-hover',
    SYNCED_MARKER_HIDDEN: 'leaflet-marker-hidden'
  },

  options: {
    // Maybe one day
	},

	initialize: function (map, options) {
    L.setOptions(this, options);
    this.map = map;
    this.lastMarker = null;
	},

  closePopup: function(marker) {
    if (marker && marker.closePopup) {
      marker.closePopup();
    }
  },

  hide: function(marker) {
    // Not marker.setOpacity(0) to avoid interference with leaflet.markercluster
    this.addClass(marker, L.Sync.SYNCED_MARKER_HIDDEN);
    if (marker === this.lastMarker) {
      this.lastMarker = null;
    }
  },

  hideIfAddedViaSync: function(marker) {
    if (marker) {
      this.unhighlight(marker);
      if (marker && marker.addedViaSync) {
        this.hide(marker);
      }
    }
  },

  show: function(marker) {
    // Not marker.setOpacity(1) to avoid interference with leaflet.markercluster
    this.removeClass(marker, L.Sync.SYNCED_MARKER_HIDDEN);
  },

  highlight: function(marker) {
    this.addClass(marker, L.Sync.SYNCED_CONTENT_HOVER);
  },

  unhighlight: function(marker) {
    this.removeClass(marker, L.Sync.SYNCED_CONTENT_HOVER);
  },

  syncContentToMarker: function(contentSelector, marker) {
    marker.on('mouseover', function(event) {
      jQuery(contentSelector).addClass(L.Sync.SYNCED_MARKER_HOVER);
    });
    marker.on('mouseout', function(event) {
      jQuery(contentSelector).removeClass(L.Sync.SYNCED_MARKER_HOVER);
    });
  },

  syncMarkerToContent: function(contentSelector, marker) {
    var sync = this;

    marker.on('popupclose', function(event) {
      var marker = event.target;
      if (marker === sync.lastMarker) {
        if (marker._icon && (marker.flags & L.Sync.SYNC_MARKER_TO_CONTENT_WITH_POPUP)) {
          marker._popup.options.offset.y = sync.popupOffsetY;
        }
        sync.unhighlight(marker);
        //sync.hideIfAddedViaSync(marker);
        sync.lastMarker = null;
      }
    });

    // Using bind() as D7 core's jQuery is old and does not support on()
    jQuery(contentSelector).bind('mouseover', function(event) {
      sync.handleContentMouseOver(marker);
    });
  },

  handleContentMouseOver: function(marker) {
    if (marker === null || marker === this.lastMarker) {
      return;
    }
    this.hideIfAddedViaSync(this.lastMarker);

    var addedViaSync = !marker._map || !marker.options.opacity;
    if (!marker._map) {
      marker.addTo(this.map);
    }
    marker.addedViaSync = addedViaSync || marker.addedViaSync;

    var point = marker.getLatLngs ? marker.getLatLngs()[0] : marker.getLatLng();
    if (!this.map.getBounds().contains(point)) {
      this.map.panTo(point);
    }
    // Make geometry visible, in case it was hidden.
    this.show(marker);
    this.highlight(marker);

    if (marker.flags & L.Sync.SYNC_MARKER_TO_CONTENT_WITH_POPUP) {
      if (marker._icon) {
        // Adjust popup position for markers, not other geometries.
        if (!this.popupOffsetY) {
          this.popupOffsetY = marker._popup.options.offset.y;
        }
        marker._popup.options.offset.y = this.popupOffsetY - 20;
      }
      marker.openPopup();
    }
    if (marker._icon && marker._icon.style) {
      // This does NOT work in most browsers.
      marker._bringToFront();
      marker.setZIndexOffset(9999);
    }
    this.lastMarker = marker;
  },

  addClass: function(marker, className) {
    var elements = this.getMarkerElements(marker);
    for (var i = 0; i < elements.length; i++) {
      L.DomUtil.addClass(elements[i], className);
    }
  },

  removeClass: function(marker, className) {
    var elements = this.getMarkerElements(marker);
    for (var i = 0; i < elements.length; i++) {
      L.DomUtil.removeClass(elements[i], className);
    }
  },

  markerClusterGroup: function() {
    for (var id in this.map._layers) {
      if (this.map._layers[id]._topClusterLevel) {
        return this.map._layers[id];
      }
    }
    return null;
  },

  getMarkersInClusters: function() {
    var markerClusterGroup = this.markerClusterGroup();
    return markerClusterGroup ? markerClusterGroup._topClusterLevel.getAllChildMarkers() : [];
  },

  getMarkerElements: function(marker) {
    var elements = [];
    if (marker) {
      if (marker._icon) {
        elements.push(marker._icon);
      }
      if (marker._container) {
        elements.push(marker._container);
      }
      if (marker._layers) {
        for (var key in marker._layers) elements.push(marker._layers[key]._container);
      }
    }
    return elements;
  }
});

// Gets triggered before 'leaflet.map'. Extend marker data for further use.
jQuery(document).bind('leaflet.feature', function(event, marker, feature) {
  // marker is the feature just added to the map, it could be a polygon too.
  // feature.feature_id is the node ID, as set by ip_geoloc_plugin_style_leaflet.inc
  if (feature.feature_id) {
    marker.feature_id = feature.feature_id;
  }
  if (feature.flags) {
    marker.flags = feature.flags;
  }
});

jQuery(document).bind('leaflet.map', function(event, map, lMap) {

  var sync = new L.Sync(lMap, {});

  lMap.on('zoomend', function(event) {
    // To avoid interference with Leaflet's way of controlling visibility via
    // setOpacity(), we remove the special 'hidden' class on 'zoomend'.
    if (sync.lastMarker) {
      sync.show(sync.lastMarker);
      sync.lastMarker.addedViaSync = false;
    }
  });

  if (map.settings.revertLastMarkerOnMapOut) {
    lMap.on('mouseout', function(event) {
      if (sync.lastMarker) {
        sync.lastMarker.closePopup();
        sync.hideIfAddedViaSync(sync.lastMarker);
        sync.lastMarker = null;
      }
    });
  }

  var clusterMarkers = sync.getMarkersInClusters();
  // Convert lMap._layers to array before concatenating
  var otherMarkers = Object.keys(lMap._layers).map(function(key) { return lMap._layers[key]; });
  var allMarkers = clusterMarkers.concat(otherMarkers);

  for (var i = 0; i < allMarkers.length; i++) {
    var marker = allMarkers[i];
    if (marker.flags) {
      // A CSS class, not an ID as multiple markers may be attached to same node.
      var contentSelector = ".sync-id-" + marker.feature_id;

      if (marker.flags & L.Sync.SYNC_CONTENT_TO_MARKER) {
        sync.syncContentToMarker(contentSelector, marker);
      }
      if (marker.flags & L.Sync.SYNC_MARKER_TO_CONTENT) {
        sync.syncMarkerToContent(contentSelector, marker);
      }
      marker.on('add', function(event) {
        event.target.addedViaSync = false;
      });
      marker.on('remove', function(event) {
        event.target.addedViaSync = false;
      });
    }
  }

});
