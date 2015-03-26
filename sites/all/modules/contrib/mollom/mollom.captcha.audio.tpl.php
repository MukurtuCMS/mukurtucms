<?php
/**
 * @file
 * Provide the HTML output for the audio CAPTCHA playback.
 *
 * Available variables:
 * - $captcha_url:  The CAPTCHA audio to present.
 * - $flash_fallback_player: The URL to the Flash plugin to use as a fallback
 *   player when HTML5 audio is unsupported for MP3.
 *
 * Assumptions:
 * - SWFObject is already included if it is available.
 *
 * @see http://www.html5rocks.com/en/tutorials/audio/quick/
 */

$flash_url = url($flash_fallback_player, array(
  'query' => array('url' => $captcha_url),
  'external' => TRUE,
));
$switch_verify = t('Switch to image verification.');
$instructions = t('Enter only the first letter of each word you hear.  If you are having trouble listening in your browser, you can <a href="@captcha-url" id="mollom_captcha_download" class="swfNext-mollom_captcha_verify">download the audio</a> to listen on your device.', array(
  '@captcha-url' => $captcha_url,
));
$unsupported = t('Your system does not support our audio playback verification.  Please <a href="@captcha-url" id="mollom_captcha_download" class="swfNext-mollom_captcha_verify">download this verification</a> to listen on your device.', array(
  '@captcha-url' => $captcha_url,
));
$refresh_alt = t('Refresh');

$refresh_image_output = theme('image', array(
  'path' => drupal_get_path('module', 'mollom') . '/images/refresh.png',
  'alt' => $refresh_alt,
  'getsize' => FALSE,
));
?>

<script type="text/javascript">
  function embedFallbackPlayer() {
    var embedDiv = document.getElementById("mollom_captcha_fallback_player");
    var audioDiv = document.getElementById("mollom_captcha_audio");
    var unsupportedDiv = document.getElementById("mollom_captcha_unsupported");
    var movie = '<?php print $flash_url; ?>';

    function embedComplete(e) {
      if (e.success) {
        e.ref.focus();
      } else {
        jQuery(unsupportedDiv).show();
      }
    }

    var flashvars = {},
      params = {
        wmode:  "opaque"
      },
      attributes = {
        "class": "swfPrev-mollom_captcha_download swfNext-mollom_captcha_verify mollom_captcha_flash_player",
      },
      playerWidth = 110,
      playerHeight = 50;
    if (typeof swfobject !== 'undefined') {
      swfobject.embedSWF(movie, embedDiv, playerWidth, playerHeight, "10.0", null, flashvars, params, attributes, embedComplete);
    } else {
      var embed = '<object id="mollom_captcha_fallback_player" name="mollom_captcha_fallback_player" ';
      embed += 'classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" ';
      embed += 'type="application/x-shockwave-flash" ';
      embed += 'data="' + movie + '" '
      for (var attr in attributes) {
        embed += attr + '="' + attributes[attr] + '" ';
      }
      embed += 'width="' + playerWidth + 'px" height="' + playerHeight + 'px">';
      embed += '<param name="movie" value="' + movie + '" />';
      for (var param in params) {
        embed += '<param name="' + param + '" value="' + params[param] + '" />';
      }
      var flashVarsArray = [];
      for(var varname in flashvars) {
        flashVarsArray.append(varname + '=' + encodeURI(flashvars[varname]));
      }
      flashVarsString = flashVarsArray.join('&');
      if (flashVarsString.length > 0) {
        embed += '<param name="flashVars" value="' + flashVarsString + '" />';
      }
      embed += '<embed src="' + movie + '" width="' + playerWidth + '" height="' + playerHeight + '" ';
      for (var attr in attributes) {
        embed += attr + '="' + attributes[attr] + '" ';
      }
      for (var param in params) {
        embed += param + '="' + params[param] + '" ';
      }
      if (flashVarsString.length > 0) {
        embed += 'flashVars="' + flashVarsString + '"';
      }
      embed += '/>';
      embed += '</object>';
      jQuery(embedDiv).replaceWith(embed);
      jQuery("#mollom_captcha_fallback_player").focus();
    }
    jQuery(audioDiv).hide();
  }
</script>

<span class="mollom-captcha-container">
  <a href="javascript:void(0);" class="mollom-refresh-captcha mollom-refresh-audio"><?php print $refresh_image_output; ?></a>
  <div class="mollom-captcha-content mollom-audio-captcha">
    <div class="mollom-audio-catcha-instructions"><?php print $instructions; ?></div>

    <!--- HTML5 Audio playback -->
    <audio id="mollom_captcha_audio" controls tabindex="0">
      <source src="<?php print $captcha_url; ?>" type="audio/mpeg" />
      <!-- Displays if HTML5 audio is unsupported and JavaScript player embed is unsupported -->
      <p><?php print $unsupported; ?></p>
    </audio>

    <!-- Fallback for browsers not supporting HTML5 audio or not MP3 format -->
    <div id="mollom_captcha_fallback">
      <div id="mollom_captcha_fallback_player"></div>
      <script>
        var audioTest = document.createElement('audio');
        if (!audioTest.canPlayType || !audioTest.canPlayType('audio/mpeg')) {
          embedFallbackPlayer();
        }
      </script>
    </div>

    <!-- Text to show when neither HTML5 audio or SWFs are supported -->
    <div id="mollom_captcha_unsupported" style="display:none;">
      <p><?php print $unsupported; ?></p>
    </div>

    <div class="mollom-audio-captcha-switch"><a href="#" class="mollom-switch-captcha mollom-image-captcha swfPrev-mollom_captcha_download" id="mollom_captcha_verify"><?php print $switch_verify; ?></a></div>
  </div>
</span>
