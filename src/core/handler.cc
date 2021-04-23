#include <iostream>
#include <fstream>
#include "core/handler.h"

using namespace myleague;

Handler::Handler(const std::string &region,
                 const std::string &locale) {
  base_url_ = kHttps + region + kDomain;
  api_url_end_ = "?api_key=" + ReadAPIKey();
}

std::string Handler::GetSummonerInfo(const std::string &summoner_name) const {
  std::string url = base_url_ + kSummonerEndpoint + summoner_name + api_url_end_;
  return HandleRequest(url);
}

std::string Handler::GetTotalMasteryScore(const std::string &summoner_id) const {
  std::string url = base_url_ + kTotalMasteryEndpoint + summoner_id + api_url_end_;
  return HandleRequest(url);
}

// Callback code adapted from https://gist.github.com/alghanmi/c5d7b761b2c9ab199157#file-curl_example-cpp
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
  }

  return readBuffer;
}

std::string Handler::ReadAPIKey() {
  std::ifstream api_file(kFilepath);
  std::string api_key;

  getline(api_file, api_key);
  api_file.close();

  return api_key;
}
