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

signed main() {
    USM;

    int n;
    cin >> n;
    vi numeros(n);
    forn {
        cin >> numeros[i];
    }
    vi real_bytes;
    for(int num : numeros) {
        int byte_original = 0;
        int bit_anterior = 0;
        for(int i = 0; i < 8; i++) {
            int bit_cifrado = (num >> i) & 1;
            int bit_actual = bit_cifrado ^ bit_anterior;
            byte_original |= (bit_actual << i); 
            bit_anterior = bit_actual;
        }
        real_bytes.push_back(byte_original);
    }

    for (int i = 0; i < n; ++i) {
        cout << real_bytes[i];
        if (i < n - 1) cout << " ";
    }

    cout << endl;

    return 0;
}
