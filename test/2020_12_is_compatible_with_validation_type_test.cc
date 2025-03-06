#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "type": "string"
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_type, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type", "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type", "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type", "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type", "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/type", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type, validation_type_same) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_different) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Incompatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_superset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "number"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_subset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "number"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_to_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_to_array_plus_more) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "integer" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_to_array_plus_more_superset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "number"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "integer", "number" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_to_array_plus_more_superset_plus_one) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "number"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "integer", "number", "string" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_to_array_mismatch) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "number" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_array_same) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "number" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "number" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_array_reorder) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "number" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "number", "string" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_array_subset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "number", "string" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_type_array_superset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "number", "array" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "number", "string" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_const_single_type_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_const_single_type_array_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_const_type_array_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "integer" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_const_single_type_mismatch) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_const_single_type_array_mismatch) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_const_type_array_mismatch) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "integer" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 3.14
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_enum_single_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_enum_single_mismatch) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_enum_many_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_enum_many_mismatch) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_enum_type_array_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "integer", "null" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 1, 2, null ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_enum_type_array_mismatch) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "integer", "null" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 1, 2, true ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_required_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "object"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_required_object_plus_others) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "integer", "object" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_required_non_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_required_non_object_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "integer" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_uniqueitems_array_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "array"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_uniqueitems_array_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "array"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_pattern_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_pattern_string_plus_more) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "integer" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_pattern_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_minimum_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/type",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_type,
     validation_minimum_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/type",
                                      "/minimum");
}
