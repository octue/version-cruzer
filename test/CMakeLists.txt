sourcemeta_googletest(PROJECT octue NAME cruzer FOLDER "Octue"
  SOURCES macros.h index_test.cc
    2020_12_is_compatible_with_boolean_true_test.cc
    2020_12_is_compatible_with_boolean_false_test.cc
    2020_12_is_compatible_with_empty_test.cc
    2020_12_is_compatible_with_core_schema_test.cc)

target_link_libraries(octue_cruzer_unit PRIVATE octue::cruzer)
