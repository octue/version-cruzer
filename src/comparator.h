#ifndef OCTUE_CRUZER_COMPARATOR_H_
#define OCTUE_CRUZER_COMPARATOR_H_

#include <cassert>       // assert
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

template <typename T>
static auto is_superset(const T &left, const T &right) -> bool {
  for (const auto &right_entry : right) {
    if (!left.contains(right_entry)) {
      return false;
    }
  }

  return true;
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
  }

  return MAKE_RESULT(Unknown);

#undef COMPARISON_2020_12
#undef MAKE_RESULT
}

} // namespace octue::cruzer

#endif
