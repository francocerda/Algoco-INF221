#include<bits/stdc++.h>
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

// Algoritmo de Strassen
void sumarMatrices(vii& A, vii& B, vii& C, int tam) {
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void restarMatrices(vii& A, vii& B, vii& C, int tam) {
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(vii& A, vii& B, vii& C, int tam) {
    if (tam == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int nuevoTam = tam / 2;
    vector<int> aux(nuevoTam);
    vii 
        A11(nuevoTam, aux), A12(nuevoTam, aux), A21(nuevoTam, aux), A22(nuevoTam, aux),
        B11(nuevoTam, aux), B12(nuevoTam, aux), B21(nuevoTam, aux), B22(nuevoTam, aux),
        C11(nuevoTam, aux), C12(nuevoTam, aux), C21(nuevoTam, aux), C22(nuevoTam, aux),
        M1(nuevoTam, aux), M2(nuevoTam, aux), M3(nuevoTam, aux), M4(nuevoTam, aux), 
        M5(nuevoTam, aux), M6(nuevoTam, aux), M7(nuevoTam, aux),
        AResult(nuevoTam, aux), BResult(nuevoTam, aux);

    // Dividiendo las matrices en submatrices
    for (int i = 0; i < nuevoTam; i++) {
        for (int j = 0; j < nuevoTam; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + nuevoTam];
            A21[i][j] = A[i + nuevoTam][j];
            A22[i][j] = A[i + nuevoTam][j + nuevoTam];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + nuevoTam];
            B21[i][j] = B[i + nuevoTam][j];
            B22[i][j] = B[i + nuevoTam][j + nuevoTam];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    sumarMatrices(A11, A22, AResult, nuevoTam);
    sumarMatrices(B11, B22, BResult, nuevoTam);
    strassen(AResult, BResult, M1, nuevoTam);

    // M2 = (A21 + A22) * B11
    sumarMatrices(A21, A22, AResult, nuevoTam);
    strassen(AResult, B11, M2, nuevoTam);

    // M3 = A11 * (B12 - B22)
    restarMatrices(B12, B22, BResult, nuevoTam);
    strassen(A11, BResult, M3, nuevoTam);

    // M4 = A22 * (B21 - B11)
    restarMatrices(B21, B11, BResult, nuevoTam);
    strassen(A22, BResult, M4, nuevoTam);

    // M5 = (A11 + A12) * B22
    sumarMatrices(A11, A12, AResult, nuevoTam);
    strassen(AResult, B22, M5, nuevoTam);

    // M6 = (A21 - A11) * (B11 + B12)
    restarMatrices(A21, A11, AResult, nuevoTam);
    sumarMatrices(B11, B12, BResult, nuevoTam);
    strassen(AResult, BResult, M6, nuevoTam);

    // M7 = (A12 - A22) * (B21 + B22)
    restarMatrices(A12, A22, AResult, nuevoTam);
    sumarMatrices(B21, B22, BResult, nuevoTam);
    strassen(AResult, BResult, M7, nuevoTam);

    // C11 = M1 + M4 - M5 + M7
    sumarMatrices(M1, M4, AResult, nuevoTam);
    restarMatrices(AResult, M5, BResult, nuevoTam);
    sumarMatrices(BResult, M7, C11, nuevoTam);

    // C12 = M3 + M5
    sumarMatrices(M3, M5, C12, nuevoTam);

    // C21 = M2 + M4
    sumarMatrices(M2, M4, C21, nuevoTam);

    // C22 = M1 - M2 + M3 + M6
    restarMatrices(M1, M2, AResult, nuevoTam);
    sumarMatrices(AResult, M3, BResult, nuevoTam);
    sumarMatrices(BResult, M6, C22, nuevoTam);

    // Uniendo las submatrices en la matriz resultante
    for (int i = 0; i < nuevoTam; i++) {
        for (int j = 0; j < nuevoTam; j++) {
            C[i][j] = C11[i][j];
            C[i][j + nuevoTam] = C12[i][j];
            C[i + nuevoTam][j] = C21[i][j];
            C[i + nuevoTam][j + nuevoTam] = C22[i][j];
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
    vii matriz(tam, vector<int>(tam));
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
