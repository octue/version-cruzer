#include <gtest/gtest.h>
#include <octue/cruzer.h>

#include "macros.h"

TEST(Cruzer_is_compatible_with_2020_12, boolean_true_true) {
  const sourcemeta::core::JSON left{true};
  const sourcemeta::core::JSON right{true};

  const auto result{octue::is_compatible_with(
      left, right,

      // We need to manually specify dialects for boolean schemas
      "https://json-schema.org/draft/2020-12/schema",
      "https://json-schema.org/draft/2020-12/schema")};

  EXPECT_EQ(result.size(), 1);
  EXPECT_COMPATIBILITY(result, 0, Unknown, "", "");
}
