#include <iostream>

using namespace std;

class Curso{
    string nombre;
    int cantidadEstudiantes;
    float *ptr;
public:
    Curso(){};
    Curso(string nombre, int cantidadEstudiantes, float *ptr){
        this -> nombre = nombre;
        this -> cantidadEstudiantes = cantidadEstudiantes;
        this -> ptr = ptr;
    }

    string getNombre(){ return nombre; }
    void setNombre(string nombre){ this -> nombre = nombre; }

    int getcantidadEstudiantes(){ return cantidadEstudiantes; }
    void setcantidadEstudiantes(int cantidadEstudiantes){ this -> cantidadEstudiantes = cantidadEstudiantes; }

    float* getPtr(){ return ptr; }
    void setPtr(float *ptr){ this -> ptr = ptr; }
};

void determinarMejorPromedio(Curso *obj1, Curso *obj2){
    float promedio1 = 0.0;
    float promedio2 = 0.0;
    for(int i=0; i<obj1->getcantidadEstudiantes(); i++){
        promedio1 += obj1->getPtr()[i];
    }
    for(int i=0; i<obj2->getcantidadEstudiantes(); i++){
        promedio2 += obj2->getPtr()[i];
    }
    if ((promedio1/obj1->getcantidadEstudiantes())>(promedio2/obj2->getcantidadEstudiantes())){
        cout << "El curso " << obj1->getNombre() << " tiene el mejor promedio";
    } else if ((promedio1/obj1->getcantidadEstudiantes())<(promedio2/obj2->getcantidadEstudiantes())){
        cout << "El curso " << obj2->getNombre() << " tiene el mejor promedio";
    } else {
        cout << "Los cursos " << obj1->getNombre() << " y " << obj2->getNombre() << " tienen el mismo promedio";
    }
}

int main() {
    float notasC1[] = {2,5,1,2,4.1, 3};
    float notasC2[] = {2,3.9,2,1};
    Curso c1("Algebra", 6, notasC1);
    Curso c2("POO", 4, notasC2);

    determinarMejorPromedio(&c1,&c2);


    return 0;
}
