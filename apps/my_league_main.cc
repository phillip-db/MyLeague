#include <core/api_handler.h>

#include <fstream>
#include <iostream>

using namespace myleague;

int main() {
  APIHandler h;
  std::cout << h.GetSummonerInfo("iWizzard").GetProfileIconId() << std::endl;
  std::cout << h.GetTotalMasteryScore("TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE");
  return 0;
}
