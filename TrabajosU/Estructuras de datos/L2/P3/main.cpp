#include <iostream>

/*
 * Write a recursive function to find the combination of n objects
 * k at a time. Then write a program to test it. The formula is given below:
 * C (n, k) = factorial (n) / ((factorial (n − k) * (factorial (k))
 */

using namespace std;

double factorial(double n){
    if (n<=1) return 1;
    return factorial(n-1)*n;
}
double c(double n,double k){
    return (factorial(n) / (factorial(n-k) * factorial(k)));
}

int main() {
    double n,k;
    n = 5;
    k = 3;
    cout << "Las combinaciones posibles de c(" << n << "," << k << ") son: " << c(n,k) << endl;
    k = 4;
    cout << "Las combinaciones posibles de c(" << n << "," << k << ") son: " << c(n,k) << endl;
    n = 20;
    k = 3;
    cout << "Las combinaciones posibles de c(" << n << "," << k << ") son: " << c(n,k) << endl;

    return 0;
}
