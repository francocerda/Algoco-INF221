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

    string s; cin >> s;
    string t = s;
    sort(t.begin(),t.end());

    do{
        if(t > s && t[0] != '0'){
            cout << t << endl;
            return 0;
        }

    } while(next_permutation(t.begin(),t.end()));
        
    
    cout << 0 << endl;
    
    return 0;
}
