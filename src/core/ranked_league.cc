#include "core/ranked_league.h"

using namespace myleague;

RankedLeague::RankedLeague(const std::string &league_id,
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
                           bool hot_streak)
    : league_id_(league_id),
      queue_type_(queue_type),
      tier_(tier),
      rank_(rank),
      summoner_id_(summoner_id),
      summoner_name_(summoner_name),
      league_points_(league_points),
      wins_(wins),
      losses_(losses),
      veteran_(veteran),
      inactive_(inactive),
      fresh_blood_(fresh_blood),
      hot_streak_(hot_streak) {}
      
const std::string &RankedLeague::GetLeagueId() const {
  return league_id_;
}

const std::string &RankedLeague::GetQueueType() const {
  return queue_type_;
}

const std::string &RankedLeague::GetTier() const {
  return tier_;
}

const std::string &RankedLeague::GetRank() const {
  return rank_;
}

const std::string &RankedLeague::GetSummonerId() const {
  return summoner_id_;
}

const std::string &RankedLeague::GetSummonerName() const {
  return summoner_name_;
}

size_t RankedLeague::GetLeaguePoints() const {
  return league_points_;
}

size_t RankedLeague::GetWins() const {
  return wins_;
}

size_t RankedLeague::GetLosses() const {
  return losses_;
}

bool RankedLeague::IsVeteran() const {
  return veteran_;
}

bool RankedLeague::IsInactive() const {
  return inactive_;
}

bool RankedLeague::IsFreshBlood() const {
  return fresh_blood_;
}

bool RankedLeague::IsHotStreak() const {
  return hot_streak_;
}
