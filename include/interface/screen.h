#pragma once

#include <cinder/Color.h>
#include <cinder/Font.h>
#include <cinder/gl/gl.h>
#include <cinder/ImageIo.h>
#include <cinder/gl/Texture.h>
#include "core/api_handler.h"

namespace myleague {

/**
 * Parent class representing a singular screen of the app
 */
class Screen {
 public:
  /**
   * Enum representing the different Screens of the app
   */
  enum ScreenType {
    kMain,
    kSummoner,
    kChampion
  };

  Screen(float width, float height, ScreenType screen_type);

  /**
   * Displays the elements of the Screen, called each frame
   */
  virtual void Display() const;

  virtual void SetChampions(const std::vector<Champion> &champions);
  float GetWidth() const;
  float GetHeight() const;
  ScreenType GetScreenType() const;
 private:
  const ci::Font kButtonFont = ci::Font("Arial", 12);

  float width_;
  float height_;
  ScreenType screen_type_;
 protected:
  const ci::Color kFontColor = ci::Color("White");
};

} // namespace myleague

