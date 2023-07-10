#include <iostream>
using namespace std;

class Camisa {
public:
    virtual ~Camisa(){};
    virtual string descripcion() = 0;
};

class CamisaDeportiva : public Camisa {
public:
    string descripcion() override {
        return "The result of the product A1.";
    }
};

class CamisaFormal : public Camisa {
    string descripcion() override {
        return "The result of the product A2.";
    }
};

class Pantalon {
public:
    virtual ~Pantalon(){};
    virtual string descripcion() = 0;
    virtual string AnotherUsefulFunctionB(Camisa &collaborator) = 0;
};

class PantalonDeportivo : public Pantalon {
public:
    string descripcion() override {
        return "The result of the product B1.";
    }
    string AnotherUsefulFunctionB(Camisa &collaborator) override {
        string result = collaborator.descripcion();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};

class PantalonFormal : public Pantalon {
public:
    string descripcion() override {
        return "The result of the product B2.";
    }
    string AnotherUsefulFunctionB(Camisa &collaborator) override {
        string result = collaborator.descripcion();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};

class Ropa {
public:
    virtual Camisa *CreateProductA() = 0;
    virtual Pantalon *CreateProductB() = 0;
};

class RopaDeportiva : public Ropa {
public:
    Camisa *CreateProductA() override {
        return new CamisaDeportiva();
    }
    Pantalon *CreateProductB() override {
        return new PantalonDeportivo();
    }
};

class RopaFormal : public Ropa {
public:
    Camisa *CreateProductA() override {
        return new CamisaFormal();
    }
    Pantalon *CreateProductB() override {
        return new PantalonFormal();
    }
};


void ClientCode(Ropa &factory) {
    Camisa *product_a = factory.CreateProductA();
    Pantalon *product_b = factory.CreateProductB();
    cout << product_b->descripcion() << "\n";
    cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
    delete product_a;
    delete product_b;
}

int main() {
    cout << "Client: Testing client code with the first factory type:\n";
    RopaDeportiva *f1 = new RopaDeportiva();
    ClientCode(*f1);
    delete f1;
    cout << std::endl;
    cout << "Client: Testing the same client code with the second factory type:\n";
    RopaFormal *f2 = new RopaFormal();
    ClientCode(*f2);
    delete f2;
    return 0;
}