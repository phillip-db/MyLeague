#include <catch2/catch.hpp>
#include "core/champion_filterer.h"

using namespace myleague;

TEST_CASE("Select champions by difficulty", "[SelectByDifficulty]") {
  Champion c1(7, "Azir", "Bird", "Bird", 2, 1, "Magic");
  Champion c2(7, "Azir", "Bird", "Bird", 2, 2, "Magic");
  Champion c3(7, "Azir", "Bird", "Bird", 2, 3, "Magic");
  
  std::vector<Champion> champions{c1, c2, c3};
  
  REQUIRE(championfilterer::SelectByDifficulty(champions, Champion::kEasy)[0].GetDifficulty() == 1);
  REQUIRE(championfilterer::SelectByDifficulty(champions, Champion::kMedium)[0].GetDifficulty() == 2);
  REQUIRE(championfilterer::SelectByDifficulty(champions, Champion::kHard)[0].GetDifficulty() == 3);
}

TEST_CASE("Select champions by playstyle", "[SelectByStyle]") {
  Champion c1(7, "Azir", "Bird", "Bird", 1, 1, "Magic");
  Champion c2(7, "Azir", "Bird", "Bird", 1, 1, "Magic");
  Champion c3(7, "Azir", "Bird", "Bird", 2, 1, "Magic");
  
  std::vector<Champion> champions{c1, c2, c3};
  
  std::vector<Champion> selected1 = championfilterer::SelectByStyle(champions, 1);
  
  REQUIRE(selected1[0].GetStyle() == 1);
  REQUIRE(selected1[1].GetStyle() == 1);
  REQUIRE(championfilterer::SelectByStyle(champions, 2)[0].GetStyle() == 2);
}

TEST_CASE("Select champions by damage type", "[SelectByDamageType") {
  Champion c1(7, "Azir", "Bird", "Bird", 1, 1, "kMagic");
  Champion c2(7, "Azir", "Bird", "Bird", 1, 1, "kPhysical");
  Champion c3(7, "Azir", "Bird", "Bird", 2, 1, "kMixed");
  
  std::vector<Champion> champs{c1, c2, c3};
  
  REQUIRE(championfilterer::SelectByDamageType(champs, "kPhysical")[0].GetDamageType() == "kPhysical");
  REQUIRE(championfilterer::SelectByDamageType(champs, "kMagic")[0].GetDamageType() == "kMagic");
  REQUIRE(championfilterer::SelectByDamageType(champs, "kMixed")[0].GetDamageType() == "kMixed");
}





