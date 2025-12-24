#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    srand(static_cast<unsigned int>(time(NULL)));
    
    bool playAgain = true;
    
    while (playAgain)
    {
        int min = 0;
        int max = 100;
        int guess;
        int attempts = 0;
        int result;
        
        MessageBox(NULL, 
                   L"Загадайте число от 0 до 100.\nКомпьютер будет угадывать ваше число.",
                   L"Игра: Угадай число",
                   MB_OK | MB_ICONINFORMATION);
        
        while (true)
        {
            attempts++;
            guess = (min + max) / 2;
            
            std::wstring message = L"Мой вариант: " + std::to_wstring(guess) + 
                                   L"\n\nВыберите:\n" +
                                   L"Да - если я угадал\n" +
                                   L"Нет - если число больше\n" +
                                   L"Отмена - если число меньше";
            
            std::wstring title = L"Попытка " + std::to_wstring(attempts);
            result = MessageBox(NULL, 
                               message.c_str(),
                               title.c_str(),
                               MB_YESNOCANCEL | MB_ICONQUESTION);
            
            if (result == IDYES)
            {
                std::wstring winMessage = L"Ура! Я угадал ваше число " + 
                                         std::to_wstring(guess) + 
                                         L" за " + std::to_wstring(attempts) + 
                                         L" попыток!";
                MessageBox(NULL, 
                          winMessage.c_str(),
                          L"Победа!",
                          MB_OK | MB_ICONINFORMATION);
                break;
            }
            else if (result == IDNO) // Число больше
            {
                min = guess + 1;
            }
            else if (result == IDCANCEL) // Число меньше
            {
                max = guess - 1;
            }
            
            if (min > max)
            {
                MessageBox(NULL, 
                          L"Что-то пошло не так. Возможно, вы ошиблись в ответах.",
                          L"Ошибка",
                          MB_OK | MB_ICONERROR);
                break;
            }
        }
        
        result = MessageBox(NULL, 
                           L"Хотите сыграть еще раз?",
                           L"Повторить игру?",
                           MB_YESNO | MB_ICONQUESTION);
        
        if (result == IDNO)
        {
            playAgain = false;
        }
    }
    
    return 0;
}

