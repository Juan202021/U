#include <iostream>
using namespace std;

int main()
{
    cout << boolalpha << "AND logico (&&)"
         << "\nfalse && false: " << ( false && false )
         << "\nfalse && true: " << ( false && true )
         << "\ntrue && false: " << ( true && false )
         << "\ntrue && true: " << ( true && true ) << "\n\n";
    cout << "OR logico (||)"
         << "\nfalse || false: " << ( false || false )
         << "\nfalse || true: " << ( false || true )
         << "\ntrue || false: " << ( true || false )
         << "\ntrue || true: " << ( true || true ) << "\n\n";
    cout << "NOT logico (!)"
         << "\n!false: " << ( !false )
         << "\n!true: " << ( !true ) << endl;
}
