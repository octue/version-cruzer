#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, false) {
  const sourcemeta::core::JSON left{false};
  const sourcemeta::core::JSON right{false};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Compatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, true) {
  const sourcemeta::core::JSON left{false};
  const sourcemeta::core::JSON right{true};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_schema) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_id) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_comment) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_ref) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_anchor) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_dynamicanchor) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_vocabulary) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_defs) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, core_definitions) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_title) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_description) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_default) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_deprecated) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_examples) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_readonly) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, metadata_writeonly) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, content_contentencoding) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false,
     content_contentmediatype) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}

TEST(Cruzer_is_compatible_with_2020_12_boolean_false, content_contentschema) {
  const sourcemeta::core::JSON left{false};
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  COMPARE_TWO_WAY_2020_12(left, right, left_result, right_result);

  EXPECT_EQ(left_result.size(), 1);
  EXPECT_COMPATIBILITY(left_result, 0, Incompatible, "", "");

  EXPECT_EQ(right_result.size(), 1);
  EXPECT_COMPATIBILITY(right_result, 0, Compatible, "", "");
}
