#include "partD.hpp"
#include <fmt/format.h>
#include <fmt/ranges.h>

int main() {
  using PartB::die_t;
  const die_t input = {4, 4, 4, 4, 3, 3};
  die_t output;
  if (PartD::find_better_die(input, output)) {
    fmt::print("b) The given die {} is beaten by the die {}.\n", input, output);
  } else
    fmt::print("b) There is no die that is better than {}.\n", input);
}
