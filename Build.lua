-- premake5.lua
workspace "Stat Tracker"
  language "C++"
  cppdialect "C++20"
  staticruntime "off"
  architecture "x64"
  configurations {"Debug", "Release"}
  startproject "StatTracker"
  
  OutputDir = "%{wks.location}/Build/%{cfg.buildcfg}"
  IntermediateDir = "%{wks.location}/Intermediate/%{cfg.buildcfg}"
  
  targetdir("../Binaries/" .. OutputDir .. "/%{prj.name}")
  objdir("../Binaries/Intermediates/" .. IntermediateDir .. "/%{prj.name}")

  defines {
    "SFML_STATIC"
  }
  
  filter "system:windows"
    buildoptions {"/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus"}
    
    defines {
      "PLATFORM_WINDOWS"
    }

  filter "Debug"
    runtime "Debug"
    symbols "On"
    defines {
      "DEBUG"
    }

  filter "Shipping"
    runtime "Release"
    optimize "On"
    symbols "Off"  
    defines {
      "SHIPPING"
    }

  group ""
    include "App/Build-App.lua"