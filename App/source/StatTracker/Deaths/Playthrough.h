#pragma once

#include "Deaths/Area.h"

struct Playthrough
{
  enum class Status : unsigned char
  {
    InProgress,
    Active,
    Completed
  };

  IndexString m_name{};
  Status m_status{};
  unsigned short m_deaths{0};
  std::map<IndexString, Area> m_areas{};
};

// https://github.com/nlohmann/json#arbitrary-types-conversions
inline void to_json(nlohmann::json& json, const Playthrough& playthrough)
{
  json["Name"] = playthrough.m_name.toString();
  json["Status"] = magic_enum::enum_name(playthrough.m_status);

  for (auto it = playthrough.m_areas.begin(); it != playthrough.m_areas.end(); ++it)
  {
    json["Areas"].push_back(it->second);
  }
}

inline void from_json(const nlohmann::json& json, Playthrough& playthrough)
{
  bool valid = (json::parseIndexString(json, "Name", playthrough.m_name) == json::ParseResult::Result_OK);
  valid &= (json::parseEnum<Playthrough::Status>(json, "Status", playthrough.m_status) == json::ParseResult::Result_OK);

  playthrough.m_deaths = 0;

  std::vector<Area> areas;
  json::ParseResult result = json::parseVector<Area>(json, "Areas", areas);
  valid &= result != json::ParseResult::Result_Invalid;
  if (result == json::ParseResult::Result_OK)
  {
    for (size_t i = 0; i < areas.size(); ++i)
    {
      playthrough.m_areas[areas[i].m_name] = areas[i];
      playthrough.m_deaths += areas[i].m_inclusiveDeaths;
    }
  }

  assert(valid);
}

inline void to_json(nlohmann::ordered_json& json, const Playthrough& playthrough)
{
  json["Name"] = playthrough.m_name.toString();
  json["Status"] = magic_enum::enum_name(playthrough.m_status);

  for (auto it = playthrough.m_areas.begin(); it != playthrough.m_areas.end(); ++it)
  {
    json["Areas"].push_back(it->second);
  }
}

inline void from_json(const nlohmann::ordered_json& json, Playthrough& playthrough)
{
  bool valid = (json::parseIndexString(json, "Name", playthrough.m_name) == json::ParseResult::Result_OK);
  valid &= (json::parseEnum<Playthrough::Status>(json, "Status", playthrough.m_status) == json::ParseResult::Result_OK);

  playthrough.m_deaths = 0;

  std::vector<Area> areas;
  json::ParseResult result = json::parseVector<Area>(json, "Areas", areas);
  valid &= result != json::ParseResult::Result_Invalid;
  if (result == json::ParseResult::Result_OK)
  {
    for (size_t i = 0; i < areas.size(); ++i)
    {
      playthrough.m_areas[areas[i].m_name] = areas[i];
      playthrough.m_deaths += areas[i].m_inclusiveDeaths;
    }
  }

  assert(valid);
}