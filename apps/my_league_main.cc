#include "core/api_handler.h"
#include "core/input_handler.h"
#include "core/statistics_analyzer.h"
#include "core/champion_filterer.h"
#include "core/champion.h"

#include <iostream>
#include <fstream>

using namespace myleague;

using json = nlohmann::json;

// Temp helper function to read champion names from file
std::vector<Champion> ReadChampionNames() {
  APIHandler a;

  std::ifstream input_file("data/champion_names.txt");
  std::string line;
  std::vector<Champion> champions;

  while (std::getline(input_file, line)) {
    champions.push_back(a.GetChampion(line));
  }

  return champions;
}

int main() {
  InputHandler h;
  
  h.ReadInput(InputHandler::Summoner);
  h.ReadInput(InputHandler::Mastery);
  h.ReadInput(InputHandler::Rank);
  h.ReadInput(InputHandler::Champion);

  APIHandler a;

  std::string id = a.GetSummonerInfo("iWizzard").GetId();
  std::cout << "Solo/Duo Ranked winrate: "
            << statisticsanalyzer::ComputeRankedWinrate(a.GetRankedLeagues(id).GetRankedLeague(true)) << std::endl;
  std::cout << "Most difficult champions from sample: ";
  std::vector<Champion> sample_champs = ReadChampionNames();
  std::vector<Champion>
      hardest_champs = championfilterer::SelectByDifficulty(sample_champs, Champion::Difficulty::kHard);
  for (const Champion &c : hardest_champs) {
    std::cout << c << " ";
  }
  std::cout << std::endl;
  return 0;
}
