#ifndef OCTUE_CRUZER_COMPARATOR_H_
#define OCTUE_CRUZER_COMPARATOR_H_

#include <sourcemeta/core/regex.h>

#include <cassert>       // assert
#include <optional>      // std::optional, std::nullopt
#include <unordered_map> // std::unordered_map
#include <unordered_set> // std::unordered_set

static auto does_not_validate(const sourcemeta::core::SchemaKeywordType &type)
    -> bool {
  return type == sourcemeta::core::SchemaKeywordType::Other ||
         type == sourcemeta::core::SchemaKeywordType::Comment ||
         type == sourcemeta::core::SchemaKeywordType::Annotation ||
         type == sourcemeta::core::SchemaKeywordType::Reference ||
         type == sourcemeta::core::SchemaKeywordType::LocationMembers ||
         type ==
             sourcemeta::core::SchemaKeywordType::ApplicatorValueInPlaceOther;
}

static auto type_to_set(const sourcemeta::core::JSON::String &value)
    -> std::unordered_set<sourcemeta::core::JSON::Type> {
  std::unordered_set<sourcemeta::core::JSON::Type> result;
  if (value == "null") {
    result.emplace(sourcemeta::core::JSON::Type::Null);
  } else if (value == "boolean") {
    result.emplace(sourcemeta::core::JSON::Type::Boolean);
  } else if (value == "object") {
    result.emplace(sourcemeta::core::JSON::Type::Object);
  } else if (value == "array") {
    result.emplace(sourcemeta::core::JSON::Type::Array);
  } else if (value == "number") {
    result.emplace(sourcemeta::core::JSON::Type::Real);
    result.emplace(sourcemeta::core::JSON::Type::Integer);
  } else if (value == "integer") {
    result.emplace(sourcemeta::core::JSON::Type::Integer);
  } else if (value == "string") {
    result.emplace(sourcemeta::core::JSON::Type::String);
  }

  return result;
}

static auto type_to_set(const sourcemeta::core::JSON &value)
    -> std::unordered_set<sourcemeta::core::JSON::Type> {
  if (value.is_string()) {
    return type_to_set(value.to_string());
  }

  std::unordered_set<sourcemeta::core::JSON::Type> result;
  if (value.is_array()) {
    for (const auto &type : value.as_array()) {
      if (type.is_string()) {
        for (auto &&new_type : type_to_set(type.to_string())) {
          result.insert(std::move(new_type));
        }
      }
    }
  }

  return result;
}

static auto array_to_set(const sourcemeta::core::JSON &array)
    -> std::unordered_set<sourcemeta::core::JSON,
                          sourcemeta::core::HashJSON<sourcemeta::core::JSON>> {
  return {array.as_array().cbegin(), array.as_array().end()};
}

template <typename T>
static auto is_superset(const T &left, const T &right) -> bool {
  for (const auto &right_entry : right) {
    if (!left.contains(right_entry)) {
      return false;
    }
  }

  return true;
}

// TODO: Move association of keywords to instance types to the Core official
// walker
// By convention, if a keyword is not here, we assume it affects all types
static const std::unordered_map<
    sourcemeta::core::JSON::String,
    std::unordered_map<sourcemeta::core::JSON::String,
                       std::unordered_set<sourcemeta::core::JSON::Type>>>
    KEYWORD_TYPES{
        {"https://json-schema.org/draft/2020-12/vocab/applicator",
         {
             {"properties", {sourcemeta::core::JSON::Type::Object}},
             {"patternProperties", {sourcemeta::core::JSON::Type::Object}},
             {"additionalProperties", {sourcemeta::core::JSON::Type::Object}},
             {"dependentSchemas", {sourcemeta::core::JSON::Type::Object}},
             {"propertyNames", {sourcemeta::core::JSON::Type::Object}},
             {"contains", {sourcemeta::core::JSON::Type::Array}},
             {"items", {sourcemeta::core::JSON::Type::Array}},
             {"prefixItems", {sourcemeta::core::JSON::Type::Array}},
         }},

        {"https://json-schema.org/draft/2020-12/vocab/unevaluated",
         {
             {"unevaluatedProperties", {sourcemeta::core::JSON::Type::Object}},
             {"unevaluatedItems", {sourcemeta::core::JSON::Type::Array}},
         }},

        {"https://json-schema.org/draft/2020-12/vocab/format-assertion",
         {
             {"format", {sourcemeta::core::JSON::Type::String}},
         }},

        {"https://json-schema.org/draft/2020-12/vocab/validation",
         {
             {"maxLength", {sourcemeta::core::JSON::Type::String}},
             {"minLength", {sourcemeta::core::JSON::Type::String}},
             {"pattern", {sourcemeta::core::JSON::Type::String}},
             {"exclusiveMaximum",
              {sourcemeta::core::JSON::Type::Integer,
               sourcemeta::core::JSON::Type::Real}},
             {"exclusiveMinimum",
              {sourcemeta::core::JSON::Type::Integer,
               sourcemeta::core::JSON::Type::Real}},
             {"maximum",
              {sourcemeta::core::JSON::Type::Integer,
               sourcemeta::core::JSON::Type::Real}},
             {"minimum",
              {sourcemeta::core::JSON::Type::Integer,
               sourcemeta::core::JSON::Type::Real}},
             {"multipleOf",
              {sourcemeta::core::JSON::Type::Integer,
               sourcemeta::core::JSON::Type::Real}},
             {"dependentRequired", {sourcemeta::core::JSON::Type::Object}},
             {"maxProperties", {sourcemeta::core::JSON::Type::Object}},
             {"minProperties", {sourcemeta::core::JSON::Type::Object}},
             {"required", {sourcemeta::core::JSON::Type::Object}},
             {"maxItems", {sourcemeta::core::JSON::Type::Array}},
             {"minItems", {sourcemeta::core::JSON::Type::Array}},
             {"maxContains", {sourcemeta::core::JSON::Type::Array}},
             {"minContains", {sourcemeta::core::JSON::Type::Array}},
             {"uniqueItems", {sourcemeta::core::JSON::Type::Array}},
         }}};

static auto keyword_types(const sourcemeta::core::JSON::String &vocabulary,
                          const sourcemeta::core::JSON::String &keyword)
    -> std::optional<std::reference_wrapper<
        const std::unordered_set<sourcemeta::core::JSON::Type>>> {
  const auto vocabulary_result{KEYWORD_TYPES.find(vocabulary)};
  if (vocabulary_result == KEYWORD_TYPES.cend()) {
    return std::nullopt;
  }

  const auto keyword_result{vocabulary_result->second.find(keyword)};
  if (keyword_result == vocabulary_result->second.cend()) {
    return std::nullopt;
  }

  return keyword_result->second;
}

static auto
have_common_types(const sourcemeta::core::JSON::String &left_vocabulary,
                  const sourcemeta::core::JSON::String &left_keyword,
                  const sourcemeta::core::JSON::String &right_vocabulary,
                  const sourcemeta::core::JSON::String &right_keyword) -> bool {
  const auto left_types{keyword_types(left_vocabulary, left_keyword)};
  const auto right_types{keyword_types(right_vocabulary, right_keyword)};

  if (left_types.has_value() && right_types.has_value()) {
    for (const auto &value : left_types.value().get()) {
      if (right_types.value().get().contains(value)) {
        return true;
      }
    }

    for (const auto &value : right_types.value().get()) {
      if (left_types.value().get().contains(value)) {
        return true;
      }
    }

    return false;
  } else {
    return true;
  }
}

static auto defines_any_relevant_type(
    const std::unordered_set<sourcemeta::core::JSON::Type> &types,
    const sourcemeta::core::JSON::String &vocabulary,
    const sourcemeta::core::JSON::String &keyword) -> bool {
  const auto expected_types{keyword_types(vocabulary, keyword)};
  if (expected_types.has_value()) {
    for (const auto &type : expected_types.value().get()) {
      if (types.contains(type)) {
        return true;
      }
    }
  }

  return false;
}

namespace octue::cruzer {

static auto compare(
    // Left current subschema
    const sourcemeta::core::JSON &left_subschema,
    // Left keyword name
    const sourcemeta::core::JSON::String &left_keyword,
    // Left keyword vocabulary
    const std::optional<sourcemeta::core::JSON::String> &left_vocabulary,
    // Left keyword type
    const sourcemeta::core::SchemaKeywordType &left_type,
    // Left schema location
    const sourcemeta::core::Pointer &left_schema_location,

    // Right current subschema
    const sourcemeta::core::JSON &right_subschema,
    // Right keyword name
    const sourcemeta::core::JSON::String &right_keyword,
    // Right keyword vocabulary
    const std::optional<sourcemeta::core::JSON::String> &right_vocabulary,
    // Right keyword type
    const sourcemeta::core::SchemaKeywordType &right_type,
    // Right schema location
    const sourcemeta::core::Pointer &right_schema_location) -> Trace {

  // Annotations / comments do not participate
  if (does_not_validate(left_type) || does_not_validate(right_type)) {
    return {Compatibility::Skip, left_schema_location, right_schema_location};

    // Handle boolean schemas on both sides
  } else if (left_subschema.is_boolean() && right_subschema.is_boolean()) {
    return {!left_subschema.to_boolean() && right_subschema.to_boolean()
                ? Compatibility::Incompatible
                : Compatibility::Compatible,
            left_schema_location, right_schema_location};
    // The "true" schema is by definition compatible to everything
  } else if (left_subschema.is_boolean() && left_subschema.to_boolean()) {
    return {Compatibility::Compatible, left_schema_location,
            right_schema_location};
    // TODO: The "false" schema is compatible against impossible schemas
  } else if (left_subschema.is_boolean() && !left_subschema.to_boolean()) {
    return {Compatibility::Incompatible, left_schema_location,
            right_schema_location};

    // If things are equal, then they are compatible by definition
  } else if (left_type == right_type && left_keyword == right_keyword &&
             left_vocabulary == right_vocabulary &&
             left_subschema.is_object() && right_subschema.is_object() &&
             left_subschema.at(left_keyword) ==
                 right_subschema.at(right_keyword)) {
    return {Compatibility::Compatible, left_schema_location,
            right_schema_location};

    // If the keywords match totally different types, then we shouldn't be
    // comparing at all
  } else if (!have_common_types(left_vocabulary.value_or(""), left_keyword,
                                right_vocabulary.value_or(""), right_keyword)) {
    return {Compatibility::Skip, left_schema_location, right_schema_location};
  }

  const auto &left_value{left_subschema.at(left_keyword)};
  const auto &right_value{right_subschema.at(right_keyword)};

#define COMPARISON_2020_12(expected_left_vocabulary, expected_left_name,       \
                           expected_right_vocabulary, expected_right_name)     \
  (left_vocabulary.has_value() &&                                              \
   left_vocabulary.value() == "https://json-schema.org/draft/2020-12/"         \
                              "vocab/" expected_left_vocabulary &&             \
   left_keyword == (expected_left_name) && right_vocabulary.has_value() &&     \
   right_vocabulary.value() == "https://json-schema.org/draft/2020-12/"        \
                               "vocab/" expected_right_vocabulary &&           \
   right_keyword == (expected_right_name))

#define MAKE_RESULT(expected_compatibility)                                    \
  Trace{Compatibility::expected_compatibility, left_schema_location,           \
        right_schema_location};

  if (left_type == sourcemeta::core::SchemaKeywordType::Assertion) {
    // Any assertion is more open than the "false" schema, by definition
    if (right_subschema.is_boolean() && !right_subschema.to_boolean()) {
      return MAKE_RESULT(Compatible);
    }

    // Any assertion is less open than the "true" schema, by definition
    if (right_subschema.is_boolean() && right_subschema.to_boolean()) {
      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "type", "validation", "type")) {
      const auto left_set{type_to_set(left_value)};
      const auto right_set{type_to_set(right_value)};
      if (is_superset(left_set, right_set)) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "type", "validation", "const")) {
      const auto left_set{type_to_set(left_value)};
      if (left_set.contains(right_value.type())) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "type", "validation", "enum")) {
      const auto left_set{type_to_set(left_value)};
      for (const auto &entry : right_value.as_array()) {
        if (!left_set.contains(entry.type())) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "pattern", "validation", "type")) {
      const auto right_set{type_to_set(right_value)};
      if (right_set.contains(sourcemeta::core::JSON::Type::String)) {
        // For example, what if the regex allows everything?
        return MAKE_RESULT(Unknown);
      } else {
        return MAKE_RESULT(Compatible);
      }
    }

    if (COMPARISON_2020_12("validation", "uniqueItems", "validation", "type")) {
      if (left_value.is_boolean() && !left_value.to_boolean()) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "uniqueItems", "validation",
                           "minItems")) {
      return MAKE_RESULT(Skip);
    }

    if (COMPARISON_2020_12("validation", "uniqueItems", "validation",
                           "maxItems")) {
      return MAKE_RESULT(Skip);
    }

#define COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION(expected_vocabulary,          \
                                                 expected_keyword)             \
  if (COMPARISON_2020_12("validation", "type", expected_vocabulary,            \
                         expected_keyword)) {                                  \
    if (defines_any_relevant_type(type_to_set(left_value),                     \
                                  "https://json-schema.org/draft/2020-12/"     \
                                  "vocab/" expected_vocabulary,                \
                                  expected_keyword)) {                         \
      return MAKE_RESULT(Compatible);                                          \
    } else {                                                                   \
      return MAKE_RESULT(Incompatible);                                        \
    }                                                                          \
  }                                                                            \
  if (COMPARISON_2020_12(expected_vocabulary, expected_keyword, "validation",  \
                         "type")) {                                            \
    if (defines_any_relevant_type(type_to_set(right_value),                    \
                                  "https://json-schema.org/draft/2020-12/"     \
                                  "vocab/" expected_vocabulary,                \
                                  expected_keyword)) {                         \
      return MAKE_RESULT(Incompatible);                                        \
    } else {                                                                   \
      return MAKE_RESULT(Compatible);                                          \
    }                                                                          \
  }

    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "required");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "uniqueItems");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "pattern");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "minimum");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "maximum");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "exclusiveMinimum");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "exclusiveMaximum");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "minLength");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "maxLength");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "minItems");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "maxItems");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "minProperties");
    COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION("validation", "maxProperties");

#undef COMPARE_2020_12_TYPE_WITH_TYPE_ASSERTION

    if (COMPARISON_2020_12("validation", "const", "validation", "type")) {
      const auto right_set{type_to_set(right_value)};
      // If the type matches the enumeration, there are cases where
      // compatibility remains, like if the "type" subschema comes with other
      // constraints that reduce the possible instances to a limited set, but
      // that's hard to check right now.
      if (!right_set.contains(left_value.type())) {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "const")) {
      if (left_value == right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "enum")) {
      if (right_value.size() == 1) {
        if (left_value == right_value.front()) {
          return MAKE_RESULT(Compatible);
        } else {
          return MAKE_RESULT(Incompatible);
        }
      } else if (right_value.size() > 1) {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "required")) {
      if (left_value.is_object()) {
        for (const auto &entry : right_value.as_array()) {
          if (!left_value.defines(entry.to_string())) {
            return MAKE_RESULT(Incompatible);
          }
        }

        // In general, this will be incompatible, but there are some corner
        // cases where it will not. We can ignore those for now
        return MAKE_RESULT(Unknown);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation",
                           "uniqueItems")) {
      if (left_value.is_array()) {
        if (left_value.unique() && right_value.is_boolean() &&
            right_value.to_boolean()) {
          // In general, this will be incompatible, but there are some corner
          // cases where it will not. We can ignore those for now
          return MAKE_RESULT(Unknown);
        } else {
          return MAKE_RESULT(Incompatible);
        }
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "pattern")) {
      if (left_value.is_string()) {
        const auto regex{sourcemeta::core::to_regex(right_value.to_string())};
        if (!regex.has_value() ||
            sourcemeta::core::matches(regex.value(), left_value.to_string())) {
          return MAKE_RESULT(Unknown);
        }
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "minimum")) {
      if (left_value.is_number() && left_value >= right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "maximum")) {
      if (left_value.is_number() && left_value <= right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation",
                           "exclusiveMinimum")) {
      if (left_value.is_number() && left_value > right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation",
                           "exclusiveMaximum")) {
      if (left_value.is_number() && left_value < right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "minLength")) {
      if (left_value.is_string() &&
          static_cast<sourcemeta::core::JSON::Integer>(left_value.size()) >=
              right_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "maxLength")) {
      if (left_value.is_string() &&
          static_cast<sourcemeta::core::JSON::Integer>(left_value.size()) <=
              right_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "minItems")) {
      if (left_value.is_array() &&
          static_cast<sourcemeta::core::JSON::Integer>(left_value.size()) >=
              right_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "maxItems")) {
      if (left_value.is_array() &&
          static_cast<sourcemeta::core::JSON::Integer>(left_value.size()) <=
              right_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation",
                           "minProperties")) {
      if (left_value.is_object() &&
          static_cast<sourcemeta::core::JSON::Integer>(left_value.size()) >=
              right_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "const", "validation",
                           "maxProperties")) {
      if (left_value.is_object() &&
          static_cast<sourcemeta::core::JSON::Integer>(left_value.size()) <=
              right_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "type")) {
      const auto right_set{type_to_set(right_value)};
      for (const auto &entry : left_value.as_array()) {
        // If the type matches the enumeration, there are cases where
        // compatibility remains, like if the "type" subschema comes with other
        // constraints that reduce the possible instances to a limited set, but
        // that's hard to check right now.
        if (!right_set.contains(entry.type())) {
          return MAKE_RESULT(Incompatible);
        }
      }
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "const")) {
      if (left_value.contains(right_value)) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "enum")) {
      if (is_superset(array_to_set(left_value), array_to_set(right_value))) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "required")) {
      bool potential_match{false};
      for (const auto &value : left_value.as_array()) {
        if (value.is_object()) {
          for (const auto &entry : right_value.as_array()) {
            if (!value.defines(entry.to_string())) {
              return MAKE_RESULT(Incompatible);
            }
          }

          potential_match = true;
        }
      }

      if (potential_match) {
        // In general, this will be incompatible, but there are some corner
        // cases where it will not. We can ignore those for now
        return MAKE_RESULT(Unknown);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "uniqueItems")) {
      for (const auto &value : left_value.as_array()) {
        if (value.is_array()) {
          if (value.unique() && right_value.is_boolean() &&
              right_value.to_boolean()) {
            // In general, this will be incompatible, but there are some corner
            // cases where it will not. We can ignore those for now
            return MAKE_RESULT(Unknown);
          }
        }
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "pattern")) {
      const auto regex{sourcemeta::core::to_regex(right_value.to_string())};
      if (!regex.has_value()) {
        return MAKE_RESULT(Unknown);
      }

      for (const auto &value : left_value.as_array()) {
        if (value.is_string()) {
          if (sourcemeta::core::matches(regex.value(), value.to_string())) {
            return MAKE_RESULT(Unknown);
          }
        }
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "minimum")) {
      for (const auto &value : left_value.as_array()) {
        if (!value.is_number()) {
          continue;
        } else if (value < right_value) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "maximum")) {
      for (const auto &value : left_value.as_array()) {
        if (!value.is_number()) {
          continue;
        } else if (value > right_value) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation",
                           "exclusiveMinimum")) {
      for (const auto &value : left_value.as_array()) {
        if (!value.is_number()) {
          continue;
        } else if (value <= right_value) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation",
                           "exclusiveMaximum")) {
      for (const auto &value : left_value.as_array()) {
        if (!value.is_number()) {
          continue;
        } else if (value >= right_value) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "minLength")) {
      for (const auto &value : left_value.as_array()) {
        if (!value.is_string()) {
          continue;
        } else if (static_cast<sourcemeta::core::JSON::Integer>(value.size()) <
                   right_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "maxLength")) {
      for (const auto &value : left_value.as_array()) {
        if (!value.is_string()) {
          continue;
        } else if (static_cast<sourcemeta::core::JSON::Integer>(value.size()) >
                   right_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "minItems")) {
      for (const auto &value : left_value.as_array()) {
        if (!value.is_array()) {
          continue;
        } else if (static_cast<sourcemeta::core::JSON::Integer>(value.size()) <
                   right_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "maxItems")) {
      for (const auto &value : left_value.as_array()) {
        if (!value.is_array()) {
          continue;
        } else if (static_cast<sourcemeta::core::JSON::Integer>(value.size()) >
                   right_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation",
                           "minProperties")) {
      for (const auto &value : left_value.as_array()) {
        if (!value.is_object()) {
          continue;
        } else if (static_cast<sourcemeta::core::JSON::Integer>(value.size()) <
                   right_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation",
                           "maxProperties")) {
      for (const auto &value : left_value.as_array()) {
        if (!value.is_object()) {
          continue;
        } else if (static_cast<sourcemeta::core::JSON::Integer>(value.size()) >
                   right_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "required", "validation", "const")) {
      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "required", "validation", "enum")) {
      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "required", "validation",
                           "required")) {
      if (is_superset(array_to_set(right_value), array_to_set(left_value))) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "required", "validation",
                           "minProperties")) {
      if (static_cast<sourcemeta::core::JSON::Integer>(left_value.size()) >=
          right_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "required", "validation",
                           "maxProperties")) {
      if (static_cast<sourcemeta::core::JSON::Integer>(left_value.size()) <=
          right_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "uniqueItems", "validation",
                           "const")) {
      if (left_value.is_boolean() && !left_value.to_boolean()) {
        return MAKE_RESULT(Compatible);
      } else if (right_value.is_array() && right_value.unique()) {
        return MAKE_RESULT(Compatible);
      } else if (right_value.is_array()) {
        return MAKE_RESULT(Incompatible);
      } else {
        return MAKE_RESULT(Compatible);
      }
    }

    if (COMPARISON_2020_12("validation", "uniqueItems", "validation", "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (left_value.is_boolean() && !left_value.to_boolean()) {
          continue;
        } else if (value.is_array() && !value.unique()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "uniqueItems", "validation",
                           "uniqueItems")) {
      if (left_value.is_boolean() && left_value.to_boolean() &&
          right_value.is_boolean() && !right_value.to_boolean()) {
        return MAKE_RESULT(Incompatible);
      } else {
        return MAKE_RESULT(Compatible);
      }
    }

    if (COMPARISON_2020_12("validation", "pattern", "validation", "const")) {
      const auto regex{sourcemeta::core::to_regex(left_value.to_string())};
      if (!regex.has_value()) {
        return MAKE_RESULT(Unknown);
      }

      if (!right_value.is_string() ||
          sourcemeta::core::matches(regex.value(), right_value.to_string())) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "pattern", "validation", "enum")) {
      const auto regex{sourcemeta::core::to_regex(left_value.to_string())};
      if (!regex.has_value()) {
        return MAKE_RESULT(Unknown);
      }

      for (const auto &value : right_value.as_array()) {
        if (value.is_string() &&
            !sourcemeta::core::matches(regex.value(), value.to_string())) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "minimum", "validation", "const")) {
      if (!right_value.is_number() || right_value >= left_value) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "minimum", "validation", "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (value.is_number() && value < left_value) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "maximum", "validation", "const")) {
      if (!right_value.is_number() || right_value <= left_value) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "maximum", "validation", "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (value.is_number() && value > left_value) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "maximum", "validation",
                           "exclusiveMinimum")) {
      if (left_value > right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "maximum", "validation",
                           "exclusiveMaximum")) {
      if (left_value < right_value - sourcemeta::core::JSON{1}) {
        return MAKE_RESULT(Incompatible);
      } else {
        return MAKE_RESULT(Compatible);
      }
    }

    if (COMPARISON_2020_12("validation", "minimum", "validation",
                           "exclusiveMinimum")) {
      if (left_value > right_value + sourcemeta::core::JSON{1}) {
        return MAKE_RESULT(Incompatible);
      } else {
        return MAKE_RESULT(Compatible);
      }
    }

    if (COMPARISON_2020_12("validation", "minimum", "validation",
                           "exclusiveMaximum")) {
      if (left_value < right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    }

    if (COMPARISON_2020_12("validation", "exclusiveMinimum", "validation",
                           "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (value.is_number() && value <= left_value) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "exclusiveMinimum", "validation",
                           "const")) {
      if (!right_value.is_number() || right_value > left_value) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "exclusiveMaximum", "validation",
                           "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (value.is_number() && value >= left_value) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "exclusiveMaximum", "validation",
                           "const")) {
      if (!right_value.is_number() || right_value < left_value) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "exclusiveMinimum", "validation",
                           "exclusiveMinimum")) {
      if (left_value < right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    } else if (COMPARISON_2020_12("validation", "exclusiveMinimum",
                                  "validation", "exclusiveMaximum")) {
      if (left_value + sourcemeta::core::JSON{1} <
          right_value - sourcemeta::core::JSON{1}) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    } else if (COMPARISON_2020_12("validation", "exclusiveMaximum",
                                  "validation", "exclusiveMinimum")) {
      if (left_value - sourcemeta::core::JSON{1} >=
          right_value + sourcemeta::core::JSON{1}) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    } else if (COMPARISON_2020_12("validation", "exclusiveMaximum",
                                  "validation", "exclusiveMaximum")) {
      if (left_value > right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    } else if (COMPARISON_2020_12("validation", "exclusiveMinimum",
                                  "validation", "maximum")) {
      if (left_value < right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    } else if (COMPARISON_2020_12("validation", "exclusiveMinimum",
                                  "validation", "minimum")) {
      if (left_value < right_value) {
        return MAKE_RESULT(Compatible);
      } else {
        return MAKE_RESULT(Incompatible);
      }
    } else if (COMPARISON_2020_12("validation", "exclusiveMaximum",
                                  "validation", "maximum")) {
      if (left_value <= right_value) {
        return MAKE_RESULT(Incompatible);
      } else {
        return MAKE_RESULT(Compatible);
      }
    } else if (COMPARISON_2020_12("validation", "exclusiveMaximum",
                                  "validation", "minimum")) {
      if (left_value <= right_value) {
        return MAKE_RESULT(Incompatible);
      } else {
        return MAKE_RESULT(Compatible);
      }
    }

    if (COMPARISON_2020_12("validation", "minLength", "validation", "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (value.is_string() && static_cast<sourcemeta::core::JSON::Integer>(
                                     value.size()) < left_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "maxLength", "validation", "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (value.is_string() && static_cast<sourcemeta::core::JSON::Integer>(
                                     value.size()) > left_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "minLength", "validation", "const")) {
      if (!right_value.is_string() ||
          static_cast<sourcemeta::core::JSON::Integer>(right_value.size()) >=
              left_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "maxLength", "validation", "const")) {
      if (!right_value.is_string() ||
          static_cast<sourcemeta::core::JSON::Integer>(right_value.size()) <=
              left_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "minItems", "validation", "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (value.is_array() && static_cast<sourcemeta::core::JSON::Integer>(
                                    value.size()) < left_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "maxItems", "validation", "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (value.is_array() && static_cast<sourcemeta::core::JSON::Integer>(
                                    value.size()) > left_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "minItems", "validation", "const")) {
      if (!right_value.is_array() ||
          static_cast<sourcemeta::core::JSON::Integer>(right_value.size()) >=
              left_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "maxItems", "validation", "const")) {
      if (!right_value.is_array() ||
          static_cast<sourcemeta::core::JSON::Integer>(right_value.size()) <=
              left_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "minItems", "validation",
                           "uniqueItems")) {
      return MAKE_RESULT(Skip);
    }

    if (COMPARISON_2020_12("validation", "maxItems", "validation",
                           "uniqueItems")) {
      return MAKE_RESULT(Skip);
    }

    if (COMPARISON_2020_12("validation", "maxItems", "validation",
                           "uniqueItems")) {
      return MAKE_RESULT(Skip);
    }

    if (COMPARISON_2020_12("validation", "maxItems", "validation",
                           "uniqueItems")) {
      return MAKE_RESULT(Skip);
    }

    if (COMPARISON_2020_12("validation", "minProperties", "validation",
                           "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (value.is_object() && static_cast<sourcemeta::core::JSON::Integer>(
                                     value.size()) < left_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "maxProperties", "validation",
                           "enum")) {
      for (const auto &value : right_value.as_array()) {
        if (value.is_object() && static_cast<sourcemeta::core::JSON::Integer>(
                                     value.size()) > left_value.to_integer()) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "minProperties", "validation",
                           "const")) {
      if (!right_value.is_object() ||
          static_cast<sourcemeta::core::JSON::Integer>(right_value.size()) >=
              left_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "maxProperties", "validation",
                           "const")) {
      if (!right_value.is_object() ||
          static_cast<sourcemeta::core::JSON::Integer>(right_value.size()) <=
              left_value.to_integer()) {
        return MAKE_RESULT(Compatible);
      }

      return MAKE_RESULT(Incompatible);
    }

    if (COMPARISON_2020_12("validation", "minProperties", "validation",
                           "required")) {
      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("validation", "maxProperties", "validation",
                           "required")) {
      if (left_value.to_integer() <
          static_cast<sourcemeta::core::JSON::Integer>(right_value.size())) {
        return MAKE_RESULT(Incompatible);
      } else {
        return MAKE_RESULT(Compatible);
      }
    }

#define COMPARE_2020_12_BOUNDS(expected_vocabulary, expected_keyword_minimum,  \
                               expected_keyword_maximum)                       \
  if (COMPARISON_2020_12(expected_vocabulary, expected_keyword_minimum,        \
                         expected_vocabulary, expected_keyword_minimum)) {     \
    if (left_value <= right_value) {                                           \
      return MAKE_RESULT(Compatible);                                          \
    } else {                                                                   \
      return MAKE_RESULT(Incompatible);                                        \
    }                                                                          \
  } else if (COMPARISON_2020_12(expected_vocabulary, expected_keyword_minimum, \
                                expected_vocabulary,                           \
                                expected_keyword_maximum)) {                   \
    if (left_value <= right_value) {                                           \
      return MAKE_RESULT(Compatible);                                          \
    } else {                                                                   \
      return MAKE_RESULT(Incompatible);                                        \
    }                                                                          \
  } else if (COMPARISON_2020_12(expected_vocabulary, expected_keyword_maximum, \
                                expected_vocabulary,                           \
                                expected_keyword_minimum)) {                   \
    if (left_value >= right_value) {                                           \
      return MAKE_RESULT(Compatible);                                          \
    } else {                                                                   \
      return MAKE_RESULT(Incompatible);                                        \
    }                                                                          \
  } else if (COMPARISON_2020_12(expected_vocabulary, expected_keyword_maximum, \
                                expected_vocabulary,                           \
                                expected_keyword_maximum)) {                   \
    if (left_value >= right_value) {                                           \
      return MAKE_RESULT(Compatible);                                          \
    } else {                                                                   \
      return MAKE_RESULT(Incompatible);                                        \
    }                                                                          \
  }

    COMPARE_2020_12_BOUNDS("validation", "minimum", "maximum");
    COMPARE_2020_12_BOUNDS("validation", "minLength", "maxLength");
    COMPARE_2020_12_BOUNDS("validation", "minItems", "maxItems");
    COMPARE_2020_12_BOUNDS("validation", "minProperties", "maxProperties");
    COMPARE_2020_12_BOUNDS("validation", "minContains", "maxContains");

#undef COMPARE_2020_12_BOUNDS
  }

  return MAKE_RESULT(Unknown);

#undef COMPARISON_2020_12
#undef MAKE_RESULT
}

} // namespace octue::cruzer

#endif
