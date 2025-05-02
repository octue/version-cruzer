#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

TEST(Cruzer_version_draft7, const_to_enum_superset) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "const": "foo"
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_UNKNOWN(result, from, to, 1);
  EXPECT_TRACE(result, 0, Unknown, "/const", "/enum");
}
