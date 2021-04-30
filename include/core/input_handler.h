#pragma once

#include "api_handler.h"

namespace myleague {

class InputHandler {
 public:
  enum Request {
    Summoner,
    Mastery,
    Champion,
    Rank
  };
  
  InputHandler();
  
  void ReadInput(Request request) const;
  
 private:
  APIHandler api_handler_;
};

} // namespace myleague

