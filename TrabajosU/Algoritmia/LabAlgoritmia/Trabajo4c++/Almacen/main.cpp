#include <iostream>

using namespace std;

int main()
{
    int opc=1, cant, valor, subTotal, total, formaPago, subtotalVentas=0, totalVentas=0, efectivo=0, cheque=0, tarjeta=0;
    while (opc==1 || opc==2)
    {
        cout << "----------------------------------------------------" << endl;
        cout << "                  ALMACEN DON JUAN" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Digite la accion que desea hacer: " << endl;
        cout << "Digite (1) si desea realizar una venta." << endl;
        cout << "Digite (2) si desea saber las ventas del dia." << endl;
        cout << "Digite cualquier otro numero si desea salir del programa." << endl;
        cin >> opc;
        switch(opc)
        {
        case 1:
            cout << "----------------------------------------------------" << endl;
            cout << "Ingrese la cantidad de camisas: ";
            cin >> cant;
            cout << "----------------------------------------------------" << endl;
            cout << "Ingrese el valor de cada camisa: ";
            cin >> valor;
            cout << "----------------------------------------------------" << endl;
            cout << "Ingrese la forma de pago: " << endl;
            cout << "Digite (1) si desea realizar el pago en efectivo." << endl;
            cout << "Digite (2) si desea realizar el pago con cheque." << endl;
            cout << "Digite (3) si desea realizar el pago con tarjeta." << endl;
            cin >> formaPago;
            switch(formaPago)
            {
            case 1:
                subTotal = cant * valor;
                total = subTotal*0.93;
                efectivo += 1;
                break;
            case 2:
                subTotal = cant * valor;
                total = subTotal*0.95;
                cheque += 1;
                break;
            case 3:
                subTotal = cant * valor;
                total = subTotal*0.98;
                tarjeta += 1;
                break;
            }
            cout << "----------------------------------------------------" << endl;
            cout << "El valor Subtotal es: " << subTotal<< endl;
            subtotalVentas += subTotal;
            cout << "El valor Total es: " << total<< endl;
            totalVentas += total;
            break;

        case 2:
            cout << "----------------------------------------------------" << endl;
            cout << "Cantidad de ventas pagadas en efectivo: " << efectivo << endl;
            cout << "Cantidad de ventas pagadas en cheque: " << cheque << endl;
            cout << "Cantidad de ventas pagadas en tarjeta: " << tarjeta << endl;
            cout << "Valor subtotal de las ventas del dia: " << subtotalVentas << endl;
            cout << "Valor total de las ventas del dia: " << totalVentas << endl;
            break;
        }
    }
    return 0;
}
