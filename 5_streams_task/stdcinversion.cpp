#include "algofunctions.hpp"
#include <map>

int main() {
  std::map<std::string, std::size_t> word_store{};

  std::string word;
  while (std::cin >> word) {
    const auto Capital_Word = Capitalize_Word(Remove_Punctuation(word));
    word_store[Capital_Word]++;
  }

  Print_Store(word_store);
}
