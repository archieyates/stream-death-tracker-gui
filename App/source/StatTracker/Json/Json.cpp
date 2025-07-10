#include "Json.h"

#include "Utils/IndexString_json.h"

namespace json
{
  nlohmann::json parseField(const nlohmann::json& jsonData, const std::string& field)
  {
    return jsonData.contains(field.c_str()) ? jsonData[field.c_str()] : nlohmann::json();
  }

  ParseResult parseString(const nlohmann::json& jsonData, const std::string& field, std::string& stringOut)
  {
    nlohmann::json fieldData = parseField(jsonData, field);

    if (!fieldData.is_null())
    {
      if (fieldData.is_string())
      {
        stringOut = fieldData.get<std::string>();
        return ParseResult::Result_OK;
      }
      else
      {
        return ParseResult::Result_Invalid;
      }
    }
    return ParseResult::Result_Unset;
  }

  ParseResult parseString(const nlohmann::json& jsonData, int index, std::string& stringOut)
  {
    nlohmann::json fieldData = jsonData.at(index);

    if (!fieldData.is_null())
    {
      if (fieldData.is_string())
      {
        stringOut = fieldData.get<std::string>();
        return ParseResult::Result_OK;
      }
      else
      {
        return ParseResult::Result_Invalid;
      }
    }
    return ParseResult::Result_Unset;
  }

  ParseResult parseIndexString(const nlohmann::json& jsonData, const std::string& field, IndexString& stringOut)
  {
    nlohmann::json fieldData = parseField(jsonData, field);

    if (!fieldData.is_null())
    {
      if (fieldData.is_string())
      {
        stringOut = fieldData.get<IndexString>();
        return ParseResult::Result_OK;
      }
      else
      {
        return ParseResult::Result_Invalid;
      }
    }
    return ParseResult::Result_Unset;
  }

  ParseResult parseIndexString(const nlohmann::json& jsonData, int index, IndexString& stringOut)
  {
    nlohmann::json fieldData = jsonData.at(index);

    if (!fieldData.is_null())
    {
      if (fieldData.is_string())
      {
        stringOut = fieldData.get<IndexString>();
        return ParseResult::Result_OK;
      }
      else
      {
        return ParseResult::Result_Invalid;
      }
    }
    return ParseResult::Result_Unset;
  }

  ParseResult parseFloat(const nlohmann::json& jsonData, const std::string& field, float& floatOut)
  {
    nlohmann::json fieldData = parseField(jsonData, field);

    if (!fieldData.is_null())
    {
      if (fieldData.is_number())
      {
        floatOut = fieldData.get<float>();
        return ParseResult::Result_OK;
      }
      else
      {
        return ParseResult::Result_Invalid;
      }
    }
    return ParseResult::Result_Unset;
  }

  ParseResult parseFloat(const nlohmann::json& jsonData, int index, float& floatOut)
  {
    nlohmann::json fieldData = jsonData.at(index);

    if (!fieldData.is_null())
    {
      if (fieldData.is_number())
      {
        floatOut = fieldData.get<float>();
        return ParseResult::Result_OK;
      }
      else
      {
        return ParseResult::Result_Invalid;
      }
    }
    return ParseResult::Result_Unset;
  }

  ParseResult parseUChar(const nlohmann::json& jsonData, const std::string& field, unsigned char& uCharOut)
  {
    nlohmann::json fieldData = parseField(jsonData, field);

    if (!fieldData.is_null())
    {
      if (fieldData.is_number())
      {
        uCharOut = fieldData.get<unsigned char>();
        return ParseResult::Result_OK;
      }
      else
      {
        return ParseResult::Result_Invalid;
      }
    }
    return ParseResult::Result_Unset;
  }

  ParseResult parseUChar(const nlohmann::json& jsonData, int index, unsigned char& uCharOut)
  {
    nlohmann::json fieldData = jsonData.at(index);

    if (!fieldData.is_null())
    {
      if (fieldData.is_number())
      {
        uCharOut = fieldData.get<unsigned char>();
        return ParseResult::Result_OK;
      }
      else
      {
        return ParseResult::Result_Invalid;
      }
    }
    return ParseResult::Result_Unset;
  }
} // namespace json