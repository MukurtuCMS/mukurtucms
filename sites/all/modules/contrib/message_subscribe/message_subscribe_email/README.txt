Message-subscribe-email uses message-subscribe module to email subscribers
that want updates. Supposed to serve as an example for further modules.

MAIN CONCEPTS
=============
1) Every flag that is prefixed with "subscribe_" (a subscription flag) requires
   a flag that is prefixed with "email_" and the same suffix (e.g.
   "subscribe_node" and "email_node"). The flag should have at least one
   bundle associated with it.
2) When the module is installed it will change the default view for each of the
   subscription views to ones that include emails.
3) You can use message_subscribe_get_subscribers() to get the list of email
   subscribers.
4) Use message_subscribe_send_message() to handle emailing the list of
   subscribers.