#pragma once

#include "nlohmann/json.hpp"
#include "summoner_info.h"
#include "ranked_league_container.h"
#include "champion.h"

using json = nlohmann::json;

namespace myleague {

/**
 * Namespace used in deserializing JSON data from API endpoints
 */
namespace riotparser {

/**
 * Deserializes the Summoner endpoint into a SummonerInfo object
 * @param raw_json The JSON received from the endpoint 
 * @return a SummonerInfo object representing the JSON info
 */
SummonerInfo ParseSummonerInfo(const json& raw_json);

/**
 * Deserializes the Leagues endpoint into RankedLeague object contained by a wrapper
 * @param raw_json The JSON received from the endpoint
 * @return a RankedLeagueContainer containing summoner's two ranked leagues
 */
RankedLeagueContainer ParseRankedLeagues(const json& raw_json);

/**
 * Deserializes the Champion endpoint into a Champion object
 * @param raw_json The JSON received from the endpoint
 * @return a Champion object containing information about that champion
 */
Champion ParseChampionInfo(const json& raw_json);

} // namespace riotparser

} // namespace myleague

