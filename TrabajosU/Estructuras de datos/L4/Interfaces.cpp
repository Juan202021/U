#ifndef L4_INTERFACES_CPP
#define L4_INTERFACES_CPP
#include "Interfaces.h"
#include "Laberinto.h"
#include <mmsystem.h>

Punto p(0,0,0);

Interfaces::Interfaces():laberintoObj(Laberinto()){}

void Interfaces::elegir_posicion(){
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    Punto pAnterior;
    bool flag= true;
    // Bucle infinito para permitir que el usuario elija una posición.
    erase(1,1,67,20);
    SetConsoleTextAttribute(hConsole, 9);
    gotoxy(10,14);
    cout << "- Muevase con las teclas direccionales a la posicion";
    gotoxy(12,15);
    cout << "en la cual desea iniciar a recorrer el laberinto. -" << endl;
    gotoxy(10,17);
    cout << "- Para seleccionar un punto oprima la tecla ENTER. -\n" << endl;
    p.setCol(0);
    p.setFil(0);
    // Imprimir el laberinto.
    laberintoObj.print(p,25,2);
    while (flag) {
        laberintoObj.printPos(pAnterior,p,25,2);
        pAnterior = p;
        system("pause > nul");
        if (teclaPresionada(0x26)){
            if (p.getFil()-1 >= 0 && p.getFil()-1 < laberintoObj.getTamanioF()) {
                p.setFil(p.getFil()-1);
            }
        }
        else if (teclaPresionada(0x28)){
            if (p.getFil()+1 >= 0 && p.getFil()+1 < laberintoObj.getTamanioF()) {
                p.setFil(p.getFil()+1);
            }
        }
        else if (teclaPresionada(0x25)){
            if (p.getCol()-1 >= 0 && p.getCol()-1 < laberintoObj.getTamanioC()) {
                p.setCol(p.getCol()-1);
            }
        }
        else if (teclaPresionada(0x27)){
            if (p.getCol()+1 >= 0 && p.getCol()+1 < laberintoObj.getTamanioC()) {
                p.setCol(p.getCol()+1);
            }
        }
        else if (teclaPresionada(0x0D)){
            if (laberintoObj.posValida(p.getFil(),p.getCol())) flag = false;
            else {
                gotoxy(6,19);
                SetConsoleTextAttribute(hConsole, 4);
                cout << "- No es una posicion valida para iniciar. Seleccione otra. -" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                erase(6,19,60,1);
            }
        }
    }
}
void Interfaces::menu_principal(){
    bool repite = true;
    int opcion;
    do{
        erase(1,1,71,20);
        cuadro(0,0,72,21);
        string titulo = "BIENVENIDOS AL MEJOR LABERINTO";
        vector<string> opciones = {"Cargar un Laberinto","Elegir musica","Salir"};
        opcion = plantilla_menu(titulo,opciones,22,8);
        if(opcion==1){
            opcion = menuContinuarLaberinto();
            if (opcion == 4) repite = false;
        } else if (opcion == 2){
            reproducir_musica();
        } else if (opcion == 3){
            repite = false;
        }
    }while(repite);
}
int Interfaces::menuContinuarLaberinto(){
    string titulo;
    vector<string> opciones;
    int opcion;

    if (laberintoObj.cargar()){
        elegir_posicion();
        //this_thread::sleep_for(chrono::seconds(1));
        erase(1,1,71,20);
        laberintoObj.iniciar(p);
        while (true){
            titulo = "";
            opciones = {"Mostrar camino","Mostrar puntos recorridos","Continuar","Salir"};
            opcion = plantilla_menu(titulo, opciones, 36,16);
            if (opcion == 1){
                erase(27,1,44,11);
                if (laberintoObj.visitadosSize() > 1) laberintoObj.printCamino();
                else {
                    gotoxy(33,5);
                    cout << char(254) << " No se puede mostrar un camino " << char(254) << endl;
                    gotoxy(35,6);
                    cout << char(254) << " No se encontro una salida " << char(254) << endl;
                }
            }
            else if (opcion == 2) laberintoObj.printPuntosRecorridos();
            else if (opcion == 3){ laberintoObj.reset(); return 3; }
            else if (opcion == 4) return 4;
        }
    }
}

void Interfaces::reproducir_musica() {
    bool rep = true;
    int opcion;
    string titulo = "    QUE MUSICA DESEA:";
    vector<string> opciones = {"LA VERRAQUERA","ESCAPE DE NOKIA","Pausar","volver"};
    erase(1,1,71,20);
    do{
        opcion = plantilla_menu(titulo, opciones, 24,8);
        std::vector<std::string> canciones = {
                "C:\\Users\\Juan\\Downloads\\cancion.wav",
                "C:\\Users\\Juan\\Downloads\\escape.wav"
        };
        if(opcion==3){
            PlaySoundA(NULL, NULL, 0);
            //Sleep(2000); // Pausa de 5 segundos
        }else if(opcion==4){
            rep=false;
        }else {
            std::string cancion = canciones[opcion - 1];
            PlaySoundA((LPCSTR)cancion.c_str(), NULL, SND_FILENAME | SND_ASYNC);
        }
    }while(rep);
}
bool Interfaces::teclaPresionada(int tecla) {
    return GetKeyState(tecla) < 0;
}
#endif