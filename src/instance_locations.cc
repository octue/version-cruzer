#include <octue/cruzer.h>

#include <sourcemeta/core/json.h>
#include <sourcemeta/core/jsonpointer.h>
#include <sourcemeta/core/jsonschema.h>

#include <algorithm> // std::find
#include <map>       // std::map
#include <optional>  // std::optional, std::nullopt
#include <vector>    // std::vector

namespace {

struct CacheSubschema {
  const sourcemeta::core::PointerTemplate instance_location;
  const sourcemeta::core::PointerTemplate relative_instance_location;
  const bool orphan;
  const std::optional<sourcemeta::core::Pointer> parent;
};

static auto traverse_origin_instance_locations(
    const sourcemeta::core::SchemaFrame &frame,
    const std::map<sourcemeta::core::Pointer,
                   std::vector<sourcemeta::core::PointerTemplate>> &instances,
    const sourcemeta::core::Pointer &current,
    const std::optional<sourcemeta::core::PointerTemplate> &accumulator,
    std::vector<sourcemeta::core::PointerTemplate> &destination) -> void {
  if (accumulator.has_value() &&
      std::find(destination.cbegin(), destination.cend(),
                accumulator.value()) == destination.cend()) {
    destination.push_back(accumulator.value());
  }

  for (const auto &reference : frame.references_to(current)) {
    const auto subschema_pointer{reference.get().first.second.initial()};
    // Avoid recursing to itself, in the case of circular subschemas
    if (subschema_pointer == current) {
      continue;
    }

    const auto match{instances.find(subschema_pointer)};
    if (match != instances.cend()) {
      for (const auto &instance_location : match->second) {
        traverse_origin_instance_locations(frame, instances, subschema_pointer,
                                           instance_location, destination);
      }
    }
  }
}

static auto repopulate_instance_locations(
    const sourcemeta::core::SchemaFrame &frame,
    const std::map<sourcemeta::core::Pointer,
                   std::vector<sourcemeta::core::PointerTemplate>> &instances,
    const std::map<sourcemeta::core::Pointer, CacheSubschema> &cache,
    const CacheSubschema &cache_entry,
    std::vector<sourcemeta::core::PointerTemplate> &destination,
    const std::optional<sourcemeta::core::PointerTemplate> &accumulator)
    -> void {
  if (cache_entry.orphan && cache_entry.instance_location.empty()) {
    return;
  } else if (cache_entry.parent.has_value() &&
             // Don't consider bases from the root subschema, as if that
             // subschema has any instance location other than "", then it
             // indicates a recursive reference
             !cache_entry.parent.value().empty()) {
    const auto match{instances.find(cache_entry.parent.value())};
    if (match == instances.cend()) {
      return;
    }

    for (const auto &parent_instance_location : match->second) {
      // Guard against overly unrolling recursive schemas
      if (parent_instance_location == cache_entry.instance_location) {
        continue;
      }

      auto new_accumulator = cache_entry.relative_instance_location;
      if (accumulator.has_value()) {
        for (const auto &token : accumulator.value()) {
          new_accumulator.emplace_back(token);
        }
      }

      auto result = parent_instance_location;
      for (const auto &token : new_accumulator) {
        result.emplace_back(token);
      }

      if (std::find(destination.cbegin(), destination.cend(), result) ==
          destination.cend()) {
        destination.push_back(result);
      }

      repopulate_instance_locations(frame, instances, cache,
                                    cache.at(cache_entry.parent.value()),
                                    destination, new_accumulator);
    }
  }
}

} // namespace

namespace octue::cruzer {

auto instance_locations(
    const sourcemeta::core::SchemaFrame &frame,
    const sourcemeta::core::JSON &schema,
    const sourcemeta::core::SchemaWalker &walker,
    const sourcemeta::core::SchemaResolver &resolver,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect)
    -> std::map<sourcemeta::core::Pointer,
                std::vector<sourcemeta::core::PointerTemplate>> {
  std::map<sourcemeta::core::Pointer,
           std::vector<sourcemeta::core::PointerTemplate>>
      result;
  std::map<sourcemeta::core::Pointer, CacheSubschema> subschemas;

  for (const auto &entry : sourcemeta::core::SchemaIterator{
           schema, walker, resolver, default_dialect}) {
    subschemas.emplace(entry.pointer,
                       CacheSubschema{entry.instance_location,
                                      entry.relative_instance_location,
                                      entry.orphan, entry.parent});
    if (entry.orphan) {
      result[entry.pointer] = {};
    } else {
      result[entry.pointer] = {entry.instance_location};
    }
  }

  for (const auto &location : frame.locations()) {
    if (location.second.type ==
        sourcemeta::core::SchemaFrame::LocationType::Pointer) {
      continue;
    }

    traverse_origin_instance_locations(frame, result, location.second.pointer,
                                       std::nullopt,
                                       result[location.second.pointer]);
  }

  for (const auto &location : frame.locations()) {
    if (location.second.type ==
        sourcemeta::core::SchemaFrame::LocationType::Pointer) {
      continue;
    }

    const auto subschema{subschemas.find(location.second.pointer)};
    if (subschema == subschemas.cend()) {
      continue;
    }

    repopulate_instance_locations(frame, result, subschemas, subschema->second,
                                  result[location.second.pointer],
                                  std::nullopt);
  }

  return result;
}

} // namespace octue::cruzer
