#include<bits/stdc++.h>
#include<chrono> // Biblioteca para medir tiempo
#define int long long 
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;

// Multiplicacion de matrices estandar
void multiplicacionEstandar(vii& A, vii& B, vii& C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Multiplicacion de matrices optimizada
void multiplicacionOptimizada(vii& A, vii& B, vii& C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Funciones auxiliares para Strassen
void sumar(vii& result, const vii& X, const vii& Y) {
    int n = X.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = X[i][j] + Y[i][j];
}

void restar(vii& result, const vii& X, const vii& Y) {
    int n = X.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = X[i][j] - Y[i][j];
}

// Algoritmo de Strassen modificado para usar referencia en C
void strassen(vii& A, vii& B, vii& C, int n) {
    if (n <= 64) { // Caso base, usando multiplicacion estandar
        multiplicacionEstandar(A, B, C, n);
        return;
    }

    int k = n / 2;
    vii A11(k, vi(k)), A12(k, vi(k)), A21(k, vi(k)), A22(k, vi(k));
    vii B11(k, vi(k)), B12(k, vi(k)), B21(k, vi(k)), B22(k, vi(k));
    vii C11(k, vi(k)), C12(k, vi(k)), C21(k, vi(k)), C22(k, vi(k));
    vii M1(k, vi(k)), M2(k, vi(k)), M3(k, vi(k)), M4(k, vi(k)), M5(k, vi(k)), M6(k, vi(k)), M7(k, vi(k));
    vii AResult(k, vi(k)), BResult(k, vi(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Calcular M1...M7
    sumar(AResult, A11, A22); // A11 + A22
    sumar(BResult, B11, B22); // B11 + B22
    strassen(AResult, BResult, M1, k); // M1 = (A11 + A22)(B11 + B22)

    sumar(AResult, A21, A22); // A21 + A22
    strassen(AResult, B11, M2, k); // M2 = (A21 + A22)B11

    restar(BResult, B12, B22); // B12 - B22
    strassen(A11, BResult, M3, k); // M3 = A11(B12 - B22)

    restar(BResult, B21, B11); // B21 - B11
    strassen(A22, BResult, M4, k); // M4 = A22(B21 - B11)

    sumar(AResult, A11, A12); // A11 + A12
    strassen(AResult, B22, M5, k); // M5 = (A11 + A12)B22

    restar(AResult, A21, A11); // A21 - A11
    sumar(BResult, B11, B12); // B11 + B12
    strassen(AResult, BResult, M6, k); // M6 = (A21 - A11)(B11 + B12)

    restar(AResult, A12, A22); // A12 - A22
    sumar(BResult, B21, B22); // B21 + B22
    strassen(AResult, BResult, M7, k); // M7 = (A12 - A22)(B21 + B22)

    // Combinar resultados
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C12[i][j] = M3[i][j] + M5[i][j];
            C21[i][j] = M2[i][j] + M4[i][j];
            C22[i][j] = M1[i][j] + M3[i][j] - M2[i][j] + M6[i][j];
        }
    }

    // Unir submatrices en C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

// Funcion para medir y mostrar tiempos de ejecucion
void medirTiempo(void (*funcionMultiplicar)(vii&, vii&, vii&, int), vii& A, vii& B, vii& C, int tam, const string& nombre) {
    auto inicio = chrono::high_resolution_clock::now();
    funcionMultiplicar(A, B, C, tam);
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << nombre << " tomo " << duracion.count() << " segundos." << endl;
}

// Funcion para generar matrices aleatorias
vii generarMatriz(int tam) {
    vii matriz(tam, vi(tam));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            matriz[i][j] = dis(gen);
        }
    }

    return matriz;
}

signed main() {
    int tam;
    cout << "Ingrese el tamano de las matrices: "; cin >> tam;

    vii A = generarMatriz(tam);
    vii B = generarMatriz(tam);
    vii C(tam, vector<int>(tam));

    vii C1 = C;
    vii C2 = C;
    vii C3 = C;

    // Medir tiempo de ejecucion para cada algoritmo
    medirTiempo(multiplicacionEstandar, A, B, C1, tam, "Multiplicacion Estandar");
    medirTiempo(multiplicacionOptimizada, A, B, C2, tam, "Multiplicacion Optimizada");
    medirTiempo(strassen, A, B, C3, tam, "Multiplicacion Strassen");

    return 0;
}
