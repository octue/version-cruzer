#include <octue/cruzer.h>

#include <algorithm> // std::move
#include <cassert>   // assert
#include <iterator>  // std::back_inserter
#include <sstream>   // std::ostringstream

#include "comparator.h"

static auto
effective_subschema(const octue::cruzer::SchemaLocation &location) noexcept
    -> const sourcemeta::core::JSON & {
  const static sourcemeta::core::JSON wildcard{true};
  return location.subschema.get().is_object() &&
                 location.subschema.get().empty()
             ? wildcard
             : location.subschema.get();
}

// TODO: Investigate why older GCC versions get confused here
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif

static auto compare_subschemas(const octue::cruzer::SchemaLocation &left,
                               const octue::cruzer::SchemaLocation &right)
    -> std::vector<octue::cruzer::Trace> {
  assert(sourcemeta::core::is_schema(left.subschema.get()));
  assert(sourcemeta::core::is_schema(right.subschema.get()));

  const auto left_vocabularies{sourcemeta::core::vocabularies(
      left.resolver, left.base_dialect, left.dialect)};
  const auto right_vocabularies{sourcemeta::core::vocabularies(
      right.resolver, right.base_dialect, right.dialect)};

  // A simple default to more transparently handle boolean schemas
  constexpr auto BOOLEAN_KEYWORD_NAME{""};

  std::vector<octue::cruzer::Trace> result;

  if (left.subschema.get().is_object() && right.subschema.get().is_object() &&
      !left.subschema.get().empty() && !right.subschema.get().empty()) {
    for (const auto &left_entry : left.subschema.get().as_object()) {
      const auto left_walker_result{
          left.walker(left_entry.first, left_vocabularies)};
      for (const auto &right_entry : right.subschema.get().as_object()) {
        const auto right_walker_result{
            right.walker(right_entry.first, right_vocabularies)};
        result.push_back(octue::cruzer::compare(
            left.subschema.get(), left_entry.first,
            left_walker_result.vocabulary, left_walker_result.type,
            left.pointer.concat({left_entry.first}), left.instance_location,
            right.subschema.get(), right_entry.first,
            right_walker_result.vocabulary, right_walker_result.type,
            right.pointer.concat({right_entry.first}),
            right.instance_location));
      }
    }
  } else if (left.subschema.get().is_object() &&
             (right.subschema.get().is_boolean() ||
              right.subschema.get().empty())) {
    if (left.subschema.get().empty()) {
      result.push_back(octue::cruzer::compare(
          effective_subschema(left), BOOLEAN_KEYWORD_NAME, std::nullopt,
          sourcemeta::core::SchemaKeywordType::Assertion, left.pointer,
          left.instance_location, effective_subschema(right),
          BOOLEAN_KEYWORD_NAME, std::nullopt,
          sourcemeta::core::SchemaKeywordType::Assertion, right.pointer,
          right.instance_location));
    } else {
      for (const auto &left_entry : left.subschema.get().as_object()) {
        const auto left_walker_result{
            left.walker(left_entry.first, left_vocabularies)};
        result.push_back(octue::cruzer::compare(
            left.subschema.get(), left_entry.first,
            left_walker_result.vocabulary, left_walker_result.type,
            left.pointer.concat({left_entry.first}), left.instance_location,
            effective_subschema(right), BOOLEAN_KEYWORD_NAME, std::nullopt,
            sourcemeta::core::SchemaKeywordType::Assertion, right.pointer,
            right.instance_location));
      }
    }
  } else if (right.subschema.get().is_object() &&
             (left.subschema.get().is_boolean() ||
              left.subschema.get().empty())) {
    if (right.subschema.get().empty()) {
      result.push_back(octue::cruzer::compare(
          effective_subschema(left), BOOLEAN_KEYWORD_NAME, std::nullopt,
          sourcemeta::core::SchemaKeywordType::Assertion, left.pointer,
          left.instance_location, effective_subschema(right),
          BOOLEAN_KEYWORD_NAME, std::nullopt,
          sourcemeta::core::SchemaKeywordType::Assertion, right.pointer,
          right.instance_location));
    } else {
      for (const auto &right_entry : right.subschema.get().as_object()) {
        const auto right_walker_result{
            right.walker(right_entry.first, right_vocabularies)};
        result.push_back(octue::cruzer::compare(
            effective_subschema(left), BOOLEAN_KEYWORD_NAME, std::nullopt,
            sourcemeta::core::SchemaKeywordType::Assertion, left.pointer,
            left.instance_location, right.subschema.get(), right_entry.first,
            right_walker_result.vocabulary, right_walker_result.type,
            right.pointer.concat({right_entry.first}),
            right.instance_location));
      }
    }
  } else {
    assert(left.subschema.get().is_boolean() || left.subschema.get().empty());
    assert(right.subschema.get().is_boolean() || right.subschema.get().empty());
    result.push_back(octue::cruzer::compare(
        effective_subschema(left), BOOLEAN_KEYWORD_NAME, std::nullopt,
        sourcemeta::core::SchemaKeywordType::Assertion, left.pointer,
        left.instance_location, effective_subschema(right),
        BOOLEAN_KEYWORD_NAME, std::nullopt,
        sourcemeta::core::SchemaKeywordType::Assertion, right.pointer,
        left.instance_location));
  }

  // We should be always be making at least one comparison,
  assert(!result.empty());
  return result;
}

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

static auto
is_annotation_subschema(const sourcemeta::core::SchemaFrame &frame,
                        const sourcemeta::core::SchemaFrame::Location &location,
                        const sourcemeta::core::SchemaWalker &walker,
                        const sourcemeta::core::SchemaResolver &resolver)
    -> bool {
  if (!location.parent.has_value()) {
    return false;
  }

  const auto &keyword{location.parent.value().empty()
                          ? location.pointer.back().to_property()
                          : location.parent.value().back().to_property()};
  const auto walker_result{
      walker(keyword, frame.vocabularies(location, resolver))};
  if (walker_result.type ==
      sourcemeta::core::SchemaKeywordType::ApplicatorValueInPlaceOther) {
    return true;
  }

  // TODO: It sucks that we have to loop over all entries to find subschema
  // location parents. Sourcemeta Core should provide a better interface for
  // this
  for (const auto &sublocation : frame.locations()) {
    if (sublocation.second.type !=
            sourcemeta::core::SchemaFrame::LocationType::Resource &&
        sublocation.second.type !=
            sourcemeta::core::SchemaFrame::LocationType::Subschema) {
      continue;
    }

    if (sublocation.second.pointer == location.parent.value() &&
        is_annotation_subschema(frame, sublocation.second, walker, resolver)) {
      return true;
    }
  }

  return false;
}

namespace octue::cruzer {

auto is_compatible_with(const SchemaIndex &left, const SchemaIndex &right)
    -> std::vector<Trace> {
  std::vector<Trace> result;

  for (const auto &[instance_location, entries] : left) {
    const auto match{right.find(instance_location)};
    if (match == right.cend()) {
      for (const auto &entry : entries) {
        // We silently omit locations that are not on both sides. If
        // any, it is the responsibility of applicator comparators to
        // prevent a problematic comparison case
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
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_left,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_right,
    const sourcemeta::core::SchemaWalker &walker_left,
    const sourcemeta::core::SchemaWalker &walker_right,
    const sourcemeta::core::SchemaResolver &resolver_left,
    const sourcemeta::core::SchemaResolver &resolver_right,
    const std::optional<sourcemeta::core::JSON::String> &default_id_left,
    const std::optional<sourcemeta::core::JSON::String> &default_id_right)
    -> std::vector<Trace> {
  sourcemeta::core::SchemaFrame frame_left{
      sourcemeta::core::SchemaFrame::Mode::Instances};
  frame_left.analyse(left, walker_left, resolver_left, default_dialect_left,
                     default_id_left);
  sourcemeta::core::SchemaFrame frame_right{
      sourcemeta::core::SchemaFrame::Mode::Instances};
  frame_right.analyse(right, walker_right, resolver_right,
                      default_dialect_right, default_id_right);

  const auto index_left{index(frame_left, left, walker_left, resolver_left)};
  const auto index_right{
      index(frame_right, right, walker_right, resolver_right)};

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

    if (is_annotation_subschema(frame, location.second, walker, resolver)) {
      continue;
    }

    for (const auto &instance_location :
         frame.instance_locations(location.second)) {
      // We don't really need to manipulate the pointer templates
      // for this use case, so we can stringify to simplify the map
      std::ostringstream key;
      sourcemeta::core::stringify(instance_location, key);
      result[key.str()].emplace_back(
          instance_location, location.second.pointer,
          sourcemeta::core::get(schema, location.second.pointer),
          location.second.dialect, location.second.base_dialect, walker,
          resolver);
    }

    for (auto &entry : result) {
      for (auto &subentry : result) {
        if (entry.first == subentry.first) {
          continue;
        }

        if (!entry.second.front().instance_location.matches(
                subentry.second.front().instance_location)) {
          continue;
        }

        for (const auto &sublocation : entry.second) {
          if (std::find_if(subentry.second.cbegin(), subentry.second.cend(),
                           [&sublocation](const auto &current) {
                             return current.pointer == sublocation.pointer;
                           }) != subentry.second.cend()) {
            continue;
          }

          subentry.second.push_back(sublocation);
        }

        for (const auto &sublocation : subentry.second) {
          if (std::find_if(entry.second.cbegin(), entry.second.cend(),
                           [&sublocation](const auto &current) {
                             return current.pointer == sublocation.pointer;
                           }) != entry.second.cend()) {
            continue;
          }

          entry.second.push_back(sublocation);
        }
      }
    }
  }

  return result;
}

auto version(
    const sourcemeta::core::JSON &from, const sourcemeta::core::JSON &to,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_from,
    const std::optional<sourcemeta::core::JSON::String> &default_dialect_to,
    const sourcemeta::core::SchemaWalker &walker_from,
    const sourcemeta::core::SchemaWalker &walker_to,
    const sourcemeta::core::SchemaResolver &resolver_from,
    const sourcemeta::core::SchemaResolver &resolver_to,
    const std::optional<sourcemeta::core::JSON::String> &default_id_from,
    const std::optional<sourcemeta::core::JSON::String> &default_id_to)
    -> Result {
  // (1) Frame both schemas for unresolved instance locations
  sourcemeta::core::SchemaFrame frame_from{
      sourcemeta::core::SchemaFrame::Mode::Instances};
  frame_from.analyse(from, walker_from, resolver_from, default_dialect_from,
                     default_id_from);
  sourcemeta::core::SchemaFrame frame_to{
      sourcemeta::core::SchemaFrame::Mode::Instances};
  frame_to.analyse(to, walker_to, resolver_to, default_dialect_to,
                   default_id_to);

  // (2) Index subschemas by their unresolved instance locations
  const auto index_from{index(frame_from, from, walker_from, resolver_from)};
  const auto index_to{index(frame_to, to, walker_to, resolver_to)};

  // (3) Collect all version compatibility traces
  std::vector<Trace> from_to_unknowns;
  std::vector<Trace> to_from_unknowns;
  std::vector<Trace> from_to_incompatibilities;
  std::vector<Trace> to_from_incompatibilities;

  const auto from_to{is_compatible_with(index_from, index_to)};
  const auto to_from{is_compatible_with(index_to, index_from)};

  for (auto &&trace : from_to) {
    switch (trace.compatibility) {
      case Compatibility::Incompatible:
        from_to_incompatibilities.push_back(std::move(trace));
        break;
      case Compatibility::Unknown:
        from_to_unknowns.push_back(std::move(trace));
        break;
      default:
        continue;
    }
  }

  for (auto &&trace : to_from) {
    switch (trace.compatibility) {
      case Compatibility::Incompatible:
        to_from_incompatibilities.emplace_back(
            trace.compatibility, std::move(trace.right), std::move(trace.left));
        break;
      case Compatibility::Unknown:
        to_from_unknowns.emplace_back(
            trace.compatibility, std::move(trace.right), std::move(trace.left));
        break;
      default:
        continue;
    }
  }

  // (4) Figure out the result
  if (!from_to_unknowns.empty() || !to_from_unknowns.empty()) {
    for (auto &&trace : to_from_unknowns) {
      if (std::find(from_to_unknowns.cbegin(), from_to_unknowns.cend(),
                    trace) == from_to_unknowns.cend()) {
        from_to_unknowns.push_back(std::move(trace));
      }
    }

    return {std::nullopt, std::move(from_to_unknowns)};
  } else if (!from_to_incompatibilities.empty() &&
             !to_from_incompatibilities.empty()) {
    for (auto &&trace : to_from_incompatibilities) {
      if (std::find(from_to_incompatibilities.cbegin(),
                    from_to_incompatibilities.cend(),
                    trace) == from_to_incompatibilities.cend()) {
        from_to_incompatibilities.push_back(std::move(trace));
      }
    }

    return {SemVer::Major, std::move(from_to_incompatibilities)};
  } else if (!to_from_incompatibilities.empty()) {
    return {SemVer::Major, std::move(to_from_incompatibilities)};
  } else if (!from_to_incompatibilities.empty()) {
    return {SemVer::Minor, std::move(from_to_incompatibilities)};
  } else {
    return {SemVer::Patch, {}};
  }
}

} // namespace octue::cruzer
