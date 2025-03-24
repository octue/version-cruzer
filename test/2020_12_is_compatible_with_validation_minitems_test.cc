#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "minItems": 2
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_type_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "array"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minItems",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_type_non_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_const_non_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_enum_no_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ [ 1, 2, 3 ], [ 1 ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ [ 1, 2, 3 ], [ 1, 2 ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minItems",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minItems",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minItems",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minItems",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minItems",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minItems",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_minlength) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minItems",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_maxlength) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minItems",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_minitems_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minItems",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_minitems_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_minitems_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_maxitems_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minItems",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_maxitems_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_maxitems_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minItems",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minitems,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minItems",
                                      "/dependentRequired");
}
