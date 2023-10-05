FILE HASH
---------

Hashes of uploaded files, which can be found on a variety of sites from
archive.org to wikileaks.org, allow files to be uniquely identified, allow
duplicate files to be detected, and allow copies to be verified against the
original source.

File Hash module generates and stores BLAKE2b-128, BLAKE2b-160, BLAKE2b-224,
BLAKE2b-256, BLAKE2b-384, BLAKE2b-512, MD5, SHA-1, SHA-224, SHA-256, SHA-384,
SHA-512/224, SHA-512/256, SHA-512, SHA3-224, SHA3-256, SHA3-384 and/or
SHA3-512 hashes for each file uploaded to the site.

Hash algorithms can be enabled and disabled by the site administrator.

Hash values are loaded into the $file object where they are available to the
theme and other modules.

Handlers are provided for Views module compatibility. In addition, a
<media:hash> element is added for file attachments in node RSS feeds (file,
image, and media field types are supported).

Tokens are provided for the full hashes, as well as pairtree tokens useful for
content addressable storage. For example, if the MD5 hash for a file is
3998b02c5cd2723153c39701683a503b, you could store it in the files/39/98
directory using these tokens:
[file:filehash-md5-pair-1]/[file:filehash-md5-pair-2]. Note, to use these tokens
to configure the file upload directory, File Entity Paths module
(https://www.drupal.org/project/fe_paths) or File (Field) Paths module
(https://www.drupal.org/project/filefield_paths) is required.

A checkbox in File Hash settings allows duplicate uploaded files to be rejected.
This feature should be considered a proof-of-concept - you likely want better UX
for such a feature. Note, in Drupal 7, empty files are not considered duplicate
files, as such "files" may represent remote media assets, etc.

If you want to use the BLAKE2b hash algorithm, either the Sodium PHP extension
or paragonie/sodium_compat polyfill are required.
