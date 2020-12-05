"postBuild x32.exe" clear out "$OUT" "Debug" "Release" : 32 64 : "FirstTest" "SDI_fondationObjects" : pdb exp ilk iobj ipdb
"postBuild x32.exe" clear out "" : : "postBuild x64" "postBuild x32" : pdb ilk iobj ipdb

:: If you usr windoe x32 replace "postBuild x64.exe" on "postBuild x32.exe" in "postBuildEvent.bat"
