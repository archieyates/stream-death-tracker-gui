#include "TickManager.h"

#include "SFML/System/Clock.hpp"

sf::Time TickManager::getTime() const
{
  return m_time;
}

sf::Time TickManager::getLastTime() const
{
  return m_lastTime;
}

float TickManager::getDeltaTime() const
{
  return m_time.asSeconds();
}

float TickManager::getLastDeltaTime() const
{
  return m_lastTime.asSeconds();
}

unsigned short TickManager::getFramesThisSecond() const
{
  return m_framesThisSecond;
}

unsigned short TickManager::getFramesLastSecond() const
{
  return m_framesLastSecond;
}

unsigned short TickManager::getAverageFPS() const
{
  return m_avgFPS;
}

void TickManager::onInit()
{
  m_clock = new sf::Clock();
}

void TickManager::onShutdown()
{
  delete m_clock;
  m_clock = nullptr;
}

void TickManager::onUpdate()
{
  m_lastTime = m_time;
  m_time = m_clock->restart();

  updateAverageFPS();
}

void TickManager::updateAverageFPS()
{
  m_framesThisSecond++;
  m_timeTracker += m_time.asSeconds();

  // Every second update the averages
  if (m_timeTracker >= 1.f)
  {
    m_timeTracker -= 1.f;

    m_framesLastSecond = m_framesThisSecond;
    m_framesThisSecond = 0;
    m_fpsTracker[m_fpsTrackerIndex] = m_framesLastSecond;
    const unsigned short count = m_fpsTrackerLooped ? TRACKED_TICK_COUNT : m_fpsTrackerIndex + 1;

    unsigned int avgFPS = 0;
    for (int i = 0; i < count; ++i)
    {
      avgFPS += m_fpsTracker[i];
    }
    avgFPS /= count;
    m_avgFPS = static_cast<unsigned short>(avgFPS);

    m_fpsTrackerIndex++;
    if (m_fpsTrackerIndex >= TRACKED_TICK_COUNT)
    {
      m_fpsTrackerIndex = 0;
      m_fpsTrackerLooped = true;
    }
  }
}