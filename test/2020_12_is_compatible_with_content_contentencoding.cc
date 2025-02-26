#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_schema) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/$schema");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$schema", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_id) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/$id");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$id", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_comment) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/$comment");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$comment", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_ref) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/$ref");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$ref", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_anchor) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/$anchor");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$anchor", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     core_dynamicanchor) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding",
                       "/$dynamicAnchor");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$dynamicAnchor",
                       "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     core_vocabulary) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding",
                       "/$vocabulary");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$vocabulary",
                       "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_defs) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/$defs");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/$defs", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     core_definitions) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding",
                       "/definitions");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/definitions",
                       "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_title) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/title");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/title", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_description) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding",
                       "/description");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/description",
                       "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_default) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/default");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/default", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_deprecated) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/deprecated");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/deprecated",
                       "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_examples) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/examples");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/examples", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_readonly) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/readOnly");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/readOnly", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_writeonly) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/writeOnly");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/writeOnly", "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     content_contentencoding) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base16"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding",
                       "/contentEncoding");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentEncoding",
                       "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     content_contentmediatype) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding",
                       "/contentMediaType");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentMediaType",
                       "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     content_contentschema) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding",
                       "/contentSchema");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/contentSchema",
                       "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     format_annotation_format) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Skip, "/contentEncoding", "/format");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Skip, "/format", "/contentEncoding");
}
