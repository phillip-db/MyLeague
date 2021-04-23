#include <handler.h>

#include <fstream>
#include <iostream>

using namespace myleague;

int main() {
  Handler h;
  std::cout << h.GetSummonerInfo("iWizzard") << std::endl;
  std::cout << h.GetTotalMasteryScore("TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE");
  return 0;
}
