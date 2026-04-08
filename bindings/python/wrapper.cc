#include <octue/cruzer.h>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

static auto version(pybind11::object from, pybind11::object to)
    -> pybind11::dict {
  const auto from_string{pybind11::module_::import("json")
                             .attr("dumps")(from)
                             .cast<std::string>()};
  const auto to_string{
      pybind11::module_::import("json").attr("dumps")(to).cast<std::string>()};
  const auto from_json = sourcemeta::core::parse_json(from_string);
  const auto to_json = sourcemeta::core::parse_json(to_string);

  const auto result{octue::cruzer::version(from_json, to_json)};
  pybind11::dict result_dict;

  if (result.version.has_value()) {
    switch (result.version.value()) {
      case octue::cruzer::SemVer::Major:
        result_dict["version"] = "major";
        break;
      case octue::cruzer::SemVer::Minor:
        result_dict["version"] = "minor";
        break;
      case octue::cruzer::SemVer::Patch:
        result_dict["version"] = "patch";
        break;
      case octue::cruzer::SemVer::Equal:
        result_dict["version"] = "equal";
        break;
    }
  } else {
    result_dict["version"] = pybind11::none();
  }

  pybind11::list traces_list;
  for (const auto &trace : result.traces) {
    pybind11::dict trace_dict;

    switch (trace.compatibility) {
      case octue::cruzer::Compatibility::Compatible:
        trace_dict["compatibility"] = "compatible";
        break;
      case octue::cruzer::Compatibility::Incompatible:
        trace_dict["compatibility"] = "incompatible";
        break;
      case octue::cruzer::Compatibility::Skip:
        trace_dict["compatibility"] = "skip";
        break;
      case octue::cruzer::Compatibility::Unknown:
        trace_dict["compatibility"] = "unknown";
        break;
    }

    if (trace.left.has_value()) {
      trace_dict["left"] = sourcemeta::core::to_string(trace.left.value());
    } else {
      trace_dict["left"] = pybind11::none();
    }

    if (trace.right.has_value()) {
      trace_dict["right"] = sourcemeta::core::to_string(trace.right.value());
    } else {
      trace_dict["right"] = pybind11::none();
    }

    traces_list.append(std::move(trace_dict));
  }

  result_dict["traces"] = std::move(traces_list);
  return result_dict;
}

static auto get_base_dialect(pybind11::object schema)
    -> std::optional<std::string> {
  const auto schema_string{pybind11::module_::import("json")
                               .attr("dumps")(schema)
                               .cast<std::string>()};
  const auto schema_json{sourcemeta::core::parse_json(schema_string)};
  const auto base_dialect{sourcemeta::core::base_dialect(
      schema_json, sourcemeta::core::schema_resolver)};
  if (base_dialect.has_value()) {
    return std::string{sourcemeta::core::to_string(base_dialect.value())};
  }
  return std::nullopt;
}

PYBIND11_MODULE(pycruzer, m) {
  m.def("get_base_dialect", &get_base_dialect,
        "Infer the base dialect from a JSON Schema");
  m.def("version", &version,
        "Compute the SemVer version bump from two schemas");
}
