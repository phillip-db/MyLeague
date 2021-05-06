#include "core/api_handler.h"
#include "core/input_handler.h"
#include "core/statistics_analyzer.h"
#include "core/champion_filterer.h"
#include "core/champion.h"

#include <iostream>
#include <fstream>

using namespace myleague;

using json = nlohmann::json;

int main() {
  APIHandler a;

  std::string id = a.GetSummonerInfo("iWizzard").GetId();
  std::cout << "Solo/Duo Ranked winrate: "
            << statisticsanalyzer::ComputeRankedWinrate(a.GetRankedLeagues(id).GetRankedLeague(true)) << std::endl;
  std::cout << "Most difficult champions from sample: ";
  std::vector<Champion> sample_champs = ReadChampionFile();
  std::vector<Champion>
      hardest_champs = championfilterer::SelectByDifficulty(sample_champs, Champion::Difficulty::kHard);
  for (const Champion &c : hardest_champs) {
    std::cout << c << " ";
  }
  std::cout << std::endl;
  return 0;
}
