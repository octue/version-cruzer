#ifndef OCTUE_CRUZER_HELPERS_H_
#define OCTUE_CRUZER_HELPERS_H_

#include <sourcemeta/core/json.h>
#include <sourcemeta/core/regex.h>

#include <algorithm>     // std::all_of, std::none_of
#include <functional>    // std::greater, std::less
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

// TODO: Elevate to Core
static auto defines_all_array(const sourcemeta::core::JSON &object,
                              const sourcemeta::core::JSON &array) -> bool {
  return std::all_of(
      array.as_array().cbegin(), array.as_array().cend(),
      [&object](const auto &key) { return object.defines(key.to_string()); });
}

static auto size_geq_integer(const sourcemeta::core::JSON &value,
                             const sourcemeta::core::JSON &size) -> bool {
  return static_cast<sourcemeta::core::JSON::Integer>(value.size()) >=
         size.to_integer();
}

static auto size_leq_integer(const sourcemeta::core::JSON &value,
                             const sourcemeta::core::JSON &size) -> bool {
  return static_cast<sourcemeta::core::JSON::Integer>(value.size()) <=
         size.to_integer();
}

static auto geq(const sourcemeta::core::JSON &left,
                const sourcemeta::core::JSON &right) -> bool {
  return left >= right;
}

static auto leq(const sourcemeta::core::JSON &left,
                const sourcemeta::core::JSON &right) -> bool {
  return left <= right;
}

static auto divisible_by(const sourcemeta::core::JSON &left,
                         const sourcemeta::core::JSON &right) -> bool {
  return left.divisible_by(right);
}

static auto dependent_required(const sourcemeta::core::JSON &left,
                               const sourcemeta::core::JSON &right) -> bool {
  return std::none_of(right.as_object().cbegin(), right.as_object().cend(),
                      [&left](const auto &dependency) {
                        return left.defines(dependency.first) &&
                               !defines_all_array(left, dependency.second);
                      });
}

static auto pattern(const sourcemeta::core::JSON &value,
                    const sourcemeta::core::JSON &pattern) -> bool {
  const auto regex{sourcemeta::core::to_regex(pattern.to_string())};
  return regex.has_value() &&
         sourcemeta::core::matches(regex.value(), value.to_string());
}

static auto unique_items(const sourcemeta::core::JSON &array,
                         const sourcemeta::core::JSON &value) -> bool {
  return array.unique() || !value.to_boolean();
}

#endif
