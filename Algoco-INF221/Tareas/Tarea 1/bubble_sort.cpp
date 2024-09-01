#include <bits/stdc++.h>
#include <chrono>
#include <iomanip> // Necesario para std::setprecision
#define int long long 
#define vi vector<int>
#define pii pair<int,int>
#define forn(i, n) for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;

vi bubble_sort(vi &arr, int n){
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; n-i-1 > j; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    return arr;
}

signed main() {
    USM;

    int n;
    cin >> n;
    vi arr(n);
    forn(i, n){
        cin >> arr[i];
    }

    auto start = chrono::high_resolution_clock::now();

    bubble_sort(arr, n);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, std::micro> duration = end - start;

    cout << fixed << setprecision(3); // Configuramos para 3 decimales
    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;
    
    forn(i, n){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
