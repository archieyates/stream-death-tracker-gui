#pragma once

#include "Deaths/Game.h"

class DeathCounter
{
public:
  std::map<IndexString, Game> m_games{};
};