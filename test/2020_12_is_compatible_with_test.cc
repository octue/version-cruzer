#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

TEST(Cruzer_is_compatible_with_2020_12, test_1) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo",
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 2);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/type");
  EXPECT_COMPATIBILITY(left_result, 1, Compatible, "/type", "/type");

  EXPECT_EQ(right_result.size(), 2);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/type", "/title");
  EXPECT_COMPATIBILITY(right_result, 1, Compatible, "/type", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12, test_2) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/type");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/type", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12, test_3) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string",
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 2);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "/type", "/const");
  EXPECT_COMPATIBILITY(left_result, 1, Compatible, "/const", "/const");

  EXPECT_EQ(right_result.size(), 2);
  EXPECT_COMPATIBILITY(right_result, 0, Unknown, "/const", "/type");
  EXPECT_COMPATIBILITY(right_result, 1, Compatible, "/const", "/const");
}
