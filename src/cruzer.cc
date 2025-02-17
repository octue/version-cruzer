#include <octue/cruzer.h>

#include <cassert> // assert
#include <sstream> // std::ostringstream

#include "comparator.h"

static auto compare_subschemas(const octue::SchemaLocation &left,
                               const octue::SchemaLocation &right)
    -> std::vector<octue::Result> {
  assert(sourcemeta::core::is_schema(left.subschema.get()));
  assert(sourcemeta::core::is_schema(right.subschema.get()));

  // TODO: Do proper boolean compatibility checks
  if (left.subschema.get().is_boolean() && right.subschema.get().is_boolean()) {
    return {{octue::Compatibility::Unknown, left.pointer, right.pointer}};
  } else if (left.subschema.get().is_boolean()) {
    return {{octue::Compatibility::Unknown, left.pointer, right.pointer}};
  } else if (right.subschema.get().is_boolean()) {
    return {{octue::Compatibility::Unknown, left.pointer, right.pointer}};

  } else {
    const auto left_vocabularies{sourcemeta::core::vocabularies(
        left.resolver, left.base_dialect, left.dialect)};
    const auto right_vocabularies{sourcemeta::core::vocabularies(
        right.resolver, right.base_dialect, right.dialect)};

    std::vector<octue::Result> result;

    // TODO: Handle empty schemas
    for (const auto &left_entry : left.subschema.get().as_object()) {
      const auto left_walker_result{
          left.walker(left_entry.first, left_vocabularies)};
      for (const auto &right_entry : right.subschema.get().as_object()) {
        const auto right_walker_result{
            right.walker(right_entry.first, right_vocabularies)};
        result.push_back(octue::compare(
            left.subschema.get(), left_entry.first,
            left_walker_result.vocabulary, left_walker_result.type,
            left.pointer, right.subschema.get(), right_entry.first,
            right_walker_result.vocabulary, right_walker_result.type,
            right.pointer));
      }
    }

    return result;
  }
}

namespace octue {

auto is_compatible_with(const SchemaIndex &left, const SchemaIndex &right)
    -> std::vector<Result> {
  std::vector<Result> result;

  for (const auto &[instance_location, entries] : left) {
    const auto match{right.find(instance_location)};
    if (match == right.cend()) {
      for (const auto &entry : entries) {
        result.emplace_back(Compatibility::Compatible, entry.pointer,
                            std::nullopt);
      }
    } else {
      for (const auto &entry : entries) {
        for (const auto &other : match->second) {
          for (auto &&outcome : compare_subschemas(entry, other)) {
            result.push_back(std::move(outcome));
          }
        }
      }
    }
  }

  return result;
}

auto is_compatible_with(
    const sourcemeta::core::JSON &left, const sourcemeta::core::JSON &right,
    const sourcemeta::core::SchemaWalker &walker_left,
    const sourcemeta::core::SchemaWalker &walker_right,
    const sourcemeta::core::SchemaResolver &resolver_left,
    const sourcemeta::core::SchemaResolver &resolver_right,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_left,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_right,
    const std::optional<sourcemeta::core::JSON::String> &default_id_left,
    const std::optional<sourcemeta::core::JSON::String> &default_id_right)
    -> std::vector<Result> {
  // (1) Frame both schemas for unresolved instance locations
  sourcemeta::core::SchemaFrame frame_left{
      sourcemeta::core::SchemaFrame::Mode::Instances};
  frame_left.analyse(left, walker_left, resolver_left, default_dialect_left,
                     default_id_left);
  sourcemeta::core::SchemaFrame frame_right{
      sourcemeta::core::SchemaFrame::Mode::Instances};
  frame_right.analyse(right, walker_right, resolver_right,
                      default_dialect_right, default_id_right);

  // (2) Index subschemas by their unresolved instance locations
  const auto index_left{index(frame_left, left, walker_left, resolver_left)};
  const auto index_right{
      index(frame_right, right, walker_right, resolver_right)};

  // (3) Proceed with the compatibility checks
  return is_compatible_with(index_left, index_right);
}

auto index(const sourcemeta::core::SchemaFrame &frame,
           const sourcemeta::core::JSON &schema,
           const sourcemeta::core::SchemaWalker &walker,
           const sourcemeta::core::SchemaResolver &resolver) -> SchemaIndex {
  SchemaIndex result;

  for (const auto &location : frame.locations()) {
    // We only care about anonymous subschemas and named subschemas (a.k.a.
    // resources)
    if (location.second.type !=
            sourcemeta::core::SchemaFrame::LocationType::Resource &&
        location.second.type !=
            sourcemeta::core::SchemaFrame::LocationType::Subschema) {
      continue;
    }

    for (const auto &instance_location :
         frame.instance_locations(location.second)) {
      // We don't really need to manipulate the pointer templates
      // for this use case, so we can stringify to simplify the map
      std::ostringstream key;
      sourcemeta::core::stringify(instance_location, key);
      result[key.str()].emplace_back(
          location.second.pointer,
          sourcemeta::core::get(schema, location.second.pointer),
          location.second.dialect, location.second.base_dialect, walker,
          resolver);
    }
  }

  return result;
}

} // namespace octue
