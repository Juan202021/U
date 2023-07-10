#include <iostream>
#include <string>

using namespace std;

int calcular_dias(int,int);
string calcular_mes(int);

int main() {
    int mes, anio;
    cout << "Introduzca el numero de mes: ";
    cin >> mes;
    cout << "Introduzca el anio: ";
    cin >> anio;

    cout << calcular_mes(mes) << " del " << anio << " tiene " << calcular_dias(mes,anio) << " dias." << endl;

    return 0;
}
int calcular_dias(int mes,int anio){
    int dias;
    if (anio%4==0){
        if (anio%100 != 0 || anio%400 == 0){
            if (mes == 2){
                dias = 29;
                return dias;
            }
        }
    }
    if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        dias = 31;
    }
    else if(mes==4 || mes==6 || mes==9 || mes==11){
        dias = 30;
    }
    else {
        dias = 28;
    }
    return dias;
}

string calcular_mes(int mes){
    string nombre_mes;
    if (mes==1) nombre_mes = "Enero";
    else if (mes==2) nombre_mes = "Febrero";
    else if (mes==3) nombre_mes = "Marzo";
    else if (mes==4) nombre_mes = "Abril";
    else if (mes==5) nombre_mes = "Mayo";
    else if (mes==6) nombre_mes = "Junio";
    else if (mes==7) nombre_mes = "Julio";
    else if (mes==8) nombre_mes = "Agosto";
    else if (mes==9) nombre_mes = "Septiembre";
    else if (mes==10) nombre_mes = "Octubre";
    else if (mes==11) nombre_mes = "Noviembre";
    else nombre_mes = "Diciembre";
    return nombre_mes;
}
