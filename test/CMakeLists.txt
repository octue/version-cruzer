sourcemeta_googletest(PROJECT octue NAME cruzer FOLDER "Octue"
  SOURCES macros.h index_test.cc 2020_12_is_compatible_with_test.cc)

target_link_libraries(octue_cruzer_unit PRIVATE octue::cruzer)
