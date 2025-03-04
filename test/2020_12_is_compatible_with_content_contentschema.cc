#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "contentSchema": { "type": "string" }
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, boolean_false) {
  const sourcemeta::core::JSON right{sourcemeta::core::parse_json(
      R"JSON({ "$schema": "https://json-schema.org/draft/2020-12/schema" })JSON")};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, core_schema) {
  const auto right{sourcemeta::core::parse_json(
      R"JSON({ "$schema": "https://json-schema.org/draft/2020-12/schema" })JSON")};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, core_id) {
  const auto right{sourcemeta::core::parse_json(
      R"JSON({ "$id": "https://www.example.com" })JSON")};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, core_comment) {
  const auto right{
      sourcemeta::core::parse_json(R"JSON({ "$comment": "Foo" })JSON")};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({ "$ref": "#" })JSON")};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, core_anchor) {
  const auto right{
      sourcemeta::core::parse_json(R"JSON({ "$anchor": "foo" })JSON")};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema,
     validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentschema, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentSchema",
                                      "/enum");
}
