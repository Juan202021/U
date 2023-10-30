//
// Created by Juan on 10/13/2023.
//
#ifndef L4_LABERINTO_CPP
#define L4_LABERINTO_CPP
#include "Laberinto.h"
#include "interfaces.h"
#include <conio.h>
#include <limits>
#include <filesystem>

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
    if (laberinto.empty()) return false;
    auto tam = laberinto[0].size();
    for (const auto& fil : laberinto){
        for (auto pos:fil){
            if (pos != ' ' && pos != '#') return false;
        }
    }
    for (const auto& fil : laberinto){
        if (fil.size() != tam || tam > 22 || laberinto.size() > 11 || tam < 3 || laberinto.size() < 3) return false;
    }
    return true;
}
bool Laberinto::cargar(){
    string docu,linea,fila;
    int i=0;
    string titulo = " Seleccione el archivo del cual desea cargar el laberinto ";
    titulo.insert(titulo.begin(),char(254));
    titulo.push_back(char(254));
    vector<string> opciones;
    erase(1,1,71,20);
    string directorio = "C:\\Users\\Juan\\JAristizabal\\U\\TrabajosU\\Estructuras de datos\\L4"; // Reemplaza con la ruta de tu directorio

    for (const auto& entry : filesystem::directory_iterator(directorio)) {
        if (filesystem::is_regular_file(entry) && entry.path().extension() == ".txt") {
            // Verificar si el nombre del archivo no es "CMakeLists.txt" ni "ColorTexto.txt"
            auto nombreArchivo = entry.path().filename();
            if (nombreArchivo != "CMakeLists.txt" && nombreArchivo != "ColorTexto.txt") {
                docu = nombreArchivo.string();
                opciones.push_back(docu);
            }
        }
    }
    i = menu(titulo,opciones,8);
    // Abrir el archivo
    ifstream archivo(directorio + "\\" + opciones[i-1]);
    if (archivo.is_open()) {
        i = 0;
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
            gotoxy(9,18);
            SetConsoleTextAttribute(hConsol, 4);
            cout << "- El laberinto no cumple con las condiciones minimas. -" << endl;
            return false;
        }
    } else {
        gotoxy(11,18);
        cout << "- No se pudo abrir el archivo. -\n";
        return false;
    }
    return true;
}
void Laberinto::print(const Punto& currentSpot = Punto()){
    SetConsoleTextAttribute(hConsol, 9);
    cuadro(0,0,25,12);
    cuadro(0,13,72,8);
    cuadro(26,0,46,12);
    erase(1,1,23,10);
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
}
void Laberinto::printPos(const Punto& currentSpot = Punto()){
    erase(25,2,42,12);
    for (int i=0; i<laberinto.size(); i++){
        gotoxy(25,2+i);
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
void Laberinto::printSPots(const List<Punto>& spots){
    int y = 1;
    erase(27,1,44,11);
    for (int i = spots.size()-1 ; i>=0; i--){
        if ( y == 55){
            gotoxy(63,y-44);
            cout << "..." << endl;
            return;
        }
        else if (y > 11 && y <= 22){
            gotoxy(36,y-11);
        }
        else if (y > 22 && y <= 33){
            gotoxy(45,y-22);
        }
        else if (y > 33 && y <= 44){
            gotoxy(54,y-33);
        }
        else if (y > 44 && y <= 55){
            gotoxy(63,y-44);
        }
        else {
            gotoxy(27,y);
        }
        cout << spots.get(i) << endl;
        y++;
    }
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
    Punto currentSpot = entrada;
    bool flag = true;
    List<Punto> spots;
    erase(1,1,71,20);
    laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
    buscarAlternativas(currentSpot);
    visitados.push(currentSpot);
    spots.insert(0,currentSpot);
    print(currentSpot);
    printSPots(spots);
    while(flag){
        if (esSalida(currentSpot)){
            gotoxy(24,15);
            cout << "YOU WIN, CHEESE IS YOURS!\n" << endl;
            break;
        }
        else if ((alternativas.size() == 0 || currentSpot.getCantAlternativas() == 0) && visitados.size() == 1){
            gotoxy(20,15);
            cout << "NO EXIT, NO CHEESE, NO SALVATION!\n" << endl;
            break;
        }
        else if (currentSpot.getCantAlternativas() == 1){
            visitados.top().setCantAlternativas(0);
            currentSpot = alternativas.top();
            alternativas.pop();
            buscarAlternativas(currentSpot);
            visitados.push(currentSpot);
            spots.insert(0,currentSpot);
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
            spots.insert(0,currentSpot);
        }
        else if (currentSpot.getCantAlternativas() > 1){
            currentSpot = alternativas.top();
            for (int i=0; i<visitados.top().getCantAlternativas(); i++){
                alternativas.pop();
            }
            visitados.push(Punto());
            buscarAlternativas(currentSpot);
            visitados.push(currentSpot);
            spots.insert(0,currentSpot);
            laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
        }
        print(currentSpot);
        printSPots(spots);
        //flag = continuar();
    }
    laberinto.clear();
    printSPots(spots);
    //gotoxy(11,17);
    //cout << char(254)<< " Digite una tecla para volver al menu principal. " << char(254) << endl;
    //system("pause > nul");
}



#endif