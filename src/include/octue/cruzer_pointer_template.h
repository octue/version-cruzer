#ifndef OCTUE_CRUZER_POINTER_TEMPLATE_H_
#define OCTUE_CRUZER_POINTER_TEMPLATE_H_

#include <sourcemeta/core/json.h>
#include <sourcemeta/core/jsonpointer.h>

#include <cassert>          // assert
#include <initializer_list> // std::initializer_list
#include <optional>         // std::optional, std::nullopt
#include <ostream>          // std::basic_ostream
#include <utility>          // std::forward, std::move
#include <variant>          // std::variant, std::holds_alternative, std::get
#include <vector>           // std::vector

namespace octue::cruzer {

class PointerTemplate {
public:
  enum class Wildcard { Property, Item, Key };
  struct Condition {
    auto operator==(const Condition &) const noexcept -> bool = default;
    std::optional<sourcemeta::core::JSON::String> suffix = std::nullopt;
  };
  struct Negation {
    auto operator==(const Negation &) const noexcept -> bool = default;
  };
  using Regex = sourcemeta::core::JSON::String;
  using Token = sourcemeta::core::Pointer::Token;
  using Container =
      std::vector<std::variant<Wildcard, Condition, Negation, Regex, Token>>;

  PointerTemplate() : data{} {}
  PointerTemplate(std::initializer_list<typename Container::value_type> tokens)
      : data{std::move(tokens)} {}

  using value_type = typename Container::value_type;
  using size_type = typename Container::size_type;
  using iterator = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;

  auto begin() noexcept -> iterator { return this->data.begin(); }
  auto end() noexcept -> iterator { return this->data.end(); }
  auto begin() const noexcept -> const_iterator { return this->data.begin(); }
  auto end() const noexcept -> const_iterator { return this->data.end(); }
  auto cbegin() const noexcept -> const_iterator { return this->data.cbegin(); }
  auto cend() const noexcept -> const_iterator { return this->data.cend(); }

  template <class... Args> auto emplace_back(Args &&...args) -> void {
    this->data.emplace_back(std::forward<Args>(args)...);
  }

  auto pop_back() -> void {
    assert(!this->empty());
    this->data.pop_back();
  }

  [[nodiscard]] auto empty() const noexcept -> bool {
    return this->data.empty();
  }

  auto operator==(const PointerTemplate &other) const noexcept -> bool {
    return this->data == other.data;
  }

private:
  Container data;
};

inline auto
stringify(const PointerTemplate &pointer,
          std::basic_ostream<sourcemeta::core::JSON::Char,
                             sourcemeta::core::JSON::CharTraits> &stream)
    -> void {
  for (const auto &token : pointer) {
    if (std::holds_alternative<PointerTemplate::Wildcard>(token)) {
      stream.put('/');
      stream.put('~');
      switch (std::get<PointerTemplate::Wildcard>(token)) {
        case PointerTemplate::Wildcard::Property:
          stream.put('P');
          break;
        case PointerTemplate::Wildcard::Item:
          stream.put('I');
          break;
        case PointerTemplate::Wildcard::Key:
          stream.put('K');
          break;
        default:
          assert(false);
          break;
      }
      stream.put('~');
    } else if (std::holds_alternative<PointerTemplate::Regex>(token)) {
      stream.put('/');
      stream.put('~');
      stream.put('R');
      const auto &value{std::get<PointerTemplate::Regex>(token)};
      stream.write(value.c_str(), static_cast<std::streamsize>(value.size()));
      stream.put('~');
    } else if (std::holds_alternative<PointerTemplate::Condition>(token)) {
      stream.put('/');
      stream.put('~');
      stream.put('?');
      const auto &value{std::get<PointerTemplate::Condition>(token)};
      if (value.suffix.has_value()) {
        stream.write(value.suffix->c_str(),
                     static_cast<std::streamsize>(value.suffix->size()));
      }
      stream.put('~');
    } else if (std::holds_alternative<PointerTemplate::Negation>(token)) {
      stream.put('/');
      stream.put('~');
      stream.put('!');
      stream.put('~');
    } else {
      const sourcemeta::core::Pointer single{
          std::get<PointerTemplate::Token>(token)};
      sourcemeta::core::stringify(single, stream);
    }
  }
}

} // namespace octue::cruzer

#endif
