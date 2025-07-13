#pragma once

#include "nlohmann/json.hpp"

#include "Json/Json.h"
#include "Utils/IndexString.h"
#include "Utils/magic_enum.h"

#include <cassert>

struct Boss
{
  enum class Status : unsigned char
  {
    Undefeated,
    Active,
    Defeated
  };

  IndexString m_name{};
  Status m_status{};
  unsigned short m_deaths{};
};

// https://github.com/nlohmann/json#arbitrary-types-conversions
inline void to_json(nlohmann::json& json, const Boss& boss)
{
  json["Name"] = boss.m_name.toString();
  json["Status"] = magic_enum::enum_name(boss.m_status);
  json["Deaths"] = boss.m_deaths;
}

inline void from_json(const nlohmann::json& json, Boss& boss)
{
  bool valid = (json::parseIndexString(json, "Name", boss.m_name) == json::ParseResult::Result_OK);
  valid &= (json::parseEnum<Boss::Status>(json, "Status", boss.m_status) == json::ParseResult::Result_OK);
  valid &= (json::parseUShort(json, "Deaths", boss.m_deaths) == json::ParseResult::Result_OK);

  assert(valid);
}

inline void to_json(nlohmann::ordered_json& json, const Boss& boss)
{
  json["Name"] = boss.m_name.toString();
  json["Status"] = magic_enum::enum_name(boss.m_status);
  json["Deaths"] = boss.m_deaths;
}

inline void from_json(const nlohmann::ordered_json& json, Boss& boss)
{
  bool valid = (json::parseIndexString(json, "Name", boss.m_name) == json::ParseResult::Result_OK);
  valid &= (json::parseEnum<Boss::Status>(json, "Status", boss.m_status) == json::ParseResult::Result_OK);
  valid &= (json::parseUShort(json, "Deaths", boss.m_deaths) == json::ParseResult::Result_OK);

  assert(valid);
}