#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "deprecated": true
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_deprecated,
     validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/deprecated",
                                      "/pattern");
}
