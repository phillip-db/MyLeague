#pragma once

#include "screen.h"

namespace myleague {

class ChampionScreen : public Screen {
 public:
  ChampionScreen(float width, float height);
  
  void Display() const;
 private:
  float width_;
  float height_;
};

} // namespace myleague

