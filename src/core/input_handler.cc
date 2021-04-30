#include <iostream>
#include "core/input_handler.h"

using namespace myleague;

InputHandler::InputHandler() : api_handler_(APIHandler()) {}

void InputHandler::ReadInput(Request request) const {
  std::string query;
  std::string id;
  bool invalid_query = true;

  while (invalid_query) {
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
      case Summoner:std::cout << "Summoner ID: " << api_handler_.GetSummonerInfo(query).GetId();
        invalid_query = false;
        break;
      case Mastery:
        std::cout << api_handler_.GetSummonerInfo(query).GetName() << "'s Total Mastery: "
                  << api_handler_.GetTotalMasteryScore(id);
        invalid_query = false;
        break;
      case Champion:
        std::cout << api_handler_.GetChampion(query).GetName() << ", " << api_handler_.GetChampion(query).GetTitle();
        invalid_query = false;
        break;
      case Rank:RankedLeague solo_duo = api_handler_.GetRankedLeagues(id).GetRankedLeague(true);
        std::cout << api_handler_.GetSummonerInfo(query).GetName() << "'s Solo/Duo Rank: " << solo_duo.GetTier()
                  << " "
                  << solo_duo.GetRank();
        invalid_query = false;
        break;
    }

    std::cout << std::endl;
  }
}

