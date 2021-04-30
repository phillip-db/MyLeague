#pragma once

#include "api_handler.h"

namespace myleague {

/**
 * Class that handles user input from the console for the various API requests
 */
class InputHandler {
 public:
  /**
   * Enum representing the various API requests a user can make
   */
  enum Request {
    Summoner,
    Mastery,
    Champion,
    Rank
  };
  
  InputHandler();
  
  /**
   * Read user input from console and call the appropriate API method
   * @param request The type of request to execute
   */
  void ReadInput(Request request) const;
  
 private:
  APIHandler api_handler_;
};

} // namespace myleague

