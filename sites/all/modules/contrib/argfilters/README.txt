So, what's the thing?

Arguments is one of the things that makes Views really powerful. Really. You
should already know that arguments is some kind of filters in Views, but that
they accept input data instead manual data to set the filter. Enough abou that.

There are at least two problems with arguments as they are currently used in
Views:
  * Many people find it difficult to wrap their head around how arguments work.
  * It is not possible to use operators on arguments, for example to show all
    nodes created *after* the timestamp value you provide in an argument, or
    display all the nodes that in their title *contain* the word/phrase in the
    argument. There is just "equals" or "not equals". (Unless you more or less
    code your own argument handlers, which would end up a special case that few
    others can make use of.)

This module helps reducing these two problems, by introducing a new way of
handling arguments. Using the "Views arguments in filters" module, you can use
placeholders when configuring filters, like so:

  * Node: Title CONTAINS %1
  * Node: Post date >= %2

Where %1 and %2 is the standard replacement patterns used to fetch the values
for input argument %1 and %2.


HOW TO USE THIS MODULE
======================
To make use of this module, configure your view as usual, but use the following
steps when adding arguments.

  * Use the argument "Global: Null" to denote the input arguments your view will
    make use of. This argument not alter your query in any way, but you can
    still use validators and actions if no argument is present as usual. And
    title, breadcrumbs, et cetera. Sweet.
  * Add a filter, and instead of adding a filter value manually, you enter %1,
    %2, et cetera to filter on the first or second input argument.

That's it!


FUTURE PLANS
============
This module is obviously a pretty quick hack to make a proof of concept. In the
future the following should be implemented:

  * Instead of entering argument tokens manually, possibly misspelling or just
    conflicting with actual filter values you want to use, there should be a
    button "use argument value" in parallell to the "expose" button for each
    filter. The button switches all filter value inputs to a dropdown showing
    the names of the presently configured arguments.
  * It should be possible to use both the raw argument input value and the
    validated argument title (if any) – in parallel to use %1 and !1.


REALLY FUTURISTIC PLANS
=======================
Eventually I hope that this module will be replaced by a Views patch. If so, the
following could change:

  * All argument handlers are replaced by a single argument input thingy, being
    the current "Global: Null" argument (but would only have to be named
    "Argument input" or something). This would probably mean that arguments
    won't be handlers, but Views plugins.


SOME MORE NOTES ON WHAT'S GOOD WITH THIS
========================================
Though this module provides some new functionality in Views, it is more of a
suggestion for a conceptual change in how arguments should be used in Views.
Here are some bullets summarizing the points of why this conceptual change is
beneficial:

  * The current arguments are a mix of input validators and filter handlers.
    This is confusing for users and produces extra work for coders (who have
    to implement two handers for the same functionality). This module allows
    separating the two functions of arguments.
  * There is currently no good way of reusing the same argument for several
    filters. This module changes this.
  * There is reasonable no way of using operators on arguments, currently. This
    module makes is as easy to use operators on arguments as on regular filters,
    since arguments become filters.


CRED
====
Cred to Letharion for ideas and discussion. Sorry that I found a way to realize
this concept without rewriting Views argument handling more or less from
scratch. :-)
