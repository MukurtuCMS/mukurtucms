Message-subscribe provides a subscription system on top of Flag and
Message-notify; providing a scalable solution for sending mass messages
(e.g. emails) as-well.

MAIN CONCEPTS
=============
1) Every flag that is prefixed with "subscribe_" is considered a valid
   subscring-flag by this module. You can add as many flags as you wish.
2) It is up to the the implementing module to create the Message entity,
   and pass it along to message_subscribe_send_message(). From there
   message-subscribe takes care of saving it, and sending it to the
   subscribed users.
3) Getting the "subscribers" is a two step process:
   - Extract the "basic context" from the given entity. For example, on the
     event of creating a new node, the implementing module will pass the
     node entity, where the Message-subscribe will add to the "context"
     the node-author, any taxonomy term the node is related to, and if OG
     module is enabled all the groups the node belongs to.
     Note: Implementing modules may pass their own custom context instead.
   - After we have the context (i.e. an array keyed by the entity-type and
     array of entity IDs as value), we iterate over it and query the {flag}
     table to get all the users that have flaggings on those items.
     Note: Implementing modules may later alter the retrieved list.

Sponsored by Acquia; Developed by Gizra
