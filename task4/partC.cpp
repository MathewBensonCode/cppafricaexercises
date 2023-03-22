#include <algorithm>
#include <array>
#include <cstdint>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <numeric>
#include <ranges>
#include <set>

namespace {
using die_t = std::array<std::uint8_t, 6>;

constexpr uint8_t max_die_sum{21};

const die_t die_range = {1, 2, 3, 4, 5, 6};

std::size_t compute_unique_dice() {

  std::set<die_t> unique_dies{};

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
                unique_dies.insert(current_die);
              }
            }
          }
        }
      }
    }
  }

  fmt::print("{}\n", fmt::join(unique_dies, "\n"));
  return unique_dies.size();
}

} // namespace

int main() {

  fmt::print("Total number of unique six-sided dice: {}\n",
             compute_unique_dice());
}
