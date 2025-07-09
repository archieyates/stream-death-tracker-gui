project "StatTracker"
kind "ConsoleApp"

files {
  "source/StatTracker/**.h",
  "source/StatTracker/**.cpp",
  "source/StatTracker/**.inl",
  "source/Vendor/**.h",
  "source/Vendor/**.hpp",
  "source/Vendor/**.cpp",
  "source/Vendor/**.inl",
  "Build-App.lua",
  "../Build.lua",
  "../_clang-format"
}

includedirs {
  "source/Vendor",
  "source/StatTracker"
}

libdirs {
  "bin/sfml/lib/Shared"
}

links {
  "opengl32",
  "freetype",
  "winmm",
  "gdi32"
}

filter "Debug"
  libdirs {
    "bin/sfml/lib/Debug"
  }
  links {
    "sfml-system-s-d",
    "sfml-window-s-d",
    "sfml-graphics-s-d"
  }

filter "Release"
  libdirs {
    "bin/sfml/lib/Release"
  }
  links {
    "sfml-system-s",
    "sfml-window-s",
    "sfml-graphics-s"
  }