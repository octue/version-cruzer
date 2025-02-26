#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "$schema": "https://json-schema.org/draft/2020-12/schema"
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_core_schema, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema", "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_core_schema, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$schema", "/type");
}
