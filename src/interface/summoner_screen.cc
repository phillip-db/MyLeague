#include "interface/summoner_screen.h"

using namespace myleague;
using namespace cinder;
using ci::gl::Texture2d;

SummonerScreen::SummonerScreen(float width, float height) : Screen(width, height, Screen::kSummoner) {
  width_ = width;
  height_ = height;
  ReadSummonerName();

  APIHandler h;
  summoner_info_ = h.GetSummonerInfo(summoner_name_);
  ranked_leagues_ = h.GetRankedLeagues(summoner_info_.GetId());
  total_mastery_ = h.GetTotalMasteryScore(summoner_info_.GetId());

  LoadImages();
}

void SummonerScreen::Display() const {
  DrawBasicInfo();
  DrawSoloRankInfo();
}

void SummonerScreen::ReadSummonerName() {
  std::cout << "Enter a summoner name: " << std::endl;
  std::cin >> summoner_name_;
  std::cout << summoner_name_ << std::endl;
}

void SummonerScreen::DrawBasicInfo() const {
  APIHandler h;

  std::string mastery = "Mastery Score: " + total_mastery_;

  float padding = 80;
  float image_size = 200;

  gl::pushModelMatrix();
  gl::translate(width_ / 8, height_ / 8);
  gl::drawString(summoner_name_, vec2(0, 0), kFontColor, kNameFont);
  gl::draw(summoner_icon_, Rectf(vec2(0, padding), vec2(image_size, image_size + padding)));
  gl::drawString(mastery, vec2(0, padding * 2 + image_size), kFontColor, kNameFont);
  gl::popModelMatrix();
}

void SummonerScreen::LoadImages() {
  std::string summoner_url = kIconEndpoint + std::to_string(summoner_info_.GetProfileIconId());
  std::cout << summoner_url << std::endl;
  Surface image(loadImage(loadUrl(summoner_url)));
  summoner_icon_ = Texture2d::create(image);
}

void SummonerScreen::DrawSoloRankInfo() const {
  RankedLeague solo = ranked_leagues_.GetRankedLeague(true);
  std::string rank =
      solo.GetTier() + " " + solo.GetRank() + " "
          + std::to_string(std::round(statisticsanalyzer::ComputeRankedWinrate(solo) * 100)).substr(0, 2)
          + "%";

  gl::pushModelMatrix();
  gl::translate(3 * width_ / 8, height_ / 8);
  gl::drawString(rank, vec2(0, 0), kFontColor, kNameFont);
  gl::popModelMatrix();
}
