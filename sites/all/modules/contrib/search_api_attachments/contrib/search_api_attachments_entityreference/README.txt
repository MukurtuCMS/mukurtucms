Search API Attachments Entityreference

This contrib module extends the work of search_api_attachments by indexing
the files that belong to an entity referenced by an entityreference field in the
parent entity index.

Example:
You have a node that has 3 fields :

 field_documents: a File field.
 field_references: an Entityreference field, that references a node containing
 some file fields:
   field_referenced_documents1: a File field.
   field_referenced_documents2: a File field.
   field_file_reference: an Entityreference field, that references a file entity.

To index the field_documents content, you don't need this submodule, just use
the search_api_attachments module.
To index field_referenced_documents1, field_referenced_documents2, and
field_file_reference content in our node index, you can use this submodule :)
