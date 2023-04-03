#include <algorithm>
#include <array>
#include <cstdint>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <map>
#include <numeric>
#include <ranges>
#include <set>

namespace {
using die_t = std::array<std::uint8_t, 6>;

constexpr uint8_t max_die_sum{21};

const die_t die_range = {1, 2, 3, 4, 5, 6};

constexpr auto total_games = die_range.size() * die_range.size();

uint8_t count_digits(const die_t &die) {
  std::array<uint8_t, 7> die_counter{};
  for (const auto num : die) {
    die_counter.at(num)++;
  }

  std::set<uint8_t> found_nums{};
  for (uint8_t index{1}; index < die_counter.size(); ++index) {
    if (die_counter.at(index) >= 2) {
      found_nums.insert(index);
    }
  }
  return static_cast<uint8_t>(found_nums.size());
}

bool is_duplicate(const die_t &current_die, const auto current_digits,
                  const auto &die_set) {
  for (const auto &[unique_die, char_count] : die_set) {
    if (current_digits == char_count) {
      auto reference_die = unique_die;
      for (std::size_t index{}; index < current_die.size(); ++index) {
        if (std::ranges::equal(current_die, reference_die)) {
          return true;
        }
        std::rotate(std::begin(reference_die),
                    std::next(std::begin(reference_die)),
                    std::end(reference_die));
      }
    }
  }

  return false;
}

auto compute_unique_dice() {

  std::map<die_t, uint8_t> unique_dies{};

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
                const auto digit_count = count_digits(current_die);
                if (!is_duplicate(current_die, digit_count, unique_dies)) {
                  unique_dies.insert({current_die, digit_count});
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

constexpr std::size_t odds(const die_t &a, const die_t &b) {
  auto win_counter{0};
  for (const auto a_move : a) {
    win_counter += std::ranges::count_if(
        b, [a_move](const auto b_move) { return (a_move > b_move); });
  }
  return static_cast<const std::size_t>(
      (static_cast<double>(win_counter) / static_cast<double>(total_games)) *
      100.0);
}

bool find_better_die(const die_t &input, die_t &output) {
  auto unique_dice = compute_unique_dice();

  for (const auto &[unique_die, count] : unique_dice) {
    auto input_odds = odds(unique_die, input);
    if (input_odds > 50) {
      output = unique_die;
      return true;
    }
  }
  return false;
}

} // namespace

int main() {
  const die_t input = {4,4,4,4,3,3};
  die_t output;
  if (find_better_die(input, output)) {
    fmt::print("b) The given die {} is beaten by the die {}.\n", input, output);
  } else
    fmt::print("b) There is no die that is better than {}.\n", input);
  return EXIT_SUCCESS;
}
