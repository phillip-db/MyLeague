#pragma once

#include "nlohmann/json.hpp"
#include "summoner_info.h"
#include "ranked_league_container.h"

using json = nlohmann::json;

namespace myleague {

namespace riotparser {

SummonerInfo ParseSummonerInfo(const json& raw_json);

RankedLeagueContainer ParseRankedLeagues(const json& raw_json);

} // namespace riotparser

} // namespace myleague

