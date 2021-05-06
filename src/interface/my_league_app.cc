#include "interface/my_league_app.h"

using namespace myleague;
using namespace cinder;

using glm::vec2;
using ci::app::KeyEvent;

MyLeagueApp::MyLeagueApp() {
  ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
  ResetApp();
}

void MyLeagueApp::draw() {
  ci::gl::clear(kBackgroundColor);
  DrawTitle();
  screen_->Display();
}

void MyLeagueApp::DrawTitle() const {
  ci::gl::pushModelMatrix();
  ci::gl::translate(kWindowWidth / 2 + 20, kWindowHeight / 20);
  ci::gl::drawStringCentered("myLeague", vec2(0, 0), kTitleColor, ci::Font("Arial", 30));
  ci::gl::translate(-kWindowWidth / 10, -12.5);
  gl::draw(texture_, Rectf(0, 0, 50, 50));
  ci::gl::popModelMatrix();
}

void MyLeagueApp::setup() {
  Surface surface(loadImage("data/images/icon.png"));
  texture_ = gl::Texture2d::create(surface);
}

void MyLeagueApp::ResetApp() {
  auto *main = new MainScreen(kWindowWidth, kWindowHeight);
  screen_ = main;
}

void MyLeagueApp::keyDown(KeyEvent event) {
  switch (screen_->GetScreenType()) {
    case Screen::kMain:
      if (event.getCode() == KeyEvent::KEY_s) {
        auto *summoner = new SummonerScreen(kWindowWidth, kWindowHeight);
        screen_ = summoner;
      } else if (event.getCode() == KeyEvent::KEY_c) {
        auto *champion = new ChampionScreen(kWindowWidth, kWindowHeight);
        screen_ = champion;
        screen_->SetChampions(champions_);
      } else if (event.getCode() == KeyEvent::KEY_ESCAPE) {
        quit();
      }
      break;
    case Screen::kSummoner:
      if (event.getCode() == KeyEvent::KEY_ESCAPE) {
        auto *main = new MainScreen(kWindowWidth, kWindowHeight);
        screen_ = main;
      }
      break;
    case Screen::kChampion:
      if (event.getCode() == KeyEvent::KEY_ESCAPE) {
        auto *main = new MainScreen(kWindowWidth, kWindowHeight);
        screen_ = main;
      } else if (event.getCode() == KeyEvent::KEY_RETURN) {
        std::vector<Champion> champions(ChampionScreen::BuildChampionList());
        
        for(const Champion& champion : champions) {
          champions_.push_back(champion);
        }
        
        screen_->SetChampions(champions_);
      } else if (event.getCode() == KeyEvent::KEY_1) {
        screen_->SetChampions(championfilterer::SelectByDifficulty(champions_, Champion::kEasy));
      } else if (event.getCode() == KeyEvent::KEY_2) {
        screen_->SetChampions(championfilterer::SelectByDifficulty(champions_, Champion::kMedium));
      } else if (event.getCode() == KeyEvent::KEY_3) {
        screen_->SetChampions(championfilterer::SelectByDifficulty(champions_, Champion::kHard));
      } else if (event.getCode() == KeyEvent::KEY_s) {
        size_t style;
        std::cout << "Enter a number 1 - 10: " << std::endl;
        std::cin >> style;
        screen_->SetChampions(championfilterer::SelectByStyle(champions_, style));
      } else if (event.getCode() == KeyEvent::KEY_t) {
        std::string type;
        std::cout << "Enter a damage type (kPhysical/kMixed/kMagic): " << std::endl;
        std::cin >> type;
        screen_->SetChampions(championfilterer::SelectByDamageType(champions_, type));
      } else if (event.getCode() == KeyEvent::KEY_r) {
        screen_->SetChampions(champions_);
      } else if (event.getCode() == KeyEvent::KEY_c) {
        champions_ = std::vector<Champion>();
        screen_->SetChampions(champions_);
      }
      break;
  }
}
