#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstancia, HINSTANCE hInstanciaPrev,
    LPSTR lpszCmd, int nEstadoVentana)
{
    MessageBox(0, "�Guardar cambios?", "T�tulo", MB_YESNO | MB_ICONQUESTION);
    return 0;
}
