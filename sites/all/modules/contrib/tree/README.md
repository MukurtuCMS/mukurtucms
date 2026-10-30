
## The vision

Each tree provider integrates into an existing workflow:

 - load by id
   # hook load
 - save
   # hook presave
   # hook update
   # hook insert
 - delete
   # hook delete
 - build a query based on the tree information, supporting:
   ->condition()
   ->order()

## Query integration

parent($item):

ancestors($item):


## Simple

## Materialized path

What needs to happen on save?

- Generate the materialized path for new items.
- 

### Field integration

- Provide an extension of EFQ that can:
  ->parentOf($field_name, $item)
  ->ancestorsOf($field_name, $item)
  ->childrenOf($field_name, $item)

- Provide a Views handler for sort by tree order

- On save:
  - Build the lineage for new items or for changed items
  - Reparent the children of the current item

- On delete:
  - Reparent the children, or
  - Delete the children

