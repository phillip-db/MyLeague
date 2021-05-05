#pragma once

#include "screen.h"

namespace myleague {

class MainScreen : public Screen {
 public:
  MainScreen(float width, float height);
  
  void Display() const;
  
  void DrawWelcomeText() const;
 private:
  const ci::Font kWelcomeFont = ci::Font("Arial", 30);
  ci::gl::Texture2dRef summoner_button_;
  ci::gl::Texture2dRef champion_button_;
  
  float width_;
  float height_;
};

}