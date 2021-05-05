#pragma once

#include "screen.h"
#include "core/ranked_league_container.h"
#include "core/summoner_info.h"

namespace myleague {

class SummonerScreen : public Screen {
 public:
  SummonerScreen(float width, float height);
  
  void Display() const;
 private:
  float width_;
  float height_;
};

}
