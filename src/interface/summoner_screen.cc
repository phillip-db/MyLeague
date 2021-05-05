#include "interface/summoner_screen.h"

using namespace myleague;

SummonerScreen::SummonerScreen(float width, float height) : Screen(width, height, Screen::kSummoner) {
  width_ = width;
  height_ = height;
}

void SummonerScreen::Display() const {}
