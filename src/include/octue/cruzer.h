#ifndef OCTUE_CRUZER_H_
#define OCTUE_CRUZER_H_

#include <sourcemeta/core/json.h>
#include <sourcemeta/core/jsonpointer.h>
#include <sourcemeta/core/jsonschema.h>

#ifndef OCTUE_CRUZER_EXPORT
#include <octue/cruzer_export.h>
#endif

#include <functional>    // std::reference_wrapper
#include <optional>      // std::optional, std::nullopt
#include <unordered_map> // std::unordered_map
#include <vector>        // std::vector

namespace octue::cruzer {
enum class Compatibility { Compatible, Incompatible, Skip, Unknown };

struct Trace {
  const Compatibility compatibility;
  const std::optional<sourcemeta::core::Pointer> left;
  const std::optional<sourcemeta::core::Pointer> right;
  auto operator==(const Trace &other) const noexcept -> bool = default;
};

struct SchemaLocation {
  const sourcemeta::core::PointerTemplate instance_location;
  const sourcemeta::core::Pointer pointer;
  const std::reference_wrapper<const sourcemeta::core::JSON> subschema;
  const sourcemeta::core::JSON::String dialect;
  const sourcemeta::core::JSON::String base_dialect;
  const std::reference_wrapper<const sourcemeta::core::SchemaWalker> walker;
  const std::reference_wrapper<const sourcemeta::core::SchemaResolver> resolver;
};

using SchemaIndex = std::unordered_map<sourcemeta::core::JSON::String,
                                       std::vector<SchemaLocation>>;

enum class SemVer { Major, Minor, Patch };

struct Result {
  const std::optional<SemVer> version;
  const std::vector<Trace> traces;
};

OCTUE_CRUZER_EXPORT
auto version(
    const sourcemeta::core::JSON &from, const sourcemeta::core::JSON &to,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_from =
        std::nullopt,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_to =
        std::nullopt,
    const sourcemeta::core::SchemaWalker &walker_from =
        sourcemeta::core::schema_official_walker,
    const sourcemeta::core::SchemaWalker &walker_to =
        sourcemeta::core::schema_official_walker,
    const sourcemeta::core::SchemaResolver &resolver_from =
        sourcemeta::core::schema_official_resolver,
    const sourcemeta::core::SchemaResolver &resolver_to =
        sourcemeta::core::schema_official_resolver,
    const std::optional<sourcemeta::core::JSON::String> &default_id_from =
        std::nullopt,
    const std::optional<sourcemeta::core::JSON::String> &default_id_to =
        std::nullopt) -> Result;

// A convenience helper for end users to avoid framing themselves
OCTUE_CRUZER_EXPORT
auto is_compatible_with(
    const sourcemeta::core::JSON &left, const sourcemeta::core::JSON &right,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_left =
        std::nullopt,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_right =
        std::nullopt,
    const sourcemeta::core::SchemaWalker &walker_left =
        sourcemeta::core::schema_official_walker,
    const sourcemeta::core::SchemaWalker &walker_right =
        sourcemeta::core::schema_official_walker,
    const sourcemeta::core::SchemaResolver &resolver_left =
        sourcemeta::core::schema_official_resolver,
    const sourcemeta::core::SchemaResolver &resolver_right =
        sourcemeta::core::schema_official_resolver,
    const std::optional<sourcemeta::core::JSON::String> &default_id_left =
        std::nullopt,
    const std::optional<sourcemeta::core::JSON::String> &default_id_right =
        std::nullopt) -> std::vector<Trace>;

OCTUE_CRUZER_EXPORT
auto is_compatible_with(const SchemaIndex &left, const SchemaIndex &right)
    -> std::vector<Trace>;

OCTUE_CRUZER_EXPORT
auto index(const sourcemeta::core::SchemaFrame &frame,
           const sourcemeta::core::JSON &schema,
           const sourcemeta::core::SchemaWalker &walker,
           const sourcemeta::core::SchemaResolver &resolver) -> SchemaIndex;

} // namespace octue::cruzer

#endif
