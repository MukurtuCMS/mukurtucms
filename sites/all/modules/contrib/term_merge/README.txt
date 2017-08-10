Term Merge
------------------------
by:
 * Max Nylin <max@articstudios.se>
 * Oleksandr Trotsenko

Description
-----------
When using taxonomy for free tagging purposes, it's easy to end up with several
terms having the same meaning. This may be due to spelling errors, or different
users simply making up synonymous terms as they go.

You, as an administrator, may then want to correct such errors or unify
synonymous terms, thereby pruning the taxonomy to a more manageable set. This
module allows you to merge multiple terms into one, while updating all fields
referring to those terms to refer to the replacement term instead.

Currently, the module only acts on:
 * fields of the following types: taxonomy term reference, entity reference, and
   other fields that correctly define their foreign keys
 * Views Taxonomy Term filter handlers
 * Redirects

The term merging may happen in 2 flavors. You can either manually indicate what
terms should be merged or you can use duplicate suggestion tool for this
purpose. This tool intends to scan your vocabulary and to detect such terms that
are likely to be duplicates. You will then only review the list of suggested
duplicates and will schedule for merging only those that actually are
duplicates. The heuristics through which duplicate tool determines potential
synonymous terms are made to be extensible by other modules. Refer to Term Merge
advanced help if you want to write a custom one, though the module itself ships
with the following heuristics:
* search by the same name
* search by the same description
* search by the same parent

You can indicate which specific heuristics should be used for searching
duplicates within the UI of duplicate suggestion tool.

Integration
-------------
Currently module integrates with the following core and contributed modules:
 * Redirect module (http://drupal.org/project/redirect). During term merging you
   may set up SEO friendly redirects from the branch terms to point to the trunk
   term.
 * Synonyms module (http://drupal.org/project/synonyms). During term merging you
   will be able to choose a trunk term's field into which all the branch terms
   will be added as synonyms (until cardinality limit for that field is
   reached).
 * Hierarchical Select (http://drupal.org/project/hierarchical_select). If
   Hierarchical Select module is configured to be used for working with
   Taxonomy, its widget will be shown on the form, where you choose what terms
   to merge.
 * Views (http://drupal.org/project/views). If the branch terms are to be
   deleted after the merging process, you could end up having some Views filters
   to filter on no longer existing terms. Term Merge module, while merging
   terms, will update those filters to filter not on the branch term, but on the
   trunk term. This way you will not have senseless filters and will not have to
   update them manually.

Requirements
-------------
The modules requires enabled the following modules:
 * Taxonomy module (ships with Drupal core)
 * Entity API (https://drupal.org/project/entity)
 * cTools (https://www.drupal.org/project/ctools)

Installation
------------
 * Copy the module's directory to your modules directory and activate the
 module.
