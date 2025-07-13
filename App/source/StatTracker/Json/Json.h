// Helper functions for parsing json files
#pragma once

#include "nlohmann/json.hpp"

#include "Utils/IndexString.h"
#include "Utils/magic_enum.h"

#include <vector>

namespace json
{
  enum class ParseResult : unsigned char
  {
    Result_OK,
    Result_Unset,
    Result_Invalid
  };

  extern nlohmann::json parseField(const nlohmann::json& actionData, const std::string& field);

  extern ParseResult parseString(const nlohmann::json& jsonData, const std::string& field, std::string& stringOut);
  extern ParseResult parseString(const nlohmann::json& jsonData, int index, std::string& stringOut);

  extern ParseResult parseIndexString(const nlohmann::json& jsonData, const std::string& field, IndexString& stringOut);
  extern ParseResult parseIndexString(const nlohmann::json& jsonData, int index, IndexString& stringOut);

  extern ParseResult parseFloat(const nlohmann::json& jsonData, const std::string& field, float& floatOut);
  extern ParseResult parseFloat(const nlohmann::json& jsonData, int index, float& floatOut);

  extern ParseResult parseUChar(const nlohmann::json& jsonData, const std::string& field, unsigned char& uCharOut);
  extern ParseResult parseUChar(const nlohmann::json& jsonData, int index, unsigned char& uCharOut);

  extern ParseResult parseUShort(const nlohmann::json& jsonData, const std::string& field, unsigned short& uShortOut);
  extern ParseResult parseUShort(const nlohmann::json& jsonData, int index, unsigned short& uShortOut);

  template <typename T>
  extern ParseResult parseEnum(const nlohmann::json& jsonData, const std::string& field, T& enumOut);
  template <typename T>
  extern ParseResult parseEnum(const nlohmann::json& jsonData, int index, T& enumOut);

  template <typename T>
  extern ParseResult parseVector(const nlohmann::json& jsonData, const std::string& field, std::vector<T>& vecOut);

} // namespace json

#include "json.inl"