#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_schema) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/$schema");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$schema", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_id) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/$id");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$id", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_comment) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/$comment");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$comment", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_ref) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/$ref");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$ref", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_anchor) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/$anchor");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$anchor", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     core_dynamicanchor) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/$dynamicAnchor");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$dynamicAnchor", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     core_vocabulary) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/$vocabulary");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$vocabulary", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_defs) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/$defs");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$defs", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     core_definitions) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/definitions");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/definitions", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_title) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/title");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/title", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_description) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/description");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/description", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_default) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/default");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/default", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_deprecated) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/deprecated");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/deprecated", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_examples) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/examples");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/examples", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_readonly) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/readOnly");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/readOnly", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_writeonly) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/writeOnly");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/writeOnly", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     content_contentencoding) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/contentEncoding");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentEncoding", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     content_contentmediatype) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/contentMediaType");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentMediaType", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     content_contentschema) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/contentSchema");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentSchema", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     format_annotation_format) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "format": "uuid"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/format", "/format");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/format", "/format");
}
