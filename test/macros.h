#ifndef OCTUE_CRUZER_TEST_MACROS_H_
#define OCTUE_CRUZER_TEST_MACROS_H_

#define EXPECT_UNKNOWN(container, expected_from, expected_to, expected_traces) \
  const auto container{octue::cruzer::version(expected_from, expected_to)};    \
  EXPECT_FALSE(container.version.has_value());                                 \
  EXPECT_EQ(container.traces.size(), (expected_traces));

#define EXPECT_VERSION(container, expected_from, expected_to,                  \
                       expected_version, expected_traces)                      \
  const auto container{octue::cruzer::version(expected_from, expected_to)};    \
  EXPECT_TRUE(container.version.has_value());                                  \
  EXPECT_EQ(container.version.value(),                                         \
            octue::cruzer::SemVer::expected_version);                          \
  EXPECT_EQ(container.traces.size(), (expected_traces));

#define EXPECT_OPTIONAL_POINTER(current, expected)                             \
  if (std::optional<std::string>{expected}.has_value()) {                      \
    EXPECT_TRUE(current.has_value());                                          \
    EXPECT_EQ(sourcemeta::core::to_string(current.value()),                    \
              std::optional<std::string>{expected}.value());                   \
  } else {                                                                     \
    EXPECT_FALSE(current.has_value());                                         \
  }

#define EXPECT_TRACE(container, expected_index, expected_compatibility,        \
                     expected_left_pointer, expected_right_pointer)            \
  EXPECT_EQ(container.traces.at(expected_index).compatibility,                 \
            octue::cruzer::Compatibility::expected_compatibility);             \
  EXPECT_OPTIONAL_POINTER(container.traces.at(expected_index).left,            \
                          expected_left_pointer);                              \
  EXPECT_OPTIONAL_POINTER(container.traces.at(expected_index).right,           \
                          expected_right_pointer);

#define COMPARE_2020_12(left, right, output)                                   \
  const auto output{octue::cruzer::is_compatible_with(                         \
      left, right, "https://json-schema.org/draft/2020-12/schema",             \
      "https://json-schema.org/draft/2020-12/schema")};

#define COMPARE_TWO_WAY_2020_12(left_schema, right_schema, left_output,        \
                                right_output)                                  \
  COMPARE_2020_12(left_schema, right_schema, left_output);                     \
  COMPARE_2020_12(right_schema, left_schema, right_output);

#define EXPECT_COMPATIBILITY(expected_traces, expected_index,                  \
                             expected_compatibility, expected_left_pointer,    \
                             expected_right_pointer)                           \
  EXPECT_EQ((expected_traces).at((expected_index)).compatibility,              \
            octue::cruzer::Compatibility::expected_compatibility);             \
  EXPECT_OPTIONAL_POINTER((expected_traces).at((expected_index)).left,         \
                          expected_left_pointer);                              \
  EXPECT_OPTIONAL_POINTER((expected_traces).at((expected_index)).right,        \
                          expected_right_pointer);

#define EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, other, compatibility,      \
                                            left_pointer, right_pointer)       \
  COMPARE_2020_12(schema, other, result);                                      \
  EXPECT_EQ(result.size(), 1);                                                 \
  EXPECT_COMPATIBILITY(result, 0, compatibility, left_pointer, right_pointer);

#endif
