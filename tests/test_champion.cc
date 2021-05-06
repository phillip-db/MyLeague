#include <catch2/catch.hpp>
#include <sstream>
#include "core/champion.h"

using namespace myleague;

TEST_CASE("Output stream operator", "[operator<<]") {
  Champion champion(7, "Azir", "Bird", "Bird", 2, 2, "Magic");
  std::ostringstream name;
  name << champion;
  
  REQUIRE(champion.GetName() == "Azir");
  REQUIRE(name.str() == "Azir");
}

TEST_CASE("Split ShortBio into multiple parts", "[SplitBio]") {
  Champion champion(7, "Azir", "Bird", "Fun Bird Champion", 2, 2, "Magic");

  std::vector<std::string> expected{"Fun", "Bird", "Champion..."};
  REQUIRE(champion.SplitBio(1) == expected);

  expected = {"Fun Bird..."};
  REQUIRE(champion.SplitBio(2) == expected);
}





