#include <iostream>
#include <windows.h>
#include "Interfaces.h"

using namespace std;

struct winsize {
    int ws_row;
    int ws_col;
};

int main() {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    // Crear una estructura para almacenar la información del cursor.
    CONSOLE_CURSOR_INFO consoleCursorInfo;

    // Obtener la información actual del cursor.
    GetConsoleCursorInfo(hConsoleOutput, &consoleCursorInfo);

    // Ocultar el cursor.
    consoleCursorInfo.bVisible = false;

    // Establecer la nueva información del cursor.
    SetConsoleCursorInfo(hConsoleOutput, &consoleCursorInfo);

    /*HANDLE wHnd = GetStdHandle (STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 50, 15};
    SetConsoleWindowInfo (wHnd, 1, &windowSize);*/


    HWND consoleWindow;
    consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE,GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    system("title LABERINTO C++");
    system("mode con: cols=65 lines=18");

    /*cout << "Yes" << endl;
    system("pause");*/

    menu_principal();

    return 0;
}
