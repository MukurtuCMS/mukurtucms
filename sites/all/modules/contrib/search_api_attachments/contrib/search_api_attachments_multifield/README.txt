Search API Attachments Multifield

This contrib module extends the work of search_api_attachments by indexing
the files that belong to a multifield in the parent entity index.

Example:
You have a node that has 2 fields :

 field_documents: a File field.
 field_multifield: a Multifield that is containing some file fields:
   field_multifield_documents1: a File field.
   field_multifield_documents2: a File field.

To index the field_documents content, you do not need this submodule, just use
the search_api_attachments module.
To index field_multifield_documents1 and field_multifield_documents2 content
in our node index, you can use this submodule.
