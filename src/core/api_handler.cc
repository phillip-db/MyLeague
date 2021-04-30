#include <iostream>
#include <fstream>
#include "core/api_handler.h"

using namespace myleague;
using json = nlohmann::json;

const std::string APIHandler::kErrorMessage = "Error";

APIHandler::APIHandler(const std::string &region,
                       const std::string &locale) {
  base_url_ = kHttps + region + kDomain;
  api_url_end_ = "?api_key=" + ReadAPIKey();
}

SummonerInfo APIHandler::GetSummonerInfo(const std::string &summoner_name) const noexcept(false) {
  std::string url = base_url_ + kSummonerEndpoint + summoner_name + api_url_end_;
  json raw_json = json::parse(HandleRequest(url));
  return riotparser::ParseSummonerInfo(raw_json);
}

std::string APIHandler::GetTotalMasteryScore(const std::string &summoner_id) const noexcept(false) {
  std::string url = base_url_ + kTotalMasteryEndpoint + summoner_id + api_url_end_;
  return HandleRequest(url);
}

RankedLeagueContainer APIHandler::GetRankedLeagues(const std::string &summoner_id) const noexcept(false) {
  std::string url = base_url_ + kRankedLeaguesEndpoint + summoner_id + api_url_end_;
  json raw_json = json::parse(HandleRequest(url));
  return riotparser::ParseRankedLeagues(raw_json);
}

Champion APIHandler::GetChampion(const std::string &champion_name) const noexcept(false) {
  std::string url = kChampionEndpoint + champion_name + "/data";
  json raw_json = json::parse(HandleRequest(url));
  return riotparser::ParseChampionInfo(raw_json);
}

// Callback code adapted from https://gist.github.com/alghanmi/c5d7b761b2c9ab199157#file-curl_example-cpp
size_t APIHandler::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  ((std::string *) userp)->append((char *) contents, size * nmemb);
  return size * nmemb;
}

std::string APIHandler::HandleRequest(const std::string &url) noexcept(false) {
  CURL *curl;
  CURLcode res;
  std::string readBuffer;
  // std::cout << "Request " << url << std::endl;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl,
                     CURLOPT_URL,
                     url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    
    long http_code;
    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code == 404) {
      throw std::invalid_argument("Invalid query parameter");
    }
    
    curl_easy_cleanup(curl);
  }

  return readBuffer;
}

std::string APIHandler::ReadAPIKey() {
  std::ifstream api_file(kFilepath);
  std::string api_key;

  getline(api_file, api_key);
  api_file.close();

  return api_key;
}
