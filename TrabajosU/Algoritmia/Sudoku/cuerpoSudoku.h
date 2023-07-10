#define color SetConsoleTextAttribute // Se define a la función "SetConsoleTextAttribute", como "color".
#include <windows.h> // Libreria que me permite cambiar el color de el texto que se imprime por pantalla.

using namespace std;


/*
    La funcion "llenarConCeros", recibe como parametro la matriz llamada "sudoku", luego empieza
    a llenar dicha matriz de ceros, en todas las posiciones.
*/
void llenarConCeros(char sudoku[12][12])
{
    for (int fila=0; fila<12; fila++)
    {
        for (int col=0; col<12; col++)
        {
            sudoku[fila][col] = '0';
        }
    }
}


/*
    La funcion "aleatorio" genera un numero aleatorio entre 0 y 11, luego guarda un caracter del arreglo
    (entre 1 y C), en la variable llamada "caracter", usando ese numero aleatorio como la posicion en la
    que debe buscar en el arreglo "caracteresPosibles". Después la devuelve con el return.
*/
char aleatorio()
{
    int numeroAlearorio;
    char caracter;
    char caracteresPosibles[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    numeroAlearorio = rand() % 12;
    caracter = caracteresPosibles[numeroAlearorio];
    return caracter;
}


/*
    La funcion "llenarDiagonal", recibe como parametros: la matriz sudoku, dos números enteros
    llamados "iniciaFila" e "iniciaCol", los cuales representan el valor desde el cual se empezará
    a iterar las filas y el valor desde el cual se empezará a iterar las columnas; además recibe
    otros dos numeros enteros llamados "terminaFila" y "terminaCol", los cuales representan el valor
    hasta el cual se van a iterar las filas y el valor hasta el cual se van a iterar las columnas.

    Luego de esto, con los parametros que la función recibió anteriormente, empieza a llenar los
    "cuadrantes" de la matriz que se encuentran en la diagonal principal (de arriba hacia abajo),
    asegurandose de que un caracter no aparezca más de una vez en cada cuadrante. Cabe aclarar que
    por cada vez que se llama a la función "llenarDiagonal", esta solo llena un cuadrante, por lo
    tanto, como queremos llenar tres cuadrantes, debemos llamar a la función tres veces.
*/
void llenarDiagonal(char sudoku[12][12], int iniciaFila, int terminaFila, int iniciaCol, int terminaCol)
{
    int posicionUsados=0, j;
    char caracter;
    char usados[12] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
    bool flag;
    for (int i=iniciaFila; i<=terminaFila; i++)
    {
        j=iniciaCol;
        while (j<=terminaCol)
        {
            flag = true;
            caracter = aleatorio();
            for (int iteradorUsados=0; iteradorUsados<12; iteradorUsados++)
            {
                if (usados[iteradorUsados]==caracter)
                {
                    flag = false;
                    break;
                }
            }
            if (flag==true)
            {
                sudoku[i][j] = caracter;
                usados[posicionUsados] = caracter;
                posicionUsados++;
                j++;
            }

        }
    }

}


/*
    La funcion "verificar", recibe un caracter, dos numeros enteros los cuales corresponden al
    numero de fila y al numero de la columna en la cual se pretende ingresar el caracter, y por
    ultimo, recibe la matriz "sudoku". Esta funcion es la encargada de revisar que no se repita
    ese caracter en la fila y columna ingresadas, además, de igual forma revisa en el mismo
    "cuadrante". Después de verificar, devuelve un valor boleano como respuesta (true en el caso
    que no se repita y false en el caso contrario).
*/
bool verificar(char caracter, int fila, int col, char sudoku[12][12])
{
    // verifica en todas las posiciones de la misma fila.
    for (int j=0; j<12; j++)
    {
        if (sudoku[fila][j] == caracter)
        {
            return false;
        }
    }

    // verifica en todas las posiciones de la misma columna.
    for (int i=0; i<12; i++)
    {
        if (sudoku[i][col] == caracter)
        {
            return false;
        }
    }

    // verifica en todas las posiciones del mismo cuadrante.
    int comienzaFila = fila - fila % 3;
    int comienzaCol = col - col % 4;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sudoku[comienzaFila + i][comienzaCol + j] == caracter)
            {
                return false;
            }
        }
    }
    return true;
}



/*
    La funcion "completar" es la encargada de poner los caracteres posibles en el sudoku, es decir,
    termina de llenar la matriz "sudoku" haciendo uso de la funcion "verificar", para que los caracteres
    no se repitan en una misma fila, columna y "cuadrante".
*/
bool completar(char sudoku[12][12])
{
    char caracteresPosibles[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    char caracter;
    bool respuesta;
    for (int fila=0; fila<12; fila++)
    {
        for (int col=0; col<12; col++)
        {
            if (sudoku[fila][col]=='0')
            {
                for (int iteradorCaracteresPosibles=0; iteradorCaracteresPosibles<12; iteradorCaracteresPosibles++)
                {
                    caracter = caracteresPosibles[iteradorCaracteresPosibles];
                    respuesta = verificar(caracter, fila, col, sudoku);
                    if (respuesta==true)
                    {
                        sudoku[fila][col] = caracter;
                        if (completar(sudoku))
                        {
                            return true;
                        }
                        sudoku[fila][col] = '0';
                    }
                }
                return false;
            }
        }
    }

    return true;
}


/*
    La funcion "sudokuConNivel", recibe como parametros la matriz "sudoku" y un numero entero llamado "numeroDeEspacios".
    La funcion es la encargada de encontrar dos valores aleatorios (n1Aleatorio y n2Aleatorio), estos los
    usa para ubicar posiciones de fila y columna en la matriz "sudoku", y luego cambia lo que tenia
    antes la posicion, por un espacio en blanco. El ciclo de cambiar lo que habia antes por espacios en
    blanco, se repite hasta "numeroDeEspacios" veces, sinedo "numeroDeEspacios" el parametro que se ingresó al comienzo.
*/
void sudokuConNivel(char sudoku[12][12], int numeroDeEspacios)
{
    int n1Aleatorio, n2Aleatorio;
    for (int i=0; i<numeroDeEspacios; i++)
    {
        n1Aleatorio = rand() % 12;
        n2Aleatorio = rand() % 12;
        sudoku[n1Aleatorio][n2Aleatorio] = ' ';
    }
}


/*
    La función "margen", es la que ayuda al momento de imprimir por pantalla el sudoku, se cree
    el recuadro o margen que lo haga lucir como un sudoku.
*/
void margen(int forma)
{
    if (forma == 1)
    {
        cout << " -------------------------------" << endl;
    }
    else
    {
        cout << " | ";
    }
}


/*
    La funcion "imprimir", recibe dos parámetros, la matriz "sudoku" y el hConsole, esta funcion
    es la encargada de imprimir por pantalla la matriz "sudoku". A la vez, usa la funcion "margen",
    para que esta tome el aspecto de un sudoku, y la funcion "SetConsoleTextAttribute", la cual en
    la parte superior, definimos simplemente como "color", la cual es la encargada de cambiar el
    color de los caracteres que se imprimen por pantalla.
*/
void imprimir(char sudoku[12][12], HANDLE hConsole)
{
    // Linea horizontal superior
    margen(1);
    for (int fila=0; fila<12; fila++)
    {
        for (int col=0; col<12; col++)
        {

            // Linea vertical izquierda
            if (col==0)
            {
                margen(2);
            }

            color(hConsole, 11);
            cout << sudoku[fila][col];
            color(hConsole, 5);

            // Lineas verticales de la mitad y el final
            if (col==3 || col==7)
            {
                margen(2);
            }
            else if (col==11)
            {
                margen(2);
                cout << endl;
            }
            else
            {
                cout << " ";
            }

            // Lineas horizontales de la mitad
            if ((fila==2 || fila==5 || fila==8) && col==11)
            {
                margen(1);
            }
        }
    }
    // Linea horizontal inferior
    margen(1);
}



/*
    La funcion "interfaz", recibe como parámetro la matriz "sudoku", esta funcion es la encargada de
    mostrar por pantalla el menú de opciones, además de controlar en que momento usar las funciones anteriores.
*/
void interfaz(char sudoku[12][12])
{
    bool flag=true;
    char opc, nivel;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while(flag)
    {
        color(hConsole, 9);
        cout << endl;
        cout << "====================================" << endl;
        cout << endl;
        color(hConsole, 3);
        cout << "     GENERADOR DE SUDOKU EN C++" << endl;
        cout << endl;
        color(hConsole, 9);
        cout << "====================================" << endl;
        cout << endl;
        color(hConsole, 14);
        cout << "Autores: ";
        color(hConsole, 12);
        cout << "Juan Aristizabal" << endl;
        cout << "         Matthew Vanegas" << endl;
        cout << "         Juan Carlos Tobon" << endl;
        cout << "         Anamaria Peña" << endl;
        cout << "         Luisa Ramos" << endl;
        cout << "         Emmanuel Camacho" << endl;
        cout << endl;
        cout << endl;
        color(hConsole, 4);
        cout << "¿Que desea hacer?." << endl;
        cout << "(1) Generar sudoku." << endl;
        cout << "(2) Salir." << endl;
        color(hConsole, 6);
        cin >> opc;
        switch(opc)
        {
        case '1':
            color(hConsole, 4);
            cout << "-Digite el nivel de dificultad para el sudoku que desea crear." << endl;
            cout << "(1) Facil." << endl;
            cout << "(2) Medio." << endl;
            cout << "(3) Dificil." << endl;
            color(hConsole, 6);
            cin >> nivel;

            color(hConsole, 5);
            switch(nivel)
            {
            case '1':
                cout << "\nDificultad: Facil\n" << endl;
                llenarConCeros(sudoku);
                llenarDiagonal(sudoku,0,2,0,3);
                llenarDiagonal(sudoku,3,5,4,7);
                llenarDiagonal(sudoku,6,8,8,11);
                if (completar(sudoku))
                {
                    sudokuConNivel(sudoku, 60);
                    imprimir(sudoku, hConsole);
                }
                cout << endl;
                cout << endl;
                system("pause");
                system("cls");
                break;
            case '2':
                cout << "\nDificultad: Medio\n" << endl;
                llenarConCeros(sudoku);
                llenarDiagonal(sudoku,0,2,0,3);
                llenarDiagonal(sudoku,3,5,4,7);
                llenarDiagonal(sudoku,6,8,8,11);
                if (completar(sudoku))
                {
                    sudokuConNivel(sudoku, 80);
                    imprimir(sudoku, hConsole);
                }
                cout << endl;
                cout << endl;
                system("pause");
                system("cls");
                break;
            case '3':
                cout << "\nDificultad: Dificil\n" << endl;
                llenarConCeros(sudoku);
                llenarDiagonal(sudoku,0,2,0,3);
                llenarDiagonal(sudoku,3,5,4,7);
                llenarDiagonal(sudoku,6,8,8,11);
                if (completar(sudoku))
                {
                    sudokuConNivel(sudoku, 110);
                    imprimir(sudoku, hConsole);
                }
                cout << endl;
                cout << endl;
                system("pause");
                system("cls");
                break;
            default:
                cout << endl;
                cout << "---Digito una opcion no valida.---" << endl;
                cout << endl;
                system("pause");
                system("cls");
                break;
            }

            break;
        case '2':
            color(hConsole, 3);
            cout << endl;
            cout << endl;
            cout << "---Gracias por usar nuestro generador, lo esperamos pronto.---" << endl;
            cout << endl;
            cout << endl;
            flag=false;
            color(hConsole, 5);
            break;
        default:
            cout << endl;
            cout << "---Digito una opcion no valida.---" << endl;
            cout << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

