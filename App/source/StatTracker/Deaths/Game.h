#pragma once

#include "Deaths/Playthrough.h"

struct Game
{
  IndexString m_name{};
  unsigned short m_deaths{};
  std::map<IndexString, Playthrough> m_playthroughs{};
};

// https://github.com/nlohmann/json#arbitrary-types-conversions
inline void to_json(nlohmann::json& json, const Game& game)
{
  json["Name"] = game.m_name.toString();

  for (auto it = game.m_playthroughs.begin(); it != game.m_playthroughs.end(); ++it)
  {
    json["Playthroughs"].push_back(it->second);
  }
}

inline void from_json(const nlohmann::json& json, Game& game)
{
  bool valid = (json::parseIndexString(json, "Name", game.m_name) == json::ParseResult::Result_OK);

  game.m_deaths = 0;

  std::vector<Playthrough> playthroughs;
  json::ParseResult result = json::parseVector<Playthrough>(json, "Playthroughs", playthroughs);
  valid &= result != json::ParseResult::Result_Invalid;
  if (result == json::ParseResult::Result_OK)
  {
    for (size_t i = 0; i < playthroughs.size(); ++i)
    {
      game.m_playthroughs[playthroughs[i].m_name] = playthroughs[i];
      game.m_deaths += playthroughs[i].m_deaths;
    }
  }

  assert(valid);
}

inline void to_json(nlohmann::ordered_json& json, const Game& game)
{
  json["Name"] = game.m_name.toString();

  for (auto it = game.m_playthroughs.begin(); it != game.m_playthroughs.end(); ++it)
  {
    json["Playthroughs"].push_back(it->second);
  }
}

inline void from_json(const nlohmann::ordered_json& json, Game& game)
{
  bool valid = (json::parseIndexString(json, "Name", game.m_name) == json::ParseResult::Result_OK);

  game.m_deaths = 0;

  std::vector<Playthrough> playthroughs;
  json::ParseResult result = json::parseVector<Playthrough>(json, "Playthroughs", playthroughs);
  valid &= result != json::ParseResult::Result_Invalid;
  if (result == json::ParseResult::Result_OK)
  {
    for (size_t i = 0; i < playthroughs.size(); ++i)
    {
      game.m_playthroughs[playthroughs[i].m_name] = playthroughs[i];
      game.m_deaths += playthroughs[i].m_deaths;
    }
  }

  assert(valid);
}