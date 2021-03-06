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
  gl::pushModelMatrix();
  gl::translate(0, height_ / 10);
  
  DrawBasicInfo();
  DrawRankInfo(true, vec2(3 * width_ / 8, height_ / 8));
  DrawRankInfo(false, vec2(3 * width_ / 8, 4 * height_ / 8));

  gl::popModelMatrix();
}

void SummonerScreen::ReadSummonerName() {
  std::string validated_id;
  APIHandler h;

  while (validated_id.empty()) { // Continues prompted until valid summoner name provided
    std::cout << "Enter a valid summoner name: " << std::endl;
    std::cin >> summoner_name_;

    validated_id = h.GetSummonerInfo(summoner_name_).GetId();
  }
}

void SummonerScreen::DrawBasicInfo() const {
  APIHandler h;

  std::string mastery = "Mastery Score: " + total_mastery_;
  std::string level = "Level " + std::to_string(summoner_info_.GetSummonerLevel());

  gl::pushModelMatrix();
  gl::translate(width_ / 10, height_ / 8);

  gl::drawStringCentered(summoner_info_.GetName(), vec2(kImgSize / 2, 0), kFontColor, kNameFont);
  gl::draw(summoner_icon_, Rectf(vec2(0, kPadding), vec2(kImgSize, kImgSize + kPadding)));
  gl::drawString(mastery, vec2(0, kPadding * 2 + kImgSize), kFontColor, kRankFont);
  gl::drawString(level, vec2(0, kPadding * 1.5 + kImgSize), kFontColor, kRankFont);

  gl::popModelMatrix();
}

void SummonerScreen::LoadImages() {
  std::string summoner_url = kIconEndpoint + std::to_string(summoner_info_.GetProfileIconId());
  Surface image(loadImage(loadUrl(summoner_url)));
  summoner_icon_ = Texture2d::create(image);

  RankedLeague solo = ranked_leagues_.GetRankedLeague(true);
  RankedLeague flex = ranked_leagues_.GetRankedLeague(false);

  std::string solo_url = kRankIconEndpoint + RankedLeague::CapitalizeFirst(solo.GetTier()) + "_1.png";

  if (solo.GetTier().empty()) {
    solo_url = kDefaultRankUrl;
  }

  image = loadImage(loadUrl(solo_url));
  ranked_solo_icon_ = Texture2d::create(image);

  std::string flex_url = kRankIconEndpoint + RankedLeague::CapitalizeFirst(flex.GetTier()) + "_1.png";

  if (flex.GetTier().empty()) {
    flex_url = kDefaultRankUrl;
  }

  image = loadImage(loadUrl(flex_url));
  ranked_flex_icon_ = Texture2d::create(image);
}

void SummonerScreen::DrawRankInfo(bool is_solo, const vec2 &translation) const {
  RankedLeague ranked_league = ranked_leagues_.GetRankedLeague(is_solo);

  std::string rank =
      ranked_league.GetTier() + " " + ranked_league.GetRank() + " "
          + std::to_string(std::round(statisticsanalyzer::ComputeRankedWinrate(ranked_league) * 100)).substr(0, 2)
          + "%"; // String including tier, rank, and win%
  std::string lp = std::to_string(ranked_league.GetLeaguePoints()) + " LP";
  std::string num_games = std::to_string(ranked_league.GetWins() + ranked_league.GetLosses());

  Rectf img_constraint = Rectf(width_ / 2.5, 0, width_ / 2.5 + kImgSize, kImgSize);

  gl::pushModelMatrix();
  gl::translate(translation.x, translation.y);

  if (is_solo) {
    gl::drawString("Solo/Duo Queue", vec2(0, 0), kFontColor, kNameFont);
    gl::draw(ranked_solo_icon_, img_constraint);
  } else {
    gl::drawString("Flex Queue", vec2(0, 0), kFontColor, kNameFont);
    gl::draw(ranked_flex_icon_, img_constraint);
  }

  gl::drawString(rank, vec2(0, kPadding), kFontColor, kNameFont);
  gl::drawString(lp + " | " + num_games + " Games", vec2(0, kPadding * 2), kFontColor, kNameFont);

  gl::popModelMatrix();
}