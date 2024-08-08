#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define USM ios::sync_with_stdio(0); cin.tie(0);
const int mod = 1e9+7;

using namespace std;

signed main() {
    USM;

    int n,y;cin>>n>>y;
    set<int> tes;
    for(int i=0;i<y;i++){
        int o;cin>>o;tes.insert(o); 
    }
    auto it = tes.begin(); 
    for (int i = 0; i < n; i++) {
        if (it != tes.end() && *it == i) {
            it++;
        } else {
            cout << i << endl;
        }
    }
    cout << "Mario got "<< tes.size() << " of the dangerous obstacles." << endl;

    return 0;

}    