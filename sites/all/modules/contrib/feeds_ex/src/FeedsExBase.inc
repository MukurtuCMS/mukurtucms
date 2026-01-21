<?php

/**
 * @file
 * Contains FeedsExBase.
 */

/**
 * The Feeds extensible parser.
 */
abstract class FeedsExBase extends FeedsParser {

  /**
   * The object used to display messages to the user.
   *
   * @var FeedsExMessengerInterface
   */
  protected $messenger;

  /**
   * The class used as the text encoder.
   *
   * @var string
   */
  protected $encoderClass = 'FeedsExTextEncoder';

  /**
   * The encoder used to convert encodings.
   *
   * @var FeedsExEncoderInterface
   */
  protected $encoder;

  /**
   * Returns rows to be parsed.
   *
   * @param FeedsSource $source
   *   Source information.
   * @param FeedsFetcherResult $fetcher_result
   *   The result returned by the fetcher.
   *
   * @return array|Traversable
   *   Some iterable that returns rows.
   */
  abstract protected function executeContext(FeedsSource $source, FeedsFetcherResult $fetcher_result);

  /**
   * Executes a single source expression.
   *
   * @param string $machine_name
   *   The source machine name being executed.
   * @param string $expression
   *   The expression to execute.
   * @param mixed $row
   *   The row to execute on.
   *
   * @return scalar|[]scalar
   *   Either a scalar, or a list of scalars. If null, the value will be
   *   ignored.
   */
  abstract protected function executeSourceExpression($machine_name, $expression, $row);

  /**
   * Validates an expression.
   *
   * @param string &$expression
   *   The expression to validate.
   *
   * @return string|null
   *   Return the error string, or null if validation was passed.
   */
  abstract protected function validateExpression(&$expression);

  /**
   * Returns the errors after parsing.
   *
   * @return array
   *   A structured array array with keys:
   *   - message: The error message.
   *   - variables: The variables for the message.
   *   - severity: The severity of the message.
   *
   * @see watchdog()
   */
  abstract protected function getErrors();

  /**
   * Allows subclasses to prepare for parsing.
   *
   * @param FeedsSource $source
   *   The feed source.
   * @param FeedsFetcherResult $fetcher_result
   *   The result of the fetching stage.
   */
  protected function setUp(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
  }

  /**
   * Allows subclasses to cleanup after parsing.
   *
   * @param FeedsSource $source
   *   The feed source.
   * @param FeedsParserResult $parser_result
   *   The result of parsing.
   */
  protected function cleanUp(FeedsSource $source, FeedsParserResult $parser_result) {
  }

  /**
   * Starts internal error handling.
   *
   * Subclasses can override this to being error handling.
   */
  protected function startErrorHandling() {
  }

  /**
   * Stops internal error handling.
   *
   * Subclasses can override this to end error handling.
   */
  protected function stopErrorHandling() {
  }

  /**
   * Loads the necessary library.
   *
   * Subclasses can override this to load the necessary library. It will be
   * called automatically.
   *
   * @throws RuntimeException
   *   Thrown if the library does not exist.
   */
  protected function loadLibrary() {
  }

  /**
   * Returns whether or not this parser uses a context query.
   *
   * Sub-classes can return false here if they don't require a user-configured
   * context query.
   *
   * @return bool
   *   True if the parser uses a context query and false if not.
   */
  protected function hasConfigurableContext() {
    return TRUE;
  }

  /**
   * Reuturns the list of table headers.
   *
   * @return array
   *   A list of header names keyed by the form keys.
   */
  protected function configFormTableHeader() {
    return array();
  }

  /**
   * Returns a form element for a specific column.
   *
   * @param array &$form_state
   *   The current form state.
   * @param array $values
   *   The individual source item values.
   * @param string $column
   *   The name of the column.
   * @param string $machine_name
   *   The machine name of the source.
   *
   * @return array
   *   A single form element.
   */
  protected function configFormTableColumn(array &$form_state, array $values, $column, $machine_name) {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $this->loadLibrary();
    $this->startErrorHandling();
    $result = new FeedsParserResult();
    // Set link.
    $fetcher_config = $source->getConfigFor($source->importer->fetcher);
    $result->link = is_string($fetcher_config['source']) ? $fetcher_config['source'] : '';

    try {
      $this->setUp($source, $fetcher_result);
      $this->parseItems($source, $fetcher_result, $result);
      $this->cleanUp($source, $result);
    }
    catch (FeedsExEmptyException $e) {
      // The feed is empty.
      $this->getMessenger()->setMessage(t('The feed is empty.'), 'warning', FALSE);
    }
    catch (Exception $exception) {
      // Do nothing. Store for later.
    }

    // Display and log errors.
    $errors = $this->getErrors();
    $this->printErrors($errors, $this->config['display_errors'] ? WATCHDOG_DEBUG : WATCHDOG_ERROR);
    $this->logErrors($source, $errors);

    $this->stopErrorHandling();

    if (isset($exception)) {
      throw $exception;
    }

    return $result;
  }

  /**
   * Performs the actual parsing.
   *
   * @param FeedsSource $source
   *   The feed source.
   * @param FeedsFetcherResult $fetcher_result
   *   The fetcher result.
   * @param FeedsParserResult $result
   *   The parser result object to populate.
   */
  protected function parseItems(FeedsSource $source, FeedsFetcherResult $fetcher_result, FeedsParserResult $result) {
    $expressions = $this->prepareExpressions();
    $variable_map = $this->prepareVariables($expressions);

    foreach ($this->executeContext($source, $fetcher_result) as $row) {
      if ($item = $this->executeSources($row, $expressions, $variable_map)) {
        $result->items[] = $item;
      }
    }
  }

  /**
   * Prepares the expressions for parsing.
   *
   * At this point we just remove empty expressions.
   *
   * @return array
   *   A map of machine name to expression.
   */
  protected function prepareExpressions() {
    $expressions = array();
    foreach ($this->config['sources'] as $machine_name => $source) {
      if (strlen($source['value'])) {
        $expressions[$machine_name] = $source['value'];
      }
    }

    return $expressions;
  }

  /**
   * Prepares the variable map used to substitution.
   *
   * @param array $expressions
   *   The expressions being parsed.
   *
   * @return array
   *   A map of machine name to variable name.
   */
  protected function prepareVariables(array $expressions) {
    $variable_map = array();
    foreach ($expressions as $machine_name => $expression) {
      $variable_map[$machine_name] = '$' . $machine_name;
    }
    return $variable_map;
  }

  /**
   * Executes the source expressions.
   *
   * @param mixed $row
   *   A single item returned from the context expression.
   * @param array $expressions
   *   A map of machine name to expression.
   * @param array $variable_map
   *   A map of machine name to varible name.
   *
   * @return array
   *   The fully-parsed item array.
   */
  protected function executeSources($row, array $expressions, array $variable_map) {
    $item = array();
    $variables = array();

    foreach ($expressions as $machine_name => $expression) {
      // Variable substitution.
      $expression = strtr($expression, $variables);

      $result = $this->executeSourceExpression($machine_name, $expression, $row);

      if (!empty($this->config['sources'][$machine_name]['debug'])) {
        $this->debug($result, $machine_name);
      }

      if ($result === NULL) {
        $variables[$variable_map[$machine_name]] = '';
        continue;
      }

      $item[$machine_name] = $result;
      $variables[$variable_map[$machine_name]] = is_array($result) ? reset($result) : $result;
    }

    return $item;
  }

  /**
   * Prints errors to the screen.
   *
   * @param array $errors
   *   A list of errors as returned by stopErrorHandling().
   * @param int $severity
   *   (optional) Limit to only errors of the specified severity. Defaults to
   *   WATCHDOG_ERROR.
   *
   * @see watchdog()
   */
  protected function printErrors(array $errors, $severity = WATCHDOG_ERROR) {
    foreach ($errors as $error) {
      if ($error['severity'] > $severity) {
        continue;
      }
      $this->getMessenger()->setMessage(t($error['message'], $error['variables']), $error['severity'] <= WATCHDOG_ERROR ? 'error' : 'warning', FALSE);
    }
  }

  /**
   * Logs errors.
   *
   * @param FeedsSource $source
   *   The feed source being importerd.
   * @param array $errors
   *   A list of errors as returned by stopErrorHandling().
   * @param int $severity
   *   (optional) Limit to only errors of the specified severity. Defaults to
   *   WATCHDOG_ERROR.
   *
   * @see watchdog()
   */
  protected function logErrors(FeedsSource $source, array $errors, $severity = WATCHDOG_ERROR) {
    foreach ($errors as $error) {
      if ($error['severity'] > $severity) {
        continue;
      }

      $source->log('feeds_ex', $error['message'], $error['variables'], $error['severity']);
    }
  }

  /**
   * Prepares the raw string for parsing.
   *
   * @param FeedsFetcherResult $fetcher_result
   *   The fetcher result.
   *
   * @return string
   *   The prepared raw string.
   */
  protected function prepareRaw(FeedsFetcherResult $fetcher_result) {
    $raw = trim($this->getEncoder()->convertEncoding($fetcher_result->getRaw()));

    if (!strlen($raw)) {
      throw new FeedsExEmptyException();
    }

    return $raw;
  }

  /**
   * Renders our debug messages into a list.
   *
   * @param mixed $data
   *   The result of an expression. Either a scalar or a list of scalars.
   * @param string $machine_name
   *   The source key that produced this query.
   */
  protected function debug($data, $machine_name) {
    $name = $machine_name;
    if ($this->config['sources'][$machine_name]['name']) {
      $name = $this->config['sources'][$machine_name]['name'];
    }

    $output = '<strong>' . $name . ':</strong>';
    $data = is_array($data) ? $data : array($data);
    foreach ($data as $key => $value) {
      $data[$key] = check_plain($value);
    }
    $output .= theme('item_list', array('items' => $data));
    $this->getMessenger()->setMessage($output);
  }

  /**
   * {@inheritdoc}
   */
  public function getMappingSources() {
    return parent::getMappingSources() + $this->config['sources'];
  }

  /**
   * {@inheritdoc}
   */
  public function configDefaults() {
    return array(
      'sources' => array(),
      'context' => array(
        'value' => '',
      ),
      'display_errors' => FALSE,
      'source_encoding' => array('auto'),
      'debug_mode' => FALSE,
    );
  }

  /**
   * {@inheritdoc}
   */
  public function configForm(&$form_state) {
    $form = array(
      '#tree' => TRUE,
      '#theme' => 'feeds_ex_configuration_table',
      '#prefix' => '<div id="feeds-ex-configuration-wrapper">',
      '#suffix' => '</div>',
    );

    if ($this->hasConfigurableContext()) {
      $form['context']['name'] = array(
        '#type' => 'markup',
        '#markup' => t('Context'),
      );
      $form['context']['value'] = array(
        '#type' => 'textfield',
        '#title' => t('Context value'),
        '#title_display' => 'invisible',
        '#default_value' => $this->config['context']['value'],
        '#size' => 50,
        '#required' => TRUE,
        // We're hiding the title, so add a little hint.
        '#description' => '<span class="form-required">*</span>',
        '#attributes' => array('class' => array('feeds-ex-context-value')),
        '#maxlength' => 1024,
      );
    }

    $form['sources'] = array(
      '#id' => 'feeds-ex-source-table',
    );

    $max_weight = 0;
    foreach ($this->config['sources'] as $machine_name => $source) {
      $form['sources'][$machine_name]['name'] = array(
        '#type' => 'textfield',
        '#title' => t('Name'),
        '#title_display' => 'invisible',
        '#default_value' => $source['name'],
        '#size' => 20,
      );
      $form['sources'][$machine_name]['machine_name'] = array(
        '#title' => t('Machine name'),
        '#title_display' => 'invisible',
        '#markup' => $machine_name,
      );
      $form['sources'][$machine_name]['value'] = array(
        '#type' => 'textfield',
        '#title' => t('Value'),
        '#title_display' => 'invisible',
        '#default_value' => $source['value'],
        '#size' => 50,
        '#maxlength' => 1024,
      );

      foreach ($this->configFormTableHeader() as $column => $name) {
        $form['sources'][$machine_name][$column] = $this->configFormTableColumn($form_state, $source, $column, $machine_name);
      }

      $form['sources'][$machine_name]['debug'] = array(
        '#type' => 'checkbox',
        '#title' => t('Debug'),
        '#title_display' => 'invisible',
        '#default_value' => $source['debug'],
      );
      $form['sources'][$machine_name]['remove'] = array(
        '#type' => 'checkbox',
        '#title' => t('Remove'),
        '#title_display' => 'invisible',
      );
      $form['sources'][$machine_name]['weight'] = array(
        '#type' => 'textfield',
        '#default_value' => $source['weight'],
        '#size' => 3,
        '#attributes' => array('class' => array('feeds-ex-source-weight')),
      );
      $max_weight = $source['weight'];
    }

    $form['add']['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Add new source'),
      '#id' => 'edit-sources-add-name',
      '#description' => t('Name'),
      '#size' => 20,
    );
    $form['add']['machine_name'] = array(
      '#title' => t('Machine name'),
      '#title_display' => 'invisible',
      '#type' => 'machine_name',
      '#machine_name' => array(
        'exists' => 'feeds_ex_source_exists',
        'source' => array('add', 'name'),
        'standalone' => TRUE,
        'label' => '',
      ),
      '#field_prefix' => '<span dir="ltr">',
      '#field_suffix' => '</span>&lrm;',
      '#feeds_importer' => $this->id,
      '#required' => FALSE,
      '#maxlength' => 32,
      '#size' => 15,
      '#description' => t('A unique machine-readable name containing letters, numbers, and underscores.'),
    );
    $form['add']['value'] = array(
      '#type' => 'textfield',
      '#description' => t('Value'),
      '#title' => '&nbsp;',
      '#size' => 50,
      '#maxlength' => 1024,
    );
    foreach ($this->configFormTableHeader() as $column => $name) {
      $form['add'][$column] = $this->configFormTableColumn($form_state, array(), $column, '');
    }
    $form['add']['debug'] = array(
      '#type' => 'checkbox',
      '#title' => t('Debug'),
      '#title_display' => 'invisible',
    );
    $form['add']['weight'] = array(
      '#type' => 'textfield',
      '#default_value' => ++$max_weight,
      '#size' => 3,
      '#attributes' => array('class' => array('feeds-ex-source-weight')),
    );
    $form['display_errors'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display errors'),
      '#description' => t('Display all error messages after parsing. Fatal errors will always be displayed.'),
      '#default_value' => $this->config['display_errors'],
    );
    $form['debug_mode'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable debug mode'),
      '#description' => t('Displays the configuration form on the feed source page to ease figuring out the expressions. Any values entered on that page will be saved here.'),
      '#default_value' => $this->config['debug_mode'],
    );

    $form = $this->getEncoder()->configForm($form, $form_state);

    $form['#attached']['drupal_add_tabledrag'][] = array(
      'feeds-ex-source-table',
      'order',
      'sibling',
      'feeds-ex-source-weight',
    );
    $form['#attached']['css'][] = drupal_get_path('module', 'feeds_ex') . '/feeds_ex.css';
    $form['#header'] = $this->getFormHeader();

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function configFormValidate(&$values) {
    // Throwing an exception during validation shows a nasty error to users.
    try {
      $this->loadLibrary();
    }
    catch (RuntimeException $e) {
      $this->getMessenger()->setMessage($e->getMessage(), 'error', FALSE);
      return;
    }

    // @todo We should do this in Feeds automatically.
    $values += $this->configDefaults();

    // Remove sources.
    foreach ($values['sources'] as $machine_name => $source) {
      if (!empty($source['remove'])) {
        unset($values['sources'][$machine_name]);
      }
    }

    // Validate context.
    if ($this->hasConfigurableContext()) {
      if ($message = $this->validateExpression($values['context']['value'])) {
        form_set_error('context', $message);
      }
    }

    // Validate expressions.
    foreach (array_keys($values['sources']) as $machine_name) {
      if ($message = $this->validateExpression($values['sources'][$machine_name]['value'])) {
        form_set_error('sources][' . $machine_name . '][value', $message);
      }
    }

    // Add new source.
    if (strlen($values['add']['machine_name']) && strlen($values['add']['name'])) {
      if ($message = $this->validateExpression($values['add']['value'])) {
        form_set_error('add][value', $message);
      }
      else {
        $values['sources'][$values['add']['machine_name']] = $values['add'];
      }
    }

    // Rebuild sources to keep the configuration values clean.
    $columns = $this->getFormHeader();
    unset($columns['remove'], $columns['machine_name']);
    $columns = array_keys($columns);

    foreach ($values['sources'] as $machine_name => $source) {
      $new_value = array();
      foreach ($columns as $column) {
        $new_value[$column] = $source[$column];
      }
      $values['sources'][$machine_name] = $new_value;
    }

    // Sort by weight.
    uasort($values['sources'], 'ctools_plugin_sort');

    // Let the encoder do its thing.
    $this->getEncoder()->configFormValidate($values);
  }

  /**
   * {@inheritdoc}
   */
  public function hasConfigForm() {
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function sourceDefaults() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function sourceForm($source_config) {
    if (!$this->hasSourceConfig()) {
      return array();
    }
    $form_state = array();

    $form = $this->configForm($form_state);
    $form['add']['machine_name']['#machine_name']['source'] = array(
      'feeds',
      get_class($this),
      'add',
      'name',
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function sourceFormValidate(&$source_config) {
    $this->configFormValidate($source_config);
  }

  /**
   * {@inheritdoc}
   */
  public function sourceSave(FeedsSource $source) {
    $config = $source->getConfigFor($this);
    $source->setConfigFor($this, array());

    if ($this->hasSourceConfig() && $config) {
      $this->setConfig($config);
      $this->save();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function hasSourceConfig() {
    return !empty($this->config['debug_mode']);
  }

  /**
   * Returns the configuration form table header.
   *
   * @return array
   *   The header array.
   */
  protected function getFormHeader() {
    $header = array(
      'name' => t('Name'),
      'machine_name' => t('Machine name'),
      'value' => t('Value'),
    );
    $header += $this->configFormTableHeader();
    $header += array(
      'debug' => t('Debug'),
      'remove' => t('Remove'),
      'weight' => t('Weight'),
    );

    return $header;
  }

  /**
   * Sets the messenger to be used to display messages.
   *
   * @param FeedsExMessengerInterface $messenger
   *   The messenger.
   *
   * @return $this
   *   The parser object.
   */
  public function setMessenger(FeedsExMessengerInterface $messenger) {
    $this->messenger = $messenger;
    return $this;
  }

  /**
   * Returns the messenger.
   *
   * @return FeedsExMessengerInterface
   *   The messenger.
   */
  public function getMessenger() {
    if (!isset($this->messenger)) {
      $this->messenger = new FeedsExMessenger();
    }
    return $this->messenger;
  }

  /**
   * Sets the encoder.
   *
   * @param FeedsExEncoderInterface $encoder
   *   The encoder.
   *
   * @return $this
   *   The parser object.
   */
  public function setEncoder(FeedsExEncoderInterface $encoder) {
    $this->encoder = $encoder;
    return $this;
  }

  /**
   * Returns the encoder.
   *
   * @return FeedsExEncoderInterface
   *   The encoder object.
   */
  public function getEncoder() {
    if (!isset($this->encoder)) {
      $class = $this->encoderClass;
      $this->encoder = new $class($this->config['source_encoding']);
    }
    return $this->encoder;
  }

}

/**
 * Displays messages to the user.
 */
interface FeedsExMessengerInterface {

  /**
   * Sets a message to display to the user.
   *
   * @param string $message
   *   The message.
   * @param string $type
   *   (optional) The type of message. Defaults to 'status'.
   * @param bool $repeat
   *   (optional) Whether to allow the message to repeat. Defaults to true.
   *
   * @see drupal_set_message()
   */
  public function setMessage($message = NULL, $type = 'status', $repeat = TRUE);

}

/**
 * Uses drupal_set_message() to show messages.
 */
class FeedsExMessenger implements FeedsExMessengerInterface {

  /**
   * {@inheritdoc}
   */
  public function setMessage($message = NULL, $type = 'status', $repeat = TRUE) {
    drupal_set_message($message, $type, $repeat);
  }

}

/**
 * Stores messages without calling drupal_set_mesage().
 */
class FeedsExTestMessenger implements FeedsExMessengerInterface {

  /**
   * The messages that have been set.
   *
   * @var array
   */
  protected $messages = array();

  /**
   * {@inheritdoc}
   */
  public function setMessage($message = NULL, $type = 'status', $repeat = TRUE) {
    $this->messages[] = array(
      'message' => $message,
      'type' => $type,
      'repeat' => $repeat,
    );
  }

  /**
   * Returns the messages.
   *
   * This is used to inspect messages that have been set.
   *
   * @return array
   *   A list of message arrays.
   */
  public function getMessages() {
    return $this->messages;
  }

}

/**
 * An exception thrown by parsers when they receive an empty feed.
 */
class FeedsExEmptyException extends RuntimeException {}
