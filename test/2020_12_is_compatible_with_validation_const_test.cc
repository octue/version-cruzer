#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "const": 1
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_const, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const", "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const", "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/const", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_type_mismatch) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Incompatible, "/const",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_type_match) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  // TODO: We should ideally be able to catch this as Incompatible
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "/const",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_const_not_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const, validation_enum_same) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_enum_different) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_enum_subset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_enum_disjoint) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_required_object_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": {
      "foo": 1,
      "bar": 2
    }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/const",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_required_object_mismatch) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": { "bar": 2 }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_required_non_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_uniqueitems_array_unique_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/const",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_uniqueitems_array_unique_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_uniqueitems_array_not_unique_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_uniqueitems_array_not_unique_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 2 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_uniqueitems_non_array_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_uniqueitems_non_array_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_pattern_string_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/const",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_pattern_string_no_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^b"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_pattern_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^b"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minimum_not_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maximum_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_exclusiveminimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_exclusiveminimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_exclusiveminimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_exclusiveminimum_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_exclusivemaximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_exclusivemaximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_exclusivemaximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_exclusivemaximum_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minlength_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minlength_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minlength_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minlength_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maxlength_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maxlength_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maxlength_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maxlength_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minitems_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minitems_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minitems_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_minitems_non_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maxitems_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maxitems_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maxitems_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/const",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_const,
     validation_maxitems_non_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/const",
                                      "/maxItems");
}
