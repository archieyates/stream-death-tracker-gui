#include "ImGuiManager.h"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "imgui-ocornut/imgui_stdlib.h"
#include "imgui-sfml/imgui-SFML.h"
#include "imgui/imgui.h"

#include "App.h"
#include "Editor/imgui.h"
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

    ImGui::Begin("Death Tracker", &m_open);
    {
      std::vector<std::string> games;
      for (auto it = m_deathCounter.m_games.begin(); it != m_deathCounter.m_games.end(); ++it)
      {
        games.push_back(it->first.toString());
      }
      std::sort(games.begin(), games.end());
      games.insert(games.begin(), "##");

      ImGui::BeginGroupPanel("Game");
      {
        if (ImGui::Button("New"))
        {
          m_newGameOpen = true;
        }

        if (ImGui::BeginCombo("##GamesSelection", m_selectedGame.toString().c_str()))
        {
          for (int i = 0; i < games.size(); ++i)
          {
            const bool isSelected = IndexString(games[i]) == m_selectedGame;
            if (ImGui::Selectable(games[i].c_str(), isSelected))
            {
              m_selectedGame.set(games[i]);
            }

            if (isSelected)
            {
              ImGui::SetItemDefaultFocus();
            }
          }
          ImGui::EndCombo();
        }

        if (m_deathCounter.m_games.contains(m_selectedGame))
        {
          showGame(m_selectedGame);
        }
      }
      ImGui::EndGroupPanel();
    }
    ImGui::End();

    if (m_newGameOpen)
    {
      ImGui::Begin("New Game", &m_open);
      {
        std::string lookup = m_newGameName.toString();

        if (ImGui::InputText("Game Name", &lookup, ImGuiInputTextFlags_EnterReturnsTrue))
        {
          m_newGameName = lookup;
        }

        if (m_newGameName.isValid() && !m_deathCounter.m_games.contains(m_newGameName))
        {
          if (ImGui::Button("Save"))
          {
            m_deathCounter.m_games[m_newGameName] = Game();
            m_deathCounter.m_games[m_newGameName].m_name = m_newGameName;

            m_selectedGame = m_newGameName;
            m_newGameName.clear();
            m_newGameOpen = false;
          }
        }
      }
      ImGui::End();
    }
    else
    {
      m_newGameName.clear();
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

void ImGuiManager::showGame(IndexString game)
{
}

void ImGuiManager::showPlaythrough(IndexString playthrough)
{
}

void ImGuiManager::showArea(IndexString area)
{
}

void ImGuiManager::showBoss(IndexString boss)
{
}
