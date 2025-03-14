#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "minLength": 2
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_type_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minLength",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_type_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minLength",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_const_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_enum_no_strings) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "x" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minLength",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/minLength",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_minlength_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minLength",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_minlength_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_minlength_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_maxlength_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minLength",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_maxlength_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_maxlength_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minlength,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/maxProperties");
}
