// Framework core class

#pragma once

class TickManager;
class WindowManager;
class ImGuiManager;

namespace app
{
  extern void init();
  extern void update();
  extern void render();
  extern void shutdown();

  extern TickManager* getTickManager();
  extern WindowManager* getWindowManager();
  extern ImGuiManager* getImGuiManager();
} // namespace app
