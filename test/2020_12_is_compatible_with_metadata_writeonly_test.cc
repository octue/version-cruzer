#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "writeOnly": true
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/format");
}
