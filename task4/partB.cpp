#include <algorithm>
#include <array>
#include <cstdint>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <numeric>

namespace {
using die_t = std::array<std::uint8_t, 6>;

constexpr std::uint8_t sum_of_dies{21};

constexpr std::size_t sum_die(const die_t &die) noexcept {
  return std::reduce(die.begin(), die.end(), std::size_t{});
}

constexpr std::size_t odds(const die_t &a, const die_t &b) {
  const auto total_games = a.size() * b.size();
  auto win_counter{0};
  for (const auto a_move : a) {
    win_counter += std::ranges::count_if(
        b, [a_move](const auto b_move) { return (a_move > b_move); });
  }
  return static_cast<const std::size_t>(
      (static_cast<double>(win_counter) / static_cast<double>(total_games)) * 100.0);
}

} // namespace
int main() {
  constexpr die_t die_A{1, 2, 3, 4, 5, 6};

  constexpr die_t die_B{6, 5, 4, 3, 2, 1};

  static_assert(sum_die(die_A) == sum_of_dies);
  static_assert(sum_die(die_B) == sum_of_dies);
  static_assert(odds(die_A, die_B) == 41);

  fmt::print("the odds of winning with a die_A => {}\n against die_B => {}\n are {}%\n", die_A,
             die_B, odds(die_A, die_B));
}
