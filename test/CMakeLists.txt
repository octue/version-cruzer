sourcemeta_googletest(PROJECT octue NAME cruzer FOLDER "Octue"
  SOURCES macros.h index_test.cc
    2020_12_is_compatible_with_boolean_true_test.cc
    2020_12_is_compatible_with_boolean_false_test.cc
    2020_12_is_compatible_with_content_contentencoding.cc
    2020_12_is_compatible_with_content_contentmediatype.cc
    2020_12_is_compatible_with_content_contentschema.cc
    2020_12_is_compatible_with_empty_test.cc
    2020_12_is_compatible_with_format_annotation_format_test.cc
    2020_12_is_compatible_with_core_anchor_test.cc
    2020_12_is_compatible_with_core_comment_test.cc
    2020_12_is_compatible_with_core_definitions_test.cc
    2020_12_is_compatible_with_core_defs_test.cc
    2020_12_is_compatible_with_core_dynamicanchor_test.cc
    2020_12_is_compatible_with_core_id_test.cc
    2020_12_is_compatible_with_core_ref_test.cc
    2020_12_is_compatible_with_core_schema_test.cc
    2020_12_is_compatible_with_core_vocabulary_test.cc
    2020_12_is_compatible_with_metadata_default_test.cc
    2020_12_is_compatible_with_metadata_deprecated_test.cc
    2020_12_is_compatible_with_metadata_description_test.cc
    2020_12_is_compatible_with_metadata_examples_test.cc
    2020_12_is_compatible_with_metadata_readonly_test.cc
    2020_12_is_compatible_with_metadata_title_test.cc
    2020_12_is_compatible_with_metadata_writeonly_test.cc
    2020_12_is_compatible_with_validation_const_test.cc
    2020_12_is_compatible_with_validation_enum_test.cc
    2020_12_is_compatible_with_validation_required_test.cc
    2020_12_is_compatible_with_validation_type_test.cc
    2020_12_is_compatible_with_test.cc
    2020_12_version_test.cc)

target_link_libraries(octue_cruzer_unit PRIVATE octue::cruzer)
