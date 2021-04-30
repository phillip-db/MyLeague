#include <catch2/catch.hpp>
#include "core/api_handler.h"

using namespace myleague;

TEST_CASE("Valid summoner name", "[GetSummonerInfo]") {
  APIHandler h;
}

TEST_CASE("Valid summoner id", "[GetTotalMasteryScore]") {
  APIHandler h;
  REQUIRE(h.GetTotalMasteryScore("TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE") == "570");
}





