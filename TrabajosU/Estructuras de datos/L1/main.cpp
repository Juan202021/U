#include <iostream>

using namespace std;



template<typename T, int N>
void findValue(T (&arreglo)[N], T valor){
    bool noEncontrado = true;
    for(int i=0; i<N; i++){
        if (arreglo[i] == valor){
            cout << "El valor - " << valor << " - se encuentra en el indice: " << i << endl;
            noEncontrado=false;
            break;
        }
    }
    if(noEncontrado){ cout << "El valor - " << valor << " - NO se encuentra en el arreglo" << endl; }
}

template<typename T, int N>
void print(T(&array)[N]){
    for(int i=0; i < N; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

template<typename T>
void swapElements(T &a, T &b){
    T aux = a;
    a = b;
    b = aux;
}

template<typename T, int N>
void reverseArray(T (&arreglo)[N]){
    cout << "Arreglo antes: ";
    print(arreglo);
    for(int i=0; i<N/2; i++){
        swapElements(arreglo[i],arreglo[N-i-1]);
    }
    cout << "Arreglo despues: ";
    print(arreglo);
}


int main() {
    int arrayInt[] = {1,3,6,8};
    char arrayChar[] = {'a','b','c','d'};
    double arrayDouble[] = {234.5,23534.2,1.45,89.2266, 1.1};
    string arrayString[] = {"Santiago","Juan", "Camilo", "Dhanielt", "Sofia"};

    reverseArray(arrayInt);
    reverseArray(arrayDouble);
    reverseArray(arrayChar);
    reverseArray(arrayString);

    findValue(arrayInt,3);
    findValue(arrayInt,8);
    findValue(arrayInt,10);
    findValue(arrayChar,'b');
    findValue(arrayChar,'c');
    findValue(arrayChar,'T');


    return 0;
}
