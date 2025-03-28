#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "examples": [ 1, 2 ]
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_metadata_examples,
     validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/examples",
                                      "/properties");
}
