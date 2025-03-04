#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "format": "email"
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_format_annotation_format,
     validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/enum");
}
