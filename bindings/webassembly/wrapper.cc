#include <octue/cruzer.h>

// See
// https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html
#include <emscripten/bind.h>
#include <emscripten/val.h>

static auto version(const std::string &from, const std::string &to)
    -> emscripten::val {
  const auto from_json{sourcemeta::core::parse_json(from)};
  const auto to_json{sourcemeta::core::parse_json(to)};
  const auto result{octue::cruzer::version(from_json, to_json)};
  emscripten::val result_json = emscripten::val::object();

  if (result.version.has_value()) {
    switch (result.version.value()) {
      case octue::cruzer::SemVer::Major:
        result_json.set("version", "major");
        break;
      case octue::cruzer::SemVer::Minor:
        result_json.set("version", "minor");
        break;
      case octue::cruzer::SemVer::Patch:
        result_json.set("version", "patch");
        break;
      case octue::cruzer::SemVer::Equal:
        result_json.set("version", "equal");
        break;
    }
  } else {
    result_json.set("version", emscripten::val::null());
  }

  emscripten::val traces_json = emscripten::val::array();
  for (const auto &trace : result.traces) {
    emscripten::val trace_json = emscripten::val::object();

    switch (trace.compatibility) {
      case octue::cruzer::Compatibility::Compatible:
        trace_json.set("compatibility", "compatible");
        break;
      case octue::cruzer::Compatibility::Incompatible:
        trace_json.set("compatibility", "incompatible");
        break;
      case octue::cruzer::Compatibility::Skip:
        trace_json.set("compatibility", "skip");
        break;
      case octue::cruzer::Compatibility::Unknown:
        trace_json.set("compatibility", "unknown");
        break;
    }

    if (trace.left.has_value()) {
      trace_json.set("left", sourcemeta::core::to_string(trace.left.value()));
    } else {
      trace_json.set("left", emscripten::val::null());
    }

    if (trace.right.has_value()) {
      trace_json.set("right", sourcemeta::core::to_string(trace.right.value()));
    } else {
      trace_json.set("right", emscripten::val::null());
    }

    traces_json.call<void>("push", std::move(trace_json));
  }

  result_json.set("traces", std::move(traces_json));
  return result_json;
}

static auto get_base_dialect(const std::string &schema) -> emscripten::val {
  const auto schema_json{sourcemeta::core::parse_json(schema)};
  const auto base_dialect{sourcemeta::core::base_dialect(
      schema_json, sourcemeta::core::schema_official_resolver)};
  if (base_dialect.has_value()) {
    return emscripten::val(base_dialect.value());
  } else {
    return emscripten::val::null();
  }
}

EMSCRIPTEN_BINDINGS(cruzer) {
  emscripten::function("version", &version);
  emscripten::function("getBaseDialect", &get_base_dialect);
}
