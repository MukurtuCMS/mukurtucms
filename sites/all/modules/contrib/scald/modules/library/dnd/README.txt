This module makes a bridge to drag and drop your atoms from any library to
a text field (it could be a textfield, plain textarea or richtext textarea).
A default library (scald_dnd_library) is also shipped within the project.

Each dropped atom contain 2 parts:

- The "editor" part: is the rendered atom itself. The default library
  (scald_dnd_library) uses by default the sdl_editor_representation context to
  render it. This part should generally not be modified, it could be in HTML
  format, or the token-like SAS (Scald Atom Shorthand) format and it is updated
  automatically.

- The "legend" part: usually is the atom title and atom author. You can modify,
  or even delete, text in this part. A provider can omit this part by setting
  $atom->omit_legend = TRUE.

