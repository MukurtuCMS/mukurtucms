api = 2
core = 7.x


;;;;;;;;;;
;; Core ;;
;;;;;;;;;;

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

;;; Field
; Required by treeable, which is currently used by sub-collections.
projects[field][patch][] = core/field-schema-alter-691932-105.patch

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

;;; Colorbox
; Enable Jack Moore's Zoom library to work on top of the Colorbox images
projects[colorbox][patch][] = contrib/zoom_on_colorbox.patch

;;; Community Tags
; PHP Notice: Undefined variables: user and terms_to_add
projects[community_tags][patch][] = https://www.drupal.org/files/issues/community_tags-undefined-variables-7.x-1.x-2420969-1_0.patch

;;; Ctools
; Modal dialog position after ajax load is not refreshed
projects[ctools][patch][] = https://www.drupal.org/files/issues/ctools-fix_modal_position_after_ajax-1803104-25.patch

;;; Dummy Image
; The 'For missing images' option will always fail
projects[dummyimage][patch][] = https://www.drupal.org/files/issues/dummyimage_missing_1728026-5.patch

;;; Entity
; Prevent error from workflow (https://www.drupal.org/project/entity/issues/2289693)
projects[entity][patch][] = contrib/entity_undefined_entity_get_info-2289693-2.patch

;;; Entity Reference
; Forbid to use duplicate entities in entityreference field
projects[entityreference][patch][] = https://www.drupal.org/files/2010488-forbid-duplicate-entities-in-entityreference-field_0.patch

;;; Feeds
; These four patches all support feeds import using a subset of fields (not touching existing data for missing fields)
; Keep track of which fields were given by the feeds source
projects[feeds][patch][] = contrib/0001-Add-new-input-fields-property-to-FeedsParser-class.patch
; Do not clear fields that were not provided in the source
projects[feeds][patch][] = contrib/0001-Add-support-for-partial-content-updates.patch
; For Feeds CSV, keep track of the field headers, these are our input fields
projects[feeds][patch][] = contrib/0001-Change-the-FeedsCSVParser-class-to-use-the-new-input.patch
; Fix feeds processor to work with partial updating of scald atoms as well
projects[feeds][patch][] = contrib/0002-Add-support-for-partial-updating-of-scald-atoms.patch
; Skip OG field validation for admins
projects[feeds][patch][] = contrib/0001-Skip-protocol-field-OG-validation-during-import-for-.patch

;;; Feeds Tamper
; Alter required field tamper to allow 0 as value.
; Mukurtu Export change to support feed imports using a subset of fields. Treat single element arrays containing
; a single empty string as empty.
projects[feeds_tamper][patch][] = contrib/0001-Alter-required-field-tamper-to-allow-0-as-value.patch

;;; Fullcalendar Create
; Contributed patch:
; 1. Send params to event create as $_GET instead of $_POST
; 2. Use link instead of modal for creating event from clicking on day.
projects[fullcalendar_create][patch][] = https://www.drupal.org/files/issues/fullcalendar_create_no_modal-1885688-28.patch
; Custom patch:
; Pass the calendar NID to the add event form, and set the destination to return to the current node (CP or calendar) after adding event.
projects[fullcalendar_create][patch][] = contrib/alter_add_event_link_path.patch

;;; Mailhandler
; Do not show the mailhandler need-to-create-mailbox message because it gets created by collab tools config and this would confuse users
projects[mailhandler][patch][] = contrib/do_not_show_mailhandler_mailbox_message.patch

;;; Organic Groups
; Allow Groups Audience field for Feeds Mapping
projects[og][patch][] = https://www.drupal.org/files/1298238-feeds-og-audience-mapper.patch
; 1. Use custom mukurtu permission logic when editing nodes-in-CPs; 2. Fix bug where Community admins get edit perms on CP nodes therein, even if they should not have that permission.
projects[og][patch][] = contrib/132925713-Apply-Mukurtu-og-patches.patch
; Second part of patch to skip OG field validation for admins during feeds import
projects[og][patch][] = contrib/0002-Skip-protocol-field-OG-validation-during-import-for-.patch

;;; Organic groups invite
; Comment out view modification for group members admin view
projects[og_invite][patch][] = contrib/0001-Go-back-to-using-default-view-but-remove-og_invite-v.patch

;;; Geofield & Geofield Gmap
; Feeds Import Not Saving Geofield
projects[geofield][patch][] = https://www.drupal.org/files/issues/geofield-feeds_import_not_saving-2534822-17.patch

;;; Partial Date
; Add property info callback
projects[partial_date][patch][] = https://www.drupal.org/files/issues/add_property_info-2781135-2.patch

;;; Owl Carousel
; Add ID to handle multiple carousels
projects[owlcarousel][patch][] = contrib/0001-Add-ID-to-handle-multiple-carousels.patch

;;; Quicktabs
; Remember collaboration parent page tab on CP, so that when a child page is added, it will return to the parent tab.
; This is from https://www.drupal.org/files/issues/quicktabs-tab-history-1454486-35.patch with a very minor edit to the JS to only remember tab history for the CP quicktabs (otherwise it remembers tab history for Community Records as well, which we don't want).
projects[quicktabs][patch][] = contrib/remember_cp_collab_tab.patch

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
; In scald_invoke_atom_access, pass account variable to user_access call
projects[scald][patch][] = contrib/scald_atom_access_account_parameter.patch

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

;;; Search API DB
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
; Change delimiter from coma to semi-colon
;projects[views][patch][] = contrib/109315810-Views-Change-delimiter-from-comma-to-semi-colon.patch

;;; Views Data Export
; Fixes issue where the first row in a data export is empty
projects[views_data_export][patch][] = https://www.drupal.org/files/issues/2018-10-16/views_data_export-empty-row-after-export-2902923-2.patch
; Add XML multival handling
projects[views_data_export][patch][] = https://www.drupal.org/files/issues/2018-11-01/1102298-multiple-values-support-16.patch
