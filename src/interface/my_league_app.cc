#include "interface/my_league_app.h"

using namespace myleague;
using namespace cinder;

using glm::vec2;
using ci::app::KeyEvent;

MyLeagueApp::MyLeagueApp() {
  ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
  ResetApp();
}

void MyLeagueApp::draw() {
  ci::gl::clear(kBackgroundColor);
  DrawTitle();
  screen_->Display();
}

void MyLeagueApp::DrawTitle() const {
  ci::gl::pushModelMatrix();
  ci::gl::translate(kWindowWidth / 2 + 20, kWindowHeight / 20);
  ci::gl::drawStringCentered("myLeague", vec2(0, 0), kTitleColor, ci::Font("Arial", 30));
  ci::gl::translate(-kWindowWidth / 10, -12.5);
  gl::draw(texture_, Rectf(0, 0, 50, 50));
  ci::gl::popModelMatrix();
}

void MyLeagueApp::setup() {
  Surface surface(loadImage("data/images/icon.png"));
  texture_ = gl::Texture2d::create(surface);
}

void MyLeagueApp::ResetApp() {
  auto *main = new MainScreen(kWindowWidth, kWindowHeight);
  screen_ = main;
}

void MyLeagueApp::keyDown(KeyEvent event) {
  switch (screen_->GetScreenType()) {
    case Screen::kMain:
      if (event.getCode() == KeyEvent::KEY_s) {
        auto *summoner = new SummonerScreen(kWindowWidth, kWindowHeight);
        screen_ = summoner;
      } else if (event.getCode() == KeyEvent::KEY_c) {
        auto *champion = new ChampionScreen(kWindowWidth, kWindowHeight);
        screen_ = champion;
      }
      break;
    case Screen::kSummoner:
      if (event.getCode() == KeyEvent::KEY_ESCAPE) {
        auto *main = new MainScreen(kWindowWidth, kWindowHeight);
        screen_ = main;
      }
      break;
    case Screen::kChampion:
      if (event.getCode() == KeyEvent::KEY_ESCAPE) {
        auto *main = new MainScreen(kWindowWidth, kWindowHeight);
        screen_ = main;
      }
      break;
  }
}
