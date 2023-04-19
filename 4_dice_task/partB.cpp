#include "partB.hpp"
#include <fmt/format.h>
#include <fmt/ranges.h>

int main() {

  constexpr PartB::die_t die_A{1, 2, 3, 4, 5, 6};

  constexpr PartB::die_t die_B{6, 5, 4, 3, 2, 1};

  fmt::print("the odds of winning with a die_A => {}\n against die_B => {}\n "
             "are {}%\n",
             die_A, die_B, PartB::odds(die_A, die_B));
}
