#ifndef OCTUE_CRUZER_TEST_MACROS_H_
#define OCTUE_CRUZER_TEST_MACROS_H_

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
            octue::Compatibility::expected_compatibility);                     \
  EXPECT_OPTIONAL_POINTER((expected_traces).at((expected_index)).left,         \
                          expected_left_pointer);                              \
  EXPECT_OPTIONAL_POINTER((expected_traces).at((expected_index)).right,        \
                          expected_right_pointer);

#endif
