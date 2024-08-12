#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define fori for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
const int mod = 1e9+7;

using namespace std;

signed main() {
    USM;

    int n;
    cin >> n;
    cin.ignore();
    fori{
        string s;getline(cin, s);
        list<char> lista;
        auto cursor = lista.begin();
        for (char c : s) {
            if (c == '<') {
                if (cursor != lista.begin()) {
                    cursor = lista.erase(--cursor); 
                }
            } else if (c == '[') {
                cursor = lista.begin();  
            } else if (c == ']') {
                cursor = lista.end(); 
            } else {
                lista.insert(cursor, c);  
            }
        }
        for (char c : lista) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
