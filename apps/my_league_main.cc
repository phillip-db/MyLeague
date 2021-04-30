#include "core/api_handler.h"
#include "core/input_handler.h"

#include <fstream>
#include <iostream>

using namespace myleague;

using json = nlohmann::json;

int main() {
  InputHandler h;
  
  h.ReadInput(InputHandler::Summoner);
  h.ReadInput(InputHandler::Mastery);
  h.ReadInput(InputHandler::Rank);
  h.ReadInput(InputHandler::Champion);
  return 0;
}
