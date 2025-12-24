#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Поиск окна Блокнота по имени класса
    HWND hwndNotepad = FindWindow(L"Notepad", NULL);
    
    if (hwndNotepad == NULL)
    {
        // Если не найдено по классу, попробуем найти по заголовку
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
    
    if (hwndNotepad != NULL)
    {
        // Отправка сообщения WM_CLOSE для закрытия окна
        SendMessage(hwndNotepad, WM_CLOSE, 0, 0);
        MessageBox(NULL, 
                   L"Сообщение о закрытии окна Блокнота было отправлено.",
                   L"Assignment 3",
                   MB_OK | MB_ICONINFORMATION);
    }
    else
    {
        MessageBox(NULL, 
                   L"Окно Блокнота не найдено.\nПожалуйста, откройте Блокнот и запустите программу снова.",
                   L"Assignment 3 - Ошибка",
                   MB_OK | MB_ICONWARNING);
    }
    
    return 0;
}

