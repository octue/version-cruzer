#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, core_schema) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/$schema");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$schema", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, core_id) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/$id");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$id", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, core_comment) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/$comment");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$comment", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, core_ref) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/$ref");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$ref", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, core_anchor) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/$anchor");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$anchor", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, core_dynamicanchor) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/$dynamicAnchor");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$dynamicAnchor", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, core_vocabulary) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/$vocabulary");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$vocabulary", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, core_defs) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/$defs");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$defs", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, core_definitions) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/definitions");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/definitions", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, metadata_title) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/title");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/title", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, metadata_description) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/description");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/description", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, metadata_default) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/default");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/default", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, metadata_deprecated) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/deprecated");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/deprecated", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, metadata_examples) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/examples");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/examples", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, metadata_readonly) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/readOnly");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/readOnly", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, metadata_writeonly) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/writeOnly");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/writeOnly", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title,
     content_contentencoding) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/contentEncoding");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentEncoding", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title,
     content_contentmediatype) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/contentMediaType");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentMediaType", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title, content_contentschema) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/contentSchema");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentSchema", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_title,
     format_annotation_format) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "title": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/title", "/format");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/format", "/title");
}
