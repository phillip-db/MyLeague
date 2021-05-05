#include "interface/main_screen.h"

using namespace myleague;

MainScreen::MainScreen(float width, float height, const std::string& summoner_name) : Screen(width, height) {
  APIHandler h;
  summoner_info_ = h.GetSummonerInfo(summoner_name);
  ranked_league_container_ = h.GetRankedLeagues(summoner_info_.GetId());
  width_ = width;
  height_ = height;
}

void MainScreen::DrawWelcomeText() const {
  ci::gl::pushModelMatrix();
  ci::gl::translate(width_ / 2, height_ / 4); // middle-top of window
  ci::gl::popModelMatrix();
}
