#include <iostream>

using namespace std;

int main()
{
    int matriz[3][3] = {{4,3,1}, {5,8,8}, {1,2,7}};
    int transpuesta[3][3];

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            transpuesta[j][i] = matriz[i][j];
        }
    }

    cout << "Matriz original: " << endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << matriz[i][j] << " ";
            if ((j==2) && (i==0 || i==1 || i==2)){
                cout << endl;
            }
        }
    }

    cout << endl;
    cout << "Matriz transpuesta: " << endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << transpuesta[i][j] << " ";
            if ((j==2) && (i==0 || i==1 || i==2)){
                cout << endl;
            }
        }
    }


    return 0;
}
