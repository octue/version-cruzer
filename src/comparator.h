#ifndef OCTUE_CRUZER_COMPARATOR_H_
#define OCTUE_CRUZER_COMPARATOR_H_

#include <cassert> // assert

namespace octue {

static auto compare(
    // Left current subschema
    const sourcemeta::core::JSON &left_subschema,
    // Left keyword name
    const sourcemeta::core::JSON::String &,
    // Left keyword vocabulary
    const std::optional<sourcemeta::core::JSON::String> &,
    // Left keyword type
    const sourcemeta::core::SchemaKeywordType &left_type,
    // Left schema location
    const sourcemeta::core::Pointer &left_schema_location,

    // Right current subschema
    const sourcemeta::core::JSON &right_subschema,
    // Right keyword name
    const sourcemeta::core::JSON::String &,
    // Right keyword vocabulary
    const std::optional<sourcemeta::core::JSON::String> &,
    // Right keyword type
    const sourcemeta::core::SchemaKeywordType &right_type,
    // Right schema location
    const sourcemeta::core::Pointer &right_schema_location) -> octue::Result {

  if (left_subschema.is_boolean() && right_subschema.is_boolean()) {
    return {!left_subschema.to_boolean() && right_subschema.to_boolean()
                ? Compatibility::Incompatible
                : Compatibility::Compatible,
            left_schema_location, right_schema_location};
  }

  if (left_subschema.is_boolean() && left_subschema.to_boolean()) {
    return {Compatibility::Compatible, left_schema_location,
            right_schema_location};
  }

  switch (left_type) {
    case sourcemeta::core::SchemaKeywordType::Other:
      if (right_subschema.is_boolean() && right_subschema.to_boolean()) {
        return {Compatibility::Compatible, left_schema_location,
                right_schema_location};
      }

      if (right_type == sourcemeta::core::SchemaKeywordType::Other) {
        return {Compatibility::Compatible, left_schema_location,
                right_schema_location};
      }

      break;
    case sourcemeta::core::SchemaKeywordType::Comment:
      if (right_subschema.is_boolean() && right_subschema.to_boolean()) {
        return {Compatibility::Annotation, left_schema_location,
                right_schema_location};
      }

      break;

    case sourcemeta::core::SchemaKeywordType::Reference:
      if (right_subschema.is_boolean() && right_subschema.to_boolean()) {
        return {Compatibility::Compatible, left_schema_location,
                right_schema_location};
      }

      break;

    case sourcemeta::core::SchemaKeywordType::LocationMembers:
      if (right_subschema.is_boolean() && right_subschema.to_boolean()) {
        return {Compatibility::Compatible, left_schema_location,
                right_schema_location};
      }

      break;

    default:
      return {Compatibility::Unknown, left_schema_location,
              right_schema_location};
  }

  return {Compatibility::Unknown, left_schema_location, right_schema_location};
}

} // namespace octue

#endif
