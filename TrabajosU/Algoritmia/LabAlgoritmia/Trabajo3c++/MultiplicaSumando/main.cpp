#include <iostream>

using namespace std;

int main()
{
    int n1, n2, res=0;
    cout << "Digite el primer numero:" << endl;
    cin >> n1;
    cout << "Digite el segundo numero:" << endl;
    cin >> n2;

    for (int i=1; i<=n1; i++)
    {
        res += n2;
    }
    cout << "El resultado de la multiplicacion es: " << res <<endl;

    return 0;
}
