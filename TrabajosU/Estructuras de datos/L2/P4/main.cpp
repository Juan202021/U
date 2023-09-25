#include <iostream>
#include <cmath>

using namespace std;

/*
 * Write a recursive tail function that reverses the digits in its argument. For
 * example, given the integer 12789, the function returns 98721. Then use a
 * nonrecursive function to call it. Test the functions in a program.
 */

string reverseInt(int num, string res){
    if (num < 1 ) return res;
    res += to_string(num%10);
    return reverseInt(num/10,res);
}
string reverseInt(int num){
    return reverseInt(num,"");
}
int main() {
    cout << reverseInt(24) << endl;
    cout << reverseInt(34658) << endl;
    cout << reverseInt(293) << endl;
    cout << reverseInt(2) << endl;
    cout << reverseInt(293457568) << endl;
    return 0;
}
