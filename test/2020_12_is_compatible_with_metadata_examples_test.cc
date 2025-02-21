#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_schema) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_id) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_comment) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_ref) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_anchor) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_dynamicanchor) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_vocabulary) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_defs) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_definitions) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_title) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     metadata_description) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_default) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_deprecated) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_examples) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_readonly) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_writeonly) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     content_contentencoding) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     content_contentmediatype) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     content_contentschema) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}
