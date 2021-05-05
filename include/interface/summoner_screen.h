#pragma once

#include "screen.h"
#include "core/ranked_league_container.h"
#include "core/summoner_info.h"
#include "core/statistics_analyzer.h"

using ci::gl::Texture2dRef;

namespace myleague {

class SummonerScreen : public Screen {
 public:
  SummonerScreen(float width, float height);
  
  void Display() const;
  
 private:
  const ci::Font kNameFont = ci::Font("Arial", 50);
  const ci::Font kRankFont = ci::Font("Arial", 25);
  const std::string kIconEndpoint = "https://cdn.communitydragon.org/latest/profile-icon/";
  const std::string kRankIconEndpoint = "https://img.rankedboost.com/wp-content/uploads/2014/09/Season_2019_-_";
  
  float width_;
  float height_;
  std::string summoner_name_;
  std::string total_mastery_;
  SummonerInfo summoner_info_;
  RankedLeagueContainer ranked_leagues_;
  Texture2dRef summoner_icon_;
  Texture2dRef ranked_solo_icon_;
  Texture2dRef ranked_flex_icon_;
  
  void ReadSummonerName();
  void LoadImages();
  void DrawBasicInfo() const;
  void DrawRankInfo(bool is_solo, const glm::vec2& translation) const;
};

}
