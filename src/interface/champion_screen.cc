#include "interface/champion_screen.h"

using namespace myleague;
using namespace cinder;

using cinder::gl::Texture2d;

const std::string ChampionScreen::kExit = "Exit";

ChampionScreen::ChampionScreen(float width, float height) : Screen(width, height, Screen::kChampion) {
  width_ = width;
  height_ = height;

  APIHandler h;
  champion_ = h.GetChampion(ReadChampionName());
  champion_bio_ = champion_.SplitBio(8);

  LoadImages();
}

void ChampionScreen::Display() const {
  DrawSplash(width_ / 10, height_ / 8, kSplashWidth);
  DrawChampionInfo(width_ / 10 + kSplashWidth + kPadding / 4, height_ / 8);
  DrawKeybindInfo(width_ / 10 + kSplashWidth + kPadding / 4, 4.5 * height_ / 8);
  DrawChampionList(7 * width_ / 10 + kPadding, height_ / 8);
}

void ChampionScreen::LoadImages() {
  std::string
      splash_url = "https://cdn.communitydragon.org/latest/champion/" + std::to_string(champion_.GetId()) + "/portrait";
  Surface image = loadImage(loadUrl(splash_url));
  champion_splash_ = Texture2d::create(image);
}

void ChampionScreen::DrawSplash(float x, float y, float width) const {
  Rectf img_constraint(0, 0, width, width * kSplashRatio);

  gl::pushModelMatrix();
  gl::translate(x, y);
  gl::draw(champion_splash_, img_constraint);
  gl::popModelMatrix();
}

void ChampionScreen::DrawChampionInfo(float x, float y) const {
  gl::pushModelMatrix();
  
  gl::translate(x, y + height_ / 25);
  gl::drawString(champion_.GetName(), vec2(0, 0), kFontColor, kInfoFontLarge);
  
  gl::translate(0, kPadding / 1.8);
  gl::drawString(champion_.GetTitle(), vec2(0, 0), kFontColor, kInfoFontMed);
  
  gl::translate(0, kPadding / 2);
  for (const std::string &line : champion_bio_) {
    gl::drawString(line, vec2(0, 0), kFontColor, kInfoFontSmall);
    gl::translate(0, kPadding / 5);
  }
  
  gl::popModelMatrix();
}

void ChampionScreen::DrawKeybindInfo(float x, float y) const {
  float line_spacing = kPadding / 1.8;
  
  gl::pushModelMatrix();
  
  gl::translate(x, y);
  gl::drawString("Press Enter to begin inputting champion names.", vec2(0, 0), kFontColor, kKeybindFont);
  
  gl::translate(0, line_spacing);
  gl::drawString(R"(Type "Exit" when done.)",
                 vec2(0, 0),
                 kFontColor,
                 kKeybindFont);
  
  gl::translate(0, line_spacing);
  gl::drawString("Press 1-3 to select by Easy/Medium/Hard.", vec2(0, 0), kFontColor, kKeybindFont);
  
  gl::translate(0, line_spacing);
  gl::drawString("Press S to select by playstyle.", vec2(0, 0), kFontColor, kKeybindFont);
  
  gl::translate(0, line_spacing);
  gl::drawString("Press T to select by damage type.", vec2(0, 0), kFontColor, kKeybindFont);
  
  gl::translate(0, line_spacing);
  gl::drawString("Press R to unfilter | Press C to Clear.", vec2(0, 0), kFontColor, kKeybindFont);
  
  gl::popModelMatrix();
}

std::string ChampionScreen::ReadChampionName() {
  std::string validated_name;
  std::string user_input;
  APIHandler h;
  
  while (validated_name.empty()) {
    std::cout << "Enter a valid champion name: " << std::endl;
    std::cin >> user_input;

    if (user_input == kExit) {
      return user_input;
    }

    validated_name = h.GetChampion(user_input).GetName();
  }

  return validated_name;
}

std::vector<Champion> ChampionScreen::BuildChampionList() {
  std::string user_input;
  std::vector<std::string> champion_names;
  std::vector<Champion> champions;

  user_input = ReadChampionName();
  while (true) {
    if (user_input == kExit) {
      break;
    }
    champion_names.push_back(user_input);
    user_input = ReadChampionName();
  }

  APIHandler h;
  for (const std::string &champion : champion_names) {
    champions.push_back(h.GetChampion(champion));
  }

  return champions;
}

void ChampionScreen::DrawChampionList(float x, float y) const {
  gl::pushModelMatrix();
  
  gl::translate(x - kListSpacing, y);
  gl::drawString("Selected Champions", vec2(0, 0), kFontColor, kInfoFontMed);
  
  gl::translate(0, kPadding / 3);
  for (size_t i = 0; i < champions_.size(); i++) {
    if (i % kNumColumns == 0) { // Draw champion name on left side
      gl::drawString(champions_[i].GetName(),
                     vec2(0, kListSpacing * std::trunc(i / kNumColumns)),
                     kFontColor,
                     kChampListFont);
    } else { // Draw champion name on right side
      gl::drawStringRight(champions_[i].GetName(),
                     vec2(0 + kPadding * 3, kListSpacing * std::trunc(i / kNumColumns)),
                     kFontColor,
                     kChampListFont);
    }
  }
  
  gl::popModelMatrix();
}

void ChampionScreen::SetChampions(const std::vector<Champion> &champions) {
  champions_ = champions;
}
