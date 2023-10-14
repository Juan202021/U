#ifndef LIST_CPP
#define LIST_CPP

#include <string>
#include <fstream>
#include <cstdlib>
#include "List.h"
#include "Punto.h"
template<typename T>
List<T>:: List(): begin(nullptr), count(0){}

template<typename T>
List<T>:: ~List()
{
    Node<T>* del = begin;
    while (begin)
    {
        begin = begin->next;
        delete del;
        del = begin;
    }
}

template <>
List<int>::List(const List<int>& l) {
    Node<int>* nodoACopiar = l.begin;
    this->count = 0;
    this->begin = nullptr;
    while (nodoACopiar) {
        // Copia el elemento
        this->insert(this->size(), nodoACopiar->data);
        nodoACopiar = nodoACopiar->next;
    }
}

template<typename T>
Node<T>* List<T>::makeNode(const T &value){
    Node<T>* temp = new Node<T>;
    temp->data = value;
    temp->next = 0;
    return temp;
}
template<typename T>
void List<T>::insert(int pos, const T &value){
    if(pos < 0 || pos>count)
    {
        cout << "Error! The position is out of range." << endl;
        return;
    }
    Node<T>* add = makeNode(value);
    if(pos == 0)
    {
        add->next = begin;
        begin = add;
    }
    else
    {
        Node<T>* cur = begin;
        for(int i=0; i<pos-1; i++)
        {
            cur = cur->next;
        }
        add->next = cur->next;
        cur->next = add;
    }
    count++;
}
template<typename T>
int List<T>::size() const{
    return count;
}
template<typename T>
void List<T>::erase(int pos) {
// Verificar si la posición es válida
    if(pos < 0 || pos>=count){
        cout << "Error! The position is out of range." << endl;
        return;
    }
//Verificar si la posición es la primera (posición 0)
    if(pos == 0){
// Eliminar el primer nodo
        Node<T>* del = begin;
        begin = begin->next;
        delete del;
    }else{
// Encontrar el nodo anterior al que se quiere eliminar
        Node<T>* cur = begin;
        for(int i=0; i<pos-1; i++){
            cur = cur->next;
        }
// Eliminar el nodo en la posición dada
// Comienzar ejercicio 3
        Node<T>* del =  cur->next;
        cur->next = del->next;
        delete del;
// Fin del ejercicio 3
    }
// Reducir el contador de elementos en la lista
    count--;
}

template<typename T>
T& List<T>::get(int pos) const{
// Verificar si la posición es válida (dentro del rango permitido)
    if(pos < 0 || pos>count-1){
        cout << "Error! The position is out of range." << endl;
        assert(false);
    }
// Si la posición es 0, devolver el valor del primer elemento
    if(pos == 0){
        return begin->data;
    }else{
// Comienzar ejercicio 4
// Agregar tu código aquí
        Node<T>* cur = begin;
        for(int i=0; i<pos; i++){
            cur = cur->next;
        }
        return cur->data;
// Fin del ejercicio 4
    }
}
template<typename T>
void List<T>::print() const{
// Verificar si la lista está vacía
    if(count == 0){
        cout << "List is empty." << endl;
        return;
    }
    Node<T>* cur = begin;
// Usar un bucle while para recorrer la lista y mostrar sus elementos. Se ejecuta mientras cur apunte a un nodo válido en la lista.
    while(cur){
        cout<<cur->data<<" ";
         // Imprimir el valor del nodo actual
         cur = cur->next; // Avanzar al siguiente nodo en la lista
    }
}

template<typename T>
void List<T>::printReverse() const {
    if(count == 0){
        cout << "List is empty." << endl;
        return;
    }
    for (int i=count-1; i>=0; i--){
        cout << get(i) << " ";
    }
}

template <>
List<int>& List<int>::operator=(const List<int> &l){
    if (this != &l) {
        Node<int>* del = begin;
        while (begin){
            begin = begin->next;
            delete del;
            del = begin;
        }
        Node<int>* nodoACopiar = l.begin;
        this->count = 0;
        this->begin = nullptr;
        while (nodoACopiar) {
            // Copia el elemento
            this->insert(this->size(), nodoACopiar->data);
            nodoACopiar = nodoACopiar->next;
        }
    }
    return *this;
}

template<>
bool List<int>::operator==(List<int> &l){
    if (this->size() != l.size()) return false;
    for (int i=0; i<this->size(); i++){
        if (this->get(i) != l.get(i)){
            return false;
        }
    }
    return true;
}

template <>
List<int> List<int>::operator+(List<int> &l){
    int acarreo = 0;
    List<int> res;
    if (this->size() > l.size()) {
        for (int i = 0; i < this->size(); i++) {
            int suma = this->get(i) + ((i < l.size()) ? l.get(i) : 0) + acarreo;
            if (suma >= 10) {
                acarreo = 1;
                suma -= 10;
            } else {
                acarreo = 0;
            }
            res.insert(i, suma);
        }
    } else {
        for (int i = 0; i < l.size(); i++) {
            int suma = (i < this->size() ? this->get(i) : 0) + l.get(i) + acarreo;
            if (suma >= 10) {
                suma -= 10;
                acarreo = 1;
            } else {
                acarreo = 0;
            }
            res.insert(i, suma);
        }
    }
    if (acarreo == 1) {
        res.insert(this->size() > l.size() ? this->size() : l.size(), acarreo);
    }
    return res;
}

template <>
List<int>& List<int>::operator++(){
    List<int> sumar,cont;
    sumar.insert(0,1);
    *this = *this + sumar;
    return *this;
}

template<>
List<int> List<int>::operator*(List<int> &l) {
    List<int> res;
    List<int> counter;
    res.insert(0,0);
    counter.insert(0,0);
    bool flag = true;
    if (this->size() > l.size()) {
        while (flag) {
            res = (*this) + res;
            ++counter;
            if (counter==l) flag = false;
        }
    } else {
        while (flag) {
            res = l + res;
            ++counter;
            if (counter==*this) flag = false;
        }
    }
    return res;
}

template<>
void List<int>::crear_ngrande(){
    string num;
    cout<<"Ingrese el numero grande: ";
    cin>>num;
    bool esEntero = true;
    for (char c : num) {
        if (!isdigit(c)) {
            esEntero = false;
            break;
        }
    }
    if (esEntero){
        for (char a: num) {
            int numero = a - '0';
            this->insert(0, numero);
        }
    } else {
        cout << "\n\n\t- Error! la entrada es invalida. -\n" << endl;
    }
}

template<>
void List<int>::archivo(vector<List<int>>& listas){
    string docu,linea,numero;
    cout<<"Ingrese el nombre del archivo sin ninguna extension, solo el nombre del archivo: ";
    cin>>docu;
    // Abrir el archivo
    ifstream archivo("C:\\Users\\Juan\\JAristizabal\\U\\TrabajosU\\Estructuras de datos\\L3\\L3\\" + docu + ".txt");
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            numero+=linea;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo";
    }
    bool esEntero = true;
    for (char c : numero) {
        if (!isdigit(c)) {
            esEntero = false;
            break;
        }
    }
    if (esEntero){
        for (char a: numero) {
            int num = a - '0';
            this->insert(0, num);
        }
        listas.push_back(*this);
    } else {
        cout << "\n\n\t- Error! el archivo contiene elementos no enteros. -\n" << endl;
    }
    archivo.close();
}

template class List<string>;
template class List<double>;
template class List<int>;
template class List<Punto<double>>;
#endif