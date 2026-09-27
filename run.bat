@echo off

echo === Compilando con CMake ===
cmake --build build

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ERROR] La compilacion ha fallado. Revisa los errores arriba.
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo === Ejecutando programa ===
echo.
.\build\SistemaCram.exe

echo.
pause
