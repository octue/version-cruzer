#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "multipleOf": 3
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_type_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/multipleOf",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_type_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_const_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_const_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/multipleOf",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_const_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_enum_one_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 4 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_enum_one_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/multipleOf",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/multipleOf",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_uniqueitems) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/multipleOf",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/multipleOf",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_multipleof_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 6
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_multipleof_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/multipleOf",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_multipleof,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/dependentRequired");
}
