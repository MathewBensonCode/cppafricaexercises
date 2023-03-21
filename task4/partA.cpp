#include <array>
#include <cstdint>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <numeric>

namespace {
using die_t = std::array<std::uint8_t, 6>;

void print_die(const die_t &dice) { fmt::print("{}", dice); }

} // namespace

int main() {
  print_die({1, 2, 3, 4, 5, 6});

}
