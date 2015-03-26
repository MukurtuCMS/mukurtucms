To enable:

1. Enable module.

2. Change site homepage to frontpage_app:

    admin/config/system/site-information

3. Make sure fitvids is enabled
  
  Make sure fitvids has permissions so you can edit the settings.
  
4. Configure Fitvids:

  admin/config/media/fitvids

  Replace 
  
    .region

  with

.node.view-mode-full .oembed-video
.node .file-type-video
.frontpage-app .file-type-video
.frontpage-app .oembed-video


5. Enable Mukurtu Services if it is not already.

6. Set Jquery Update to 1.8:

  admin/config/development/jquery_update


7. Edit front page content (uses twitter bootstrap markup)

    admin/config/frontpage_app












