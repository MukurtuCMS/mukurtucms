<?php

/**
 * @file
 * Builds placeholder replacement tokens for atom-related data.
 */

/**
 * Implements hook_token_info().
 */
function scald_token_info() {
  $type = array(
    'name' => t('Atoms'),
    'description' => t('Tokens related to atoms.'),
    'needs-data' => 'atom',
  );

  $atom['title'] = array(
    'name' => t('Title'),
    'description' => t('The title of the atom.'),
  );
  $atom['author'] = array(
    'name' => t('Author'),
    'description' => t('The author, or publisher if there is no author, of the atom.'),
  );

  return array(
    'types' => array('atom' => $type),
    'tokens' => array('atom' => $atom),
  );
}

/**
 * Implements hook_tokens().
 */
function scald_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $url_options = array('absolute' => TRUE);
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = NULL;
  }
  $sanitize = !empty($options['sanitize']);

  $replacements = array();

  if ($type == 'atom' && !empty($data['atom'])) {
    $atom = $data['atom'];
    // We will use $atom->rendered, so if is not rendered yet, we need to do it
    // now.
    if (empty($atom->rendered)) {
      scald_render($atom, 'title');
    }

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'title':
          $replacements[$original] = $atom->rendered->title;
          break;

        case 'author':
          $authors = array();
          if (!empty($atom->rendered->authors)) {
            foreach ($atom->rendered->authors as $author) {
              $authors[] = $sanitize ? $author->name : $author->link;
            }
          }
          else {
            $authors[] = $atom->rendered->publisher[$sanitize ? 'name' : 'link'];
          }
          $replacements[$original] = implode(', ', $authors);
          break;
      }
    }
  }

  return $replacements;
}
