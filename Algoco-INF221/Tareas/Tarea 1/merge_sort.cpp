#include <bits/stdc++.h>
#include <chrono> // Incluimos la biblioteca chrono
#include <iomanip> // Necesario para std::setprecision
#define int long long 
#define vi vector<int>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;

vi merge(vi &left, vi &right) {
    vi resultado;
    int i = 0, j = 0;
    while(i < left.size() && j < right.size()) {
        if(left[i] <= right[j]) {
            resultado.push_back(left[i]);
            i++;
        } else {
            resultado.push_back(right[j]);
            j++;
        }
    }
    while(i < left.size()) {
        resultado.push_back(left[i]);
        i++;
    }
    while(j < right.size()) {
        resultado.push_back(right[j]);
        j++;
    }

    return resultado;
}

// Funcion recursiva para dividir 
vi dividir(vi &arr, int inicio, int final) {
    if(inicio == final) {
        return vi(1, arr[inicio]);
    }
    int mid = inicio + (final - inicio) / 2;
    vi left = dividir(arr, inicio, mid);
    vi right = dividir(arr, mid + 1, final);
    return merge(left, right);
}

// Funcion merge_sort
vi merge_sort(vi &arr) {
    return dividir(arr, 0, arr.size() - 1);
}

signed main() {
    USM;

    int n;
    cin >> n;
    vi arr(n);
    forn {
        cin >> arr[i];
    }

    // Capturamos el tiempo antes de la ejecucion del algoritmo
    auto start = chrono::high_resolution_clock::now();

    // Ejecucion del algoritmo
    vi vi_ordenado = merge_sort(arr);

    // Capturamos el tiempo despues de la ejecucion del algoritmo
    auto end = chrono::high_resolution_clock::now();

    // Calculamos la duracion de la ejecucion en microsegundos
    chrono::duration<double, std::micro> duration = end - start;

    // Imprimimos el tiempo de ejecucion en microsegundos
    cout << fixed << setprecision(3);
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;

    forn {
        cout << vi_ordenado[i] << " ";
    }
    cout << endl;

    return 0;
}
