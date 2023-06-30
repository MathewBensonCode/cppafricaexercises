#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <unordered_map>

using namespace std::literals;

namespace {

auto Remove_Punctuation = [](const auto &input_word) {
  std::string word_without_punctuation{};
  std::ranges::copy_if(
      input_word, std::back_inserter(word_without_punctuation),
      [](const auto character) { return !std::ispunct(character); });

  return word_without_punctuation;
};

auto Capitalize_Word = [](const auto &word) {
  std::string capital_word{};
  std::ranges::transform(
      word, std::back_inserter(capital_word),
      [](const auto letter) { return std::toupper(letter); });
  return capital_word;
};

void Print_Store(const auto &store) {
  std::cout << "Word --> Times Found :\n\n =================\n\n";
  for (const auto &[word, word_count] : store) {
    std::cout << word << " --> " << word_count << '\n';
  }
}

constexpr auto line_delimiter{"\n"sv};
constexpr auto word_delimiter{" "sv};

auto get_words = std::views::split(word_delimiter) |
                 std::views::transform(Remove_Punctuation) |
                 std::views::transform(Capitalize_Word);

auto get_lines = std::views::split(line_delimiter);
} // namespace

int main() {
  constexpr auto inputdata =
      R"(This is a short story of the history of the White House
Construction began when the first cornerstone was laid in October of 1792. Although President Washington oversaw the construction of the house, he never lived in it. It was not until 1800, when the White House was nearly completed, that its first residents, President John Adams and his wife, Abigail, moved in.
)"sv;

  std::unordered_map<std::string, std::size_t> word_store{};

  for (const auto &line : inputdata | get_lines) {
    for (const auto word : line | get_words) {
      word_store[word]++;
    }
  }

  Print_Store(word_store);
}
