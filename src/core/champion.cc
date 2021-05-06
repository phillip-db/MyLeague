#include <sstream>
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

std::vector<std::string> Champion::SplitBio(size_t num_words) const {
  std::istringstream ss(short_bio_);
  std::string word;
  size_t count = 0;
  std::string line;
  std::vector<std::string> split_bio;

  while (ss >> word) { // Using input stream to loop over every word
    count++;
    line += word;
    if (count % num_words == 0) { // Reached max num_words per line
      split_bio.push_back(line);
      line = "";
    } else {
      line += " ";
    }
  }
  split_bio[split_bio.size() - 1] = split_bio.back().append("..."); // Add trailing ellipse to last line

  return split_bio;
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
