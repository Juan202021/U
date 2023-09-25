#include <iostream>

/*
 * Write a recursive function that counts and prints the number
 * of a given character in a string. Test the function in a program.
 */
using namespace std;

int countChar(string str, char letter, int found){
    if (str.length() < 1) return found;
    else if (str[0] == letter) found++;
    return countChar(str.substr(1,str.length()-1),letter,found);
}
int countChar(string str, char letter){
    return countChar(str,letter,0);
}

int main() {
    string a = "Hello world";
    cout << countChar(a,'l') << endl;
    cout << countChar(a,'e') << endl;
    cout << countChar(a,'o') << endl;
    cout << countChar(a,' ') << endl;
    return 0;
}
