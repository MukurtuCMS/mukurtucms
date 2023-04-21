REROUTE EMAIL
-------------

CONTENTS OF THIS FILE
---------------------

 * Description
 * Installation and configuration
 * Tips and Tricks
 * Settings code snippet
 * Test Email Form
 * Bugs / features / patches
 * Authors and maintainers
 * Link references

--------------------------------------------------------------------------------
                                 DESCRIPTION
--------------------------------------------------------------------------------

This module intercepts all outgoing emails from a Drupal site and reroutes them
to a list of predefined configurable email addresses.

This is especially useful in cases where you would not want emails sent from a
Drupal site to reach target users. For example, if a live site was copied to a
test site for development and testing purposes, in general, you would like to
prevent any email sent from the test site to reach real users of the original
site. The module is also an appropriate tool for checking closer outgoing emails
for formatting, footers, headers, and more.

Additionally, it is a good example of what hook_mail_alter(), available in
Drupal 5.x and later, can do.

--------------------------------------------------------------------------------
                        INSTALLATION AND CONFIGURATION
--------------------------------------------------------------------------------

To install this module, do the following:

1 - Download the module and copy it into your contributed modules folder:
[for example, your_drupal_path/sites/all/modules/contrib] and enable it from the
modules administration/management page (no requirements).
More information at: Installing contributed modules (Drupal 7) [1].

2 - Configuration:
After successful installation, browse to the Reroute Email settings page either
by using the "Configure" link (next to module's name on the modules listing
page), or page's menu link under:
Home » Administration » Configuration » Development
Path: /admin/config/development/reroute_email

3 - Enter a list of email addresses to route all emails to. If the field is
empty and no value is provided for rerouted email addresses, all outgoing
emails would be aborted and recorded in the recent log entries, with a full
dump of the email variables, which could provide an additional debugging
method. The whitelist section allows setting up lists of email address and
domain name exceptions for which outgoing emails would not be rerouted.

--------------------------------------------------------------------------------
                               TIPS AND TRICKS
--------------------------------------------------------------------------------

1 - Reroute Email provides configuration variables that can be directly
overridden in the settings.php file of a site. This is particularly useful for
moving sites from live to test and vice versa.

2 - An example of setup would be to enable rerouting on a test environment,
while making sure it is disabled in production.

Add the following line in the settings.php file for the test environment:
  $conf['reroute_email_enable'] = 1;

And for the live site, set it as follows:
  $conf['reroute_email_enable'] = 0;

3 - Your custom module can add a special header 'X-Rerouted-Force' with TRUE or
FALSE value to any own emails in hook_mail or any emails in hook_mail_alter()
implementations. This header will force enable or disable email rerouting by
ignoring default settings.

--------------------------------------------------------------------------------
                            SETTINGS CODE SNIPPET
--------------------------------------------------------------------------------

Configuration and all the settings variables can be overridden in the
settings.php file by copying and pasting the code snippet below and changing
the values:

/**
 * Reroute Email module:
 *
 * To override specific variables and ensure that email rerouting is enabled or
 * disabled, change the values below accordingly for your site.
 */

// Enable email rerouting.
$conf['reroute_email_enable'] = 1;

// Space, comma, semicolon, or newline-delimited list of email addresses. Every
// destination email address which is not on "Whitelisted email addresses" list
// will be rerouted to these addresses. If the field is empty and no value is
// provided, all outgoing emails would be aborted and the email would be
// recorded in the recent log entries (if enabled).
$conf['reroute_email_address'] = 'reroute-to@example.com';

// Space, comma, semicolon, or newline-delimited list of email addresses to pass
// through. Every destination email address which is not on this list will be
// rerouted. If the field is empty and no value is provided, all outgoing emails
// would be rerouted. We can use wildcard email "*@example.com" to whitelist all
// emails by the domain.
$conf['reroute_email_whitelist'] = '*@example.com, foo@bar.com';

// Space, comma, semicolon, or newline-delimited list of message keys to be
// rerouted. Either module machine name or specific mail key can be used for
// that. Only matching messages will be rerouted. If left empty (as default),
// all emails will be selected for rerouting.
$conf['reroute_email_mail_keys'] = 'somemodule, mymodule_mykey';

// Enable inserting a message into the email body when the mail is being
// rerouted.
$conf['reroute_email_enable_message'] = 1;

// Enable the display of a Drupal status message after rerouting email.
$conf['reroute_email_enable_dsm'] = 1;

--------------------------------------------------------------------------------
                               TEST EMAIL FORM
--------------------------------------------------------------------------------

Reroute Email also provides a convenient form for testing email sending or
rerouting. After enabling the module, a test email form is accessible under:
Admin » Configuration » Development » Reroute Email » Test email form
Path: /admin/config/development/reroute_email/test

This form allows sending an email upon submission to the recipients entered in
the fields To, Cc and Bcc, which is very practical for testing if emails are
correctly rerouted to the configured addresses.

--------------------------------------------------------------------------------
                          BUGS / FEATURES / PATCHES
--------------------------------------------------------------------------------

Feel free to follow up in the issue queue [2] for any contributions, bug
reports, feature requests.
Tests, feedback or comments in general are highly appreciated.

--------------------------------------------------------------------------------
                           AUTHORS AND MAINTAINERS
--------------------------------------------------------------------------------

kbahey (https://www.drupal.org/user/4063)
rfay (http://drupal.org/user/30906)
DYdave (http://drupal.org/user/467284)
bohart (https://drupal.org/user/289861)

If you use this module, find it useful, and want to send the author a thank you
note, then use the Feedback/Contact page at the URL above.

--------------------------------------------------------------------------------
                               LINK REFERENCES
--------------------------------------------------------------------------------

1: http://drupal.org/documentation/install/modules-themes/modules-7
2: https://www.drupal.org/project/issues/reroute_email
