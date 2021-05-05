#include "interface/champion_screen.h"

using namespace myleague;

ChampionScreen::ChampionScreen(float width, float height) : Screen(width, height, Screen::kChampion) {
  width_ = width;
  height_ = height;
}

void ChampionScreen::Display() const {}
