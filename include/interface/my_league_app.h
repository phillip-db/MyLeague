#pragma once

#include "main_screen.h"
#include "summoner_screen.h"
#include "champion_screen.h"
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

namespace myleague {

/**
 * Main interface where the user will interact with the app.
 */
class MyLeagueApp : public ci::app::App {
 public:
  MyLeagueApp();

  void draw() override;
  void setup() override;
  
  void keyDown(ci::app::KeyEvent event) override;

  void DrawTitle() const;

  void ResetApp();

  const float kWindowWidth = 1200;
  const float kWindowHeight = 700;
 private:
  const ci::Color8u kBackgroundColor = ci::Color8u(46, 56, 73); // shade of cyan
  const ci::Color kTitleColor = ci::Color("White");
  
  ci::gl::Texture2dRef texture_;
  Screen *screen_;
  std::vector<Champion> champions_;
};

} // namespace myleague
