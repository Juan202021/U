#include <iostream>
#include <cmath>

using namespace std;

class Forma {
protected:
    float lado;
public:
    Forma() { lado = 0.0; }

    Forma(float lado) { this->lado = lado; }

    float getLado() { return lado; }

    void setLado(float lado) {
        this->lado = lado;
    }
};

class Cuadrado : public Forma {
public:
    Cuadrado() : Forma() {}
    Cuadrado(float lado) : Forma(lado) {}

    float getArea() { return lado * lado; }
    float getPerimetro() { return lado * 4; }

    friend ostream& operator<<(ostream &out, Cuadrado c) {
        out << "Lado: " << c.getLado() << endl;
        out << "Area: " << c.getArea() << endl;
        out << "Perimetro: " << c.getPerimetro() << endl;
        return out;
    };
};

class Cubo : public Cuadrado {
public:
    Cubo() : Cuadrado() {}
    Cubo(float lado) : Cuadrado(lado) {}

    float getSuperficie() { return (lado * lado) * 6; }
    float getVolumen() { return lado * lado * lado; }

    friend ostream& operator<<(ostream &out, Cubo c) {
        out << "Lado: " << c.getLado() << endl;
        out << "Superficie: " << c.getSuperficie() << endl;
        out << "Volumen: " << c.getVolumen() << endl;
        return out;
    }
};

class Rectangulo: public Forma {
protected:
    float largo;
public:
    Rectangulo() : Forma(),largo(0.0) {}
    Rectangulo(float largo, float lado) : Forma(lado), largo(largo) {}

    float getLargo(){ return largo; };
    void setLargo(float largo){ this -> largo = largo; };

    float getArea() { return (largo * lado); }
    float getPerimetro() { return largo * 2 + lado * 2; }
    friend ostream& operator<<(ostream &out, Rectangulo r) {
        out << "Lado: " << r.getLado() << endl;
        out << "Largo: " << r.getLargo() << endl;
        out << "Area: " << r.getArea() << endl;
        out << "Perimetro: " << r.getPerimetro() << endl;
        return out;
    }
};

class Cuboide: public Rectangulo{
    float altura;
public:
    Cuboide(): Rectangulo(), altura(0.0){}
    Cuboide(float lado, float largo, float altura): Rectangulo(largo, lado), altura(altura){}

    float getAltura(){ return altura; }
    void setAltura(float altura){ this -> altura = altura; }

    float getSuperficie(){ return 4*M_PI*(lado*lado); }
    float getVolumen(){ return (4/3)*M_PI*pow(lado,3); }
    friend ostream& operator<<(ostream &out, Cuboide c) {
        out << "Lado: " << c.getLado() << endl;
        out << "Largo: " << c.getLargo() << endl;
        out << "Altura: " << c.getAltura() << endl;
        out << "Superficie: " << c.getSuperficie() << endl;
        out << "Volumen: " << c.getVolumen() << endl;
        return out;
    }

};

class Circulo: public Forma {
public:
    Circulo(): Forma(){}
    Circulo(float lado):Forma(lado){}

    float getPerimetro(){ return M_PI*(lado*2); }
    float getArea(){ return M_PI*(lado*lado); }
    friend ostream& operator<<(ostream &out, Circulo c) {
        out << "Lado: " << c.getLado() << endl;
        out << "Area: " << c.getArea() << endl;
        out << "Perimetro: " << c.getPerimetro() << endl;
        return out;
    }
};

class Esfera: public Circulo{
public:
    Esfera(): Circulo(){}
    Esfera(float lado): Circulo(lado){}

    float getSuperficie(){ return 4*M_PI*(lado*lado); }
    float getVolumen(){ return (4/3)*M_PI*pow(lado,3); }
    friend ostream& operator<<(ostream &out, Esfera e) {
        out << "Lado: " << e.getLado() << endl;
        out << "Superficie: " << e.getSuperficie() << endl;
        out << "Volumen: " << e.getVolumen() << endl;
        return out;
    }
};

int main() {
    Cuadrado cua1;
    Cuadrado cua2;
    Rectangulo r1;
    Rectangulo r2;
    Circulo cir1;
    Circulo cir2;
    Cubo cubo1;
    Cubo cubo2;
    Cuboide cuboi1;
    Cuboide coboi2;
    Esfera esf1;
    Esfera esf2;
    int opc, opc2;
    float lado, largo, altura;

    do {
        cout << "###################################\n######## Gestion de Formas ########\n###################################\n" << endl;
        cout << "Menu: \n1.Crear formas\n2.Mostrar una forma\n3.Editar formas\n4.Eliminar forma\n5.Salir\n\n Que desea realizar"<<endl;
        cin >> opc;
        if (opc == 1){
            cout <<"Seleccione la forma que desea crear"<<endl;
            cout << "1.Cuadrado\n2.Cubo\n3.Rectangulo\n4.Cuboide\n5.Circulo\n6.Esfera"<<endl;
            cin >> opc2;
            if (opc2 == 1){
                cout <<"Seleccione en cual forma desea crear"<<endl;
                cout << "1. Forma 1\n2. Forma 2" <<endl;
                cin >> opc2;
                if (opc2==1){
                    cout << "Digite el lado: ";
                    cin >> lado;
                    cua1.setLado(lado);
                }
                else if (opc2==2){
                    cout << "Digite el lado: ";
                    cin >> lado;
                    cua2.setLado(lado);
                }
                else { cout << "--Digito una opcion incorrecta.--"<<endl; }
            }
            else if (opc2 == 2) {}
            else if (opc2 == 3){}
            else if (opc2 == 4){}
            else if (opc2 == 5){}
            else if (opc2 == 5){}
        }
        else if (opc == 2){
            cout <<"seleccione la figura"<<endl;
            cout << "1.Cuadrado\n2.Cubo\n3.Rectangulo\n4.Cuboide\n5.Circulo\n6.Esfera"<<endl;
            cin >> opc2;
            if (opc2 == 1){}
            else if (opc2 == 2) {}
            else if (opc2 == 3){}
            else if (opc2 == 4){}
            else if (opc2 == 5){}
            else if (opc2 == 5){}
        }
        else if (opc == 3){}
        else if (opc == 4){}
        else if (opc == 5){cout << "Adios" <<endl;}
        else {cout << "--Digito una opcion incorrecta.--"<<endl;}
    } while (opc != 5);


    return 0;
}