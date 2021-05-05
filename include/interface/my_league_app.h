#pragma once

#include "screen.h"
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

namespace myleague {

/**
 * Main interface where the user will interact with the app.
 */
class MyLeagueApp : public ci::app::App {
 public:
  const ci::Color kFontColor = ci::Color("White");
  
  MyLeagueApp();

  void draw() override;
  
  void setup() override;
  
  void DrawTitle() const;
  
  void ResetApp() const;

  const float kWindowWidth = 1200;
  const float kWindowHeight = 700;
  const double kMargin = 100;
 private:
  const ci::Color8u kBackgroundColor = ci::Color8u(46, 56, 73); // shade of cyan
  ci::gl::Texture2dRef texture_;
  Screen screen_;
};

} // namespace myleague
