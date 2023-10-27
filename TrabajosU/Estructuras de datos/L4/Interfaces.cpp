//
// Created by santi on 20/10/2023.
//

#include "interfaces.h"
#include "Laberinto.h"
#include <mmsystem.h>
#include <conio.h>

#define TECLA_ARRIBA 72
#define TECLA_IZQUIERDA 75
#define TECLA_DERECHA 77
#define TECLA_ABAJO 80
#define ENTER 13
int fila_actual = 8;
int columna_actual = 6;

// Declaramos las variables para almacenar el color y el tamaño de la letra
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;
int menu(const char*titulo,const char*opciones[],int n);
Laberinto laberinto;
Punto p(fila_actual,columna_actual,0);

void elegir_posicion(){
    bool flag= true;
    char tecla = ' ';
    // Bucle infinito para permitir que el usuario elija una posición.
    while (flag) {
        // Imprimir el laberinto.
        laberinto.printPos(p);
        SetConsoleTextAttribute(hConsole, 9);
        cout << "      - Muevase con las teclas direccionales a la posicion\n\t en la cual desea iniciar a recorrer el laberinto. -" << endl;
        cout << "      - Para seleccionar un punto oprima la tecla ENTER. -\n" << endl;
        laberinto.cuadro(0,0,64,17);
        system("pause > nul");
        if (teclaPresionada(0x26)){
            if (p.getFil()-1 >= 0 && p.getFil()-1 < laberinto.getTamanioF()) {
                p.setFil(p.getFil()-1);
            }
        }
        else if (teclaPresionada(0x28)){
            if (p.getFil()+1 >= 0 && p.getFil()+1 < laberinto.getTamanioF()) {
                p.setFil(p.getFil()+1);
            }
        }
        else if (teclaPresionada(0x25)){
            if (p.getCol()-1 >= 0 && p.getCol()-1 < laberinto.getTamanioC()) {
                p.setCol(p.getCol()-1);
            }
        }
        else if (teclaPresionada(0x27)){
            if (p.getCol()+1 >= 0 && p.getCol()+1 < laberinto.getTamanioC()) {
                p.setCol(p.getCol()+1);
            }
        }
        else if (teclaPresionada(0x0D)){
            if (laberinto.posValida(p.getFil(),p.getCol())) flag = false;
            else {
                cout << "\n\t- No es una posicion valida para iniciar. Seleccione otra." << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }
    }
}
void menu_principal(){
    bool repite = true;
    int opcion;

    const char*titulo = "BIENVENIDOS AL MEJOR LABERINTO";
    const char*opciones[] = {"Cargar un Laberinto","Elegir musica","Salir"};
    int n=3;
    do{
        //system("COLOR D");
        opcion = menu(titulo, opciones,n);
        //cuadro(0,0,17,64);
        if(opcion==1){
            system("cls");
            if (laberinto.cargar()){
                elegir_posicion();
                this_thread::sleep_for(chrono::seconds(1));
                system("cls");
                laberinto.iniciar(p);
            }
            this_thread::sleep_for(chrono::seconds(2));
        }else if(opcion == 2){
            reproducir_musica();
        }else if(opcion == 3){
            repite= false;
        }

        //ALTERNATIVAS


    }while(repite);

}
int menu(const char*titulo,const char*opciones[],int n){
    int opcionesSeleccionada=1;
    int tecla;
    bool repite = true;
    do{
        system("cls");
        //system("COLOR B0");
        SetConsoleTextAttribute(hConsole, 8);
        laberinto.gotoxy(15,6+opcionesSeleccionada);
        //cout << "\033[" << 3+opcionesSeleccionada << ";5H";
        cout<<"  >";
        SetConsoleTextAttribute(hConsole, 3);

        //SetConsoleFontSize(GetStdHandle(STD_OUTPUT_HANDLE), 20);
        laberinto.gotoxy(17,4);
        //cout << "\033[2;15H";
        cout<<titulo;

        for(int i=0;i<n;i++){
            laberinto.gotoxy(20,i+7);
            SetConsoleTextAttribute(hConsole, 9);
            //cout << "\033[" << 4+opcionesSeleccionada << ";12H";
            cout<<i+1<<") "<<opciones[i]<<endl<<endl;

        }
        laberinto.cuadro(0,0,64,17);
        do{
            tecla = getch();

        }while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER );
        switch(tecla){
            case TECLA_ARRIBA:
                opcionesSeleccionada--;
                if(opcionesSeleccionada<1){
                    opcionesSeleccionada = n;
                }
                break;
            case TECLA_ABAJO:
                opcionesSeleccionada++;
                if(opcionesSeleccionada>n){
                    opcionesSeleccionada = 1;
                }
                break;
            case ENTER:
                repite = false;
                break;
        }
    }while(repite);

    return opcionesSeleccionada;
}

void reproducir_musica() {
    bool rep = true;
    int opcion;

    const char*titulo = "    QUE MUSICA DESEA:";
    const char*opciones[] = {"LA VERRAQUERA","ESCAPE DE NOKIA","Pausar","volver"};
    int n=4;
    do{
        opcion = menu(titulo, opciones,n);
        //ALTERNATIVAS
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
bool teclaPresionada(int tecla) {
    return GetKeyState(tecla) < 0;
}
