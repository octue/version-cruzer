#ifndef OCTUE_CRUZER_COMPARATOR_H_
#define OCTUE_CRUZER_COMPARATOR_H_

#include <cassert> // assert

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

  // If things are equal, then they are compatible by definition
  if (left_type == right_type && left_keyword == right_keyword &&
      left_vocabulary == right_vocabulary && left_subschema.is_object() &&
      right_subschema.is_object() &&
      left_subschema.at(left_keyword) == right_subschema.at(right_keyword)) {
    return {Compatibility::Compatible, left_schema_location,
            right_schema_location};
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
  }

  switch (left_type) {
    case sourcemeta::core::SchemaKeywordType::Other:
      return {Compatibility::Compatible, left_schema_location,
              right_schema_location};
    case sourcemeta::core::SchemaKeywordType::Comment:
      return {Compatibility::Annotation, left_schema_location,
              right_schema_location};
    case sourcemeta::core::SchemaKeywordType::Reference:
      return {Compatibility::Compatible, left_schema_location,
              right_schema_location};
    case sourcemeta::core::SchemaKeywordType::LocationMembers:
      return {Compatibility::Compatible, left_schema_location,
              right_schema_location};
    default:
      break;
  }

  return {Compatibility::Unknown, left_schema_location, right_schema_location};
}

} // namespace octue::cruzer

#endif
