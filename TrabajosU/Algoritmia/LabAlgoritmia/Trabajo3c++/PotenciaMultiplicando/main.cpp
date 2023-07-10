#include <iostream>

using namespace std;

int main()
{
    int n1, n2, res=1;
    cout << "Digite la base:" << endl;
    cin >> n1;
    cout << "Digite el exponente:" << endl;
    cin >> n2;

    for (int i=1; i<=n2; i++)
    {
        res *= n1;
    }
    cout << "El resultado de la potencia es: " << res <<endl;
}
