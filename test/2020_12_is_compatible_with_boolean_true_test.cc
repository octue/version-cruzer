#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const sourcemeta::core::JSON schema{true};

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, true) {
  const sourcemeta::core::JSON right{true};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, false) {
  const sourcemeta::core::JSON right{false};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, core_id) {
  const auto right{sourcemeta::core::parse_json(
      R"JSON({ "$id": "https://www.example.com" })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_true, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "/type");
}
