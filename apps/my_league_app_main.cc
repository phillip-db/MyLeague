#include <interface/my_league_app.h>

using myleague::MyLeagueApp;

void prepareSettings(MyLeagueApp::Settings *settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(MyLeagueApp, ci::app::RendererGl, prepareSettings);