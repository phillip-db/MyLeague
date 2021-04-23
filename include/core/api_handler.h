#pragma once
#include <curl/curl.h>

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
   * @return a raw JSON as a string containing summoner info.
   */
  std::string GetSummonerInfo(const std::string &summoner_name) const;

  /**
   * Retrieves the total mastery score for a given summoner.
   * @param summoner_id 
   * @return a string of a summoner's total mastery score.
   */
  std::string GetTotalMasteryScore(const std::string &summoner_id) const;

 private:
  const std::string kHttps = "https://";
  const std::string kDomain = ".api.riotgames.com";
  const std::string kSummonerEndpoint = "/lol/summoner/v4/summoners/by-name/";
  const std::string kTotalMasteryEndpoint = "/lol/champion-mastery/v4/scores/by-summoner/";
  const std::string kFilepath = "data/no_commit_api_key.txt";

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
  static std::string HandleRequest(const std::string &url);

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