sourcemeta_library(PROJECT octue NAME cruzer FOLDER "Octue" SOURCES cruzer.cc)

target_link_libraries(octue_cruzer PUBLIC sourcemeta::core::json)
target_link_libraries(octue_cruzer PRIVATE sourcemeta::core::jsonpointer)
target_link_libraries(octue_cruzer PRIVATE sourcemeta::core::jsonschema)
