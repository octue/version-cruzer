#ifndef OCTUE_CRUZER_COMPARATOR_H_
#define OCTUE_CRUZER_COMPARATOR_H_

#include <cassert> // assert

#include "helpers.h"

namespace octue::cruzer {

static auto compare(
    // Left current subschema
    const sourcemeta::core::JSON &left_subschema,
    // Left keyword name
    const sourcemeta::core::JSON::String &left_keyword,
    // Left keyword vocabulary
    const std::optional<sourcemeta::core::JSON::String> &left_vocabulary,
    // Left keyword type
    const sourcemeta::core::SchemaKeywordType &left_type,
    // Left schema location
    const sourcemeta::core::Pointer &left_schema_location,
    // Left instance location
    const octue::cruzer::PointerTemplate &,

    // Right current subschema
    const sourcemeta::core::JSON &right_subschema,
    // Right keyword name
    const sourcemeta::core::JSON::String &right_keyword,
    // Right keyword vocabulary
    const std::optional<sourcemeta::core::JSON::String> &right_vocabulary,
    // Right keyword type
    const sourcemeta::core::SchemaKeywordType &right_type,
    // Right schema location
    const sourcemeta::core::Pointer &right_schema_location,
    // Right instance location
    const octue::cruzer::PointerTemplate &) -> Trace {

#define MAKE_RESULT(expected_compatibility)                                    \
  Trace{Compatibility::expected_compatibility, left_schema_location,           \
        right_schema_location};

#define MAKE_IF(expected_compatibility, expected_result)                       \
  if ((expected_result)) {                                                     \
    return MAKE_RESULT(expected_compatibility);                                \
  }

#define MAKE_IF_ELSE(expected_compatibility, expected_else_compatibility,      \
                     expected_result)                                          \
  if ((expected_result)) {                                                     \
    return MAKE_RESULT(expected_compatibility);                                \
  } else {                                                                     \
    return MAKE_RESULT(expected_else_compatibility);                           \
  }

#define MAKE_IF_ANY_ELSE(expected_compatibility, expected_else_compatibility,  \
                         expected_iterator, expected_item_name,                \
                         expected_result)                                      \
  for (const auto &expected_item_name : (expected_iterator)) {                 \
    MAKE_IF(expected_compatibility, (expected_result));                        \
  }                                                                            \
  return MAKE_RESULT(expected_else_compatibility);

  // Annotations / comments do not participate
  MAKE_IF(Skip, does_not_validate(left_type) || does_not_validate(right_type));

  // Handle boolean schemas on both sides
  MAKE_IF(Incompatible,
          left_subschema.is_boolean() && right_subschema.is_boolean() &&
              !left_subschema.to_boolean() && right_subschema.to_boolean());
  MAKE_IF(Compatible,
          left_subschema.is_boolean() && right_subschema.is_boolean());
  assert(!left_subschema.is_boolean() || !right_subschema.is_boolean());

  // The "true" schema is by definition compatible to everything
  MAKE_IF(Compatible,
          left_subschema.is_boolean() && left_subschema.to_boolean());

  // TODO: The "false" schema is compatible against impossible schemas. Though
  // we can probably do `Incompatible` for non-applicators?
  MAKE_IF(Unknown, left_subschema.is_boolean() && !left_subschema.to_boolean());

  // If things are equal, then they are compatible by definition
  MAKE_IF(Compatible,
          left_type == right_type && left_keyword == right_keyword &&
              left_vocabulary == right_vocabulary &&
              left_subschema.is_object() && right_subschema.is_object() &&
              left_subschema.at(left_keyword) ==
                  right_subschema.at(right_keyword));

  // If the keywords match totally different types, then we shouldn't be
  // comparing at all
  MAKE_IF(Skip,
          !have_common_types(left_vocabulary.value_or(""), left_keyword,
                             right_vocabulary.value_or(""), right_keyword));

#define COMPARISON_2020_12(expected_left_vocabulary, expected_left_name,       \
                           expected_right_vocabulary, expected_right_name)     \
  (left_vocabulary.has_value() &&                                              \
   left_vocabulary.value() == "https://json-schema.org/draft/2020-12/"         \
                              "vocab/" expected_left_vocabulary &&             \
   left_keyword == (expected_left_name) && right_vocabulary.has_value() &&     \
   right_vocabulary.value() == "https://json-schema.org/draft/2020-12/"        \
                               "vocab/" expected_right_vocabulary &&           \
   right_keyword == (expected_right_name))

#define BIDIRECTIONAL_2020_12(expected_vocabulary, expected_keyword_left,      \
                              expected_keyword_right, expected_result_left,    \
                              expected_result_right)                           \
  if (COMPARISON_2020_12(expected_vocabulary, expected_keyword_left,           \
                         expected_vocabulary, expected_keyword_right)) {       \
    MAKE_IF_ELSE(Compatible, Incompatible, (expected_result_left));            \
  } else if (COMPARISON_2020_12(expected_vocabulary, expected_keyword_right,   \
                                expected_vocabulary, expected_keyword_left)) { \
    MAKE_IF_ELSE(Compatible, Incompatible, (expected_result_right));           \
  }

#define BIDIRECTIONAL_TYPED_2020_12(expected_vocabulary, expected_left_name,   \
                                    expected_right_name,                       \
                                    expected_type_function, expected_operator) \
  BIDIRECTIONAL_2020_12(expected_vocabulary, expected_left_name,               \
                        expected_right_name,                                   \
                        left_value.expected_type_function() &&                 \
                            expected_operator(left_value, right_value),        \
                        !right_value.expected_type_function() ||               \
                            expected_operator(right_value, left_value));

#define BIDIRECTIONAL_TYPED_ANY_2020_12(                                       \
    expected_vocabulary, expected_left_name, expected_right_name,              \
    expected_iterator_function, expected_type_function, expected_operator)     \
  if (COMPARISON_2020_12(expected_vocabulary, expected_left_name,              \
                         expected_vocabulary, expected_right_name)) {          \
    MAKE_IF_ANY_ELSE(Incompatible, Compatible,                                 \
                     left_value.expected_iterator_function(), value,           \
                     value.expected_type_function() &&                         \
                         !expected_operator(value, right_value));              \
  } else if (COMPARISON_2020_12(expected_vocabulary, expected_right_name,      \
                                expected_vocabulary, expected_left_name)) {    \
    MAKE_IF_ANY_ELSE(Incompatible, Compatible,                                 \
                     right_value.expected_iterator_function(), value,          \
                     value.expected_type_function() &&                         \
                         !expected_operator(value, left_value));               \
  }

  const auto &left_value{left_subschema.is_object()
                             ? left_subschema.at(left_keyword)
                             : left_subschema};
  const auto &right_value{right_subschema.is_object()
                              ? right_subschema.at(right_keyword)
                              : right_subschema};

  if (is_applicator(left_type)) {
    if (right_type == sourcemeta::core::SchemaKeywordType::Assertion) {
      // Going from one or multiple constants into a schema is a tricky edge
      // case. Not that common in practice, and requires full schema evaluation
      // to confirm. Possible with Blaze, but might not be worth focusing on
      // right now
      MAKE_IF(Unknown, right_keyword == "const" || right_keyword == "enum");

      // Adding a type declaration to a type-less schema is by definition
      // incompatible
      if (right_vocabulary.has_value() &&
          right_vocabulary.value() == "https://json-schema.org/draft/2020-12/"
                                      "vocab/validation" &&
          right_keyword == "type" && !left_subschema.defines("type") &&
          !left_subschema.defines("allOf") && !left_subschema.defines("enum") &&
          !left_subschema.defines("const")) {
        if (left_subschema.is_boolean() && left_subschema.to_boolean()) {
          return MAKE_RESULT(Compatible);
        }

        return MAKE_RESULT(Incompatible);
      }

      // Other than the cases above, comparing applicators to assertions does
      // not make much sense
      return MAKE_RESULT(Skip);
    }

    if (COMPARISON_2020_12("applicator", "properties", "applicator",
                           "properties")) {
      for (const auto &property : left_value.as_object()) {
        if (!right_value.defines(property.first)) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("applicator", "patternProperties", "applicator",
                           "patternProperties")) {
      for (const auto &property : left_value.as_object()) {
        if (!right_value.defines(property.first)) {
          return MAKE_RESULT(Incompatible);
        }
      }

      return MAKE_RESULT(Compatible);
    }

    if (COMPARISON_2020_12("applicator", "patternProperties", "applicator",
                           "properties")) {
      return MAKE_RESULT(Unknown);
    }

    return MAKE_RESULT(Skip);

  } else if (left_type == sourcemeta::core::SchemaKeywordType::Assertion) {
    // Any assertion is less open than the "true" schema, by definition
    MAKE_IF(Incompatible,
            right_subschema.is_boolean() && right_subschema.to_boolean());
    // Any assertion is more open than the "false" schema, by definition
    MAKE_IF(Compatible,
            right_subschema.is_boolean() && !right_subschema.to_boolean());
    assert(right_subschema.is_object());

    if (is_applicator(right_type)) {
      // Going from a schema into one or multiple constants is a tricky edge
      // case. Not that common in practice, and requires full schema evaluation
      // to confirm. Possible with Blaze, but might not be worth focusing on
      // right now
      MAKE_IF(Unknown, left_keyword == "const" || left_keyword == "enum");

      // Adding a type declaration to a type-less schema is by definition
      // incompatible
      if (left_vocabulary.has_value() &&
          left_vocabulary.value() == "https://json-schema.org/draft/2020-12/"
                                     "vocab/validation" &&
          left_keyword == "type" && !right_subschema.defines("type") &&
          !right_subschema.defines("allOf") &&
          !right_subschema.defines("enum") &&
          !right_subschema.defines("const")) {
        return MAKE_RESULT(Incompatible);
      }

      // Other than the case above, comparing assertions to applicators does
      // not make much sense
      return MAKE_RESULT(Skip);
    }

    ///////////////////////////////////////////////////////////////////
    // Self-checks
    ///////////////////////////////////////////////////////////////////

    if (COMPARISON_2020_12("validation", "type", "validation", "type")) {
      MAKE_IF_ELSE(
          Compatible, Incompatible,
          is_superset(type_to_set(left_value), type_to_set(right_value)));
    }

    if (COMPARISON_2020_12("validation", "const", "validation", "const")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value == right_value);
    }

    if (COMPARISON_2020_12("validation", "enum", "validation", "enum")) {
      MAKE_IF_ELSE(
          Compatible, Incompatible,
          is_superset(array_to_set(left_value), array_to_set(right_value)));
    }

    if (COMPARISON_2020_12("validation", "required", "validation",
                           "required")) {
      MAKE_IF_ELSE(
          Compatible, Incompatible,
          is_superset(array_to_set(right_value), array_to_set(left_value)));
    }

    if (COMPARISON_2020_12("validation", "uniqueItems", "validation",
                           "uniqueItems")) {
      MAKE_IF_ELSE(Incompatible, Compatible,
                   left_value.is_boolean() && left_value.to_boolean() &&
                       right_value.is_boolean() && !right_value.to_boolean());
    }

    if (COMPARISON_2020_12("validation", "multipleOf", "validation",
                           "multipleOf")) {
      MAKE_IF_ELSE(Compatible, Incompatible,
                   right_value.divisible_by(left_value));
    }

    if (COMPARISON_2020_12("validation", "minLength", "validation",
                           "minLength")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value <= right_value);
    }

    if (COMPARISON_2020_12("validation", "maxLength", "validation",
                           "maxLength")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value >= right_value);
    }

    if (COMPARISON_2020_12("validation", "minItems", "validation",
                           "minItems")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value <= right_value);
    }

    if (COMPARISON_2020_12("validation", "maxItems", "validation",
                           "maxItems")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value >= right_value);
    }

    if (COMPARISON_2020_12("validation", "minProperties", "validation",
                           "minProperties")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value <= right_value);
    }

    if (COMPARISON_2020_12("validation", "maxProperties", "validation",
                           "maxProperties")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value >= right_value);
    }

    if (COMPARISON_2020_12("validation", "minimum", "validation", "minimum")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value <= right_value);
    }

    if (COMPARISON_2020_12("validation", "maximum", "validation", "maximum")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value >= right_value);
    }

    if (COMPARISON_2020_12("validation", "exclusiveMinimum", "validation",
                           "exclusiveMinimum")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value < right_value);
    }

    if (COMPARISON_2020_12("validation", "exclusiveMaximum", "validation",
                           "exclusiveMaximum")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value > right_value);
    }

    if (COMPARISON_2020_12("validation", "dependentRequired", "validation",
                           "dependentRequired")) {
      for (const auto &dependency : left_value.as_object()) {
        MAKE_IF(Incompatible, !right_value.defines(dependency.first));
        for (const auto &property : dependency.second.as_array()) {
          MAKE_IF(Incompatible,
                  !right_value.at(dependency.first).contains(property));
        }
      }

      return MAKE_RESULT(Compatible);
    }

    ///////////////////////////////////////////////////////////////////
    // Trivial checks
    ///////////////////////////////////////////////////////////////////

#define MARK_DEPENDENT_2020_12(expected_vocabulary, expected_name,             \
                               expected_dependency)                            \
  if (left_vocabulary.has_value() &&                                           \
      left_vocabulary.value() == "https://json-schema.org/draft/2020-12/"      \
                                 "vocab/" expected_vocabulary &&               \
      left_keyword == (expected_name) &&                                       \
      !left_subschema.defines(expected_dependency)) {                          \
    return MAKE_RESULT(Skip);                                                  \
  } else if (right_vocabulary.has_value() &&                                   \
             right_vocabulary.value() ==                                       \
                 "https://json-schema.org/draft/2020-12/"                      \
                 "vocab/" expected_vocabulary &&                               \
             right_keyword == (expected_name) &&                               \
             !right_subschema.defines(expected_dependency)) {                  \
    return MAKE_RESULT(Skip);                                                  \
  }

    MARK_DEPENDENT_2020_12("validation", "minContains", "contains");
    MARK_DEPENDENT_2020_12("validation", "maxContains", "contains");

#undef MARK_DEPENDENT_2020_12

    // Always compatible
    BIDIRECTIONAL_2020_12("validation", "uniqueItems", "minItems", true, true);
    BIDIRECTIONAL_2020_12("validation", "uniqueItems", "maxItems", true, true);
    BIDIRECTIONAL_2020_12("validation", "dependentRequired", "required", true,
                          true);
    BIDIRECTIONAL_2020_12("validation", "dependentRequired", "minProperties",
                          true, true);
    BIDIRECTIONAL_2020_12("validation", "multipleOf", "minimum", true, true);
    BIDIRECTIONAL_2020_12("validation", "multipleOf", "maximum", true, true);
    BIDIRECTIONAL_2020_12("validation", "multipleOf", "exclusiveMinimum", true,
                          true);
    BIDIRECTIONAL_2020_12("validation", "multipleOf", "exclusiveMaximum", true,
                          true);

    ///////////////////////////////////////////////////////////////////
    // Special checks
    ///////////////////////////////////////////////////////////////////

    if (COMPARISON_2020_12("validation", "const", "validation", "enum")) {
      MAKE_IF_ELSE(Compatible, Incompatible,
                   right_value.size() <= 1 &&
                       left_value == right_value.front());
    } else if (COMPARISON_2020_12("validation", "enum", "validation",
                                  "const")) {
      MAKE_IF_ELSE(Compatible, Incompatible, left_value.contains(right_value));
    }

    if (COMPARISON_2020_12("validation", "type", "validation", "const")) {
      MAKE_IF_ELSE(Compatible, Incompatible,
                   type_to_set(left_value).contains(right_value.type()));
    } else if (COMPARISON_2020_12("validation", "const", "validation",
                                  "type")) {
      MAKE_IF_ELSE(Incompatible,
                   // If the type matches the enumeration, there are cases where
                   // compatibility remains, like if the "type" subschema comes
                   // with other constraints that reduce the possible instances
                   // to a limited set, but that's hard to check right now.
                   Unknown,
                   !type_to_set(right_value).contains(left_value.type()));
    }

    if (COMPARISON_2020_12("validation", "type", "validation", "enum")) {
      const auto type_set{type_to_set(left_value)};
      MAKE_IF_ANY_ELSE(Incompatible, Compatible, right_value.as_array(), entry,
                       !type_set.contains(entry.type()));
    } else if (COMPARISON_2020_12("validation", "enum", "validation", "type")) {
      const auto type_set{type_to_set(right_value)};
      MAKE_IF_ANY_ELSE(Incompatible, Compatible, left_value.as_array(), entry,
                       !type_set.contains(entry.type()));
    }

    if (COMPARISON_2020_12("validation", "pattern", "validation", "type")) {
      MAKE_IF_ELSE(
          // For example, what if the regex allows everything?
          Unknown, Compatible,
          type_to_set(right_value)
              .contains(sourcemeta::core::JSON::Type::String));
    }

    if (COMPARISON_2020_12("validation", "uniqueItems", "validation", "type")) {
      MAKE_IF_ELSE(Compatible, Incompatible,
                   left_value.is_boolean() && !left_value.to_boolean());
    } else if (COMPARISON_2020_12("validation", "type", "validation",
                                  "uniqueItems")) {
      MAKE_IF(Compatible,
              right_value.is_boolean() && !right_value.to_boolean());
    }

    if (COMPARISON_2020_12("validation", "uniqueItems", "validation",
                           "const")) {
      MAKE_IF(Compatible, left_value.is_boolean() && !left_value.to_boolean());
    }

    if (COMPARISON_2020_12("validation", "uniqueItems", "validation", "enum")) {
      MAKE_IF(Compatible, left_value.is_boolean() && !left_value.to_boolean());
    }

    if (COMPARISON_2020_12("validation", "required", "validation",
                           "minProperties")) {
      MAKE_IF_ELSE(Compatible, Incompatible,
                   size_geq_integer(left_value, right_value));
    } else if (COMPARISON_2020_12("validation", "minProperties", "validation",
                                  "required")) {
      return MAKE_RESULT(Compatible);
    }

    BIDIRECTIONAL_2020_12("validation", "required", "maxProperties",
                          size_leq_integer(left_value, right_value),
                          size_leq_integer(right_value, left_value));

    if (COMPARISON_2020_12("validation", "maxProperties", "validation",
                           "dependentRequired")) {
      MAKE_IF_ANY_ELSE(Incompatible, Compatible, right_value.as_object(),
                       dependency,
                       static_cast<sourcemeta::core::JSON::Integer>(
                           dependency.second.size()) +
                               1 >
                           left_value.to_integer());
    } else if (COMPARISON_2020_12("validation", "dependentRequired",
                                  "validation", "maxProperties")) {
      MAKE_IF_ANY_ELSE(Incompatible, Compatible, left_value.as_object(),
                       dependency,
                       static_cast<sourcemeta::core::JSON::Integer>(
                           dependency.second.size()) +
                               1 >
                           right_value.to_integer());
    }

    // Adding a type declaration to a type-less schema is by definition
    // incompatible
    if (left_vocabulary.has_value() &&
        left_vocabulary.value() == "https://json-schema.org/draft/2020-12/"
                                   "vocab/validation" &&
        left_keyword == "type" && !right_subschema.defines("type") &&
        !right_subschema.defines("enum") && !right_subschema.defines("const")) {
      return MAKE_RESULT(Incompatible);
    }

    if (right_vocabulary.has_value() &&
        right_vocabulary.value() == "https://json-schema.org/draft/2020-12/"
                                    "vocab/validation" &&
        (right_keyword == "const" || right_keyword == "enum")) {
      if (!left_subschema.defines("type") && !left_subschema.defines("enum") &&
          !left_subschema.defines("enum")) {
        return MAKE_RESULT(Unknown);
      }
    }

#define COMPARE_2020_12_TYPE_VALIDATION(expected_keyword)                      \
  BIDIRECTIONAL_2020_12(                                                       \
      "validation", "type", expected_keyword,                                  \
      defines_any_relevant_type(type_to_set(left_value),                       \
                                "https://json-schema.org/draft/2020-12/"       \
                                "vocab/validation",                            \
                                expected_keyword),                             \
      !defines_any_relevant_type(type_to_set(right_value),                     \
                                 "https://json-schema.org/draft/2020-12/"      \
                                 "vocab/validation",                           \
                                 expected_keyword) ||                          \
          (right_subschema.defines(left_keyword) &&                            \
           right_subschema.at(left_keyword) == left_value));

    COMPARE_2020_12_TYPE_VALIDATION("required");
    COMPARE_2020_12_TYPE_VALIDATION("uniqueItems");
    COMPARE_2020_12_TYPE_VALIDATION("pattern");
    COMPARE_2020_12_TYPE_VALIDATION("minimum");
    COMPARE_2020_12_TYPE_VALIDATION("maximum");
    COMPARE_2020_12_TYPE_VALIDATION("exclusiveMinimum");
    COMPARE_2020_12_TYPE_VALIDATION("exclusiveMaximum");
    COMPARE_2020_12_TYPE_VALIDATION("minLength");
    COMPARE_2020_12_TYPE_VALIDATION("maxLength");
    COMPARE_2020_12_TYPE_VALIDATION("minItems");
    COMPARE_2020_12_TYPE_VALIDATION("maxItems");
    COMPARE_2020_12_TYPE_VALIDATION("minProperties");
    COMPARE_2020_12_TYPE_VALIDATION("maxProperties");
    COMPARE_2020_12_TYPE_VALIDATION("multipleOf");
    COMPARE_2020_12_TYPE_VALIDATION("dependentRequired");

#undef COMPARE_2020_12_TYPE_VALIDATION

    // `const`

    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "uniqueItems", is_array,
                                unique_items);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "pattern", is_string,
                                pattern);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "required", is_object,
                                defines_all_array);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "minimum", is_number,
                                geq);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "maximum", is_number,
                                leq);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "exclusiveMinimum",
                                is_number,
                                std::greater<sourcemeta::core::JSON>{});
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "exclusiveMaximum",
                                is_number, std::less<sourcemeta::core::JSON>{});
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "multipleOf", is_number,
                                divisible_by);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "minLength", is_string,
                                size_geq_integer);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "maxLength", is_string,
                                size_leq_integer);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "minItems", is_array,
                                size_geq_integer);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "maxItems", is_array,
                                size_leq_integer);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "minProperties",
                                is_object, size_geq_integer);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "maxProperties",
                                is_object, size_leq_integer);
    BIDIRECTIONAL_TYPED_2020_12("validation", "const", "dependentRequired",
                                is_object, dependent_required);

    // `enum`

    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "minimum", as_array,
                                    is_number, geq);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "maximum", as_array,
                                    is_number, leq);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "pattern", as_array,
                                    is_string, pattern);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "minLength", as_array,
                                    is_string, size_geq_integer);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "maxLength", as_array,
                                    is_string, size_leq_integer);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "minItems", as_array,
                                    is_array, size_geq_integer);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "maxItems", as_array,
                                    is_array, size_leq_integer);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "uniqueItems",
                                    as_array, is_array, unique_items);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "minProperties",
                                    as_array, is_object, size_geq_integer);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "maxProperties",
                                    as_array, is_object, size_leq_integer);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "dependentRequired",
                                    as_array, is_object, dependent_required);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "required", as_array,
                                    is_object, defines_all_array);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "multipleOf",
                                    as_array, is_number, divisible_by);
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "exclusiveMinimum",
                                    as_array, is_number, std::greater{});
    BIDIRECTIONAL_TYPED_ANY_2020_12("validation", "enum", "exclusiveMaximum",
                                    as_array, is_number, std::less{});

    // Bounds

    BIDIRECTIONAL_2020_12("validation", "minimum", "exclusiveMinimum",
                          left_value <= right_value, left_value < right_value);
    BIDIRECTIONAL_2020_12("validation", "maximum", "exclusiveMaximum",
                          left_value >= right_value, left_value > right_value);
    BIDIRECTIONAL_2020_12("validation", "exclusiveMinimum", "exclusiveMaximum",
                          left_value<right_value, left_value> right_value);
    BIDIRECTIONAL_2020_12("validation", "minimum", "maximum",
                          left_value <= right_value, left_value >= right_value);
    BIDIRECTIONAL_2020_12("validation", "minimum", "exclusiveMaximum",
                          left_value<right_value, left_value> right_value);
    BIDIRECTIONAL_2020_12("validation", "exclusiveMinimum", "maximum",
                          left_value<right_value, left_value> right_value);
    BIDIRECTIONAL_2020_12("validation", "minLength", "maxLength",
                          left_value <= right_value, left_value >= right_value);
    BIDIRECTIONAL_2020_12("validation", "minItems", "maxItems",
                          left_value <= right_value, left_value >= right_value);
    BIDIRECTIONAL_2020_12("validation", "minProperties", "maxProperties",
                          left_value <= right_value, left_value >= right_value);
    BIDIRECTIONAL_2020_12("validation", "minContains", "maxContains",
                          left_value <= right_value, left_value >= right_value);
  }

  return MAKE_RESULT(Unknown);

#undef MAKE_RESULT
#undef MAKE_IF
#undef MAKE_IF_ELSE
#undef MAKE_IF_ANY_ELSE
#undef COMPARISON_2020_12
#undef BIDIRECTIONAL_2020_12
#undef BIDIRECTIONAL_TYPED_2020_12
#undef BIDIRECTIONAL_TYPED_ANY_2020_12

} // namespace octue::cruzer

} // namespace octue::cruzer

#endif
