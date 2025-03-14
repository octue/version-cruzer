#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "minProperties": 2
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_type_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "object"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/minProperties", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_type_non_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": {
      "foo": 1,
      "bar": 2,
      "baz": 3
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": {
      "foo": 1,
      "bar": 2,
      "baz": 3
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": {
      "foo": 1,
      "bar": 2,
      "baz": 3
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/minProperties", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_const_non_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_enum_no_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ { "foo": 1, "bar": 2, "baz": 3 }, { "foo": 1 } ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/minProperties", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ { "foo": 1, "bar": 2, "baz": 3 }, { "foo": 1, "bar": 2 } ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_required_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_required_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_required_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar", "baz" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minProperties",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minProperties",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minProperties",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minProperties",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minProperties",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minProperties",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minProperties",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_minlength) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minProperties",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_maxlength) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minProperties",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_minproperties_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/minProperties", "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_minproperties_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_minproperties_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_maxproperties_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/minProperties", "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_maxproperties_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_maxproperties_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minProperties",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_minproperties,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minProperties",
                                      "/maxContains");
}
