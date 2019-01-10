; Open Atrium Core Makefile

api = 2
core = 7.x

; Advagg
projects[advagg][version] = 2.6
projects[advagg][subdir] = contrib

; Bootstrap Library
projects[bootstrap_library][version] = 1.4
projects[bootstrap_library][subdir] = contrib
projects[bootstrap_library][patch][2244553] = https://www.drupal.org/files/issues/bootstrap_library-jquery_version_check-2244553-8.patch

; Chosen
projects[chosen][version] = 2.0
projects[chosen][subdir] = contrib

libraries[chosen][download][type] = "get"
libraries[chosen][download][url] = "https://github.com/harvesthq/chosen/releases/download/1.0.0/chosen_v1.0.0.zip"
libraries[chosen][directory_name] = "chosen"
libraries[chosen][destination] = "libraries"

; Colorizer
projects[colorizer][version] = 1.10
projects[colorizer][subdir] = contrib

; Conditional Fields
projects[conditional_fields][version] = 3.x-dev
projects[conditional_fields][subdir] = contrib
projects[conditional_fields][download][type] = git
projects[conditional_fields][download][branch] = 7.x-3.x
projects[conditional_fields][download][revision] = 12ab0cb
projects[conditional_fields][patch][2027307] = https://www.drupal.org/files/issues/2027307-conditional_fields-export-clean-3.patch

; Conditional Style Sheets
projects[conditional_styles][version] = 2.2
projects[conditional_styles][subdir] = contrib

; Date Facets
projects[date_facets][version] = 1.0
projects[date_facets][subdir] = contrib

; Diff
projects[diff][version] = 3.3
projects[diff][subdir] = contrib

; Features Template
projects[features_template][version] = 1.0-beta2
projects[features_template][subdir] = contrib

; Feeds
projects[feeds][version] = 2.0-beta3
projects[feeds][subdir] = contrib
projects[feeds][patch][2127787] = https://www.drupal.org/files/issues/2127787-feeds-feed_nid-3.patch
projects[feeds][patch][2828605] = https://www.drupal.org/files/issues/feeds-moved-module-2828605-7.patch

; SimplePie library used by Feeds
libraries[simplepie][download][type] = "get"
libraries[simplepie][download][url] = "https://github.com/simplepie/simplepie/archive/1.3.1.tar.gz"
libraries[simplepie][directory_name] = "simplepie"
libraries[simplepie][destination] = "libraries"

; Flag
projects[flag][version] = 3.9
projects[flag][subdir] = contrib

; HTML Mail
projects[htmlmail][version] = 2.71
projects[htmlmail][subdir] = contrib

; Job Scheduler
projects[job_scheduler][version] = 2.0-alpha3
projects[job_scheduler][subdir] = contrib

; Mail System
projects[mailsystem][version] = 2.35
projects[mailsystem][subdir] = contrib

; Message
projects[message][version] = 1.12
projects[message][subdir] = contrib
projects[message][patch][2046591] = http://drupal.org/files/message-token_replace-2046591-1.patch
projects[message][patch][2040735] = http://drupal.org/files/message.target_bundles.2040735-3.patch

; Message Digest
projects[message_digest][version] = 1.0
projects[message_digest][subdir] = contrib

; Message Notify
projects[message_notify][version] = 2.5
projects[message_notify][subdir] = contrib

; Message Subscribe
projects[message_subscribe][version] = 1.0-rc2
projects[message_subscribe][subdir] = contrib

; MimeMail
projects[mimemail][version] = 1.1
projects[mimemail][subdir] = contrib
projects[mimemail][patch][2552613] = https://www.drupal.org/files/issues/mimemail.fix-itok.2552613-22.patch

; Organic Groups
projects[og][version] = 2.9
projects[og][subdir] = contrib
; Related to Entity Reference revisions patch (1837650)
projects[og][patch][2363599] = http://drupal.org/files/issues/og-2363599-1-infinite-loop-entityreference-revisions-load.patch
; For select2widget configuration
projects[og][patch][2403619] = https://www.drupal.org/files/issues/2403619-og_widget_settings-1.patch
; Fix group manager regranted default
projects[og][patch][2411041] = https://www.drupal.org/files/issues/2411041-og-og_is_member-5-12.patch
; Prevent infinite loops in og_context
projects[og][patch][2717489] = https://www.drupal.org/files/issues/og_context_infinite_loop-2717489-10.patch

; Og menu single
projects[og_menu_single][version] = 1.0-beta2
projects[og_menu_single][subdir] = contrib

; OG Session Context
projects[og_session_context][version] = 1.0
projects[og_session_context][subdir] = contrib

; Og Variables
projects[og_variables][version] = 1.0
projects[og_variables][subdir] = contrib

; Organic Groups Vocabulary
projects[og_vocab][version] = 1.2
projects[og_vocab][subdir] = contrib
; patch to support subgroups
projects[og_vocab][patch][2039009] = https://www.drupal.org/files/issues/2039009-og_vocab-share-29.patch
projects[og_vocab][patch][2399883] = https://www.drupal.org/files/issues/2399883-og_vocab-menuitem-4.patch
projects[og_vocab][patch][2503991] = https://www.drupal.org/files/issues/og_vocab_support_custom_widget_settings-2503991-1.patch
projects[og_vocab][patch][2242387] = https://www.drupal.org/files/issues/og_vocab_override_widget_settings-2242387-2.patch
projects[og_vocab][patch][2503997] = https://www.drupal.org/files/issues/og_vocab_add_support_for_select2widget-2503997-1.patch

; Panels Custom Error
projects[panels_customerror][version] = 1.0
projects[panels_customerror][subdir] = contrib

; Paragraphs
projects[paragraphs][version] = 1.0-rc5
projects[paragraphs][subdir] = contrib
projects[paragraphs][patch][2458801] = https://www.drupal.org/files/issues/paragraphs-instructions_setting-2458801-14.patch
projects[paragraphs][patch][2481627] = https://www.drupal.org/files/issues/paragraphs-modal_targets_wrong_id-2481627-3.patch
projects[paragraphs][patch][2560601] = https://www.drupal.org/files/issues/2560601-paragraphs-join_extra-2.patch

; Real Name
projects[realname][version] = 1.3
projects[realname][subdir] = contrib

; References Dialog
projects[references_dialog][version] = 1.0-beta2
projects[references_dialog][subdir] = contrib

; Reference Option Limit
projects[reference_option_limit][version] = 1.x-dev
projects[reference_option_limit][subdir] = contrib
projects[reference_option_limit][download][type] = git
projects[reference_option_limit][download][branch] = 7.x-1.x
projects[reference_option_limit][download][revision] = 0ea5303
projects[reference_option_limit][patch][1986532] = https://www.drupal.org/files/issues/1986532-reference_option_limit-og-7.patch
projects[reference_option_limit][patch][1986526] = http://drupal.org/files/1986526_reference_option_limit_12.patch


; Select 2 Widget
projects[select2widget][version] = 2.9
projects[select2widget][subdir] = contrib

libraries[select2][download][type] = "get"
libraries[select2][download][url] = "https://github.com/ivaynberg/select2/archive/3.5.2.tar.gz"
libraries[select2][directory_name] = "select2"
libraries[select2][destination] = "libraries"

; Variable
projects[variable][version] = 2.5
projects[variable][subdir] = contrib

; Views Load More
projects[views_load_more][version] = 1.5
projects[views_load_more][subdir] = contrib

; Ultimate Cron
projects[ultimate_cron][version] = 2.6
projects[ultimate_cron][subdir] = contrib
