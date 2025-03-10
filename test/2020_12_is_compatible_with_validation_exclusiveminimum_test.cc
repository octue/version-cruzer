#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "exclusiveMinimum": 2
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMinimum",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_type_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_type_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "number"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_type_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMinimum", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMinimum", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_const_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMinimum", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_enum_no_numbers) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMinimum", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/exclusiveMinimum",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/exclusiveMinimum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/exclusiveMinimum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/exclusiveMinimum",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_minimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_minimum_equal_real_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2.0
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_minimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_minimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMinimum", "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_maximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_maximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_maximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMinimum", "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_exclusiveminimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_exclusiveminimum_less_minus_1) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_exclusiveminimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMinimum", "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_exclusiveminimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMinimum", "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_exclusivemaximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_exclusivemaximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusiveminimum,
     validation_exclusivemaximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMinimum", "/exclusiveMaximum");
}
