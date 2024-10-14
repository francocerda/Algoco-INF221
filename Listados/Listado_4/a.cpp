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

    int n,m;cin >> n >> m;
    vector<pair<int,int>> llegada;

    forn{
        int a, b;cin >> a >> b;
        llegada.push_back({a,b});
    }

    sort(llegada.begin(),llegada.end());
    int ahorro = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diferencia = (llegada[j].first - (llegada[i].first+llegada[i].second));
            if(diferencia >= 0 && diferencia <= m){
                ahorro++;
                break;
            }

            if(diferencia>m) break;

        }   
    }


    cout << ahorro << endl;
    

    

    return 0;
}
