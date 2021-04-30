#pragma once

#include "api_handler.h"

namespace myleague {

class InputHandler {
 public:
  enum Request {
    Summoner,
    Mastery
  };
  
  InputHandler();
  
  
  
 private:
  APIHandler api_handler_;
};

} // namespace myleague

