#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const sourcemeta::core::JSON schema{false};

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, false) {
  const sourcemeta::core::JSON right{false};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, true) {
  const sourcemeta::core::JSON right{true};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Incompatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_id) {
  const auto right{sourcemeta::core::parse_json(
      R"JSON({ "$id": "https://www.example.com" })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "",
                                      "/uniqueItems");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/pattern");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/minimum");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/maximum");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false,
     validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "",
                                      "/exclusiveMinimum");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false,
     validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "",
                                      "/exclusiveMaximum");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/minLength");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/maxLength");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/minItems");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "", "/maxItems");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "",
                                      "/minProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "",
                                      "/maxProperties");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "",
                                      "/minContains");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "",
                                      "/maxContains");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "",
                                      "/multipleOf");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "",
                                      "/dependentRequired");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "",
                                      "/properties");
}
