#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "maxItems": 2
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_type_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "array"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maxItems",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_type_non_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxItems",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maxItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 4
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_const_non_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxItems",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_enum_no_array) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ [ 1, 2, 3 ], [ 1 ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maxItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ [ 1 ], [ 1, 2 ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxItems",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxItems",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxItems",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxItems",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxItems",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxItems",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxItems",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxItems",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxItems",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_minlength) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxItems",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_maxlength) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxItems",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_minitems_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxItems",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_minitems_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxItems",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_minitems_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maxItems",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_maxitems_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxItems",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_maxitems_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxItems",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_maxitems_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maxItems",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxitems,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxItems",
                                      "/multipleOf");
}
