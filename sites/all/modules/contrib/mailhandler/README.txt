CONTENTS OF THIS FILE
---------------------

 * Overview
 * Features
 * More documentation

OVERVIEW
--------

The Mailhandler module allows registered users to create or edit nodes and
comments via email. Authentication is usually based on the From: email address.
Users may post taxonomy terms, teasers, and other node parameters using the
Commands capability.

FEATURES
--------

Mailhandler 2.x leans on other frameworks where possible in order to
reduce the amount of code that lives in Mailhandler itself when that code 
consists of patterns better provided by other library or framework modules.

- Retrieve mail from any IMAP / POP3 mailbox using a variety of settings, and
  export/import mailbox configurations using CTools / Features.
- Extensible authentication system- authenticate users by matching "from"
  address to Drupal user accounts, or by using more advanced token- and
  password-based authentication methods
- Extensible commands system- set fields using a simple key: value system, or
  use more complex command plugins.
- Filters allow you to strip signatures and other cruft from messages.

MORE DOCUMENTATION
------------------

See the INSTALL.txt for setup instructions.

More documentation is located at http://drupal.org/handbook/modules/mailhandler
which discusses topics such as how to configure mailboxes for specific email
providers.
