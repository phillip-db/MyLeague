#include "interface/screen.h"

using namespace myleague;
using glm::vec2;

Screen::Screen(float width, float height, ScreenType screen_type)
    : width_(width), height_(height), screen_type_(screen_type) {}

void Screen::Display() const { // Unused in parent class
}

void Screen::SetChampions(const std::vector<Champion> &champions) { // Unused in parent class
}

float Screen::GetWidth() const {
  return width_;
}

float Screen::GetHeight() const {
  return height_;
}

Screen::ScreenType Screen::GetScreenType() const {
  return screen_type_;
}

