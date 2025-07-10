// Framework core class

#pragma once

class TickManager;
class WindowManager;
class ImGuiManager;

namespace game
{
  extern void init();
  extern void update();
  extern void render();
  extern void shutdown();

  extern TickManager* getTickManager();
  extern WindowManager* getWindowManager();
  extern ImGuiManager* getImGuiManager();
} // namespace game
