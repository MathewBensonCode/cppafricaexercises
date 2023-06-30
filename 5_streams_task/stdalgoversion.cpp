#include "algofunctions.hpp"
#include <map>

int main() {

  const auto inputstring =
      R"(This is a short story of the history of the White House
Construction began when the first cornerstone was laid in October of 1792. Although President Washington oversaw the construction of the house, he never lived in it. It was not until 1800, when the White House was nearly completed, that its first residents, President John Adams and his wife, Abigail, moved in.
)";

  std::istringstream inputstream{inputstring};
  std::string input_word{};
  std::map<std::string, std::size_t> word_store{};

  while (inputstream >> input_word) {

    word_store[Capitalize_Word(Remove_Punctuation(input_word))]++;
  }

  Print_Store(word_store);

}
