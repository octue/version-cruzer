#ifndef OCTUE_CRUZER_TEST_MACROS_H_
#define OCTUE_CRUZER_TEST_MACROS_H_

#define COMPARE_TWO_WAY_2020_12(left_schema, right_schema, left_output,        \
                                right_output)                                  \
  const auto left_output{octue::cruzer::is_compatible_with(                    \
      left_schema, right_schema,                                               \
      "https://json-schema.org/draft/2020-12/schema",                          \
      "https://json-schema.org/draft/2020-12/schema")};                        \
  const auto right_output{octue::cruzer::is_compatible_with(                   \
      right_schema, left_schema,                                               \
      "https://json-schema.org/draft/2020-12/schema",                          \
      "https://json-schema.org/draft/2020-12/schema")};

#define EXPECT_OPTIONAL_POINTER(expected_pointer, expected_value)              \
  if (std::optional<sourcemeta::core::JSON::String>{expected_value}            \
          .has_value()) {                                                      \
    EXPECT_TRUE((expected_pointer).has_value());                               \
    EXPECT_EQ(sourcemeta::core::to_string((expected_pointer).value()),         \
              expected_value);                                                 \
  } else {                                                                     \
    EXPECT_FALSE((expected_pointer).has_value());                              \
  }

#define EXPECT_COMPATIBILITY(expected_traces, expected_index,                  \
                             expected_compatibility, expected_left_pointer,    \
                             expected_right_pointer)                           \
  EXPECT_EQ((expected_traces).at((expected_index)).compatibility,              \
            octue::cruzer::Compatibility::expected_compatibility);             \
  EXPECT_EQ(sourcemeta::core::to_string(                                       \
                (expected_traces).at((expected_index)).left),                  \
            expected_left_pointer);                                            \
  EXPECT_OPTIONAL_POINTER((expected_traces).at((expected_index)).right,        \
                          expected_right_pointer);

#endif
