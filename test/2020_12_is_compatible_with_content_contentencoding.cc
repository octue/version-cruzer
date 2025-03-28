#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "contentEncoding": "base64"
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base16"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentencoding,
     validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentEncoding",
                                      "/properties");
}
