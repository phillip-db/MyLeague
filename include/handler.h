#pragma once

#include <string>
namespace myleague {

class Handler {
 public:
  enum Region {
    NA
  };
  
  enum Locale {
    en_US
  };
  
  explicit Handler(const std::string& api_key, const Region& region = NA, const Locale& locale = en_US);
  
 private:
  std::string api_key_;
  Region region_;
  Locale locale_;
};

} // 