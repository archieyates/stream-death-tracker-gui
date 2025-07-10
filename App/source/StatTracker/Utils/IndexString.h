#pragma once

#include <string>

struct IndexString
{
  IndexString();
  IndexString(const std::string& string);

  friend bool operator<(const IndexString& a, const IndexString& b)
  {
    return a.m_hash < b.m_hash;
  }

  friend bool operator>(const IndexString& a, const IndexString& b)
  {
    return a.m_hash > b.m_hash;
  }

  friend bool operator==(const IndexString& a, const IndexString& b)
  {
    return a.m_hash == b.m_hash;
  }

  friend bool operator!=(const IndexString& a, const IndexString& b)
  {
    return a.m_hash != b.m_hash;
  }

  IndexString& operator=(const IndexString& string)
  {
    this->m_string = string.m_string;
    this->m_hash = string.m_hash;
    return *this;
  }

  bool isValid() const;
  void set(const std::string& string);
  size_t get();
  void clear();
  const std::string& toString() const;

private:
  std::string m_string{};
  size_t m_hash{0};
};