#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "definitions": {
    "foo": false
  }
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions, validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_core_definitions,
     validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/definitions",
                                      "/uniqueItems");
}
