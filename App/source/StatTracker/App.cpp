#include "App.h"

#include "Editor/ImGuiManager.h"
#include "Manager/TickManager.h"
#include "Manager/WindowManager.h"

#include <cassert>
#include <vector>

#define INIT_MANAGER(manager, ManagerClass) \
  manager = new ManagerClass();             \
  manager->init();

#define SHUTDOWN_MANAGER(manager) \
  manager->shutdown();            \
  delete manager;                 \
  manager = nullptr;

class App
{
public:
  void init()
  {
    INIT_MANAGER(m_tickManager, TickManager);
    INIT_MANAGER(m_windowManager, WindowManager);
    INIT_MANAGER(m_imguiManager, ImGuiManager);
  }

  void postInit()
  {
    m_tickManager->postInit();
    m_windowManager->postInit();
    m_imguiManager->postInit();
  }

  void update()
  {
    // Tick manager needs to go first to establish the delta time for the frame
    m_tickManager->update();

    m_windowManager->update();

    m_imguiManager->update();
  }

  void preRender()
  {
    m_windowManager->preRender();
  }

  void render()
  {
    m_imguiManager->render();
  }

  void draw()
  {
    // Window manager draws after everything else
    m_windowManager->draw();
  }

  void shutdown()
  {
    SHUTDOWN_MANAGER(m_tickManager);
    SHUTDOWN_MANAGER(m_windowManager);
    SHUTDOWN_MANAGER(m_imguiManager);
  }

  ImGuiManager* m_imguiManager{nullptr};
  TickManager* m_tickManager{nullptr};
  WindowManager* m_windowManager{nullptr};
};

static App* s_app = nullptr;

namespace app
{
  void init()
  {
    assert(s_app == nullptr);

    s_app = new App();
    s_app->init();
    s_app->postInit();
  }

  void update()
  {
    assert(s_app != nullptr);

    s_app->update();
  }

  void render()
  {
    assert(s_app != nullptr);

    s_app->preRender();
    s_app->render();
    s_app->draw();
  }

  void shutdown()
  {
    assert(s_app != nullptr);

    s_app->shutdown();
    delete s_app;
    s_app = nullptr;
  }

  TickManager* getTickManager()
  {
    assert(s_app != nullptr);
    return s_app->m_tickManager;
  }

  WindowManager* getWindowManager()
  {
    assert(s_app != nullptr);
    return s_app->m_windowManager;
  }

  ImGuiManager* getImGuiManager()
  {
    assert(s_app != nullptr);
    return s_app->m_imguiManager;
  }
} // namespace app