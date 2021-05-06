#pragma once

#include <cinder/Color.h>
#include <cinder/Font.h>
#include <cinder/gl/gl.h>
#include <cinder/ImageIo.h>
#include <cinder/gl/Texture.h>
#include "core/api_handler.h"

namespace myleague {

/**
 * Class that handles displaying various graphical elements in Cinder app.
 */
class Screen {
 public:
  enum ScreenType {
    kMain,
    kSummoner,
    kChampion
  };
  
  Screen(float width, float height, ScreenType screen_type);

  virtual void Display() const;
  
  virtual void SetChampions(const std::vector<Champion>& champions);

  void DrawButton(float x, float y, const cinder::Color &color, const std::string &label, float size) const;
  
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

