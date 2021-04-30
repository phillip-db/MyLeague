#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "core/api_handler.h"

namespace myleague {

/**
 * Main interface where the user will interact with the app.
 */
class MyLeagueApp : public ci::app::App {
 public:
  MyLeagueApp();

  void draw() override;

  const double kWindowWidth = 1200;
  const double kWindowHeight = 700;
  const double kMargin = 100;
 private:
  ci::Color8u kBackgroundColor = ci::Color8u(63, 17, 128); // shade of purple
};

} // namespace myleague
