#include <iostream>
#include <locale>
#include <map>
#include <sstream>
#include <utility>

auto Capitalize_Word(const std::string &word) {
  auto capital_word{word};
  for (auto &letter : capital_word){
    letter = std::toupper(letter, std::locale{});
  }
  return capital_word;
}

auto Remove_Punctuation(const std::string &word) {
  auto word_without_punctuation = word;
  if ( const auto last_char = word.back();
          last_char == ',' || last_char == '.') {
    word_without_punctuation.pop_back();
  }
  return word_without_punctuation;
}

auto Count_Word_Occurence(const auto &word, const auto &store) {
  std::size_t result{};
  if (store.contains(word)) {
    result = store.at(word);
  }

  return ++result;
}

void Print_Store(const auto &store) {
  std::cout << "Word --> Times Found :\n\n =================\n\n";
  for (const auto &[word, word_count] : store) {
    std::cout << word << " --> " << word_count << '\n';
  }
}

