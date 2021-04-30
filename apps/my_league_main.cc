#include <core/api_handler.h>

#include <fstream>
#include <iostream>

using namespace myleague;

using json = nlohmann::json;

int main() {
  APIHandler h;
  std::cout << "Summoner name: " << h.GetSummonerInfo("iWizzard").GetName() << std::endl;
  std::string id = "TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE";
  
  std::cout << "Total Mastery Score: " << h.GetTotalMasteryScore(id) << std::endl;
  
  RankedLeague league = h.GetRankedLeagues(id).GetRankedLeague(true);
  std::cout << "Rank: " << league.GetTier() << " " << league.GetRank() << std::endl;
  
  std::string champion = "Jhin";
  std::cout << "Best designed champion in the game: " << h.GetChampion(champion).GetName() << ", " << h.GetChampion(champion).GetTitle();
  return 0;
}
