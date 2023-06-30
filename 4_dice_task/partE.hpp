#ifndef PARTE_H
#define PARTE_H

#include "partB.hpp"
#include <array>

namespace PartE{
    using winning_dies = std::array<PartB::die_t, 3>;

    winning_dies get_winning_dies(const auto & unique_dies);
}

#endif
