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

  if (left_type == sourcemeta::core::SchemaKeywordType::Assertion) {
    // Any assertion is more open than the "false" schema, by definition
    if (right_subschema.is_boolean() && !right_subschema.to_boolean()) {
      return {Compatibility::Compatible, left_schema_location,
              right_schema_location};
    }

    // Any assertion is less open than the "true" schema, by definition
    if (right_subschema.is_boolean() && right_subschema.to_boolean()) {
      return {Compatibility::Incompatible, left_schema_location,
              right_schema_location};
    }

    assert(left_vocabulary.has_value());

    // "type"
    if (left_vocabulary.value() ==
            "https://json-schema.org/draft/2020-12/vocab/validation" &&
        left_keyword == "type") {
      if (right_vocabulary.has_value() &&
          right_vocabulary.value() ==
              "https://json-schema.org/draft/2020-12/vocab/validation" &&
          right_keyword == "type") {
        const auto &left_value{left_subschema.at(left_keyword)};
        const auto &right_value{right_subschema.at(right_keyword)};

        std::unordered_set<sourcemeta::core::JSON::String> left_set;
        std::unordered_set<sourcemeta::core::JSON::String> right_set;

        if (left_value.is_string()) {
          left_set.insert(left_value.to_string());
        } else if (left_value.is_array()) {
          for (const auto &value : left_value.as_array()) {
            left_set.insert(value.to_string());
          }
        }

        if (right_value.is_string()) {
          right_set.insert(right_value.to_string());
        } else if (right_value.is_array()) {
          for (const auto &value : right_value.as_array()) {
            right_set.insert(value.to_string());
          }
        }

        if (left_set.contains("number")) {
          left_set.emplace("integer");
        }

        if (right_set.contains("number")) {
          right_set.emplace("integer");
        }

        for (const auto &right_entry : right_set) {
          if (!left_set.contains(right_entry)) {
            return {Compatibility::Incompatible, left_schema_location,
                    right_schema_location};
          }
        }

        return {Compatibility::Compatible, left_schema_location,
                right_schema_location};
      }
    }
  }

  return {Compatibility::Unknown, left_schema_location, right_schema_location};
}

} // namespace octue::cruzer

#endif
