# Makefile для компиляции заданий Windows API

CXX = g++
CXXFLAGS = -std=c++11 -O2
LDFLAGS = -mwindows

# Все задания
all: assignment1.exe assignment2.exe assignment3.exe assignment4.exe

# Задание 1: Hello World
assignment1.exe: assignment1.cpp
	$(CXX) $(CXXFLAGS) -o assignment1.exe assignment1.cpp $(LDFLAGS)

# Задание 2: Игра угадай число
assignment2.exe: assignment2.cpp
	$(CXX) $(CXXFLAGS) -o assignment2.exe assignment2.cpp $(LDFLAGS)

# Задание 3: Закрытие Блокнота
assignment3.exe: assignment3.cpp
	$(CXX) $(CXXFLAGS) -o assignment3.exe assignment3.cpp $(LDFLAGS)

# Задание 4: Обновление заголовка Блокнота
assignment4.exe: assignment4.cpp
	$(CXX) $(CXXFLAGS) -o assignment4.exe assignment4.cpp $(LDFLAGS)

# Очистка
clean:
	rm -f *.exe *.o

.PHONY: all clean

