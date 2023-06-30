#include "functions.hpp"

namespace {
const auto inputstring =
    R"(This is a short story of the history of the White House
Construction began when the first cornerstone was laid in October of 1792. Although President Washington oversaw the construction of the house, he never lived in it. It was not until 1800, when the White House was nearly completed, that its first residents, President John Adams and his wife, Abigail, moved in.
)";

}

int main() {
  std::istringstream inputstream{inputstring};
  std::map<std::string, std::size_t, std::less<>> word_store{};

  std::string word;
  while (inputstream >> word) {
    const auto Capital_Word = Capitalize_Word(Remove_Punctuation(word));
    word_store.insert_or_assign(Capital_Word, Count_Word_Occurence(
        Capital_Word, word_store));
  }

  Print_Store(word_store);
}
