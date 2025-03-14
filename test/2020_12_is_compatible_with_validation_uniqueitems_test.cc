#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "uniqueItems": true
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_type_array_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "array"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/uniqueItems",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_type_array_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "array"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_type_non_array_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "object"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/uniqueItems",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_type_non_array_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "object"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_type_superset_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "array", "object" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/uniqueItems",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_type_superset_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": [ "array", "object" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_const_array_unique_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_const_array_unique_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_const_array_non_unique_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/uniqueItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_const_array_non_unique_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_const_non_array_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_const_non_array_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_enum_superset_unique_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, [ false, true ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_enum_superset_unique_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, [ false, true ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_enum_superset_not_unique_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, [ false, false ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/uniqueItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_enum_superset_not_unique_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, [ false, false ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_enum_non_array_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_enum_non_array_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_required_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/uniqueItems",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_required_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/uniqueItems",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_uniqueitems_false_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_uniqueitems_false_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_uniqueitems_true_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/uniqueItems",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_uniqueitems_true_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/uniqueItems",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_pattern_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/uniqueItems",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_pattern_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/uniqueItems",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/uniqueItems",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/uniqueItems",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/uniqueItems",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/uniqueItems",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_uniqueitems,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/uniqueItems",
                                      "/dependentRequired");
}
