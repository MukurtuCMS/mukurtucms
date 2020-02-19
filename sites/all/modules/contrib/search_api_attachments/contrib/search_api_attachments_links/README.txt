Search API Attachments Links

This contrib module extends the work of search_api_attachments by indexing
the files that are referenced by a link field in the parent entity index.

Example:
You have a node that has 2 fields :

 field_documents: a File field.
 field_links: a link field, that has file URLs.

To index the field_documents content, you don't need this submodule, just use
the search_api_attachments module.
To index field_links content in our node index, you can use this submodule :)
