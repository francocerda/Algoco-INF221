#include <bits/stdc++.h>
#include <chrono> // Incluimos la biblioteca chrono
#include <iomanip> // Necesario para std::setprecision
#define int long long 
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;

vii transpose_matrix(const vii &matrix, int fila, int columna) {
    vii transposed_matrix(columna, vector<int>(fila));
    for(int i = 0; i < fila; i++) {
        for(int j = 0; j < columna; j++) {
            transposed_matrix[j][i] = matrix[i][j]; 
        }
    }
    return transposed_matrix;
}

vii result_matrix(const vii &matrix_1, const vii &transposed_matrix, int fila_1, int columna_1, int fila_2, int columna_2) {
    vii new_matrix(fila_1, vector<int>(columna_2, 0));
    for(int i = 0; i < fila_1; i++) {
        for(int j = 0; j < columna_2; j++) {
            for(int k = 0; k < columna_1; k++) {
                new_matrix[i][j] += matrix_1[i][k] * transposed_matrix[j][k];
            }
        }
    }
    return new_matrix;
}

signed main() {
    USM;
        
    int fila_1, columna_1;
    cin >> fila_1 >> columna_1;
    vii matrix_1(fila_1, vector<int>(columna_1));
    for(int i = 0; i < fila_1; i++) {
        for(int j = 0; j < columna_1; j++) {
            cin >> matrix_1[i][j];
        }
    }
    int fila_2, columna_2;
    cin >> fila_2 >> columna_2;
    vii matrix_2(fila_2, vector<int>(columna_2));
    for(int i = 0; i < fila_2; i++) {
        for(int j = 0; j < columna_2; j++) {
            cin >> matrix_2[i][j];
        }
    }
    if(columna_1 != fila_2) {
        cout << "La multiplicacion no es posible." << endl;
        return 0;
    }

    // Capturamos el tiempo antes de la ejecucion del algoritmo
    auto start = chrono::high_resolution_clock::now();

    // Transponemos la segunda matriz
    vii matrix_3 = transpose_matrix(matrix_2, fila_2, columna_2);

    // Ejecucion de la multiplicacion de matrices
    vii resultado = result_matrix(matrix_1, matrix_3, fila_1, columna_1, fila_2, columna_2);

    // Capturamos el tiempo despues de la ejecucion del algoritmo
    auto end = chrono::high_resolution_clock::now();

    // Calculamos la duracion de la ejecucion en microsegundos
    chrono::duration<double, std::micro> duration = end - start;

    // Imprimimos el tiempo de ejecucion en microsegundos
    cout << fixed << setprecision(3);
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;

    for(int i = 0; i < fila_1; i++) {
        for(int j = 0; j < columna_2; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
