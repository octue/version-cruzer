#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "readOnly": true
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_readonly,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/readOnly",
                                      "/dependentRequired");
}
