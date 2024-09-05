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

    int n;cin>>n;
    int contador;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        vi arr(20);
        contador=0;
        for(int j=0;j<20;j++){
            cin>>arr[j];
            
        }
        vi arr2(20);
        for(int j=0;j<20;j++){
            auto it = lower_bound(arr2.begin(),arr2.end(),arr[j]);
            int distancia = arr2.end() - it;
            contador += distancia;
            arr2.insert(it,arr[j]);
            
        }
        cout << k << " " << contador << endl;
        
    }

    return 0;
}
