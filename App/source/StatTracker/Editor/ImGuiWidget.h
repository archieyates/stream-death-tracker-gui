#pragma once

#include <string>

class ImGuiWidget
{
  friend class ImGuiManager;

public:
  ImGuiWidget();
  virtual ~ImGuiWidget() {};

  virtual void init() {};
  virtual void tick(const float dt) = 0;
  virtual void shutdown() {};

private:
  std::string m_name;
};