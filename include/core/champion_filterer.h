#pragma once
#include "champion.h"

namespace myleague {

namespace championfilterer {

std::vector<Champion> SelectByDifficulty(const std::vector<Champion> &champions, Champion::Difficulty difficulty);

std::vector<Champion> SelectByStyle(const std::vector<Champion> &champions, size_t style);

std::vector<Champion> SelectByDamageType(const std::vector<Champion> &champions, std::string damage_type);
}

} // namespace myleague
