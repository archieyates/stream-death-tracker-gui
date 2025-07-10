#include "Game.h"

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

class Game
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

static Game* s_game = nullptr;

namespace game
{
  void init()
  {
    assert(s_game == nullptr);

    s_game = new Game();
    s_game->init();
    s_game->postInit();
  }

  void update()
  {
    assert(s_game != nullptr);

    s_game->update();
  }

  void render()
  {
    assert(s_game != nullptr);

    s_game->preRender();
    s_game->render();
    s_game->draw();
  }

  void shutdown()
  {
    assert(s_game != nullptr);

    s_game->shutdown();
    delete s_game;
    s_game = nullptr;
  }

  TickManager* getTickManager()
  {
    assert(s_game != nullptr);
    return s_game->m_tickManager;
  }

  WindowManager* getWindowManager()
  {
    assert(s_game != nullptr);
    return s_game->m_windowManager;
  }

  ImGuiManager* getImGuiManager()
  {
    assert(s_game != nullptr);
    return s_game->m_imguiManager;
  }
} // namespace game