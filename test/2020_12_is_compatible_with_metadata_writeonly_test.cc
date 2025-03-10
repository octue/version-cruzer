#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "writeOnly": true
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly, validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_writeonly,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/writeOnly",
                                      "/dependentRequired");
}
