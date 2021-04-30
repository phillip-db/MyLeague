#include "core/statistics_analyzer.h"

using namespace myleague;

using namespace statisticsanalyzer;

double statisticsanalyzer::ComputeRankedWinrate(const RankedLeague &ranked_league) {
  double total_games = ranked_league.GetLosses() + ranked_league.GetWins();
  return ranked_league.GetWins() / total_games;
}
