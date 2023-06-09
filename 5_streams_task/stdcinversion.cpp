#include "functions.hpp"

int main() {
  std::map<std::string, std::size_t> word_store{};

  std::string word;
  while (std::cin >> word) {
    const auto Capital_Word = Capitalize_Word(Remove_Punctuation(word));
    word_store.insert_or_assign(Capital_Word, Count_Word_Occurence(Capital_Word, word_store));
  }

  Print_Store(word_store);
}
