#pragma once

#include <string>
namespace myleague {

class RankedLeague {
 public:
  RankedLeague(const std::string &league_id,
               const std::string &queue_type,
               const std::string &tier,
               const std::string &rank,
               const std::string &summoner_id,
               const std::string &summoner_name,
               size_t league_points,
               size_t wins,
               size_t losses,
               bool veteran,
               bool inactive,
               bool fresh_blood,
               bool hot_streak);
  
  const std::string &GetLeagueId() const;
  const std::string &GetQueueType() const;
  const std::string &GetTier() const;
  const std::string &GetRank() const;
  const std::string &GetSummonerId() const;
  const std::string &GetSummonerName() const;
  size_t GetLeaguePoints() const;
  size_t GetWins() const;
  size_t GetLosses() const;
  bool IsVeteran() const;
  bool IsInactive() const;
  bool IsFreshBlood() const;
  bool IsHotStreak() const;
 private:
  std::string league_id_;
  std::string queue_type_;
  std::string tier_;
  std::string rank_;
  std::string summoner_id_;
  std::string summoner_name_;
  size_t league_points_;
  size_t wins_;
  size_t losses_;
  bool veteran_;
  bool inactive_;
  bool fresh_blood_;
  bool hot_streak_;
};

} // namespace myleague

