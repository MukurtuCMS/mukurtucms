<?php
/**
 * @file
 * ip_geoloc.session.inc
 *
 * Implements via Session Cache API one of several storage mechanisms for the
 * user's changing location details.
 */

/**
 * Set a value to the user's SESSION.
 *
 * @param string $name
 *   if FALSE all IPGV&M session variables are deleted;
 *   if NULL the array of all IPGV&M session variables is returned.
 *
 * @param mixed $value
 *   The value to set. Use NULL to wipe the existing value.
 *
 * @return array|null
 *   The requested or all session variables from ip_geoloc
 */
function _ip_geoloc_set_session_value($name, $value = NULL) {

  if (!variable_get('ip_geoloc_allow_session_storage', TRUE)) {
    return NULL;
  }

  if (module_exists('context_session') && $name == 'location') {
    _ip_geoloc_set_location_on_context_session($value);
  }

  if (!module_exists('session_cache')) {
    if ($name === FALSE) {
      unset($_SESSION['ip_geoloc']);
    }
    elseif (isset($name)) {
      $_SESSION['ip_geoloc'][$name] = isset($_SESSION) && isset($_SESSION['ip_geoloc'][$name]) && is_array($_SESSION['ip_geoloc'][$name]) && is_array($value)
        ? array_merge($_SESSION['ip_geoloc'][$name], $value)
        : $value;
    }
    return isset($_SESSION) && isset($_SESSION['ip_geoloc']) ? $_SESSION['ip_geoloc'] : NULL;
  }

  if ($name === FALSE) {
    session_cache_set('ip_geoloc', NULL);
    return NULL;
  }

  $variables = session_cache_get('ip_geoloc');
  if (isset($name)) {
    // Merge/override the session with the supplied value
    $variables[$name] = isset($variables[$name]) && is_array($variables[$name]) && is_array($value)
      ? array_merge($variables[$name], $value)
      : $value;
    session_cache_set('ip_geoloc', $variables);
  }
  return $variables;
}

/**
 * Copy attributes from the supplied location to the context session.
 *
 * @param array $location
 *   Array containing country_code, locality, postal_code and possibly more
 */
function _ip_geoloc_set_location_on_context_session($location) {
  // context_session does not support session_cache, can only use $_SESSION.
  // Note that context_session only offers boolean support: it sets a
  // context based on the fact whether a key is present or not. So we have
  // to fake name|value pairs.
  foreach (array('country_code', 'administrative_area_level_1', 'locality', 'postal_code') as $key) {
    // Clear out old values
    foreach ($_SESSION as $session_key => $val) {
      if (strpos($session_key, "ip_geoloc:location.$key=") === 0) {
        unset($_SESSION[$session_key]);
      }
    }
    if (!empty($location[$key])) {
      $_SESSION["ip_geoloc:location.$key=" . $location[$key]] = TRUE;
      // If and when Context Session accepts name|value pairs we can go:
      //$_SESSION["ip_geoloc:location.$key"] = $val;
    }
  }
}

/**
 * Get a value from the user's SESSION or all values, if no name is specified.
 *
 * @param string $name
 *   The name of the variable to retrieve
 *
 * @return mixed
 *   The session value belonging to $name or all session values when name is
 *   omittted.
 */
function _ip_geoloc_get_session_value($name = NULL) {
  $variables = _ip_geoloc_set_session_value(NULL);
  return empty($name) ? $variables : (isset($variables[$name]) ? $variables[$name] : NULL);
}
