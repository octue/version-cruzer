#include <gtest/gtest.h>
#include <octue/cruzer.h>

TEST(Cruzer_index, example_2020_12_1) {
  const auto schema{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com",
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "properties": {
      "foo": {
        "additionalProperties": {
          "type": "string"
        }
      },
      "bar": {
        "$ref": "#/properties/foo/additionalProperties"
      }
    }
  })JSON")};

  sourcemeta::core::SchemaFrame frame{
      sourcemeta::core::SchemaFrame::Mode::Instances};
  frame.analyse(schema, sourcemeta::core::schema_official_walker,
                sourcemeta::core::schema_official_resolver);

  const auto index{octue::index(frame, schema,
                                sourcemeta::core::schema_official_walker,
                                sourcemeta::core::schema_official_resolver)};

  EXPECT_EQ(index.size(), 4);

  EXPECT_TRUE(index.contains(""));
  EXPECT_TRUE(index.contains("/foo"));
  EXPECT_TRUE(index.contains("/foo/~?~/~P~"));
  EXPECT_TRUE(index.contains("/bar"));

  EXPECT_EQ(index.at("").size(), 1);
  EXPECT_EQ(sourcemeta::core::to_string(index.at("").at(0).pointer), "");
  EXPECT_EQ(index.at("").at(0).subschema.get(), schema);
  EXPECT_EQ(index.at("").at(0).dialect,
            "https://json-schema.org/draft/2020-12/schema");
  EXPECT_EQ(index.at("").at(0).base_dialect,
            "https://json-schema.org/draft/2020-12/schema");

  EXPECT_EQ(index.at("/foo").size(), 1);
  EXPECT_EQ(sourcemeta::core::to_string(index.at("/foo").at(0).pointer),
            "/properties/foo");
  EXPECT_EQ(index.at("/foo").at(0).subschema.get(),
            schema.at("properties").at("foo"));
  EXPECT_EQ(index.at("/foo").at(0).dialect,
            "https://json-schema.org/draft/2020-12/schema");
  EXPECT_EQ(index.at("/foo").at(0).base_dialect,
            "https://json-schema.org/draft/2020-12/schema");

  EXPECT_EQ(index.at("/foo/~?~/~P~").size(), 1);
  EXPECT_EQ(sourcemeta::core::to_string(index.at("/foo/~?~/~P~").at(0).pointer),
            "/properties/foo/additionalProperties");
  EXPECT_EQ(index.at("/foo/~?~/~P~").at(0).subschema.get(),
            schema.at("properties").at("foo").at("additionalProperties"));
  EXPECT_EQ(index.at("/foo/~?~/~P~").at(0).dialect,
            "https://json-schema.org/draft/2020-12/schema");
  EXPECT_EQ(index.at("/foo/~?~/~P~").at(0).base_dialect,
            "https://json-schema.org/draft/2020-12/schema");

  EXPECT_EQ(index.at("/bar").size(), 2);

  EXPECT_EQ(sourcemeta::core::to_string(index.at("/bar").at(0).pointer),
            "/properties/bar");
  EXPECT_EQ(index.at("/bar").at(0).subschema.get(),
            schema.at("properties").at("bar"));
  EXPECT_EQ(index.at("/bar").at(0).dialect,
            "https://json-schema.org/draft/2020-12/schema");
  EXPECT_EQ(index.at("/bar").at(0).base_dialect,
            "https://json-schema.org/draft/2020-12/schema");

  EXPECT_EQ(sourcemeta::core::to_string(index.at("/bar").at(1).pointer),
            "/properties/foo/additionalProperties");
  EXPECT_EQ(index.at("/bar").at(1).subschema.get(),
            schema.at("properties").at("foo").at("additionalProperties"));
  EXPECT_EQ(index.at("/bar").at(1).dialect,
            "https://json-schema.org/draft/2020-12/schema");
  EXPECT_EQ(index.at("/bar").at(1).base_dialect,
            "https://json-schema.org/draft/2020-12/schema");
}
