#pragma once

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
  bool m_imguiInit{false};
};