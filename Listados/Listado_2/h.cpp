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

    bool flag = true;
    while(flag){
        int n;cin>>n;
        if(n==0) break;
        vi arr_1(n),arr_2(n);
        forn{
            cin >> arr_1[i]; 
        }
        forn{
            cin >> arr_2[i];
        }
        vi ar_aux = arr_1;
        sort(ar_aux.begin(),ar_aux.end());
        sort(arr_2.begin(),arr_2.end());
        map<int,int> mapa;
        forn{
            mapa[ar_aux[i]] = arr_2[i];
        }
        forn{
            cout << mapa[arr_1[i]] << endl;
        }
        cout << endl;
    
    }
    
    
    return 0;
}
