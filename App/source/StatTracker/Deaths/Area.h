#pragma once

#include "Deaths/Boss.h"

struct Area
{
  IndexString m_name{};

  // Deaths including bosses
  unsigned short m_inclusiveDeaths{0};
  // Deaths excluding bosses
  unsigned short m_exclusiveDeaths{0};

  std::map<IndexString, Boss> m_bosses{};
};

// https://github.com/nlohmann/json#arbitrary-types-conversions
inline void to_json(nlohmann::json& json, const Area& area)
{
  json["Name"] = area.m_name.toString();
  json["Deaths"] = area.m_exclusiveDeaths;

  for (auto it = area.m_bosses.begin(); it != area.m_bosses.end(); ++it)
  {
    json["Bosses"].push_back(it->second);
  }
}

inline void from_json(const nlohmann::json& json, Area& area)
{
  bool valid = (json::parseIndexString(json, "Name", area.m_name) == json::ParseResult::Result_OK);

  valid &= (json::parseUShort(json, "Deaths", area.m_exclusiveDeaths) == json::ParseResult::Result_OK);

  area.m_inclusiveDeaths = area.m_exclusiveDeaths;

  std::vector<Boss> bosses;
  json::ParseResult result = json::parseVector<Boss>(json, "Bosses", bosses);
  valid &= result != json::ParseResult::Result_Invalid;
  if (result == json::ParseResult::Result_OK)
  {
    for (size_t i = 0; i < bosses.size(); ++i)
    {
      area.m_bosses[bosses[i].m_name] = bosses[i];
      area.m_inclusiveDeaths += bosses[i].m_deaths;
    }
  }

  assert(valid);
}

inline void to_json(nlohmann::ordered_json& json, const Area& area)
{
  json["Name"] = area.m_name.toString();
  json["Deaths"] = area.m_exclusiveDeaths;

  for (auto it = area.m_bosses.begin(); it != area.m_bosses.end(); ++it)
  {
    json["Bosses"].push_back(it->second);
  }
}

inline void from_json(const nlohmann::ordered_json& json, Area& area)
{
  bool valid = (json::parseIndexString(json, "Name", area.m_name) == json::ParseResult::Result_OK);

  valid &= (json::parseUShort(json, "Deaths", area.m_exclusiveDeaths) == json::ParseResult::Result_OK);

  area.m_inclusiveDeaths = area.m_exclusiveDeaths;

  std::vector<Boss> bosses;
  json::ParseResult result = json::parseVector<Boss>(json, "Bosses", bosses);
  valid &= result != json::ParseResult::Result_Invalid;
  if (result == json::ParseResult::Result_OK)
  {
    for (size_t i = 0; i < bosses.size(); ++i)
    {
      area.m_bosses[bosses[i].m_name] = bosses[i];
      area.m_inclusiveDeaths += bosses[i].m_deaths;
    }
  }

  assert(valid);
}