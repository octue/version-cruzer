#ifndef OCTUE_CRUZER_COMPARATOR_H_
#define OCTUE_CRUZER_COMPARATOR_H_

namespace octue {

static auto compare(
    // Left current subschema
    const sourcemeta::core::JSON &,
    // Left keyword name
    const sourcemeta::core::JSON::String &,
    // Left keyword vocabulary
    const std::optional<sourcemeta::core::JSON::String> &,
    // Left keyword type
    const sourcemeta::core::SchemaKeywordType &,
    // Left schema location
    const sourcemeta::core::Pointer &left_schema_location,

    // Right current subschema
    const sourcemeta::core::JSON &,
    // Right keyword name
    const sourcemeta::core::JSON::String &,
    // Right keyword vocabulary
    const std::optional<sourcemeta::core::JSON::String> &,
    // Right keyword type
    const sourcemeta::core::SchemaKeywordType &,
    // Right schema location
    const sourcemeta::core::Pointer &right_schema_location) -> octue::Result {
  return {Compatibility::Unknown, left_schema_location, right_schema_location};
}

} // namespace octue

#endif
