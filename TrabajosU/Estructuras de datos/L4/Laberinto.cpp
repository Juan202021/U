#ifndef L4_LABERINTO_CPP
#define L4_LABERINTO_CPP
#include "Laberinto.h"
#include <conio.h>
#include <filesystem>

Laberinto::Laberinto(){
    laberinto = {};
    laberintoCopia = {};
}
Laberinto::Laberinto(vector<vector<char>>& laberinto, Stack<Punto>& visitados, Stack<Punto>& alternativas):
        visitados(visitados), alternativas(alternativas), laberinto(laberinto), laberintoCopia(laberinto){}

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
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    string docu,linea,fila;
    int i=0;
    string titulo = " Seleccione el archivo del cual desea cargar el laberinto ";
    titulo.insert(titulo.begin(),char(254));
    titulo.push_back(char(254));
    vector<string> opciones;
    erase(1,1,71,20);
    cuadro(0,0,72,21);
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
    i = plantilla_menu(titulo, opciones, 24,8);
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
            SetConsoleTextAttribute(hConsole, 4);
            cout << "- El laberinto no cumple con las condiciones minimas. -" << endl;
            laberinto = {};
            this_thread::sleep_for(chrono::seconds(2));
            return false;
        }
    } else {
        gotoxy(11,18);
        cout << "- No se pudo abrir el archivo. -\n";
        this_thread::sleep_for(chrono::seconds(2));
        return false;
    }
    laberintoCopia = laberinto;
    return true;
}
void Laberinto::print(const Punto& currentSpot = Punto(), int x = 2, int y = 1){
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    SetConsoleTextAttribute(hConsole, 9);
    for (int i=0; i<laberinto.size(); i++){
        gotoxy(x,y+i);
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
    //this_thread::sleep_for(chrono::seconds(1));
}
void Laberinto::print2(const Punto& currentSpot, int x, int y){
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    SetConsoleTextAttribute(hConsole, 9);
    for (int i=0; i<laberintoCopia.size(); i++){
        gotoxy(x,y+i);
        for (int j=0; j<laberintoCopia[0].size(); j++){
            if (laberinto[i][j] == '#'){
                cout << "\x1b[33m" << char(219) << "\x1b[0m";
                //cout << "\x1b[35m" << char(219) << "\x1b[0m";
            }
            else if (i == currentSpot.getFil() && j == currentSpot.getCol()){
                cout << "\x1b[5;35;46m" << char(254) << "\x1b[0m";
                //cout << "\x1b[5;34;46m" << char(254) << "\x1b[0m";
            }
            else {
                cout << "\x1b[34m" << char(219) << "\x1b[0m"; //espacio azul
                //cout << "\x1b[1;33m" << char(219) << "\x1b[0m";
            }
        }
        cout << endl;
    }
    //this_thread::sleep_for(chrono::seconds(1));
}
void Laberinto::printPos(Punto& lastSpot, Punto& currentSpot, int x, int y){
    for (int i=0; i<laberinto.size(); i++){
        for (int j=0; j<laberinto[0].size(); j++){
            gotoxy(x+j,y+i);
            if (i == lastSpot.getFil() && j == lastSpot.getCol()){
                if (laberinto[i][j] == ' ') cout << "\x1b[34m" << char(219) << "\x1b[0m";
                else { cout << "\x1b[33m" << char(219) << "\x1b[0m"; }
            }
            gotoxy(x+j,y+i);
            if (i == currentSpot.getFil() && j == currentSpot.getCol()){
                if (laberinto[i][j] == ' ') cout << "\x1b[5;35;44m" << char(254) << "\x1b[0m";
                else { cout << "\x1b[5;35;43m" << char(254) << "\x1b[0m"; }
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
void Laberinto::printPos2(Punto& lastSpot, Punto& currentSpot, int x, int y){
    for (int i=0; i<laberintoCopia.size(); i++){
        for (int j=0; j<laberintoCopia[0].size(); j++){
            gotoxy(x+j,y+i);
            if (i == lastSpot.getFil() && j == lastSpot.getCol()){
                cout << "\x1b[36m" << char(219) << "\x1b[0m";
            }
            gotoxy(x+j,y+i);
            if (i == currentSpot.getFil() && j == currentSpot.getCol()){
                cout << "\x1b[5;35;46m" << char(254) << "\x1b[0m";
            }
        }
        cout << endl;
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
void Laberinto::printInfo(){
    gotoxy(2,17);
    cout << "\x1b[33m" << char(219) << "\x1b[0m" << " Paredes ";
    gotoxy(2,18);
    cout << "\x1b[34m" << char(219) << "\x1b[0m" << " Camino no recorrido ";
    gotoxy(2,19);
    cout << "\x1b[36m" << char(219) << "\x1b[0m" << " Camino recorrido una vez ";
    gotoxy(2,20);
    cout << "\x1b[31m" << char(219) << "\x1b[0m" << " Camino recorrido mas de una vez";
}
void Laberinto::iniciar(const Punto& entrada){
    HANDLE hConsole(GetStdHandle(STD_OUTPUT_HANDLE));
    Punto currentSpot = entrada;
    bool flag = true;
    List<Punto> spots;
    erase(1,1,71,20);
    laberinto[currentSpot.getFil()][currentSpot.getCol()] = 'O';
    buscarAlternativas(currentSpot);
    visitados.push(currentSpot);
    spots.insert(0,currentSpot);
    cuadro(0,0,25,12);
    cuadro(0,13,72,8);
    cuadro(26,0,46,12);
    erase(1,1,23,10);
    print(currentSpot,1,1);
    printInfo();
    while(flag){
        if (esSalida(currentSpot)){
            gotoxy(41,15);
            SetConsoleTextAttribute(hConsole, 5);
            cout << "YOU WIN, CHEESE IS YOURS!\n" << endl;
            break;
        }
        else if ((alternativas.size() == 0 || currentSpot.getCantAlternativas() == 0) && visitados.size() == 1){
            gotoxy(36,15);
            SetConsoleTextAttribute(hConsole, 4);
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
        print(currentSpot,1,1);
    }
}
int Laberinto::getTamanioF(){ return laberinto.size(); }
int Laberinto::getTamanioC(){ return laberinto[0].size(); }
void Laberinto::printPuntosRecorridos() {
    int y = 1;
    Stack<Punto> stack = visitados;
    stack.reverseContent();
    erase(27,1,44,11);
    for (int i = 0; i < visitados.size(); i++){
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
        if (stack.top()!=Punto()) {
            cout << stack.top();
            y++;
        }
        stack.pop();
    }
}
void Laberinto::printCamino(Punto currentSpot){
    Punto lastSpot;
    Stack<Punto> visitadosCopia = visitados;
    visitadosCopia.reverseContent();
    erase(27,1,44,11);
    print2(currentSpot,27,1);
    while (visitadosCopia.size() > 0){
        lastSpot = currentSpot;
        currentSpot.setFil(visitadosCopia.top().getFil());
        currentSpot.setCol(visitadosCopia.top().getCol());
        visitadosCopia.pop();
        printPos2(lastSpot,currentSpot,27,1);
        this_thread::sleep_for(chrono::seconds(1/2));
    }
}
void Laberinto::reset(){
    laberinto.clear();
    visitados.~Stack();
    visitados = Stack<Punto>();
    alternativas.~Stack();
    alternativas = Stack<Punto>();
}
int Laberinto::visitadosSize(){ return visitados.size(); }


#endif