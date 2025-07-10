#pragma once

#include "SFML/Window/Event.hpp"

#include "Events.h"
#include "Manager/Manager.h"

#include <vector>

namespace sf
{
  class RenderWindow;
}

class WindowManager : public Manager
{
public:
  void draw();

  bool isOpen() const;
  sf::RenderWindow* getWindow();

  EventNotifier getWindowClosedEvent();
  void forEachWindowEvent(std::function<void(const sf::Event*)> func);
  template <typename TEventSubtype>
  void forEachWindowEventOfType(std::function<void(const TEventSubtype*)> func);
  template <typename TEventSubtype>
  const TEventSubtype* getFirstWindowEventOfType() const;

protected:
  void onInit() override;
  void onPostInit() override;
  void onShutdown() override;
  void onUpdate() override;
  void onPreRender() override;

private:
  EventNotifier m_windowClosedEventNotifier{};
  sf::RenderWindow* m_window{nullptr};

  std::vector<sf::Event> m_windowEventsThisFrame{};
};

#include "WindowManager.inl"