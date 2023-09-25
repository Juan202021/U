#include "list.h"
#include "Punto.h"
using namespace std;
int main()
{
    List<string> list;
    list.insert(0, "nestor");
    list.insert(1, "victor");
    list.insert(2, "Maria");
    list.insert(3, "juan");
    list.insert(4, "pedro");
    list.print();
    cout << endl;
    list.printReverse();
    cout << "\nSize sin del: " << list.size() << endl;
    cout << "Element (Maria): " << list.get(2) << endl;

    list.erase(2);
    list.print();
    cout << "\nSize con del: " << list.size() << endl;
    cout << "Element (juan): " << list.get(2) << endl;

    List<double> listD;
    listD.insert(0,1.4);
    listD.insert(1,7.3);
    listD.insert(2,8.4);
    cout << endl;
    listD.print();
    cout << endl;
    listD.printReverse();
    cout << "\nSize: " << listD.size() << endl;
    cout << "Element (7.3): " << listD.get(1) << endl;
    listD.erase(1);
    listD.print();
    cout << "\nSize: " << listD.size() << endl;
    cout << "Element (8.4): " << listD.get(1) << endl;

    List<Punto<double>> lp;
    lp.insert(0,Punto(3.4,3.5));
    lp.insert(1,Punto(5.4,7.5));
    lp.insert(2,Punto(4.7,9.1));
    lp.insert(3,Punto(3.4,3.7));
    cout << endl;
    lp.print();
    cout << endl;
    lp.printReverse();
    cout << "\nSize sin del: " << lp.size() << endl;
    cout << "Element (Punto(4.7,9.1)): " << lp.get(2) << endl;
    lp.erase(2);
    lp.print();
    cout << "\nSize con del: " << list.size() << endl;
    cout << "Element (Punto(3.4,3.7)): " << lp.get(2) << endl;

    return 0;
}
