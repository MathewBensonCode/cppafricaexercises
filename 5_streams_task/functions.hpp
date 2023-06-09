#include <iostream>
#include <locale>
#include <map>
#include <sstream>
#include <utility>

auto Capitalize_Word(const std::string &word) {
  auto capital_word{word};
  for (std::size_t index{}; index < capital_word.length(); ++index) {
    const auto letter = capital_word.at(index);
    const auto upperletter = std::toupper(letter, std::locale{});
    capital_word.at(index) = upperletter;
  }
  return capital_word;
}

auto Remove_Punctuation(const std::string &word) {
  auto word_without_punctuation = word;
  const auto last_char = word.back();
  if (last_char == ',' || last_char == '.') {
    word_without_punctuation.pop_back();
  }
  return word_without_punctuation;
}

auto Count_Word_Occurence(const auto &word, const auto &store) {
  std::size_t result{};
  if (store.contains(word)) {
    std::size_t current_value = store.at(word);
    result = current_value;
  }

  return ++result;
}

void Print_Store(const auto &store) {
  std::cout << "Word --> Times Found :\n\n =================\n\n";
  for (const auto &[word, word_count] : store) {
    std::cout << word << " --> " << word_count << '\n';
  }
}

