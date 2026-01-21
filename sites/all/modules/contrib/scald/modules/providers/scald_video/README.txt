Scald Video is a scald provider to host your videos in your drupal site.
Accepts video files .mp4, .webm and .ogv.

The following modules provide additional players:
  - VideoJS (http://www.videojs.com/): html5, flash fallback
  https://www.drupal.org/project/scald_video_videojs
  - JWPlayer: uses https://www.drupal.org/project/jw_player
  https://www.drupal.org/project/scald_video_jw_player

Install:
  - Enable module (https://drupal.org/documentation/install/modules-themes/modules-7)

Configure:
  - Configure a context to use the new video player providers, on admin/structure/scald/video/contexts

How to use:
  - Create a new video atom
  - Choose in the source list "Upload a video"
  - Upload a video file

Known issues:
  - For the moment, the module is not able to get a thumbnail automatically from the video file. So don't forget to
    define a thubmnail when creating the atom.

Extend it
You can provide different player by creating scald players module. You can take example on subdirectory players.
Name players by following this logic: scald_video_player_[library_name]

TODO
  - videos transcoding: mp4, webm (see https://drupal.org/project/ffmpeg_wrapper & https://drupal.org/project/video)
  - responsive
