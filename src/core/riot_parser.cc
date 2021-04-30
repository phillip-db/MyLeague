#include "core/riot_parser.h"

using namespace myleague;
using json = nlohmann::json;

SummonerInfo riotparser::ParseSummonerInfo(const json &raw_json) {
  std::string id = raw_json.value("id", "");
  std::string account_id = raw_json.value("accountId", "");
  std::string puuid = raw_json.value("puuid", "");
  std::string name = raw_json.value("name", "");
  size_t profile_icon_id = raw_json.value("profileIconId", 0);
  size_t revision_date = raw_json.value("revisionDate", 0);
  size_t summoner_level = raw_json.value("summonerLevel", 0);

  return SummonerInfo(id, account_id, puuid, name, profile_icon_id, revision_date, summoner_level);
}

RankedLeagueContainer riotparser::ParseRankedLeagues(const json &raw_json) {
  std::vector<RankedLeague> ranked_leagues;
  
  for (const auto& element : raw_json) {
    std::string league_id = element.value("leagueId", "");
    std::string queue_type = element.value("queueType", "");
    std::string tier = element.value("tier", "");
    std::string rank = element.value("rank", "");
    std::string summoner_id = element.value("summonerId", "");
    std::string summoner_name = element.value("summonerName", "");
    size_t league_points = element.value("leaguePoints", 0);
    size_t wins = element.value("wins", 0);
    size_t losses = element.value("losses", 0);
    bool veteran = element.value("veteran", false);
    bool inactive = element.value("inactive", false);
    bool fresh_blood = element.value("freshBlood", false);
    bool hot_streak = element.value("hotStreak", false);

    ranked_leagues.emplace_back(league_id,
                                queue_type,
                                tier,
                                rank,
                                summoner_id,
                                summoner_name,
                                league_points,
                                wins,
                                losses,
                                veteran,
                                inactive,
                                fresh_blood,
                                hot_streak);
  }
  
  return RankedLeagueContainer(ranked_leagues);
}
