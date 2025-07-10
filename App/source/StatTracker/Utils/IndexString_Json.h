#pragma once

#include "nlohmann/json.hpp"

#include "Utils/IndexString.h"

// https://github.com/nlohmann/json#arbitrary-types-conversions
inline void to_json(nlohmann::json& json, const IndexString& string)
{
  json = string.toString();
}

inline void from_json(const nlohmann::json& json, IndexString& string)
{
  std::string stringLit = json.get<std::string>();
  string.set(stringLit);
}

inline void to_json(nlohmann::ordered_json& json, const IndexString& string)
{
  json = string.toString();
}

inline void from_json(const nlohmann::ordered_json& json, IndexString& string)
{
  std::string stringLit = json.get<std::string>();
  string.set(stringLit);
}