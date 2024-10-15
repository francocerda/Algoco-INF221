#include <bits/stdc++.h>
#define int int64_t
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

    int t;cin>>t;
    for(int i=0;i<t;i++){
        int l,n;cin >> l>>n;
        vi posiciones(n);
        int minimo=0,maximo=0;
        forn{
            cin >> posiciones[i];
            minimo = max(minimo,min(posiciones[i],l-posiciones[i]));
            maximo =  max(maximo,max(posiciones[i],l-posiciones[i]));

        }

        cout << minimo << " " << maximo << endl;

    }


    
    return 0;
}
