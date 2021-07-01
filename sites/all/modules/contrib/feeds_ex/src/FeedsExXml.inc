<?php

/**
 * @file
 * Contains FeedsExXml.
 */

/**
 * Parses XML documents with XPath.
 */
class FeedsExXml extends FeedsExBase {

  /**
   * The FeedsExXpathDomXpath object used for parsing.
   *
   * @var FeedsExXpathDomXpath
   */
  protected $xpath;

  /**
   * The previous value for XML error handling.
   *
   * @var bool
   */
  protected $handleXmlErrors;

  /**
   * The previous value for the entity loader.
   *
   * @var bool
   */
  protected $entityLoader;

  /**
   * {@inheritdoc}
   */
  protected $encoderClass = 'FeedsExXmlEncoder';

  /**
   * {@inheritdoc}
   */
  protected function setUp(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $document = $this->prepareDocument($source, $fetcher_result);
    $this->xpath = new FeedsExXpathDomXpath($document);
  }

  /**
   * {@inheritdoc}
   */
  protected function cleanUp(FeedsSource $source, FeedsParserResult $result) {
    // Try to free up some memory. There shouldn't be any other references to
    // $this->xpath or the DOMDocument.
    unset($this->xpath);

    // Calculate progress.
    $state = $source->state(FEEDS_PARSE);
    $state->progress($state->total, $state->pointer);
  }

  /**
   * {@inheritdoc}
   */
  protected function executeContext(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $state = $source->state(FEEDS_PARSE);

    if (!$state->total) {
      $state->total = $this->xpath->evaluate('count(' . $this->config['context']['value'] . ')');
    }

    $start = (int) $state->pointer;
    $state->pointer = $start + $source->importer->getLimit();

    // A batched XPath expression.
    $context_query = '(' . $this->config['context']['value'] . ")[position() > $start and position() <= {$state->pointer}]";
    return $this->xpath->query($context_query);
  }

  /**
   * {@inheritdoc}
   */
  protected function executeSourceExpression($machine_name, $expression, $row) {
    $result = $this->xpath->evaluate($expression, $row);

    if (!$result instanceof DOMNodeList) {
      return $result;
    }
    if ($result->length == 0) {
      return;
    }

    $return = array();
    if (!empty($this->config['sources'][$machine_name]['inner'])) {
      foreach ($result as $node) {
        $return[] = $this->getInnerXml($node);
      }
    }
    elseif (!empty($this->config['sources'][$machine_name]['raw'])) {
      foreach ($result as $node) {
        $return[] = $this->getRaw($node);
      }
    }
    else {
      foreach ($result as $node) {
        $return[] = $node->nodeValue;
      }
    }

    // Return a single value if there's only one value.
    return count($return) === 1 ? reset($return) : $return;
  }

  /**
   * {@inheritdoc}
   */
  public function configDefaults() {
    return array(
      'use_tidy' => FALSE,
    ) + parent::configDefaults();
  }

  /**
   * {@inheritdoc}
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    if (extension_loaded('tidy')) {
      $form['use_tidy'] = array(
        '#type' => 'checkbox',
        '#title' => t('Use tidy'),
        '#description' => t('The <a href="http://php.net/manual/en/book.tidy.php">Tidy PHP</a> extension has been detected. Select this to clean the markup before parsing.'),
        '#default_value' => $this->config['use_tidy'],
      );
    }

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  protected function configFormTableHeader() {
    return array('raw' => t('Raw'), 'inner' => t('Inner XML'));
  }

  /**
   * {@inheritdoc}
   */
  protected function configFormTableColumn(array &$form_state, array $values, $column, $machine_name) {
    $id = 'feeds-ex-xml-raw-' . check_plain($machine_name);

    switch ($column) {
      case 'raw':
        return array(
          '#type' => 'checkbox',
          '#title' => t('Raw value'),
          '#title_display' => 'invisible',
          '#default_value' => (int) !empty($values['raw']),
          '#id' => $id,
        );

      case 'inner':
        return array(
          '#type' => 'checkbox',
          '#title' => t('Inner XML'),
          '#title_display' => 'invisible',
          '#default_value' => (int) !empty($values['inner']),
          '#states' => array(
            'visible' => array('#' . $id => array('checked' => TRUE)),
          ),
        );
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function validateExpression(&$expression) {
    $expression = trim($expression);
    $message = NULL;

    if (!$expression) {
      return $message;
    }

    $this->startErrorHandling();
    $xml = new SimpleXMLElement("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<items></items>");
    $xml->xpath($expression);

    if ($error = libxml_get_last_error()) {
      // Our variable substitution options can cause syntax errors, check if
      // we're doing that.
      if ($error->code == 1207 && strpos($expression, '$') !== FALSE) {
        // Do nothing.
      }
      // Error code 1219 is an undefined namespace prefix.
      // Our sample doc doesn't have any namespaces.
      elseif ($error->code != 1219) {
        $message = check_plain(trim($error->message));
      }
    }

    $this->stopErrorHandling();
    return $message;
  }

  /**
   * {@inheritdoc}
   */
  public function configFormValidate(&$values) {
    parent::configFormValidate($values);

    // Remove values that are inner but not raw.
    foreach ($values['sources'] as $machine_name => $source) {
      if (!empty($source['inner']) && empty($source['raw'])) {
        unset($values['sources'][$machine_name]['inner']);
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function convertEncoding($data, $encoding = 'UTF-8') {
    return FeedsExXmlUtility::convertXmlEncoding($data, $this->config['source_encoding']);
  }

  /**
   * Prepares the DOM document.
   *
   * @param FeedsSource $source
   *   The feed source.
   * @param FeedsFetcherResult $fetcher_result
   *   The fetcher result.
   *
   * @return DOMDocument
   *   The DOM document.
   */
  protected function prepareDocument(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $raw = $this->prepareRaw($fetcher_result);
    // Remove default namespaces. This has to run after the encoding conversion
    // because a limited set of encodings are supported in regular expressions.
    $raw = FeedsExXmlUtility::removeDefaultNamespaces($raw);

    if ($this->config['use_tidy'] && extension_loaded('tidy')) {
      $raw = tidy_repair_string($raw, $this->getTidyConfig(), 'utf8');
    }
    return FeedsExXmlUtility::createXmlDocument($raw);
  }

  /**
   * Returns the raw XML of a DOM node.
   *
   * @param DOMNode $node
   *   The node to convert to raw XML.
   *
   * @return string
   *   The raw XML.
   */
  protected function getRaw(DOMNode $node) {
    return $node->ownerDocument->saveXML($node);
  }

  /**
   * Returns the inner XML of a DOM node.
   *
   * @param DOMNode $node
   *   The node to convert to raw XML.
   *
   * @return string
   *   The inner XML.
   */
  protected function getInnerXml(DOMNode $node) {
    $buffer = '';
    foreach ($node->childNodes as $child) {
      $buffer .= $this->getRaw($child);
    }
    return $buffer;
  }

  /**
   * {@inheritdoc}
   */
  protected function startErrorHandling() {
    parent::startErrorHandling();

    libxml_clear_errors();
    $this->handleXmlErrors = libxml_use_internal_errors(TRUE);

    // Only available in PHP >= 5.2.11.
    // See http://symfony.com/blog/security-release-symfony-2-0-17-released for
    // details.
    if (function_exists('libxml_disable_entity_loader')) {
      $this->entityLoader = libxml_disable_entity_loader(TRUE);
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function stopErrorHandling() {
    parent::stopErrorHandling();

    libxml_clear_errors();
    libxml_use_internal_errors($this->handleXmlErrors);
    if (function_exists('libxml_disable_entity_loader')) {
      libxml_disable_entity_loader($this->entityLoader);
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function getErrors() {
    $return = array();
    foreach (libxml_get_errors() as $error) {

      // Translate error values.
      switch ($error->level) {
        case LIBXML_ERR_FATAL:
          $severity = WATCHDOG_ERROR;
          break;

        case LIBXML_ERR_ERROR:
          $severity = WATCHDOG_WARNING;
          break;

        default:
          $severity = WATCHDOG_NOTICE;
          break;
      }

      $return[] = array(
        'message' => '%error on line %num. Error code: %code',
        'variables' => array(
          '%error' => trim($error->message),
          '%num' => $error->line,
          '%code' => $error->code,
        ),
        'severity' => $severity,
      );
    }

    return $return;
  }

  /**
   * Returns the options for phptidy.
   *
   * http://php.net/manual/en/book.tidy.php
   *
   * @see tidy_repair_string()
   *
   * @return array
   *   The configuration array.
   */
  protected function getTidyConfig() {
    return array(
      'input-xml' => TRUE,
      'wrap' => 0,
      'tidy-mark' => FALSE,
    );
  }

}

/**
 * Wraps DOMXPath simplifying usage.
 */
class FeedsExXpathDomXpath {

  /**
   * The XPath query object.
   *
   * @var DOMXPath
   */
  protected $xpath;

  /**
   * Constructs a FeedsExXpathDomXpath object.
   *
   * @param DOMDocument $document
   *   The DOM document to parse.
   *
   * @todo Add an option to force a deep scan of namespaces.
   */
  public function __construct(DOMDocument $document) {
    $this->xpath = new DOMXPath($document);

    // Find all namespaces.
    // Calling simplexml_import_dom() and SimpleXML::getNamespaces() is several
    // orders of magnitude faster than searching for the namespaces ourselves
    // using XPath.
    $simple = simplexml_import_dom($document);
    // An empty DOMDocument will make $simple NULL.
    if ($simple === NULL) {
      return;
    }
    foreach ($simple->getNamespaces(TRUE) as $prefix => $namespace) {
      $this->xpath->registerNamespace($prefix, $namespace);
    }
  }

  /**
   * Evaluates the XPath expression and returns a typed result if possible.
   *
   * @param string $expression
   *   The XPath expression to execute.
   * @param DOMNode $context_node
   *   (optional) The optional contextnode can be specified for doing relative
   *   XPath queries. Defaults to the root element.
   *
   * @see DOMXPath::evaluate()
   */
  public function evaluate($expression, DOMNode $context_node = NULL) {
    if ($context_node === NULL) {
      $context_node = $this->xpath->document;
    }
    return $this->xpath->evaluate($expression, $context_node);
  }

  /**
   * Evaluates the given XPath expression.
   *
   * @param string $expression
   *   The XPath expression to execute.
   * @param DOMNode $context_node
   *   (optional) The optional contextnode can be specified for doing relative
   *   XPath queries. Defaults to the root element.
   *
   * @see DOMXPath::query()
   */
  public function query($expression, DOMNode $context_node = NULL) {
    if ($context_node === NULL) {
      $context_node = $this->xpath->document;
    }
    return $this->xpath->query($expression, $context_node);
  }

}
