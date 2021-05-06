#include <catch2/catch.hpp>
#include "core/ranked_league.h"

using namespace myleague;

TEST_CASE("Capitalize only first letter of string", "[CapitalizeFirst]") {
  SECTION("Empty string") {
    REQUIRE(RankedLeague::CapitalizeFirst("").empty());
  }

  SECTION("First letter already capitalized") {
    REQUIRE(RankedLeague::CapitalizeFirst("TEsT") == "Test");
  }

  SECTION("First letter not capitalized") {
    REQUIRE(RankedLeague::CapitalizeFirst("teSt") == "Test");
  }
}





