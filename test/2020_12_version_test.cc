#include <gtest/gtest.h>
#include <octue/cruzer.h>

TEST(Cruzer_version_2020_12, add_id) {
  const auto from{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com",
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  const auto result{octue::cruzer::version(from, to)};
  EXPECT_TRUE(result.version.has_value());
  EXPECT_EQ(result.version.value(), octue::cruzer::SemVer::Patch);
  EXPECT_EQ(result.traces.size(), 0);
}
