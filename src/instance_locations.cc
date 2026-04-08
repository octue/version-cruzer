#include <octue/cruzer.h>

#include <sourcemeta/core/json.h>
#include <sourcemeta/core/jsonpointer.h>
#include <sourcemeta/core/jsonschema.h>

#include <algorithm> // std::find
#include <cassert>   // assert
#include <cstddef>   // std::size_t
#include <map>       // std::map
#include <optional>  // std::optional, std::nullopt
#include <string>    // std::string, std::to_string
#include <vector>    // std::vector

namespace {

struct IteratorEntry {
  std::optional<sourcemeta::core::Pointer> parent;
  sourcemeta::core::Pointer pointer;
  octue::cruzer::PointerTemplate instance_location;
  octue::cruzer::PointerTemplate relative_instance_location;
  bool orphan;
};

static auto
walk(const std::optional<sourcemeta::core::Pointer> &parent,
     const sourcemeta::core::Pointer &pointer,
     const octue::cruzer::PointerTemplate &instance_location,
     const octue::cruzer::PointerTemplate &relative_instance_location,
     std::vector<IteratorEntry> &entries,
     const sourcemeta::core::JSON &subschema,
     const sourcemeta::core::SchemaWalker &walker,
     const sourcemeta::core::SchemaResolver &resolver,
     const std::string &dialect, const bool orphan) -> void {
  if (!sourcemeta::core::is_schema(subschema)) {
    return;
  }

  // Recalculate the dialect and its vocabularies at every step.
  // This is needed for correctly traversing through schemas that
  // contains pointers that use different dialect/vocabularies.
  // This is often the case for bundled schemas.
  const std::optional<std::string> current_dialect{
      sourcemeta::core::dialect(subschema, dialect)};
  assert(current_dialect.has_value());
  const std::string &new_dialect{current_dialect.value()};

  const std::optional<std::string> base_dialect{
      sourcemeta::core::base_dialect(subschema, resolver, new_dialect)};
  assert(base_dialect.has_value());
  const std::map<std::string, bool> vocabularies{sourcemeta::core::vocabularies(
      resolver, base_dialect.value(), new_dialect)};

  entries.push_back(
      {parent, pointer, instance_location, relative_instance_location, orphan});

  if (!subschema.is_object()) {
    return;
  }

  for (const auto &pair : subschema.as_object()) {
    switch (walker(pair.first, vocabularies).type) {
      case sourcemeta::core::SchemaKeywordType::
          ApplicatorValueTraverseSomeProperty: {
        sourcemeta::core::Pointer new_pointer{pointer};
        new_pointer.emplace_back(pair.first);
        auto new_instance_location{instance_location};
        new_instance_location.emplace_back(
            octue::cruzer::PointerTemplate::Condition{pair.first});
        new_instance_location.emplace_back(
            octue::cruzer::PointerTemplate::Wildcard::Property);
        walk(pointer, new_pointer, new_instance_location,
             {octue::cruzer::PointerTemplate::Condition{pair.first},
              octue::cruzer::PointerTemplate::Wildcard::Property},
             entries, pair.second, walker, resolver, new_dialect, orphan);
      } break;

      case sourcemeta::core::SchemaKeywordType::
          ApplicatorValueTraverseAnyPropertyKey: {
        sourcemeta::core::Pointer new_pointer{pointer};
        new_pointer.emplace_back(pair.first);
        auto new_instance_location{instance_location};
        new_instance_location.emplace_back(
            octue::cruzer::PointerTemplate::Wildcard::Key);
        walk(pointer, new_pointer, new_instance_location,
             {octue::cruzer::PointerTemplate::Wildcard::Key}, entries,
             pair.second, walker, resolver, new_dialect, orphan);
      } break;

      case sourcemeta::core::SchemaKeywordType::
          ApplicatorValueTraverseAnyItem: {
        sourcemeta::core::Pointer new_pointer{pointer};
        new_pointer.emplace_back(pair.first);
        auto new_instance_location{instance_location};
        new_instance_location.emplace_back(
            octue::cruzer::PointerTemplate::Wildcard::Item);
        walk(pointer, new_pointer, new_instance_location,
             {octue::cruzer::PointerTemplate::Wildcard::Item}, entries,
             pair.second, walker, resolver, new_dialect, orphan);
      } break;

      case sourcemeta::core::SchemaKeywordType::
          ApplicatorValueTraverseSomeItem: {
        sourcemeta::core::Pointer new_pointer{pointer};
        new_pointer.emplace_back(pair.first);
        auto new_instance_location{instance_location};
        new_instance_location.emplace_back(
            octue::cruzer::PointerTemplate::Condition{pair.first});
        new_instance_location.emplace_back(
            octue::cruzer::PointerTemplate::Wildcard::Item);
        walk(pointer, new_pointer, new_instance_location,
             {octue::cruzer::PointerTemplate::Condition{pair.first},
              octue::cruzer::PointerTemplate::Wildcard::Item},
             entries, pair.second, walker, resolver, new_dialect, orphan);
      } break;

      case sourcemeta::core::SchemaKeywordType::ApplicatorValueTraverseParent: {
        sourcemeta::core::Pointer new_pointer{pointer};
        new_pointer.emplace_back(pair.first);
        auto new_instance_location{instance_location};
        new_instance_location.pop_back();
        walk(pointer, new_pointer, new_instance_location, {}, entries,
             pair.second, walker, resolver, new_dialect, orphan);
      } break;

      case sourcemeta::core::SchemaKeywordType::ApplicatorValueInPlaceOther: {
        sourcemeta::core::Pointer new_pointer{pointer};
        new_pointer.emplace_back(pair.first);
        walk(pointer, new_pointer, instance_location, {}, entries, pair.second,
             walker, resolver, new_dialect, orphan);
      } break;

      case sourcemeta::core::SchemaKeywordType::ApplicatorValueInPlaceNegate: {
        sourcemeta::core::Pointer new_pointer{pointer};
        new_pointer.emplace_back(pair.first);
        auto new_instance_location{instance_location};
        new_instance_location.emplace_back(
            octue::cruzer::PointerTemplate::Negation{});
        walk(pointer, new_pointer, new_instance_location,
             {octue::cruzer::PointerTemplate::Negation{}}, entries, pair.second,
             walker, resolver, new_dialect, orphan);
      } break;

      case sourcemeta::core::SchemaKeywordType::ApplicatorValueInPlaceMaybe: {
        sourcemeta::core::Pointer new_pointer{pointer};
        new_pointer.emplace_back(pair.first);
        auto new_instance_location{instance_location};
        new_instance_location.emplace_back(
            octue::cruzer::PointerTemplate::Condition{pair.first});
        walk(pointer, new_pointer, new_instance_location,
             {octue::cruzer::PointerTemplate::Condition{pair.first}}, entries,
             pair.second, walker, resolver, new_dialect, orphan);
      } break;

      case sourcemeta::core::SchemaKeywordType::ApplicatorElementsTraverseItem:
        if (pair.second.is_array()) {
          for (std::size_t index = 0; index < pair.second.size(); index++) {
            sourcemeta::core::Pointer new_pointer{pointer};
            new_pointer.emplace_back(pair.first);
            new_pointer.emplace_back(index);
            auto new_instance_location{instance_location};
            new_instance_location.emplace_back(new_pointer.back());
            walk(pointer, new_pointer, new_instance_location,
                 {new_pointer.back()}, entries, pair.second.at(index), walker,
                 resolver, new_dialect, orphan);
          }
        }

        break;

      case sourcemeta::core::SchemaKeywordType::ApplicatorElementsInPlace:
        if (pair.second.is_array()) {
          for (std::size_t index = 0; index < pair.second.size(); index++) {
            sourcemeta::core::Pointer new_pointer{pointer};
            new_pointer.emplace_back(pair.first);
            new_pointer.emplace_back(index);
            walk(pointer, new_pointer, instance_location, {}, entries,
                 pair.second.at(index), walker, resolver, new_dialect, orphan);
          }
        }

        break;

      case sourcemeta::core::SchemaKeywordType::ApplicatorElementsInPlaceSome:
        if (pair.second.is_array()) {
          for (std::size_t index = 0; index < pair.second.size(); index++) {
            sourcemeta::core::Pointer new_pointer{pointer};
            new_pointer.emplace_back(pair.first);
            new_pointer.emplace_back(index);
            auto new_instance_location{instance_location};
            new_instance_location.emplace_back(
                octue::cruzer::PointerTemplate::Condition{pair.first});
            new_instance_location.emplace_back(
                octue::cruzer::PointerTemplate::Condition{
                    std::to_string(index)});
            walk(pointer, new_pointer, new_instance_location,
                 {octue::cruzer::PointerTemplate::Condition{pair.first},
                  octue::cruzer::PointerTemplate::Condition{
                      std::to_string(index)}},
                 entries, pair.second.at(index), walker, resolver, new_dialect,
                 orphan);
          }
        }

        break;

      case sourcemeta::core::SchemaKeywordType::
          ApplicatorElementsInPlaceSomeNegate:
        if (pair.second.is_array()) {
          for (std::size_t index = 0; index < pair.second.size(); index++) {
            sourcemeta::core::Pointer new_pointer{pointer};
            new_pointer.emplace_back(pair.first);
            new_pointer.emplace_back(index);
            auto new_instance_location{instance_location};
            new_instance_location.emplace_back(
                octue::cruzer::PointerTemplate::Condition{pair.first});
            new_instance_location.emplace_back(
                octue::cruzer::PointerTemplate::Condition{
                    std::to_string(index)});
            new_instance_location.emplace_back(
                octue::cruzer::PointerTemplate::Negation{});
            walk(pointer, new_pointer, new_instance_location,
                 {octue::cruzer::PointerTemplate::Condition{pair.first},
                  octue::cruzer::PointerTemplate::Condition{
                      std::to_string(index)},
                  octue::cruzer::PointerTemplate::Negation{}},
                 entries, pair.second.at(index), walker, resolver, new_dialect,
                 orphan);
          }
        }

        break;

      case sourcemeta::core::SchemaKeywordType::
          ApplicatorMembersTraversePropertyStatic:
        if (pair.second.is_object()) {
          for (const auto &subpair : pair.second.as_object()) {
            sourcemeta::core::Pointer new_pointer{pointer};
            new_pointer.emplace_back(pair.first);
            new_pointer.emplace_back(subpair.first);
            auto new_instance_location{instance_location};
            new_instance_location.emplace_back(new_pointer.back());
            walk(pointer, new_pointer, new_instance_location,
                 {new_pointer.back()}, entries, subpair.second, walker,
                 resolver, new_dialect, orphan);
          }
        }

        break;

      case sourcemeta::core::SchemaKeywordType::
          ApplicatorMembersTraversePropertyRegex:
        if (pair.second.is_object()) {
          for (const auto &subpair : pair.second.as_object()) {
            sourcemeta::core::Pointer new_pointer{pointer};
            new_pointer.emplace_back(pair.first);
            new_pointer.emplace_back(subpair.first);
            auto new_instance_location{instance_location};
            new_instance_location.emplace_back(subpair.first);
            walk(pointer, new_pointer, new_instance_location, {subpair.first},
                 entries, subpair.second, walker, resolver, new_dialect,
                 orphan);
          }
        }

        break;

      case sourcemeta::core::SchemaKeywordType::ApplicatorMembersInPlaceSome:
        if (pair.second.is_object()) {
          for (const auto &subpair : pair.second.as_object()) {
            sourcemeta::core::Pointer new_pointer{pointer};
            new_pointer.emplace_back(pair.first);
            new_pointer.emplace_back(subpair.first);
            auto new_instance_location{instance_location};
            new_instance_location.emplace_back(
                octue::cruzer::PointerTemplate::Condition{pair.first});
            new_instance_location.emplace_back(
                octue::cruzer::PointerTemplate::Condition{subpair.first});
            walk(pointer, new_pointer, new_instance_location,
                 {octue::cruzer::PointerTemplate::Condition{pair.first},
                  octue::cruzer::PointerTemplate::Condition{subpair.first}},
                 entries, subpair.second, walker, resolver, new_dialect,
                 orphan);
          }
        }

        break;

      case sourcemeta::core::SchemaKeywordType::LocationMembers:
        if (pair.second.is_object()) {
          for (const auto &subpair : pair.second.as_object()) {
            sourcemeta::core::Pointer new_pointer{pointer};
            new_pointer.emplace_back(pair.first);
            new_pointer.emplace_back(subpair.first);
            walk(pointer, new_pointer, instance_location, {}, entries,
                 subpair.second, walker, resolver, new_dialect, true);
          }
        }

        break;

      case sourcemeta::core::SchemaKeywordType::
          ApplicatorValueOrElementsTraverseAnyItemOrItem:
        if (pair.second.is_array()) {
          for (std::size_t index = 0; index < pair.second.size(); index++) {
            sourcemeta::core::Pointer new_pointer{pointer};
            new_pointer.emplace_back(pair.first);
            new_pointer.emplace_back(index);
            auto new_instance_location{instance_location};
            new_instance_location.emplace_back(new_pointer.back());
            walk(pointer, new_pointer, new_instance_location,
                 {new_pointer.back()}, entries, pair.second.at(index), walker,
                 resolver, new_dialect, orphan);
          }
        } else {
          sourcemeta::core::Pointer new_pointer{pointer};
          new_pointer.emplace_back(pair.first);
          auto new_instance_location{instance_location};
          new_instance_location.emplace_back(
              octue::cruzer::PointerTemplate::Wildcard::Item);
          walk(pointer, new_pointer, new_instance_location,
               {octue::cruzer::PointerTemplate::Wildcard::Item}, entries,
               pair.second, walker, resolver, new_dialect, orphan);
        }

        break;

      case sourcemeta::core::SchemaKeywordType::
          ApplicatorValueOrElementsInPlace:
        if (pair.second.is_array()) {
          for (std::size_t index = 0; index < pair.second.size(); index++) {
            sourcemeta::core::Pointer new_pointer{pointer};
            new_pointer.emplace_back(pair.first);
            new_pointer.emplace_back(index);
            walk(pointer, new_pointer, instance_location, {}, entries,
                 pair.second.at(index), walker, resolver, new_dialect, orphan);
          }
        } else {
          sourcemeta::core::Pointer new_pointer{pointer};
          new_pointer.emplace_back(pair.first);
          walk(pointer, new_pointer, instance_location, {}, entries,
               pair.second, walker, resolver, new_dialect, orphan);
        }

        break;
      case sourcemeta::core::SchemaKeywordType::Assertion:
        break;
      case sourcemeta::core::SchemaKeywordType::Annotation:
        break;
      case sourcemeta::core::SchemaKeywordType::Reference:
        break;
      case sourcemeta::core::SchemaKeywordType::Other:
        break;
      case sourcemeta::core::SchemaKeywordType::Comment:
        break;
      case sourcemeta::core::SchemaKeywordType::Unknown:
        break;
    }
  }
}

static auto
iterate(const sourcemeta::core::JSON &schema,
        const sourcemeta::core::SchemaWalker &walker,
        const sourcemeta::core::SchemaResolver &resolver,
        const std::optional<sourcemeta::core::JSON::String> &default_dialect)
    -> std::vector<IteratorEntry> {
  std::vector<IteratorEntry> entries;
  const std::optional<std::string> dialect{
      sourcemeta::core::dialect(schema, default_dialect)};

  const sourcemeta::core::Pointer pointer;
  const octue::cruzer::PointerTemplate instance_location;
  // If the given schema declares no dialect and the user didn't
  // pass a default, then there is nothing we can do. We know
  // the current schema is a subschema, but cannot walk any further.
  if (!dialect.has_value()) {
    entries.push_back(
        {std::nullopt, pointer, instance_location, instance_location, false});
  } else {
    walk(std::nullopt, pointer, instance_location, instance_location, entries,
         schema, walker, resolver, dialect.value(), false);
  }

  return entries;
}

struct CacheSubschema {
  const octue::cruzer::PointerTemplate instance_location;
  const octue::cruzer::PointerTemplate relative_instance_location;
  const bool orphan;
  const std::optional<sourcemeta::core::Pointer> parent;
};

static auto traverse_origin_instance_locations(
    const sourcemeta::core::SchemaFrame &frame,
    const std::map<sourcemeta::core::Pointer,
                   std::vector<octue::cruzer::PointerTemplate>> &instances,
    const sourcemeta::core::Pointer &current,
    const std::optional<octue::cruzer::PointerTemplate> &accumulator,
    std::vector<octue::cruzer::PointerTemplate> &destination) -> void {
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
                   std::vector<octue::cruzer::PointerTemplate>> &instances,
    const std::map<sourcemeta::core::Pointer, CacheSubschema> &cache,
    const CacheSubschema &cache_entry,
    std::vector<octue::cruzer::PointerTemplate> &destination,
    const std::optional<octue::cruzer::PointerTemplate> &accumulator) -> void {
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
                std::vector<octue::cruzer::PointerTemplate>> {
  std::map<sourcemeta::core::Pointer,
           std::vector<octue::cruzer::PointerTemplate>>
      result;
  std::map<sourcemeta::core::Pointer, CacheSubschema> subschemas;

  for (const auto &entry : iterate(schema, walker, resolver, default_dialect)) {
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
