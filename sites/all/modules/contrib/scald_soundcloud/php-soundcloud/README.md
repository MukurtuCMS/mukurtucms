# SoundCloud PHP API Wrapper

## Introduction

A wrapper for the SoundCloud API written in PHP with support for authentication using [OAuth 2.0](http://oauth.net/2/).

The wrapper got a real overhaul with version 2.0. The current version was written with [PEAR](http://pear.php.net/) in mind and can easily by distributed as a PEAR package.

## Getting started

Check out the [getting started](https://github.com/mptre/php-soundcloud/wiki/OAuth-2) wiki entry for further reference on how to get started. Also make sure to check out the [demo application](https://github.com/mptre/ci-soundcloud) for some example code.


## Examples

The wrapper includes convenient methods used to perform HTTP requests on behalf of the authenticated user. Below you'll find a few quick examples.

Ofcourse you need to handle the authentication first before being able to request and modify protect resources as demonstrated below. Therefor I refer to the [demo application](https://github.com/mptre/ci-soundcloud) which got some example code on how to handle authentication.

### GET

``` php
<?php
try {
    $response = json_decode($soundcloud->get('me'), true);
} catch (Services_Soundcloud_Invalid_Http_Response_Code_Exception $e) {
    exit($e->getMessage());
}
```

### POST

``` php
<?php
$comment = <<<EOH
<comment>
    <body>Yeah!</body>
</comment>
EOH;

try {
    $response = json_decode(
        $soundcloud->post(
            'tracks/1/comments',
            $comment,
            array(CURLOPT_HTTPHEADER => array('Content-Type: application/xml'))
        ),
        true
    );
} catch (Services_Soundcloud_Invalid_Http_Response_Code_Exception $e) {
    exit($e->getMessage());
}
```

### PUT

``` php
<?php
$track = <<<EOH
<track>
    <downloadable>true</downloadable>
</track>
EOH;

try {
    $response = json_decode(
        $soundcloud->put(
            'tracks/1',
            $track,
            array(CURLOPT_HTTPHEADER => array('Content-Type: application/xml'))
        ),
        true
    );
} catch (Services_Soundcloud_Invalid_Http_Response_Code_Exception $e) {
    exit($e->getMessage());
}
```

### DELETE

``` php
<?php
try {
    $response = json_decode($soundcloud->delete('tracks/1'), true);
} catch (Services_Soundcloud_Invalid_Http_Response_Code_Exception $e) {
    exit($e->getMessage());
}
```

### Upload track

``` php
<?php
$track = array(
    'track[title]' => 'My awesome track',
    'track[tags]' => 'dubstep rofl',
    'track[asset_data]' => '@/absolute/path/to/track.mp3'
);
    
try {
    $response = $soundcloud->post('tracks', $track);
} catch (Services_Soundcloud_Invalid_Http_Response_Code_Exception $e) {
    exit($e->getMessage());
}
```

### Download track

``` php
<?php
try {
    $track = $soundcloud->download(1337);
} catch (Services_Soundcloud_Invalid_Http_Response_Code_Exception $e) {
    exit($e->getMessage());
}

// do something clever with $track. Save to file perhaps?
```

### Update playlist

Many found it difficult to update a existing playlist. Therefor a custom method is available to simplify this matter.

``` php
<?php
$playlistId = 2000;
$trackIds = array(2001);
$optionalFields = array('title' => 'My awesome playlist');

try {
    $playlist = $soundcloud->updatePlaylist($playlistId, $trackIds, $optionalFields);
} catch (Services_Soundcloud_Invalid_Http_Response_Code_Exception $e) {
    exit($e->getMessage());
}
```

## Feedback and questions

Found a bug or missing a feature? Don't hesitate to create a new issue here on GitHub. Or contact me [directly](https://github.com/mptre).

Also make sure to check out the official [documentation](https://github.com/soundcloud/api/wiki/) and the join [Google Group](https://groups.google.com/group/soundcloudapi?pli=1) in order to stay updated.

## License

Copyright (c) 2011 Anton Lindqvist

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
