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

signed main() {
    USM;
    
    int n;
    cin >> n;
    vi arr(n);
    forn{
        cin >> arr[i];
    }

    // Capturamos el tiempo antes de la ejecucion del algoritmo
    auto start = chrono::high_resolution_clock::now();

    // Ejecucion del algoritmo
    sort(arr.begin(), arr.end());

    // Capturamos el tiempo despues de la ejecucion del algoritmo
    auto end = chrono::high_resolution_clock::now();

    // Calculamos la duracion de la ejecucion en microsegundos
    chrono::duration<double, std::micro> duration = end - start;

    // Imprimimos el tiempo de ejecucion en microsegundos
    cout << fixed << setprecision(3);
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;

    forn{
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
