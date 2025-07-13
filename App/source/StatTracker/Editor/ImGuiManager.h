#pragma once

#include "Deaths/DeathCounter.h"
#include "Manager/Manager.h"

struct ImFont;

class ImGuiManager : public Manager
{
protected:
  void onPostInit() override;
  void onUpdate() override;
  void onShutdown() override;
  void onRender() override;

private:
  void showGame(IndexString game);
  void showPlaythrough(IndexString playthrough);
  void showArea(IndexString area);
  void showBoss(IndexString boss);

  IndexString m_selectedGame{"##"};
  IndexString m_selectedPlaythough{"##"};
  IndexString m_selectedArea{"##"};
  IndexString m_selectedBoss{"##"};

  bool m_imguiInit{false};
  bool m_open{true};

  bool m_newGameOpen{false};
  IndexString m_newGameName{};

  DeathCounter m_deathCounter{};
};