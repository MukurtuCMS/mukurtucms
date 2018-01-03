api = 2
core = 7.x


;;;;;;;;;;
;; Core ;;
;;;;;;;;;;

; Fix IE11 & Chrome scrolls to the top of the page after dragging the bottom item with jquery 1.5 <-> 1.11.
projects[drupal][patch][] = https://www.drupal.org/files/issues/2843240-22.patch

; Custom logo and favicon stored in private filesystem if it is the default.
projects[drupal][patch][] = https://www.drupal.org/files/issues/1087250.logo-public-filesystem.057.patch

; Ignore files dir contents but include files dir itself.
projects[drupal][patch][] = core/ignore_files_dir_contents_but_include_files_dir_itself.patch

; Mukurtu custom default.settings.php.
projects[drupal][patch][] = core/mukurtu_custom_default_settings_file.patch

; Multipatch combination of 3 separate custom patches from before this was cleaned up in drush patchfile:
; 1150608_use_comma_for_tax_delimiter_and_allow_quotes.patch
; 109315810-Change-delimiter-from-comma-to-semi-colon.patch
; 117661693-Stop-double-quoting-quotes-in-term-autocomplete.patch
projects[drupal][patch][] = core/multipatch-109315810-109315810-109315810.patch



;;;;;;;;;;;;;;;;;;;
;; Core Projects ;;
;;;;;;;;;;;;;;;;;;;
;;; These projects are contained in core, but must be specified here by their specific project name, not "Drupal"

;;; Color
; Show added palette fields. NOTE: this was not previously applied.
projects[color][patch][] = core/789554-show-added-palette-fields.patch
; Include newly added colorable elements.
projects[color][patch][] = core/include-newly-added-colorable-elements-1236098.patch

;;; Seven (theme)
; Use Mukurtu logo during install.
projects[seven][patch][] = core/use_mukurtu_logo_during_install.patch



;;;;;;;;;;;;;
;; Contrib ;;
;;;;;;;;;;;;;

;;; Bootstrap (theme)
; Add First and Last Classes to Lists
projects[bootstrap][patch][] = contrib/150281138-add-first-last-classes-to-lists.patch
; Do not skip over text format fields
projects[bootstrap][patch][] = contrib/150281089-Dont-skip-over-text_format-fields.patch

;;; Community Tags
; PHP Notice: Undefined variables: user and terms_to_add
projects[community_tags][patch][] = https://www.drupal.org/files/issues/community_tags-undefined-variables-7.x-1.x-2420969-1_0.patch

;;; Ctools
; Modal dialog position after ajax load is not refreshed
projects[ctools][patch][] = https://www.drupal.org/files/issues/ctools-fix_modal_position_after_ajax-1803104-25.patch

;;; Dummy Image
; The 'For missing images' option will always fail
projects[dummyimage][patch][] = https://www.drupal.org/files/issues/dummyimage_missing_1728026-5.patch

;;; Entity Reference
; Forbid to use duplicate entities in entityreference field
projects[entityreference][patch][] = https://www.drupal.org/files/2010488-forbid-duplicate-entities-in-entityreference-field_0.patch

;;; Feeds Tamper
; Alter required field tamper to allow 0 as value
projects[feeds_tamper][patch][] = contrib/0001-Alter-required-field-tamper-to-allow-0-as-value.patch

;;; Organic Groups
; Allow Groups Audience field for Feeds Mapping
projects[og][patch][] = https://www.drupal.org/files/1298238-feeds-og-audience-mapper.patch
; 1. Use custom mukurtu permission logic when editing nodes-in-CPs; 2. Fix bug where Community admins get edit perms on CP nodes therein, even if they should not have that permission.
projects[og][patch][] = contrib/132925713-Apply-Mukurtu-og-patches.patch

;;; Geofield & Geofield Gmap
; Feeds Import Not Saving Geofield
projects[geofield][patch][] = https://www.drupal.org/files/issues/geofield-feeds_import_not_saving-2534822-17.patch
; Google maps API fix
projects[geofield][patch][] = https://www.drupal.org/files/issues/geofield-google-api-key-2757953-71.patch
projects[geofield_gmap][patch][] = https://www.drupal.org/files/issues/fix-api-key-not-being-used-2746209-16.patch

;;; Partial Date
; Add property info callback
projects[partial_date][patch][] = https://www.drupal.org/files/issues/add_property_info-2781135-2.patch

;;; Owl Carousel
; Add ID to handle multiple carousels
projects[owlcarousel][patch][] = contrib/0001-Add-ID-to-handle-multiple-carousels.patch

;;; Scald
; Use simple dewplayer for audio
projects[scald][patch][] = contrib/use_simple_dewplayer_for_audio.patch
; Make whole scald drawer atom row draggable
projects[scald][patch][] = contrib/make_whole_scald_drawer_atom_row_draggable.patch
; Change default scald audio html5 template
projects[scald][patch][] = contrib/Change-default-scald-audio-html5-template.patch
; Add custom hook in scald for media warnings
projects[scald][patch][] = contrib/Add-custom-hook-in-Scald-for-media-warnings.patch
; Uploaded video dimension fix. Copies the code from scald_youtube. NOTE: this was not previously applied.
projects[scald][patch][] = contrib/uploaded_video_dimension_fix.patch
; Upload video do no fill dimensions on upload. NOTE: this was not previously applied.
projects[scald][patch][] = contrib/uploaded_video_do_not_fill_dimenions_on_upload.patch

;;; Scald Feeds
; Add scald feeds metadata support
projects[scald_feeds][patch][] = contrib/83564940-add_scald_metadata_support.patch

;;; Scald Soundcloud
; Respect quoted strings in Soundcloud tags
projects[scald_soundcloud][patch][] = contrib/Respect-quoted-strings-in-Soundcloud-tags.patch

;;; Search API
; Fix 'For missing images' option will always fail
projects[search_api][patch][] = https://www.drupal.org/files/issues/search_api-fix_access_info_indexing.patch
; Modify dictionary search results based on custom sort
projects[search_api_db][patch][] = contrib/modify_dictionary_search_results_based_on_custom_sort.patch
; Change Seach API DB to pull regex from Search API
projects[search_api_db][patch][] = contrib/0001-Change-Search-API-DB-to-pull-regex-from-Search-API.patch

;;; Search API Glossary
; 1. Index display and sort ALL characters. 2. Option to skip padding
projects[search_api_glossary][patch][] = contrib/index_display_and_sort_ALL_characters_and_option_to_skip_padding.patch

;;; Services
; Fix services issue with multivals
; see https://www.drupal.org/project/services/issues/2224803
projects[services][patch][] = contrib/fix_services_multivals-2224803-comment-8844431

;;; Tree (treeable)
; Skip treeable field formatter patch
projects[tree][patch][] = contrib/skip_treeable_field_formatter.patch

;;; Views
; Taxonomy term "Representative node" views with filters and sorts don't work
projects[views][patch][] = https://www.drupal.org/files/issues/views-representative_view-1417090-82.patch
; Change delimiter from coma to semi-colon
projects[views][patch][] = contrib/109315810-Views-Change-delimiter-from-comma-to-semi-colon.patch
