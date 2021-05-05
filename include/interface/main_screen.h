#pragma once

#include "screen.h"
#include "core/ranked_league_container.h"
#include "core/summoner_info.h"

namespace myleague {

class MainScreen : public Screen {
 public:
  MainScreen(float width, float height, const std::string& summoner_name);
  
  void Display() const;
  
  void DrawWelcomeText() const;
 private:
  const ci::Font kWelcomeFont = ci::Font("Arial", 30);
  
  float width_;
  float height_;
  SummonerInfo summoner_info_;
  RankedLeagueContainer ranked_league_container_;
};

}