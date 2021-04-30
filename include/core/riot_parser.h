#pragma once

#include "summoner_info.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

namespace myleague {

namespace riotparser {

SummonerInfo ParseSummonerInfo(const json& raw_json);



} // namespace riotparser

} // namespace myleague

