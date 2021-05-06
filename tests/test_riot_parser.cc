#include <catch2/catch.hpp>
#include <iostream>
#include "core/riot_parser.h"

using namespace myleague;
using json = nlohmann::json;

TEST_CASE("Test SummonerInfo parsing", "[ParseSummonerInfo]") {
  json j = json::parse(R"({
    "id": "ID",
    "accountId": "a_ID",
    "puuid": "puuid",
    "name": "Name",
    "profileIconId": 1,
    "revisionDate": 3,
    "summonerLevel": 0
})");

  SummonerInfo s = riotparser::ParseSummonerInfo(j);
  REQUIRE(s.GetId() == "ID");
  REQUIRE(s.GetAccountId() == "a_ID");
  REQUIRE(s.GetPuuid() == "puuid");
  REQUIRE(s.GetName() == "Name");
  REQUIRE(s.GetProfileIconId() == 1);
  REQUIRE(s.GetRevisionDate() == 3);
  REQUIRE(s.GetSummonerLevel() == 0);
}

TEST_CASE("Test RankedLeagues parsing", "[ParseSummonerInfo]") {
  json j = json::parse(R"([
    {
        "leagueId": "1b3cf57b-49cb-49e7-ad38-3a0d8064c24e",
        "queueType": "RANKED_FLEX_SR",
        "tier": "GOLD",
        "rank": "II",
        "summonerId": "TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE",
        "summonerName": "iWizzard",
        "leaguePoints": 65,
        "wins": 13,
        "losses": 15,
        "veteran": false,
        "inactive": false,
        "freshBlood": false,
        "hotStreak": false
    },
    {
    }
])");

  RankedLeagueContainer rlc = riotparser::ParseRankedLeagues(j);

  const RankedLeague &solo = rlc.GetRankedLeague(true);
  const RankedLeague &flex = rlc.GetRankedLeague(false);

  SECTION("Verify solo rank league values") {
    REQUIRE(solo.GetLeagueId().empty());
    REQUIRE(solo.GetQueueType().empty());
    REQUIRE(solo.GetTier().empty());
    REQUIRE(solo.GetRank().empty());
    REQUIRE(solo.GetSummonerId().empty());
    REQUIRE(solo.GetSummonerName().empty());
    REQUIRE(solo.GetLeaguePoints() == 0);
    REQUIRE(solo.GetWins() == 0);
    REQUIRE(solo.GetLosses() == 0);
    REQUIRE(solo.IsVeteran() == false);
    REQUIRE(solo.IsInactive() == false);
    REQUIRE(solo.IsFreshBlood() == false);
    REQUIRE(solo.IsHotStreak() == false);
  }

  SECTION("Verify flex rank league values") {
    REQUIRE(flex.GetLeagueId() == "1b3cf57b-49cb-49e7-ad38-3a0d8064c24e");
    REQUIRE(flex.GetQueueType() == "RANKED_FLEX_SR");
    REQUIRE(flex.GetTier() == "GOLD");
    REQUIRE(flex.GetRank() == "II");
    REQUIRE(flex.GetSummonerId() == "TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE");
    REQUIRE(flex.GetSummonerName() == "iWizzard");
    REQUIRE(flex.GetLeaguePoints() == 65);
    REQUIRE(flex.GetWins() == 13);
    REQUIRE(flex.GetLosses() == 15);
    REQUIRE(flex.IsVeteran() == false);
    REQUIRE(flex.IsInactive() == false);
    REQUIRE(flex.IsFreshBlood() == false);
    REQUIRE(flex.IsHotStreak() == false);
  }
}

TEST_CASE("Test Champion parsing", "[ParseChampionInfo]") {
  json j = json::parse(R"({
      "id": 268,
      "name": "Azir",
      "title": "Bird",
      "tacticalInfo": {
        "style": 5,
        "difficulty": 3,
        "damageType": "kMagic"
      }
    }
)");

  Champion c = riotparser::ParseChampionInfo(j);

  REQUIRE(c.GetId() == 268);
  REQUIRE(c.GetName() == "Azir");
  REQUIRE(c.GetTitle() == "Bird");
  REQUIRE(c.GetShortBio().empty());
  REQUIRE(c.GetStyle() == 5);
  REQUIRE(c.GetDifficulty() == 3);
  REQUIRE(c.GetDamageType() == "kMagic");
}







