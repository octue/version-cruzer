#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "maxContains": 3
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "array"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ [ 1 ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ [ 1, 2, 3 ], [ [ 1 ] ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_uniqueitems_false) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_uniqueitems_true) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_maxcontains,
     validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxContains",
                                      "/properties");
}
