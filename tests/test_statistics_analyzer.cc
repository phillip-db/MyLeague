#include <catch2/catch.hpp>
#include "core/statistics_analyzer.h"

using namespace myleague;

TEST_CASE("Calculate win percentage", "[ComputeRankedWinrate]") {
  SECTION("Multiple games played") {
    RankedLeague rl("", "", "", "", "", "", 0, 1, 1, false, false, false, false);
    REQUIRE(statisticsanalyzer::ComputeRankedWinrate(rl) == Approx(0.5));
  }

  SECTION("No games played") {
    RankedLeague rl2("", "", "", "", "", "", 0, 0, 0, false, false, false, false);
    REQUIRE(std::isnan(statisticsanalyzer::ComputeRankedWinrate(rl2)));
  }
}





