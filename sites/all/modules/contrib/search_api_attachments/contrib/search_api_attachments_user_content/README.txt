Search API Attachments User Content

This contrib module extends the work of search_api_attachments by indexing
the files that belong to nodes that were created by the indexed user.

Example:
You have two file fields, one on users, one on nodes:

  User:
    field_user_file
  Node:
    field_node_file

If you create a search index based on users, but want to index all the contents
from field_node_file, based on the node author, you have to use this module.

For indexing field_user_file in a user index, you don't need this module. If you
do not have an index based on users (item type "User" or similar), this module
will not have any effect.
