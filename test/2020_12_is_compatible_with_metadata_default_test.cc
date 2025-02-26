#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, core_schema) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/$schema");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$schema", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, core_id) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/$id");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$id", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, core_comment) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/$comment");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$comment", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, core_ref) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/$ref");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$ref", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, core_anchor) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/$anchor");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$anchor", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, core_dynamicanchor) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/$dynamicAnchor");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$dynamicAnchor", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, core_vocabulary) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/$vocabulary");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$vocabulary", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, core_defs) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/$defs");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$defs", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, core_definitions) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/definitions");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/definitions", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, metadata_title) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/title");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/title", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, metadata_description) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/description");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/description", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, metadata_default) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/default");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/default", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, metadata_deprecated) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/deprecated");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/deprecated", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, metadata_examples) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/examples");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/examples", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, metadata_readonly) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/readOnly");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/readOnly", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default, metadata_writeonly) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/writeOnly");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/writeOnly", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default,
     content_contentencoding) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/contentEncoding");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentEncoding", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default,
     content_contentmediatype) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/contentMediaType");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentMediaType", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default,
     content_contentschema) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/contentSchema");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentSchema", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_default,
     format_annotation_format) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "default": {}
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/default", "/format");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/format", "/default");
}
