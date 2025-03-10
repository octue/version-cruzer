#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "enum": [ 1, 2, 3 ]
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum", "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum", "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum", "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum", "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/enum", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, validation_type_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/enum", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_type_mismatch) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_type_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "string", "integer" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/enum", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, validation_const_same) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_const_different) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "1"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_const_superset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, true, "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_const_disjoint) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, true, "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum, validation_enum_same) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, true ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, true ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_enum_reorder) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, true ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ true, 2, 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_enum_superset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, true ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ true ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_enum_non_superset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, true ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ false ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_required_non_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, true ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_required_superset_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, { "foo": 1 } ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/enum",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_uniqueitems_superset_unique_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, [ 1, 2, 3 ] ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/enum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_uniqueitems_superset_unique_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, [ 1, 2, 3 ] ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_uniqueitems_no_array_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_uniqueitems_no_array_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_pattern_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_pattern_one_string_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/enum",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_pattern_one_string_no_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_pattern_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/enum",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_minimum_numbers_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_minimum_numbers_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_minimum_numbers_mixed) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_minimum_non_numbers) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_minimum_hybrid_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_maximum_one_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_maximum_one_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_maximum_one_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_maximum_non_numbers) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_exclusiveminimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_exclusiveminimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_exclusiveminimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_exclusiveminimum_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_exclusivemaximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_exclusivemaximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/enum",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_exclusivemaximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_enum,
     validation_exclusivemaximum_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/enum",
                                      "/exclusiveMaximum");
}
