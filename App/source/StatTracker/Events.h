#pragma once

#include <cassert>
#include <functional>
#include <vector>

struct EventData
{
};

struct EventHandle
{
  friend class EventNotifier;
  template <typename T>
  friend class EventDispatcher;

  EventHandle()
  {
    m_index = UINT_MAX;
  }

  ~EventHandle()
  {
    assert(m_index == UINT_MAX);
  }

  bool isBound()
  {
    return m_index != UINT_MAX;
  }

private:
  EventHandle(size_t index)
  {
    m_index = index;
  }

  size_t m_index{UINT_MAX};
};

class EventNotifier
{
public:
  ~EventNotifier()
  {
    m_subs.clear();
  }

  void subscribe(EventHandle& hndl, std::function<void(void)> func)
  {
    assert(hndl.m_index == UINT_MAX);

    for (size_t i = 0; i < m_subs.size(); ++i)
    {
      if (m_subs[i] == nullptr)
      {
        m_subs[i] = func;
        hndl.m_index = i;
      }
    }

    m_subs.push_back(func);
    hndl.m_index = (m_subs.size() - 1);
  }

  void unsubscribe(EventHandle& hndl)
  {
    if (hndl.m_index < m_subs.size())
    {
      m_subs[hndl.m_index] = {};
      hndl.m_index = UINT_MAX;
    }
  }

  void notify() const
  {
    for (size_t i = 0; i < m_subs.size(); ++i)
    {
      if (m_subs[i] != nullptr)
      {
        m_subs[i]();
      }
    }
  }

  std::vector<std::function<void(void)>> m_subs;
};

template <typename T>
class EventDispatcher
{
  static_assert(std::is_base_of<EventData, T>::value, "T must derive from EventData");

public:
  ~EventDispatcher()
  {
    for (size_t i = 0; i < m_subs.size(); ++i)
    {
      assert(m_subs[i] == nullptr);
    }
    m_subs.clear();
  }

  void subscribe(EventHandle& hndl, std::function<void(const T&)> func)
  {
    assert(hndl.m_index == UINT_MAX);

    for (size_t i = 0; i < m_subs.size(); ++i)
    {
      if (m_subs[i] == nullptr)
      {
        m_subs[i] = func;
        hndl.m_index = i;
        return;
      }
    }

    m_subs.push_back(func);
    hndl.m_index = (m_subs.size() - 1);
  }

  void unsubscribe(EventHandle& hndl)
  {
    if (hndl.m_index < m_subs.size())
    {
      m_subs[hndl.m_index] = {};
      hndl.m_index = UINT_MAX;
    }
  }

  void dispatch(const T& data) const
  {
    for (size_t i = 0; i < m_subs.size(); ++i)
    {
      if (m_subs[i] != nullptr)
      {
        m_subs[i](data);
      }
    }
  }

  std::vector<std::function<void(const T&)>> m_subs;
};