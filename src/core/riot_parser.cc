#include "core/riot_parser.h"

using namespace myleague;
using json = nlohmann::json;

SummonerInfo riotparser::ParseSummonerInfo(const json& raw_json) {
  std::string id = raw_json.value("id", "");
  std::string account_id = raw_json.value("accountId", "");
  std::string puuid = raw_json.value("puuid", "");
  std::string name = raw_json.value("name", "");
  size_t profile_icon_id = raw_json.value("profileIconId", 0);
  size_t revision_date = raw_json.value("revisionDate", 0);
  size_t summoner_level = raw_json.value("summonerLevel", 0);
  
  return SummonerInfo(id, account_id, puuid, name, profile_icon_id, revision_date, summoner_level);
}
