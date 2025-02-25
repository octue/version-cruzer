#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "contentEncoding": "base64"
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base16"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/type");
}
