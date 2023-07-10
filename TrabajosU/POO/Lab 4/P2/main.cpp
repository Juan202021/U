#include <iostream>

using namespace std;

class Producto{
    string nombre;
    int precio;
public:
    Producto(){
        nombre = "";
        precio = 0;
    };
    Producto(string nombre, int precio){
        this -> nombre = nombre;
        this -> precio = precio;
    }
    string getNombre(){ return nombre; }
    void setNombre(string nombre){ this -> nombre = nombre; }

    int getPrecio(){ return precio; }
    void setPrecio(int precio){ this -> precio = precio; }

    friend ostream& operator<<(ostream &out, Producto &p){
        out << "Nombre: " << p.nombre << endl;
        out << "Precio: " << p.precio << endl;
        return out;
    }

    friend istream& operator>>(istream &in, Producto &p){
        cout << "Digite el nombre del producto: " << endl;
        in >> p.nombre;
        cout << "Digite el precio del producto: " << endl;
        in >> p.precio;
        return in;
    }

    Producto operator++(){
        precio++;
        return Producto("nuevo",precio);
    }

    Producto operator--(){
        precio--;
        return Producto("nuevo",precio);
    }

    Producto operator-(){
        precio = -precio;
        return Producto("nuevo",precio);
    }
};
void ordenar(Producto *productos){
    Producto aux;
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            if (productos[j].getPrecio() < productos[j+1].getPrecio()){
                aux = productos[j];
                productos[j] = productos[j+1];
                productos[j+1] = aux;
            }
        }
    }
    for (int x = 0; x < 4; x++) {
        cout << productos[x].getNombre() << " - " << productos[x].getPrecio() << endl;
    }
}

int main() {
    Producto p1("Salsa",2900);   // salsa
    Producto p2("Cebolla",1900); // carne
    Producto p3("Carne",7300);   // platano
    Producto p4("Platano",5100); // cebolla
    Producto p5 = Producto("xddd",54300);
    Producto arr[4] = {p1,p2,p3,p4};
    ordenar(arr);
    cout << "\n" << p5;

    cin >> p5;
    cout << "\n" << p5;
    -p5;
    cout << "\n" << p5;
    ++p5;
    cout << "\n" << p5;
    --p5;
    cout << "\n" << p5;

    return 0;
}
