api = 2
core = 7.x


;;;;;;;;;;
;; Core ;;
;;;;;;;;;;

; Fix a PHP8 fatal error issue with the Batch API sending the key of the redirect path when it should not. This occurs at the end of a Mukurtu CSV batch export.
projects[drupal][patch][] = core/drop_path_key_from_batch_redirect.patch

; During feeds imports, do not fail fatally if field_comm_records_mm $items is an empty string instead of an array.
projects[drupal][patch][] = core/check_items_is_array_in_field_filter_items.patch

; Custom logo and favicon stored in private filesystem if it is the default.
projects[drupal][patch][] = https://www.drupal.org/files/issues/1087250.logo-public-filesystem.057.patch

; Ignore files dir contents but include files dir itself.
projects[drupal][patch][] = core/ignore_files_dir_contents_but_include_files_dir_itself.patch

; Mukurtu custom default.settings.php.
projects[drupal][patch][] = core/mukurtu_custom_default_settings_file.patch

; The Drupal side of this multipatch has been incorporated as of Drupal 7.102.
; However, this multipatch cannot be deleted entirely because there are some
; Mukurtu patches that must remain.
; Multipatch combination of 3 separate custom patches from before this was cleaned up in drush patchfile:
; 1150608_use_comma_for_tax_delimiter_and_allow_quotes.patch
; 109315810-Change-delimiter-from-comma-to-semi-colon.patch
; 117661693-Stop-double-quoting-quotes-in-term-autocomplete.patch
projects[drupal][patch][] = core/multipatch-109315810-109315810-109315810.patch

; Redirect on empty database for Reclaim.
projects[drupal][patch][] = core/install_redirect_on_empty_database-728702-17.patch

; Chrome collapsible fieldset bug (https://www.drupal.org/project/drupal/issues/3243853).
projects[drupal][patch][] = core/seven-collapsible-fieldset-chrome-fix.patch

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

;;; Argument Filters
; Make arg filters compatible with PHP 8
projects[argfilters][patch][] = contrib/make_arg_filters_module_php8_compatible.patch

;;; Bootstrap (theme)
; Add First and Last Classes to Lists
projects[bootstrap][patch][] = contrib/150281138-add-first-last-classes-to-lists.patch
; Do not skip over text format fields
projects[bootstrap][patch][] = contrib/150281089-Dont-skip-over-text_format-fields.patch

;;; Cer
; PHP 8 deprecation warnings
projects[cer][patch][] = contrib/0001-Suppress-deprecation-warnings-for-PHP-8.patch
; More PHP 8 deprecation warnings
projects[cer][patch][] = contrib/0002-Suppress-deprecation-warnings-for-PHP-8.patch

;;; Colorbox
; Enable Jack Moore's Zoom library to work on top of the Colorbox images
projects[colorbox][patch][] = contrib/zoom_on_colorbox.patch

;;; Community Tags
; PHP Notice: Undefined variables: user and terms_to_add
projects[community_tags][patch][] = https://www.drupal.org/files/issues/community_tags-undefined-variables-7.x-1.x-2420969-1_0.patch

;;; Ctools
; Modal dialog position after ajax load is not refreshed
projects[ctools][patch][] = https://www.drupal.org/files/issues/2021-02-03/ctools-fix_modal_position_after_ajax-1803104-28.patch

;;; Dummy Image
; The 'For missing images' option will always fail
projects[dummyimage][patch][] = https://www.drupal.org/files/issues/dummyimage_missing_1728026-5.patch

;;; ECK
; PHP 8 deprecation warnings
projects[eck][patch][] = contrib/0001-Suppress-ECK-PHP-8-deprecation-warnings.patch

;;; Entity
; Prevent error from workflow (https://www.drupal.org/project/entity/issues/2289693)
projects[entity][patch][] = contrib/entity_undefined_entity_get_info-2289693-2.patch
; Multiple EMW failures of unknown data property after PHP8 update resolved by this patch
projects[entity][patch][] = https://www.drupal.org/files/issues/entity-metadata-wrapper-exception-11768576-4_0.patch

;;; Entity Reference
; Forbid to use duplicate entities in entityreference field
projects[entityreference][patch][] = https://www.drupal.org/files/2010488-forbid-duplicate-entities-in-entityreference-field_0.patch
projects[entityreference][patch][] = contrib/0001-Fix-for-related-content-field-for-single-type.patch
projects[entityreference][patch][] = contrib/Add-quicker-method-to-load-titles-for-nodes.patch

;;; Entity Reference Prepopulate
; Entity Reference Prepopulate PHP 7.4 patch
projects[entityreference_prepopulate][patch][] = https://www.drupal.org/files/issues/2020-06-10/3115641-unparenthesized-ternary-deprecated.patch

;;; Facet API
; PHP 8 deprecation warnings
projects[facetapi][patch][] = contrib/0001-Facet-API-Suppress-PHP-8-deprecation-warnings.patch

;;; Features extras
; Default param patch
projects[fe_block][patch][] = contrib/0001-Remove-default-parameter-value-for-PHP-8.patch
; Another default param
projects[fe_block][patch][] = contrib/0001-Remove-another-default-argument.patch

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
; Change language handling for taxonomy import
projects[feeds][patch][] = contrib/0001-Mukurtu-language-handling-for-taxonomy-import.patch
; Change language handling for text import
projects[feeds][patch][] = contrib/0001-Use-new-field-language-handling-in-feeds.patch

;;; Feeds Comment Processor
; Make feeds_comment_processor compatible with PHP8
projects[feeds_comment_processor][patch][] = https://www.drupal.org/files/issues/2020-09-28/compatibility_with_feeds_processor-3171586.patch

;;; Feeds Files
; Change entityValidate definition
projects[feeds_file][patch][] = contrib/0001-Add-parameter-to-entityValidate-to-stop-warning.patch

;;; Feeds Tamper
; Alter required field tamper to allow 0 as value.
; Mukurtu Export change to support feed imports using a subset of fields. Treat single element arrays containing
; a single empty string as empty.
projects[feeds_tamper][patch][] = contrib/0001-Alter-required-field-tamper-to-allow-0-as-value.patch

;;; Fullcalendar Create
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
; OG Contexts PHP 8 patch
projects[og][patch][] = contrib/og-3306532-5-php8-comp.patch
; Array to bool conversion fix
projects[og][patch][] = contrib/0001-Array-to-bool-conversion-not-supported-in-PHP-8.patch

;;; Organic groups invite
; Comment out view modification for group members admin view
projects[og_invite][patch][] = contrib/0001-Go-back-to-using-default-view-but-remove-og_invite-v.patch

;;; Geofield & Geofield Gmap
; Feeds Import Not Saving Geofield
; projects[geofield][patch][] = https://www.drupal.org/files/issues/geofield-feeds_import_not_saving-2534822-17.patch

;;; Partial Date
; Add property info callback
projects[partial_date][patch][] = https://www.drupal.org/files/issues/add_property_info-2781135-2.patch
; PHP 7.3 patch
projects[partial_date][patch][] = https://www.drupal.org/files/issues/2020-01-16/partial_date-php_73_compat.patch

;;; Owl Carousel
; Add ID to handle multiple carousels
projects[owlcarousel][patch][] = contrib/0001-Add-ID-to-handle-multiple-carousels.patch
; PHP 8 deprecation fix
projects[owlcarousel][patch][] = contrib/0001-PHP-8-deprecation-fix.patch

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
; PHP 7.4 patch
projects[scald][patch][] = contrib/issue-3248924.patch
; Operation Link order
projects[scald][patch][] = contrib/0001-Switch-order-of-the-atom-links.patch

;;; Scald Feeds
; Add scald feeds metadata support
projects[scald_feeds][patch][] = contrib/83564940-add_scald_metadata_support.patch

;;; Scald Soundcloud
; Respect quoted strings in Soundcloud tags
projects[scald_soundcloud][patch][] = contrib/Respect-quoted-strings-in-Soundcloud-tags.patch
; Don't use versioned API URLs
projects[scald_soundcloud][patch][] = contrib/0001-Default-to-not-using-versioned-URL.patch

;;; Search API
; Fix 'For missing images' option will always fail
projects[search_api][patch][] = https://www.drupal.org/files/issues/search_api-fix_access_info_indexing.patch
; PHP 8 deprecation warning
projects[search_api][patch][] = contrib/0001-Fix-deprecation-warning-null-in-substr.patch
; Modify dictionary search results based on custom sort
projects[search_api_db][patch][] = contrib/modify_dictionary_search_results_based_on_custom_sort.patch

;;; Search API DB
; Change Seach API DB to pull regex from Search API
projects[search_api_db][patch][] = contrib/0001-Pull-regex-from-config.patch

;;; Search API Glossary
; 1. Index display and sort ALL characters. 2. Option to skip padding
projects[search_api_glossary][patch][] = contrib/index_display_and_sort_ALL_characters_and_option_to_skip_padding.patch

;;; Services
; Fix for submitting multi-value fields.
projects[services][patch][] = https://www.drupal.org/files/issues/2019-05-09/services-multivalue_fields_fix-2224803-78.patch
; Custom validation on paragraph fields.
projects[services][patch][] = contrib/custom_validation_on_paragraph_fields.patch
; PHP 8 fix
projects[services][patch][] = contrib/0001-Function-signature-change-for-PHP-8.patch

;;; Services Field Collection
; Fix the sandbox project services_field_collection so that field collections can be created.
projects[services_field_collection][patch][] = contrib/fix_services_field_collection_create.patch

;;; Tree (treeable)
; Make treeable compatible with PHP8
projects[tree][patch][] = contrib/make_treeable_php8_compatible.patch

;;; Views
; Handle array in view definition
projects[views][patch][] = contrib/0001-Handle-array-type-for-view-definition.patch
; Change delimiter from coma to semi-colon
;projects[views][patch][] = contrib/109315810-Views-Change-delimiter-from-comma-to-semi-colon.patch

;;; Views Data Export
; Fixes issue where the first row in a data export is empty
projects[views_data_export][patch][] = https://www.drupal.org/files/issues/2018-10-16/views_data_export-empty-row-after-export-2902923-2.patch
; Add XML multival handling
projects[views_data_export][patch][] = https://www.drupal.org/files/issues/2018-11-01/1102298-multiple-values-support-16.patch
