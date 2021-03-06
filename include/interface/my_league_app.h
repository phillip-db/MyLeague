#pragma once

#include "main_screen.h"
#include "summoner_screen.h"
#include "champion_screen.h"
#include "core/champion_filterer.h"
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

  /**
   * Called when a key is pressed, used for switching screens and various functions
   * @param event The recorded keyboard event
   */
  void keyDown(ci::app::KeyEvent event) override;

  /**
   * Draws title seen across all screens
   */
  void DrawTitle() const;

  /**
   * Resets the app state to the main screen
   */
  void ResetApp();

  const float kWindowWidth = 1200;
  const float kWindowHeight = 700;
 private:
  const ci::Color8u kBackgroundColor = ci::Color8u(46, 56, 73); // shade of cyan
  const ci::Color kTitleColor = ci::Color("White");
  const std::string kIconPath = "data/images/icon.png";
  const std::string kAppName = "myLeague";

  ci::gl::Texture2dRef texture_;
  Screen *screen_;
  std::vector<Champion> champions_;
};

} // namespace myleague
