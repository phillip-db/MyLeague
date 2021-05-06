#pragma once

#include "screen.h"
#include "core/ranked_league_container.h"
#include "core/summoner_info.h"
#include "core/statistics_analyzer.h"

using ci::gl::Texture2dRef;

namespace myleague {

/**
 * Child class of Screen, represents Screen for information on Summoner
 */
class SummonerScreen : public Screen {
 public:
  SummonerScreen(float width, float height);

  void Display() const;

 private:
  const ci::Font kNameFont = ci::Font("Arial", 50);
  const ci::Font kRankFont = ci::Font("Arial", 25);
  const std::string kIconEndpoint = "https://cdn.communitydragon.org/latest/profile-icon/";
  const std::string kRankIconEndpoint = "https://img.rankedboost.com/wp-content/uploads/2014/09/Season_2019_-_";
  const std::string kDefaultRankUrl = "https://img.rankedboost.com/wp-content/uploads/2014/09/unranked-season-rewards-lol.png";
  constexpr static float kPadding = 80;
  constexpr static float kImgSize = 200;

  float width_;
  float height_;
  std::string summoner_name_;
  std::string total_mastery_;
  SummonerInfo summoner_info_;
  RankedLeagueContainer ranked_leagues_;
  Texture2dRef summoner_icon_;
  Texture2dRef ranked_solo_icon_;
  Texture2dRef ranked_flex_icon_;

  /**
   * Reads valid summoner name from console
   */
  void ReadSummonerName();

  /**
   * Preloads required images based on provided summoner name
   */
  void LoadImages();

  /**
   * Draws basic Summoner info (name, icon, level, mastery)
   */
  void DrawBasicInfo() const;

  /**
   * Draws info for ranked league (rank, winrate, points, games, icon)
   * @param is_solo Whether ranked league is solo/flex
   * @param translation The positional translation of the rank info
   */
  void DrawRankInfo(bool is_solo, const glm::vec2 &translation) const;
};

}
