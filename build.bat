@echo off
echo Компиляция заданий Windows API...
echo.

REM Проверка наличия компилятора
where g++ >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo Ошибка: g++ не найден в PATH
    echo Установите MinGW или добавьте его в PATH
    pause
    exit /b 1
)

echo Компиляция задания 1...
g++ -std=c++11 -o assignment1.exe assignment1.cpp -mwindows
if %ERRORLEVEL% NEQ 0 (
    echo Ошибка компиляции задания 1
    pause
    exit /b 1
)

echo Компиляция задания 2...
g++ -std=c++11 -o assignment2.exe assignment2.cpp -mwindows
if %ERRORLEVEL% NEQ 0 (
    echo Ошибка компиляции задания 2
    pause
    exit /b 1
)

echo Компиляция задания 3...
g++ -std=c++11 -o assignment3.exe assignment3.cpp -mwindows
if %ERRORLEVEL% NEQ 0 (
    echo Ошибка компиляции задания 3
    pause
    exit /b 1
)

echo Компиляция задания 4...
g++ -std=c++11 -o assignment4.exe assignment4.cpp -mwindows
if %ERRORLEVEL% NEQ 0 (
    echo Ошибка компиляции задания 4
    pause
    exit /b 1
)

echo.
echo Все задания успешно скомпилированы!
pause

