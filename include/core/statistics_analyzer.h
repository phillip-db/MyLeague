#pragma once

#include "ranked_league.h"
namespace myleague {

/**
 * Namespace containing analysis functions for various statistics (Ranked/Champions)
 */
namespace statisticsanalyzer {

/**
 * Computes a summoner's ranked winrate for the given Ranked League
 * @param ranked_league The Ranked League (Flex/SoloDuo) to compute winrate of
 * @return a summoner's winrate for the given Ranked League
 */
double ComputeRankedWinrate(const RankedLeague &ranked_league);

} // namespace statisticsanalyzer

} // namespace myleague
