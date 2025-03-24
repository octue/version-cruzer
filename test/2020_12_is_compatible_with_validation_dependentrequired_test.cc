#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "dependentRequired": {
    "foo": [ "bar" ]
  }
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_type_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "object"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/dependentRequired", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_type_non_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/dependentRequired", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_const_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": {
      "foo": 1,
      "bar": 2
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown,
                                      "/dependentRequired", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_const_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": {
      "foo": 1
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown,
                                      "/dependentRequired", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_const_non_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown,
                                      "/dependentRequired", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_enum_no_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown,
                                      "/dependentRequired", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ { "foo": 1, "bar": 2, "baz": 3 }, { "foo": 1 } ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown,
                                      "/dependentRequired", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ { "foo": 1, "bar": 2, "baz": 3 }, { "foo": 1, "bar": 2 } ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown,
                                      "/dependentRequired", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/dependentRequired", "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/dependentRequired",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/dependentRequired",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/dependentRequired",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/dependentRequired",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/dependentRequired",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/dependentRequired",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/dependentRequired",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_minlength) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/dependentRequired",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_maxlength) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/dependentRequired",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_minproperties) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/dependentRequired", "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_maxproperties_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/dependentRequired", "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_maxproperties_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/dependentRequired", "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/dependentRequired",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_dependentrequired_more) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar", "baz" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(
      left, right, Incompatible, "/dependentRequired", "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_dependentrequired_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar", "baz" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(
      left, right, Compatible, "/dependentRequired", "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_dependentrequired_more_dependents) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar", "baz" ], "qux": [ "test" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar", "baz" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(
      left, right, Incompatible, "/dependentRequired", "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_dependentrequired,
     validation_dependentrequired_less_dependents) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar", "baz" ] }
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar", "baz" ], "qux": [ "test" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(
      left, right, Compatible, "/dependentRequired", "/dependentRequired");
}
