#ifndef PARTC
#define PARTC

#include "partB.hpp"
#include <array>
#include <cstdint>
#include <set>

namespace PartC {

using PartB::die_t;

std::set<die_t> compute_unique_dice();

} // namespace PartC

#endif
