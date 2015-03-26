Views node field (viewsnodefield)

Provides a field to display a node
-------

Because various cool plugins are field-only, views node field was created. It 
adds a field that can be added under fields, node in the views ui. Build mode
and whether to display links/comments (untested) can be set. 

An example module is views_accordion, that stable release does not provide a 
row plugin style. 

Hooks Implemented
-----------------

hook_views_data()
  Describes the field to views.
  
hook_views_handlers()
  Notifies views of the handler that provides the field.