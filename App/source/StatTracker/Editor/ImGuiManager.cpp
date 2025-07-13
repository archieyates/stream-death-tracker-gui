#include "ImGuiManager.h"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "imgui-sfml/imgui-SFML.h"
#include "imgui/imgui.h"

#include "App.h"
#include "Manager/TickManager.h"
#include "Manager/WindowManager.h"
#include "Utils/Paths.h"

void ImGuiManager::onPostInit()
{
  m_imguiInit = ImGui::SFML::Init(*app::getWindowManager()->getWindow(), false);

  if (m_imguiInit)
  {
    ImGuiIO& io = ImGui::GetIO();

    const std::string path = app::getResourcesDir() + "/Inter-Regular.ttf";
    io.Fonts->AddFontFromFileTTF(path.c_str(), 20.f, nullptr, io.Fonts->GetGlyphRangesDefault());
    m_imguiInit = ImGui::SFML::UpdateFontTexture();

    assert(m_imguiInit);
  }
}

void ImGuiManager::onUpdate()
{
  sf::Time time = app::getTickManager()->getTime();
  float dt = time.asSeconds();

  if (m_imguiInit)
  {
    WindowManager* windowManager = app::getWindowManager();

    windowManager->forEachWindowEvent([this, windowManager](const sf::Event* event)
    {
      ImGui::SFML::ProcessEvent(*windowManager->getWindow(), (*event));
    });

    ImGui::SFML::Update(*windowManager->getWindow(), time);

    if (ImGui::BeginMainMenuBar())
    {
      if (ImGui::BeginMenu("Game"))
      {
        ImGui::EndMenu();
      }
      ImGui::EndMainMenuBar();
    }
  }
}

void ImGuiManager::onShutdown()
{
  if (m_imguiInit)
  {
    ImGui::SFML::Shutdown();
    m_imguiInit = false;
  }
}

void ImGuiManager::onRender()
{
  if (m_imguiInit)
  {
    ImGui::SFML::Render(*app::getWindowManager()->getWindow());
  }
}