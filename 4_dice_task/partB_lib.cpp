#include "partB.hpp"
#include <algorithm>
#include <cstdint>
#include <numeric>

namespace PartB {

std::size_t sum_die(const die_t &die) noexcept {
  return std::reduce(die.begin(), die.end(), std::size_t{});
}

std::size_t odds(const die_t &a, const die_t &b) {
  const std::size_t total_games = a.size() * b.size();
  std::size_t win_counter{};
  for (const auto a_move : a) {
    win_counter += static_cast<std::size_t>(std::ranges::count_if(
        b, [a_move](const auto b_move) { return (a_move > b_move); }));
  }
  return ((win_counter * 100) / total_games);
}

} // namespace PartB
