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
    int suma;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        vi arr(20);
        suma = 0;
        for(int j=0;j<20;j++){
            cin>>arr[j];
            
        }
        cout << k << " " << suma << endl;
    }

    return 0;
}
