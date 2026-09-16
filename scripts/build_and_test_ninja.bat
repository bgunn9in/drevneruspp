@echo off
setlocal
chcp 65001 >nul
pushd "%~dp0\.."

cmake -S . -B build-ninja -G Ninja -DCMAKE_BUILD_TYPE=Release
if errorlevel 1 goto :fail

cmake --build build-ninja --parallel
if errorlevel 1 goto :fail

ctest --test-dir build-ninja --output-on-failure
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

