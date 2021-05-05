#include <iostream>
#include "core/input_handler.h"

using namespace myleague;

InputHandler::InputHandler() : api_handler_(APIHandler()) {}

void InputHandler::ReadInput(Request request) const {
  std::string query;
  std::string id;

  std::cout << "Please enter ";
  if (request == Champion) {
    std::cout << "a Champion name:" << std::endl;
    std::cin >> query;
  } else {
    std::cout << "a Summoner name:" << std::endl;
    std::cin >> query;
    id = api_handler_.GetSummonerInfo(query).GetId();
  }

  switch (request) {
    case Summoner:
      std::cout << "Summoner ID: " << api_handler_.GetSummonerInfo(query).GetId();
      break;
    case Mastery:
      std::cout << api_handler_.GetSummonerInfo(query).GetName() << "'s Total Mastery: "
                << api_handler_.GetTotalMasteryScore(id);
      break;
    case Champion:
      std::cout << api_handler_.GetChampion(query).GetName() << ", " << api_handler_.GetChampion(query).GetTitle();
      break;
    case Rank:
      RankedLeague solo_duo = api_handler_.GetRankedLeagues(id).GetRankedLeague(true);
      std::cout << api_handler_.GetSummonerInfo(query).GetName() << "'s Solo/Duo Rank: " << solo_duo.GetTier()
                << " "
                << solo_duo.GetRank();
      break;
  }

  std::cout << std::endl;
}

