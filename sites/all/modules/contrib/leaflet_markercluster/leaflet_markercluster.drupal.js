/*
 * We are overriding a large part of the JS defined in leaflet (leaflet.drupal.js).
 * Not nice, but we can't do otherwise without refactoring code in Leaflet.
 */

(function ($) {

  var LEAFLET_MARKERCLUSTER_EXCLUDE_FROM_CLUSTER = 0x01;

  Drupal.behaviors.leaflet = { // overrides same behavior in leaflet/leaflet.drupal.js
    attach: function(context, settings) {
      var start = (new Date()).getTime();

      $(settings.leaflet).each(function () {
        // skip to the next iteration if the map already exists
        var container = L.DomUtil.get(this.mapId);
        if (!container || container._leaflet) {
          return false;
        }

        // load a settings object with all of our map settings
        var settings = {};
        for (var setting in this.map.settings) {
          settings[setting] = this.map.settings[setting];
        }

        // instantiate our new map
        var lMap = new L.Map(this.mapId, settings);
        lMap.bounds = [];

        // add map layers
        var layers = {}, overlays = {};
        var i = 0;
        for (var key in this.map.layers) {
          var layer = this.map.layers[key];
          var map_layer = Drupal.leaflet.create_layer(layer, key);

          layers[key] = map_layer;

          // keep the reference of first layer
          // Distinguish between "base layers" and "overlays", fallback to "base"
          // in case "layer_type" has not been defined in hook_leaflet_map_info()
          layer.layer_type = (typeof layer.layer_type === 'undefined') ? 'base' : layer.layer_type;
          // as written in the doc (http://leafletjs.com/examples/layers-control.html)
          // Always add overlays layers when instantiate, and keep track of
          // them for Control.Layers.
          // Only add the very first "base layer" when instantiating the map
          // if we have map controls enabled
          switch (layer.layer_type) {
            case 'overlay':
              lMap.addLayer(map_layer);
              overlays[key] = map_layer;
              break;
            default:
              if (i === 0 || !this.map.settings.layerControl) {
                lMap.addLayer(map_layer);
                i++;
              }
              layers[key] = map_layer;
              break;
          }
          i++;
        }
        // We loop through the layers once they have all been created to connect them to their switchlayer if necessary.
        var switchEnable = false;
        for (var key in layers) {
          if (layers[key].options.switchLayer) {
            layers[key].setSwitchLayer(layers[layers[key].options.switchLayer]);
            switchEnable = true;
          }
        }
        if (switchEnable) {
          switchManager = new SwitchLayerManager(lMap, {baseLayers: layers});
        }

        // keep an instance of leaflet layers
        this.map.lLayers = layers;

        // keep an instance of map_id
        this.map.map_id = this.mapId;

        // @RdB create marker cluster layers if leaflet.markercluster.js is included
        // There will be one cluster layer for each "clusterGroup".
        var clusterLayers = {};
        if (typeof L.MarkerClusterGroup !== 'undefined') {

          // If we specified a custom cluster icon, use that.
          if (this.map.markercluster_icon) {
            var icon_settings = this.map.markercluster_icon;

            settings['iconCreateFunction'] = function(cluster) {
              var icon = new L.Icon({iconUrl: icon_settings.iconUrl});

              // override applicable marker defaults
              if (icon_settings.iconSize) {
                icon.options.iconSize = new L.Point(parseInt(icon_settings.iconSize.x), parseInt(icon_settings.iconSize.y));
              }
              if (icon_settings.iconAnchor) {
                icon.options.iconAnchor = new L.Point(parseFloat(icon_settings.iconAnchor.x), parseFloat(icon_settings.iconAnchor.y));
              }
              if (icon_settings.popupAnchor) {
                icon.options.popupAnchor = new L.Point(parseFloat(icon_settings.popupAnchor.x), parseFloat(icon_settings.popupAnchor.y));
              }
              if (icon_settings.shadowUrl !== undefined) {
                icon.options.shadowUrl = icon_settings.shadowUrl;
              }
              if (icon_settings.shadowSize) {
                icon.options.shadowSize = new L.Point(parseInt(icon_settings.shadowSize.x), parseInt(icon_settings.shadowSize.y));
              }
              if (icon_settings.shadowAnchor) {
                icon.options.shadowAnchor = new L.Point(parseInt(icon_settings.shadowAnchor.x), parseInt(icon_settings.shadowAnchor.y));
              }

              return icon;
            }
          }
        }

        // add features
        for (i = 0; i < this.features.length; i++) {
          var feature = this.features[i];
         
          var cluster = (feature.type === 'point') && (!feature.flags || !(feature.flags & LEAFLET_MARKERCLUSTER_EXCLUDE_FROM_CLUSTER));
          if (cluster) {
            var clusterGroup = feature.clusterGroup ? feature.clusterGroup : 'global';
            if (!clusterLayers[clusterGroup]) {
              // Note: only applicable settings will be used, remainder are ignored
              clusterLayers[clusterGroup] = new L.MarkerClusterGroup(settings);
              lMap.addLayer(clusterLayers[clusterGroup]);
            }
          }
          var lFeature;

          // dealing with a layer group
          if (feature.group) {
            var lGroup = new L.LayerGroup();
            for (var groupKey in feature.features) {
              var groupFeature = feature.features[groupKey];
              lFeature = leaflet_create_feature(groupFeature, lMap);
              lFeature.options.regions = feature.regions;
              if (groupFeature.popup) {
                lFeature.bindPopup(groupFeature.popup);
              }
              lGroup.addLayer(lFeature);
            }

            // add the group to the layer switcher
            overlays[feature.label] = lGroup;

            if (cluster && clusterLayers[clusterGroup])  {
              clusterLayers[clusterGroup].addLayer(lGroup);
            } else {
              lMap.addLayer(lGroup);
            }
          }
          else {
            lFeature = leaflet_create_feature(feature, lMap);
            // @RdB add to cluster layer if one is defined, else to map
            if (cluster && clusterLayers[clusterGroup]) {
              lFeature.options.regions = feature.regions;
              clusterLayers[clusterGroup].addLayer(lFeature);
            }
            else {
              lMap.addLayer(lFeature);
            }
            if (feature.popup) {
              lFeature.bindPopup(feature.popup/*, {autoPanPadding: L.point(25,25)}*/);
            }
          }

          // Allow others to do something with the feature that was just added to the map
          $(document).trigger('leaflet.feature', [lFeature, feature]);
        }

        // add layer switcher
        if (this.map.settings.layerControl) {
          lMap.addControl(new L.Control.Layers(layers, overlays));
        }

        // center the map
        var zoom = this.map.settings.zoom ? this.map.settings.zoom : this.map.settings.zoomDefault;
        if (this.map.center && (this.map.center.force || this.features.length === 0)) {
          lMap.setView(new L.LatLng(this.map.center.lat, this.map.center.lon), zoom);
        }
        else if (this.features.length > 0) {
          Drupal.leaflet.fitbounds(lMap);
          if (this.map.settings.zoom) { // or: if (zoom) ?
            lMap.setZoom(zoom);
          }
        }

        // associate the center and zoom level proprerties to the built lMap.
        // useful for post-interaction with it
        lMap.center = lMap.getCenter();
        lMap.zoom = lMap.getZoom();

        // add attribution
        if (this.map.settings.attributionControl && this.map.attribution) {
          lMap.attributionControl.setPrefix(this.map.attribution.prefix);
          lMap.attributionControl.addAttribution(this.map.attribution.text);
        }

        // add the leaflet map to our settings object to make it accessible
        this.lMap = lMap;

        // allow other modules to get access to the map object using jQuery's trigger method
        $(document).trigger('leaflet.map', [this.map, lMap]);

        // Destroy features so that an AJAX reload does not get parts of the old set.
        // Required when the View has "Use AJAX" set to Yes.
        this.features = null;
      });

      function leaflet_create_feature(feature, lMap) {
        var lFeature;
        switch (feature.type) {
          case 'point':
            lFeature = Drupal.leaflet.create_point(feature, lMap);
            break;
          case 'linestring':
            lFeature = Drupal.leaflet.create_linestring(feature, lMap);
            break;
          case 'polygon':
            lFeature = Drupal.leaflet.create_polygon(feature, lMap);
            break;
          case 'multipolygon':
          case 'multipolyline':
            lFeature = Drupal.leaflet.create_multipoly(feature, lMap);
            break;
          case 'json':
            lFeature = Drupal.leaflet.create_json(feature.json, lMap);
            break;
          case 'popup':
            lFeature = Drupal.leaflet.create_popup(feature, lMap);
            break;
          case 'circle':
            lFeature = Drupal.leaflet.create_circle(feature, lMap);
            break;
        }

        // assign our given unique ID, useful for associating nodes
        if (feature.leaflet_id) {
          lFeature._leaflet_id = feature.leaflet_id;
        }

        var options = {};
        if (feature.options) {
          for (var option in feature.options) {
            options[option] = feature.options[option];
          }
          lFeature.setStyle(options);
        }
        return lFeature;
      }

      if (console) {
        //var renderTime = (new Date()).getTime() - start;
        //console.log('leaflet_markercluster.drupal.js render time: ' + renderTime/1000 + ' s');
      }
    }
  };

})(jQuery);
