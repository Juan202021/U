#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

float distancia_euclideana(int[], int[]);
void to_int(string, string);
const int tam=3;

int main()
{
    string str1, str2;

    cout << "Digite el punto 1: ";
    getline(cin,str1);
    cout << "Digite el punto 2: ";
    getline(cin,str2);

    to_int(str1,str2);

    return 0;
}
void to_int(string str1, string str2){
    int p[tam], q[tam];
    str1.erase(remove(str1.begin(), str1.end(), '('), str1.end());
    str1.erase(remove(str1.begin(), str1.end(), ','), str1.end());
    str1.erase(remove(str1.begin(), str1.end(), ')'), str1.end());
    str2.erase(remove(str2.begin(), str2.end(), '('), str2.end());
    str2.erase(remove(str2.begin(), str2.end(), ','), str2.end());
    str2.erase(remove(str2.begin(), str2.end(), ')'), str2.end());
    for (int i=0; i<tam; i++){
        p[i] = str1[i];
        q[i] = str2[i];
    }
    cout << fixed << setprecision(2);
    cout << "\nLa distancia euclideana entre los puntos es: " << distancia_euclideana(p,q) << endl;
}

float distancia_euclideana(int p[], int q[]){
    float distancia=0.0;
    for (int i=0; i<tam; i++){
        distancia += pow((p[i] - q[i]),2);
    }
    return sqrt(distancia);
}
