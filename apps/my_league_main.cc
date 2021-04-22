#include <handler.h>

#include <string>
#include <fstream>
#include <iostream>

using namespace myleague;

std::string ReadAPIKey() {
  std::ifstream api_file("data/no_commit_api_key.txt");
  std::string api_key;

  getline(api_file, api_key);
  api_file.close();

  return api_key;
}

int main() {
  std::string api_key = ReadAPIKey();
  std::cout << api_key << std::endl;
  Handler h(api_key);
  std::cout << h.GetSummonerInfo("iWizzard") << std::endl;
  std::cout << h.GetAllChampionMastery("TL-tx-RnrpNdAte17eLrOBFvxHb9ql42t1szEwYgyv5FyiE");
  return 0;
}
