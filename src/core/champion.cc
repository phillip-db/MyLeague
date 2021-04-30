#include "core/champion.h"

using namespace myleague;

Champion::Champion(size_t id,
                   const std::string &name,
                   const std::string &title,
                   const std::string &short_bio,
                   size_t style,
                   size_t difficulty,
                   const std::string &damage_type)
    : id_(id),
      name_(name),
      title_(title),
      short_bio_(short_bio),
      style_(style),
      difficulty_(difficulty),
      damage_type_(damage_type) {}

std::ostream &myleague::operator<<(std::ostream &os, const Champion &champion) {
  os << champion.GetName();
  return os;
}

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

size_t Champion::GetStyle() const {
  return style_;
}

size_t Champion::GetDifficulty() const {
  return difficulty_;
}

const std::string &Champion::GetDamageType() const {
  return damage_type_;
}
