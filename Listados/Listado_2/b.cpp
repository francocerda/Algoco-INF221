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

    bool flag = true;
    while(flag){
        int n;cin>>n;
        if(n==0) break;
        vector<string> arr(n);
        forn{
            cin >> arr[i];
        }
        stable_sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
            return a.substr(0, 2) < b.substr(0, 2);
        });

        forn{
            cout << arr[i] << endl;
        }
        cout << endl;   
    
    
    }
    
    
    
    return 0;
}
