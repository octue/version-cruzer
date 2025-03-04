#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "$dynamicAnchor": "foo"
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_core_dynamicanchor,
     validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$dynamicAnchor",
                                      "/required");
}
