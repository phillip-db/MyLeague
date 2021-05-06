#pragma once
#include "champion.h"

namespace myleague {

namespace championfilterer {

/**
 * Selects champions based on their difficulty
 * @param champions The champions to select from
 * @param difficulty The difficulty to select for
 * @return champions that match the given difficulty
 */
std::vector<Champion> SelectByDifficulty(const std::vector<Champion> &champions, Champion::Difficulty difficulty);

/**
 * Selects champions based on their playstyle
 * @param champions The champions to select from
 * @param style The playstyle to select for
 * @return champions that match the given playstyle
 */
std::vector<Champion> SelectByStyle(const std::vector<Champion> &champions, size_t style);

/**
 * Selects champions based on their damage type
 * @param champions The champions to select from
 * @param damage_type The damage type to select for
 * @return champions that match the given damage type
 */
std::vector<Champion> SelectByDamageType(const std::vector<Champion> &champions, const std::string &damage_type);
}

} // namespace myleague
