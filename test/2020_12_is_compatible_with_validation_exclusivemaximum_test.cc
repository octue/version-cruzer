#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "exclusiveMaximum": 2
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_type_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_type_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "number"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_type_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMaximum", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMaximum", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_const_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMaximum", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_enum_no_numbers) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMaximum", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/exclusiveMaximum",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/exclusiveMaximum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/exclusiveMaximum",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/exclusiveMaximum",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_minimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_minimum_equal_real_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2.0
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_minimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMaximum", "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_minimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_maximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMaximum", "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_maximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_maximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_exclusiveminimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMaximum", "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_exclusiveminimum_less_minus_1) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMaximum", "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_exclusiveminimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_exclusiveminimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_exclusivemaximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMaximum", "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_exclusivemaximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible,
                                      "/exclusiveMaximum", "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_exclusivemaximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/exclusiveMaximum", "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible,
                                      "/exclusiveMaximum", "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_exclusivemaximum,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/exclusiveMaximum",
                                      "/dependentRequired");
}
