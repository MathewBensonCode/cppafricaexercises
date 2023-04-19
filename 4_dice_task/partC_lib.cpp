#include <algorithm>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <map>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

#include "partC.hpp"

namespace PartC {

constexpr uint8_t max_die_sum{21};

const die_t die_range = {1, 2, 3, 4, 5, 6};

bool is_duplicate(const die_t &current_die, const auto &die_set) {
  auto temp_current_die = current_die;
  std::ranges::sort(temp_current_die);

  for (const auto &unique_die : die_set) {
    auto reference_die = unique_die;
    std::ranges::sort(reference_die);
    if (std::ranges::equal(temp_current_die, reference_die)) {
      return true;
    }
  }

  return false;
}

std::set<die_t> compute_unique_dice() {

  std::set<die_t> unique_dies;

  for (const uint8_t first : die_range) {
    for (const uint8_t second : die_range) {
      for (const uint8_t third : die_range) {
        for (const uint8_t fourth : die_range) {
          for (const uint8_t fifth : die_range) {
            for (const uint8_t sixth : die_range) {
              const die_t current_die{first,  second, third,
                                      fourth, fifth,  sixth};
              if (max_die_sum == std::accumulate(current_die.begin(),
                                                 current_die.end(),
                                                 std::uint8_t{})) {
                if (!is_duplicate(current_die, unique_dies)) {
                  unique_dies.insert(current_die);
                }
              }
            }
          }
        }
      }
    }
  }

  return unique_dies;
}
} // namespace PartC
