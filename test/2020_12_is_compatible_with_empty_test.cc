#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_empty, false) {
  const auto right{sourcemeta::core::parse_json(R"JSON(false)JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, true) {
  const auto right{sourcemeta::core::parse_json(R"JSON(true)JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, empty) {
  const auto right{sourcemeta::core::parse_json(R"JSON({})JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/properties");
}

TEST(Cruzer_is_compatible_with_2020_12_empty, validation_patternproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "patternProperties": { "^f": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/patternProperties");
}
