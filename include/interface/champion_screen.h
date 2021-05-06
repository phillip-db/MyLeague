#pragma once

#include "screen.h"
#include "core/champion.h"

using cinder::gl::Texture2dRef;

namespace myleague {

/**
 * Child of Screen, displays Champion information
 */
class ChampionScreen : public Screen {
 public:
  ChampionScreen(float width, float height);

  void Display() const override;

  /**
   * Reads and validates champion name from console
   * @return validated champion name
   */
  static std::string ReadChampionName();

  /**
   * Prompts user to provide Champion names and builds list from the given champions
   * @return a list of Champions
   */
  static std::vector<Champion> BuildChampionList();

  void SetChampions(const std::vector<Champion> &champions) override;
 private:
  constexpr static float kSplashRatio = 560.0 / 308;
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
  const std::string kSplashEndpoint = "https://cdn.communitydragon.org/latest/champion/";

  float width_;
  float height_;
  std::vector<std::string> champion_bio_;
  Champion champion_;
  std::vector<Champion> champions_;
  Texture2dRef champion_splash_;

  /**
   * Loads required images when screen is created
   */
  void LoadImages();

  /**
   * Draws Champion Splash art image on screen
   * @param x Starting x position
   * @param y Starting y position
   * @param width Width of the image
   */
  void DrawSplash(float x, float y, float width) const;

  /**
   * Draws Champion info text on the screen
   * @param x Starting x position
   * @param y Starting y position
   */
  void DrawChampionInfo(float x, float y) const;

  /**
   * Draws keybind info text on screen
   * @param x Starting x position
   * @param y Starting y position
   */
  void DrawKeybindInfo(float x, float y) const;

  /**
   * Draws list of champions on screen
   * @param x Starting x position
   * @param y Startying y position
   */
  void DrawChampionList(float x, float y) const;
};

} // namespace myleague

