<?php

/**
 * @file
 * Contains FeedsExXmlUtility.
 */

/**
 * Simple XML helpers.
 */
class FeedsExXmlUtility {

  /**
   * Matches the characters of an XML element.
   *
   * @var string
   */
  protected static $elementRegex = '[:A-Z_a-z\\xC0-\\xD6\\xD8-\\xF6\\xF8-\\x{2FF}\\x{370}-\\x{37D}\\x{37F}-\\x{1FFF}\\x{200C}-\\x{200D}\\x{2070}-\\x{218F}\\x{2C00}-\\x{2FEF}\\x{3001}-\\x{D7FF}\\x{F900}-\\x{FDCF}\\x{FDF0}-\\x{FFFD}\\x{10000}-\\x{EFFFF}][:A-Z_a-z\\xC0-\\xD6\\xD8-\\xF6\\xF8-\\x{2FF}\\x{370}-\\x{37D}\\x{37F}-\\x{1FFF}\\x{200C}-\\x{200D}\\x{2070}-\\x{218F}\\x{2C00}-\\x{2FEF}\\x{3001}-\\x{D7FF}\\x{F900}-\\x{FDCF}\\x{FDF0}-\\x{FFFD}\\x{10000}-\\x{EFFFF}\\.\\-0-9\\xB7\\x{0300}-\\x{036F}\\x{203F}-\\x{2040}]*';

  /**
   * Strips the default namespaces from an XML string.
   *
   * @param string $xml
   *   The XML string.
   *
   * @return string
   *   The XML string with the default namespaces removed.
   */
  public static function removeDefaultNamespaces($xml) {
    return preg_replace('/(<' . self::$elementRegex . '[^>]*)\s+xmlns\s*=\s*("|\').*?(\2)([^>]*>)/u', '$1$4', $xml);
  }

  /**
   * Creates an XML document.
   *
   * @param string $source
   *   The string containing the XML.
   * @param int $options
   *   (optional) Bitwise OR of the libxml option constants. Defaults to 0.
   *
   * @return DOMDocument
   *   The newly created DOMDocument.
   *
   * @throws RuntimeException
   *   Thrown if there is a fatal error parsing the XML.
   */
  public static function createXmlDocument($source, $options = 0) {
    $document = self::buildDomDocument();
    $options = $options | LIBXML_NOENT | LIBXML_NONET | defined('LIBXML_COMPACT') ? LIBXML_COMPACT : 0;

    if ((version_compare(PHP_VERSION, '5.3.2', '>=') || version_compare(PHP_VERSION, '5.2.12', '>='))
      && version_compare(LIBXML_DOTTED_VERSION, '2.7.0', '>=')) {
      $options = $options | LIBXML_PARSEHUGE;
    }

    if (!$document->loadXML($source, $options)) {
      throw new RuntimeException(t('There was an error parsing the XML document.'));
    }
    return $document;
  }

  /**
   * Creates an HTML document.
   *
   * @param string $source
   *   The string containing the HTML.
   * @param int $options
   *   (optional) Bitwise OR of the libxml option constants. Defaults to 0.
   *
   * @return DOMDocument
   *   The newly created DOMDocument.
   *
   * @throws RuntimeException
   *   Thrown if there is a fatal error parsing the XML.
   */
  public static function createHtmlDocument($source, $options = 0) {
    // Fun hack to force parsing as utf-8.
    $source = '<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />' . "\n" . $source;
    $document = self::buildDomDocument();
    // Pass in options if available.
    if (version_compare(PHP_VERSION, '5.4.0', '>=')) {
      $options = $options | LIBXML_NOENT | LIBXML_NONET | defined('LIBXML_COMPACT') ? LIBXML_COMPACT : 0;

      if (version_compare(LIBXML_DOTTED_VERSION, '2.7.0', '>=')) {
        $options = $options | LIBXML_PARSEHUGE;
      }
      $success = $document->loadHTML($source, $options);
    }
    else {
      $success = $document->loadHTML($source);
    }

    if (!$success) {
      throw new RuntimeException(t('There was an error parsing the HTML document.'));
    }
    return $document;
  }

  /**
   * Builds a DOMDocument setting some default values.
   *
   * @return DOMDocument
   *   A new DOMDocument.
   */
  protected static function buildDomDocument() {
    $document = new DOMDocument('1.0', 'UTF-8');
    $document->strictErrorChecking = FALSE;
    $document->resolveExternals = FALSE;
    // Libxml specific.
    $document->substituteEntities = FALSE;
    $document->recover = TRUE;
    $document->encoding = 'UTF-8';
    return $document;
  }

}

/**
 * Converts the encoding of an XML document to UTF-8.
 */
class FeedsExXmlEncoder extends FeedsExTextEncoder {

  /**
   * The regex used to find the encoding.
   *
   * @var string
   */
  protected $findRegex = '/^<\?xml[^>]+encoding\s*=\s*("|\')([\w-]+)(\1)/';

  /**
   * The regex used to replace the encoding.
   *
   * @var string
   */
  protected $replaceRegex = '/^(<\?xml[^>]+encoding\s*=\s*("|\'))([\w-]+)(\2)/';

  /**
   * The replacement pattern.
   *
   * @var string
   */
  protected $replacePattern = '$1UTF-8$4';

  /**
   * {@inheritdoc}
   */
  public function convertEncoding($data) {
    // Check for an encoding declaration in the XML prolog.
    $matches = FALSE;
    $encoding = 'ascii';
    if (preg_match($this->findRegex, $data, $matches)) {
      $encoding = $matches[2];
    }
    elseif ($detected = $this->detectEncoding($data)) {
      $encoding = $detected;
    }

    // Unsupported encodings are converted here into UTF-8.
    if (in_array(strtolower($encoding), self::$utf8Compatible)) {
      return $data;
    }

    $data = $this->doConvert($data, $encoding);
    if ($matches) {
      $data = preg_replace($this->replaceRegex, $this->replacePattern, $data);
    }

    return $data;
  }
}

/**
 * Converts the encoding of an HTML document to UTF-8.
 */
class FeedsExHtmlEncoder extends FeedsExXmlEncoder {

  /**
   * {@inheritdoc}
   */
  protected $findRegex = '/(<meta[^>]+charset\s*=\s*["\']?)([\w-]+)\b/i';

  /**
   * {@inheritdoc}
   */
  protected $replaceRegex = '/(<meta[^>]+charset\s*=\s*["\']?)([\w-]+)\b/i';

  /**
   * {@inheritdoc}
   */
  protected $replacePattern = '$1UTF-8';

}
