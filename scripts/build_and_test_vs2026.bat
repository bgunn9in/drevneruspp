@echo off
setlocal
chcp 65001 >nul
pushd "%~dp0\.."

cmake -S . -B build-vs2026 -G "Visual Studio 18 2026" -A x64
if errorlevel 1 goto :fail

cmake --build build-vs2026 --config Release --parallel
if errorlevel 1 goto :fail

ctest --test-dir build-vs2026 -C Release --output-on-failure
if errorlevel 1 goto :fail

echo.
echo Летопись собрана. Все испытания пройдены.
popd
exit /b 0

:fail
echo.
echo Беда великая: сборка или испытания завершились неудачей.
popd
exit /b 1

