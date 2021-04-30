#include <catch2/catch.hpp>
#include "core/api_handler.h"

using namespace myleague;

TEST_CASE("Valid summoner name", "[GetSummonerInfo]") {
  APIHandler h;
  SummonerInfo s = h.GetSummonerInfo("iWizzard");

  REQUIRE(s.GetId() == "TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE");
  REQUIRE(s.GetAccountId() == "URt5t7OPPzGiO7pEmR7YK5b3DxngaH08h_C47iPFLVK1XQ");
  REQUIRE(s.GetPuuid() == "iEg8LB9IlT6UzggVlESAj93Gf6EUU5NbQZVPeSPqE016LjOFJ3qLhV_P60REnEMLTZfR--hlJK2nCg");
  REQUIRE(s.GetName() == "iWizzard");
  REQUIRE(s.GetProfileIconId() == 3506);
  REQUIRE(s.GetSummonerLevel() == 339);
}

TEST_CASE("Valid summoner id", "[GetTotalMasteryScore]") {
  APIHandler h;
  REQUIRE(h.GetTotalMasteryScore("TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE") == "570");
}





