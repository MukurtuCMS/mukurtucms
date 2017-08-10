<?php
/**
 * @file
 * Default theme implementation to display bar for a single choice in a poll.
 *
 * Variables available:
 * - $title: The title of the poll.
 * - $votes: The number of votes for this choice
 * - $total_votes: The number of votes for this choice
 * - $percentage: The percentage of votes for this choice.
 * - $vote: The choice number of the current user's vote.
 * - $voted: Set to TRUE if the user voted for this choice.
 *
 * @see template_preprocess_poll_bar()
 *
 * @ingroup templates
 */
?>
<div class="text"><?php print $title; ?></div>
<div class="progress">
  <div class="progress-bar" role="progressbar" aria-valuenow="<?php print $percentage; ?>" aria-valuemin="0" aria-valuemax="100" style="width: <?php print $percentage; ?>%;">
    <?php print $percentage; ?>%
  </div>
</div>
