#pragma once

#include "ranked_league.h"

#include <vector>
namespace myleague {

class RankedLeagueContainer {
 public:
  explicit RankedLeagueContainer(const std::vector<RankedLeague> &ranked_leagues);
 private:
  std::vector<RankedLeague> ranked_leagues_;
};

} // namespace myleague

