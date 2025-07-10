#include "SFML/Graphics/RenderWindow.hpp"
#include "imgui-sfml/imgui-SFML.h"
#include "imgui/imgui.h"

#include "Game.h"
#include "Manager/WindowManager.h"

#include <cassert>
#include <iostream>

int main()
{
  game::init();

  WindowManager* windowManager = game::getWindowManager();

  while (windowManager->isOpen())
  {
    game::update();
    game::render();
  }
  windowManager = nullptr;

  game::shutdown();

  return 0;
}