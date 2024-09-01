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

int ordenar(vi &arr, int inicio, int final) {
    int pivote = arr[final];
    int i = inicio - 1;

    for (int j = inicio; j < final; j++) {
        if (arr[j] <= pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[final]);
    return i + 1;
}

void quick_sort(vi &arr, int inicio, int final) {
    if (inicio < final) {
        int indice_pivote = ordenar(arr, inicio, final);
        quick_sort(arr, inicio, indice_pivote - 1);
        quick_sort(arr, indice_pivote + 1, final);
    }
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
    quick_sort(arr, 0, n - 1);

    // Capturamos el tiempo despues de la ejecucion del algoritmo
    auto end = chrono::high_resolution_clock::now();

    // Calculamos la duracion de la ejecucion en microsegundos
    chrono::duration<double, std::micro> duration = end - start;

    // Imprimimos el tiempo de ejecucion en microsegundos
    cout << fixed << setprecision(3);
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;

    forn {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
