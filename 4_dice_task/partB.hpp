#ifndef PARTB_H
#define PARTB_H

#include <array>
#include <cstdint>

namespace PartB {

using die_t = std::array<std::uint8_t, 6>;

constexpr std::uint8_t sum_of_dies{21};

std::size_t sum_die(const die_t) noexcept;
std::size_t odds(const die_t &, const die_t &);

} // namespace PartB

#endif
