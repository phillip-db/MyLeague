#pragma once

#include <string>
namespace myleague {

class Champion {
 public:

 private:
 public:
  Champion(size_t id, const std::string &name, const std::string &title, const std::string &short_bio);
  size_t GetId() const;
  const std::string &GetName() const;
  const std::string &GetTitle() const;
  const std::string &GetShortBio() const;
 private:
  size_t id_;
  std::string name_;
  std::string title_;
  std::string short_bio_;
};

} // namespace myleague

