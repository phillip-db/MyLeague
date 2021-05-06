#pragma once

#include "screen.h"
#include "core/champion.h"

using cinder::gl::Texture2dRef;

namespace myleague {

class ChampionScreen : public Screen {
 public:
  ChampionScreen(float width, float height);
  
  void Display() const;

  static std::string ReadChampionName();
  static std::vector<Champion> BuildChampionList();
 private:
  constexpr static float kSplashRatio = 560.0/308;
  constexpr static float kPadding = 80;
  constexpr static float kSplashWidth = 300;
  const ci::Font kInfoFontLarge = ci::Font("Arial", 50);
  const ci::Font kInfoFontMed = ci::Font("Arial", 25);
  const ci::Font kInfoFontSmall = ci::Font("Arial", 14);
  const ci::Font kKeybindFont = ci::Font("Arial", 20);
  const static std::string kAll;
  const static std::string kExit;
  
  float width_;
  float height_;
  std::vector<std::string> champion_bio_;
  Champion champion_;
  Texture2dRef champion_splash_;
  
  void LoadImages();
  
  void DrawSplash(float x, float y, float width) const;
  
  void DrawChampionInfo(float x, float y) const;
  
  void DrawKeybindInfo(float x, float y) const;
};

} // namespace myleague

