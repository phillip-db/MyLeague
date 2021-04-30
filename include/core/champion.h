#pragma once

#include <string>
#include <vector>
namespace myleague {

class Champion {
 public:
  enum Difficulty {
    Easy,
    Medium,
    Hard
  };

  Champion(size_t id,
           const std::string &name,
           const std::string &title,
           const std::string &short_bio,
           size_t style,
           size_t difficulty,
           const std::string &damage_type);

  friend std::ostream &operator<<(std::ostream &os, const Champion &champion);

  size_t GetId() const;
  const std::string &GetName() const;
  const std::string &GetTitle() const;
  const std::string &GetShortBio() const;
  size_t GetStyle() const;
  size_t GetDifficulty() const;
  const std::string &GetDamageType() const;
  
 private:
  size_t id_;
  std::string name_;
  std::string title_;
  std::string short_bio_;
  size_t style_;
  size_t difficulty_;
  std::string damage_type_;
};

} // namespace myleague

