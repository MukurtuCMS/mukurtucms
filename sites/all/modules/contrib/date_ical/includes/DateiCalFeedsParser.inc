<?php
/**
 * @file
 * DateiCalFeedsParser is Date iCal's Feeds parser plugin.
 */

class DateiCalFeedsParser extends FeedsParser {

  /**
   * Implements FeedsParser::getMappingSources().
   */
  public function getMappingSources() {
    return parent::getMappingSources() + self::getiCalMappingSources();
  }

  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $library = libraries_load('iCalcreator');
    if (!$library['loaded']) {
      throw new DateIcalException(t('Unable to load the iCalcreator library. Please ensure that it is properly installed.'));
    }
    $state = $source->state(FEEDS_PARSE);

    // Read the iCal feed into memory.
    $ical_feed_contents = $fetcher_result->getRaw();

    // Parse the feed into an iCalcreator vcalendar object.
    $calendar = new vcalendar();
    if ($calendar->parse($ical_feed_contents) === FALSE) {
      $plugin = $source->importer->config['fetcher']['plugin_key'];
      $url = $source->config[$plugin]['source'];
      throw new DateIcalException(t('Parsing the data from %url failed. Please ensure that this URL leads to a valid iCal feed.', array('%url' => $url)));
    }

    // Total hack to get around iCalcreator's mistreatment of UID "0".
    if (empty($calendar->components[0]->uid) || empty($calendar->components[0]->uid['value'])) {
      $calendar->components[0]->uid = array('value' => 'zero', 'params' => NULL);
    }

    // Allow modules to alter the vcalendar object before we interpret it.
    $context = array(
      'source' => $source,
      'fetcher_result' => $fetcher_result,
    );
    drupal_alter('date_ical_import_vcalendar', $calendar, $context);

    // We've got a vcalendar object created from the feed data. Now we need to
    // convert that vcalendar into an array of Feeds-compatible data arrays.
    // ParserVcalendar->parse() does that.
    require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'date_ical') . '/libraries/ParserVcalendar.inc';
    $parser = new ParserVcalendar($calendar, $source, $fetcher_result, $source->getConfigFor($this));

    // Using the stored progress pointer (or 0 if it's not set),
    // determine which section of the feed to parse, then parse it.
    $offset = isset($state->pointer) ? $state->pointer : 0;
    $limit = $source->importer->getLimit();
    $rows = $parser->parse($offset, $limit);

    // Report progress.
    $state->total = $parser->getTotalComponents();
    // We need to add 1 to the index of the last parsed componenent so that
    // the subsequent batch starts on the first unparsed component.
    $state->pointer = $parser->getLastComponentParsed() + 1;
    $state->progress($state->total, $state->pointer);

    return new FeedsParserResult($rows);
  }

  /**
   * Defines the default configuration settings for an actual import.
   */
  public function sourceDefaults() {
    return array(
      'indefinite_count' => $this->config['indefinite_count'],
      'until_not_utc' => $this->config['until_not_utc'],
      'skip_days' => $this->config['skip_days'],
    );
  }

  /**
   * Defines the default settings shown on the configuration form.
   */
  public function configDefaults() {
    return array(
      'indefinite_count' => '52',
      'indefinite_message_display' => TRUE,
      'until_not_utc' => FALSE,
      'skip_days' => NULL,
    );
  }

  /**
   * Builds the configuration form.
   */
  public function configForm(&$form_state) {
    $form = array();
    $form['indefinite_count'] = array(
      '#title' => t('Indefinite COUNT'),
      '#type' => 'select',
      '#options' => array(
        '31' => '31',
        '52' => '52',
        '90' => '90',
        '365' => '365',
      ),
      '#description' => t('Indefinitely repeating events are not supported. The repeat count will instead be set to this number.'),
      '#default_value' => $this->config['indefinite_count'],
    );
    $form['indefinite_message_display'] = array(
      '#title' => t('Display message when RRULE is missing COUNT'),
      '#type' => 'checkbox',
      '#default_value' => $this->config['indefinite_message_display'],
      '#description' => t('Display a message when an indefinitely repeating rule is adjusted by the "Indefinite COUNT" setting above.'),
    );
    $form['until_not_utc'] = array(
      '#title' => t('RRULE UNTILs are not in UTC'),
      '#type' => 'checkbox',
      '#description' => t('Enable this setting if your reccuring events are not repeating the correct number of times. ' .
          'The iCal spec requires that the UNTIL value in an RRULE almost always be specified in UTC, but some iCal feed creators fail to follow that rule ' .
          '(the UNTIL values in those feeds\' RRULEs don\'t end is "Z"). This causes the UNTIL value to be off by several hours, ' .
          'which can cause the repeat calculator to miss or add repeats.'),
      '#default_value' => $this->config['until_not_utc'],
    );
    $form['skip_days'] = array(
      '#title' => t('Skip events more than X days old'),
      '#type' => 'textfield',
      '#size' => 5,
      '#description' => t('Set this value to any positive integer (or 0) to skip events which ended more than that many days before the import. ' .
        'Leave it blank to import all events.'),
      '#default_value' => $this->config['skip_days'],
    );
    return $form;
  }

  /**
   * Validation handler for configForm.
   */
  public function configFormValidate(&$source_config) {
    if (!preg_match('/^\d+$/', $source_config['skip_days']) && $source_config['skip_days'] !== '') {
      form_set_error('skip_days', 'You must enter a positive integer.');
    }
    if ($source_config['skip_days'] === '') {
      $source_config['skip_days'] = NULL;
    }
  }

  /**
   * Creates the list of mapping sources offered by DateiCalFeedsParser.
   */
  public static function getiCalMappingSources() {
    $sources = array();
    $sources['SUMMARY'] = array(
      'name' => t('Summary/Title'),
      'description' => t('The SUMMARY property. A short summary (usually the title) of the event.
        A title is required for every node, so you need to include this source and have it mapped to the node title, except under unusual circumstances.'
      ),
      'date_ical_parse_handler' => 'parseTextProperty',
    );
    $sources['COMMENT'] = array(
      'name' => t('Comment'),
      'description' => t('The COMMENT property. A text comment is allowed on most components.'),
      'date_ical_parse_handler' => 'parseTextProperty',
    );
    $sources['DESCRIPTION'] = array(
      'name' => t('Description'),
      'description' => t('The DESCRIPTION property. A more complete description of the event than what is provided by the Summary.'),
      'date_ical_parse_handler' => 'parseTextProperty',
    );
    $sources['DTSTART'] = array(
      'name' => t('Date: Start'),
      'description' => t('The DTSTART property. The start time of each event in the feed.'),
      'date_ical_parse_handler' => 'parseDateTimeProperty',
    );
    $sources['DTEND'] = array(
      'name' => t('Date: End'),
      'description' => t('THE DTEND or DURATION property. The end time (or duration) of each event in the feed.'),
      'date_ical_parse_handler' => 'parseDateTimeProperty',
    );
    $sources['RRULE'] = array(
      'name' => t('Date: Repeat Rule'),
      'description' => t('The RRULE property. Describes when and how often this event should repeat.
        The date field for the target node must be configured to support repeating dates, using the Date Repeat Field module (a submodule of Date).'),
      'date_ical_parse_handler' => 'parseRepeatProperty',
    );
    $sources['UID'] = array(
      'name' => 'UID',
      'description' => t('The UID property. Each event must have a UID if you wish for the import process to be able to update previously-imported nodes.
        If used, this field MUST be set to Unique.'),
      'date_ical_parse_handler' => 'parseTextProperty',
    );
    $sources['URL'] = array(
      'name' => 'URL',
      'description' => t('The URL property. Some feeds specify a URL for the event using this property.'),
      'date_ical_parse_handler' => 'parseTextProperty',
    );
    $sources['LOCATION'] = array(
      'name' => t('Location'),
      'description' => t('The LOCATION property. Can be mapped to a text field, or the title of a referenced node.'),
      'date_ical_parse_handler' => 'parseTextProperty',
    );
    $sources['LOCATION:ALTREP'] = array(
      'name' => t('Location: ALTREP'),
      'description' => t('The ALTREP value of the LOCATION property. Additional location information, usually a URL to a page with more info.'),
      'date_ical_parse_handler' => 'parsePropertyParameter',
    );
    $sources['CATEGORIES'] = array(
      'name' => t('Categories'),
      'description' => t('The CATEGORIES property. Catagories that describe the event, which can be imported into taxonomy terms.'),
      'date_ical_parse_handler' => 'parseMultivalueProperty',
    );

    // Allow other modules to add custom source fields.
    drupal_alter('date_ical_mapping_sources', $sources);

    return $sources;
  }
}
