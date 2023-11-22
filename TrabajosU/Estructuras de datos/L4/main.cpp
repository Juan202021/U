#include <iostream>
#include "Interfaces.h"

using namespace std;

int main() {
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    // Crear una estructura para almacenar la información del cursor.
    CONSOLE_CURSOR_INFO consoleCursorInfo;

    // Obtener la información actual del cursor.
    GetConsoleCursorInfo(hConsole, &consoleCursorInfo);

    // Ocultar el cursor.
    consoleCursorInfo.bVisible = false;

    // Establecer la nueva información del cursor.
    SetConsoleCursorInfo(hConsole, &consoleCursorInfo);

    HWND consoleWindow;
    consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE,GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    system("title LABERINTO C++");
    system("mode con: cols=73 lines=22");

    Interfaces interfaz;
    interfaz.menu_principal();

    return 0;
}
