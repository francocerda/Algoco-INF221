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
    
    int n;cin>>n;
    vi arr(n);
    forn{
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    forn{
        cout << arr[i] << " ";
    }
    
    return 0;
}