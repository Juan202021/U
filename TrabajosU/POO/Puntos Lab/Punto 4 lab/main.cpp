#include <iostream>

using namespace std;

void calcular_tiempo(int);

int main() {
    int min;
    cout << "Ingrese el numero de minutos: ";
    cin >> min;

    calcular_tiempo(min);
    return 0;
}
void calcular_tiempo(int minutos){
    int dias=0, anios=0, minu=minutos;
    while (minutos >= 1440){
        minutos -= 1440;
        dias += 1;
        if (dias >= 365){
            anios += 1;
            dias -= 365;
        }
    }
    cout << "\n" << minu << " minutos son aproximadamente " << anios << " anios y "
        << dias << " dias." << endl;
}
