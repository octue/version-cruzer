sourcemeta_library(PROJECT octue NAME cruzer FOLDER "Octue"
  SOURCES cruzer.cc instance_locations.cc comparator.h helpers.h)

target_link_libraries(octue_cruzer PUBLIC sourcemeta::core::json)
target_link_libraries(octue_cruzer PUBLIC sourcemeta::core::jsonpointer)
target_link_libraries(octue_cruzer PUBLIC sourcemeta::core::jsonschema)
target_link_libraries(octue_cruzer PRIVATE sourcemeta::core::regex)
