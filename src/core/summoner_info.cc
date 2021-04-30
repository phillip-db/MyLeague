#include "core/summoner_info.h"

using namespace myleague;

SummonerInfo::SummonerInfo(const std::string &id,
                           const std::string &account_id,
                           const std::string &puuid,
                           const std::string &name,
                           size_t profile_icon_id,
                           size_t revision_date,
                           size_t summoner_level)
    : id_(id),
      account_id_(account_id),
      puuid_(puuid),
      name_(name),
      profile_icon_id_(profile_icon_id),
      revision_date_(revision_date),
      summoner_level_(summoner_level) {}
      
const std::string &SummonerInfo::GetId() const {
  return id_;
}

const std::string &SummonerInfo::GetAccountId() const {
  return account_id_;
}

const std::string &SummonerInfo::GetPuuid() const {
  return puuid_;
}

const std::string &SummonerInfo::GetName() const {
  return name_;
}

size_t SummonerInfo::GetProfileIconId() const {
  return profile_icon_id_;
}

size_t SummonerInfo::GetRevisionDate() const {
  return revision_date_;
}

size_t SummonerInfo::GetSummonerLevel() const {
  return summoner_level_;
}
