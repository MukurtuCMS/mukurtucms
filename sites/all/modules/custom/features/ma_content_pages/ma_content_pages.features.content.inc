<?php
/**
 * @file
 * ma_content_pages.features.content.inc
 */

/**
 * Implements hook_content_defaults().
 */
function ma_content_pages_content_defaults() {
  $content = array();

  $content['ma_about'] = (object) array(
    'exported_path' => 'about',
    'link' => array(
      'menu_name' => 'main-menu',
      'link_path' => 'node-name/ma_about',
      'router_path' => 'node/%',
      'link_title' => 'About',
      'options' => array(
        'attributes' => array(),
      ),
      'module' => 'menu',
      'hidden' => 1,
      'external' => 0,
      'has_children' => 0,
      'expanded' => 0,
      'weight' => -39,
      'customized' => 1,
      'identifier' => 'main-menu:node-name/ma_about',
    ),
    'title' => 'About',
    'status' => 1,
    'promote' => 0,
    'sticky' => 0,
    'type' => 'page',
    'language' => 'und',
    'created' => 1341954255,
    'comment' => 2,
    'translate' => 0,
    'machine_name' => 'ma_about',
    'body' => array(
      'und' => array(
        0 => array(
          'value' => '<p>Mukurtu CMS provides:</p><ul><li>Local cultural protocols to provide granular access parameters for digital heritage content;</li><li>Flexible templates that adapt to various indigenous stakeholder needs;</li><li>Traditional knowledge fields customizable for curating content alongside standard Dublin Core metadata fields;</li><li>An innovative set of Traditional Knowledge licenses that work with traditional copyright and Creative Commons licenses to better serve Indigenous needs; and</li><li>A safe, secure, free and open source platform for managing digital cultural heritage materials online and offline</li></ul><p>Mukurtu is distributed under the terms of the <a href="http://www.gnu.org/copyleft/gpl.html">GNU General Public License (or "GPL")</a>, which means anyone is free to download it and share it with others. This open development model means that people are constantly working to make sure Mukurtu is a cutting-edge platform that supports the unique needs of indigenous libraries, archives and museums as they seek to preserve and share their digital heritage. Mukurtu encourages collaboration and innovation as we seek to offer respectful and responsible models for content management.</p><ul><li>Read our <a href="http://www.mukurtu.org/wiki/Manual:Contents">documentation</a></li><li>Check out the <a href="http://www.mukurtu.org/">Mukurtu website</a></li><li>Follow our <a href="http://townsendlab.berkeley.edu/mukurtu">development</a> and <a href="http://www.codifi.info/projects/mukurtu">project</a> blogs</li><li>And join the <a href="http://www.mukurtu.org/community.html">community!</a></li></ul>',
          'summary' => NULL,
          'format' => 'full_html',
          'safe_value' => '<p>Mukurtu CMS provides:</p>
<ul><li>Local cultural protocols to provide granular access parameters for digital heritage content;</li>
<li>Flexible templates that adapt to various indigenous stakeholder needs;</li>
<li>Traditional knowledge fields customizable for curating content alongside standard Dublin Core metadata fields;</li>
<li>An innovative set of Traditional Knowledge licenses that work with traditional copyright and Creative Commons licenses to better serve Indigenous needs; and</li>
<li>A safe, secure, free and open source platform for managing digital cultural heritage materials online and offline</li>
</ul><p>Mukurtu is distributed under the terms of the <a href="http://www.gnu.org/copyleft/gpl.html">GNU General Public License (or "GPL")</a>, which means anyone is free to download it and share it with others. This open development model means that people are constantly working to make sure Mukurtu is a cutting-edge platform that supports the unique needs of indigenous libraries, archives and museums as they seek to preserve and share their digital heritage. Mukurtu encourages collaboration and innovation as we seek to offer respectful and responsible models for content management.</p>
<ul><li>Read our <a href="http://www.mukurtu.org/wiki/Manual:Contents">documentation</a></li>
<li>Check out the <a href="http://www.mukurtu.org/">Mukurtu website</a></li>
<li>Follow our <a href="http://townsendlab.berkeley.edu/mukurtu">development</a> and <a href="http://www.codifi.info/projects/mukurtu">project</a> blogs</li>
<li>And join the <a href="http://www.mukurtu.org/community.html">community!</a></li>
</ul>',
          'safe_summary' => '',
        ),
      ),
    ),
  );

  $content['ma_access_denied'] = (object) array(
    'exported_path' => 'access-denied',
    'title' => 'Access Denied',
    'status' => 1,
    'promote' => 0,
    'sticky' => 0,
    'type' => 'page',
    'language' => 'en',
    'created' => 1343234100,
    'comment' => 1,
    'translate' => 0,
    'machine_name' => 'ma_access_denied',
    'body' => array(),
  );

  $content['ma_contact'] = (object) array(
    'exported_path' => 'contact-information',
    'link' => array(
      'menu_name' => 'main-menu',
      'link_path' => 'node-name/ma_contact',
      'router_path' => 'node/%',
      'link_title' => 'Contact',
      'options' => array(
        'attributes' => array(),
      ),
      'module' => 'menu',
      'hidden' => 1,
      'external' => 0,
      'has_children' => 0,
      'expanded' => 0,
      'weight' => -38,
      'customized' => 1,
      'identifier' => 'main-menu:node-name/ma_contact',
    ),
    'title' => 'Contact Information',
    'status' => 1,
    'promote' => 0,
    'sticky' => 0,
    'type' => 'page',
    'language' => 'und',
    'created' => 1341954309,
    'comment' => 1,
    'translate' => 0,
    'machine_name' => 'ma_contact',
    'body' => array(
      'und' => array(
        0 => array(
          'value' => '<p>Contact information.</p>',
          'summary' => NULL,
          'format' => 'full_html',
          'safe_value' => '<p>Contact information.</p>',
          'safe_summary' => '',
        ),
      ),
    ),
  );

  $content['ma_page_not_found'] = (object) array(
    'exported_path' => 'page-not-found',
    'title' => 'Page not found',
    'status' => 1,
    'promote' => 0,
    'sticky' => 0,
    'type' => 'page',
    'language' => 'en',
    'created' => 1343234179,
    'comment' => 1,
    'translate' => 0,
    'machine_name' => 'ma_page_not_found',
    'body' => array(),
  );

  $content['ma_resources'] = (object) array(
    'exported_path' => 'resources',
    'link' => array(
      'menu_name' => 'main-menu',
      'link_path' => 'node-name/ma_resources',
      'router_path' => 'node/%',
      'link_title' => 'Resources',
      'options' => array(
        'attributes' => array(),
      ),
      'module' => 'menu',
      'hidden' => 1,
      'external' => 0,
      'has_children' => 0,
      'expanded' => 0,
      'weight' => -40,
      'customized' => 1,
      'identifier' => 'main-menu:node-name/ma_resources',
    ),
    'title' => 'Resources',
    'status' => 1,
    'promote' => 0,
    'sticky' => 0,
    'type' => 'page',
    'language' => 'und',
    'created' => 1339716915,
    'comment' => 1,
    'translate' => 0,
    'machine_name' => 'ma_resources',
    'body' => array(
      'und' => array(
        0 => array(
          'value' => 'Resources page.',
          'summary' => NULL,
          'format' => 'full_html',
          'safe_value' => '<p>Resources page.</p>',
          'safe_summary' => '',
        ),
      ),
    ),
  );

  $content['page_welcome'] = (object) array(
    'exported_path' => 'welcome',
    'title' => 'Welcome',
    'status' => 1,
    'promote' => 1,
    'sticky' => 0,
    'type' => 'page',
    'language' => 'und',
    'created' => 1307037966,
    'comment' => 1,
    'translate' => 0,
    'machine_name' => 'page_welcome',
    'body' => array(
      'und' => array(
        0 => array(
          'value' => '<p>Mukurtu CMS provides:</p><ul><li>Local cultural protocols to provide granular access parameters for digital heritage content;</li><li>Flexible templates that adapt to various indigenous stakeholder needs;</li><li>Traditional knowledge fields customizable for curating content alongside standard Dublin Core metadata fields;</li><li>An innovative set of Traditional Knowledge licenses that work with traditional copyright and Creative Commons licenses to better serve Indigenous needs; and</li><li>A safe, secure, free and open source platform for managing digital cultural heritage materials online and offline</li></ul><p>Mukurtu is distributed under the terms of the <a href="http://www.gnu.org/copyleft/gpl.html">GNU General Public License (or "GPL")</a>, which means anyone is free to download it and share it with others. This open development model means that people are constantly working to make sure Mukurtu is a cutting-edge platform that supports the unique needs of indigenous libraries, archives and museums as they seek to preserve and share their digital heritage. Mukurtu encourages collaboration and innovation as we seek to offer respectful and responsible models for content management.</p><ul><li>Read our <a href="http://www.mukurtu.org/wiki/Manual:Contents">documentation</a></li><li>Check out the <a href="http://www.mukurtu.org/">Mukurtu website</a></li><li>Follow our <a href="http://townsendlab.berkeley.edu/mukurtu">development</a> and <a href="http://www.codifi.info/projects/mukurtu">project</a> blogs</li><li>And join the <a href="http://www.mukurtu.org/community.html">community!</a></li></ul>',
          'summary' => 'Mukurtu (MOOK-oo-too) is a  free and open source community content management system that provides international standards-based tools adaptable to the local cultural protocols and intellectual property systems of indigenous communities, libraries, archives, and museums. It is a flexible platform that allows users to manage and share digital cultural heritage through easy to follow Mukurtu Core steps and localized cultural protocols. So, get started creating your own digital heritage items and collections. If you need help while you are setting up your instance of Mukurtu CMS contact us at: info@mukurtu.org.',
          'format' => 'full_html',
          'safe_value' => '<p>Mukurtu CMS provides:</p>
<ul><li>Local cultural protocols to provide granular access parameters for digital heritage content;</li>
<li>Flexible templates that adapt to various indigenous stakeholder needs;</li>
<li>Traditional knowledge fields customizable for curating content alongside standard Dublin Core metadata fields;</li>
<li>An innovative set of Traditional Knowledge licenses that work with traditional copyright and Creative Commons licenses to better serve Indigenous needs; and</li>
<li>A safe, secure, free and open source platform for managing digital cultural heritage materials online and offline</li>
</ul><p>Mukurtu is distributed under the terms of the <a href="http://www.gnu.org/copyleft/gpl.html">GNU General Public License (or "GPL")</a>, which means anyone is free to download it and share it with others. This open development model means that people are constantly working to make sure Mukurtu is a cutting-edge platform that supports the unique needs of indigenous libraries, archives and museums as they seek to preserve and share their digital heritage. Mukurtu encourages collaboration and innovation as we seek to offer respectful and responsible models for content management.</p>
<ul><li>Read our <a href="http://www.mukurtu.org/wiki/Manual:Contents">documentation</a></li>
<li>Check out the <a href="http://www.mukurtu.org/">Mukurtu website</a></li>
<li>Follow our <a href="http://townsendlab.berkeley.edu/mukurtu">development</a> and <a href="http://www.codifi.info/projects/mukurtu">project</a> blogs</li>
<li>And join the <a href="http://www.mukurtu.org/community.html">community!</a></li>
</ul>',
          'safe_summary' => '<p>Mukurtu (MOOK-oo-too) is a  free and open source community content management system that provides international standards-based tools adaptable to the local cultural protocols and intellectual property systems of indigenous communities, libraries, archives, and museums. It is a flexible platform that allows users to manage and share digital cultural heritage through easy to follow Mukurtu Core steps and localized cultural protocols. So, get started creating your own digital heritage items and collections. If you need help while you are setting up your instance of Mukurtu CMS contact us at: <a href="mailto:info@mukurtu.org">info@mukurtu.org</a>.</p>',
        ),
      ),
    ),
  );

return $content;
}
