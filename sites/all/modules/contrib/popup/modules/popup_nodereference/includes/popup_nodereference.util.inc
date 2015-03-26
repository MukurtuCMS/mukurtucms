<?php



/* Renders a series of node bodies */
function _popup_nodereference_render_group($nids, $attributes){

  module_load_include('inc', 'popup', 'includes/popup.api');
  
	$rendered = '';

	foreach ($nids as $nid) {

		$node_attribs = $attributes;
		$node_attribs['node'] = $nid;
	
		$rendered .= _popup_node($node_attribs, 'body');

  }
  
  return $rendered;
}