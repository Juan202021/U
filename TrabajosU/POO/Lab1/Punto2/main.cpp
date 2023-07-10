#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void palindromo(string palabra){
    string palabra_alreves = "";

    palabra.erase(remove(palabra.begin(), palabra.end(), ' '), palabra.end());

    for (int i=0; i<palabra.length(); i++){
        palabra[i] = tolower(palabra[i]);
    }

    for (int i=palabra.length()-1; i>=0; i--){
        palabra_alreves += palabra[i];
    }

    if (palabra.compare(palabra_alreves)==0){
        cout << "Es palindromo" << endl;
    } else {
        cout << "No es palindromo" << endl;
    }
}

int main()
{
    string palabra;
    getline(cin,palabra);

    palindromo(palabra);

    return 0;
}
