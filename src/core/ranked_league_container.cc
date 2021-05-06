#include "core/ranked_league_container.h"

using namespace myleague;
RankedLeagueContainer::RankedLeagueContainer(const std::vector<RankedLeague> &ranked_leagues) : ranked_leagues_(
    ranked_leagues) {}

const RankedLeague &RankedLeagueContainer::GetRankedLeague(bool is_solo_duo) const {
  if (is_solo_duo) {
    return ranked_leagues_[1]; // Solo/duo rank index is 1
  } else {
    return ranked_leagues_[0]; // Flex rank index is 0
  }
}
