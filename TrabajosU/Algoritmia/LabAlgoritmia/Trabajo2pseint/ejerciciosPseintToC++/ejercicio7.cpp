#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "***Programa para calcular la distancia entre dos puntos***" << endl;
    float x1, x2, y1, y2, xT, yT, distancia;
    cout << "Digite la coordenada x del primer punto: ";
    cin >> x1;
    cout << "Digite la coordenada y del primer punto: ";
    cin >> y1;
    cout << "Digite la coordenada x del segundo punto: ";
    cin >> x2;
    cout << "Digite la coordenada y del segundo punto: ";
    cin >> y2;
    xT = x2-x1;
	yT = y2-y1;
	distancia = sqrt(xT*xT + yT*yT);
    cout << "La distancia entre los dos puntos es de: "<< distancia<< endl;

    return 0;
}
