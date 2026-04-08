#ifndef OCTUE_CRUZER_H_
#define OCTUE_CRUZER_H_

#include <sourcemeta/core/json.h>
#include <sourcemeta/core/jsonpointer.h>
#include <sourcemeta/core/jsonschema.h>

#include <octue/cruzer_pointer_template.h>

#ifndef OCTUE_CRUZER_EXPORT
#include <octue/cruzer_export.h>
#endif

#include <cstdint>       // std::uint8_t
#include <functional>    // std::reference_wrapper
#include <map>           // std::map
#include <optional>      // std::optional, std::nullopt
#include <string_view>   // std::string_view
#include <unordered_map> // std::unordered_map
#include <vector>        // std::vector

namespace octue::cruzer {
enum class Compatibility : std::uint8_t {
  Compatible,
  Incompatible,
  Skip,
  Unknown
};

struct Trace {
  Compatibility compatibility;
  std::optional<sourcemeta::core::WeakPointer> left;
  std::optional<sourcemeta::core::WeakPointer> right;
  [[nodiscard]] auto operator==(const Trace &other) const noexcept
      -> bool = default;
};

struct SchemaLocation {
  octue::cruzer::PointerTemplate instance_location;
  std::optional<sourcemeta::core::WeakPointer> parent;
  sourcemeta::core::WeakPointer pointer;
  std::reference_wrapper<const sourcemeta::core::JSON> subschema;
  std::reference_wrapper<const sourcemeta::core::JSON> root;
  std::string_view dialect;
  sourcemeta::core::SchemaBaseDialect base_dialect;
  std::reference_wrapper<const sourcemeta::core::SchemaWalker> walker;
  std::reference_wrapper<const sourcemeta::core::SchemaResolver> resolver;
};

using SchemaIndex = std::unordered_map<sourcemeta::core::JSON::String,
                                       std::vector<SchemaLocation>>;

enum class SemVer : std::uint8_t { Major, Minor, Patch, Equal };

struct Result {
  std::optional<SemVer> version;
  std::vector<Trace> traces;
};

OCTUE_CRUZER_EXPORT
auto version(
    const sourcemeta::core::JSON &from, const sourcemeta::core::JSON &to,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_from =
        std::nullopt,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_to =
        std::nullopt,
    const sourcemeta::core::SchemaWalker &walker_from =
        sourcemeta::core::schema_walker,
    const sourcemeta::core::SchemaWalker &walker_to =
        sourcemeta::core::schema_walker,
    const sourcemeta::core::SchemaResolver &resolver_from =
        sourcemeta::core::schema_resolver,
    const sourcemeta::core::SchemaResolver &resolver_to =
        sourcemeta::core::schema_resolver,
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
        sourcemeta::core::schema_walker,
    const sourcemeta::core::SchemaWalker &walker_right =
        sourcemeta::core::schema_walker,
    const sourcemeta::core::SchemaResolver &resolver_left =
        sourcemeta::core::schema_resolver,
    const sourcemeta::core::SchemaResolver &resolver_right =
        sourcemeta::core::schema_resolver,
    const std::optional<sourcemeta::core::JSON::String> &default_id_left =
        std::nullopt,
    const std::optional<sourcemeta::core::JSON::String> &default_id_right =
        std::nullopt) -> std::vector<Trace>;

OCTUE_CRUZER_EXPORT
auto is_compatible_with(const SchemaIndex &left, const SchemaIndex &right)
    -> std::vector<Trace>;

OCTUE_CRUZER_EXPORT
auto instance_locations(const sourcemeta::core::SchemaFrame &frame,
                        const sourcemeta::core::JSON &schema,
                        const sourcemeta::core::SchemaWalker &walker =
                            sourcemeta::core::schema_walker,
                        const sourcemeta::core::SchemaResolver &resolver =
                            sourcemeta::core::schema_resolver,
                        const std::optional<sourcemeta::core::JSON::String>
                            &default_dialect = std::nullopt)
    -> std::map<sourcemeta::core::WeakPointer,
                std::vector<octue::cruzer::PointerTemplate>>;

OCTUE_CRUZER_EXPORT
auto index(const sourcemeta::core::SchemaFrame &frame,
           const sourcemeta::core::JSON &schema,
           const sourcemeta::core::SchemaWalker &walker,
           const sourcemeta::core::SchemaResolver &resolver,
           const std::optional<sourcemeta::core::JSON::String>
               &default_dialect = std::nullopt) -> SchemaIndex;

} // namespace octue::cruzer

#endif
