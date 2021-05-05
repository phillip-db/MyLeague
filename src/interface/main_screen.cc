#include "interface/main_screen.h"

using namespace myleague;
using namespace cinder;

using glm::vec2;

MainScreen::MainScreen(float width, float height) : Screen(width, height, ScreenType::kMain) {
  width_ = width;
  height_ = height;

  Surface image(loadImage("data/images/summoner_button.jpg"));
  summoner_button_ = gl::Texture2d::create(image);

  image = loadImage("data/images/champion_button.jpg");
  champion_button_ = gl::Texture2d::create(image);
}

void MainScreen::Display() const {
  gl::pushModelMatrix();
  gl::translate(0, -height_ / 10);
  DrawWelcomeText();

  float button_size = width_ / 4;
  float btn_x1 = width_ / 4 - button_size / 2;
  float btn_x2 = 3 * width_ / 4 - button_size / 2;
  float btn_y = height_ / 4 + button_size / 2;

  gl::draw(summoner_button_,
           Rectf(btn_x1, height_ - btn_y, btn_x1 + button_size, height_ + button_size - btn_y));
  gl::drawStringCentered("Summoner", vec2(btn_x1 + button_size / 2, btn_y + button_size), kFontColor, kWelcomeFont);

  gl::draw(champion_button_, Rectf(btn_x2, height_ - btn_y, btn_x2 + button_size, height_ + button_size - btn_y));
  gl::drawStringCentered("Champion", vec2(btn_x2 + button_size / 2, btn_y + button_size), kFontColor, kWelcomeFont);
  gl::popModelMatrix();
}

void MainScreen::DrawWelcomeText() const {
  ci::gl::pushModelMatrix();
  ci::gl::translate(width_ / 2, height_ / 3); // middle of window
  ci::gl::drawStringCentered("Welcome to myLeague!", vec2(0, 0), kFontColor, kWelcomeFont);
  ci::gl::drawStringCentered("Press S for Summoner stats and C for Champion stats",
                             vec2(0, 50),
                             kFontColor,
                             kWelcomeFont);
  ci::gl::popModelMatrix();
}
