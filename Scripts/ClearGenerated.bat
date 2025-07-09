@echo off

pushd ..
del "Stat Tracker.sln"
pushd "App"
del "StatTracker.vcxproj"
del "StatTracker.vcxproj.filters"
popd
rd /s /q "Build"
rd /s /q "Intermediate"
popd