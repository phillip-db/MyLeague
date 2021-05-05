#include "interface/screen.h"

using namespace myleague;
using glm::vec2;

Screen::Screen(float width, float height) : width_(width), height_(height) {}

void Screen::DrawButton(float x,
                             float y,
                             const cinder::Color &color,
                             const std::string &label,
                             float size) const {
  ci::gl::color(color);
  ci::gl::pushModelMatrix();
  ci::gl::translate(x - size / 2, y - size / 2);
  ci::gl::drawSolidRoundedRect(cinder::Rectf(0, 0, 0 + size, 0 + size), 10, 10);
  ci::gl::drawStringCentered(label, vec2(0 + size / 2, 0 + size / 2), ci::Color("White"), kButtonFont);
  ci::gl::popModelMatrix();
}

