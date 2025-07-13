#include "WindowManager.h"

#include "SFML/Graphics/RenderWindow.hpp"

#include "App.h"
#include "Utils/magic_enum.h"

void WindowManager::draw()
{
  m_window->display();
}

bool WindowManager::isOpen() const
{
  return m_window->isOpen();
}

sf::RenderWindow* WindowManager::getWindow()
{
  return m_window;
}

EventNotifier WindowManager::getWindowClosedEvent()
{
  return m_windowClosedEventNotifier;
}

void WindowManager::forEachWindowEvent(std::function<void(const sf::Event*)> func)
{
  for (size_t i = 0; i < m_windowEventsThisFrame.size(); ++i)
  {
    func(&m_windowEventsThisFrame[i]);
  }
}

void WindowManager::onInit()
{
  m_window = new sf::RenderWindow(sf::VideoMode({1920, 1080}), "Stream Death Tracker");
  m_window->setVerticalSyncEnabled(true);

  m_windowEventsThisFrame.reserve(64);
}

void WindowManager::onPostInit()
{
}

void WindowManager::onShutdown()
{
  m_windowEventsThisFrame.clear();

  if (m_window != nullptr)
  {
    delete m_window;
    m_window = nullptr;
  }
}

void WindowManager::onUpdate()
{
  m_windowEventsThisFrame.clear();

  while (const std::optional<sf::Event> event = m_window->pollEvent())
  {
    m_windowEventsThisFrame.push_back(*event);

    if (event->is<sf::Event::Closed>())
    {
      m_windowClosedEventNotifier.notify();
      m_window->close();

      return;
    }
  }
}

void WindowManager::onPreRender()
{
  m_window->clear(sf::Color(18, 33, 43));
}