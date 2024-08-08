#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define USM ios::sync_with_stdio(0); cin.tie(0);
const int mod = 1e9+7;

using namespace std;

signed main() {
    USM;
    
    int n, k;
    cin >> n >> k;
    vi mov;
    int final = 0;
    for(int i = 0; i < k; i++) {
        string s;
        cin >> s;
        if (s == "undo") {
            int m;
            cin >> m;
            while(m--) {
                mov.pop_back();
            }
        } else {
            int num = stoi(s);
            mov.push_back(num);
        }
    }
    for(int movimiento : mov) {
        final = (final + movimiento) % n;
    }
    if (final < 0) final += n;  
    cout << final << endl;

    return 0;
}
