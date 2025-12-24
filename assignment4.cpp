#include <windows.h>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

std::wstring GetCurrentTimeString()
{
    time_t now = time(0);
    struct tm timeinfo;
    
    // Используем localtime_s для MSVC или localtime для MinGW
    #ifdef _MSC_VER
        localtime_s(&timeinfo, &now);
    #else
        struct tm* timeptr = localtime(&now);
        if (timeptr != NULL)
        {
            timeinfo = *timeptr;
        }
    #endif
    
    std::wstringstream ss;
    ss << std::setfill(L'0') << std::setw(2) << timeinfo.tm_hour << L":"
       << std::setfill(L'0') << std::setw(2) << timeinfo.tm_min << L":"
       << std::setfill(L'0') << std::setw(2) << timeinfo.tm_sec;
    
    return ss.str();
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Поиск окна Блокнота
    HWND hwndNotepad = FindWindow(L"Notepad", NULL);
    
    if (hwndNotepad == NULL)
    {
        // Попробуем найти по заголовку
        hwndNotepad = FindWindow(NULL, L"Безымянный - Блокнот");
        if (hwndNotepad == NULL)
        {
            hwndNotepad = FindWindow(NULL, L"*Безымянный - Блокнот");
        }
        if (hwndNotepad == NULL)
        {
            hwndNotepad = FindWindow(NULL, L"Untitled - Notepad");
        }
    }
    
    if (hwndNotepad == NULL)
    {
        MessageBox(NULL, 
                   L"Окно Блокнота не найдено.\nПожалуйста, откройте Блокнот и запустите программу снова.",
                   L"Assignment 4 - Ошибка",
                   MB_OK | MB_ICONWARNING);
        return 1;
    }
    
    MessageBox(NULL, 
               L"Программа будет обновлять заголовок Блокнота каждую секунду.\nНажмите OK для начала.",
               L"Assignment 4",
               MB_OK | MB_ICONINFORMATION);
    
    // Обновление заголовка каждую секунду
    while (IsWindow(hwndNotepad))
    {
        std::wstring timeStr = GetCurrentTimeString();
        std::wstring title = L"Блокнот - " + timeStr;
        
        // Отправка сообщения для изменения заголовка окна
        SetWindowText(hwndNotepad, title.c_str());
        
        // Ожидание 1 секунды
        Sleep(1000);
        
        // Проверка, что окно все еще существует
        hwndNotepad = FindWindow(L"Notepad", NULL);
        if (hwndNotepad == NULL)
        {
            hwndNotepad = FindWindow(NULL, L"Безымянный - Блокнот");
            if (hwndNotepad == NULL)
            {
                hwndNotepad = FindWindow(NULL, L"*Безымянный - Блокнот");
            }
            if (hwndNotepad == NULL)
            {
                hwndNotepad = FindWindow(NULL, L"Untitled - Notepad");
            }
        }
    }
    
    return 0;
}

