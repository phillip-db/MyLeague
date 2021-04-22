#include <iostream>
#include "handler.h"

using namespace myleague;

Handler::Handler(const std::string &api_key,
                 const std::string &region,
                 const std::string &locale) {
  api_key_ = api_key;
  region_ = region;
  locale_ = locale;
  
  base_url_ = kHttps + region + kDomain;
  api_url_end_ = "?api_key=" + api_key;
}

std::string Handler::GetSummonerInfo(const std::string &summoner_name) const {
  std::string url = base_url_ + kSummonerEndpoint + summoner_name + api_url_end_;
  return HandleRequest(url);
}

std::string Handler::GetAllChampionMastery(const std::string &summoner_id) const {
  std::string url = base_url_ + kMasteryEndpoint + summoner_id + api_url_end_;
  return HandleRequest(url);
}

size_t Handler::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  ((std::string *) userp)->append((char *) contents, size * nmemb);
  return size * nmemb;
}

std::string Handler::HandleRequest(const std::string &url) {
  CURL *curl;
  CURLcode res;
  std::string readBuffer;
  std::cout << "Request " << url << std::endl;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl,
                     CURLOPT_URL,
                     url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res == CURLE_HTTP_NOT_FOUND) {
      throw std::invalid_argument("Summoner name not found");
    }
  }
  
  return readBuffer;
}
