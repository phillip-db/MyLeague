#pragma once
#include <curl/curl.h>

#include <string>
namespace myleague {

class Handler {
 public:

  explicit Handler(const std::string &api_key, const std::string &region = "NA1", const std::string &locale = "en_US");
  
  std::string GetSummonerInfo(const std::string& summoner_name) const;
  
  std::string GetAllChampionMastery(const std::string& summoner_id) const;

 private:
  const std::string kHttps = "https://";
  const std::string kDomain = ".api.riotgames.com";
  const std::string kSummonerEndpoint = "/lol/summoner/v4/summoners/by-name/";
  const std::string kMasteryEndpoint = "/lol/champion-mastery/v4/champion-masteries/by-summoner/";
  const std::string kByChampion = "/by-champion/";
  
  std::string base_url_;
  std::string api_url_end_;
  std::string api_key_;
  std::string region_;
  std::string locale_;

  static std::string HandleRequest(const std::string& url) ;
  static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

} // 