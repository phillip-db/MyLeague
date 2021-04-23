#include <catch2/catch.hpp>
#include "core/handler.h"

using namespace myleague;

TEST_CASE("Valid summoner name", "[GetSummonerInfo]") {
  Handler h;
  REQUIRE(h.GetSummonerInfo("iWizzard")
              == "{\"id\":\"TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE\",\"accountId\":\"URt5t7OPPzGiO7pEmR7YK5b3DxngaH08h_C47iPFLVK1XQ\",\"puuid\":\"iEg8LB9IlT6UzggVlESAj93Gf6EUU5NbQZVPeSPqE016LjOFJ3qLhV_P60REnEMLTZfR--hlJK2nCg\",\"name\":\"iWizzard\",\"profileIconId\":3506,\"revisionDate\":1618878153000,\"summonerLevel\":339}");
}

TEST_CASE("Valid summoner id", "[GetTotalMasteryScore]") {
  Handler h;
  REQUIRE(h.GetTotalMasteryScore("TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE") == "570");
}





