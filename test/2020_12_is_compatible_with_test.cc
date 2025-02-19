#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

TEST(Cruzer_is_compatible_with_2020_12, boolean_true_true) {
  const sourcemeta::core::JSON left{true};
  const sourcemeta::core::JSON right{true};

  const auto result{octue::is_compatible_with(
      left, right,

      // We need to manually specify dialects for boolean schemas
      "https://json-schema.org/draft/2020-12/schema",
      "https://json-schema.org/draft/2020-12/schema")};

  EXPECT_EQ(result.size(), 1);
  EXPECT_COMPATIBILITY(result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12, boolean_true_false) {
  const sourcemeta::core::JSON left{true};
  const sourcemeta::core::JSON right{false};

  const auto result{octue::is_compatible_with(
      left, right,

      // We need to manually specify dialects for boolean schemas
      "https://json-schema.org/draft/2020-12/schema",
      "https://json-schema.org/draft/2020-12/schema")};

  EXPECT_EQ(result.size(), 1);
  EXPECT_COMPATIBILITY(result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12, boolean_false_true) {
  const sourcemeta::core::JSON left{false};
  const sourcemeta::core::JSON right{true};

  const auto result{octue::is_compatible_with(
      left, right,

      // We need to manually specify dialects for boolean schemas
      "https://json-schema.org/draft/2020-12/schema",
      "https://json-schema.org/draft/2020-12/schema")};

  EXPECT_EQ(result.size(), 1);
  EXPECT_COMPATIBILITY(result, 0, Incompatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12, boolean_false_false) {
  const sourcemeta::core::JSON left{false};
  const sourcemeta::core::JSON right{false};

  const auto result{octue::is_compatible_with(
      left, right,

      // We need to manually specify dialects for boolean schemas
      "https://json-schema.org/draft/2020-12/schema",
      "https://json-schema.org/draft/2020-12/schema")};

  EXPECT_EQ(result.size(), 1);
  EXPECT_COMPATIBILITY(result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12, empty_empty) {
  const auto left{sourcemeta::core::parse_json(R"JSON({})JSON")};
  const auto right{sourcemeta::core::parse_json(R"JSON({})JSON")};

  const auto result{octue::is_compatible_with(
      left, right, "https://json-schema.org/draft/2020-12/schema",
      "https://json-schema.org/draft/2020-12/schema")};

  EXPECT_EQ(result.size(), 1);
  EXPECT_COMPATIBILITY(result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12, core_schema_core_schema_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  const auto result{octue::is_compatible_with(left, right)};

  EXPECT_EQ(result.size(), 1);
  EXPECT_COMPATIBILITY(result, 0, Compatible, "", "");
}
