#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "contentMediaType": "application/yaml"
})JSON")};

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/$schema");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/$id");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/$comment");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/$ref");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/$anchor");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/$dynamicAnchor");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/$vocabulary");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/$defs");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/definitions");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/title");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/description");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/default");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/deprecated");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/examples");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/readOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/writeOnly");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/contentEncoding");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/contentMediaType");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/contentSchema");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/format");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/type");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/const");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/enum");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/required");
}

TEST(Cruzer_is_compatible_with_2020_12_content_contentmediatype,
     validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/contentMediaType",
                                      "/uniqueItems");
}
