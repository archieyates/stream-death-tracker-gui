#pragma once

template <typename TEventSubtype>
const TEventSubtype* WindowManager::getFirstWindowEventOfType() const
{
  for (int i = 0; i < m_windowEventsThisFrame.size(); ++i)
  {
    if (m_windowEventsThisFrame[i].is<TEventSubtype>())
    {
      return m_windowEventsThisFrame[i].getIf<TEventSubtype>();
    }
  }

  return nullptr;
}

template <typename TEventSubtype>
void WindowManager::forEachWindowEventOfType(std::function<void(const TEventSubtype*)> func)
{
  for (int i = 0; i < m_windowEventsThisFrame.size(); ++i)
  {
    if (m_windowEventsThisFrame[i].is<TEventSubtype>())
    {
      func(m_windowEventsThisFrame[i].getIf<TEventSubtype>());
    }
  }
}