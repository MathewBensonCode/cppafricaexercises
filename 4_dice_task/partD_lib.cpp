#include "partC.hpp"
#include "partD.hpp"

namespace PartD {

bool find_better_die(const die_t &input, die_t &output) {
  const auto unique_dice = PartC::compute_unique_dice();

  for (const auto &unique_die : unique_dice) {
    const auto input_odds = PartB::odds(unique_die, input);
    if (input_odds > 50) {
      output = unique_die;
      return true;
    }
  }
  return false;
}

} // namespace PartD
