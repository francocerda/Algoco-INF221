#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;

vii transpose_matrix(vii &matrix, int fila, int columna) {
    vii transpose_matrix(columna, vector<int>(fila));
    for(int i = 0; i < fila; i++) {
        for(int j = 0; j < columna; j++) {
            transpose_matrix[j][i] = matrix[i][j]; // Matriz transpuesta
        }
    }
    return transpose_matrix;
}

vii result_matrix(vii matrix_1, vii transpos_matrix, int fila_1, int columna_1, int fila_2, int columna_2) {
    vii new_matrix(fila_1, vector<int>(columna_2));
    for(int i = 0; i < fila_1; i++) {
        for(int j = 0; j < columna_2; j++) {
            for(int k = 0; k < columna_1; k++) {
                new_matrix[i][j] += matrix_1[i][k] * transpos_matrix[j][k];
            }
        }
    }
    return new_matrix;
}

signed main() {
        

    // Menu para pedir los datos
    int fila_1, columna_1;
    cout << "Ingrese el numero de filas de la primera matriz: ";
    cin >> fila_1;
    cout << "Ingrese el numero de columnas de la primera matriz: ";
    cin >> columna_1;

    vii matrix_1(fila_1, vector<int>(columna_1)); // Inicializo el tamaño de la matriz 1
    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for(int i = 0; i < fila_1; i++) {
        for(int j = 0; j < columna_1; j++) {
            cin >> matrix_1[i][j];
        }
    }

    int fila_2, columna_2;
    cout << "Ingrese el numero de filas de la segunda matriz: ";
    cin >> fila_2;
    cout << "Ingrese el numero de columnas de la segunda matriz: ";
    cin >> columna_2;

    vii matrix_2(fila_2, vector<int>(columna_2)); // Inicializo el tamaño de la matriz 2
    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    for(int i = 0; i < fila_2; i++) {
        for(int j = 0; j < columna_2; j++) {
            cin >> matrix_2[i][j];
        }
    }

    // Verificar si la multiplicacion es posible
    if(columna_1 != fila_2) {
        cout << "La multiplicacion no es posible." << endl;
        return 0;
    }

    // Transponer y multiplicar matrices
    vii matrix_3 = transpose_matrix(matrix_2, fila_2, columna_2);
    vii resultado = result_matrix(matrix_1, matrix_3, fila_1, columna_1, fila_2, columna_2);

    // Mostrar el resultado
    cout << "El resultado de la multiplicacion de matrices es:" << endl;
    for(int i = 0; i < fila_1; i++) {
        for(int j = 0; j < columna_2; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
