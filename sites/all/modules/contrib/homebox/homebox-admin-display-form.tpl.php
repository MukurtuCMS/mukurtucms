<?php

/**
 * @file
 * homebox-admin-display-form.tpl.php
 * Default theme implementation to configure homebox blocks.
 */
?>
<?php
  // Add table javascript.
  drupal_add_js('misc/tableheader.js');
  drupal_add_js(drupal_get_path('module', 'block') .'/block.js');
  foreach ($block_regions as $region => $title) {
    drupal_add_tabledrag('blocks', 'match', 'sibling', 'block-region-select', 'block-region-'. $region, NULL, FALSE);
    drupal_add_tabledrag('blocks', 'order', 'sibling', 'block-weight', 'block-weight-'. $region);
  }
?>
<table id="blocks" class="sticky-enabled">
  <thead>
    <tr>
      <th><?php print t('Block'); ?></th>
      <th><?php print t('Region'); ?></th>
      <th><?php print t('Custom title'); ?></th>
      <th><?php print t('Weight'); ?></th>
      <th><?php print t('Visible'); ?></th>
      <th><?php print t('Open'); ?></th>
      <th><?php print t('Movable'); ?></th>
      <th><?php print t('Closable'); ?></th>
    </tr>
  </thead>
  <tbody>
    <?php $row = 0; ?>
    <?php foreach ($block_regions as $region => $title): ?>
      <tr class="region region-<?php print $region ?>">
        <td colspan="7" class="region"><?php print $title; ?></td>
      </tr>
      <tr class="region-message region-<?php print $region?>-message <?php print empty($block_listing[$region]) ? 'region-empty' : 'region-populated'; ?>">
        <td colspan="7"><em><?php print t('No blocks in this column'); ?></em></td>
      </tr>
      <?php foreach ($block_listing[$region] as $delta => $data): ?>
      <tr class="draggable <?php print $row % 2 == 0 ? 'odd' : 'even'; ?><?php print $data->row_class ? ' '. $data->row_class : ''; ?>">
        <td class="block">
          <?php print $data->block_title; ?>
        </td>
        <td><?php print $data->region_select; ?></td>
        <td><?php print $data->title; ?></td>
        <td><?php print $data->weight_select; ?> <?php print $data->bid ?></td>
        <td><?php print $data->status; ?></td>
        <td><?php print $data->open; ?></td>
        <td><?php print $data->movable; ?></td>
        <td><?php print $data->closable; ?></td>
      </tr>
      <?php $row++; ?>
      <?php endforeach; ?>
    <?php endforeach; ?>
  </tbody>
</table>

<?php print $form_submit; ?>
<!-- End Homebox admin form layout -->
