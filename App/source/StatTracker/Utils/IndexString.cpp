#include "IndexString.h"

#include <algorithm>
#include <functional>

IndexString::IndexString()
{
  m_hash = 0;
  m_string = std::string();
}

IndexString::IndexString(const std::string& string)
{
  set(string);
}

bool IndexString::isValid() const
{
  return (!m_string.empty() && m_hash != 0);
}

void IndexString::set(const std::string& string)
{
  m_string = string;
  std::transform(m_string.begin(), m_string.end(), m_string.begin(), std::tolower);

  m_hash = std::hash<std::string>{}(m_string);
}

size_t IndexString::get()
{
  return m_hash;
}

void IndexString::clear()
{
  m_string.clear();
  m_hash = 0;
}

const std::string& IndexString::toString() const
{
  return m_string;
}