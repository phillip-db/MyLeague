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
  
  void SetChampions(const std::vector<Champion>& champions);
 private:
  constexpr static float kSplashRatio = 560.0/308;
  constexpr static float kPadding = 80;
  constexpr static float kSplashWidth = 300;
  constexpr static float kListSpacing = 20;
  const size_t kNumColumns = 2;
  const ci::Font kInfoFontLarge = ci::Font("Arial", 50);
  const ci::Font kInfoFontMed = ci::Font("Arial", 25);
  const ci::Font kInfoFontSmall = ci::Font("Arial", 14);
  const ci::Font kKeybindFont = ci::Font("Arial", 20);
  const ci::Font kChampListFont = ci::Font("Arial", 18);
  const static std::string kExit;
  
  float width_;
  float height_;
  std::vector<std::string> champion_bio_;
  Champion champion_;
  std::vector<Champion> champions_;
  Texture2dRef champion_splash_;
  
  void LoadImages();
  
  void DrawSplash(float x, float y, float width) const;
  
  void DrawChampionInfo(float x, float y) const;
  
  void DrawKeybindInfo(float x, float y) const;
  
  void DrawChampionList(float x, float y) const;
};

} // namespace myleague

