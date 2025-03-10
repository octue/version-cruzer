#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "maximum": 2
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum", "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_type_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_type_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_const_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_enum_one_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_enum_one_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_enum_one_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_enum_one_non_numbers) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maximum",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_uniqueitems) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maximum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum, validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maximum",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_minimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_minimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_minimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_maximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_maximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_maximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_exclusiveminimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_exclusiveminimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_exclusiveminimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_exclusivemaximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_exclusivemaximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_exclusivemaximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maximum,
     validation_exclusivemaximum_greater_plus_one) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/exclusiveMaximum");
}
