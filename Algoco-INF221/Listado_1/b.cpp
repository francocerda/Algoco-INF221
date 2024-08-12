#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
const int mod = 1e9+7;

using namespace std;

signed main() {
    USM;

    int n;cin>>n;
    vi arr(n);
    forn{
        cin>> arr[i];
    }
    vi max_l(n),max_r(n);
    max_l[0] = arr[0];
    max_r[n-1] = arr[n-1];
    for (int i = 1; i < n; i++) {
        max_l[i] = max(max_l[i-1], arr[i]);
    }
    for (int i = n-2; i >= 0; i--) {
        max_r[i] = max(max_r[i+1], arr[i]);
    }
    int max_salto = 0;
    for (int i = 1; i < n-1; i++) {
        int altura = min(max_l[i-1], max_r[i+1]);
        if (altura > arr[i]) {
            int salto = altura - arr[i];
            max_salto = max(max_salto, salto);
        }
    }
    cout << max_salto << endl;

    return 0;
}
