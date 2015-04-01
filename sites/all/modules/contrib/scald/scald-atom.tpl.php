<?php

/**
 * @file
 * Default theme implementation to display a scald_atom.
 *
 * Available variables:
 * - $content: An array of items for the content of the scald_atom.
 *
 * Other variables:
 * - ?
 *
 * @see template_preprocess()
 * @see template_process()
 *
 * @ingroup themeable
 */

print render($content);
