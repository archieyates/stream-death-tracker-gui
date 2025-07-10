#pragma once

namespace json
{
  template <typename T>
  ParseResult parseEnum(const nlohmann::json& jsonData, const std::string& field, T& enumOut)
  {
    nlohmann::json fieldData = parseField(jsonData, field);

    if (!fieldData.is_null())
    {
      if (fieldData.is_string())
      {
        std::string typeString = fieldData;
        auto typeMagic = magic_enum::enum_cast<T>(typeString);
        if (typeMagic.has_value())
        {
          enumOut = typeMagic.value();
          return ParseResult::Result_OK;
        }
        else
        {
          return ParseResult::Result_Invalid;
        }
      }
      else
      {
        return ParseResult::Result_Invalid;
      }
    }
    return ParseResult::Result_Unset;
  }

  template <typename T>
  ParseResult parseEnum(const nlohmann::json& jsonData, int index, T& enumOut)
  {
    nlohmann::json fieldData = jsonData.at(index);

    if (!fieldData.is_null())
    {
      if (fieldData.is_string())
      {
        std::string typeString = fieldData;
        auto typeMagic = magic_enum::enum_cast<T>(typeString);
        if (typeMagic.has_value())
        {
          enumOut = typeMagic.value();
          return ParseResult::Result_OK;
        }
        else
        {
          return ParseResult::Result_Invalid;
        }
      }
      else
      {
        return ParseResult::Result_Invalid;
      }
    }
    return ParseResult::Result_Unset;
  }

  template <typename T>
  ParseResult parseVector(const nlohmann::json& jsonData, const std::string& field, std::vector<T>& vecOut)
  {
    nlohmann::json fieldData = parseField(jsonData, field);

    if (!fieldData.is_null())
    {
      if (fieldData.is_array())
      {
        vecOut = fieldData.get<std::vector<T>>();
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