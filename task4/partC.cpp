#include <algorithm>
#include <array>
#include <cstdint>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

namespace {
using die_t = std::array<std::uint8_t, 6>;

constexpr uint8_t max_die_sum{21};

struct die_digit_count{
    die_t die;
    uint8_t char_count{};
};

const die_t die_range = {1, 2, 3, 4, 5, 6};

uint8_t count_digits(const die_t &die){
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

bool is_duplicate(const die_t &current_die, const auto current_digits, const auto &die_set) {

    for(const auto die_in_set : die_set){
        if(current_digits == die_in_set.char_count){
            auto reference_die = die_in_set.die;
            for(std::size_t index{}; index<current_die.size(); ++index){
                if(std::ranges::equal(current_die, reference_die)){
                        fmt::print("\tREMOVED DUPLICATE {} of {}\n", current_die, die_in_set.die);
                        return true;
                        }
                std::rotate(std::begin(reference_die), std::next(std::begin(reference_die)), std::end(reference_die));
            }
        }
    }
  
  fmt::print("{}\n", current_die);
  return false;
}

std::size_t compute_unique_dice() {

  std::vector<die_digit_count> unique_dies{};

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
                  unique_dies.push_back({current_die, digit_count});
                }
              }
            }
          }
        }
      }
    }
  }

  return unique_dies.size();
}

} // namespace

int main() {

  fmt::print("Total number of unique six-sided dice: {}\n",
             compute_unique_dice());
}
