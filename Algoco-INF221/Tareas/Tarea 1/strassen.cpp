#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;

//!Fuente: Chat GPT

typedef vector<vector<int>> Matrix;

// Function to add matrices
Matrix add(const Matrix &A, const Matrix &B, int size) {
    Matrix C(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Function to subtract matrices
Matrix subtract(const Matrix &A, const Matrix &B, int size) {
    Matrix C(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Strassen's Algorithm
Matrix strassen(const Matrix &A, const Matrix &B, int size) {
    if (size == 1) {
        Matrix C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = size / 2;
    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    // Divide matrices A and B into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    Matrix M1 = strassen(add(A11, A22, newSize), add(B11, B22, newSize), newSize);
    Matrix M2 = strassen(add(A21, A22, newSize), B11, newSize);
    Matrix M3 = strassen(A11, subtract(B12, B22, newSize), newSize);
    Matrix M4 = strassen(A22, subtract(B21, B11, newSize), newSize);
    Matrix M5 = strassen(add(A11, A12, newSize), B22, newSize);
    Matrix M6 = strassen(subtract(A21, A11, newSize), add(B11, B12, newSize), newSize);
    Matrix M7 = strassen(subtract(A12, A22, newSize), add(B21, B22, newSize), newSize);

    Matrix C(size, vector<int>(size));

    // Combine the submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + newSize] = M3[i][j] + M5[i][j];
            C[i + newSize][j] = M2[i][j] + M4[i][j];
            C[i + newSize][j + newSize] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    return C;
}

// Main function with a menu to request and display data
signed main() {
    USM;

    int n;
    cout << "Ingrese el tamano de las matrices (potencia de 2): ";
    cin >> n;

    Matrix A(n, vector<int>(n));
    Matrix B(n, vector<int>(n));

    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    Matrix C = strassen(A, B, n);

    cout << "El resultado de la multiplicacion de matrices es:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
