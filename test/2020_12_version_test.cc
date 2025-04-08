#include <gtest/gtest.h>
#include <octue/cruzer.h>

#define EXPECT_UNKNOWN(container, expected_from, expected_to, expected_traces) \
  const auto container{octue::cruzer::version(expected_from, expected_to)};    \
  EXPECT_FALSE(container.version.has_value());                                 \
  EXPECT_EQ(container.traces.size(), (expected_traces));

#define EXPECT_VERSION(container, expected_from, expected_to,                  \
                       expected_version, expected_traces)                      \
  const auto container{octue::cruzer::version(expected_from, expected_to)};    \
  EXPECT_TRUE(container.version.has_value());                                  \
  EXPECT_EQ(container.version.value(),                                         \
            octue::cruzer::SemVer::expected_version);                          \
  EXPECT_EQ(container.traces.size(), (expected_traces));

#define EXPECT_OPTIONAL_POINTER(current, expected)                             \
  if (std::optional<std::string>{expected}.has_value()) {                      \
    EXPECT_TRUE(current.has_value());                                          \
    EXPECT_EQ(sourcemeta::core::to_string(current.value()),                    \
              std::optional<std::string>{expected}.value());                   \
  } else {                                                                     \
    EXPECT_FALSE(current.has_value());                                         \
  }

#define EXPECT_TRACE(container, expected_index, expected_compatibility,        \
                     expected_left_pointer, expected_right_pointer)            \
  EXPECT_EQ(container.traces.at(expected_index).compatibility,                 \
            octue::cruzer::Compatibility::expected_compatibility);             \
  EXPECT_OPTIONAL_POINTER(container.traces.at(expected_index).left,            \
                          expected_left_pointer);                              \
  EXPECT_OPTIONAL_POINTER(container.traces.at(expected_index).right,           \
                          expected_right_pointer);

TEST(Cruzer_version_2020_12, add_id) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com",
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_VERSION(result, from, to, Patch, 0);
}

TEST(Cruzer_version_2020_12, const_to_enum_superset) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "const": "foo"
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_VERSION(result, from, to, Minor, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/const", "/enum");
}

TEST(Cruzer_version_2020_12, schema_to_const_match) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "type": "string",
    "minimum": 1
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "const": "foo"
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, "/type", "/const");
}

TEST(Cruzer_version_2020_12, add_default_minimum) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "type": "number"
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "type": "number",
    "minimum": 0
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/type", "/minimum");
}

TEST(Cruzer_version_2020_12, add_type) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "minimum": 2
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "type": "number",
    "minimum": 2
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/minimum", "/type");
}

TEST(Cruzer_version_2020_12, schema_to_const) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "minimum": 2
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "const": 5
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, "/minimum", "/const");
}

TEST(Cruzer_version_2020_12, properties_to_another_type) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "type": "string"
      }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "type": "string"
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/properties", "/type");
}

TEST(Cruzer_version_2020_12, properties_add_new_property) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "type": "string"
      }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "type": "string"
      },
      "bar": {
        "type": "string"
      }
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/properties", "/properties");
}

TEST(Cruzer_version_2020_12, properties_remove_property) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "type": "string"
      },
      "bar": {
        "type": "string"
      }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "type": "string"
      }
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Minor, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/properties", "/properties");
}

TEST(Cruzer_version_2020_12, properties_remove_relax_assertion) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "type": "string",
        "minLength": 3
      }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "type": "string"
      }
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Minor, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/properties/foo/minLength",
               "/properties/foo/type");
}

TEST(Cruzer_version_2020_12, properties_change_type) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "type": "string"
      }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "type": "integer"
      }
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/properties/foo/type",
               "/properties/foo/type");
}

TEST(Cruzer_version_2020_12, standalone_defs) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "$defs": {
      "foo": {
        "type": "string"
      }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "$defs": {
      "foo": {
        "type": "integer"
      }
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Patch, 0);
}

TEST(Cruzer_version_2020_12, properties_change_type_through_ref) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "$ref": "#/$defs/foo"
      }
    },
    "$defs": {
      "foo": {
        "type": "string"
      }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "$ref": "#/$defs/foo"
      }
    },
    "$defs": {
      "foo": {
        "type": "integer"
      }
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/$defs/foo/type", "/$defs/foo/type");
}

TEST(Cruzer_version_2020_12, patternproperties_add_new_regex) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "patternProperties": {
      "^f": { "type": "string" }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "patternProperties": {
      "^f": { "type": "string" },
      "o$": { "type": "string" }
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/patternProperties",
               "/patternProperties");
}

TEST(Cruzer_version_2020_12, patternproperties_remove_regex) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "patternProperties": {
      "^f": { "type": "string" },
      "o$": { "type": "string" }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "patternProperties": {
      "^f": { "type": "string" }
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Minor, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/patternProperties",
               "/patternProperties");
}

TEST(Cruzer_version_2020_12, properties_add_matching_patternproperties) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": { "type": "string" }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": { "type": "string" }
    },
    "patternProperties": {
      "^f": { "type": "string" }
    }
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, "/properties", "/patternProperties");
}

TEST(Cruzer_version_2020_12, additionalproperties_open_to_close) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": { "type": "string" }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": { "type": "string" }
    },
    "additionalProperties": false
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, std::nullopt, "/additionalProperties");
}

TEST(Cruzer_version_2020_12, additionalproperties_open_to_explicit_open) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": { "type": "string" }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": { "type": "string" }
    },
    "additionalProperties": true
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, std::nullopt, "/additionalProperties");
}

TEST(Cruzer_version_2020_12, additionalproperties_with_patternproperties) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "patternProperties": {
      "foo": { "type": "string" }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "patternProperties": {
      "foo": { "type": "string" }
    },
    "additionalProperties": false
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, std::nullopt, "/additionalProperties");
}

TEST(Cruzer_version_2020_12, additionalproperties_open_to_close_standalone) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "additionalProperties": true
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "additionalProperties": false
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/additionalProperties",
               "/additionalProperties");
}

TEST(Cruzer_version_2020_12, additionalproperties_open_to_schema) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "additionalProperties": true
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "additionalProperties": {
      "type": "string"
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/additionalProperties",
               "/additionalProperties/type");
}

TEST(Cruzer_version_2020_12, additionalproperties_schema_to_schema) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "additionalProperties": {
      "type": "integer"
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "additionalProperties": {
      "type": "number"
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Minor, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/additionalProperties/type",
               "/additionalProperties/type");
}

TEST(Cruzer_version_2020_12, properties_to_additionalproperties) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": { "type": "integer" }
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "additionalProperties": {
      "type": "integer"
    }
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, std::nullopt, "/additionalProperties");
}

TEST(Cruzer_version_2020_12, propertynames_incompatible) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "propertyNames": {
      "type": "number"
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "propertyNames": {
      "type": "integer"
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/propertyNames/type",
               "/propertyNames/type");
}

TEST(Cruzer_version_2020_12, propertynames_add) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "propertyNames": {
      "type": "integer"
    }
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, std::nullopt, "/propertyNames");
}

TEST(Cruzer_version_2020_12, contains_add) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "contains": {
      "type": "integer"
    }
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, std::nullopt, "/contains");
}

TEST(Cruzer_version_2020_12, contains_incompatible) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "contains": {
      "type": "number"
    }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "contains": {
      "type": "integer"
    }
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/contains/type", "/contains/type");
}

TEST(Cruzer_version_2020_12, if_then_add_else) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "if": { "type": "string" },
    "then": { "minLength": 3 }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "if": { "type": "string" },
    "then": { "minLength": 3 },
    "else": { "type": "number" }
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, std::nullopt, "/else");
}

TEST(Cruzer_version_2020_12, if_then_else_incompatible) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "if": { "type": "string" },
    "then": { "minLength": 3 },
    "else": { "type": "number" }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "if": { "type": "string" },
    "then": { "minLength": 3 },
    "else": { "type": "integer" }
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/else/type", "/else/type");
}

TEST(Cruzer_version_2020_12, if_standalone) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "if": { "type": "string" }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "if": { "type": "string", "minLength": 3 }
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/if/type", "/if/minLength");
}

TEST(Cruzer_version_2020_12, not_incompatible) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "not": { "type": "number" }
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "not": { "type": "integer" }
  })JSON")};

  EXPECT_VERSION(result, from, to, Major, 1);
  EXPECT_TRACE(result, 0, Incompatible, "/not/type", "/not/type");
}

TEST(Cruzer_version_2020_12, prefixitems_add) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "prefixItems": [
      { "type": "string" },
      { "type": "string" }
    ]
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "prefixItems": [
      { "type": "string" },
      { "type": "string" },
      { "type": "string" }
    ]
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, std::nullopt, "/prefixItems/2");
}

TEST(Cruzer_version_2020_12, prefixitems_remove) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "prefixItems": [
      { "type": "string" },
      { "type": "string" },
      { "type": "string" }
    ]
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "prefixItems": [
      { "type": "string" },
      { "type": "string" }
    ]
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, "/prefixItems/2", std::nullopt);
}
