Search API Attachments References

This contrib module extends the work of search_api_attachments by indexing
the files that belong to a referenced node by an node reference field in the
parent entity index.

Example:
You have a node that has 2 fields :

 field_documents: a File field.
 field_references: a reference field, that is containing some file fields:
   field_referenced_documents1: a File field.
   field_referenced_documents2: a File field.

To index the field_documents content, you don't need this submodule, just use
the search_api_attachments module.
To index field_referenced_documents1 and field_referenced_documents2 content
in our node index, you can use this submodule :)
