#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;

signed main() {
    USM;

    string s;
    vector<string> palabras;
    set<string> final;
    while(cin>>s){
        palabras.push_back(s);
    }
    for(int i=0;i<palabras.size();i++){
       for(int j=0;j<palabras.size();j++){
            if(i!=j){
                final.insert(palabras[i]+palabras[j]);
            }
        }
    }
    for (const auto &str : final) {
        cout << str << endl;
    }


    return 0;
}
