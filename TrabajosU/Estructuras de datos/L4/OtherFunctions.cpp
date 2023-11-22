#ifndef L4_OTHERFUNCTIONS_CPP
#define L4_OTHERFUNCTIONS_CPP
#include "OtherFunctions.h"
void OtherFunctions::gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
void OtherFunctions::cuadro(int x1, int y1, int ancho, int alto){
    //SetConsoleTextAttribute(hConsole, 4); //rojo
    //SetConsoleTextAttribute(hConsole, 5); //violeta
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    SetConsoleTextAttribute(hConsole, 11);
    for(int i = x1 + 1; i < ancho + x1; i++){
        gotoxy(i,y1); // arriba
        std::cout<<char(205);
        gotoxy(i, y1 + alto); // abajo
        std::cout<<char(205);
    }
    for(int j = y1 + 1; j < alto + y1; j++){
        gotoxy(x1+ancho,j); // Derecha
        std::cout<<char(186);
        gotoxy(x1, j); // Izquierda
        std::cout<<char(186);
    }
    gotoxy(x1,y1); std::cout<<char(201);
    gotoxy(x1, y1 + alto); std::cout << char(200);
    gotoxy(x1 + ancho, y1); std::cout << char(187);
    gotoxy(x1 + ancho, y1 + alto); std::cout << char(188);
}
void OtherFunctions::erase(int x1, int y1, int ancho, int alto){
    for(int i = x1; i < ancho + x1; i++){
        for (int j = y1; j < alto + y1; j++){
            gotoxy(i,j);
            std::cout<<" ";
        }
    }
}
int OtherFunctions::plantilla_menu(std::string& titulo, std::vector<std::string> opciones, int x, int y){
    int opcionSeleccionada = 1, tecla;
    bool repite = true;
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    //erase(1,1,71,20);
    do{
        erase(x,y,3,opciones.size()+1);
        SetConsoleTextAttribute(hConsole, 8);
        gotoxy(x,y+opcionSeleccionada);
        std::cout<<"  >";
        SetConsoleTextAttribute(hConsole, 3);
        if (titulo.size() <= 20){
            gotoxy(x+8,y-2);
            std::cout<<titulo;
        }
        else if (titulo.size() <= 30 && titulo.size() > 20){
            gotoxy(x,y-2);
            std::cout<<titulo;
        }
        else {
            gotoxy(x-17,y-2);
            std::cout<<titulo;
        }
        for(int i=0;i<opciones.size();i++){
            gotoxy(x+4,i+y+1);
            SetConsoleTextAttribute(hConsole, 9);
            std::cout<<"["<<i+1<<"] "<<opciones[i]<<std::endl;
        }
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
#endif