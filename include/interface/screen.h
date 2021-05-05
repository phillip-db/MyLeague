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
  Screen(float width, float height);

  void Display() const;

  void DrawButton(float x, float y, const cinder::Color &color, const std::string &label, float size) const;
  
 private:
  const ci::Font kButtonFont = ci::Font("Arial", 12);
  float width_;
  float height_;

};

} // namespace myleague

