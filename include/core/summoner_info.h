#pragma once

#include <string>
namespace myleague {

class SummonerInfo {
 public:
  SummonerInfo(const std::string &id,
               const std::string &account_id,
               const std::string &puuid,
               const std::string &name,
               size_t profile_icon_id,
               size_t revision_date,
               size_t summoner_level);
  const std::string &GetId() const;
  const std::string &GetAccountId() const;
  const std::string &GetPuuid() const;
  const std::string &GetName() const;
  size_t GetProfileIconId() const;
  size_t GetRevisionDate() const;
  size_t GetSummonerLevel() const;
 private:
  std::string id_;
  std::string account_id_;
  std::string puuid_;
  std::string name_;
  size_t profile_icon_id_;
  size_t revision_date_;
  size_t summoner_level_;
};

} //namespace myleague