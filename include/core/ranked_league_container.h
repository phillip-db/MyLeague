#pragma once

#include "ranked_league.h"

#include <vector>
namespace myleague {

class RankedLeagueContainer {
 public:
  explicit RankedLeagueContainer(const std::vector<RankedLeague> &ranked_leagues);
  
  const RankedLeague& GetRankedLeague(bool is_solo_duo) const;
  
 private:
  std::vector<RankedLeague> ranked_leagues_;
};

} // namespace myleague

