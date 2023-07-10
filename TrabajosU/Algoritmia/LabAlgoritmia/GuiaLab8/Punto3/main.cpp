#include <iostream>

using namespace std;

int main()
{
    int matriz[4][4];

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (i==j){
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }

    for (int k=0; k<4; k++){
        for (int l=0; l<4; l++){
            cout << matriz[k][l] << " ";
            if ((l==3) && (k==0 || k==1 || k==2 || k==3)){
                cout << endl;
            }
        }
    }
    return 0;
}
