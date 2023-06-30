#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

auto Remove_Punctuation(const std::string &input_word) {
  std::ostringstream without_punctuation_stream{};
  std::ranges::copy_if(
      input_word, std::ostream_iterator<char>(without_punctuation_stream),
      [](const auto character) { return !std::ispunct(character); });

  return without_punctuation_stream.str();
}

auto Capitalize_Word(const std::string &word) {
  std::ostringstream capital_stream{};
  std::ranges::transform(
      word, std::ostream_iterator<char>(capital_stream),
      [](const auto letter) { return std::toupper(letter); });

  return capital_stream.str();
}

void Print_Store(const auto &store) {
  std::cout << "Word --> Times Found :\n\n =================\n\n";
  for (const auto &[word, word_count] : store) {
    std::cout << word << " --> " << word_count << '\n';
  }
}
