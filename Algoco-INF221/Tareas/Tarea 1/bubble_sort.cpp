#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;


vi bublle_sort(vi &arr, int &n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}

signed main() {
    USM;

    int n;cin>>n;
    vi arr(n);
    forn{
        cin>> arr[i];
    }

    bublle_sort(arr,n);
    
    forn{
        cout << arr[i] << " ";
    }

    return 0;
}
