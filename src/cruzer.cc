#include <octue/cruzer.h>

#include <sstream> // std::ostringstream

namespace octue {

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

  return {};
}

auto index(const sourcemeta::core::SchemaFrame &frame,
           const sourcemeta::core::JSON &schema) -> SchemaIndex {
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
          location.second.dialect, location.second.base_dialect);
    }
  }

  return result;
}

} // namespace octue
