#include "partC.hpp"

#include <fmt/format.h>
#include <fmt/ranges.h>

int main() {

  const auto unique_dice = PartC::compute_unique_dice();

  fmt::print("Unique Dice \n{}\n", fmt::join(unique_dice, "\n"));

  fmt::print("Total number of unique six-sided dice: {}\n",
             unique_dice.size());
}
