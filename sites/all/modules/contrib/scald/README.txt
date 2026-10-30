SCALD: MEDIA MANAGEMENT MADE EASY
---------------------------------

Homepage: http://drupal.org/project/scald
Documentation: http://drupal.org/node/1652740

Contents of this file:

 * Introduction
 * Terminology
 * Installation


INTRODUCTION
------------

"SCALD is Content, Attribution, Licensing, & Distribution". The problem that
sparked the development of Scald is obvious all over the web. When I (the
end-user) want to post something online I first must figure out what *type* of
thing I'm posting. If I am writing something for my personal blog about my
vacation last weekend, I'll open up Blogger and start writing. But then I
realize that I have a video which I want to include in my post. So I open up
YouTube, check to see if the video format that I have my video in is compatible
with YouTube, upload my video, copy the embed code, paste it into Blogger and
then test my post to see if the video actually embedded properly. THEN, I can
get back to writing my post -- only to realize that the photos I took on the
trip would be good to include too, so I open up Flickr...

As the narrative above highlights, the web currently has "silos" of media which
are exposed to the end-user. I shouldn't have to care that YouTube is where
videos live. Or which codecs YouTube supports. I should be able to just upload
my video directly in Blogger, pay no attention to where its being stored and
put it in my post. Similarly, if the video is already online, I shouldn't have
to figure out if the embed code from Vimeo is different than the one on
YouTube. I should just be able to select my video and put it in my blog post --
ideally from right within Blogger. And this should apply to audio, images, and
video -- all regardless of the source (my hard drive or someone else's
website).

To make things worse, we have not even begun to consider the licensing
implications, we're just discussing a format usability problem. The average
user has no concept of the intracacies of "fair use" or "attribution
share-alike". Despite all the efforts by the Creative Commons folks, these are
concepts which are very difficult for those who don't deal with such issues
daily to understand. What I want to know is "how do I get that video in my blog
post?". There should be a mechanism which distills the licensing issues down to
"can I use it or not?" Even better, the content which I am not allowed to use
in that way shouldn't even be exposed in the interface. The related problem of
"how do I let other people use my stuff without giving it away" is something
that casual content creators may or may not consider.


TERMINOLOGY
-----------

So again, SCALD is Content, Attribution, Licensing, & Distribution. The core
concepts of Scald are Scald Atoms, the Scald Unified Type system, Display
Contexts, Transcoders and Players.

WTH? Too many new concepts! In fact, Scald started in 2008, at the same time as
Drupal 6. There was very little concept about entities, view modes. Therefore,
Scald used its own terminology for concepts that came in Drupal 7.

- Scald Atom (or atomic asset): is Entity in Scald terminology.

- Scald Unified Type (or atom type): is Entity Bundle. Each atom type thus can
  have different attached fields, different view modes and different display
  settings. Why "Unified Type"? Because one type (e.g. video) can have many
  providers (e.g. local files, YouTube, Dailymotion etc.)
  and are all treated the same way (e.g. share the same player).

- Scald Display Context: is similar to Entity View mode. What make it
  different is while view modes are about field display settings, in Scald the
  atom itself (an "extra fields") could also have display settings. In each
  context (read: view mode), an atom can have a different
  transcoder (read: image style) and a different player (read: display plugin).
  It is similar to the possibility of having different displays of node title
  in different view modes
- but an atom is much more complex than a node title.

- Scald Action: is also designed to be extensible. Common actions defined in
  Scald core are: fetch (read: load), view, edit, delete. Modules can defined
  more actions. Each atom can be configured to open to certain actions. Scald
  supports a permission system per action so that access
  control works out of the box with great level of granularity.

- Transcoder: is similar to image style, but designed to work with all kinds of
  content. For example, a video or an audio transcoded to different bit rates
  for different display contexts.

- Player: is used to controlled how the atom is displayed. From that point of
  view, it is similar to a theme. However, players are pluggable and look more
  like a display plugin.

- Scald Atom Shorthand (SAS): is a format representating an atom in a context
  with options and does not use HTML markup. It could be abusively called
  "token". SAS is not required, though it helps to avoid using dangerous HTML
  markup in a text field.


INSTALLATION
------------

Scald depends on Views, CTools and has integration for Edit, CKEditor or
WYSIWYG, Token.

Other than type/context/action/transcoder/player providers, Scald has 3 types
of modules:

- Drag and Drop integration: the DnD module features drag and drop interface
  for Scald atoms. DnD support many atom libraries, however if you don't want
  to use your own, the scald_dnd_library module (requires Views) is available.

- Field integration: MEE (Multimedia Editorial Element) enhances text fields to
  support SAS conversion and atom usage tracking. The Atom Reference module
  provides an entity reference field (which is compatible with Entity Reference
  module) and a d'n'd widget. The Entity Reference module could be used as a
  drop-in replacement for Atom Reference if you don't need the d'n'd widget.

- Atom provider: lots of modules. They are in general independent and can be
  enabled when necessary.

Because Scald is modular, you need at least one module in each category to work:

- dnd: the bridge between a library and a field, it is responsible for the drag
  and drop.

- scald_dnd_library: the default library in Scald.

- a field that supports dnd: either Atom Reference field, or a text field with
  "Drag and Drop" option enabled.

- An atom provider module.

More detail on how to install/configure Scald is available at
http://drupal.org/node/1775718.
