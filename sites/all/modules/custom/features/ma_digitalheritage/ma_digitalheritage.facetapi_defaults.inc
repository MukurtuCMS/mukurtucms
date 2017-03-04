<?php
/**
 * @file
 * ma_digitalheritage.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function ma_digitalheritage_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::dh_original_year';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'dh_original_year';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'original_year',
  );
  $export['search_api@default_node_index::dh_original_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_category';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_category';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'category',
    'pretty_paths_taxonomy_pathauto' => 1,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'category',
  );
  $export['search_api@default_node_index::field_category'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_collection';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_collection';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_collection',
  );
  $export['search_api@default_node_index::field_collection'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_community_ref';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_community_ref';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'community',
  );
  $export['search_api@default_node_index::field_community_ref'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_dh_type';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_dh_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'type',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'dh_type',
  );
  $export['search_api@default_node_index::field_dh_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_media_asset:type';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_media_asset:type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'media-type',
  );
  $export['search_api@default_node_index::field_media_asset:type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_tags';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_tags';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'keywords',
    'pretty_paths_taxonomy_pathauto' => 1,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'tags',
  );
  $export['search_api@default_node_index::field_tags'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:dh_original_year';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'dh_original_year';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'search_api_ranges_ui_slider',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'glossary_az' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'glossary_az' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'glossary_az' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'show_all' => 1,
    'show_count' => 1,
    'name' => 'Original Year',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => '10',
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '<p>&nbsp;</p>

<table border="1" cellpadding="1" cellspacing="0" class="xdebug-error xe-notice" dir="ltr">
	<tbody>
		<tr>
			<th align="left" bgcolor="#f57900" colspan="5"><font size="1"><span>( ! )</span> Notice: PDO::__construct(): send of 95 bytes failed with errno=32 Broken pipe in /www/kivalina/includes/database/database.inc on line <i>321</i></font></th>
		</tr>
		<tr>
			<th align="left" bgcolor="#e9b96e" colspan="5"><font size="1">Call Stack</font></th>
		</tr>
		<tr>
			<th align="center" bgcolor="#eeeeec"><font size="1">#</font></th>
			<th align="left" bgcolor="#eeeeec"><font size="1">Time</font></th>
			<th align="left" bgcolor="#eeeeec"><font size="1">Memory</font></th>
			<th align="left" bgcolor="#eeeeec"><font size="1">Function</font></th>
			<th align="left" bgcolor="#eeeeec"><font size="1">Location</font></th>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">1</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0158</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">2507520</font></td>
			<td bgcolor="#eeeeec"><font size="1">_drupal_exception_handler( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/bootstrap.inc"><font size="1">.../bootstrap.inc<b>:</b>0</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">2</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0159</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">2509000</font></td>
			<td bgcolor="#eeeeec"><font size="1">_drupal_log_error( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/bootstrap.inc"><font size="1">.../bootstrap.inc<b>:</b>2594</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">3</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0159</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">2509064</font></td>
			<td bgcolor="#eeeeec"><font size="1">drupal_maintenance_theme( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/errors.inc"><font size="1">.../errors.inc<b>:</b>179</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">4</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0162</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">2543040</font></td>
			<td bgcolor="#eeeeec"><font size="1">_drupal_maintenance_theme( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/bootstrap.inc"><font size="1">.../bootstrap.inc<b>:</b>2857</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">5</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0278</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4336720</font></td>
			<td bgcolor="#eeeeec"><font size="1">list_themes( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/theme.maintenance.inc"><font size="1">.../theme.maintenance.inc<b>:</b>57</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">6</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0279</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4338216</font></td>
			<td bgcolor="#eeeeec"><font size="1">_system_rebuild_theme_data( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/theme.inc"><font size="1">.../theme.inc<b>:</b>798</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">7</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0452</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4349576</font></td>
			<td bgcolor="#eeeeec"><font size="1">module_invoke_all( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/modules/system/system.module"><font size="1">.../system.module<b>:</b>2511</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">8</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0452</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4350112</font></td>
			<td bgcolor="#eeeeec"><font size="1">module_implements( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/module.inc"><font size="1">.../module.inc<b>:</b>954</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">9</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0452</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4351256</font></td>
			<td bgcolor="#eeeeec"><font size="1">cache_get( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/module.inc"><font size="1">.../module.inc<b>:</b>754</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">10</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0452</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4351256</font></td>
			<td bgcolor="#eeeeec"><font size="1">DrupalDatabaseCache-&gt;get( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/cache.inc"><font size="1">.../cache.inc<b>:</b>57</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">11</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0452</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4351560</font></td>
			<td bgcolor="#eeeeec"><font size="1">DrupalDatabaseCache-&gt;getMultiple( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/cache.inc"><font size="1">.../cache.inc<b>:</b>330</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">12</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0452</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4351560</font></td>
			<td bgcolor="#eeeeec"><font size="1">db_escape_table( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/cache.inc"><font size="1">.../cache.inc<b>:</b>349</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">13</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0452</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4351560</font></td>
			<td bgcolor="#eeeeec"><font size="1">Database::getConnection( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/database.inc"><font size="1">.../database.inc<b>:</b>2626</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">14</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0453</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4351608</font></td>
			<td bgcolor="#eeeeec"><font size="1">Database::openConnection( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/database.inc"><font size="1">.../database.inc<b>:</b>1535</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">15</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0453</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4353984</font></td>
			<td bgcolor="#eeeeec"><font size="1">DatabaseConnection_mysql-&gt;__construct( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/database.inc"><font size="1">.../database.inc<b>:</b>1745</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">16</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0453</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4355800</font></td>
			<td bgcolor="#eeeeec"><font size="1">DatabaseConnection-&gt;__construct( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/mysql/database.inc"><font size="1">.../database.inc<b>:</b>66</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">17</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0453</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4357696</font></td>
			<td bgcolor="#eeeeec"><font size="1"><a href="http://www.php.net/PDO.construct" target="_new">__construct</a> ( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/database.inc"><font size="1">.../database.inc<b>:</b>321</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">18</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0455</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4368320</font></td>
			<td bgcolor="#eeeeec"><font size="1">_drupal_error_handler( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/database.inc"><font size="1">.../database.inc<b>:</b>321</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">19</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0455</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4368320</font></td>
			<td bgcolor="#eeeeec"><font size="1">_drupal_error_handler_real( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/bootstrap.inc"><font size="1">.../bootstrap.inc<b>:</b>2576</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">20</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0457</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4385680</font></td>
			<td bgcolor="#eeeeec"><font size="1">_drupal_log_error( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/errors.inc"><font size="1">.../errors.inc<b>:</b>75</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">21</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0457</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4385776</font></td>
			<td bgcolor="#eeeeec"><font size="1">watchdog( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/errors.inc"><font size="1">.../errors.inc<b>:</b>210</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">22</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0458</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4387864</font></td>
			<td bgcolor="#eeeeec"><font size="1">module_implements( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/bootstrap.inc"><font size="1">.../bootstrap.inc<b>:</b>1996</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">23</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0458</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4388056</font></td>
			<td bgcolor="#eeeeec"><font size="1">cache_get( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/module.inc"><font size="1">.../module.inc<b>:</b>754</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">24</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0458</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4388056</font></td>
			<td bgcolor="#eeeeec"><font size="1">DrupalDatabaseCache-&gt;get( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/cache.inc"><font size="1">.../cache.inc<b>:</b>57</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">25</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0458</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4388360</font></td>
			<td bgcolor="#eeeeec"><font size="1">DrupalDatabaseCache-&gt;getMultiple( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/cache.inc"><font size="1">.../cache.inc<b>:</b>330</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">26</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0458</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4388360</font></td>
			<td bgcolor="#eeeeec"><font size="1">db_escape_table( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/cache.inc"><font size="1">.../cache.inc<b>:</b>349</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">27</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0458</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4388360</font></td>
			<td bgcolor="#eeeeec"><font size="1">Database::getConnection( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/database.inc"><font size="1">.../database.inc<b>:</b>2626</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">28</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0458</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4388408</font></td>
			<td bgcolor="#eeeeec"><font size="1">Database::openConnection( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/database.inc"><font size="1">.../database.inc<b>:</b>1535</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">29</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0458</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4390784</font></td>
			<td bgcolor="#eeeeec"><font size="1">DatabaseConnection_mysql-&gt;__construct( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/database.inc"><font size="1">.../database.inc<b>:</b>1745</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">30</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0458</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4392600</font></td>
			<td bgcolor="#eeeeec"><font size="1">DatabaseConnection-&gt;__construct( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/mysql/database.inc"><font size="1">.../database.inc<b>:</b>66</font></td>
		</tr>
		<tr>
			<td align="center" bgcolor="#eeeeec"><font size="1">31</font></td>
			<td align="center" bgcolor="#eeeeec"><font size="1">0.0458</font></td>
			<td align="right" bgcolor="#eeeeec"><font size="1">4394496</font></td>
			<td bgcolor="#eeeeec"><font size="1"><a href="http://www.php.net/PDO.construct" target="_new">__construct</a> ( )</font></td>
			<td bgcolor="#eeeeec" title="/www/kivalina/includes/database/database.inc"><font size="1">.../database.inc<b>:</b>321</font></td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    'precision' => '0',
    'step' => '1',
  );
  $export['search_api@default_node_index:block:dh_original_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_category';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_category';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
  );
  $export['search_api@default_node_index:block:field_category'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_collection';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_collection';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
  );
  $export['search_api@default_node_index:block:field_collection'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_community_ref';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_community_ref';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
  );
  $export['search_api@default_node_index:block:field_community_ref'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_dh_type';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_dh_type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'glossary_az' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'glossary_az' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'glossary_az' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'show_all' => 1,
    'show_count' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@default_node_index:block:field_dh_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_media_asset:type';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_media_asset:type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'glossary_az' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'glossary_az' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'glossary_az' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'show_all' => 1,
    'show_count' => 1,
  );
  $export['search_api@default_node_index:block:field_media_asset:type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_tags';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_tags';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
  );
  $export['search_api@default_node_index:block:field_tags'] = $facet;

  return $export;
}
