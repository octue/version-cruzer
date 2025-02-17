#ifndef OCTUE_CRUZER_H_
#define OCTUE_CRUZER_H_

#include <sourcemeta/core/json.h>
#include <sourcemeta/core/jsonpointer.h>
#include <sourcemeta/core/jsonschema.h>

#ifndef OCTUE_CRUZER_EXPORT
#include <octue/cruzer_export.h>
#endif

#include <optional> // std::optional, std::nullopt
#include <vector>   // std::vector

namespace octue {
enum class Compatibility { Compatible, Incompatible, Annotation, Unknown };

struct Result {
  const Compatibility compatibility;
  const sourcemeta::core::Pointer left;
  const sourcemeta::core::Pointer right;
};

auto is_compatible_with(
    const sourcemeta::core::JSON &left, const sourcemeta::core::JSON &right,
    const sourcemeta::core::SchemaWalker &walker_left =
        sourcemeta::core::schema_official_walker,
    const sourcemeta::core::SchemaWalker &walker_right =
        sourcemeta::core::schema_official_walker,
    const sourcemeta::core::SchemaResolver &resolver_left =
        sourcemeta::core::schema_official_resolver,
    const sourcemeta::core::SchemaResolver &resolver_right =
        sourcemeta::core::schema_official_resolver,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_left =
        std::nullopt,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_right =
        std::nullopt,
    const std::optional<sourcemeta::core::JSON::String> &default_id_left =
        std::nullopt,
    const std::optional<sourcemeta::core::JSON::String> &default_id_right =
        std::nullopt) -> std::vector<Result>;

} // namespace octue

#endif
