#include <algorithm>
#include <array>
#include <coroutine>
#include <cppcoro/generator.hpp>
#include <cstdlib>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <unordered_set>

template <typename T, std::size_t Sides> using die_t = std::array<T, Sides>;

template <typename T> struct sides_t;

template <typename T, std::size_t Sides> struct sides_t<std::array<T, Sides>> {
  static constexpr std::size_t value = Sides;
};

template <typename T> constexpr std::size_t sides_v = sides_t<T>::value;

template <typename T, std::size_t Sides>
std::uint8_t odds(const die_t<T, Sides> &a, const die_t<T, Sides> &b) {
  const auto total_games = Sides * Sides;
  auto win_counter{0};
  for (const auto a_move : a) {
    win_counter += std::ranges::count_if(
        b, [a_move](const auto b_move) { return (a_move > b_move); });
  }
  return static_cast<const std::uint8_t>(win_counter * 100 / total_games);
}

/// Generates all possible unique dice variations with given total sum. All dice
/// values are sorted by default.
template <typename Dice>
cppcoro::generator<std::pair<Dice, std::size_t>>
dice_generator(std::size_t sum) {
  Dice die;
  std::size_t index = 0;

  auto remaining_sum = sum;
  for (die[5] = (remaining_sum + 5) / 6; die[5] <= sides_v<Dice>; ++die[5]) {
    remaining_sum -= die[5];
    for (die[4] = (remaining_sum + 4) / 5; die[4] <= die[5]; ++die[4]) {
      remaining_sum -= die[4];
      for (die[3] = (remaining_sum + 3) / 4; die[3] <= die[4]; ++die[3]) {
        remaining_sum -= die[3];
        for (die[2] = (remaining_sum + 2) / 3;
             die[2] <= std::min<std::size_t>(die[3], remaining_sum - 2);
             ++die[2]) {
          remaining_sum -= die[2];
          for (die[1] = (remaining_sum + 1) / 2;
               die[1] <= std::min<std::size_t>(die[2], remaining_sum - 1);
               ++die[1]) {
            die[0] = remaining_sum - die[1];
            co_yield {die, index++};
          }
          remaining_sum += die[2];
        }
        remaining_sum += die[3];
      }
      remaining_sum += die[4];
    }
    remaining_sum += die[5];
  }
}

/// A simple set of three indices.
/// @remarks
///   Using strong type to avoid breaking other stuff.
struct solution_indices {
  constexpr solution_indices() = default;

  constexpr solution_indices(std::size_t a, std::size_t b, std::size_t c)
      : values(a, b, c) {}

  constexpr solution_indices(const solution_indices &) = default;
  constexpr solution_indices(solution_indices &&) = default;
  constexpr solution_indices &operator=(const solution_indices &) = default;
  constexpr solution_indices &operator=(solution_indices &&) = default;

  using values_type = std::tuple<std::size_t, std::size_t, std::size_t>;
  values_type values;
};

template <std::size_t Index>
constexpr auto &get(const solution_indices &indices) {
  return std::get<Index>(indices.values);
}

/// Compared one set of indices with another potentially rotated one.
template <> struct std::equal_to<solution_indices> {
  constexpr bool operator()(const solution_indices &lhs,
                            const solution_indices &rhs) const {
    using std::get;

    return (get<0>(lhs) == get<0>(rhs) && get<1>(lhs) == get<1>(rhs) &&
            get<2>(lhs) == get<2>(rhs)) ||
           (get<0>(lhs) == get<1>(rhs) && get<1>(lhs) == get<2>(rhs) &&
            get<2>(lhs) == get<0>(rhs)) ||
           (get<0>(lhs) == get<2>(rhs) && get<1>(lhs) == get<0>(rhs) &&
            get<2>(lhs) == get<1>(rhs));
  }
};

template <typename T, typename... Rest>
void hash_combine(std::size_t &seed, const T &value, const Rest &...rest) {
  seed ^= std::hash<T>{}(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  (hash_combine(seed, rest), ...);
}

/// Builds a stable hash for rotated indices.
template <> struct std::hash<solution_indices> {
  std::size_t operator()(const solution_indices &indices) const noexcept {
    using std::get;

    std::size_t hash_a = 0;
    std::size_t hash_b = 0;
    std::size_t hash_c = 0;
    hash_combine(hash_a, get<0>(indices), get<1>(indices), get<2>(indices));
    hash_combine(hash_b, get<1>(indices), get<2>(indices), get<0>(indices));
    hash_combine(hash_c, get<2>(indices), get<0>(indices), get<1>(indices));
    return hash_a ^ hash_b ^ hash_c;
  }
};

using standard_die_t = die_t<std::size_t, 6>;

int main(int /*argc*/, const char * /*argv*/[]) {
  std::unordered_set<solution_indices> solutions;
  for (auto [die_a, index_a] : dice_generator<standard_die_t>(21)) {
    for (auto [die_b, index_b] : dice_generator<standard_die_t>(21)) {
      for (auto [die_c, index_c] : dice_generator<standard_die_t>(21)) {
        if (!solutions.contains({index_a, index_b, index_c})) {
          if (auto odds_b_a = odds(die_b, die_a); odds_b_a > 50) {
            if (auto odds_c_b = odds(die_c, die_b); odds_c_b > 50) {
              if (auto odds_a_c = odds(die_a, die_c); odds_a_c > 50) {
                solutions.emplace(index_a, index_b, index_c);
                fmt::print("A:{} B:{} C:{}  BvsA:{} CvsB:{} AvsC:{}\n", die_a,
                           die_b, die_c, odds_b_a, odds_c_b, odds_a_c);
              }
            }
          }
        }
      }
    }
  }

  return EXIT_SUCCESS;
}
