#pragma once

#include "screen.h"

namespace myleague {

/**
 * Child class of Screen, represents the main/home screen of the app
 */
class MainScreen : public Screen {
 public:
  MainScreen(float width, float height);

  void Display() const override;

  /**
   * Draws the welcome text/images on the scren
   */
  void DrawWelcomeText() const;
 private:
  const ci::Font kWelcomeFont = ci::Font("Arial", 30);
  const std::string kSummonerPath = "data/images/summoner_button.jpg";
  const std::string kChampionPath = "data/images/champion_button.jpg";
  
  ci::gl::Texture2dRef summoner_button_;
  ci::gl::Texture2dRef champion_button_;

  float width_;
  float height_;
};

}