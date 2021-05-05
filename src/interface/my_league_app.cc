#include "interface/my_league_app.h"

using namespace myleague;

using glm::vec2;

using namespace cinder;

MyLeagueApp::MyLeagueApp() : screen_(kWindowWidth, kWindowHeight) {
  ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
}

void MyLeagueApp::draw() {
  ci::gl::clear(kBackgroundColor);
  DrawTitle();
  ci::gl::pushModelMatrix();
  ci::gl::translate(kWindowWidth / 2.0f, kWindowHeight / 2.0f);
  ci::gl::rotate(0);
  ci::gl::drawStringCentered(
      "Welcome to myLeague!", glm::vec2(0, 0), ci::Color("White"),
      ci::Font("Arial", 20));
  ci::gl::popModelMatrix();
}

void MyLeagueApp::DrawTitle() const {
  ci::gl::pushModelMatrix();
  ci::gl::translate(kWindowWidth / 2 + 20, kWindowHeight / 20);
  ci::gl::drawStringCentered("myLeague", vec2(0, 0), kFontColor, ci::Font("Arial", 30));
  ci::gl::translate(-kWindowWidth / 10, -12.5);
  gl::draw(texture_, Rectf(0, 0, 50, 50));
  ci::gl::popModelMatrix();
}

void MyLeagueApp::setup() {
  Surface surface(loadImage("data/images/icon.png"));
  texture_ = gl::Texture2d::create(surface);
}
