#include "SFML/Graphics/RenderWindow.hpp"
#include "imgui-sfml/imgui-SFML.h"
#include "imgui/imgui.h"

#include "App.h"
#include "Deaths/Game.h"
#include "Manager/WindowManager.h"

#include <cassert>
#include <iostream>

int main()
{
  app::init();

  WindowManager* windowManager = app::getWindowManager();

  while (windowManager->isOpen())
  {
    app::update();
    app::render();
  }
  windowManager = nullptr;

  app::shutdown();

  return 0;
}