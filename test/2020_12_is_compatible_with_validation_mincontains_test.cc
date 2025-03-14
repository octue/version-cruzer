#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "minContains": 3
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "array"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": [ [ 1 ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ [ 1, 2, 3 ], [ [ 1 ] ] ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_uniqueitems_false) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_uniqueitems_true) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_validation_mincontains,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minContains",
                                      "/multipleOf");
}
