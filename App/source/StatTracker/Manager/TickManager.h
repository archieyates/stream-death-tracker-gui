#pragma once

#include "SFML/System/Time.hpp"

#include "Manager/Manager.h"

#define TRACKED_TICK_COUNT 60

namespace sf
{
  class Clock;
}

class TickManager : public Manager
{
public:
  sf::Time getTime() const;
  sf::Time getLastTime() const;
  float getDeltaTime() const;
  float getLastDeltaTime() const;

  unsigned short getFramesThisSecond() const;
  unsigned short getFramesLastSecond() const;
  unsigned short getAverageFPS() const;

protected:
  void onInit() override;
  void onShutdown() override;
  void onUpdate() override;

private:
  void updateAverageFPS();

  sf::Clock* m_clock{nullptr};
  sf::Time m_time{};
  sf::Time m_lastTime{};

  // Variables used to track average FPS
  float m_timeTracker{0.f};
  unsigned short m_avgFPS{0};
  unsigned short m_fpsTracker[TRACKED_TICK_COUNT]{};
  unsigned char m_fpsTrackerIndex{0};
  bool m_fpsTrackerLooped{false};
  unsigned short m_framesThisSecond{0};
  unsigned short m_framesLastSecond{0};
};