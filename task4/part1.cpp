#include <array>
#include <cstdint>
#include <fmt/format.h>
#include <fmt/ranges.h>

namespace {
using die_t = std::array<std::uint8_t, 6>;

void print_die(const die_t &dice) { fmt::print("{}", dice); }

std::uint8_t odds(const die_t &a, const die_t &b){

}

} // namespace
int main() {
  die_t standard_die{1, 2, 3, 4, 5, 6};
  print_die(standard_die);
}
