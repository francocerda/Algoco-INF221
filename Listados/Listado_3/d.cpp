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
    for(int i= t.size()-1;i>=1;i--){
        if(s[i-1] > s[i]){
            swap(s[i-1],s[i]);
        }
        if(t < s){
            cout << s << endl;
            return 0;
        }
    }
   
    
    
    
    return 0;
}
