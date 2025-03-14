#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "minimum": 2
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum", "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_type_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minimum",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_type_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "number"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minimum",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_type_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minimum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_const_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_enum_no_numbers) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minimum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minimum",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minimum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minimum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum, validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minimum",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_minimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_minimum_equal_real_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2.0
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_minimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minimum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_minimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_maximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minimum",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_maximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_maximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_exclusiveminimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_exclusiveminimum_less_minus_1) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minimum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_exclusiveminimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_exclusiveminimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_exclusivemaximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minimum",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_exclusivemaximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minimum",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_exclusivemaximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minimum",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minimum,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minimum",
                                      "/maxProperties");
}
