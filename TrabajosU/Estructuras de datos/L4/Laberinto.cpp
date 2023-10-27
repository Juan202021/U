//
// Created by Juan on 10/13/2023.
//
#ifndef L4_LABERINTO_CPP
#define L4_LABERINTO_CPP
#include "Laberinto.h"
#include <conio.h>

HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);

Laberinto::Laberinto(){
    laberinto = {};
}
Laberinto::Laberinto(vector<vector<char>>& laberinto, Stack<Punto>& visitados, Stack<Punto>& alternativas):
        visitados(visitados), alternativas(alternativas), laberinto(laberinto){}
int Laberinto::getTamanioF(){
    return laberinto.size();
}
int Laberinto::getTamanioC(){
    return laberinto[0].size();
}
bool Laberinto::cumpleTam(){
    auto tam = laberinto[0].size();
    for (const auto& fil : laberinto){
        for (auto pos:fil){
            if (pos != ' ' && pos != '#') return false;
        }
    }
    for (const auto& fil : laberinto){
        if (fil.size() != tam) return false;
    }
    return true;
}
bool Laberinto::cargar(){
    string docu,linea,fila;
    int i=0;
    system("cls");
    cuadro(0,0,64,17);
    gotoxy(5,6);
    cout << char(254) << " Ingrese el nombre del archivo sin ninguna extension " << char(254) << endl;
    cout << "\n\t\t\t> ";
    cin >> docu;
    // Abrir el archivo
    ifstream archivo("C:\\Users\\Juan\\JAristizabal\\U\\TrabajosU\\Estructuras de datos\\L4\\" + docu + ".txt");
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            fila = linea;
            laberinto.emplace_back();
            for (int j=0; j<linea.size(); j++){
                laberinto[i].push_back(linea[j]);
            }
            i++;
        }
        archivo.close();
        if (!cumpleTam()){
            cout << "\n\n\t- El laberinto no cumple con las condiciones minimas. -\n" << endl;
            laberinto.clear();
            return false;
        }
    } else {
        cout << "\n\n\n\t\t- No se pudo abrir el archivo. -\n";
        return false;
    }
    return true;
}
void Laberinto::print(const Punto& currentSpot = Punto()){
    system("cls");
    SetConsoleTextAttribute(hConsol, 9);
    cuadro(0,0,25,12);
    cuadro(0,13,64,4);
    cuadro(26,0,38,12);
    for (int i=0; i<laberinto.size(); i++){
        gotoxy(2,1+i);
        for (int j=0; j<laberinto[0].size(); j++){
            if (laberinto[i][j] == '#'){
                cout << "\x1b[33m" << char(219) << "\x1b[0m";
                //cout << "\x1b[35m" << char(219) << "\x1b[0m";
            }
            else if (i == currentSpot.getFil() && j == currentSpot.getCol()){
                if (laberinto[i][j] == '-') cout << "\x1b[5;35;41m" << char(254) << "\x1b[0m";
                else { cout << "\x1b[5;35;46m" << char(254) << "\x1b[0m"; }

                //if (laberinto[i][j] == '-') cout << "\x1b[5;34;41m" << char(254) << "\x1b[0m";
                //else { cout << "\x1b[5;34;46m" << char(254) << "\x1b[0m"; }
            }
            else if (laberinto[i][j] == 'O'){
                cout << "\x1b[36m" << char(219) << "\x1b[0m";
                //cout << "\x1b[1;36m" << char(219) << "\x1b[0m";
            }
            else if (laberinto[i][j] == '-'){
                cout << "\x1b[31m" << char(219) << "\x1b[0m";
            }
            else {
                cout << "\x1b[34m" << char(219) << "\x1b[0m"; //espacio azul
                //cout << "\x1b[1;33m" << char(219) << "\x1b[0m";
            }
        }
        cout << endl;
    }
    char cancion[] = "C:\\Users\\Juan\\Downloads\\mario.wav";

    // Reproduce la canción de forma asíncrona.
    PlaySound((LPCSTR)cancion, NULL, SND_FILENAME | SND_ASYNC);
    cout << endl;
    this_thread::sleep_for(chrono::seconds(1));
    //system("cls");
}
void Laberinto::printPos(const Punto& currentSpot = Punto()){
    system("cls");
    for (int i=0; i<laberinto.size(); i++){
        gotoxy(21,2+i);
        for (int j=0; j<laberinto[0].size(); j++){
            if (i == currentSpot.getFil() && j == currentSpot.getCol()){
                if (laberinto[i][j] == ' ') cout << "\x1b[5;35;44m" << char(254) << "\x1b[0m";
                else { cout << "\x1b[5;35;43m" << char(254) << "\x1b[0m"; }
            }
            else if (laberinto[i][j] == '#'){
                cout << "\x1b[33m" << char(219) << "\x1b[0m";
            }
            else {
                cout << "\x1b[34m" << char(219) << "\x1b[0m"; //espacio azul
            }
        }
        cout << endl;
    }
    cout << endl;
    char cancion[] = "C:\\Users\\Juan\\Downloads\\mario.wav";
    // Reproduce la canción de forma asíncrona.
    PlaySound((LPCSTR)cancion, NULL, SND_FILENAME | SND_ASYNC);
    //this_thread::sleep_for(chrono::seconds(1));
}
bool Laberinto::esSalida(const Punto& currentSpot){
    return (currentSpot.getFil() == 0
            || currentSpot.getFil() == laberinto.size() - 1
            || currentSpot.getCol() == 0
            || currentSpot.getCol() == laberinto[0].size() - 1);
}
bool Laberinto::posValida(int fila, int columna){
    return (fila >= 0 && fila < laberinto.size() && columna >= 0 && columna < laberinto[0].size() && laberinto[fila][columna] == ' ');
}
bool Laberinto::noPosAnterior(int fila, int columna){
    return (visitados.size() == 0) || ((fila != visitados.top().getFil()) || (columna != visitados.top().getCol()));
}
void Laberinto::buscarAlternativas(Punto& currentSpot){
    currentSpot.setCantAlternativas(0);
    if (posValida(currentSpot.getFil() + 1, currentSpot.getCol())
        && noPosAnterior(currentSpot.getFil() + 1,currentSpot.getCol())){
        alternativas.push(Punto(currentSpot.getFil() + 1,currentSpot.getCol(),0));
        currentSpot.setCantAlternativas(currentSpot.getCantAlternativas()+1);
    }
    if (posValida(currentSpot.getFil(), currentSpot.getCol() - 1)
        && noPosAnterior(currentSpot.getFil(),currentSpot.getCol() - 1)){
        alternativas.push(Punto(currentSpot.getFil(),currentSpot.getCol() - 1,0));
        currentSpot.setCantAlternativas(currentSpot.getCantAlternativas()+1);
    }
    if (posValida(currentSpot.getFil(), currentSpot.getCol() + 1)
        && noPosAnterior(currentSpot.getFil(),currentSpot.getCol() + 1)){
        alternativas.push(Punto(currentSpot.getFil(),currentSpot.getCol() + 1,0));
        currentSpot.setCantAlternativas(currentSpot.getCantAlternativas()+1);
    }
    if (posValida(currentSpot.getFil() - 1, currentSpot.getCol())
        && noPosAnterior(currentSpot.getFil() - 1,currentSpot.getCol())){
        alternativas.push(Punto(currentSpot.getFil() - 1,currentSpot.getCol(),0));
        currentSpot.setCantAlternativas(currentSpot.getCantAlternativas()+1);
    }
}
bool Laberinto::continuar(){
    string res;
    char tecla = ' ';
    bool flag;
    while (flag) {
        cout << "Continuar" << endl;
        cout << "Salir" << endl;
        cout<<"  >";
        system("pause > nul");
        if (GetKeyState(0x25) < 0){

        }
        else if (GetKeyState(0x27) < 0){

        }
        else if (GetKeyState(0x0D) < 0) {
            flag = false;
        }
    }
}
void Laberinto::iniciar(const Punto& entrada){
    if (laberinto.empty()) return;
    Punto currentSpot = entrada;
    bool flag = true;
    laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
    buscarAlternativas(currentSpot);
    visitados.push(currentSpot);
    print(currentSpot);
    while(flag){
        if (esSalida(currentSpot)){
            cout << "\n\t\t    YOU WIN, CHEESE IS YOURS!\n" << endl;
            break;
        }
        else if ((alternativas.size() == 0 || currentSpot.getCantAlternativas() == 0) && visitados.size() == 1){
            cout << "\n\t\tNO EXIT, NO CHEESE, NO SALVATION!\n" << endl;
            break;
        }
        else if (currentSpot.getCantAlternativas() == 1){
            visitados.top().setCantAlternativas(0);
            currentSpot = alternativas.top();
            alternativas.pop();
            buscarAlternativas(currentSpot);
            visitados.push(currentSpot);
            laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
        }
        else if (currentSpot.getCantAlternativas() == 0 && visitados.size() > 1){
            visitados.pop();
            if (visitados.top().getFil() == -1 && visitados.top().getCol() == -1){
                visitados.pop();
                buscarAlternativas(visitados.top());
                currentSpot = visitados.top();
            }
            else {
                buscarAlternativas(visitados.top());
                currentSpot = visitados.top();
            }
            laberinto[currentSpot.getFil()][currentSpot.getCol()] = '-';
        }
        else if (currentSpot.getCantAlternativas() > 1){
            currentSpot = alternativas.top();
            for (int i=0; i<visitados.top().getCantAlternativas(); i++){
                alternativas.pop();
            }
            visitados.push(Punto());
            buscarAlternativas(currentSpot);
            visitados.push(currentSpot);
            laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
        }
        print(currentSpot);
        //flag = continuar();
    }
    laberinto.clear();
    system("pause > nul");
}
void Laberinto::gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
void Laberinto::cuadro(int x1, int y1, int ancho, int alto){
    for(int i=x1; i < ancho + x1; i++){
        gotoxy(i,y1); // arriba
        cout<<char(205);
        gotoxy(i, y1 + alto); // abajo
        cout<<char(205);
    }
    for(int j=y1; j < alto + y1; j++){
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

#endif