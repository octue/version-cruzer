#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "$vocabulary": {
    "https://json-schema.org/draft/2020-12/vocab/core": true
  }
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_core_vocabulary, validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/$vocabulary",
                                      "/properties");
}
