#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define USM ios::sync_with_stdio(0); cin.tie(0);
const int mod = 1e9+7;

using namespace std;

signed main() {
    USM;

    int n;cin>>n;

    while (n--) {
        string s; cin >> s;
        int t; cin >> t;
        bool flag = true, error = false;
        deque<int> cola;
        string list,num; cin >> list;
        for (int i = 1; i < list.size(); i++) {  
            if (isdigit(list[i])) {
                num += list[i];
            } else if (list[i] == ',' || list[i] == ']') {
                if (!num.empty()) {
                    cola.push_back(stoll(num));  
                    num.clear();
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') {
                flag = !flag;
            } else {
                if (cola.empty()) {
                    error = true;
                    break;
                } else {
                    if (flag) {
                        cola.pop_front();
                    } else {
                        cola.pop_back();
                    }
                }
            }
        }
        if (error) {
            cout << "error" << endl;
        } else {
            cout << "[";
            while (!cola.empty()) {
                if (flag) {
                    cout << cola.front();
                    cola.pop_front();
                } else {
                    cout << cola.back();
                    cola.pop_back();
                }
                if (!cola.empty()) { cout << ','; }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}
