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
    multiset<int> t_n, t_m;
    forn{
        int x;cin >> x;
        t_n.insert(x);
    }
    for(int i=0; i<m;i++){
        int y;cin >> y;
        t_m.insert(y);
    }    
    
    int cont=0;
    for(auto it = t_n.begin();it != t_n.end();it++){
        auto it_m = t_m.lower_bound(*it);
        if(it_m != t_m.end() && *it <= *it_m){
            cont++;
            t_m.erase(it_m);
        }
    }

    cout << cont << endl;

    return 0;
}
