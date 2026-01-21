<?php
/**
 * Implementation of hook_drush_command().
 */
function exif_drush_command() {
	$items['exif-list'] = array(
		'description' => 'list content type where exif is enabled.',
	);
	$items['exif-update'] = array(
		'description' => 'Update all nodes where exif is enabled.',
		'arguments' => array(
			'type' => 'Optional. The content-type to update (all other content-type will be ignored).',
	),
	);

	return $items;
};


/**
 * Implementation of hook_drush_help().
 */
function exif_drush_help($section) {
	switch ($section) {
		case 'drush:exif-list':
			return dt('list content type where exif is enabled.');
		case 'drush:exif-update':
			return dt('Update all nodes where exif is enabled.');
	}
}


function __drush_exif_list_active_types() {
	$types = array();
	//fill up array with checked nodetypes
	foreach (variable_get('exif_nodetypes', array()) as $type) {
		if ($type != "0" ) {
			$types[] = array(
				'entity' => 'node',
				'type' => $type
			);
		}
	}
	foreach (variable_get('exif_mediatypes', array()) as $type) {
		if ($type != "0" ) {
			$types[] = array(
				'entity' => 'file',
				'type' => $type
			);
		}
	}
	return $types;
}
/**
 * Drush callback;
 */
function drush_exif_list() {
	$types = __drush_exif_list_active_types();
	drush_log(t('listing %count content types.', array('%count' =>  count($types))),'ok');
	foreach ( $types as $type) {
		drush_log(t('- %entity, %type.', array('%entity' => $type['entity'], '%type' => $type['type'])), 'ok');
	}
}

/**
 * Drush callback;
 */
function drush_exif_update($type = '') {
	$types = __drush_exif_list_active_types();
	drush_log(dt('Need to update %count content type.', array('%count' =>  count($types))));
	foreach ( $types as $type) {
		if ($type['entity']=='node') {
			$count = __drush_exif_node_update($type['type']);
		} else if ($type['entity']=='file') {
			$count = __drush_exif_file_update($type['type']);
		}

	}
}

function __drush_exif_node_update($type = '') {
	$query = "SELECT n.nid FROM {node} n WHERE n.type = :type";
	$result =  db_query($query, array(':type' => $type));
	$count = 0;
	foreach ($result as $record) {
		// Load the node object from the database
		$node = node_load($record->nid);
		// Resave the node to make exif changes.
		node_save($node);
		$count++;
	}
	drush_log(dt('Updated %count %type nodes.', array('%count' => $count, '%type' => $type)),"ok");
	return $count;
}

function __drush_exif_file_update($type = '') {
	$query = "SELECT n.fid FROM {file_managed} n WHERE n.type = :type";
	$result =  db_query($query, array(':type' => $type));
	$count = 0;
	foreach ($result as $record) {
		// Load the node object from the database
		$file = file_load($record->fid);
		// Resave the node to make exif changes.
		file_save($file);
		$count++;
	}
	drush_log(dt('Updated %count %type files.', array('%count' => $count, '%type' => $type)),"ok");
	return $count;
}