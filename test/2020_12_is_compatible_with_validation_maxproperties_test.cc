#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "maxProperties": 2
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_type_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "object"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/maxProperties", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_type_non_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxProperties",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": {
      "foo": 1,
      "bar": 2,
      "baz": 3
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxProperties",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": {
      "foo": 1,
      "bar": 2,
      "baz": 3
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxProperties",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 4
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": {
      "foo": 1,
      "bar": 2,
      "baz": 3
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxProperties",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_const_non_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxProperties",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_enum_no_object) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxProperties",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ { "foo": 1, "bar": 2, "baz": 3 }, { "foo": 1 } ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxProperties",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ { "foo": 1, "bar": 2, "baz": 3 }, { "foo": 1, "bar": 2 } ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxProperties",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_required_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxProperties",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_required_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxProperties",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_required_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar", "baz" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/maxProperties", "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxProperties",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxProperties",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxProperties",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxProperties",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxProperties",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxProperties",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxProperties",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_minlength) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxProperties",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_maxlength) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxProperties",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_minproperties_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxProperties",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_minproperties_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxProperties",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_minproperties_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/maxProperties", "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_maxproperties_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxProperties",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_maxproperties_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxProperties",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_maxproperties_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/maxProperties", "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_dependentrequired_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 1
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible,
                                      "/maxProperties", "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_dependentrequired_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxProperties",
                                      "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_dependentrequired_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxProperties",
                                      "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/properties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxproperties,
     validation_patternproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "patternProperties": { "^f": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxProperties",
                                      "/patternProperties");
}
