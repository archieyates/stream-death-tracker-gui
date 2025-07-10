#pragma once

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui/imgui.h"

namespace ImGui
{
  extern const float getWindowContentRegionWidth();
  extern const float getWindowContentRegionHeight();

  // From https://github.com/ocornut/imgui/issues/1496#issuecomment-655048353
  extern void BeginGroupPanel(const char* name, const ImVec2& size = ImVec2(0.0f, 0.0f));
  extern void EndGroupPanel();

  extern bool SliderUChar(const char* label, unsigned char* v, unsigned char v_min, unsigned char v_max, const char* format = "%d", ImGuiSliderFlags flags = 0);
  extern bool InputUChar(const char* label, unsigned char* v, unsigned char step = 1, unsigned char step_fast = 5, ImGuiInputTextFlags flags = 0);

} // namespace ImGui
