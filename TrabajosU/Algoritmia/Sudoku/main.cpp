#include <iostream> // Libreria para la entrada y salida de texto.
#include <ctime> // Libreria que permite tomar al tiempo, como semilla en la función srand().
#include <conio.h>
#include <windows.h>
#include "cuerpoSudoku.h" // Se importa el archivo .h que contiene el cuerpo del sudoku.
#include <locale.h>
#include <wchar.h>

using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    srand((time(0)));
    char soundfile[] = "hola.wav";
    cout << PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC);
    char sudoku[12][12];
    interfaz(sudoku);

    getch();
    return 0;
}

