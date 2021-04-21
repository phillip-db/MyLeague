#include "handler.h"

using namespace myleague;

Handler::Handler(const std::string &api_key,
                           const myleague::Handler::Region &region,
                           const myleague::Handler::Locale &locale) {
  api_key_ = api_key;
  region_ = region;
  locale_ = locale;
}
