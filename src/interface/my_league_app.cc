#include "interface/my_league_app.h"

using namespace myleague;

MyLeagueApp::MyLeagueApp() {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void MyLeagueApp::draw() {
  ci::gl::clear(kBackgroundColor);
  ci::gl::pushModelMatrix();
  ci::gl::translate(kWindowSize / 2.0, kWindowSize / 2.0);
  ci::gl::rotate(0);
  ci::gl::drawStringCentered(
      "Welcome to myLeague!", glm::vec2(0, 0), ci::Color("White"),
      ci::Font("Arial", 20));
  ci::gl::popModelMatrix();
}