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
Laberinto laberinto;
Punto p(fila_actual,columna_actual,0);

void elegir_posicion(){
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
    while (flag) {
        // Imprimir el laberinto.
        laberinto.printPos(p);
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
                gotoxy(6,19);
                SetConsoleTextAttribute(hConsole, 4);
                cout << "- No es una posicion valida para iniciar. Seleccione otra. -" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                erase(6,19,60,1);
            }
        }
    }
}
void menu_principal(){
    bool repite = true;
    int opcion;
    do{
        erase(1,1,71,20);
        cuadro(0,0,72,21);
        string titulo = "BIENVENIDOS AL MEJOR LABERINTO";
        vector<string> opciones = {"Cargar un Laberinto","Elegir musica","Salir"};
        opcion = menu(titulo, opciones,8);
        if(opcion==1){
            if (laberinto.cargar()){
                elegir_posicion();
                this_thread::sleep_for(chrono::seconds(1));
                erase(1,1,71,20);
                laberinto.iniciar(p);
                titulo = "";
                opciones = {"Continuar","Salir"};
                if (menu(titulo,opciones,16) == 2) repite = false;
            }
            this_thread::sleep_for(chrono::seconds(2));
        }else if(opcion == 2){
            reproducir_musica();
        }else if(opcion == 3){
            repite= false;
        }
    }while(repite);

}
int menu(string titulo, vector<string> opciones, int y){
    int opcionSeleccionada=1, tecla;
    bool repite = true;
    //erase(1,1,71,20);
    do{
        erase(18,y,3,opciones.size()+1);
        SetConsoleTextAttribute(hConsole, 8);
        gotoxy(18,y+opcionSeleccionada);
        cout<<"  >";
        SetConsoleTextAttribute(hConsole, 3);

        if (titulo.size() <= 30){
            gotoxy(20,y-2);
            cout<<titulo;
        }
        else {
            gotoxy(6,y-2);
            cout<<titulo;
        }
        for(int i=0;i<opciones.size();i++){
            gotoxy(24,i+y+1);
            SetConsoleTextAttribute(hConsole, 9);
            cout<<i+1<<") "<<opciones[i]<<endl<<endl;
        }
        //cuadro(0,0,72,21);
        do{
            tecla = getch();
        }while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER );
        switch(tecla){
            case TECLA_ARRIBA:
                opcionSeleccionada--;
                if(opcionSeleccionada<1){
                    opcionSeleccionada = opciones.size();
                }
                break;
            case TECLA_ABAJO:
                opcionSeleccionada++;
                if(opcionSeleccionada>opciones.size()){
                    opcionSeleccionada = 1;
                }
                break;
            case ENTER:
                repite = false;
                break;
        }
    }while(repite);
    return opcionSeleccionada;
}
void reproducir_musica() {
    bool rep = true;
    int opcion;
    string titulo = "    QUE MUSICA DESEA:";
    vector<string> opciones = {"LA VERRAQUERA","ESCAPE DE NOKIA","Pausar","volver"};
    erase(1,1,71,20);
    do{
        opcion = menu(titulo, opciones,8);
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
void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
void cuadro(int x1, int y1, int ancho, int alto){
    //SetConsoleTextAttribute(hConsole, 4); //rojo
    //SetConsoleTextAttribute(hConsole, 5); //violeta
    SetConsoleTextAttribute(hConsole, 11);
    for(int i = x1 + 1; i < ancho + x1; i++){
        gotoxy(i,y1); // arriba
        cout<<char(205);
        gotoxy(i, y1 + alto); // abajo
        cout<<char(205);
    }
    for(int j = y1 + 1; j < alto + y1; j++){
        gotoxy(x1+ancho,j); // Derecha
        cout<<char(186);
        gotoxy(x1, j); // Izquierda
        cout<<char(186);
    }
    gotoxy(x1,y1); cout<<char(201);
    gotoxy(x1, y1 + alto); cout << char(200);
    gotoxy(x1 + ancho, y1); cout << char(187);
    gotoxy(x1 + ancho, y1 + alto); cout << char(188);

}
void erase(int x1, int y1, int ancho, int alto){
    for(int i = x1; i < ancho + x1; i++){
        for (int j = y1; j < alto + y1; j++){
            gotoxy(i,j);
            cout<<" ";
        }

    }
}