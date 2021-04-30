#pragma once
#include <curl/curl.h>
#include "riot_parser.h"

#include <string>
namespace myleague {

/**
 * Class that handles requests to the League of Legends API.
 */
class APIHandler {
 public:
  /**
   * Creates a new handler for the given region and locale.
   * @param region Region to obtain data from.
   * @param locale The language of the region.
   */
  explicit APIHandler(const std::string &region = "NA1", const std::string &locale = "en_US");

  /**
   * Retrieves info on the given summoner name.
   * @param summoner_name The summoner name to get info on.
   * @return a SummonerInfo object.
   */
  SummonerInfo GetSummonerInfo(const std::string &summoner_name) const noexcept(false);

  /**
   * Retrieves the total mastery score for a given summoner.
   * @param summoner_id 
   * @return a string of a summoner's total mastery score.
   */
  std::string GetTotalMasteryScore(const std::string &summoner_id) const noexcept(false);
  
  RankedLeagueContainer GetRankedLeagues(const std::string &summoner_id) const noexcept(false);
  
  Champion GetChampion(const std::string &champion_name) const noexcept(false);

 private:
  const std::string kHttps = "https://";
  const std::string kDomain = ".api.riotgames.com";
  const std::string kSummonerEndpoint = "/lol/summoner/v4/summoners/by-name/";
  const std::string kTotalMasteryEndpoint = "/lol/champion-mastery/v4/scores/by-summoner/";
  const std::string kRankedLeaguesEndpoint = "/lol/league/v4/entries/by-summoner/";
  const std::string kFilepath = "data/no_commit_api_key.txt";
  const std::string kChampionEndpoint = "https://cdn.communitydragon.org/latest/champion/";
  static const std::string kErrorMessage;

  std::string base_url_;
  std::string api_url_end_;

  /**
   * Reads in developer API key from file
   * @return A developer API Key as a string
   */
  std::string ReadAPIKey();

  /**
   * Handles an HTTP request directed at a given League of Legends endpoint
   * @param url The URL to send a request to
   * @return The data received from the request
   */
  static std::string HandleRequest(const std::string &url) noexcept(false);

  /**
   * Writes a callback used in libcurl HTTP requests.
   * @param contents The contents of the request
   * @param size Size of the request
   * @param nmemb 
   * @param userp 
   * @return Callback for a request
   */
  static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

} // namespace myleague