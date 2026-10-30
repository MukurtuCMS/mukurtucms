<?php

namespace Drupal\bootstrap\Backport\Plugin\Provider;

/**
 * The "custom" CDN provider plugin.
 *
 * Note: this class is a backport from the 8.x-3.x code base.
 *
 * @see https://drupal-bootstrap.org/api/bootstrap/namespace/Drupal%21bootstrap%21Plugin%21Provider/8
 *
 * @ingroup plugins_provider
 */
class Custom extends ProviderBase {

  /**
   * {@inheritdoc}
   */
  protected $pluginId = 'custom';

  /**
   * {@inheritdoc}
   */
  protected function discoverCdnAssets($version, $theme) {
    $assets = array();
    foreach (array('css', 'js') as $type) {
      if ($setting = bootstrap_setting('cdn_custom_' . $type)) {
        $assets[$type][] = $setting;
      }
      if ($setting = bootstrap_setting('cdn_custom_' . $type . '_min')) {
        $assets['min'][$type][] = $setting;
      }
    }
    return $assets;
  }

}
