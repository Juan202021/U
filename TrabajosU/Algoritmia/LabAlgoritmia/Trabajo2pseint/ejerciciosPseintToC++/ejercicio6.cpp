#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "***Programa para calcular el area de una figura***" << endl;
    float radio, hipotenusa, altura, areaTriangulo, areaCirculo, areaTotal;
    cout << "Digite el radio: ";
    cin >> radio;
    cout << "Digite la hipotenusa: ";
    cin >> hipotenusa;
    altura = sqrt(hipotenusa*hipotenusa - radio*radio);
	areaTriangulo = radio * altura;
	areaCirculo = (M_PI * radio*radio) / 2;
	areaTotal = areaTriangulo + areaCirculo;
    cout << "El area de la figura es: "<< areaTotal<< endl;

    return 0;
}
