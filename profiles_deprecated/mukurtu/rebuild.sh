#!/bin/bash
#
# Rebuilds the install profile tarball.
#

# Update the dev site database
pushdb --from live --to dev --iSessions --eCache --yes
cd ~/public_html/ma-dev/
# Delete users other than anon/admin
~/bin/php-cli /home/staff/ca-scrpt/bin/drush-4.4/drush.php uinf $(seq -s, 2 50) --pipe | cut -d',' -f1 | xargs -n1 ~/bin/php-cli /home/staff/ca-scrpt/bin/drush-4.4/drush.php user-cancel -y 
# Reset the admin user password
~/bin/php-cli /home/staff/ca-scrpt/bin/drush-4.4/drush.php user-password admin --password=mukurtu
~/bin/php-cli /home/staff/ca-scrpt/bin/drush-4.4/drush.php vset --always-set site_frontpage 'node/120'
# Insert other "cleanup" actions here
# Create a database dump on dev using demo-mk.
~/bin/php-cli /home/staff/ca-scrpt/bin/drush-4.4/drush.php demo-mk blank
# Move it in place on the live site.
mv ~/public_html/ma-dev/sites/default/files/private/demo/blank.sql ~/public_html/ma/profiles/mukurtu/private/
cd ~/public_html/
# Create a single directory clone of the live site.
rm -rf mukurtu
cp -aL ma mukurtu
# Set more relaxed file permissions (since this will be installed on hosts with different hosting setup).
find "mukurtu" -type f -print0 | xargs -0r chmod 664 --
find "mukurtu" -type d -print0 | xargs -0r chmod 775 --
# Replace .htaccess and settings.php with the standard ones.
rm mukurtu/.htaccess
mv mukurtu/.htaccess.orig mukurtu/.htaccess
rm mukurtu/sites/default/settings.*
rm -rf mukurtu/sites/default/files/training_videos
cp mukurtu/sites.orig/default/default.settings.php mukurtu/sites/default/settings.php
cp mukurtu/sites.orig/default/default.settings.php mukurtu/sites/default/default.settings.php
# Create the tarball and move it in a web accessible location on the dev site.
tar --hard-dereference -czhf mukurtu.tar.gz mukurtu
mv mukurtu.tar.gz ~/public_html/ma-dev/
fixwebperms.sh mukurtu
fixwebperms.sh ~/public_html/ma-dev/mukurtu.tar.gz

