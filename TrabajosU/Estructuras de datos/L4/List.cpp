#ifndef LIST_CPP
#define LIST_CPP

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
        //assert(false);
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

template class List<Punto>;
#endif