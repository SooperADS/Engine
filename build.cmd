@echo off

::		salutionName			  config
devenv "GraphicsLibs.sln" /build "Release|x32"
devenv "GraphicsLibs.sln" /build "Release|x64"
devenv "GraphicsLibs.sln" /build "Debug|x32"
devenv "GraphicsLibs.sln" /build "Debug|x64"

cls
@echo on
