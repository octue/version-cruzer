sourcemeta_googletest(PROJECT octue NAME cruzer FOLDER "Octue" SOURCES cruzer_test.cc)

target_link_libraries(octue_cruzer_unit PRIVATE sourcemeta::core::json)
target_link_libraries(octue_cruzer_unit PRIVATE octue::cruzer)
