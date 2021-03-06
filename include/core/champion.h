#pragma once

#include <string>
#include <vector>

namespace myleague {

/**
 * Stores various information about a Champion
 */
class Champion {
 public:
  /**
   * An enum to represent the three difficulties a Champion falls under
   */
  enum Difficulty {
    kEasy,
    kMedium,
    kHard
  };

  Champion() = default;

  Champion(size_t id,
           const std::string &name,
           const std::string &title,
           const std::string &short_bio,
           size_t style,
           size_t difficulty,
           const std::string &damage_type);

  /**
   * Overload output stream operator to output champion name only
   * @param os The output stream
   * @param champion The champion object to feed into the output stream
   * @return an output stream of only the champion's name
   */
  friend std::ostream &operator<<(std::ostream &os, const Champion &champion);

  /**
   * Splits the Champion shortbio into multiple lines
   * @param num_words The maximum number of words per line
   * @return the shortbio separated by lines as a vector
   */
  std::vector<std::string> SplitBio(size_t num_words) const;

  size_t GetId() const;
  const std::string &GetName() const;
  const std::string &GetTitle() const;
  const std::string &GetShortBio() const;
  size_t GetStyle() const;
  size_t GetDifficulty() const;
  const std::string &GetDamageType() const;

 private:
  static const std::string kAll;
  static const std::string kExit;

  size_t id_{};
  std::string name_;
  std::string title_;
  std::string short_bio_;
  size_t style_{}; // What playstyle the champion falls under, represented as a number
  size_t difficulty_{};
  std::string damage_type_;
};

} // namespace myleague

