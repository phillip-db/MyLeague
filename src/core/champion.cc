#include "core/champion.h"

using namespace myleague;

Champion::Champion(size_t id, const std::string &name, const std::string &title, const std::string &short_bio)
    : id_(id), name_(name), title_(title), short_bio_(short_bio) {}

size_t Champion::GetId() const {
  return id_;
}

const std::string &Champion::GetName() const {
  return name_;
}

const std::string &Champion::GetTitle() const {
  return title_;
}

const std::string &Champion::GetShortBio() const {
  return short_bio_;
}
