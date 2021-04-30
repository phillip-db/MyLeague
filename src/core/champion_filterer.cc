#include "core/champion_filterer.h"

using namespace myleague;

using namespace championfilterer;

std::vector<Champion> SelectByDifficulty(const std::vector<Champion> &champions,
                                                Champion::Difficulty difficulty) {
  std::vector<Champion> selected;
  
  for (const Champion& champion : champions) {
    if (champion.GetDifficulty() == difficulty) {
      selected.push_back(champion);
    }
  }
  
  return selected;
}

std::vector<Champion> SelectByStyle(const std::vector<Champion> &champions, size_t style) {
  std::vector<Champion> selected;

  for (const Champion& champion : champions) {
    if (champion.GetStyle() == style) {
      selected.push_back(champion);
    }
  }

  return selected;
}

std::vector<Champion> SelectByDamageType(const std::vector<Champion> &champions, std::string damage_type) {
  std::vector<Champion> selected;

  for (const Champion& champion : champions) {
    if (champion.GetDamageType() == damage_type) {
      selected.push_back(champion);
    }
  }

  return selected;
}
