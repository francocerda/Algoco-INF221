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

    int l, d, n; cin >> l >> d >>n;
    vi pajaros(n);
    forn{
        cin >> pajaros[i];
    }
    int total =0;
    sort(pajaros.begin(),pajaros.end());
    if(n==0){
        total = (l - 12)/d + 1;
        cout << total << endl;
        return 0;
    }else{
        int pos_inicial = 6;

        total += (pajaros[0]-6)/d;
        for(int i=1;i<n;i++){
            total += (pajaros[i]-pajaros[i-1] -d)/d;
        }
        total+= (l-6 -pajaros[n-1])/d;
        
    }
    
    
    cout  << total << endl;
    
    return 0;
}
